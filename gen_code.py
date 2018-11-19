#!/usr/bin/env python3

import sys
import os
import numpy as np
from random import randint as rand

#  chars={}
#  words=[]

def read_chars(char_file):
	global chars
	chars={x[1]: x[0] for x in np.loadtxt(char_file, dtype=str) if len(x[0]) >= 3}
	print("Read Chars done, len = {}".format(len(chars)))


def read_words(word_file):
	global words
	words=np.loadtxt(word_file, dtype=str)
	print("Read Words done, len = {}".format(len(words)))

def gen_codes():
	global chars, words, codes
	if chars is None or words is None:
		print("Error! chars or words are None")
		sys.exit(130)
	print("len: single {}, words {}".format(len(chars), len(words)))
	for w in words:
		freq=rand(0,100)
		code=''
		if len(w) is 2:
			code = w + "\t" + chars[w[0]][0:2]+chars[w[1]][0:2] + "\t" + str(freq)
		if len(w) is 3:
			code = w + "\t" + chars[w[0]][0]+chars[w[1]][0]+chars[w[2][0:2]] + "\t" + str(freq)
		if len(w) >= 4:
			code = w + "\t" + chars[w[0]][0]+chars[w[1]][0]+chars[w[2]][0]+chars[w[-1]][1] + "\t" + str(freq)
		codes.append(code)
		print("code: {}".format(codes[-1]))
		#  except:
			#  print("Cound not find Keys for {}".format(w))
		#  return codes


if __name__ == "__main__":
	chars = []
	words = []
	codes = []
	char_file = sys.argv[1]
	word_file = sys.argv[2]
	code_file = sys.argv[3]
	read_chars(char_file)
	read_words(word_file)
	gen_codes()#(chars, words, codes)
	with open(code_file,"w") as outfile:
		outfile.write("\n".join(codes))

