void brazilianFlag_QtoqZ_2016db_13TeV()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Oct 30 14:03:38 2019) by ROOT version 6.12/07
   TCanvas *c1 = new TCanvas("c1", "c1",560,312,800,600);
   c1->SetHighLightColor(2);
   c1->Range(0.9,-6.121568,6.733333,3.224833);
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
   hframe__1->SetMaximum(300);
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
   hframe__1->GetYaxis()->SetTitle("#sigma_{95%} x B(q* #rightarrow qZ) (pb)");
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
   0.08113281,
   0.05322876,
   0.04147461,
   0.01450775,
   0.007776489,
   0.004482422,
   0.002586517,
   0.001605957,
   0.001092041,
   0.0005694336,
   0.000255498,
   0.001388955,
   0.002768665,
   0.004744516,
   0.006469322,
   0.009785938,
   0.01629995,
   0.02784792,
   0.05138174,
   0.1468896,
   0.1937164,
   0.2994362};
   TGraph *graph = new TGraph(22,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#ffcc00");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#ffcc00");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,1.06,7.54);
   Graph_Graph1->SetMinimum(0.0002299482);
   Graph_Graph1->SetMaximum(0.3293543);
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
   0.1094101,
   0.07186499,
   0.05554703,
   0.01943026,
   0.01041507,
   0.005996475,
   0.003487998,
   0.002201821,
   0.001514557,
   0.0008101494,
   0.0003698698,
   0.0009167988,
   0.001884192,
   0.003306566,
   0.004612174,
   0.007088342,
   0.01196888,
   0.02055516,
   0.03802335,
   0.1087008,
   0.1431833,
   0.2198729};
   graph = new TGraph(22,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#00cc00");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#00cc00");
   graph->SetLineColor(ci);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,1.06,7.54);
   Graph_Graph2->SetMinimum(0.0003328829);
   Graph_Graph2->SetMaximum(0.2418232);
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
   0.155,
   0.1009375,
   0.0775,
   0.02710938,
   0.01453125,
   0.0084375,
   0.004941406,
   0.0031625,
   0.00221875,
   0.001225,
   0.00057375};
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
   Graph_Graph1001->SetMinimum(0.000516375);
   Graph_Graph1001->SetMaximum(0.1704426);
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
   0.3313509,
   0.08452812,
   0.06362634,
   0.04146029,
   0.008719127,
   0.006592619,
   0.004519178,
   0.002615909,
   0.004059767,
   0.00179229,
   0.0009335065};
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
   Graph_Graph1002->SetMinimum(0.0008401559);
   Graph_Graph1002->SetMaximum(0.3643926);
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
   
   Double_t QtoqZ_gtheory_fx1003[12] = {
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
   Double_t QtoqZ_gtheory_fy1003[12] = {
   3.971,
   2.164,
   1.2,
   0.3168,
   0.0944,
   0.03035,
   0.01019,
   0.003495,
   0.00121,
   0.0004161,
   0.0001439,
   5.035e-05};
   Double_t QtoqZ_gtheory_fex1003[12] = {
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
   Double_t QtoqZ_gtheory_fey1003[12] = {
   0.2207876,
   0.1311384,
   0.07968,
   0.0272448,
   0.01081824,
   0.004731565,
   0.002114425,
   0.000945048,
   0.000417813,
   0.000177425,
   7.331705e-05,
   2.920803e-05};
   gre = new TGraphErrors(12,QtoqZ_gtheory_fx1003,QtoqZ_gtheory_fy1003,QtoqZ_gtheory_fex1003,QtoqZ_gtheory_fey1003);
   gre->SetName("QtoqZ_gtheory");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(3);
   
   TH1F *Graph_QtoqZ_gtheory1003 = new TH1F("Graph_QtoqZ_gtheory1003","Graph",100,1.11,6.99);
   Graph_QtoqZ_gtheory1003->SetMinimum(1.902777e-05);
   Graph_QtoqZ_gtheory1003->SetMaximum(4.610964);
   Graph_QtoqZ_gtheory1003->SetDirectory(0);
   Graph_QtoqZ_gtheory1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_QtoqZ_gtheory1003->SetLineColor(ci);
   Graph_QtoqZ_gtheory1003->GetXaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheory1003->GetXaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheory1003->GetXaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheory1003->GetXaxis()->SetTitleFont(42);
   Graph_QtoqZ_gtheory1003->GetYaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheory1003->GetYaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheory1003->GetYaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheory1003->GetYaxis()->SetTitleOffset(0);
   Graph_QtoqZ_gtheory1003->GetYaxis()->SetTitleFont(42);
   Graph_QtoqZ_gtheory1003->GetZaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheory1003->GetZaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheory1003->GetZaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheory1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_QtoqZ_gtheory1003);
   
   gre->Draw("l");
   
   Double_t QtoqZ_gtheoryUP_fx3[12] = {
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
   Double_t QtoqZ_gtheoryUP_fy3[12] = {
   4.191788,
   2.295138,
   1.27968,
   0.3440448,
   0.1052182,
   0.03508156,
   0.01230442,
   0.004440048,
   0.001627813,
   0.000593525,
   0.000217217,
   7.955803e-05};
   graph = new TGraph(12,QtoqZ_gtheoryUP_fx3,QtoqZ_gtheoryUP_fy3);
   graph->SetName("QtoqZ_gtheoryUP");
   graph->SetTitle("Graph");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   
   TH1F *Graph_QtoqZ_gtheoryUP3 = new TH1F("Graph_QtoqZ_gtheoryUP3","Graph",100,1.11,6.99);
   Graph_QtoqZ_gtheoryUP3->SetMinimum(7.160223e-05);
   Graph_QtoqZ_gtheoryUP3->SetMaximum(4.610958);
   Graph_QtoqZ_gtheoryUP3->SetDirectory(0);
   Graph_QtoqZ_gtheoryUP3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_QtoqZ_gtheoryUP3->SetLineColor(ci);
   Graph_QtoqZ_gtheoryUP3->GetXaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheoryUP3->GetXaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheoryUP3->GetXaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheoryUP3->GetXaxis()->SetTitleFont(42);
   Graph_QtoqZ_gtheoryUP3->GetYaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheoryUP3->GetYaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheoryUP3->GetYaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheoryUP3->GetYaxis()->SetTitleOffset(0);
   Graph_QtoqZ_gtheoryUP3->GetYaxis()->SetTitleFont(42);
   Graph_QtoqZ_gtheoryUP3->GetZaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheoryUP3->GetZaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheoryUP3->GetZaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheoryUP3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_QtoqZ_gtheoryUP3);
   
   graph->Draw("l");
   
   Double_t QtoqZ_gtheoryDOWN_fx4[12] = {
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
   Double_t QtoqZ_gtheoryDOWN_fy4[12] = {
   3.750212,
   2.032862,
   1.12032,
   0.2895552,
   0.08358176,
   0.02561843,
   0.008075575,
   0.002549952,
   0.000792187,
   0.000238675,
   7.058295e-05,
   2.114197e-05};
   graph = new TGraph(12,QtoqZ_gtheoryDOWN_fx4,QtoqZ_gtheoryDOWN_fy4);
   graph->SetName("QtoqZ_gtheoryDOWN");
   graph->SetTitle("Graph");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   
   TH1F *Graph_QtoqZ_gtheoryDOWN4 = new TH1F("Graph_QtoqZ_gtheoryDOWN4","Graph",100,1.11,6.99);
   Graph_QtoqZ_gtheoryDOWN4->SetMinimum(1.902777e-05);
   Graph_QtoqZ_gtheoryDOWN4->SetMaximum(4.125232);
   Graph_QtoqZ_gtheoryDOWN4->SetDirectory(0);
   Graph_QtoqZ_gtheoryDOWN4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_QtoqZ_gtheoryDOWN4->SetLineColor(ci);
   Graph_QtoqZ_gtheoryDOWN4->GetXaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheoryDOWN4->GetXaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheoryDOWN4->GetXaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheoryDOWN4->GetXaxis()->SetTitleFont(42);
   Graph_QtoqZ_gtheoryDOWN4->GetYaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheoryDOWN4->GetYaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheoryDOWN4->GetYaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheoryDOWN4->GetYaxis()->SetTitleOffset(0);
   Graph_QtoqZ_gtheoryDOWN4->GetYaxis()->SetTitleFont(42);
   Graph_QtoqZ_gtheoryDOWN4->GetZaxis()->SetLabelFont(42);
   Graph_QtoqZ_gtheoryDOWN4->GetZaxis()->SetLabelSize(0.035);
   Graph_QtoqZ_gtheoryDOWN4->GetZaxis()->SetTitleSize(0.035);
   Graph_QtoqZ_gtheoryDOWN4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_QtoqZ_gtheoryDOWN4);
   
   graph->Draw("l");
   TLatex *   tex = new TLatex(0.96,0.936,"35.9 fb^{-1} (13 TeV)");
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
   hframe_copy__2->SetMaximum(300);
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
   hframe_copy__2->GetYaxis()->SetTitle("#sigma_{95%} x B(q* #rightarrow qZ) (pb)");
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
   hframe_copy__3->SetMaximum(300);
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
   hframe_copy__3->GetYaxis()->SetTitle("#sigma_{95%} x B(q* #rightarrow qZ) (pb)");
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
   entry=leg->AddEntry("QtoqZ_gtheory","#sigma_{TH}#timesBR(q*#rightarrowqZ)","L");

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
