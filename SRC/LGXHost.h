//## begin module%3902D5B601DE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5B601DE.cm

//## begin module%3902D5B601DE.cp preserve=no
//## end module%3902D5B601DE.cp

//## Module: LGXHost%3902D5B601DE; Package specification
//## Subsystem: Host%3902D5720367
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXHost.h

#ifndef LGXHost_h
#define LGXHost_h 1

//## begin module%3902D5B601DE.additionalIncludes preserve=no
//## end module%3902D5B601DE.additionalIncludes

//## begin module%3902D5B601DE.includes preserve=yes
//## end module%3902D5B601DE.includes

// LGXLNPHelper
#include "LGXLNPHl.h"
// LGXTower
#include "LGXTower.h"
// LGXDefs
#include "LGXDefs.h"

class CLGXPort;

//## begin module%3902D5B601DE.declarations preserve=no
//## end module%3902D5B601DE.declarations

//## begin module%3902D5B601DE.additionalDeclarations preserve=yes
//## end module%3902D5B601DE.additionalDeclarations


//## Class: CLGXHost%3902C57E00D9
//## Category: LGX Host%3902D1AE00B8
//## Subsystem: Host%3902D5720367
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3926798901D1;CLGXPort { -> F}
//## Uses: <unnamed>%3926AF4500EB;CLGXLNPAddressedFrame { -> }

class CLGXHost 
{
  //## begin CLGXHost%3902C57E00D9.initialDeclarations preserve=yes
  //## end CLGXHost%3902C57E00D9.initialDeclarations

  public:
    //## Class: TPortsMap%392677D90324
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef map<TPORTID, CLGXPort *> TPortsMap;

    //## begin CLGXHost::TPortsMap%392677D90324.postscript preserve=yes
    //## end CLGXHost::TPortsMap%392677D90324.postscript

  public:
    //## Constructors (generated)
      CLGXHost();

    //## Destructor (generated)
      virtual ~CLGXHost();


    //## Other Operations (specified)
      //## Operation: Init%956487414
      bool Init (THOSTID nPCHostID, THOSTID nHostID, CLGXTowerMgr *pTowerMgr);

      //## Operation: GetPort%956487415
      CLGXPort * GetPort (TPORTID nPortID);

      //## Operation: Dispatch%956487418
      bool Dispatch (CLGXLNPAddressedFrame *pFrame);

      //## Operation: GetHostID%956487419
      THOSTID GetHostID ();

    // Additional Public Declarations
      //## begin CLGXHost%3902C57E00D9.public preserve=yes
      //## end CLGXHost%3902C57E00D9.public

  protected:
    // Additional Protected Declarations
      //## begin CLGXHost%3902C57E00D9.protected preserve=yes
      //## end CLGXHost%3902C57E00D9.protected

  private:
    // Additional Private Declarations
      //## begin CLGXHost%3902C57E00D9.private preserve=yes
      //## end CLGXHost%3902C57E00D9.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: nPCHostID%392680170328
      //## begin CLGXHost::nPCHostID%392680170328.attr preserve=no  private: THOSTID {U} -1
      THOSTID m_nPCHostID;
      //## end CLGXHost::nPCHostID%392680170328.attr

      //## Attribute: nHostID%3902DDB5035E
      //## begin CLGXHost::nHostID%3902DDB5035E.attr preserve=no  private: THOSTID {U} -1
      THOSTID m_nHostID;
      //## end CLGXHost::nHostID%3902DDB5035E.attr

      //## Attribute: PortsMap%3926797403C6
      //## begin CLGXHost::PortsMap%3926797403C6.attr preserve=no  private: TPortsMap {U} 
      TPortsMap m_PortsMap;
      //## end CLGXHost::PortsMap%3926797403C6.attr

    // Data Members for Associations

      //## Association: LGX Host::<unnamed>%3902F8310118
      //## Role: CLGXHost::pTowerMgr%3902F83102F9
      //## begin CLGXHost::pTowerMgr%3902F83102F9.role preserve=no  public: CLGXTowerMgr {0 -> 1RHN}
      CLGXTowerMgr *m_pTowerMgr;
      //## end CLGXHost::pTowerMgr%3902F83102F9.role

    // Additional Implementation Declarations
      //## begin CLGXHost%3902C57E00D9.implementation preserve=yes
      //## end CLGXHost%3902C57E00D9.implementation

};

//## begin CLGXHost%3902C57E00D9.postscript preserve=yes
//## end CLGXHost%3902C57E00D9.postscript

// Class CLGXHost 

//## begin module%3902D5B601DE.epilog preserve=yes
//## end module%3902D5B601DE.epilog


#endif
