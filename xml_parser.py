﻿#! /usr/bin/python
#-*- coding: utf-8 -*-

from BeautifulSoup import BeautifulSoup

html = open('./city1.xml').read()
soup = BeautifulSoup(html)
provinces = soup.findAll('province')

data_l = []

for province in provinces:
    data = {}
    data['province'] = province['name']
    data['city'] = []
    for city in province.findAll("city"):
        data['city'].append(city['name'])
    data_l.append(data)
data = ""
for d in data_l:
    data +=  "\n".join(d['city'])
#print data


data  = ""
for d in data_l:
    print d['province']
"""
f = open("zidian.txt","w")
f.write(data)
f.close()
"""