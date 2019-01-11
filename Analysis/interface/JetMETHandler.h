#ifndef JETMETHANDLER_H
#define JETMETHANDLER_H

#include <vector>
#include "IvyBase.h"
#include "ElectronObject.h"
#include "MuonObject.h"
#include "AK4JetObject.h"
#include "AK8JetObject.h"
#include "TFTopObject.h"
#include "METObject.h"
#include "BtagScaleFactorHandler.h"
#include "JECScaleFactorHandler.h"
#include "JERScaleFactorHandler.h"


class JetMETHandler : public IvyBase{
protected:
  std::vector<AK4JetObject*> ak4jets;
  std::vector<AK8JetObject*> ak8jets;
  std::vector<TFTopObject*> tftops;
  METObject* metobj;

  BtagScaleFactorHandler* registeredBtagSFHandler;
  BtagScaleFactorHandler* registeredBtagSFHandler_FastSim;

  JECScaleFactorHandler* registeredJECSFHandler_ak4jets;
  JECScaleFactorHandler* registeredJECSFHandler_ak8jets;

  JERScaleFactorHandler* registeredJERSFHandler_ak4jets;
  JERScaleFactorHandler* registeredJERSFHandler_ak8jets;

  std::vector<ElectronObject*> const* registeredElectrons;
  std::vector<MuonObject*> const* registeredMuons;

  bool constructAK4Jets();
  bool constructAK8Jets();
  bool constructMET();
  bool constructTFTops();
  bool applyBtagSFs();
  bool applyJetCleaning();
  bool applyJEC();
  bool applyJER();
  bool applySelections();

  void clear();

public:
  // Constructors
  JetMETHandler();

  // Destructors
  ~JetMETHandler(){ clear(); }

  std::vector<AK4JetObject*>& getAK4Jets(){ return ak4jets; }
  std::vector<AK8JetObject*>& getAK8Jets(){ return ak8jets; }
  std::vector<TFTopObject*>& getTFTops(){ return tftops; }
  METObject*& getMET(){ return metobj; }

  std::vector<AK4JetObject*> const& getAK4Jets() const{ return ak4jets; }
  std::vector<AK8JetObject*> const& getAK8Jets() const{ return ak8jets; }
  std::vector<TFTopObject*> const& getTFTops() const{ return tftops; }
  METObject* const& getMET() const{ return metobj; }

  void registerLeptons(std::vector<ElectronObject*> const& electrons, std::vector<MuonObject*> const& muons){ registeredElectrons = &electrons; registeredMuons = &muons; }
  void registerBtagSFHandlers(BtagScaleFactorHandler* handler, BtagScaleFactorHandler* handler_fastsim){ registeredBtagSFHandler = handler; registeredBtagSFHandler_FastSim = handler_fastsim; }
  void registerJECSFHandlers(JECScaleFactorHandler* ak4jer, JECScaleFactorHandler* ak8jer){ registeredJECSFHandler_ak4jets = ak4jer; registeredJECSFHandler_ak8jets = ak8jer; }
  void registerJERSFHandlers(JERScaleFactorHandler* ak4jer, JERScaleFactorHandler* ak8jer){ registeredJERSFHandler_ak4jets = ak4jer; registeredJERSFHandler_ak8jets = ak8jer; }
  bool constructJetMET();

  static void bookBranches(BaseTree* tree);
  static TString getAK4JetDeepFlavorPrefix(std::vector<TString> const& bDiscriminatorNames);
  static float getBtagValueFromLists(std::vector<TString> const& bDiscriminatorNames, std::vector<std::vector<float>> const& btagvals, size_t ijet, TString btagname);

};


#endif
