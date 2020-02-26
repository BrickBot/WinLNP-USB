//## begin module%3902D62C0274.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D62C0274.cm

//## begin module%3902D62C0274.cp preserve=no
//## end module%3902D62C0274.cp

//## Module: LGXTower%3902D62C0274; Package specification
//## Subsystem: Tower%3902D5790122
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXTower.h

#ifndef LGXTower_h
#define LGXTower_h 1

//## begin module%3902D62C0274.additionalIncludes preserve=no
//## end module%3902D62C0274.additionalIncludes

//## begin module%3902D62C0274.includes preserve=yes
//## end module%3902D62C0274.includes

// LGXDefs
#include "LGXDefs.h"

class CLGXSystem;

//## begin module%3902D62C0274.declarations preserve=no
//## end module%3902D62C0274.declarations

//## begin module%3902D62C0274.additionalDeclarations preserve=yes
//## end module%3902D62C0274.additionalDeclarations


//## Class: CLGXTowerMgr%3902C571022F
//## Category: LGX Tower%3902D1650077
//## Subsystem: Tower%3902D5790122
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLGXTowerMgr 
{
  //## begin CLGXTowerMgr%3902C571022F.initialDeclarations preserve=yes
  //## end CLGXTowerMgr%3902C571022F.initialDeclarations

  public:
    //## Constructors (generated)
      CLGXTowerMgr();

    //## Destructor (generated)
      virtual ~CLGXTowerMgr();


    //## Other Operations (specified)
      //## Operation: Init%956487426
      bool Init (unsigned char nComPort, unsigned long nParity, CLGXSystem *pSystem);

      //## Operation: Close%956487448
      void Close ();

      //## Operation: Sleep%956487427
      void Sleep ();

      //## Operation: WakeUp%956487428
      void WakeUp ();

      //## Operation: IsRunning%958908577
      bool IsRunning ();

      //## Operation: Send%956487429
      bool Send (unsigned short nLength, unsigned char *pData);

      //## Operation: RCXSend%956494586
      //	Special function used only when downloading LegOS over
      //	the mindstorm original firmware.
      unsigned long RCXSend (unsigned char *pOutData, unsigned short nOutLength, unsigned char *pInData, unsigned short &nInLength);

    // Additional Public Declarations
      //## begin CLGXTowerMgr%3902C571022F.public preserve=yes
      //## end CLGXTowerMgr%3902C571022F.public

  protected:

    //## Other Operations (specified)
      //## Operation: InitComm%956494578
      bool InitComm (unsigned char nComPort, unsigned long nParity);

      //## Operation: InitThreads%956494579
      bool InitThreads ();

      //## Operation: LineWatcher%956487430
      void LineWatcher ();

      //## Operation: KeepAliveRoutine%956487431
      void KeepAliveRoutine ();

      //## Operation: StartWatcher%956494580
      static DWORD WINAPI StartWatcher (LPVOID pData);

      //## Operation: StartKeepAlive%956494581
      static DWORD WINAPI StartKeepAlive (LPVOID pData);

    // Additional Protected Declarations
      //## begin CLGXTowerMgr%3902C571022F.protected preserve=yes
      //## end CLGXTowerMgr%3902C571022F.protected

  private:
    // Additional Private Declarations
      //## begin CLGXTowerMgr%3902C571022F.private preserve=yes
      //## end CLGXTowerMgr%3902C571022F.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: hComm%3902ED930232
      //## begin CLGXTowerMgr::hComm%3902ED930232.attr preserve=no  private: HANDLE {U} INVALID_HANDLE_VALUE
      HANDLE m_hComm;
      //## end CLGXTowerMgr::hComm%3902ED930232.attr

	  BYTE   m_bUseUSB; // added by Alexander Cech

      //## Attribute: hKeepAliveThread%3927C8800279
      //## begin CLGXTowerMgr::hKeepAliveThread%3927C8800279.attr preserve=no  private: HANDLE {U} NULL
      HANDLE m_hKeepAliveThread;
      //## end CLGXTowerMgr::hKeepAliveThread%3927C8800279.attr

      //## Attribute: bIsKeepAliveRunning%3927C920021F
      //## begin CLGXTowerMgr::bIsKeepAliveRunning%3927C920021F.attr preserve=no  private: bool {U} false
      bool m_bIsKeepAliveRunning;
      //## end CLGXTowerMgr::bIsKeepAliveRunning%3927C920021F.attr

      //## Attribute: CS%3927E27F00DE
      //## begin CLGXTowerMgr::CS%3927E27F00DE.attr preserve=no  private: CComAutoCriticalSection {U} 
      CComAutoCriticalSection m_CS;
      //## end CLGXTowerMgr::CS%3927E27F00DE.attr

    // Data Members for Associations

      //## Association: <unnamed>%3902CF0002C4
      //## Role: CLGXTowerMgr::pSystem%3902CF0100BD
      //## begin CLGXTowerMgr::pSystem%3902CF0100BD.role preserve=no  public: CLGXSystem {1 -> 1RFHGN}
      CLGXSystem *m_pSystem;
      //## end CLGXTowerMgr::pSystem%3902CF0100BD.role

    // Additional Implementation Declarations
      //## begin CLGXTowerMgr%3902C571022F.implementation preserve=yes
      //## end CLGXTowerMgr%3902C571022F.implementation

};

//## begin CLGXTowerMgr%3902C571022F.postscript preserve=yes
//## end CLGXTowerMgr%3902C571022F.postscript

// Class CLGXTowerMgr 

//## begin module%3902D62C0274.epilog preserve=yes
//## end module%3902D62C0274.epilog


#endif
