#!/usr/bin/env/python

import os
import sys

inp = raw_input("Enter step number, 0,1,2: ")
inp2 = raw_input("Enter directory name: ")
print "directory name: ",inp2
if inp!="0" and inp!="1" and inp!="2": 
    print inp, "is not 0, 1 or 2. Exiting"
    raise SystemExit
if inp=="0" or inp=="1":
    com1 =  "python runUEanalysis.py -s " + inp + " -i \" "  
    com2 = "eos/cms/store/cmst3/group/top/summer2016/TopUE_era2016/MC13TeV_TTJets_dilpowheg_{0}.root".format(0)

    for x in range(1, 10): 
        com2 = com2 + ", eos/cms/store/cmst3/group/top/summer2016/TopUE_era2016/MC13TeV_TTJets_dilpowheg_{0}.root".format(x)

    com2 = com2 + " \" "
    com2 = com1 + com2 + " --out " + inp2
    print "running the command: ", com2
    os.system(com2)
elif inp=="2":
    for x in range(0,80):
#    for x in range(0,3):
#        com2 = "python runUEanalysis.py -s 2 -i  /store/cmst3/group/top/summer2016/TopUE_era2016/MC13TeV_TTJets_dilpowheg_{0}.root --out `pwd`/".format(x)+inp2+" -q 8nh"
        com2 = "python runUEanalysis.py -s 2 -i  /store/cmst3/group/top/summer2016/TopUE_era2016/MC13TeV_TTJets_dilpowheg_{0}.root --out `pwd`/".format(x)+inp2+" -q 8nh"
        print "running the command: ", com2
        os.system(com2)
