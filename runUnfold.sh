#!/bin/bash

#main file, toy files, 1: use toy files, 0: don't use toy files 
rm -f pulls_*.txt

for (( i = 0 ; i < 133; i++ ))
do
FILE=/afs/cern.ch/user/p/psilva/work/analysis_0_0/Chunks/MC13TeV_TTJets_$i.root
if [ -f $FILE ]; then
        ./UEUnfold /afs/cern.ch/user/p/psilva/work/analysis_0_0//plots/plotter.root $FILE 1
else
	echo "File $FILE does not exist"
fi
done
root -l -q -b plot_pulls.C 
