#! /usr/bin/python
# -*- coding: utf-8 -*-
# import rospy
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
from scipy.spatial import Voronoi,voronoi_plot_2d


png_read=mpimg.imread('/home/khs/Algorithm/test/map.png')
# png_read_1ch = png_read[:,:,0]
mapsize=png_read.shape
count=-1
obs_x=[]
obs_y=[]
for width in range(0,mapsize[0]):
    for height in range(0,mapsize[1]):
        if png_read[width][height]==0:
            count=count+1
            obs_x.insert(count,width+1)
            obs_y.insert(count,height+1)
        
arr1=np.array([obs_x,obs_y])
points=np.transpose(arr1)
sizeobs=points.shape

obs_xy=obs_x+obs_y
# print(arr1)
# print(points)
# print(type(points))
vor=Voronoi(points)
# fig=voronoi_plot_2d(vor)
fig=voronoi_plot_2d(vor,show_vertices=True, line_colors='red',line_width=2,line_alpha=0.,point_size=2)
vertices_data=vor.vertices
col=vertices_data.shape
pros=np.transpose(vertices_data)
tmp1=pros[0:col[0]][0]
tmp2=pros[0:col[0]][1]
tmp3=[0]*col[0]
ver_data=tmp1.tolist()+tmp2.tolist()+tmp3
# print((vertices_data))


plt.show()

