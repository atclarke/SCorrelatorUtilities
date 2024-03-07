// ----------------------------------------------------------------------------
// 'TrkInfo.h'
// Derek Anderson
// 03.05.2024
//
// Utility class to hold information from tracks.
// ----------------------------------------------------------------------------

#ifndef SCORRELATORUTILITIES_TRKINFO_H
#define SCORRELATORUTILITIES_TRKINFO_H

// c++ utilities
#include <cmath>
#include <limits>
#include <string>
#include <vector>
#include <utility>
// root libraries
#include <TF1.h>
#include <Rtypes.h>
#include <Math/Vector3D.h>
// phool libraries
#include <phool/PHCompositeNode.h>
// tracking libraries
#include <trackbase_historic/SvtxTrack.h>
// analysis utilities
#include "Tools.h"
#include "Constants.h"

// make common namespaces implicit
using namespace std;



namespace SColdQcdCorrelatorAnalysis {
  namespace Types {

    // TrkInfo definition -----------------------------------------------------

    class TrkInfo {

      private:

        // data members
        int    id         = numeric_limits<int>::max();
        int    nMvtxLayer = numeric_limits<int>::max();
        int    nInttLayer = numeric_limits<int>::max();
        int    nTpcLayer  = numeric_limits<int>::max();
        int    nMvtxClust = numeric_limits<int>::max();
        int    nInttClust = numeric_limits<int>::max();
        int    nTpcClust  = numeric_limits<int>::max();
        double eta        = numeric_limits<double>::max();
        double phi        = numeric_limits<double>::max();
        double ene        = numeric_limits<double>::max();
        double px         = numeric_limits<double>::max();
        double py         = numeric_limits<double>::max();
        double pz         = numeric_limits<double>::max();
        double pt         = numeric_limits<double>::max();
        double dcaXY      = numeric_limits<double>::max();
        double dcaZ       = numeric_limits<double>::max();
        double ptErr      = numeric_limits<double>::max();
        double quality    = numeric_limits<double>::max();
        double vx         = numeric_limits<double>::max();
        double vy         = numeric_limits<double>::max();
        double vz         = numeric_limits<double>::max();

        // internal methods
        void Minimize();
        void Maximize();

      public:

        // getters
        int    GetID()         {return id;}
        int    GetNMvtxLayer() {return nMvtxLayer;}
        int    GetNInttLayer() {return nInttLayer;}
        int    GetNTpcLayer()  {return nTpcLayer;}
        int    GetNMvtxClust() {return nMvtxClust;}
        int    GetNInttClust() {return nInttClust;}
        int    GetNTpcClust()  {return nTpcClust;}
        double GetEta()        {return eta;}
        double GetPhi()        {return phi;}
        double GetEne()        {return ene;}
        double GetPX()         {return px;}
        double GetPY()         {return py;}
        double GetPZ()         {return pz;}
        double GetPT()         {return pt;}
        double GetDcaXY()      {return dcaXY;}
        double GetDcaZ()       {return dcaZ;}
        double GetPtErr()      {return ptErr;}
        double GetQuality()    {return quality;}
        double GetVX()         {return vx;}
        double GetVY()         {return vy;}
        double GetVZ()         {return vz;}

        // setters
        void SetID(const int arg_id)                 {id         = arg_id;}
        void SetNMvtxLayer(const int arg_nMvtxLayer) {nMvtxLayer = arg_nMvtxLayer;}
        void SetNInttLayer(const int arg_nInttLayer) {nInttLayer = arg_nInttLayer;}
        void SetNTpcLayer(const int arg_nTpcLayer)   {nTpcLayer  = arg_nTpcLayer;}
        void SetNMvtxClust(const int arg_nMvtxClust) {nMvtxClust = arg_nMvtxClust;}
        void SetNInttClust(const int arg_nInttClust) {nInttClust = arg_nInttClust;}
        void SetNTpcClust(const int arg_nTpcClust)   {nTpcClust  = arg_nTpcClust;}
        void SetEta(const double arg_eta)            {eta        = arg_eta;}
        void SetPhi(const double arg_phi)            {phi        = arg_phi;}
        void SetEne(const double arg_ene)            {ene        = arg_ene;}
        void SetPX(const double arg_px)              {px         = arg_px;}
        void SetPY(const double arg_py)              {py         = arg_py;}
        void SetPZ(const double arg_pz)              {pz         = arg_pz;}
        void SetPT(const double arg_pt)              {pt         = arg_pt;}
        void SetDcaXY(const double arg_dcaXY)        {dcaXY      = arg_dcaXY;}
        void SetDcaZ(const double arg_dcaZ)          {dcaZ       = arg_dcaZ;}
        void SetPtErr(const double arg_ptErr)        {ptErr      = arg_ptErr;}
        void SetQuality(const double arg_quality)    {quality    = arg_quality;}
        void SetVX(const double arg_vx)              {vx         = arg_vx;}
        void SetVY(const double arg_vy)              {vy         = arg_vy;}
        void SetVZ(const double arg_vz)              {vz         = arg_vz;}

        // public methods
        void Reset();
        void SetInfo(SvtxTrack* track, PHCompositeNode* topNode);
        bool IsInAcceptance(const TrkInfo& minimum, const TrkInfo& maximum);
        bool IsInAcceptance(const pair<TrkInfo, TrkInfo>& range);
        bool IsInSigmaDcaCut(const pair<float, float> nSigCut, const pair<float, float> ptFitMax, const pair<TF1*, TF1*> fSigmaDca);

        // static methods
        static vector<string> GetListOfMembers();

        // overloaded operators
        friend bool operator <(const TrkInfo& lhs, const TrkInfo& rhs);
        friend bool operator >(const TrkInfo& lhs, const TrkInfo& rhs);
        friend bool operator <=(const TrkInfo& lhs, const TrkInfo& rhs);
        friend bool operator >=(const TrkInfo& lhs, const TrkInfo& rhs);

        // default ctor/dtor
        TrkInfo();
        ~TrkInfo();

        // ctors accepting arguments
        TrkInfo(const Const::Init init);
        TrkInfo(SvtxTrack* track, PHCompositeNode* topNode);

      // identify this class to ROOT
      ClassDefNV(TrkInfo, 1);

    };  // end TrkInfo def



    // overloaded operator definitions ----------------------------------------

    bool operator <(const TrkInfo& lhs, const TrkInfo& rhs);
    bool operator >(const TrkInfo& lhs, const TrkInfo& rhs);
    bool operator <=(const TrkInfo& lhs, const TrkInfo& rhs);
    bool operator >=(const TrkInfo& lhs, const TrkInfo& rhs);

  }  // end Types namespace
}  // end SColdQcdCorrelatorAnalysis namespace

#endif

// end ------------------------------------------------------------------------
