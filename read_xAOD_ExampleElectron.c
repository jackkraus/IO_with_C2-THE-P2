// authored: Jack Kraus, 24/12/13
#include <vector>
#include <cstdio>
#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TH1F.h"
#include "TBenchmark.h"
#include "TRandom.h"
#include "TSystem.h"
#include "TTreePerfStats.h"



int n = 1e2; // Number of events


void read() {
   TFile *f = TFile::Open("ExampleE_test_write.root","READ");
   
   if (!f) {
        std::cout<<"Error: ExampleE_test_write: file error"<<std::endl;
        return;
   }

   TTree *t = f->Get<TTree>("t_electrons");

   for (int i = 0; i < n; i++){
        t->Show( i );  
    }
}

int read_xAOD_ExampleElectron() {
   gBenchmark = new TBenchmark();
   // Timed read()
   gBenchmark->Start("read_ExampleElectron");
   read();
   gBenchmark->Show("read_ExampleElectron");

   return 0;
}