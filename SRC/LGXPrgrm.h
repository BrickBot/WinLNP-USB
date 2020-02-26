//## begin module%3902D5CB00EE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5CB00EE.cm

//## begin module%3902D5CB00EE.cp preserve=no
//## end module%3902D5CB00EE.cp

//## Module: LGXProgram%3902D5CB00EE; Package specification
//## Subsystem: Host%3902D5720367
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXPrgrm.h

#ifndef LGXPrgrm_h
#define LGXPrgrm_h 1

//## begin module%3902D5CB00EE.additionalIncludes preserve=no
//## end module%3902D5CB00EE.additionalIncludes

//## begin module%3902D5CB00EE.includes preserve=yes
#include "..\..\util\dll-src\lx.h"
//## end module%3902D5CB00EE.includes

// ILGXHandler
#include "ILGXHndl.h"
// LGXDefs
#include "LGXDefs.h"

class CLGXSystem;
class CLGXHost;
class CLGXPort;

//## begin module%3902D5CB00EE.declarations preserve=no
//## end module%3902D5CB00EE.declarations

//## begin module%3902D5CB00EE.additionalDeclarations preserve=yes
//## end module%3902D5CB00EE.additionalDeclarations


//## Class: CLGXProgramMgr%3902C5A700EC
//## Category: LGX Host%3902D1AE00B8
//## Subsystem: Host%3902D5720367
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3926BC180128;CLGXPort { -> F}
//## Uses: <unnamed>%3926C46A0225;CLGXHost { -> F}

class CLGXProgramMgr : public ILGXHandler  //## Inherits: <unnamed>%3902D0390057
{
  //## begin CLGXProgramMgr%3902C5A700EC.initialDeclarations preserve=yes
  //## end CLGXProgramMgr%3902C5A700EC.initialDeclarations

  public:
    //## Constructors (generated)
      CLGXProgramMgr();

    //## Destructor (generated)
      virtual ~CLGXProgramMgr();


    //## Other Operations (specified)
      //## Operation: Init%956494572
      bool Init (CLGXSystem *pLGXSystem);

      //## Operation: Delete%956487420
      bool Delete (THOSTID nHostID, BYTE nPrgID);

      //## Operation: Run%956487421
      bool Run (THOSTID nHostID, BYTE nPrgID);

      //## Operation: Download%956487423
      bool Download (THOSTID nHostID, BYTE nPrgID, char *szFileName);

      //## Operation: TreatData%956487424
      virtual bool TreatData (CLGXLNPFrame *pFrame);

      //## Operation: GetSessionID%958835228
      virtual TPORTID GetSessionID ();

    // Additional Public Declarations
      //## begin CLGXProgramMgr%3902C5A700EC.public preserve=yes
      //## end CLGXProgramMgr%3902C5A700EC.public

  protected:

    //## Other Operations (specified)
      //## Operation: Relocate%956494575
      void Relocate (lx_t *lx, unsigned short base);

      //## Operation: ReadLXFile%956494576
      bool ReadLXFile (lx_t *lx, const CString &szFileName);

      //## Operation: DownloadText%956494577
      bool DownloadText (CLGXPort *pPort, BYTE nPrgID, lx_t *lx);

      //## Operation: WaitForAck%956572846
      bool WaitForAck ();

      //## Operation: GetSystemPort%958835229
      CLGXPort * GetSystemPort (THOSTID nHostID);

      //## Operation: DeleteImpl%958835231
      bool DeleteImpl (CLGXPort *pPort, BYTE nPrgID);

    // Additional Protected Declarations
      //## begin CLGXProgramMgr%3902C5A700EC.protected preserve=yes
      //## end CLGXProgramMgr%3902C5A700EC.protected

  private:
    // Additional Private Declarations
      //## begin CLGXProgramMgr%3902C5A700EC.private preserve=yes
      //## end CLGXProgramMgr%3902C5A700EC.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: pAckFrame%39043BE70219
      //## begin CLGXProgramMgr::pAckFrame%39043BE70219.attr preserve=no  private: CLGXLNPFrame * {U} NULL
      CLGXLNPFrame *m_pAckFrame;
      //## end CLGXProgramMgr::pAckFrame%39043BE70219.attr

      //## Attribute: hAckEvent%390440B80013
      //## begin CLGXProgramMgr::hAckEvent%390440B80013.attr preserve=no  private: HANDLE {U} NULL
      HANDLE m_hAckEvent;
      //## end CLGXProgramMgr::hAckEvent%390440B80013.attr

      //## Attribute: CS%3927E2A7008B
      //## begin CLGXProgramMgr::CS%3927E2A7008B.attr preserve=no  private: CComAutoCriticalSection {U} 
      CComAutoCriticalSection m_CS;
      //## end CLGXProgramMgr::CS%3927E2A7008B.attr

    // Data Members for Associations

      //## Association: LGX Program Mgr::<unnamed>%3926BD0B018B
      //## Role: CLGXProgramMgr::pLGXSystem%3926BD0B0330
      //## begin CLGXProgramMgr::pLGXSystem%3926BD0B0330.role preserve=no  public: CLGXSystem {0 -> 1RFHN}
      CLGXSystem *m_pLGXSystem;
      //## end CLGXProgramMgr::pLGXSystem%3926BD0B0330.role

    // Additional Implementation Declarations
      //## begin CLGXProgramMgr%3902C5A700EC.implementation preserve=yes
      //## end CLGXProgramMgr%3902C5A700EC.implementation

};

//## begin CLGXProgramMgr%3902C5A700EC.postscript preserve=yes
//## end CLGXProgramMgr%3902C5A700EC.postscript

// Class CLGXProgramMgr 

//## begin module%3902D5CB00EE.epilog preserve=yes
//## end module%3902D5CB00EE.epilog


#endif
