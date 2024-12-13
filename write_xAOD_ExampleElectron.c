// authored: Jack Kraus, 2024/12/13
#include <vector>
#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TH1F.h"
#include "TBenchmark.h"
#include "TRandom.h"
#include "TSystem.h"

#include "xAOD::ExampleElectron/ExampleElectron.h"

int N = 1e5; // Number of events

void write() {

   TFile *f = TFile::Open("exampleElectron_test_write.root","RECREATE");

   if (!f) {
           std::cout<< "Error: xAOD::ExampleElectron_test_write: file error"<<std::endl;
        return;
   }

   xAOD::ExampleElectron e;
   
   // Create a TTree
   TTree *t = new TTree("t_electrons","Tree with ExampleElectrons");
   t->Branch("electrons",&e); // creates a branch in TTree t, called electrons


   gRandom->SetSeed();
   for (int i = 0; i < N; i++) {
     float p;
     p = 115.;
     e.setPt( p );

     float c;
     c = -1.0;
     e.setCharge( c );

     t->Fill();
   }

   t->Print();
   f->Write();

   delete f;
}

int write_xAOD_ExampleElectron() {
        gBenchmark = new TBenchmark();

        // Timed write()
        gBenchmark->Start("write_hvector");
        write();
        gBenchmark->Show("write_hvector");

   return 0;
}