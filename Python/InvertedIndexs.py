# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
from nltk.tokenize import word_tokenize
import sqlite3
from sqlite3 import Error
try:
    conn = sqlite3.connect('F:/IT Sem-5/Python/replies.db')     
except Error as e:
    print(e)
cur = conn.cursor()
cur.execute("select token from tab1 where token is not null")
rows = cur.fetchall()
did={}
for i in range(0,len(rows)):
    str=rows[i][0]
    str=word_tokenize(str)
    str=sorted(str)   
    for j in str:
        if j in did.keys():
            did[j].append({i+1:str.count(j)})
        else:
            did[j] = [{i+1:str.count(j)}]
print(did)
        
    
    
    
    
    

         
    
