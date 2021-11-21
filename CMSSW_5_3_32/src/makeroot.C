void makeroot(){

	TFile *f = TFile::Open("VBF_20210926.root","read");
	TTree *t1 = (TTree*)f->Get("demo/Events");
	//f->GetObject("demo/Events",t1);



	TFile *f_new = TFile::Open("jy_skimmed.root","recreate");



//	TFile *g = new TFile("ggH_muon_tau.root");
	TFile *g = new TFile("ggH_20210926.root");
	TTree *t2 = (TTree*)g->Get("demo/Events");
	//g->GetObject("demo/Events",t2);

	//gROOT->cd();
	//t1->Draw("muon_eta>>h1","","");
	//t2->Draw("muon_eta>>h2","","same");
	
	Int_t default_nbin = 30;

	TH1F *h1 = new TH1F("histo1","VBF_Muon_Eta", default_nbin, -2.5, 2.5);
	TH1F *h2 = new TH1F("histo2","ggH_Muon_Eta", default_nbin, -2.5, 2.5);


	TH1F *h3 = new TH1F("histo3","VBF_Muon_pT", default_nbin, 15, 70);
	TH1F *h4 = new TH1F("histo4","ggH_Muon_pT", default_nbin, 15, 70);
	TH1F *h5 = new TH1F("histo5","VBF_Muon_Phi", default_nbin, -3.14, 3.14);
	TH1F *h6 = new TH1F("histo6","ggH_Muon_Phi", default_nbin, -3.14, 3.14);
//	h1 = t1->GetHistogram("muon_eta");


	std::vector<float> *VBF_muon_eta=0;
	std::vector<float> *ggH_muon_eta=0;

	std::vector<float> *VBF_muon_pT=0;
	std::vector<float> *ggH_muon_pT=0;
	std::vector<float> *VBF_muon_Phi=0;
	std::vector<float> *ggH_muon_Phi=0;

//, muon_eta2;


	t1->SetBranchAddress("muon_eta",&VBF_muon_eta);
//	t1->Print();
	t2->SetBranchAddress("muon_eta",&ggH_muon_eta);

	t1->SetBranchAddress("muon_pt",&VBF_muon_pT);
	t2->SetBranchAddress("muon_pt",&ggH_muon_pT);
	t1->SetBranchAddress("muon_phi",&VBF_muon_Phi);
	t2->SetBranchAddress("muon_phi",&ggH_muon_Phi);

/*

	for (int i=0; i<t1->GetEntries(); i++){V
		t1->GetEntry(i);
		h1->Fill(muon_eta);
	}

*/

	for (int i=0; i<t1->GetEntries(); i++){
		t1->GetEntry(i);


		for(int j = 0; j < VBF_muon_eta->size(); j++){

			h1->Fill((*VBF_muon_eta)[j]);		
		}	
	
		for(int k = 0; k < VBF_muon_pT->size(); k++){


			h3->Fill((*VBF_muon_pT)[k]);		
		}	
		for(int l = 0; l < VBF_muon_Phi->size(); l++){


			h5->Fill((*VBF_muon_Phi)[l]);		
		}	

	}





	for (int i=0; i<t2->GetEntries(); i++){
		t2->GetEntry(i);


		for(int j = 0; j < ggH_muon_eta->size(); j++){

			h2->Fill((*ggH_muon_eta)[j]);		
		}	
		for(int k = 0; k < ggH_muon_pT->size(); k++){

			h4->Fill((*ggH_muon_pT)[k]);		
		}	

		for(int l = 0; l < ggH_muon_Phi->size(); l++){


			h6->Fill((*ggH_muon_Phi)[l]);		
		}	
	}

	h1->Scale(1/h1->Integral());
	h2->Scale(1/h2->Integral());
	h3->Scale(1/h3->Integral());
	h4->Scale(1/h4->Integral());
	h5->Scale(1/h5->Integral());
	h6->Scale(1/h6->Integral());


/*
	for (int i=0; i<t2->GetEntries(); i++){
		t2->GetEntry(i);
		h2->Fill(muon_eta2);
	}
*/

	//TGraph* gr = new TGraph(t1->GetEntries());


	f_new->cd();
	f_new->Write();
	h1->Write();
	h2->Write();
	h3->Write();
	h4->Write();
	h5->Write();
	h6->Write();

	t1->Print();

//        t1->Write();
//        t2->Write();


	//gr->Write();

	f->Close();
	g->Close();
	f_new->Close();


	new TBrowser();
	}
