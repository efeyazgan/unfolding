#!/usr/bin/env/python

#script to save axes definitions read from the pickle file

import os
import ROOT
import pickle

fOut = ROOT.TFile.Open('forEfe/axisdefs_with_pt_cut.root','RECREATE')

obsAxes=None

#path = 'prod_ptcut'
path = 'forEfe' 
in_filename = 'analysiscfg.pck'

with open(os.path.join(path, in_filename), 'r') as infile:
    obsAxes = pickle.load(infile)
    for key in obsAxes:
	obsAxes[key].Write()
fOut.Close()   	
    


