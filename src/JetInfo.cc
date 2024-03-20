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

  void Types::JetInfo::Minimize() {

    jetID = numeric_limits<uint32_t>::min();
    nCsts = numeric_limits<uint64_t>::min();
    ene   = -1. * numeric_limits<double>::max();
    px    = -1. * numeric_limits<double>::max();
    py    = -1. * numeric_limits<double>::max();
    pz    = -1. * numeric_limits<double>::max();
    pt    = -1. * numeric_limits<double>::max();
    eta   = -1. * numeric_limits<double>::max();
    phi   = -1. * numeric_limits<double>::max();
    area  = -1. * numeric_limits<double>::max();
    return;

  }  // end 'Minimize()'



  void Types::JetInfo::Maximize() {

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

  void Types::JetInfo::Reset() {

    Maximize();
    return;

  }  // end 'Reset()'



  void Types::JetInfo::SetInfo(fastjet::PseudoJet& pseudojet) {

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



  bool Types::JetInfo::IsInAcceptance(const JetInfo& minimum, const JetInfo& maximum) const {

    return ((*this >= minimum) && (*this <= maximum));

  }  // end 'IsInAcceptance(JetInfo&, JetInfo&)'



  bool Types::JetInfo::IsInAcceptance(const pair<JetInfo, JetInfo>& range) const {

/*
  cout << " ==> Is >=?\n"
       << "  this.nCsts = " << (*this).nCsts << ", range.min.nCsts = " << range.first.nCsts << ", passes? " << ((*this).nCsts >= range.first.nCsts) << "\n"
       << "  this.ene   = " << (*this).ene   << ", range.min.ene   = " << range.first.ene   << ", passes? " << ((*this).ene   >= range.first.ene)   << "\n"
       << "  this.px    = " << (*this).px    << ", range.min.px    = " << range.first.px    << ", passes? " << ((*this).px    >= range.first.px)    << "\n"
       << "  this.py    = " << (*this).py    << ", range.min.py    = " << range.first.py    << ", passes? " << ((*this).py    >= range.first.py)    << "\n"
       << "  this.pz    = " << (*this).pz    << ", range.min.pz    = " << range.first.pz    << ", passes? " << ((*this).pz    >= range.first.pz)    << "\n"
       << "  this.pt    = " << (*this).pt    << ", range.min.pt    = " << range.first.pt    << ", passes? " << ((*this).pt    >= range.first.pt)    << "\n"
       << "  this.eta   = " << (*this).eta   << ", range.min.eta   = " << range.first.eta   << ", passes? " << ((*this).eta   >= range.first.eta)   << "\n"
       << "  this.phi   = " << (*this).phi   << ", range.min.phi   = " << range.first.phi   << ", passes? " << ((*this).phi   >= range.first.phi)   << "\n"
       << "  this.area  = " << (*this).area  << ", range.min.area  = " << range.first.area  << ", passes? " << ((*this).area  >= range.first.area)  << "\n"
       << " ==> Is <=?\n"
       << "  this.nCsts = " << (*this).nCsts << ", range.max.nCsts = " << range.second.nCsts << ", passes? " << ((*this).nCsts <= range.second.nCsts) << "\n"
       << "  this.ene   = " << (*this).ene   << ", range.max.ene   = " << range.second.ene   << ", passes? " << ((*this).ene   <= range.second.ene)   << "\n"
       << "  this.px    = " << (*this).px    << ", range.max.px    = " << range.second.px    << ", passes? " << ((*this).px    <= range.second.px)    << "\n"
       << "  this.py    = " << (*this).py    << ", range.max.py    = " << range.second.py    << ", passes? " << ((*this).py    <= range.second.py)    << "\n"
       << "  this.pz    = " << (*this).pz    << ", range.max.pz    = " << range.second.pz    << ", passes? " << ((*this).pz    <= range.second.pz)    << "\n"
       << "  this.pt    = " << (*this).pt    << ", range.max.pt    = " << range.second.pt    << ", passes? " << ((*this).pt    <= range.second.pt)    << "\n"
       << "  this.eta   = " << (*this).eta   << ", range.max.eta   = " << range.second.eta   << ", passes? " << ((*this).eta   <= range.second.eta)   << "\n"
       << "  this.phi   = " << (*this).phi   << ", range.max.phi   = " << range.second.phi   << ", passes? " << ((*this).phi   <= range.second.phi)   << "\n"
       << "  this.area  = " << (*this).area  << ", range.max.area  = " << range.second.area  << ", passes? " << ((*this).area  <= range.second.area)  << "\n"
       << " TESTS:\n"
       << "  Lower bound pass? " << (*this >= range.first) << "\n"
       << "  Upper bound pass? " << (*this <= range.second)
       << endl;
*/

    return ((*this >= range.first) && (*this <= range.second));

  }  // end 'IsInAcceptance(pair<JetInfo, JetInfo>&)'



  // static methods -----------------------------------------------------------

  vector<string> Types::JetInfo::GetListOfMembers() {

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

  bool Types::operator <(const JetInfo& lhs, const JetInfo& rhs) {

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
  
  }  // end 'operator <(JetInfo&, JetInfo&)'



  bool Types::operator >(const JetInfo& lhs, const JetInfo& rhs) {

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
  
  }  // end 'operator >(JetInfo&, JetInfo&)'



  bool Types::operator <=(const JetInfo& lhs, const JetInfo& rhs) {

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
  
  }  // end 'operator <=(JetInfo&, JetInfo&)'



  bool Types::operator >=(const JetInfo& lhs, const JetInfo& rhs) {

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
  
  }  // end 'operator >=(JetInfo&, JetInfo&)'



  // ctor/dtor ----------------------------------------------------------------

  // default ctor/dtor
  Types::JetInfo::JetInfo() {

    /* nothing to do */

  }  // end ctor()



  Types::JetInfo::~JetInfo() {

    /* nothing to do */

  }  // end dtor()



  Types::JetInfo::JetInfo(const Const::Init init) {

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



  Types::JetInfo::JetInfo(fastjet::PseudoJet& pseudojet) {

    SetInfo(pseudojet);

  }  // ctor(PseudoJet&)'

}  // end SColdQcdCorrelatorAnalysis namespace

// end ------------------------------------------------------------------------
