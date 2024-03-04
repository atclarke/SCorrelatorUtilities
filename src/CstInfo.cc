// ----------------------------------------------------------------------------
// 'CstInfo.cc'
// Derek Anderson
// 03.02.2024
//
// Utility class to hold information from
// jet constituents
// ----------------------------------------------------------------------------

#define CSTINFO_CC

// c++ utilities
#include <limits>
#include <string>
#include <vector>
#include <utility>
#include <optional>
// fastjet libraries
#include <fastjet/PseudoJet.hh>
// analysis utlities
#include "CstInfo.h"
#include "Constants.h"

// make comon namespaces implicit
using namespace std;



namespace SColdQcdCorrelatorAnalysis {

  // internal methods ---------------------------------------------------------

  void CstInfo::Minimize() {

    type    = numeric_limits<int>::min();
    cstID   = numeric_limits<int>::min();
    jetID   = numeric_limits<int>::min();
    embedID = numeric_limits<int>::min();
    pid     = numeric_limits<int>::min();
    z       = numeric_limits<double>::min();
    dr      = numeric_limits<double>::min();
    ene     = numeric_limits<double>::min();
    px      = numeric_limits<double>::min();
    py      = numeric_limits<double>::min();
    pz      = numeric_limits<double>::min();
    pt      = numeric_limits<double>::min();
    eta     = numeric_limits<double>::min();
    phi     = numeric_limits<double>::min();
    return;

  }  // end 'Minimize()'



  void CstInfo::Maximize() {

    type    = numeric_limits<int>::max();
    cstID   = numeric_limits<int>::max();
    jetID   = numeric_limits<int>::max();
    embedID = numeric_limits<int>::max();
    pid     = numeric_limits<int>::max();
    z       = numeric_limits<double>::max();
    dr      = numeric_limits<double>::max();
    ene     = numeric_limits<double>::max();
    px      = numeric_limits<double>::max();
    py      = numeric_limits<double>::max();
    pz      = numeric_limits<double>::max();
    pt      = numeric_limits<double>::max();
    eta     = numeric_limits<double>::max();
    phi     = numeric_limits<double>::max();
    return;

  }  // end 'Maximize()'



  // public methods -----------------------------------------------------------

  void CstInfo::Reset() {

    Maximize();
    return;

  }  // end 'Reset()'



  void CstInfo::SetInfo(fastjet::PseudoJet& pseudojet) {

    cstID = pseudojet.user_index();
    ene   = pseudojet.E();
    px    = pseudojet.px();
    py    = pseudojet.py();
    pz    = pseudojet.pz();
    pt    = pseudojet.perp();
    eta   = pseudojet.pseudorapidity();
    phi   = pseudojet.phi_std();
    return;

  }  // end 'SetInfo(fastjet::PseudoJet)'



  bool CstInfo::IsInAcceptance(const CstInfo& minimum, const CstInfo& maximum) {

    return ((*this >= minimum) && (*this <= maximum));

  }  // end 'IsInAcceptance(CstInfo&, CstInfo&)'



  bool CstInfo::IsInAcceptance(const pair<CstInfo, CstInfo>& range) {

    return ((*this >= range.first) && (*this <= range.second));

  }  // end 'IsInAcceptance(pair<CstInfo, CstInfo>&)'



  // static methods -----------------------------------------------------------

  vector<string> CstInfo::GetListOfMembers() {

    vector<string> members = {
      "type",
      "cstID",
      "jetID",
      "embedID",
      "pid",
      "z",
      "dr",
      "ene",
      "px",
      "py",
      "pz",
      "pt",
      "eta",
      "phi"
    };
    return members;

  }  // end 'GetListOfMembers()'



  // overloaded operators -----------------------------------------------------

  bool operator<(const CstInfo& lhs, const CstInfo& rhs) {

    // note that some quantities aren't relevant for this comparison
    const bool isLessThan = (
      (lhs.z   < rhs.z)   &&
      (lhs.dr  < rhs.dr)  &&
      (lhs.ene < rhs.ene) &&
      (lhs.px  < rhs.px)  &&
      (lhs.py  < rhs.py)  &&
      (lhs.pz  < rhs.pz)  &&
      (lhs.pt  < rhs.pt)  &&
      (lhs.eta < rhs.eta) &&
      (lhs.phi < rhs.phi)
    );
    return isLessThan;
  
  }  // end 'operator<(CstInfo&, CstInfo&)'



  bool operator>(const CstInfo& lhs, const CstInfo& rhs) {

    // note that some quantities aren't relevant for this comparison
    const bool isGreaterThan = (
      (lhs.z   > rhs.z)   &&
      (lhs.dr  > rhs.dr)  &&
      (lhs.ene > rhs.ene) &&
      (lhs.px  > rhs.px)  &&
      (lhs.py  > rhs.py)  &&
      (lhs.pz  > rhs.pz)  &&
      (lhs.pt  > rhs.pt)  &&
      (lhs.eta > rhs.eta) &&
      (lhs.phi > rhs.phi)
    );
    return isGreaterThan;
  
  }  // end 'operator<(CstInfo&, CstInfo&)'



  bool operator<=(const CstInfo& lhs, const CstInfo& rhs) {

    // note that some quantities aren't relevant for this comparison
    const bool isLessThanOrEqualTo = (
      (lhs.z   <= rhs.z)   &&
      (lhs.dr  <= rhs.dr)  &&
      (lhs.ene <= rhs.ene) &&
      (lhs.px  <= rhs.px)  &&
      (lhs.py  <= rhs.py)  &&
      (lhs.pz  <= rhs.pz)  &&
      (lhs.pt  <= rhs.pt)  &&
      (lhs.eta <= rhs.eta) &&
      (lhs.phi <= rhs.phi)
    );
    return isLessThanOrEqualTo;
  
  }  // end 'operator<=(CstInfo&, CstInfo&)'



  bool operator>=(const CstInfo& lhs, const CstInfo& rhs) {

    // note that some quantities aren't relevant for this comparison
    const bool isGreaterThan = (
      (lhs.z   >= rhs.z)   &&
      (lhs.dr  >= rhs.dr)  &&
      (lhs.ene >= rhs.ene) &&
      (lhs.px  >= rhs.px)  &&
      (lhs.py  >= rhs.py)  &&
      (lhs.pz  >= rhs.pz)  &&
      (lhs.pt  >= rhs.pt)  &&
      (lhs.eta >= rhs.eta) &&
      (lhs.phi >= rhs.phi)
    );
    return isGreaterThan;
  
  }  // end 'operator<(CstInfo&, CstInfo&)'



  // ctor/dtor ----------------------------------------------------------------

  CstInfo::CstInfo(const Const::Init init) {

    switch (init) {
      case Const::Init::Minimize:
        Minimize();
        break;
      case Const::Init::Maximize:
        Maximize();
        break;
      default:
        Maximize();
        break;
    }

  }  // end ctor(Const::init)



  CstInfo::CstInfo(fastjet::PseudoJet& pseudojet) {

    SetInfo(pseudojet);

  }  // end ctor(PseudoJet&)

}  // end SColdQcdCorrelatorAnalysis namespace

// end ------------------------------------------------------------------------
