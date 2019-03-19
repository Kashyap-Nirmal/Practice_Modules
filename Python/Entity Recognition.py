#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 18 15:26:58 2018

@author: root
"""

import spacy
nlp=spacy.load('en')
doc=nlp("what is the grade at Smit ? He works at google")
for ent in doc.ents:
    print(ent.text, ent.label_)