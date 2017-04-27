#include "UEUnfold.h"


using namespace std;

void UEUnfold(){
  TString dir = gSystem->UnixPathName(__FILE__);
  
  TH1::SetDefaultSumw2();


   m_incchmult = 0;
   m_incchavgpt = 0;
   m_incchflux = 0;

   gen_incchmult = 0;
   gen_incchavgpt = 0;
   gen_incchflux = 0;

   rec_incchmult = 0;
   rec_incchavgpt = 0;
   rec_incchflux = 0;

   data_incchmult = 0;

   def_axis[0] = 0;//gen <--- 0
   def_axis[1] = 0;//rec <--- 1
	
   //   sprintf(file_name,"prod/analysis_0_0/combined_80.root");
   //sprintf(file_name,"prod_ptcut/analysis_0_0/with_pt_cut_0_80.root");
  
   //sprintf(file_name,"forEfe/plotter.root");

   cout<<"Main file: "<<file_name<<endl;
   cout<<"Toy file:  "<<file_toy<<endl;

   //cout<<argv[2]<<endl;
   //sprintf(file_name,argv[0]);
   //cout<<file_name<<endl;

   //sprintf(file_name_2,"prod/analysis_0_0/second_batch/combined_beyond_80.root");

   sprintf(file_axes,"forEfe/axisdefs_with_pt_cut.root");

   TFile f(file_name);

   sprintf(name_h,"m_%schmult/m_%schmult_t#bar{t}","inc","inc");
   f.GetObject(name_h,m_incchmult);
   sprintf(name_h,"gen_%schmult/gen_%schmult_t#bar{t}","inc","inc");
   f.GetObject(name_h,gen_incchmult);
   sprintf(name_h,"rec_%schmult/rec_%schmult_t#bar{t}","inc","inc");
   f.GetObject(name_h,rec_incchmult);
   sprintf(name_h,"rec_%schmult/rec_%schmult_Single top","inc","inc");
   f.GetObject(name_h,rec_incchmult_bkg[0]);
   sprintf(name_h,"rec_%schmult/rec_%schmult_W","inc","inc");
   f.GetObject(name_h,rec_incchmult_bkg[1]);
   sprintf(name_h,"rec_%schmult/rec_%schmult_DY","inc","inc");
   f.GetObject(name_h,rec_incchmult_bkg[2]);
   sprintf(name_h,"rec_%schmult/rec_%schmult_Multiboson","inc","inc");
   f.GetObject(name_h,rec_incchmult_bkg[3]);
   sprintf(name_h,"rec_%schmult/rec_%schmult_t#bar{t}+V","inc","inc");
   f.GetObject(name_h,rec_incchmult_bkg[4]);
   for (int i=0;i<5;i++) cout<<i<<"  "<<rec_incchmult_bkg[i]<<"  "<<rec_incchmult_bkg[i]->GetName()<<endl;



   sprintf(name_h,"m_%schavgpt/m_%schavgpt_t#bar{t}","inc","inc");
   f.GetObject(name_h,m_incchavgpt);
   sprintf(name_h,"gen_%schavgpt/gen_%schavgpt_t#bar{t}","inc","inc");
   f.GetObject(name_h,gen_incchavgpt);
   sprintf(name_h,"rec_%schavgpt/rec_%schavgpt_t#bar{t}","inc","inc");
   f.GetObject(name_h,rec_incchavgpt);
   sprintf(name_h,"rec_%schavgpt/rec_%schavgpt_Single top","inc","inc");
   f.GetObject(name_h,rec_incchavgpt_bkg[0]);
   sprintf(name_h,"rec_%schavgpt/rec_%schavgpt_W","inc","inc");
   f.GetObject(name_h,rec_incchavgpt_bkg[1]);
   sprintf(name_h,"rec_%schavgpt/rec_%schavgpt_DY","inc","inc");
   f.GetObject(name_h,rec_incchavgpt_bkg[2]);
   sprintf(name_h,"rec_%schavgpt/rec_%schavgpt_Multiboson","inc","inc");
   f.GetObject(name_h,rec_incchavgpt_bkg[3]);
   sprintf(name_h,"rec_%schavgpt/rec_%schavgpt_t#bar{t}+V","inc","inc");
   f.GetObject(name_h,rec_incchavgpt_bkg[4]);
   for (int i=0;i<5;i++) cout<<i<<"  "<<rec_incchavgpt_bkg[i]<<"  "<<rec_incchavgpt_bkg[i]->GetName()<<endl;

   sprintf(name_h,"m_%schflux/m_%schflux_t#bar{t}","inc","inc");
   f.GetObject(name_h,m_incchflux);
   sprintf(name_h,"gen_%schflux/gen_%schflux_t#bar{t}","inc","inc");
   f.GetObject(name_h,gen_incchflux);
   sprintf(name_h,"rec_%schflux/rec_%schflux_t#bar{t}","inc","inc");
   f.GetObject(name_h,rec_incchflux);
   sprintf(name_h,"rec_%schflux/rec_%schflux_Single top","inc","inc");
   f.GetObject(name_h,rec_incchflux_bkg[0]);
   sprintf(name_h,"rec_%schflux/rec_%schflux_W","inc","inc");
   f.GetObject(name_h,rec_incchflux_bkg[1]);
   sprintf(name_h,"rec_%schflux/rec_%schflux_DY","inc","inc");
   f.GetObject(name_h,rec_incchflux_bkg[2]);
   sprintf(name_h,"rec_%schflux/rec_%schflux_Multiboson","inc","inc");
   f.GetObject(name_h,rec_incchflux_bkg[3]);
   sprintf(name_h,"rec_%schflux/rec_%schflux_t#bar{t}+V","inc","inc");
   f.GetObject(name_h,rec_incchflux_bkg[4]);
   for (int i=0;i<5;i++) cout<<i<<"  "<<rec_incchflux_bkg[i]<<"  "<<rec_incchflux_bkg[i]->GetName()<<endl;
   //@@@@@@@@@@@@@@@@@@@@@@@@@@



   TString hname(m_incchmult->GetName());
   hname.ReplaceAll("t#bar{t}","tt");
   m_incchmult->SetName( hname );
   cout<<m_incchmult->GetName()<<endl;

   TString hname2(gen_incchmult->GetName());
   hname2.ReplaceAll("t#bar{t}","tt");
   gen_incchmult->SetName( hname2 );
   cout<<gen_incchmult->GetName()<<endl;

   TString hname3(rec_incchmult->GetName());
   hname3.ReplaceAll("t#bar{t}","tt");
   rec_incchmult->SetName( hname3 );
   cout<<rec_incchmult->GetName()<<endl;

   TString hname4(rec_incchmult_bkg[0]->GetName());;
   hname4.ReplaceAll("Single top","SingleTop");
   rec_incchmult_bkg[0]->SetName( hname4 );

   TString hname5(rec_incchmult_bkg[4]->GetName());;
   hname5.ReplaceAll("t#bar{t}+V","tbart+V");
   rec_incchmult_bkg[4]->SetName( hname5 );
   
   for (int i=0;i<5;i++) cout<<i<<"  "<<rec_incchmult_bkg[i]<<"  "<<rec_incchmult_bkg[i]->GetName()<<endl;

   TString hname6(m_incchavgpt->GetName());
   hname6.ReplaceAll("t#bar{t}","tt");
   m_incchavgpt->SetName( hname6 );
   cout<<m_incchavgpt->GetName()<<endl;

   TString hname7(gen_incchavgpt->GetName());
   hname7.ReplaceAll("t#bar{t}","tt");
   gen_incchavgpt->SetName( hname7 );
   cout<<gen_incchavgpt->GetName()<<endl;

   TString hname8(rec_incchavgpt->GetName());
   hname8.ReplaceAll("t#bar{t}","tt");
   rec_incchavgpt->SetName( hname8 );
   cout<<rec_incchavgpt->GetName()<<endl;

   TString hname9(rec_incchavgpt_bkg[0]->GetName());;
   hname9.ReplaceAll("Single top","SingleTop");
   rec_incchavgpt_bkg[0]->SetName( hname9 );

   TString hname10(rec_incchavgpt_bkg[4]->GetName());;
   hname10.ReplaceAll("t#bar{t}+V","tbart+V");
   rec_incchavgpt_bkg[4]->SetName( hname10 );
   
   for (int i=0;i<5;i++) cout<<i<<"  "<<rec_incchavgpt_bkg[i]<<"  "<<rec_incchavgpt_bkg[i]->GetName()<<endl;

   TString hname11(m_incchflux->GetName());
   hname11.ReplaceAll("t#bar{t}","tt");
   m_incchflux->SetName( hname11 );
   cout<<m_incchflux->GetName()<<endl;

   TString hname12(gen_incchflux->GetName());
   hname12.ReplaceAll("t#bar{t}","tt");
   gen_incchflux->SetName( hname12 );
   cout<<gen_incchflux->GetName()<<endl;

   TString hname13(rec_incchflux->GetName());
   hname13.ReplaceAll("t#bar{t}","tt");
   rec_incchflux->SetName( hname13 );
   cout<<rec_incchflux->GetName()<<endl;

   TString hname14(rec_incchflux_bkg[0]->GetName());;
   hname14.ReplaceAll("Single top","SingleTop");
   rec_incchflux_bkg[0]->SetName( hname14 );

   TString hname15(rec_incchflux_bkg[4]->GetName());;
   hname15.ReplaceAll("t#bar{t}+V","tbart+V");
   rec_incchflux_bkg[4]->SetName( hname15 );
   
   for (int i=0;i<5;i++) cout<<i<<"  "<<rec_incchflux_bkg[i]<<"  "<<rec_incchflux_bkg[i]->GetName()<<endl;


   //@@@@@@@@@@@@@@@@@@@@@@@@@@

   m_incchmult->SetDirectory(0);
   gen_incchmult->SetDirectory(0);
   rec_incchmult->SetDirectory(0);
   m_incchavgpt->SetDirectory(0);
   gen_incchavgpt->SetDirectory(0);
   rec_incchavgpt->SetDirectory(0);
   m_incchflux->SetDirectory(0);
   gen_incchflux->SetDirectory(0);
   rec_incchflux->SetDirectory(0);
   TFile f2(file_name);//gecici olarak ikinci bunchin cutli versiyonu yok diye!
   //   TFile f2(file_name_2);
   //sprintf(name_h2,"rec_%schmult","inc");
   sprintf(name_h2,"rec_%schmult/rec_%schmult_t#bar{t}","inc","inc");//testing

   sprintf(name_h3,"rec_%schmult/rec_%schmult","inc","inc");//real data
   f2.GetObject(name_h3,data_incchmult);//h2 test//h3 data_incchmult
   cout<<"data_incchmult:  "<<data_incchmult<<"  "<<data_incchmult->GetName()<<endl;

   sprintf(name_h3,"rec_%schavgpt/rec_%schavgpt","inc","inc");//real data
   f2.GetObject(name_h3,data_incchavgpt);//h2 test//h3 data_incchmult
   cout<<"data_incchavgpt:  "<<data_incchavgpt<<"  "<<data_incchavgpt->GetName()<<endl;

   sprintf(name_h3,"rec_%schflux/rec_%schflux","inc","inc");//real data
   f2.GetObject(name_h3,data_incchflux);//h2 test//h3 data_incchmult
   cout<<"data_incchflux:  "<<data_incchflux<<"  "<<data_incchflux->GetName()<<endl;

   cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;

   TH1F *data_incchmult_bkg_sub = (TH1F*)data_incchmult->Clone("data_incchmult_bkg_sub");
   TH1F *data_incchavgpt_bkg_sub = (TH1F*)data_incchavgpt->Clone("data_incchavgpt_bkg_sub");
   TH1F *data_incchflux_bkg_sub = (TH1F*)data_incchflux->Clone("data_incchflux_bkg_sub");


   char tmp_name[100];
   for (int i=0;i<5;i++){
     sprintf(tmp_name,"h_temp_incchmult[%i]",i);
     h_temp_incchmult[i] = (TH1F*)rec_incchmult_bkg[i]->Clone(tmp_name);
     h_temp_incchmult[i]->Scale(-1.);
     data_incchmult_bkg_sub->Add(h_temp_incchmult[i]);
   }
   for (int i=0;i<5;i++){
     sprintf(tmp_name,"h_temp_incchavgpt[%i]",i);
     h_temp_incchavgpt[i] = (TH1F*)rec_incchavgpt_bkg[i]->Clone(tmp_name);
     h_temp_incchavgpt[i]->Scale(-1.);
     data_incchavgpt_bkg_sub->Add(h_temp_incchavgpt[i]);
   }   
   for (int i=0;i<5;i++){
     sprintf(tmp_name,"h_temp_incchflux[%i]",i);
     h_temp_incchflux[i] = (TH1F*)rec_incchflux_bkg[i]->Clone(tmp_name);
     h_temp_incchflux[i]->Scale(-1.);
     data_incchflux_bkg_sub->Add(h_temp_incchflux[i]);
   }

   TCanvas *c_dbkg = new TCanvas();
   c_dbkg->Divide(3,1);
   c_dbkg->cd(1);
   rec_incchmult->Draw();
   data_incchmult_bkg_sub->SetMarkerColor(4);
   data_incchmult_bkg_sub->SetLineColor(4);
   data_incchmult_bkg_sub->Draw("sames");
   c_dbkg->cd(2);
   rec_incchavgpt->Draw();
   data_incchavgpt_bkg_sub->SetMarkerColor(4);
   data_incchavgpt_bkg_sub->SetLineColor(4);
   data_incchavgpt_bkg_sub->Draw("sames");
   c_dbkg->cd(3);
   rec_incchflux->Draw();
   data_incchflux_bkg_sub->SetMarkerColor(4);
   data_incchflux_bkg_sub->SetLineColor(4);
   data_incchflux_bkg_sub->Draw("sames");
   c_dbkg->SaveAs("bkg_sub_data_incchmult_and_reco_ttbar.C");

   TCanvas *c_d_b = new TCanvas();
   c_d_b->cd();
   data_incchmult->Draw();
   for (int i=0;i<5;i++){ 
     rec_incchmult_bkg[i]->SetLineColor(i+2);
     rec_incchmult_bkg[i]->Draw("sames");
   }
   rec_incchmult->SetLineColor(6);
   rec_incchmult->Draw("sames");
   c_d_b->SaveAs("data_incchmultback.C");

   TFile f_toy(file_toy);
   sprintf(name_toy_h,"rec_incchmult");
   f_toy.GetObject(name_toy_h,rec_incchmult_toy);
   cout<<"toy name:  "<<rec_incchmult_toy->GetName()<<endl;
   rec_incchmult_toy->SaveAs("deltest.C");


   TFile f3(file_axes);
   //   sprintf(axes[0],"gen_chmult%s_0","inc");
   //   sprintf(axes[1],"rec_chmult%s_0","inc");
   sprintf(axes[0],"chmult_genSlices");
   sprintf(axes[1],"chmult_recSlices");
   f3.GetObject(axes[0],def_axis[0]);
   f3.GetObject(axes[1],def_axis[1]);


   int nbins[2];
   nbins[0] = def_axis[0]->GetNbins();
   nbins[1] = def_axis[1]->GetNbins(); 

   double gen_axis_arr[nbins[0]+1], rec_axis_arr[nbins[1]+1];
   
   for (int i=0;i<nbins[0]+2;i++) gen_axis_arr[i] = def_axis[0]->GetBinLowEdge(i+1);

   for (int i=0;i<nbins[1]+2;i++) rec_axis_arr[i] = def_axis[1]->GetBinLowEdge(i+1);     
   
   nbins_gen_incchmult = m_incchmult->GetNbinsX();
   nbins_rec_incchmult = m_incchmult->GetNbinsY();
   m_incchmult->GetBinXYZ((m_incchmult->GetBin(nbins_gen_incchmult,nbins_rec_incchmult)), cx_incchmult,cy_incchmult,cz_incchmult);
   nbinmax_gen_incchmult = cx_incchmult;
   //   nbinmax_rec_incchmult = cy;
   
   //   TH1F *nonselected = new TH1F("nonselected","Non selected rec events' truth values",nbins_gen_incchmult,0,nbinmax_gen_incchmult);

   int nbinsunfolded_incchmult = nbins_gen_incchmult;
   int nbinsreconstructed_incchmult = nbins_rec_incchmult;

   double bin_edges_rec_incchmult[nbinsreconstructed_incchmult+1];
   double bin_edges_gen_incchmult[nbinsunfolded_incchmult+1];

   for (int i=0;i<nbinsreconstructed_incchmult+1;i++) bin_edges_rec_incchmult[i] = i;//i*0.5
   for (int i=0;i<nbinsunfolded_incchmult+1;i++) bin_edges_gen_incchmult[i]= i;

   TH2F* migrationmatrix_incchmult = (TH2F*)m_incchmult->Clone();
   TH2F* migrationmatrix_incchavgpt = (TH2F*)m_incchavgpt->Clone();
   TH2F* migrationmatrix_incchflux = (TH2F*)m_incchflux->Clone();

   TH1 *gen_incchmult_real = new TH1D("gen_incchmult_real","gen_incchmult_real",nbins[0],gen_axis_arr);
   for (int i=0;i<nbins[0]+1;i++){ 
     gen_incchmult_real->SetBinContent(i+1,gen_incchmult->GetBinContent(i+1));
     gen_incchmult_real->SetBinError(i+1,gen_incchmult->GetBinError(i+1));
   }
   TH1 *rec_incchmult_real = new TH1D("rec_incchmult_real","rec_incchmult_real",nbins[1],rec_axis_arr);
   TH1 *data_real = new TH1D("data_real","data_real",nbins[1],rec_axis_arr);
   for (int i=0;i<nbins[1]+1;i++){ 
     rec_incchmult_real->SetBinContent(i+1,rec_incchmult->GetBinContent(i+1));
     rec_incchmult_real->SetBinError(i+1,rec_incchmult->GetBinError(i+1));
     data_real->SetBinContent(i+1,rec_incchmult->GetBinContent(i+1));
     data_real->SetBinError(i+1,rec_incchmult->GetBinError(i+1));     
   }

   
   double norm_factor_matrix[nbins[1]];
   TH2 *m_incchmult_real = new TH2D("m_incchmult_real","m_incchmult_real",nbins[0],gen_axis_arr,nbins[1],rec_axis_arr);
   for (int i=0;i<nbins[0]+1;i++){
     for (int j=0;j<nbins[1]+1;j++){
       m_incchmult_real->SetBinContent(i+1,j+1,m_incchmult->GetBinContent(i+1,j+1));
       //       m_incchmult_real->SetBinError(i+1,j+1,m_incchmult->GetBinError(i+1,j+1));
      norm_factor_matrix[i] += m_incchmult->GetBinContent(i+1,j+1);
     }
   }

   double me = 0.;
   for (int i=0;i<nbins[0]+1;i++){
     for (int j=0;j<nbins[1]+1;j++){
       me = m_incchmult->GetBinContent(i+1,j+1);// /norm_factor_matrix[i];
       m_incchmult_real->SetBinContent(i+1,j+1,me);
       //       m_incchmult->SetBinContent(i+1,j+1,me);
     }
   }   

   TCanvas *mtest = new TCanvas();
   gStyle->SetPaintTextFormat("0.2f");
   mtest->Divide(2,1);  
   mtest->cd(1);
   m_incchmult_real->Draw("colz text");
   mtest->cd(2);
   m_incchmult->Draw("colz text");

   mtest->SaveAs("mtest.C");

   TCanvas *ctest = new TCanvas();
   ctest->Divide(2,2);
   ctest->cd(1);
   gen_incchmult_real->Draw();
   ctest->cd(2);
   gen_incchmult->Draw();
   ctest->cd(3);
   rec_incchmult_real->Draw();
   ctest->cd(4);
   rec_incchmult->Draw();
   ctest->SaveAs("real.C");

   TCanvas *mats = new TCanvas();
   mats->Divide(2,2);
   mats->cd(1);
   m_incchmult->Draw("colz");
   mats->cd(2);
   m_incchavgpt->Draw("colz");
   mats->cd(3);
   m_incchflux->Draw("colz");
   mats->SaveAs("matrices.C");

   /*
   for (int i=0;i<nbins_gen_incchmult;i++){ 
     nonselected->SetBinContent(i+1,m_incchmult->GetBinContent(i+1,0));
     const double content = nonselected->GetBinContent(i);//is this OK?
     const double error = nonselected->GetBinError(i);//is this OK?
     migrationmatrix_incchmult->SetBinContent(i+1,nbins_rec_incchmult+1,content);
     migrationmatrix_incchmult->SetBinError(i+1,nbins_rec_incchmult+1,error);
     migrationmatrix_incchmult->SetBinContent(nbins_gen_incchmult+1,i+1,0);
     migrationmatrix_incchmult->SetBinError(nbins_gen_incchmult+1,i+1,0);
     migrationmatrix_incchmult->SetBinContent(i+1,0,0);
     migrationmatrix_incchmult->SetBinError(i+1,0,0);
     migrationmatrix_incchmult->SetBinContent(0,i+1,0);
     migrationmatrix_incchmult->SetBinError(0,i+1,0);
     
   }
   */

   // Scale factor for the bias distribution. 
   //Choose such that normalization will correspond to expected normalization of result. 
   // For example, a simple approximation could be using expectedNUnfolded = n_data / ttbar_selection_efficiency
   //const double scaleBias = expectedNUnfolded / histogram_with_mc_truth->Integral();


   const double scaleBias = 1;
   
   /*
   TUnfoldBinning *fineBinning_incchmult = new TUnfoldBinning("fine");
   TUnfoldBinning *recoBinning_incchmult = fineBinning_incchmult->AddBinning("reco");
   //   recoBinning->AddAxis("recoquantity",nbins[1],rec_axis_arr,true,true);
   recoBinning_incchmult->AddAxis("recoquantity",nbinsreconstructed_incchmult,bin_edges_rec_incchmult,true,true);
   TUnfoldBinning *coarseBinning = new TUnfoldBinning("coarseBinning");
   TUnfoldBinning *genBinning = coarseBinning->AddBinning("gen");
   // genBinning->AddAxis("genquantity",nbins[0],gen_axis_arr,true,true);
   genBinning->AddAxis("genquantity",nbinsunfolded_incchmult,bin_edges_gen_incchmult,true,true);
   */
   //TUnfoldSys tunfold(migrationmatrix_incchmult, TUnfold::kHistMapOutputHoriz, TUnfold::kRegModeCurvature);
   //TUnfold::ERegMode regMode = TUnfold::kRegModeCurvature;
   TUnfold::ERegMode regMode = TUnfold::kRegModeSize;
   //TUnfold::EConstraint constraint = TUnfold::kEConstraintArea;
   TUnfold::EConstraint constraint = TUnfold::kEConstraintNone;
   TUnfoldDensity::EDensityMode densityFlags=TUnfoldDensity::kDensityModeBinWidth;
   //   TUnfoldDensity unfold(migrationmatrix_incchmult,TUnfold::kHistMapOutputHoriz,
   //			 regMode,constraint,densityFlags,coarseBinning,fineBinning_incchmult);  
   TUnfoldDensity unfold_incchmult(migrationmatrix_incchmult,TUnfold::kHistMapOutputHoriz,
			 regMode,constraint,densityFlags);  
   //unfold.SetInput(data,scaleBias);//test

   
   
   //   unfold_incchmult.SetInput(rec_incchmult,scaleBias);//WORKS EXACTLY
   unfold_incchmult.SetInput(data_incchmult_bkg_sub,scaleBias);

   TUnfoldDensity unfold_incchavgpt(migrationmatrix_incchavgpt,TUnfold::kHistMapOutputHoriz,
			 regMode,constraint,densityFlags);  
   //   unfold_incchavgpt.SetInput(rec_incchavgpt,scaleBias);//WORKS EXACTLY?
   unfold_incchavgpt.SetInput(data_incchavgpt_bkg_sub,scaleBias);//WORKS EXACTLY?

   TUnfoldDensity unfold_incchflux(migrationmatrix_incchflux,TUnfold::kHistMapOutputHoriz,
			 regMode,constraint,densityFlags);  
   //   unfold_incchflux.SetInput(rec_incchflux,scaleBias);//WORKS EXACTLY?
   unfold_incchflux.SetInput(data_incchflux_bkg_sub,scaleBias);//WORKS EXACTLY?


   Int_t nScan=100;
   double tauMin=1.e-4;
   double tauMax=1.e-1;
   TSpline *logTauX,*logTauY;
   TSpline *rhoScan_incchmult=0;
   TSpline *rhoScan_incchavgpt=0;
   TSpline *rhoScan_incchflux=0;

   const char *SCAN_DISTRIBUTION="signal";
   const char *SCAN_AXISSTEERING=0;

   TUnfoldDensity::EScanTauMode tauflag = TUnfoldDensity::kEScanTauRhoAvg;
   //TUnfoldDensity::EScanTauMode tauflag = TUnfoldDensity::kEScanTauRhoMax;//crazy large correlations
   //TUnfoldDensity::EScanTauMode tauflag = TUnfoldDensity::kEScanTauRhoSqaureAvg;//crazy large correlations

   unfold_incchmult.ScanTau(nScan,tauMin,tauMax,&rhoScan_incchmult,tauflag);	  
   unfold_incchavgpt.ScanTau(nScan,tauMin,tauMax,&rhoScan_incchavgpt,tauflag);	  
   unfold_incchflux.ScanTau(nScan,tauMin,tauMax,&rhoScan_incchflux,tauflag);	  
   int iBest_incchmult = unfold_incchmult.ScanTau(nScan,tauMin,tauMax,&rhoScan_incchmult,tauflag);	  
   int iBest_incchavgpt = unfold_incchavgpt.ScanTau(nScan,tauMin,tauMax,&rhoScan_incchavgpt,tauflag);	  
   int iBest_incchflux = unfold_incchflux.ScanTau(nScan,tauMin,tauMax,&rhoScan_incchflux,tauflag);	  

   // create graphs with one point to visualize best choice of tau
   Double_t t_incchmult[1],rho_incchmult[1];//,x[1],y[1];
   Double_t t_incchavgpt[1],rho_incchavgpt[1];
   Double_t t_incchflux[1],rho_incchflux[1];
   rhoScan_incchmult->GetKnot(iBest_incchmult,t_incchmult[0],rho_incchmult[0]);
   rhoScan_incchavgpt->GetKnot(iBest_incchavgpt,t_incchavgpt[0],rho_incchavgpt[0]);
   rhoScan_incchflux->GetKnot(iBest_incchflux,t_incchflux[0],rho_incchflux[0]);
   TGraph *bestRho_incchmult=new TGraph(1,t_incchmult,rho_incchmult);
   TGraph *bestRho_incchavgpt=new TGraph(1,t_incchavgpt,rho_incchavgpt);
   TGraph *bestRho_incchflux=new TGraph(1,t_incchflux,rho_incchflux);
   Double_t *tAll_incchmult=new Double_t[nScan],*rhoAll_incchmult=new Double_t[nScan];
   Double_t *tAll_incchavgpt=new Double_t[nScan],*rhoAll_incchavgpt=new Double_t[nScan];
   Double_t *tAll_incchflux=new Double_t[nScan],*rhoAll_incchflux=new Double_t[nScan];
   for(Int_t i=0;i<nScan;i++) {
     rhoScan_incchmult->GetKnot(i,tAll_incchmult[i],rhoAll_incchmult[i]);
     rhoScan_incchavgpt->GetKnot(i,tAll_incchavgpt[i],rhoAll_incchavgpt[i]);
     rhoScan_incchflux->GetKnot(i,tAll_incchflux[i],rhoAll_incchflux[i]);
     //     cout<<i<<"  "<<tAll[i]<<"  "<<rhoAll[i]<<endl;
   }
   cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  TAU,iBest (incchmult) --> "<<t_incchmult[0]<<"  "<<unfold_incchmult.GetTau()<<"  "<<iBest_incchmult<<endl;
   cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  TAU,iBest (incchavgpt) --> "<<t_incchavgpt[0]<<"  "<<unfold_incchavgpt.GetTau()<<"  "<<iBest_incchavgpt<<endl;
   cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  TAU,iBest (incchflux)--> "<<t_incchflux[0]<<"  "<<unfold_incchflux.GetTau()<<"  "<<iBest_incchflux<<endl;



   float opt_tau_incchmult = unfold_incchmult.GetTau();
   float opt_tau_incchavgpt = unfold_incchavgpt.GetTau();
   float opt_tau_incchflux = unfold_incchflux.GetTau();


   //unfold.DoUnfold(t[0]);
   //unfold.DoUnfold(0,data_real,scaleBias); 
   //unfold.DoUnfold(0.0048949);
   //unfold.DoUnfold(0);
   //   TH1 *unfolded = unfold.GetOutput("unfolded",0,0,"*[UO]",kTRUE); //ignore underflow and overflow
   TH1 *unfolded_incchmult = unfold_incchmult.GetOutput("unfolded_incchmult",0,0,"",kFALSE);
   TH1 *unfolded_incchavgpt = unfold_incchavgpt.GetOutput("unfolded_incchavgpt",0,0,"",kFALSE);
   TH1 *unfolded_incchflux = unfold_incchflux.GetOutput("unfolded_incchflux",0,0,"",kFALSE);
   // TH1 *unfolded = unfold.GetOutput("unfolded",0,0,0,kTRUE);

   TGraph *knots_incchmult=new TGraph(nScan,tAll_incchmult,rhoAll_incchmult);
   TGraph *knots_incchavgpt=new TGraph(nScan,tAll_incchavgpt,rhoAll_incchavgpt);
   TGraph *knots_incchflux=new TGraph(nScan,tAll_incchflux,rhoAll_incchflux);
   cout<<"incchmult chi**2="<<unfold_incchmult.GetChi2A()<<"+"<<unfold_incchmult.GetChi2L()<<" / "<<unfold_incchmult.GetNdf()<<"\n";
   cout<<"incchavgpt chi**2="<<unfold_incchavgpt.GetChi2A()<<"+"<<unfold_incchavgpt.GetChi2L()<<" / "<<unfold_incchavgpt.GetNdf()<<"\n";
   cout<<"incchflux chi**2="<<unfold_incchflux.GetChi2A()<<"+"<<unfold_incchflux.GetChi2L()<<" / "<<unfold_incchflux.GetNdf()<<"\n";


   cout<<"TUnfold version is "<<TUnfold::GetTUnfoldVersion()<<"\n";

   TH1 *unfolded_toy_incchmult;
   if (toy_switch){
     rec_incchmult_toy->Scale(gen_incchmult->Integral()/rec_incchmult_toy->Integral());
     unfold_incchmult.SetInput(rec_incchmult_toy,scaleBias);
     cout<<"IN TOY SWITCH"<<endl;
     cout<<"using optimum tau:  "<<opt_tau_incchmult<<endl;
     unfold_incchmult.DoUnfold(opt_tau_incchmult);

     unfolded_toy_incchmult = unfold_incchmult.GetOutput("unfolded_toy_incchmult",0,0,"",kFALSE);
   }

   
   //data_bkg_sub->Scale(gen_incchmult->Integral()/data_bkg_sub->Integral());//gerekli diil gibi!
   unfold_incchmult.SetInput(data_incchmult_bkg_sub,scaleBias);
   unfold_incchavgpt.SetInput(data_incchavgpt_bkg_sub,scaleBias);
   unfold_incchflux.SetInput(data_incchflux_bkg_sub,scaleBias);

   unfold_incchmult.DoUnfold(opt_tau_incchmult);
   unfold_incchavgpt.DoUnfold(opt_tau_incchavgpt);
   unfold_incchflux.DoUnfold(opt_tau_incchflux);
   //unfold.DoUnfold(0);
   TH1 *unfolded_data_incchmult = unfold_incchmult.GetOutput("unfolded_data_incchmult",0,0,"",kFALSE);
   TH1 *unfolded_data_incchavgpt = unfold_incchavgpt.GetOutput("unfolded_data_incchavgpt",0,0,"",kFALSE);
   TH1 *unfolded_data_incchflux = unfold_incchflux.GetOutput("unfolded_data_incchflux",0,0,"",kFALSE);
   TH1 *folded_data_incchmult = unfold_incchmult.GetFoldedOutput("folded_data_incchmult",0,0,"",kFALSE);
   TH1 *folded_data_incchavgpt = unfold_incchavgpt.GetFoldedOutput("folded_data_incchavgpt",0,0,"",kFALSE);
   TH1 *folded_data_incchflux = unfold_incchflux.GetFoldedOutput("folded_data_incchflux",0,0,"",kFALSE);

   TH2 *EMatrixTotal_data_incchmult = unfold_incchmult.GetEmatrixTotal("unfolding total error matrix for incchmult");
   TH2 *EMatrixTotal_data_incchavgpt = unfold_incchavgpt.GetEmatrixTotal("unfolding total error matrix for incchavgpt");
   TH2 *EMatrixTotal_data_incchflux = unfold_incchflux.GetEmatrixTotal("unfolding total error matrix for incchflux");


   //unfold.SetInput(rec_incchmult_toy,scaleBias);

   // unfold.SetBias(gen_incchmult_real);

   //unfold.DoUnfold(0);//orig loc. 

   //unfold.SetInput(data_bkg_sub,scaleBias);//unfold data

   
   TCanvas *tcanv = new TCanvas();
   tcanv->Divide(2,2);
   tcanv->cd(1);
   rhoScan_incchmult->Draw();
   rhoScan_incchmult->SetTitle(";log_{10}(#tau);average(#rho_{i})");
   rhoScan_incchmult->SetLineColor(kRed);
   bestRho_incchmult->Draw("*");

   tcanv->cd(2);
   rhoScan_incchavgpt->Draw();
   rhoScan_incchavgpt->SetTitle(";log_{10}(#tau);average(#rho_{i})");
   rhoScan_incchavgpt->SetLineColor(kRed);
   bestRho_incchavgpt->Draw("*");

   tcanv->cd(3);
   rhoScan_incchflux->Draw();
   rhoScan_incchflux->SetTitle(";log_{10}(#tau);average(#rho_{i})");
   rhoScan_incchflux->SetLineColor(kRed);
   bestRho_incchflux->Draw("*");

   tcanv->SaveAs("knots.C");
   tcanv->SaveAs("knots.pdf");  
 
   TCanvas *c2 = new TCanvas();
   c2->Divide(2,2);
   //   float scale = rec_incchmult_real->GetSumOfWeights()/gen_incchmult_real->GetSumOfWeights();
   c2->cd(1);
   gen_incchmult->SetMarkerStyle(8);
   gen_incchmult->SetMarkerColor(2);
   gen_incchmult->SetLineColor(2);
   gen_incchmult->SetLineWidth(2); 
   gen_incchmult->Draw();
   /*
   unfolded_incchmult->SetMarkerColor(2);
   unfolded_incchmult->SetLineColor(2);
   unfolded_incchmult->SetLineStyle(2);
   unfolded_incchmult->SetMarkerStyle(8);
   unfolded_incchmult->Draw("sames");
   */
   unfolded_data_incchmult->SetMarkerStyle(21);
   unfolded_data_incchmult->SetMarkerColor(4);
   unfolded_data_incchmult->SetLineColor(4);
   unfolded_data_incchmult->SetLineWidth(2);
   unfolded_data_incchmult->Draw("sames");

   c2->cd(2);
   gen_incchavgpt->SetMarkerStyle(8);
   gen_incchavgpt->SetMarkerColor(2);
   gen_incchavgpt->SetLineColor(2);
   gen_incchavgpt->SetLineWidth(2); 
   gen_incchavgpt->Draw();
   /*
   unfolded_incchavgpt->SetMarkerColor(2);
   unfolded_incchavgpt->SetLineColor(2);
   unfolded_incchavgpt->SetLineStyle(2);
   unfolded_incchavgpt->SetMarkerStyle(8);
   unfolded_incchavgpt->Draw("sames");
   */
   unfolded_data_incchavgpt->SetMarkerStyle(21);
   unfolded_data_incchavgpt->SetMarkerColor(4);
   unfolded_data_incchavgpt->SetLineColor(4);
   unfolded_data_incchavgpt->SetLineWidth(2);
   unfolded_data_incchavgpt->Draw("sames");

   c2->cd(3);
   gen_incchflux->SetMarkerStyle(8);
   gen_incchflux->SetMarkerColor(2);
   gen_incchflux->SetLineColor(2);
   gen_incchflux->SetLineWidth(2); 
   gen_incchflux->Draw();
   /*
   unfolded_incchflux->SetMarkerColor(2);
   unfolded_incchflux->SetLineColor(2);
   unfolded_incchflux->SetLineStyle(2);
   unfolded_incchflux->SetMarkerStyle(8);
   unfolded_incchflux->Draw("sames");
   */
   unfolded_data_incchflux->SetMarkerStyle(21);
   unfolded_data_incchflux->SetMarkerColor(4);
   unfolded_data_incchflux->SetLineColor(4);
   unfolded_data_incchflux->SetLineWidth(2);
   unfolded_data_incchflux->Draw("sames");

   c2->Update();
   c2->SaveAs("unfolded.C");
   
   cout<<"before pulls"<<endl;
   ofstream pulls_file,pulls_file_bin[5];
   pulls_file.open("pulls_file.txt",ios::app);

   char namepullbinfile[100];
   for (int i =0;i<5;i++){ 
     sprintf(namepullbinfile,"pulls_file_bin%i.txt",i);
     pulls_file_bin[i].open(namepullbinfile,ios::app);
   }
   h_PULLS = new TH1D("h_PULLS","h_PULLS",100,-5,5);
  
   float pull = -99.;
   float pull_b[5];
   TCanvas *c_pull = new TCanvas();
   c_pull->cd();
   for (int i=0;i<5;i++){ 
     //if (unfolded->GetBinError(i+1)) 
     pull_b[i] = -999.;
     pull = (unfolded_toy_incchmult->GetBinContent(i+1)-gen_incchmult->GetBinContent(i+1))/unfolded_toy_incchmult->GetBinError(i+1);
     pull_b[i] = (unfolded_toy_incchmult->GetBinContent(i+1)-gen_incchmult->GetBinContent(i+1))/unfolded_toy_incchmult->GetBinError(i+1);
     h_PULLS->Fill(pull);
     cout<<"pull toy, gen toy, err:  "<<unfolded_toy_incchmult->GetBinContent(i+1)<<"  "<<gen_incchmult->GetBinContent(i+1)<<"  "<<unfolded_toy_incchmult->GetBinError(i+1)<<endl;
     cout<<"pull:   "<<pull<<endl;
     pulls_file<< pull <<"\n";
     pulls_file_bin[i]<<pull_b[i]<<"\n";
   }
   pulls_file.close();
   for (int i =0;i<5;i++) pulls_file_bin[i].close();
   h_PULLS->Draw();
   c_pull->SaveAs("pull.C");

  
   TCanvas *c4 = new TCanvas();
   c4->Divide(2,2);
   c4->cd(1);
   data_incchmult_bkg_sub->Draw();
   folded_data_incchmult->SetLineColor(4);
   folded_data_incchmult->SetMarkerColor(4);
   folded_data_incchmult->Draw("sames");

   c4->cd(2);
   data_incchavgpt_bkg_sub->Draw();
   folded_data_incchavgpt->SetLineColor(4);
   folded_data_incchavgpt->SetMarkerColor(4);
   folded_data_incchavgpt->Draw("sames");

   c4->cd(3);
   data_incchflux_bkg_sub->Draw();
   folded_data_incchflux->SetLineColor(4);
   folded_data_incchflux->SetMarkerColor(4);
   folded_data_incchflux->Draw("sames");
   c4->SaveAs("folded.C");

  TCanvas *c5 = new TCanvas();
  c5->cd(1);
  gen_incchmult->SetLineColor(1);
  gen_incchmult->SetLineWidth(2);
  gen_incchmult->Draw("e1");
  unfolded_incchmult->SetMarkerColor(2);
  unfolded_incchmult->SetLineColor(2);
  unfolded_incchmult->SetLineStyle(2);
  unfolded_incchmult->SetMarkerStyle(8);
  unfolded_incchmult->Draw("sames");
  unfolded_data_incchmult->SetMarkerColor(4);
  unfolded_data_incchmult->SetLineColor(4);
  unfolded_data_incchmult->SetLineStyle(3);
  unfolded_data_incchmult->Draw("sames");
  c5->SaveAs("unfolded_incmult_and_sqrtN.C");

  TCanvas *c6 = new TCanvas();
  c6->Divide(2,2);
  c6->cd(1);
  EMatrixTotal_data_incchmult->Draw("colz");
  c6->cd(2);
  EMatrixTotal_data_incchavgpt->Draw("colz");
  c6->cd(3);
  EMatrixTotal_data_incchflux->Draw("colz");
  c6->SaveAs("error_matrices.C");
  c6->SaveAs("error_matrices.pdf");
}

int main(int argc, char* argv[]){
  cout<<argv[1]<<"  "<<argv[2]<<"  "<<argv[3]<<endl;
  sprintf(file_name,argv[1]);
  sprintf(file_toy,argv[2]);
  toy_switch = argv[3];
  UEUnfold();
}
