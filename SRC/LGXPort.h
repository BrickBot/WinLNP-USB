//## begin module%3902D5DC0355.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5DC0355.cm

//## begin module%3902D5DC0355.cp preserve=no
//## end module%3902D5DC0355.cp

//## Module: LGXPort%3902D5DC0355; Package specification
//## Subsystem: Port%3902D580003C
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXPort.h

#ifndef LGXPort_h
#define LGXPort_h 1

//## begin module%3902D5DC0355.additionalIncludes preserve=no
//## end module%3902D5DC0355.additionalIncludes

//## begin module%3902D5DC0355.includes preserve=yes
//## end module%3902D5DC0355.includes

// LGXDefs
#include "LGXDefs.h"
// LGXLNPHelper
#include "LGXLNPHl.h"
// LGXTower
#include "LGXTower.h"

class ILGXHandler;

//## begin module%3902D5DC0355.declarations preserve=no
//## end module%3902D5DC0355.declarations

//## begin module%3902D5DC0355.additionalDeclarations preserve=yes
//## end module%3902D5DC0355.additionalDeclarations


//## Class: CLGXPort%3902C589019D
//## Category: LGX Port%3902D1FE0103
//## Subsystem: Port%3902D580003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%390477EE03E6;CLGXLNPBroadcastFrame { -> }
//## Uses: <unnamed>%390477F10015;CLGXLNPAddressedFrame { -> }
//## Uses: <unnamed>%39267E7D024D;ILGXHandler { -> F}

class CLGXPort 
{
  //## begin CLGXPort%3902C589019D.initialDeclarations preserve=yes
  //## end CLGXPort%3902C589019D.initialDeclarations

  public:
    //## Class: THandlersMap%39267E2A0261
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef map<TPORTID, ILGXHandler *> THandlersMap;

    //## begin CLGXPort::THandlersMap%39267E2A0261.postscript preserve=yes
    //## end CLGXPort::THandlersMap%39267E2A0261.postscript

  public:
    //## Constructors (generated)
      CLGXPort();

    //## Destructor (generated)
      virtual ~CLGXPort();


    //## Other Operations (specified)
      //## Operation: Init%956487432
      bool Init (THOSTID nPCHostID, THOSTID nHostID, TPORTID nPortID, CLGXTowerMgr *pTowerMgr);

      //## Operation: Send%956487433
      bool Send (TPORTID nSrcPortID, unsigned char nLength, unsigned char *pData);

      //## Operation: Dispatch%956487434
      bool Dispatch (CLGXLNPAddressedFrame *pFrame);

      //## Operation: GetPortID%956487435
      TPORTID GetPortID ();

      //## Operation: GetHostID%956487436
      THOSTID GetHostID ();

      //## Operation: RegisterHandler%956487437
      void RegisterHandler (TPORTID nSessionID, ILGXHandler *pHandler);

      //## Operation: UnregisterHandler%956487438
      void UnregisterHandler (ILGXHandler *pHandler);

    // Additional Public Declarations
      //## begin CLGXPort%3902C589019D.public preserve=yes
      //## end CLGXPort%3902C589019D.public

  protected:
    // Additional Protected Declarations
      //## begin CLGXPort%3902C589019D.protected preserve=yes
      //## end CLGXPort%3902C589019D.protected

  private:
    // Additional Private Declarations
      //## begin CLGXPort%3902C589019D.private preserve=yes
      //## end CLGXPort%3902C589019D.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: nPCHostID%39267FAA0354
      //## begin CLGXPort::nPCHostID%39267FAA0354.attr preserve=no  private: THOSTID {U} -1
      THOSTID m_nPCHostID;
      //## end CLGXPort::nPCHostID%39267FAA0354.attr

      //## Attribute: nHostID%3902E6AE03C5
      //## begin CLGXPort::nHostID%3902E6AE03C5.attr preserve=no  private: THOSTID {U} -1
      THOSTID m_nHostID;
      //## end CLGXPort::nHostID%3902E6AE03C5.attr

      //## Attribute: nPortID%3902E6C900CB
      //## begin CLGXPort::nPortID%3902E6C900CB.attr preserve=no  private: TPORTID {U} -1
      TPORTID m_nPortID;
      //## end CLGXPort::nPortID%3902E6C900CB.attr

      //## Attribute: HandlersMap%39267DCA0000
      //## begin CLGXPort::HandlersMap%39267DCA0000.attr preserve=no  private: THandlersMap {U} 
      THandlersMap m_HandlersMap;
      //## end CLGXPort::HandlersMap%39267DCA0000.attr

      //## Attribute: CS%3927E134010A
      //## begin CLGXPort::CS%3927E134010A.attr preserve=no  private: CComAutoCriticalSection {U} 
      CComAutoCriticalSection m_CS;
      //## end CLGXPort::CS%3927E134010A.attr

    // Data Members for Associations

      //## Association: <unnamed>%3902CF31024C
      //## Role: CLGXPort::pTowerMgr%3902CF3200B3
      //## begin CLGXPort::pTowerMgr%3902CF3200B3.role preserve=no  public: CLGXTowerMgr {0 -> 1RHN}
      CLGXTowerMgr *m_pTowerMgr;
      //## end CLGXPort::pTowerMgr%3902CF3200B3.role

    // Additional Implementation Declarations
      //## begin CLGXPort%3902C589019D.implementation preserve=yes
      //## end CLGXPort%3902C589019D.implementation

};

//## begin CLGXPort%3902C589019D.postscript preserve=yes
//## end CLGXPort%3902C589019D.postscript

// Class CLGXPort 

//## begin module%3902D5DC0355.epilog preserve=yes
//## end module%3902D5DC0355.epilog


#endif
