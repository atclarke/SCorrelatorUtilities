// ----------------------------------------------------------------------------
// 'GenInfo.h'
// Derek Anderson
// 03.06.2024
//
// Utility class to hold event-level generator
// information.
// ----------------------------------------------------------------------------

#ifndef SCORRELATORUTILITIES_GENINFO_H
#define SCORRELATORUTILITIES_GENINFO_H

// c++ utilities
#include <limits>
#include <string>
#include <vector>
#include <utility>
#include <optional>
// root libraries
#include <Rtypes.h>
#include <Math/Vector3D.h>
// analysis utilities
#include "Tools.h"
#include "ParInfo.h"
#include "Constants.h"
#include "Interfaces.h"

// make common namespaces implicit
using namespace std;



namespace SColdQcdCorrelatorAnalysis {

  // GenInfo definition ------------------------------------------------------

  class GenInfo {

    private:

      // atomic data members
      int    nChrgPar = numeric_limits<int>::max();
      int    nNeuPar  = numeric_limits<int>::max();
      bool   isEmbed  = false;
      double eSumChrg = numeric_limits<double>::max();
      double eSumNeu  = numeric_limits<double>::max();

      // hard scatter products
      pair<ParInfo, ParInfo> partons;

      // internal methods
      void Minimize();
      void Maximize();

    public:

      // getters
      int                    GetNChrgPar() {return nChrgPar;}
      int                    GetNNeuPar()  {return nNeuPar;}
      bool                   GetIsEmbed()  {return isEmbed;}
      double                 GetESumChrg() {return eSumChrg;}
      double                 GetESumNeu()  {return eSumNeu;}
      ParInfo                GetPartonA()  {return partons.first;}
      ParInfo                GetPartonB()  {return partons.second;}
      pair<ParInfo, ParInfo> GetPartons()  {return partons;} 

      // setters
      void SetNChrgPar(int arg_nChrgPar)                  {nChrgPar = arg_nChrgPar;}
      void SetNNeuPar(int arg_nNeuPar)                    {nNeuPar  = arg_nNeuPar;}
      void SetIsEmbed(bool arg_isEmbed)                   {isEmbed  = arg_isEmbed;}
      void SetESumChrg(double arg_eSumChrg)               {eSumChrg = arg_eSumChrg;}
      void SetESumNeu(double arg_eSumNeu)                 {eSumNeu  = arg_eSumNeu;}
      void SetPartons(pair<ParInfo, ParInfo> arg_partons) {partons  = arg_partons;} 

      // public methods
      void Reset();
      void SetInfo(PHCompositeNode* topNode, const bool embed, const vector<int> evtsToGrab);

      // static methods
      static vector<string> GetListOfMembers();

      // default ctor/dtor
      GenInfo();
      ~GenInfo();

      // ctor accepting PHCompositeNode* and list of subevents
      GenInfo(const Const::Init init);
      GenInfo(PHCompositeNode* topNode, const bool embed, vector<int> evtsToGrab);

    // identify this class to ROOT
    ClassDefNV(GenInfo, 1);

  };  // end GenInfo definition

}  // end SColdQcdCorrelatorAnalysis namespace

#endif

// end ------------------------------------------------------------------------