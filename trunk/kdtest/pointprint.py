#!/usr/bin/python

from data import data

print 'loaded points'
minx=min(map(lambda x:x[0],data))
miny=min(map(lambda x:x[1],data))
maxx=max(map(lambda x:x[0],data))
maxy=max(map(lambda x:x[1],data))
print 'calculated mins and maxs'

print len(data)
print minx,miny,maxx,maxy

def remap(resx,resy):
  return map(lambda x:( int((x[0]-minx)*resx/(maxx-minx)), int((x[1]-miny)*resy/(maxy-miny))) , data)


 
import pygame,sys,random
from pygame.locals import *
 
pygame.init()

screen = pygame.display.set_mode((640, 480))

data=remap(640,480)
print 'remapped'

minp=(len(data)/2)+2

def part(l,hor,bbox):
  print hor, len(l)
  color="#"+random.choice('01234')+random.choice('1234')+random.choice('AB654CDEF')+random.choice('03216A1234')+random.choice('A543543BCDEF')+random.choice('A12312312BCDEF');
  color=Color(color)
  if len(l)<minp:
    for p in l:
      #print p
      screen.set_at(p,color)
      pass
    return 0

  if hor:
    l.sort(lambda x,y: x[1]-y[1])
  else:
    l.sort(lambda x,y: x[0]-y[0])

  p=l[len(l)/2]
  l1=l[:len(l)/2]
  l2=l[len(l)/2:]


  if hor:
    pygame.draw.line(screen, color, (bbox[0][0],p[1]), (bbox[1][0],p[1]))
    bbox1=(bbox[0], (bbox[1][0],p[1]))
    bbox2=((bbox[0][0], p[1]), bbox[1])
  else:
    pygame.draw.line(screen, color, (p[0], bbox[0][1]), (p[0],bbox[1][1]))
    bbox1=(bbox[0], (p[0],bbox[1][1]))
    bbox2=((p[0], bbox[0][1]), bbox[1])

  

  part(l1,not hor, bbox1)
  depth=part(l2,not hor, bbox2)
  return depth+1

part(data,True,((0,0),(640,480)))

pygame.display.flip()

while 1:
  for event in pygame.event.get():
    if event.type in (QUIT,):
      sys.exit()
    if event.type in (KEYDOWN,):
      minp=(minp/2)+2
      print 'depth is',part(data,True,((0,0),(640,480)))

      pygame.display.flip()
