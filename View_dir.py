#coding=utf-8
import os
import sys
res = str(sys.argv[1])
stra = ""
lista = os.listdir(res)#("./piano")   #如果在一个文件夹里就用.
for i in lista:
    #stra += i
    #stra += "  "
    print(i,end="  ")
#print(stra)