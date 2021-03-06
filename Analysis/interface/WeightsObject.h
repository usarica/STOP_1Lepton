#ifndef WEIGHTSOBJECT_H
#define WEIGHTSOBJECT_H

#include "TString.h"


class WeightVariables{
public:
  enum WeightType{
    wCentral=0,
    wFacScaleUp, wFacScaleDn,
    wRenScaleUp, wRenScaleDn,
    wPDFUp, wPDFDn,
    wAsMZUp, wAsMZDn,
    wPSUp, wPSDn, // ISR*FSR
    // This is the set of default weights
    wCentral_Default,
    wPDFUp_Default, wPDFDn_Default,
    wISRUp, wISRDn,
    wFSRUp, wFSRDn,
    nWeightTypes
  };

  float wgt_central;
  float wgt_muF2;
  float wgt_muF0p5;
  float wgt_muR2;
  float wgt_muR0p5;
  float wgt_PDFVariationUp;
  float wgt_PDFVariationDn;
  float wgt_AsMZUp;
  float wgt_AsMZDn;
  float wgt_PSUp;
  float wgt_PSDn;

  float wgt_central_default;
  float wgt_PDFVariationUp_default;
  float wgt_PDFVariationDn_default;
  float wgt_ISRUp;
  float wgt_ISRDn;
  float wgt_FSRUp;
  float wgt_FSRDn;

  WeightVariables();
  WeightVariables(WeightVariables const& other);
  WeightVariables& operator=(const WeightVariables& other);

  void swap(WeightVariables& other);

  static TString getWeightName(WeightVariables::WeightType type);
  static TString getWeightLabel(WeightVariables::WeightType type, bool use2016);
  float getWeight(WeightVariables::WeightType type) const;

};

class WeightsObject{
public:
  WeightVariables extras;

  WeightsObject();
  WeightsObject(const WeightsObject& other);
  WeightsObject& operator=(const WeightsObject& other);
  ~WeightsObject();

  void swap(WeightsObject& other);

};

#endif
