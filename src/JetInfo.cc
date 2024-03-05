// ----------------------------------------------------------------------------
// 'JetInfo.cc'
// Derek Anderson
// 03.04.2024
//
// Utility class to hold information from jets.
// ----------------------------------------------------------------------------

#define SCORRELATORUTILITIES_JETINFO_CC

// class definition
#include "JetInfo.h"

// make comon namespaces implicit
using namespace std;



namespace SColdQcdCorrelatorAnalysis {

  // internal methods ---------------------------------------------------------

  void JetInfo::Minimize() {

    jetID = numeric_limits<uint32_t>::min();
    nCsts = numeric_limits<uint64_t>::min();
    ene   = numeric_limits<double>::min();
    px    = numeric_limits<double>::min();
    py    = numeric_limits<double>::min();
    pz    = numeric_limits<double>::min();
    pt    = numeric_limits<double>::min();
    eta   = numeric_limits<double>::min();
    phi   = numeric_limits<double>::min();
    area  = numeric_limits<double>::min();
    return;

  }  // end 'Minimize()'



  void JetInfo::Maximize() {

    jetID = numeric_limits<uint32_t>::max();
    nCsts = numeric_limits<uint64_t>::max();
    ene   = numeric_limits<double>::max();
    px    = numeric_limits<double>::max();
    py    = numeric_limits<double>::max();
    pz    = numeric_limits<double>::max();
    pt    = numeric_limits<double>::max();
    eta   = numeric_limits<double>::max();
    phi   = numeric_limits<double>::max();
    area  = numeric_limits<double>::max();
    return;

  }  // end 'Maximize()'



  // public methods -----------------------------------------------------------

  void JetInfo::Reset() {

    Maximize();
    return;

  }  // end 'Reset()'



  void JetInfo::SetInfo(fastjet::PseudoJet& pseudojet) {

    nCsts = pseudojet.constituents().size();
    ene   = pseudojet.E();
    px    = pseudojet.px();
    py    = pseudojet.py();
    pz    = pseudojet.pz();
    pt    = pseudojet.perp();
    eta   = pseudojet.pseudorapidity();
    phi   = pseudojet.phi_std();
    return;

  }  // end 'SetInfo(PseudoJet&)'



  bool JetInfo::IsInAcceptance(const JetInfo& minimum, const JetInfo& maximum) {

    return ((*this >= minimum) && (*this <= maximum));

  }  // end 'IsInAcceptance(JetInfo&, JetInfo&)'



  bool JetInfo::IsInAcceptance(const pair<JetInfo, JetInfo>& range) {

    return ((*this >= range.first) && (*this <= range.second));

  }  // end 'IsInAcceptance(pair<JetInfo, JetInfo>&)'



  // static methods -----------------------------------------------------------

  vector<string> JetInfo::GetListOfMembers() {

    vector<string> members = {
      "jetID",
      "nCsts",
      "ene",
      "px",
      "py",
      "pz",
      "pt",
      "eta",
      "phi",
      "area"
    };
    return members;

  }  // end 'GetListOfMembers()'



  // overloaded operators -----------------------------------------------------

  bool operator<(const JetInfo& lhs, const JetInfo& rhs) {

    // note that some quantities aren't relevant for this comparison
    const bool isLessThan = (
      (lhs.nCsts < rhs.nCsts) &&
      (lhs.ene   < rhs.ene)   &&
      (lhs.px    < rhs.px)    &&
      (lhs.py    < rhs.py)    &&
      (lhs.pz    < rhs.pz)    &&
      (lhs.pt    < rhs.pt)    &&
      (lhs.eta   < rhs.eta)   &&
      (lhs.phi   < rhs.phi)   &&
      (lhs.area  < rhs.area)
    );
    return isLessThan;
  
  }  // end 'operator<(JetInfo&, JetInfo&)'



  bool operator>(const JetInfo& lhs, const JetInfo& rhs) {

    // note that some quantities aren't relevant for this comparison
    const bool isGreaterThan = (
      (lhs.nCsts > rhs.nCsts) &&
      (lhs.ene   > rhs.ene)   &&
      (lhs.px    > rhs.px)    &&
      (lhs.py    > rhs.py)    &&
      (lhs.pz    > rhs.pz)    &&
      (lhs.pt    > rhs.pt)    &&
      (lhs.eta   > rhs.eta)   &&
      (lhs.phi   > rhs.phi)   &&
      (lhs.area  > rhs.area)
    );
    return isGreaterThan;
  
  }  // end 'operator>(JetInfo&, JetInfo&)'



  bool operator<=(const JetInfo& lhs, const JetInfo& rhs) {

    // note that some quantities aren't relevant for this comparison
    const bool isLessThanOrEqualTo = (
      (lhs.nCsts <= rhs.nCsts) &&
      (lhs.ene   <= rhs.ene)   &&
      (lhs.px    <= rhs.px)    &&
      (lhs.py    <= rhs.py)    &&
      (lhs.pz    <= rhs.pz)    &&
      (lhs.pt    <= rhs.pt)    &&
      (lhs.eta   <= rhs.eta)   &&
      (lhs.phi   <= rhs.phi)   &&
      (lhs.area  <= rhs.area)
    );
    return isLessThanOrEqualTo;
  
  }  // end 'operator<=(JetInfo&, JetInfo&)'



  bool operator>=(const JetInfo& lhs, const JetInfo& rhs) {

    // note that some quantities aren't relevant for this comparison
    const bool isGreaterThanOrEqualTo = (
      (lhs.nCsts >= rhs.nCsts) &&
      (lhs.ene   >= rhs.ene)   &&
      (lhs.px    >= rhs.px)    &&
      (lhs.py    >= rhs.py)    &&
      (lhs.pz    >= rhs.pz)    &&
      (lhs.pt    >= rhs.pt)    &&
      (lhs.eta   >= rhs.eta)   &&
      (lhs.phi   >= rhs.phi)   &&
      (lhs.area  >= rhs.area)
    );
    return isGreaterThanOrEqualTo;
  
  }  // end 'operator>=(JetInfo&, JetInfo&)'



  // ctor/dtor ----------------------------------------------------------------

  // default ctor/dtor
  JetInfo::JetInfo() {

    /* nothing to do */

  }  // end ctor()



  JetInfo::~JetInfo() {

    /* nothing to do */

  }  // end dtor()



  JetInfo::JetInfo(const Const::Init init) {

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



  JetInfo::JetInfo(fastjet::PseudoJet& pseudojet) {

    SetInfo(pseudojet);

  }  // ctor(PseudoJet&)'

}  // end SColdQcdCorrelatorAnalysis namespace

// end ------------------------------------------------------------------------