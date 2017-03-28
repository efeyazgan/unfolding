#./UEUnfold forEfe/plotter.root

#main file, toy files, 1: use toy files, 0: don't use toy files 
for (( i = 0 ; i < 133; i++ ))
do
./UEUnfold forEfe/plotter.root /afs/cern.ch/user/p/psilva/work/Top/Moriond17/CMSSW_8_0_26/src/TopLJets2015/TopAnalysis/UEanalysis/analysis_0_0/Chunks/MC13TeV_TTJets_$i.root 1
done
