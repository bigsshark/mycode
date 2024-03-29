# cuda  cudnn   cublas
# opencl

# Tensorflow/PyTorch/Caffe/Matlab/Theano

# Andrej karpathy


# import torch
# from torch.autograd import Variable
# import torchvision

# alexnet = torchvision.models.alexnet()
# vgg16 = torchvision.models.vgg16()
# resnet101 = torchvision.models.resnet101()

# Tensor

# VAriable

# Module  torch.nn.Module

# tensorflow Static  PyTorch Dynamic

# 32 * 32 * 3  5 * 5 * 3  =  28 * 28 * 1 

# Pooling layer  提升计算效率  数据降维，丢失图像信息 , max,avg pooling


# style transfer
# 内容: 欧式里德距离代表内容距离  风格:featuremap 的协方差(同一层) 两个矩阵直接的协方差代表的是风格的距离  通一层的协方差  协方差求欧式距离

import code
import numpy as np
import PIL
from PIL import Image 

import torch
import torch.nn as nn
import torch.optim as op
from torch.autograd import Variable
import torchvision.transforms as transforms
import torchvision.models as models
use_cuda = torch.cuda.is_available()
dtype = torch.cuda.FloatTensor if use_cuda else torch.FloatTensor

# images

imsize = 200  # desired size of the output image

loader = transforms.Compose([
    transforms.Resize(imsize),  # scale imported image
    transforms.ToTensor()])  # transform it into a torch tensor


def image_loader(image_name):
    image = Image.open(image_name)
    image = Variable(loader(image))
    # fake batch dimension required to fit network's input dimensions
    image = image.unsqueeze(0)
    return image


style = image_loader("images/picasso.jpg").type(dtype)
content = image_loader("images/dancing.jpg").type(dtype)

assert style.size() == content.size(),"we need to import style and content images of the same size"


# display

unloader = transforms.ToPILImage()  # reconvert into PIL image


def toimage(tensor):
    image = tensor.clone().cpu()  # we clone the tensor to not do changes on it
    image = image.view(3, imsize, imsize)  # remove the fake batch dimension
    image = unloader(image)
    return image

# content loss

class ContentLoss(nn.Module):
    def __init__(self, target, weight):
        super(ContentLoss, self).__init__()
        # we 'detach' the target content from the tree used
        self.target = target.detach() * weight
        # to dynamically compute the gradient: this is a stated value,
        # not a variable. Otherwise the forward method of the criterion
        # will throw an error.
        self.weight = weight
        self.criterion = nn.MSELoss()

    def forward(self, input):
        self.loss = self.criterion.forward(input * self.weight, self.target)
        self.output = input
        return self.output

    def backward(self, retain_variables=True):
        self.loss.backward(retain_graph=True)
        return self.loss

# style loss

#格拉姆矩阵  风格的协方差矩阵
class GramMatrix(nn.Module):
    def forward(self, input):
        a, b, c, d = input.size()  # a=batch size(=1)
        # b=number of feature maps
        # (c,d)=dimensions of a f. map (N=c*d)

        features = input.view(a * b, c * d)  # resise F_XL into \hat F_XL

        G = torch.mm(features, features.t())  # compute the gram product

        # we 'normalize' the values of the gram matrix
        # by dividing by the number of element in each feature maps.
        return G.div(a * b * c * d)


class StyleLoss(nn.Module):
    def __init__(self, target, weight):
        super(StyleLoss, self).__init__()
        self.target = target.detach() * weight
        self.weight = weight
        self.gram = GramMatrix()
        self.criterion = nn.MSELoss()

    def forward(self, input):
        self.output = input.clone()
        self.G = self.gram.forward(input)
        self.G.mul_(self.weight)
        self.loss = self.criterion.forward(self.G, self.target)
        return self.output
    #retain_variables=retain_variables
    def backward(self, retain_variables=True):
        self.loss.backward(retain_graph=True)
        return self.loss

# load the cnn and build the model


cnn = models.vgg19(pretrained=True).features

# move it to the GPU if possible:
if use_cuda:
    cnn = cnn.cuda()

# desired depth layers to compute style/content losses :
content_layers = ['conv_4']
style_layers = ['conv_1', 'conv_2', 'conv_3', 'conv_4', 'conv_5']

# just in order to have an iterable access to or list of content/syle losses
content_losses = []
style_losses = []

model = nn.Sequential()  # the new Sequential module network
gram = GramMatrix()  # we need a gram module in order to compute style targets

# move these modules to the GPU if possible:
if use_cuda:
    model = model.cuda()
    gram = gram.cuda()

# weigth associated with content and style losses
content_weight = 1
style_weight = 1000
i = 1
for layer in list(cnn):
    if isinstance(layer, nn.Conv2d):
        name = "conv_" + str(i)
        model.add_module(name, layer)

        if name in content_layers:
            # add content loss:
            target = model.forward(content).clone()
            content_loss = ContentLoss(target, content_weight)
            model.add_module("content_loss_" + str(i), content_loss)
            content_losses.append(content_loss)

        if name in style_layers:
            # add style loss:

            # print(layer,name)
            target_feature = model.forward(style).clone()
            # print(target_feature.shape)
            target_feature_gram = gram.forward(target_feature)
            style_loss = StyleLoss(target_feature_gram, style_weight)
            model.add_module("style_loss_" + str(i), style_loss)
            style_losses.append(style_loss)

    if isinstance(layer, nn.ReLU):
        name = "relu_" + str(i)
        model.add_module(name, layer)

        if name in content_layers:
            # add content loss:
            target = model.forward(content).clone()
            content_loss = ContentLoss(target, content_weight)
            model.add_module("content_loss_" + str(i), content_loss)
            content_losses.append(content_loss)

        if name in style_layers:
            # add style loss:
            target_feature = model.forward(style).clone()
            target_feature_gram = gram.forward(target_feature)
            style_loss = StyleLoss(target_feature_gram, style_weight)
            model.add_module("style_loss_" + str(i), style_loss)
            style_losses.append(style_loss)

        i += 1

    if isinstance(layer, nn.MaxPool2d):
        name = "pool_" + str(i)
        model.add_module(name, layer)  

# print(model)
input = image_loader('images/dancing.jpg').type(dtype)
input.data = torch.randn(input.data.size()).type(dtype)
input_image = toimage(input.data)


input = nn.Parameter(input.data)
opt = op.LBFGS([input])





run = [0]
while run[0] <= 300:
	
	def clouser():
		input.data.clamp_(0,1)
		opt.zero_grad()
		model.forward(input)
		
		#loss
		style_score = 0
		content_score = 0
		for sl in style_losses:
			style_score += sl.backward()
		for cl in content_losses:
			content_score += cl.backward()

		run[0] += 1
		if run[0] % 10 == 0:
			print('run' + str(run) + ':')
			print(style_score[0])
			print(content_score[0])
		return style_score+content_score
	opt.step(clouser)
input.data.clamp_(0, 1)
out_image = toimage(input.data)
content_iamge = toimage(content.data)
style_iamge = toimage(style.data)

np.savez("result.npz", input=input_image, content=content_iamge, style=style_iamge, output=out_image)
