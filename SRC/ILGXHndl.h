//## begin module%3902D5B8017D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5B8017D.cm

//## begin module%3902D5B8017D.cp preserve=no
//## end module%3902D5B8017D.cp

//## Module: ILGXHandler%3902D5B8017D; Package specification
//## Subsystem: Host%3902D5720367
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\ILGXHndl.h

#ifndef ILGXHndl_h
#define ILGXHndl_h 1

//## begin module%3902D5B8017D.additionalIncludes preserve=no
//## end module%3902D5B8017D.additionalIncludes

//## begin module%3902D5B8017D.includes preserve=yes
//## end module%3902D5B8017D.includes

// LGXDefs
#include "LGXDefs.h"
// LGXLNPHelper
#include "LGXLNPHl.h"
//## begin module%3902D5B8017D.declarations preserve=no
//## end module%3902D5B8017D.declarations

//## begin module%3902D5B8017D.additionalDeclarations preserve=yes
//## end module%3902D5B8017D.additionalDeclarations


//## Class: ILGXHandler%3902D01003A1; Abstract
//## Category: LGX Port%3902D1FE0103
//## Subsystem: Host%3902D5720367
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%39047816011D;CLGXLNPFrame { -> }

class ILGXHandler 
{
  //## begin ILGXHandler%3902D01003A1.initialDeclarations preserve=yes
  //## end ILGXHandler%3902D01003A1.initialDeclarations

  public:
    //## Destructor (generated)
      virtual ~ILGXHandler();


    //## Other Operations (specified)
      //## Operation: TreatData%956487425
      virtual bool TreatData (CLGXLNPFrame *pFrame) = 0;

      //## Operation: GetSessionID%958821002
      virtual TPORTID GetSessionID () = 0;

    // Additional Public Declarations
      //## begin ILGXHandler%3902D01003A1.public preserve=yes
      //## end ILGXHandler%3902D01003A1.public

  protected:
    // Additional Protected Declarations
      //## begin ILGXHandler%3902D01003A1.protected preserve=yes
      //## end ILGXHandler%3902D01003A1.protected

  private:
    // Additional Private Declarations
      //## begin ILGXHandler%3902D01003A1.private preserve=yes
      //## end ILGXHandler%3902D01003A1.private

  private:  //## implementation
    // Additional Implementation Declarations
      //## begin ILGXHandler%3902D01003A1.implementation preserve=yes
      //## end ILGXHandler%3902D01003A1.implementation

};

//## begin ILGXHandler%3902D01003A1.postscript preserve=yes
//## end ILGXHandler%3902D01003A1.postscript

// Class ILGXHandler 

//## begin module%3902D5B8017D.epilog preserve=yes
//## end module%3902D5B8017D.epilog


#endif
