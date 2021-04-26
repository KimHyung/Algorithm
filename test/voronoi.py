#! /usr/bin/python
# -*- coding: utf-8 -*-
import collections
import rospy
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import timeit
import os
import cv2
from scipy.spatial import Voronoi,voronoi_plot_2d
from std_msgs.msg import MultiArrayDimension
from std_msgs.msg import Float32MultiArray
from nav_msgs.msg import *
from std_msgs.msg import *

src='/home/khs/Algorithm/test/map.png'
map_resolution=0.1

global sizeobs,col,ver_data,obs_xyz
start_time = timeit.default_timer()
path=os.path.join('img',src)
img=cv2.imread(path)
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
contours, hierarchy=cv2.findContours(gray,cv2.RETR_LIST,cv2.CHAIN_APPROX_NONE)
for contour in contours:
	img=cv2.drawContours(img,[contour],-1,(0,0,255),2)
arry=np.array(contours)
result=[]
for item in contours[0]:
	result.extend(item)
newlist=[]
for i in range(0,arry.shape[1]):
	newlist.insert(i,result[i])
a = np.array(newlist).T[0]
b = np.array(newlist).T[1]
tool=np.array([b,a])
points=np.transpose(tool)
vor=Voronoi((points))

sizeobs=points.shape
obs_xy=tool
obst1=obs_xy[0:sizeobs[0]][0]
obst2=obs_xy[0:sizeobs[0]][1]

obs_xyz=obst1.tolist()+obst2.tolist()
## show voronoi graph
fig=voronoi_plot_2d(vor)
fig=voronoi_plot_2d(vor,show_vertices=True, line_colors='red',line_width=2,line_alpha=0.,point_size=2)
vertices_data=vor.vertices

col=vertices_data.shape

pros=np.transpose(vertices_data)
tmp1=pros[0:col[0]][0]
tmp2=pros[0:col[0]][1]
tmp3=[0]*col[0]
ver_data=tmp1.tolist()+tmp2.tolist()+tmp3
terminate_time = timeit.default_timer()
## show map and obstacles
# plt.plot(obst1,obst2,'ro')
# plt.plot(tmp1,tmp2,'bo')
# print(terminate_time-start_time)


# plt.show()
