//## begin module%3921965500DC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3921965500DC.cm

//## begin module%3921965500DC.cp preserve=no
//## end module%3921965500DC.cp

//## Module: LGXSystem%3921965500DC; Package specification
//## Subsystem: System%3902D56B01EA
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXSystm.h

#ifndef LGXSystm_h
#define LGXSystm_h 1

//## begin module%3921965500DC.additionalIncludes preserve=no
//## end module%3921965500DC.additionalIncludes

//## begin module%3921965500DC.includes preserve=yes
//## end module%3921965500DC.includes

// LGXDefs
#include "LGXDefs.h"
// LGXLNPHelper
#include "LGXLNPHl.h"
// LGXTower
#include "LGXTower.h"
// LGXProgram
#include "LGXPrgrm.h"

class CLGXHost;

//## begin module%3921965500DC.declarations preserve=no
//## end module%3921965500DC.declarations

//## begin module%3921965500DC.additionalDeclarations preserve=yes
//## end module%3921965500DC.additionalDeclarations


//## Class: CLGXSystem%3902C6A00271
//## Category: LGX System%3902D13F0343
//## Subsystem: System%3902D56B01EA
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%392679320168;CLGXHost { -> F}

class CLGXSystem 
{
  //## begin CLGXSystem%3902C6A00271.initialDeclarations preserve=yes
  //## end CLGXSystem%3902C6A00271.initialDeclarations

  public:
    //## Class: THostsMap%392674910150
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef map<THOSTID, CLGXHost*> THostsMap;

    //## begin CLGXSystem::THostsMap%392674910150.postscript preserve=yes
    //## end CLGXSystem::THostsMap%392674910150.postscript

  public:
    //## Constructors (generated)
      CLGXSystem();

    //## Destructor (generated)
      virtual ~CLGXSystem();


    //## Other Operations (specified)
      //## Operation: Init%956487400
      bool Init (BYTE nComPort, BYTE nMaxSession, THOSTID nPCHostID);

      //## Operation: InstallLegOS%956487401
      bool InstallLegOS (const CString &szFileName);

      //## Operation: GetHost%956487402
      CLGXHost * GetHost (THOSTID nHostID);

      //## Operation: HandleByte%956487404
      void HandleByte (unsigned char  b);

      //## Operation: GetProgramMgr%958835230
      CLGXProgramMgr & GetProgramMgr ();

      //## Operation: GetTowerMgr%958908576
      CLGXTowerMgr & GetTowerMgr ();

    // Additional Public Declarations
      //## begin CLGXSystem%3902C6A00271.public preserve=yes
      //## end CLGXSystem%3902C6A00271.public

  protected:
    // Additional Protected Declarations
      //## begin CLGXSystem%3902C6A00271.protected preserve=yes
      //## end CLGXSystem%3902C6A00271.protected

  private:
    // Additional Private Declarations
      //## begin CLGXSystem%3902C6A00271.private preserve=yes
      //## end CLGXSystem%3902C6A00271.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: nComPort%39031F930039
      //## begin CLGXSystem::nComPort%39031F930039.attr preserve=no  private: unsigned char {U} 0
      unsigned char m_nComPort;
      //## end CLGXSystem::nComPort%39031F930039.attr

      //## Attribute: pFile%3903230E0149
      //## begin CLGXSystem::pFile%3903230E0149.attr preserve=no  private: FILE * {U} NULL
      FILE *m_pFile;
      //## end CLGXSystem::pFile%3903230E0149.attr

      //## Attribute: nPCHostID%392671D5006D
      //## begin CLGXSystem::nPCHostID%392671D5006D.attr preserve=no  private: THOSTID {U} 0
      THOSTID m_nPCHostID;
      //## end CLGXSystem::nPCHostID%392671D5006D.attr

      //## Attribute: nMaxSession%392194D20158
      //## begin CLGXSystem::nMaxSession%392194D20158.attr preserve=no  private: BYTE {U} 0
      BYTE m_nMaxSession;
      //## end CLGXSystem::nMaxSession%392194D20158.attr

      //## Attribute: HostsMap%3926790B03CF
      //## begin CLGXSystem::HostsMap%3926790B03CF.attr preserve=no  private: THostsMap {U} 
      THostsMap m_HostsMap;
      //## end CLGXSystem::HostsMap%3926790B03CF.attr

    // Data Members for Associations

      //## Association: <unnamed>%3902CF0002C4
      //## Role: CLGXSystem::LGXTowerMgr%3902CF0100C7
      //## begin CLGXSystem::LGXTowerMgr%3902CF0100C7.role preserve=no  public: CLGXTowerMgr {1 -> 1VHN}
      CLGXTowerMgr m_LGXTowerMgr;
      //## end CLGXSystem::LGXTowerMgr%3902CF0100C7.role

      //## Association: LGX System::<unnamed>%390429DA0214
      //## Role: CLGXSystem::LNPStateMachine%390429DB00E9
      //## begin CLGXSystem::LNPStateMachine%390429DB00E9.role preserve=no  public: CLGXLNPStateMachine {0 -> 1VHN}
      CLGXLNPStateMachine m_LNPStateMachine;
      //## end CLGXSystem::LNPStateMachine%390429DB00E9.role

      //## Association: LGX System::<unnamed>%3926BDB10176
      //## Role: CLGXSystem::LGXProgramMgr%3926BDB1039D
      //## begin CLGXSystem::LGXProgramMgr%3926BDB1039D.role preserve=no  public: CLGXProgramMgr {0 -> 1VHN}
      CLGXProgramMgr m_LGXProgramMgr;
      //## end CLGXSystem::LGXProgramMgr%3926BDB1039D.role

    // Additional Implementation Declarations
      //## begin CLGXSystem%3902C6A00271.implementation preserve=yes
      //## end CLGXSystem%3902C6A00271.implementation

};

//## begin CLGXSystem%3902C6A00271.postscript preserve=yes
//## end CLGXSystem%3902C6A00271.postscript

// Class CLGXSystem 

//## begin module%3921965500DC.epilog preserve=yes
//## end module%3921965500DC.epilog


#endif
