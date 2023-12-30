// ----------------------------------------------------------------------------
// 'Constants.h'
// Derek Anderson
// 11.16.2023
//
// Various constants used throughout the SColdQcdCorrelatorAnalysis
// namespace are collected here.
// ----------------------------------------------------------------------------

#pragma once



namespace SColdQcdCorrelatorAnalysis {

  // constants, enums, etc. ---------------------------------------------------

  namespace {

    // subsystem indices
    enum Subsys {Mvtx, Intt, Tpc, EMCal, IHCal, OHCal};

    // tracking-related constants
    const uint16_t NMvtxLayer = 3;
    const uint16_t NInttLayer = 8;
    const uint16_t NTpcLayer  = 48;
    const uint16_t NTpcSector = 12;

    // pion mass in GeV/c^2
    const double MassPion = 0.140;

  }  // end constants

}  // end SColdQcdCorrealtorAnalysis namespace

// end ------------------------------------------------------------------------
