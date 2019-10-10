import ROOT as rt
import time
from ROOT import *
import os
import glob
import math
import array
import sys
sys.path.append('/nfs/dust/cms/user/zoiirene/LimitCode/CMSSW_8_1_0/src/DijetCombineLimitCode/Limits')
import CMS_lumi
#import tdrstyle
import time
import random
import numpy as np
import glob
from array import array

from optparse import OptionParser

CMS_lumi.lumi_13TeV = "35.9 fb^{-1}"
CMS_lumi.writeExtraText = 1
CMS_lumi.extraText = "              (personal work)"
CMS_lumi.lumi_sqrtS = "13 TeV" # used with iPeriod = 0, e.g. for simulation-only plots (default is an empty string)
iPos = 11
CMS_lumi.relPosY = -0.07
CMS_lumi.relPosX  = 0
CMS_lumi.relExtraDY = 0.05
if( iPos==0 ): CMS_lumi.relPosX = 0.12
iPeriod=4

def getIntersectionOfObservedLimitTheoryLine(mass,g,f):
    isu = mass*(1.5)
    isd = mass*(0.5)
    ism = mass
    NMAX = 100000;
    N =0
    resultUP = 0
    while ( N <= NMAX): # limit iterations to prevent infinite loop
        ism = (isu + isd)/2 # new midpoint
        fc = rt.TMath.Abs(f.Eval(ism)-g.Eval(ism))
        #print fc
        #print ism
        #print 
        if fc < 0.00000001 or rt.TMath.Abs((isd - isu)/2) <= 0.00000001: # solution found
            resultUP = ism
            break
        N = N + 1 # increment step counter
        fism = f.Eval(ism)-g.Eval(ism)
        fisu = f.Eval(isu)-g.Eval(isu)
        #print str(fism)+"    "+str(fisu)
        if np.sign(fism) == np.sign(fisu):
            isu = ism
        else:
            isd = ism # new interval
    return resultUP

