#!/usr/bin/env python3

import sys
import os
import numpy as np
from random import randint as rand

#  chars={}
#  words=[]

freq_min=0
freq_max=1000

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
	global freq_max, freq_min
	if chars is None or words is None:
		print("Error! chars or words are None")
		sys.exit(130)
	print("len: single {}, words {}, freq_min:{}, freq_max:{}".format(len(chars), len(words), freq_min, freq_max))
	for w in words:
		freq=rand(freq_min, freq_max)
		code=''
		try:
			if len(w) is 2:
				code = w + "\t" + chars[w[0]][0:2]+chars[w[1]][0:2] + "\t" + str(freq)
			if len(w) is 3:
				code = w + "\t" + chars[w[0]][0]+chars[w[1]][0]+chars[w[2]][0:2] + "\t" + str(freq)
			if len(w) >= 4:
				code = w + "\t" + chars[w[0]][0]+chars[w[1]][0]+chars[w[2]][0]+chars[w[-1]][1] + "\t" + str(freq)
			codes.append(code)
		except:
			print("Error word: {}".format(w))
		#  print("code: {}".format(codes[-1]))
		#  except:
			#  print("Cound not find Keys for {}".format(w))
		#  return codes


if __name__ == "__main__":
	chars = []
	words = []
	codes = []
	if len(sys.argv)  <  4:
		print("Usage:\n\t this_file single_file words_file output_file [freq_max [freq_min]]")
	char_file = sys.argv[1]
	word_file = sys.argv[2]
	code_file = sys.argv[3]
	if len(sys.argv) >= 5:
		freq_max = int(sys.argv[4])
	if len(sys.argv) == 6:
		freq_min = int(sys.argv[5])

	read_chars(char_file)
	read_words(word_file)
	gen_codes()#(chars, words, codes)
	with open(code_file,"w") as outfile:
		outfile.write("\n".join(codes))

