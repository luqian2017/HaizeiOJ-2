#!/usr/bin/env python
# coding=utf-8

n = int(input())
list = [1, 1]
for i in range(1, n):
    list.append(list[-1] + list[-2])
print(list[n])