def Plot(files, label, obs,CompareLimits=False,plotExpLimitRatio=""):

    radmasses = []
    efficiencies={}


    #fChain = []
    #for onefile in files:
        ## if onefile.find("2500")!=-1 or onefile.find("2500")!=-1: continue
        #fileIN = rt.TFile.Open(onefile)
        #fChain.append(fileIN.Get("limit;1"))

        #rt.gROOT.ProcessLine("struct limit_t {Double_t limit;};")
        #from ROOT import limit_t
        #limit_branch = limit_t()

        #for j in range(0,len(fChain)):
            #chain = fChain[j]
            #chain.SetBranchAddress("limit", rt.AddressOf(limit_branch,'limit'))

    #rad = []
    #for j in range(0,len(fChain)):
        #chain = fChain[j]
        #thisrad = []
        #for  i in range(0,6):
          #chain.GetTree().GetEntry(i)
          #thisrad.append(limit_branch.limit)
        #rad.append(thisrad)


    rad = []
    for onefile in files:
        print "using file " + onefile
        file = rt.TFile(onefile)
        tree = file.Get("limit")
        print tree
        limits = []
        for quantile in tree:
            if tree.limit >= 0.00001:
                limits.append(tree.limit)
                print ">>>   %.2f" % limits[-1]

        print "Got " + str(len(limits)) + " limits"
        if len(limits) == 6:
            mass = float(onefile[-9:-5]) / 1000.
            print "Mass: " + str(mass)
            radmasses.append(mass)
            rad.append(limits[:6])

    for mass in radmasses:
        efficiencies[mass]=1/100.0 # assume 1/pb signal cross section

    print limits
    mg = rt.TMultiGraph()
    mg.SetTitle("X -> ZZ")
    x = []
    yobs = []
    y2up = []
    y1up = []
    y1down = []
    y2down = []
    ymean = []

    for i in range(0,len(rad)):

        print "rad i 2 " + str(rad[i][2])
        print "radmasses i " + str(radmasses[i])
        print "efficiency  " + str(efficiencies[radmasses[i]])

        y2up.append(rad[i][0]*efficiencies[radmasses[i]])
        y1up.append(rad[i][1]*efficiencies[radmasses[i]])
        ymean.append(rad[i][2]*efficiencies[radmasses[i]])
        y1down.append(rad[i][3]*efficiencies[radmasses[i]])
        y2down.append(rad[i][4]*efficiencies[radmasses[i]])
        yobs.append(rad[i][5]*efficiencies[radmasses[i]])

    grobs = rt.TGraphErrors(1)
    grobs.SetMarkerStyle(8)
    grobs.SetMarkerSize(0.8)
    grobs.SetLineColor(rt.kBlack)
    grobs.SetLineWidth(2)
    gr2up = rt.TGraphErrors(1)
    gr2up.SetMarkerColor(0)
    gr1up = rt.TGraphErrors(1)
    gr1up.SetMarkerColor(0)
    grmean = rt.TGraphErrors(1)
    grmean.SetLineColor(1)
    grmean.SetLineWidth(4)
    grmean.SetLineStyle(2) #irene
    grmean.SetMarkerStyle(20) #irene
    gr1down = rt.TGraphErrors(1)
    gr1down.SetMarkerColor(0)
    gr2down = rt.TGraphErrors(1)
    gr2down.SetMarkerColor(0)

    for j in range(0,len(radmasses)):
        grobs.SetPoint(j, radmasses[j], yobs[j])
        gr2up.SetPoint(j, radmasses[j], y2up[j])
        gr1up.SetPoint(j, radmasses[j], y1up[j])
        grmean.SetPoint(j, radmasses[j], ymean[j])
        gr1down.SetPoint(j, radmasses[j], y1down[j])
        gr2down.SetPoint(j, radmasses[j], y2down[j])


    mg.Add(gr2up)#.Draw("same")
    mg.Add(gr1up)#.Draw("same")
    mg.Add(grmean,"L")#.Draw("same,AC*")
    mg.Add(gr1down)#.Draw("same,AC*")
    mg.Add(gr2down)#.Draw("same,AC*")
    if obs: mg.Add(grobs,"L")#.Draw("AC*")


    H_ref = 600;
    W_ref = 800;
    W = W_ref
    H  = H_ref

    T = 0.08*H_ref
    B = 0.12*H_ref
    L = 0.12*W_ref
    R = 0.04*W_ref

    c1 = rt.TCanvas("c1","c1",50,50,W,H)
    c1.SetFillColor(0)
    c1.SetBorderMode(0)
    c1.SetFrameFillStyle(0)
    c1.SetFrameBorderMode(0)
    c1.SetLeftMargin( L/W )
    c1.SetRightMargin( R/W )
    c1.SetTopMargin( T/H )
    c1.SetBottomMargin( B/H )
    c1.SetTickx(0)
    c1.SetTicky(0)
    c1.GetWindowHeight()
    c1.GetWindowWidth()
    c1.SetLogy()
    #c1.SetGrid()
    c1.SetLogy()
    c1.cd()

    frame = c1.DrawFrame(1.1,0.001, 4.2, 10)
    #if "qZ" in label.split("_")[0] or label.find("qW")!=-1: frame = c1.DrawFrame(1.1,0.001, 6.5, 800.)
    #frame.GetYaxis().CenterTitle()
    frame.GetYaxis().SetTitleSize(0.05)
    frame.GetXaxis().SetTitleSize(0.05)
    frame.GetXaxis().SetLabelSize(0.04)
    frame.GetYaxis().SetLabelSize(0.04)
    frame.GetYaxis().SetTitleOffset(1.15)
    frame.GetXaxis().SetTitleOffset(1.05)
    #frame.GetXaxis().CenterTitle()
    frame.SetMaximum(50)
    if "WZ" in label.split("_")[0] and ( label.find("_WZ")!=-1 or label.find("_VV")!=-1):
        frame.SetMinimum(0.0001)
        frame.SetMaximum(9)
    if label.find("_new_combined")!=-1:
        frame.SetMinimum(0.0001)
        frame.SetMaximum(109.)
    if (label.find("new")!=-1) and label.find("qW")!=-1 or label.find("qZ")!=-1:
        frame.SetMinimum(0.0002)
        frame.SetMaximum(300.)
    frame.GetXaxis().SetNdivisions(508)
    frame.SetMinimum(0.00001)
    #frame.GetYaxis().CenterTitle(True)

    if "graviton" in label.split("_")[0]:
        frame.GetXaxis().SetTitle("M_{G_{Bulk}} (TeV)")
        resonance="G_{Bulk}"
    if "radion" in label.split("_")[0]:
        resonance="R"
        frame.GetXaxis().SetTitle("M_{R} (TeV)")
    if "wprime" in label.split("_")[0]:
        resonance="W'"
        frame.GetXaxis().SetTitle("M_{W'} (TeV)")
    if "zprime" in label.split("_")[0]:
        resonance="Z'"
        frame.GetXaxis().SetTitle("M_{Z'} (TeV)")

