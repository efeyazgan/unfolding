#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void plot_pulls() {
  gStyle->SetOptFit(1);
  ifstream ifile,ifilebin[5];
  float pull, pullbin[5];
  TH1D *h_PULLS = new TH1D("h_PULLS","h_PULLS",18,-5,5);
  ifile.open("pulls_file.txt");
  while(1){
    if (!ifile.good()) break;
    ifile >> pull;
    h_PULLS->Fill(pull);
  }
  h_PULLS->Fit("gaus");
  h_PULLS->Draw();
  h_PULLS->SaveAs("pull_histo.C");

  TH1D *h_PULLS_BIN[5];
  char hname[100],fname[100];
  for (int i=0;i<5;i++){ 
    sprintf(hname,"pulls_bin_%i",i);
    h_PULLS_BIN[i] = new TH1D(hname,hname,17,-4,4);//18
    sprintf(fname,"pulls_file_bin%i.txt",i);
    ifilebin[i].open(fname);
  }


  TCanvas *c_p = new TCanvas();
  c_p->Divide(3,2);
  TF1 *fit[5];
  float mean[5];
  float sigma[5];
  float bins[5];
  int itest = 0;

  for (int i=0;i<5;i++){
    while(1){
      if (!ifilebin[i].good()) break;
      ifilebin[i] >> pullbin[i];
      h_PULLS_BIN[i]->Fill(pullbin[i]);
      if (i==0){ 
        itest++;
	cout<<itest<<"  "<<pullbin[i]<<endl;  	
      }
    }
    bins[i] = i+0.5;
    c_p->cd(i+1);
    h_PULLS_BIN[i]->Draw();
    //    mean[i] = h_PULLS_BIN[i]->GetMean();
    //    sigma[i] = h_PULLS_BIN[i]->GetRMS();
    h_PULLS_BIN[i]->Fit("gaus");
    fit[i] = h_PULLS_BIN[i]->GetFunction("gaus");
    mean[i] = fit[i]->GetParameter(1);
    sigma[i] = fit[i]->GetParameter(2);
  }
  c_p->SaveAs("ind_pull_bin.C");
  c_p->SaveAs("ind_pull_bin.pdf");


  gr = new TGraphErrors(5,bins,mean,0,sigma);
  gr->SetTitle("Pulls");
  gr->GetXaxis()->SetTitle("Bin #");
  gr->GetYaxis()->SetTitle("Mean");
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->Draw("AP");
  gr->SaveAs("pulls_mean_sigma_vs_bin.C");

}
