#pragma once

#include "UHH2/core/include/fwd.h"
#include "UHH2/core/include/AnalysisModule.h"
#include "UHH2/core/include/Selection.h"
#include "UHH2/common/include/ObjectIdUtils.h"

namespace uhh2examples {

class EtaSelection: public uhh2::Selection {
public:
    EtaSelection(float deta_max = 1.3f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float deta_max;
};

class InvMassSelection: public uhh2::Selection {
public:
    InvMassSelection(float invmass_min = 1050.f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float invmass_min;
};

class MuonVeto : public uhh2::Selection {
public:
    MuonVeto(float deltaR_min = 0.8f, const boost::optional<MuonId> &muid = boost::none);
    virtual bool passes(const uhh2::Event &event) override;
private:
    float deltaR_min;
    boost::optional<MuonId> muid;
};

class ElectronVeto : public uhh2::Selection {
public:
    ElectronVeto(float deltaR_min = 0.8f, const boost::optional<ElectronId> &muid = boost::none);
    virtual bool passes(const uhh2::Event &event) override;
private:
    float deltaR_min;
    boost::optional<ElectronId> eleid;
};

class Pt1Selection : public uhh2::Selection {
public:
    Pt1Selection(float pt_min_ = 700.f) : pt_min(pt_min_) {}
    virtual bool passes(const uhh2::Event &event) override;
private:
    float pt_min;
};

class PtCleaner {
public:
    PtCleaner(uhh2::Context &ctx, float pt_min_, float pt_max_) : pt_min(pt_min_),
                pt_max(pt_max_), hndl(ctx.get_handle<std::vector<TopJet>>("topjets")) {}
    void process(uhh2::Event &event);

private:
    float pt_min, pt_max;
    uhh2::Event::Handle<std::vector<TopJet>> hndl;
};

}