#    frame.GetYaxis().SetTitle("#sigma_{95%} #times BR("+resonance+" #rightarrow WW"+label.split("_")[0].replace("graviton","").replace("radion","")+") (pb)") #irene
    frame.GetXaxis().SetTitle("M_{jj} (TeV)")
    if "qW" in label:
        resonance = "qW"
        frame.GetYaxis().SetTitle("#sigma_{95%} x B(q* #rightarrow qW) (pb)") #david
    if "qZ" in label:
        resonance = "qZ"
        frame.GetYaxis().SetTitle("#sigma_{95%} x B(q* #rightarrow qZ) (pb)") #david



    if(label.find("q")!=-1):
        mg.GetXaxis().SetLimits(1.6,6.5)
    elif "BulkZZ" in label.split("_")[0]:
        mg.GetXaxis().SetLimits(1.1,4.0)
    else:
        mg.GetXaxis().SetLimits(1.1,4.7)

    mg.GetXaxis().SetLimits(1.6,6.5)


    # histo to shade
    n=len(radmasses)

    grgreen = rt.TGraph(2*n)
    for i in range(0,n):
        grgreen.SetPoint(i,radmasses[i],y2up[i])
        grgreen.SetPoint(n+i,radmasses[n-i-1],y2down[n-i-1])

    grgreen.SetFillColor(rt.kOrange)
    grgreen.SetLineColor(rt.kOrange)
    grgreen.SetFillStyle(1001)
    grgreen.Draw("F")


    gryellow = rt.TGraph(2*n)
    for i in range(0,n):
        gryellow.SetPoint(i,radmasses[i],y1up[i])
        gryellow.SetPoint(n+i,radmasses[n-i-1],y1down[n-i-1])

    gryellow.SetFillColor(rt.kGreen+1)
    gryellow.SetLineColor(rt.kGreen+1)
    gryellow.SetFillStyle(1001)
    gryellow.Draw("Fsame")

    grmean.Draw("LP")
    if obs:
        grobs.Draw("LPsame")


    gtheory = rt.TGraphErrors(1)
    gtheoryUP = rt.TGraphErrors(1)
    gtheoryUP.SetLineColor(rt.kRed-2)
    gtheoryUP.SetLineWidth(3)
    gtheoryDOWN = rt.TGraphErrors(1)
    gtheoryDOWN.SetLineColor(rt.kRed-2)
    gtheoryDOWN.SetLineWidth(3)
    gtheorySHADE = rt.TGraphErrors(1)
    gtheorySHADE.SetLineColor(rt.kRed-2)
    gtheorySHADE.SetLineWidth(3)


    #filenameTH = "%s_xSecUnc.root"%label.split("_")[0]
    #thFile       = rt.TFile.Open(filenameTH,'READ')
    #print "Opening file " ,thFile.GetName()
    #gtheory      = thFile.Get("gtheory")
    x,y,ex,ey =  array('d'), array('d'), array('d'), array('d')
    for v in [1.6, 1.8, 2,2.5,3,3.5,4,4.5,5,5.5,6,6.5]:
        x.append(v)
    if "qW" in label:
        for v in [11.06, 6.002, 3.306, 0.8839, 0.2670, 0.08597, 0.02913, 0.009895, 0.003453, 0.001208, 0.0004144, 0.0001445]:
            y.append(v)
        for v in [11.06*0.0556, 6.002*0.0606, 3.306*0.0664, 0.8839*0.086, 0.2670*0.1146, 0.08597*0.1559, 0.02913*0.2075,
                0.009895*0.2704, 0.003453*0.3453, 0.001208*0.4264, 0.0004144*0.5095, 0.0001445*0.5801]:
            ey.append(v)
    elif "qZ" in label:
        for v in [3.971, 2.164, 1.2, 0.3168, 0.0944, 0.03035, 0.01019, 0.003495, 0.00121, 0.0004161, 0.0001439,
                0.00005035]:
            y.append(v)
        for v in [3.971*0.0556, 2.164*0.0606, 1.2*0.0664, 0.3168*0.086, 0.0944*0.1146, 0.03035*0.1559, 0.01019*0.2075,
                0.003495*0.2704, 0.00121*0.3453, 0.0004161*0.4264, 0.0001439*0.5095,0.00005035*0.5801]:
            ey.append(v)

    for v in [0,0,0,0,0,0,0,0,0,0,0,0]:
        ex.append(v)
    gtheory = rt.TGraphErrors(12, x, y, ex, ey)
    gtheory.SetLineColor(rt.kRed)
    gtheory.SetLineWidth(3)
    gtheoryUP    = rt.TGraph(12, x, np.add(y, ey))
    gtheoryDOWN  = rt.TGraph(12, x, np.subtract(y, ey))
    #gtheorySHADE = thFile.Get("grshade")
    gtheory     .SetName("%s_gtheory"    %label.split("_")[0] )
    gtheoryUP   .SetName("%s_gtheoryUP"  %label.split("_")[0] )
    gtheoryDOWN .SetName("%s_gtheoryDOWN"%label.split("_")[0] )
    #gtheorySHADE.SetName("%s_grshade"    %label.split("_")[0] )
    #gtheorySHADE.SetLineColor(0)
    gtheoryUP.SetLineColor(rt.kRed)
    gtheoryDOWN.SetLineColor(rt.kRed)
    gtheoryUP.SetLineWidth(1)
    gtheoryDOWN.SetLineWidth(1)
    if obs:
        print "max cross section (observed limit ) : " +str(round(rt.TMath.MaxElement(n,grobs.GetY()),5))+ " pb"
        print "min cross section (observed limit ) : " +str(round(rt.TMath.MinElement(n,grobs.GetY()),5))+ " pb"
    print "max cross section (expected limit ) : " +str(round(rt.TMath.MaxElement(n,grmean.GetY()),5))+ " pb"
    print "min cross section (expected limit ) : " +str(round(rt.TMath.MinElement(n,grmean.GetY()),5))+ " pb"

    #tmpmasses = grobs.GetX()
    #tmplimits = grobs.GetY()
    #tmplimitsexp = grmean.GetY()
    #tmptheory = gtheory.GetY()
    #for counter in  range(0,n):
    #    print "mass : "+str(tmpmasses[counter]) + " observed limit : "+str(round(tmplimits[counter]*1000,2))+" fb "+" expected limit "+str(round(tmplimitsexp[counter],5)*1000)+ " fb theory "+str(round(gtheory.Eval(tmpmasses[counter]),5)*1000)



    #if label.find("Zprime")!=-1:
    #    root = getIntersectionOfObservedLimitTheoryLine(2.6,gtheory,grobs)
    #    printTheoryUncAtPoint(root,gtheory,gtheoryUP,gtheoryDOWN)
    #if label.find("WZ")!=-1:
    #    root = getIntersectionOfObservedLimitTheoryLine(2.6,gtheory,grobs)
    #    printTheoryUncAtPoint(root,gtheory,gtheoryUP,gtheoryDOWN)
    if label.find("qZ")!=-1:
        limit = getIntersectionOfObservedLimitTheoryLine(4.8,gtheory,grobs)
        upper = getIntersectionOfObservedLimitTheoryLine(5,gtheoryUP, grobs)
        lower = getIntersectionOfObservedLimitTheoryLine(4.5, gtheoryDOWN, grobs)
        #printTheoryUncAtPoint(root,gtheory,gtheoryUP,gtheoryDOWN)
    if label.find("qW")!=-1:
        limit = getIntersectionOfObservedLimitTheoryLine(5,gtheory,grobs)
        upper = getIntersectionOfObservedLimitTheoryLine(5.2,gtheoryUP, grobs)
        lower = getIntersectionOfObservedLimitTheoryLine(4.7, gtheoryDOWN, grobs)
        #printTheoryUncAtPoint(root,gtheory,gtheoryUP,gtheoryDOWN)
    print "Limit: " + str(limit) + "; Upper: " + str(upper) + "; Lower: " + str(lower)

    mg.Add(gtheory,"L")
    mg.Add(gtheoryUP,"L")
    mg.Add(gtheoryDOWN,"L")
    #mg.Add(gtheorySHADE,"L")
    gtheory.Draw("L")
    gtheoryUP.Draw("L")
    gtheoryDOWN.Draw("L")
    #gtheorySHADE.Draw("F")


    if "qZ" in label.split("_")[0]:
        ltheory="#sigma_{TH}#timesBR(q*#rightarrowqZ)"
    if "qW" in label.split("_")[0]:
        ltheory="#sigma_{TH}#timesBR(q*#rightarrowqW)"
    if "WZ" in label.split("_")[0]:
        ltheory="#sigma_{TH}#timesBR(W'#rightarrowWZ) HVT_{B}"
    if "BulkWW" in label.split("_")[0]:
        ltheory="#sigma_{TH}#timesBR(G_{Bulk}#rightarrowWW) #tilde{k}=0.5"
    if "BulkZZ" in label.split("_")[0]:
        ltheory="#sigma_{TH}#timesBR(G_{Bulk}#rightarrowZZ) #tilde{k}=0.5"
    if "ZprimeWW" in label.split("_")[0]:
        ltheory="#sigma_{TH}#timesBR(Z'#rightarrowWW) HVT_{B}"

    # if "WW" in label.split("_")[0] or "ZZ" in label.split("_")[0]:
    #    leg = rt.TLegend(0.43,0.65,0.95,0.89)
    #    leg2 = rt.TLegend(0.43,0.65,0.95,0.89)
    # else:
    leg = rt.TLegend(0.5,0.6002591,0.9446734,0.9011917)
    leg2 = rt.TLegend(0.5,0.6002591,0.9446734,0.9011917)
    #leg.SetTextFont(42)
    #leg2.SetTextFont(42)
    leg.SetTextSize(0.038)
    leg.SetLineColor(1)
    leg.SetShadowColor(0)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(kWhite)
    # leg.SetFillStyle(0)
    leg.SetMargin(0.3)
    leg2.SetTextSize(0.038)
    leg2.SetLineColor(1)
    leg2.SetShadowColor(0)
    leg2.SetLineStyle(1)
    leg2.SetLineWidth(1)
    leg2.SetFillColor(0)
    leg2.SetFillStyle(0)
    leg2.SetMargin(0.35)
    leg.SetBorderSize(1)

    if obs: leg.AddEntry(grobs, "Observed", "Lp")
    leg.AddEntry(gryellow, "Expected #pm 1 std. deviation", "f")
    leg.AddEntry(grgreen , "Expected #pm 2 std. deviation", "f")
    leg.AddEntry(gtheory, ltheory, "L")

    if obs: leg2.AddEntry(grobs, " ", "")
    #leg2.AddEntry(grmean, " ", "L")
    #leg2.AddEntry(grmean, " ", "L")
    #leg2.AddEntry(gtheorySHADE, " ", "F")

    if label.find("BulkWW")!=-1:
        gt2 = PlotTheoryLine("ZprimeWW")
        gt2[0].SetLineColor(rt.kBlue)
        gt2[1].SetLineColor(0)
        gt2[1].SetFillColor(rt.kBlue-2)
        gt2[0].Draw("L")
        gt2[1].Draw("F")
        ltheory2 = "#sigma_{TH}#timesBR(Z'#rightarrowWW) HVT_{B}"
        leg.AddEntry(gt2[0],ltheory2,"L")
        leg2.AddEntry(gt2[1]," ","F")


    # addInfo = rt.TPaveText(0.548995,0.1830769,0.9346734,0.2897203,"NDC")
    addInfo = rt.TPaveText(0.6946309,0.5437063,0.795302,0.6363636,"NDC")
    addNarrow = rt.TPaveText(0.9,0.02,0.64,0.3,"NDC")
    if label.find("qW")!=-1 or label.find("qZ")!=-1 or label.find("Zprime")!=-1 or label.find("WZ_")!=-1:
        addNarrow = rt.TPaveText(0.15,0.02,0.64,0.3,"NDC")
    if label.find("BulkWW")!=-1:
        addNarrow = rt.TPaveText(0.4,0.02,0.64,0.3,"NDC")
    if (label.find("new")!=-1) and label.find("qW")!=-1 or label.find("qZ")!=-1:addInfo = rt.TPaveText(0.7846309,0.5437063,0.825302,0.6363636,"NDC")
    addInfo.SetFillColor(0)
    addInfo.SetLineColor(0)
    addInfo.SetFillStyle(0)
    addInfo.SetBorderSize(0)
    addInfo.SetTextFont(42)
    addInfo.SetTextSize(0.040)
    addInfo.SetTextAlign(12)

    #addNarrow.SetFillColor(0)
    #addNarrow.SetLineColor(0)
    ##addNarrow.SetTextColor(kRed)
    #addNarrow.SetFillStyle(0)
    #addNarrow.SetBorderSize(0)
    #addNarrow.SetTextFont(42)
    #addNarrow.SetTextSize(0.035)
    #addNarrow.SetTextAlign(12)
    #addNarrow.AddText("narrow width approximation")

    # addInfo.AddText("Pruned mass sideband")
    if(label.find("HP")!=-1):
        if(label.find("_ww")!=-1):addinfo.addtext("ww enriched")
        elif(label.find("_wz")!=-1):addinfo.addtext("wz enriched")
        elif(label.find("_zz")!=-1):addinfo.addtext("zz enriched")
        elif(label.find("_vv_new")!=-1):addinfo.addtext("ww+wz+zz")
        elif(label.find("_vvhp_new")!=-1):addinfo.addtext("ww+wz+zz")
        elif(label.find("_vv_old")!=-1):addinfo.addtext("vv category")
        elif(label.find("_qw")!=-1):addinfo.addtext("qw enriched")
        elif(label.find("_qz")!=-1):addinfo.addtext("qz enriched")
        elif(label.find("_qv")!=-1):addinfo.addtext("qw+qz")
        addInfo.AddText("High-purity")
    elif(label.find("LP")!=-1):
        if(label.find("_WW")!=-1):addInfo.AddText("WW enriched")
        elif(label.find("_WZ")!=-1):addInfo.AddText("WZ enriched")
        elif(label.find("_ZZ")!=-1):addInfo.AddText("ZZ enriched")
        elif(label.find("_VV_new")!=-1):addInfo.AddText("WW+WZ+ZZ")
        elif(label.find("_VVLP_new")!=-1):addInfo.AddText("WW+WZ+ZZ")
        elif(label.find("_VV_old")!=-1):addInfo.AddText("VV category")

        elif(label.find("_qW")!=-1):addInfo.AddText("qW enriched")
        elif(label.find("_qZ")!=-1):addInfo.AddText("qZ enriched")
        elif(label.find("_qV")!=-1):addInfo.AddText("qW+qZ")
        addInfo.AddText("Low-purity")
    else:
        if label.find("old")!=-1:
            addInfo.AddText("VV category")
            addInfo.AddText("HP+LP")
        elif (label.find("new")!=-1) and label.find("qW")!=-1 or label.find("qZ")!=-1:
            addInfo.AddText("qW+qZ")
            addInfo.AddText("HP+LP")

        elif label.find("new_combined")!=-1:
            addInfo.AddText("WW+WZ+ZZ")
            addInfo.AddText("HP+LP")

    #addInfo.Draw()
    #addNarrow.Draw()
    c1.Update()
    frame = c1.GetFrame()
    frame.Draw()
    CMS_lumi.CMS_lumi(c1, iPeriod, iPos)
    c1.cd()
    c1.Update()
    c1.RedrawAxis()
    c1.RedrawAxis("g")
    c1.cd()
    c1.Update()

    c1.cd()
    c1.Update()

    leg.Draw()
    leg2.Draw("same")

    #========================= print observed limits for some mass points ==========================
    if "graviton" in label.split("_")[0]:
        print "graviton"
    if "radion" in label.split("_")[0]:
        print "radion"
    if "wprime" in label.split("_")[0]:
        print "wprime"
    if "zprime" in label.split("_")[0]:
        print "zprime"
    if obs:
        print " observed limit for M=1200 GeV "+str(grobs.Eval(1.2))
        print " observed limit for M=2000 GeV "+str(grobs.Eval(2.0))
        print " observed limit for M=4000 GeV "+str(grobs.Eval(4.0))


