void brazilianFlag_QtoqW_Combineddb_13TeV()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Oct 14 14:19:27 2019) by ROOT version 6.12/07
   TCanvas *c1 = new TCanvas("c1", "c1",2480,372,800,600);
   c1->SetHighLightColor(2);
   c1->Range(0.9,-6.004845,6.733333,2.368867);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLogy();
   c1->SetLeftMargin(0.12);
   c1->SetRightMargin(0.04);
   c1->SetTopMargin(0.08);
   c1->SetBottomMargin(0.12);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *hframe__1 = new TH1F("hframe__1","",1000,1.6,6.5);
   hframe__1->SetMinimum(1e-05);
   hframe__1->SetMaximum(50);
   hframe__1->SetDirectory(0);
   hframe__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hframe__1->SetLineColor(ci);
   hframe__1->GetXaxis()->SetTitle("M_{jj} (TeV)");
   hframe__1->GetXaxis()->SetNdivisions(508);
   hframe__1->GetXaxis()->SetLabelFont(42);
   hframe__1->GetXaxis()->SetTitleSize(0.05);
   hframe__1->GetXaxis()->SetTitleOffset(1.05);
   hframe__1->GetXaxis()->SetTitleFont(42);
   hframe__1->GetYaxis()->SetTitle("#sigma_{95%} x B(q* #rightarrow qW) (pb)");
   hframe__1->GetYaxis()->SetLabelFont(42);
   hframe__1->GetYaxis()->SetTitleSize(0.05);
   hframe__1->GetYaxis()->SetTitleOffset(1.15);
   hframe__1->GetYaxis()->SetTitleFont(42);
   hframe__1->GetZaxis()->SetLabelFont(42);
   hframe__1->GetZaxis()->SetLabelSize(0.035);
   hframe__1->GetZaxis()->SetTitleSize(0.035);
   hframe__1->GetZaxis()->SetTitleFont(42);
   hframe__1->Draw(" ");
   
   Double_t Graph0_fx1[22] = {
   1.6,
   1.8,
   2,
   2.5,
   3,
   3.5,
   4,
   4.5,
   5,
   6,
   7,
   7,
   6,
   5,
   4.5,
   4,
   3.5,
   3,
   2.5,
   2,
   1.8,
   1.6};
   Double_t Graph0_fy1[22] = {
   0.03484131,
   0.0220752,
   0.01764343,
   0.007159424,
   0.003480606,
   0.001795044,
   0.000953331,
   0.0005430222,
   0.000334053,
   0.0001703644,
   8.857727e-05,
   0.0005337941,
   0.0009017014,
   0.001470846,
   0.002200692,
   0.003606872,
   0.006570354,
   0.01244627,
   0.02520962,
   0.06288103,
   0.08424838,
   0.1297908};
   TGraph *graph = new TGraph(22,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#ffcc00");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#ffcc00");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,1.06,7.54);
   Graph_Graph1->SetMinimum(7.971954e-05);
   Graph_Graph1->SetMaximum(0.142761);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("f");
   
   Double_t Graph1_fx2[22] = {
   1.6,
   1.8,
   2,
   2.5,
   3,
   3.5,
   4,
   4.5,
   5,
   6,
   7,
   7,
   6,
   5,
   4.5,
   4,
   3.5,
   3,
   2.5,
   2,
   1.8,
   1.6};
   Double_t Graph1_fy2[22] = {
   0.04698458,
   0.03001369,
   0.02362988,
   0.009502935,
   0.004637963,
   0.00241374,
   0.001285596,
   0.0007403898,
   0.0004606071,
   0.0002442563,
   0.0001303029,
   0.0003472147,
   0.0006007754,
   0.001016882,
   0.001559514,
   0.0026126,
   0.004793095,
   0.009174166,
   0.01868109,
   0.04650448,
   0.06141362,
   0.09495185};
   graph = new TGraph(22,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00cc00");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#00cc00");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,1.06,7.54);
   Graph_Graph2->SetMinimum(0.0001172726);
   Graph_Graph2->SetMaximum(0.104434);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleOffset(0);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("f");
   
   Double_t Graph2_fx1001[11] = {
   1.6,
   1.8,
   2,
   2.5,
   3,
   3.5,
   4,
   4.5,
   5,
   6,
   7};
   Double_t Graph2_fy1001[11] = {
   0.0665625,
   0.0428125,
   0.03296875,
   0.01328125,
   0.006503906,
   0.003378906,
   0.001821289,
   0.001069336,
   0.0006787109,
   0.0003759766,
   0.0002099609};
   Double_t Graph2_fex1001[11] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fey1001[11] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   TGraphErrors *gre = new TGraphErrors(11,Graph2_fx1001,Graph2_fy1001,Graph2_fex1001,Graph2_fey1001);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineStyle(2);
   gre->SetLineWidth(4);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,1.06,7.54);
   Graph_Graph1001->SetMinimum(0.0001889648);
   Graph_Graph1001->SetMaximum(0.07319775);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw("lp");
   
   Double_t Graph3_fx1002[11] = {
   1.6,
   1.8,
   2,
   2.5,
   3,
   3.5,
   4,
   4.5,
   5,
   6,
   7};
   Double_t Graph3_fy1002[11] = {
   0.1237402,
   0.05422329,
   0.04657774,
   0.01108957,
   0.00501591,
   0.004083535,
   0.001266371,
   0.001230623,
   0.001490311,
   0.0003393463,
   0.0004594696};
   Double_t Graph3_fex1002[11] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph3_fey1002[11] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   gre = new TGraphErrors(11,Graph3_fx1002,Graph3_fy1002,Graph3_fex1002,Graph3_fey1002);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(8);
   gre->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,1.06,7.54);
   Graph_Graph1002->SetMinimum(0.0003054116);
   Graph_Graph1002->SetMaximum(0.1360803);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw("lp");
   
   Double_t QtoqW_gtheory_fx1003[12] = {
   1.6,
   1.8,
   2,
   2.5,
   3,
   3.5,
   4,
   4.5,
   5,
   5.5,
   6,
   6.5};
   Double_t QtoqW_gtheory_fy1003[12] = {
   11.06,
   6.002,
   3.306,
   0.8839,
   0.267,
   0.08597,
   0.02913,
   0.009895,
   0.003453,
   0.001208,
   0.0004144,
   0.0001445};
   Double_t QtoqW_gtheory_fex1003[12] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t QtoqW_gtheory_fey1003[12] = {
   0.614936,
   0.3637212,
   0.2195184,
   0.0760154,
   0.0305982,
   0.01340272,
   0.006044475,
   0.002675608,
   0.001192321,
   0.0005150912,
   0.0002111368,
   8.382445e-05};
   gre = new TGraphErrors(12,QtoqW_gtheory_fx1003,QtoqW_gtheory_fy1003,QtoqW_gtheory_fex1003,QtoqW_gtheory_fey1003);
   gre->SetName("QtoqW_gtheory");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);
   
   TH1F *Graph_QtoqW_gtheory1003 = new TH1F("Graph_QtoqW_gtheory1003","Graph",100,1.11,6.99);
   Graph_QtoqW_gtheory1003->SetMinimum(5.4608e-05);
   Graph_QtoqW_gtheory1003->SetMaximum(12.84242);
   Graph_QtoqW_gtheory1003->SetDirectory(0);
   Graph_QtoqW_gtheory1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_QtoqW_gtheory1003->SetLineColor(ci);
   Graph_QtoqW_gtheory1003->GetXaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheory1003->GetXaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheory1003->GetXaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheory1003->GetXaxis()->SetTitleFont(42);
   Graph_QtoqW_gtheory1003->GetYaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheory1003->GetYaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheory1003->GetYaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheory1003->GetYaxis()->SetTitleOffset(0);
   Graph_QtoqW_gtheory1003->GetYaxis()->SetTitleFont(42);
   Graph_QtoqW_gtheory1003->GetZaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheory1003->GetZaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheory1003->GetZaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheory1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_QtoqW_gtheory1003);
   
   gre->Draw("l");
   
   Double_t QtoqW_gtheoryUP_fx3[12] = {
   1.6,
   1.8,
   2,
   2.5,
   3,
   3.5,
   4,
   4.5,
   5,
   5.5,
   6,
   6.5};
   Double_t QtoqW_gtheoryUP_fy3[12] = {
   11.67494,
   6.365721,
   3.525518,
   0.9599154,
   0.2975982,
   0.09937272,
   0.03517447,
   0.01257061,
   0.004645321,
   0.001723091,
   0.0006255368,
   0.0002283244};
   graph = new TGraph(12,QtoqW_gtheoryUP_fx3,QtoqW_gtheoryUP_fy3);
   graph->SetName("QtoqW_gtheoryUP");
   graph->SetTitle("Graph");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   
   TH1F *Graph_QtoqW_gtheoryUP3 = new TH1F("Graph_QtoqW_gtheoryUP3","Graph",100,1.11,6.99);
   Graph_QtoqW_gtheoryUP3->SetMinimum(0.000205492);
   Graph_QtoqW_gtheoryUP3->SetMaximum(12.84241);
   Graph_QtoqW_gtheoryUP3->SetDirectory(0);
   Graph_QtoqW_gtheoryUP3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_QtoqW_gtheoryUP3->SetLineColor(ci);
   Graph_QtoqW_gtheoryUP3->GetXaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheoryUP3->GetXaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheoryUP3->GetXaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheoryUP3->GetXaxis()->SetTitleFont(42);
   Graph_QtoqW_gtheoryUP3->GetYaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheoryUP3->GetYaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheoryUP3->GetYaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheoryUP3->GetYaxis()->SetTitleOffset(0);
   Graph_QtoqW_gtheoryUP3->GetYaxis()->SetTitleFont(42);
   Graph_QtoqW_gtheoryUP3->GetZaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheoryUP3->GetZaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheoryUP3->GetZaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheoryUP3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_QtoqW_gtheoryUP3);
   
   graph->Draw("l");
   
   Double_t QtoqW_gtheoryDOWN_fx4[12] = {
   1.6,
   1.8,
   2,
   2.5,
   3,
   3.5,
   4,
   4.5,
   5,
   5.5,
   6,
   6.5};
   Double_t QtoqW_gtheoryDOWN_fy4[12] = {
   10.44506,
   5.638279,
   3.086482,
   0.8078846,
   0.2364018,
   0.07256728,
   0.02308552,
   0.007219392,
   0.002260679,
   0.0006929088,
   0.0002032632,
   6.067555e-05};
   graph = new TGraph(12,QtoqW_gtheoryDOWN_fx4,QtoqW_gtheoryDOWN_fy4);
   graph->SetName("QtoqW_gtheoryDOWN");
   graph->SetTitle("Graph");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   
   TH1F *Graph_QtoqW_gtheoryDOWN4 = new TH1F("Graph_QtoqW_gtheoryDOWN4","Graph",100,1.11,6.99);
   Graph_QtoqW_gtheoryDOWN4->SetMinimum(5.4608e-05);
   Graph_QtoqW_gtheoryDOWN4->SetMaximum(11.48956);
   Graph_QtoqW_gtheoryDOWN4->SetDirectory(0);
   Graph_QtoqW_gtheoryDOWN4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_QtoqW_gtheoryDOWN4->SetLineColor(ci);
   Graph_QtoqW_gtheoryDOWN4->GetXaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheoryDOWN4->GetXaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheoryDOWN4->GetXaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheoryDOWN4->GetXaxis()->SetTitleFont(42);
   Graph_QtoqW_gtheoryDOWN4->GetYaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheoryDOWN4->GetYaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheoryDOWN4->GetYaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheoryDOWN4->GetYaxis()->SetTitleOffset(0);
   Graph_QtoqW_gtheoryDOWN4->GetYaxis()->SetTitleFont(42);
   Graph_QtoqW_gtheoryDOWN4->GetZaxis()->SetLabelFont(42);
   Graph_QtoqW_gtheoryDOWN4->GetZaxis()->SetLabelSize(0.035);
   Graph_QtoqW_gtheoryDOWN4->GetZaxis()->SetTitleSize(0.035);
   Graph_QtoqW_gtheoryDOWN4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_QtoqW_gtheoryDOWN4);
   
   graph->Draw("l");
   TLatex *   tex = new TLatex(0.96,0.936,"137.19 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.12,0.976,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(61);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.12,0.973,"              (personal work)");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0456);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *hframe_copy__2 = new TH1F("hframe_copy__2","",1000,1.6,6.5);
   hframe_copy__2->SetMinimum(1e-05);
   hframe_copy__2->SetMaximum(50);
   hframe_copy__2->SetDirectory(0);
   hframe_copy__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   hframe_copy__2->SetLineColor(ci);
   hframe_copy__2->GetXaxis()->SetTitle("M_{jj} (TeV)");
   hframe_copy__2->GetXaxis()->SetNdivisions(508);
   hframe_copy__2->GetXaxis()->SetLabelFont(42);
   hframe_copy__2->GetXaxis()->SetTitleSize(0.05);
   hframe_copy__2->GetXaxis()->SetTitleOffset(1.05);
   hframe_copy__2->GetXaxis()->SetTitleFont(42);
   hframe_copy__2->GetYaxis()->SetTitle("#sigma_{95%} x B(q* #rightarrow qW) (pb)");
   hframe_copy__2->GetYaxis()->SetLabelFont(42);
   hframe_copy__2->GetYaxis()->SetTitleSize(0.05);
   hframe_copy__2->GetYaxis()->SetTitleOffset(1.15);
   hframe_copy__2->GetYaxis()->SetTitleFont(42);
   hframe_copy__2->GetZaxis()->SetLabelFont(42);
   hframe_copy__2->GetZaxis()->SetLabelSize(0.035);
   hframe_copy__2->GetZaxis()->SetTitleSize(0.035);
   hframe_copy__2->GetZaxis()->SetTitleFont(42);
   hframe_copy__2->Draw("sameaxis");
   
   TH1F *hframe_copy__3 = new TH1F("hframe_copy__3","",1000,1.6,6.5);
   hframe_copy__3->SetMinimum(1e-05);
   hframe_copy__3->SetMaximum(50);
   hframe_copy__3->SetDirectory(0);
   hframe_copy__3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hframe_copy__3->SetLineColor(ci);
   hframe_copy__3->GetXaxis()->SetTitle("M_{jj} (TeV)");
   hframe_copy__3->GetXaxis()->SetNdivisions(508);
   hframe_copy__3->GetXaxis()->SetLabelFont(42);
   hframe_copy__3->GetXaxis()->SetTitleSize(0.05);
   hframe_copy__3->GetXaxis()->SetTitleOffset(1.05);
   hframe_copy__3->GetXaxis()->SetTitleFont(42);
   hframe_copy__3->GetYaxis()->SetTitle("#sigma_{95%} x B(q* #rightarrow qW) (pb)");
   hframe_copy__3->GetYaxis()->SetLabelFont(42);
   hframe_copy__3->GetYaxis()->SetTitleSize(0.05);
   hframe_copy__3->GetYaxis()->SetTitleOffset(1.15);
   hframe_copy__3->GetYaxis()->SetTitleFont(42);
   hframe_copy__3->GetZaxis()->SetLabelFont(42);
   hframe_copy__3->GetZaxis()->SetLabelSize(0.035);
   hframe_copy__3->GetZaxis()->SetTitleSize(0.035);
   hframe_copy__3->GetZaxis()->SetTitleFont(42);
   hframe_copy__3->Draw("sameaxig");
   
   TLegend *leg = new TLegend(0.5,0.6002591,0.9446734,0.9011917,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.038);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph3","Observed","Lp");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(0.8);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Expected #pm 1 std. deviation","f");

   ci = TColor::GetColor("#00cc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#00cc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","Expected #pm 2 std. deviation","f");

   ci = TColor::GetColor("#ffcc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("QtoqW_gtheory","#sigma_{TH}#timesBR(q*#rightarrowqW)","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.5,0.6002591,0.9446734,0.9011917,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.038);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("Graph3"," ","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
