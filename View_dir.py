#coding=utf-8
import os
import sys
res = str(sys.argv[1])
stra = ""
lista = os.listdir(res)#("./piano")   #�����һ���ļ��������.
for i in lista:
    #stra += i
    #stra += "  "
    print(i,end="  ")
#print(stra)