#    print " expected limit for M=2000 GeV "+str(grmean.Eval(2.0))
#    print " expected limit for M=4000 GeV "+str(grmean.Eval(4.0))

    #text_file = open("LimitTxt/"+label+"_Limit_NewFormat.txt", "w")
    #text_file.write("mass limit +1sigma -1sigma \n")
    #for i in range(0,len(efficiencies)):
    #    print " expected limit for M="+str(radmasses[i])+" TeV "+str(grmean.Eval(radmasses[i]))
    #    text_file.write("{0} {1} {2} {3} \n".format( str(radmasses[i]),str(grmean.Eval(radmasses[i])), str(gr1up.Eval(radmasses[i])), str(gr1down.Eval(radmasses[i])) )    )

    #text_file.close()
    #===============================================================================================
    postfix = ""
    fname = postfix+"brazilianFlag_%s_13TeV.pdf" %label
    c1.SaveAs(fname)
    c1.SaveAs(fname.replace(".pdf" ,".C"  ))

    if plotExpLimitRatio != '':
        yexp1 = grmean.GetY()
        if obs == True:
            yexp2 = cgraphs[1].GetY()
        else:
            yexp2 = cgraphs[0].GetY()

        if obs:
            yexp2 = cgraphs[1].GetY()
        x = grmean.GetX()
        print x
        print yexp1
        print yexp2
        print yexp1[0]
        y = []
        n = grmean.GetN()
        gratio = TGraph()
        for i in range(0,n):
            #y.append((yexp2[i]/yexp1[i]))
            y.append( (1-yexp2[i]/yexp1[i]))
            print y[i]
            gratio.SetPoint(i,x[i],y[i])
        print y
        gratio.SetMaximum(0.1)
        gratio.SetMinimum(-0.1)
        gratio.GetXaxis().SetTitle("m_{jj} (TeV)")
        gratio.GetYaxis().SetTitle("(1- exp. limit alt. func./ exp. limit)")
        gratio.SetMarkerStyle(24)
        gratio.SetMarkerColor(kBlue)
        cratio = TCanvas("cratio","cratio",400,400)
        gratio.Draw("AP")
        addInfo2 = addText(label)
        addInfo2.Draw()
        time.sleep(5)
        cratio.SaveAs("testratio_"+label+".pdf")


    # del c1
  #   del leg
  #   del leg2
  #   del addInfo
  #   del mg
  #   del gtheory
  #   del gtheoryUP
  #   del gtheoryDOWN
    #del gtheorySHADE
    #thFile.Close()



    time.sleep(5)

if sys.argv[1][:4] == "Comb":
    CMS_lumi.lumi_13TeV = "137.19 fb^{-1}"
files = glob.glob("cl_output/" + sys.argv[1] + "/higgsCombine" + sys.argv[2] + ".AsymptoticLimits.mH*.root");
files.sort()
Plot(files, "Qto" + sys.argv[2] + "_" + sys.argv[1], True)
