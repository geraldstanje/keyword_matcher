#!/usr/bin/python

import os
from struct import *
import subprocess

# compile
os.system('clear; make clean; make')

# run test to check for memory leaks
pipe = subprocess.Popen(['valgrind', '--tool=memcheck', '--leak-check=full', './main'], stderr=subprocess.PIPE)
stdout, stderr = pipe.communicate()
stderr_res = stderr.decode('utf-8')  
pipe.wait()

if stderr_res.find("ERROR SUMMARY: 0 errors") == -1:
  print "valigrind check...failed"
else:
  print "valigrind check...passed"