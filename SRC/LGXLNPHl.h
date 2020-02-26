//## begin module%3902D5EF0168.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5EF0168.cm

//## begin module%3902D5EF0168.cp preserve=no
//## end module%3902D5EF0168.cp

//## Module: LGXLNPHelper%3902D5EF0168; Package specification
//## Subsystem: Channel%3902D580003C
//## Source file: c:\projects\legos\legos-0.2.3\legox\src\LGXLNPHl.h

#ifndef LGXLNPHl_h
#define LGXLNPHl_h 1

//## begin module%3902D5EF0168.additionalIncludes preserve=no
//## end module%3902D5EF0168.additionalIncludes

//## begin module%3902D5EF0168.includes preserve=yes
//## end module%3902D5EF0168.includes

// LGXDefs
#include "LGXDefs.h"
//## begin module%3902D5EF0168.declarations preserve=no
//## end module%3902D5EF0168.declarations

//## begin module%3902D5EF0168.additionalDeclarations preserve=yes
#define LNP_MAX_BUFFER_SIZE		256+3
//## end module%3902D5EF0168.additionalDeclarations


//## Class: CLGXLNPFrame%3902E00900BC
//## Category: LGX LNP Helper%3902D7BA0353
//## Subsystem: Channel%3902D580003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLGXLNPFrame 
{
  //## begin CLGXLNPFrame%3902E00900BC.initialDeclarations preserve=yes
  //## end CLGXLNPFrame%3902E00900BC.initialDeclarations

  public:
    //## Class: ELNP_FRAME_TYPE%390460780015
    //## Category: <Top Level>
    //## Subsystem: <Top Level>
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef enum 
    {
        ELNP_UNKNOWN_TYPE = 0,
        ELNP_BROADCAST_FRAME = 0xF0,
        ELNP_ADDRESSED_FRAME = 0xF1,
    } ELNP_FRAME_TYPE;

    //## begin CLGXLNPFrame::ELNP_FRAME_TYPE%390460780015.postscript preserve=yes
    //## end CLGXLNPFrame::ELNP_FRAME_TYPE%390460780015.postscript

  public:
    //## Constructors (generated)
      CLGXLNPFrame();

    //## Constructors (specified)
      //## Operation: CLGXLNPFrame%956588848
      CLGXLNPFrame (unsigned char* pFrame, unsigned char nLength);

    //## Destructor (generated)
      virtual ~CLGXLNPFrame();


    //## Other Operations (specified)
      //## Operation: CheckFrame%956487408
      bool CheckFrame ();

      //## Operation: GetData%956487441
      virtual unsigned char * GetData ();

      //## Operation: GetDataLength%956494573
      virtual unsigned char GetDataLength ();

      //## Operation: GetCRC%956487439
      unsigned char GetCRC ();

      //## Operation: GetFrame%956588841
      unsigned char * GetFrame ();

      //## Operation: GetFrameLength%956588842
      unsigned short GetFrameLength ();

      //## Operation: GetFrameType%956588843
      CLGXLNPFrame::ELNP_FRAME_TYPE GetFrameType ();

    // Additional Public Declarations
      //## begin CLGXLNPFrame%3902E00900BC.public preserve=yes
      //## end CLGXLNPFrame%3902E00900BC.public

  protected:

    //## Other Operations (specified)
      //## Operation: ComputeChecksum%956588844
      unsigned char ComputeChecksum ();

      //## Operation: Free%956588852
      void Free ();

    // Data Members for Class Attributes

      //## Attribute: pBuffer%3902E0230362
      //## begin CLGXLNPFrame::pBuffer%3902E0230362.attr preserve=no  protected: unsigned char * {UA} NULL
      unsigned char *m_pBuffer;
      //## end CLGXLNPFrame::pBuffer%3902E0230362.attr

    // Additional Protected Declarations
      //## begin CLGXLNPFrame%3902E00900BC.protected preserve=yes
      //## end CLGXLNPFrame%3902E00900BC.protected

  private:
    // Additional Private Declarations
      //## begin CLGXLNPFrame%3902E00900BC.private preserve=yes
      //## end CLGXLNPFrame%3902E00900BC.private

  private:  //## implementation
    // Additional Implementation Declarations
      //## begin CLGXLNPFrame%3902E00900BC.implementation preserve=yes
      //## end CLGXLNPFrame%3902E00900BC.implementation

};

//## begin CLGXLNPFrame%3902E00900BC.postscript preserve=yes
//## end CLGXLNPFrame%3902E00900BC.postscript

//## Class: CLGXLNPStateMachine%390423830080
//## Category: LGX LNP Helper%3902D7BA0353
//## Subsystem: Channel%3902D580003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%39046E2E0076;CLGXLNPFrame { -> }

class CLGXLNPStateMachine 
{
  //## begin CLGXLNPStateMachine%390423830080.initialDeclarations preserve=yes
  //## end CLGXLNPStateMachine%390423830080.initialDeclarations

  public:
    //## Constructors (generated)
      CLGXLNPStateMachine();

    //## Destructor (generated)
      virtual ~CLGXLNPStateMachine();


    //## Other Operations (specified)
      //## Operation: HandleByte%956572842
      bool HandleByte (unsigned char b);

      //## Operation: GetFrame%956572843
      CLGXLNPFrame * GetFrame ();

    // Additional Public Declarations
      //## begin CLGXLNPStateMachine%390423830080.public preserve=yes
      //## end CLGXLNPStateMachine%390423830080.public

  protected:

    //## Other Operations (specified)
      //## Operation: Reset%956572845
      void Reset ();

    // Additional Protected Declarations
      //## begin CLGXLNPStateMachine%390423830080.protected preserve=yes
      //## end CLGXLNPStateMachine%390423830080.protected

  private:
    // Additional Private Declarations
      //## begin CLGXLNPStateMachine%390423830080.private preserve=yes
      //## end CLGXLNPStateMachine%390423830080.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: nState%390423C60285
      //## begin CLGXLNPStateMachine::nState%390423C60285.attr preserve=no  private: unsigned char {U} 
      unsigned char m_nState;
      //## end CLGXLNPStateMachine::nState%390423C60285.attr

      //## Attribute: nBytesRead%3904239501F9
      //## begin CLGXLNPStateMachine::nBytesRead%3904239501F9.attr preserve=no  private: unsigned char {U} 
      unsigned char m_nBytesRead;
      //## end CLGXLNPStateMachine::nBytesRead%3904239501F9.attr

      //## Attribute: nEndOfData%390423C50111
      //## begin CLGXLNPStateMachine::nEndOfData%390423C50111.attr preserve=no  private: unsigned char {U} 
      unsigned char m_nEndOfData;
      //## end CLGXLNPStateMachine::nEndOfData%390423C50111.attr

      //## Attribute: pData%390424740113
      //## begin CLGXLNPStateMachine::pData%390424740113.attr preserve=no  private: unsigned char [LNP_MAX_BUFFER_SIZE] {U} 
      unsigned char  m_pData[LNP_MAX_BUFFER_SIZE];
      //## end CLGXLNPStateMachine::pData%390424740113.attr

    // Additional Implementation Declarations
      //## begin CLGXLNPStateMachine%390423830080.implementation preserve=yes
      //## end CLGXLNPStateMachine%390423830080.implementation

};

//## begin CLGXLNPStateMachine%390423830080.postscript preserve=yes
//## end CLGXLNPStateMachine%390423830080.postscript

//## Class: CLGXLNPAddressedFrame%3902E0940347
//## Category: LGX LNP Helper%3902D7BA0353
//## Subsystem: Channel%3902D580003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLGXLNPAddressedFrame : public CLGXLNPFrame  //## Inherits: <unnamed>%390443D30356
{
  //## begin CLGXLNPAddressedFrame%3902E0940347.initialDeclarations preserve=yes
  //## end CLGXLNPAddressedFrame%3902E0940347.initialDeclarations

  public:
    //## Constructors (generated)
      CLGXLNPAddressedFrame();

    //## Constructors (specified)
      //## Operation: CLGXLNPAddressedFrame%956588857
      CLGXLNPAddressedFrame (unsigned char* pFrame, unsigned char nLength);

    //## Destructor (generated)
      virtual ~CLGXLNPAddressedFrame();


    //## Other Operations (specified)
      //## Operation: Build%956588845
      bool Build (THOSTID nDestHostID, TPORTID nDestPortID, THOSTID nSrcHostID, TPORTID nSrcPortID, unsigned char nLength, unsigned char* pData);

      //## Operation: GetData%956487445
      unsigned char * GetData ();

      //## Operation: GetDataLength%956494574
      unsigned char GetDataLength ();

      //## Operation: GetDestHostID%956588853
      THOSTID GetDestHostID ();

      //## Operation: GetDestPortID%956588854
      TPORTID GetDestPortID ();

      //## Operation: GetSrcHostID%956588855
      THOSTID GetSrcHostID ();

      //## Operation: GetSrcPortID%956588856
      TPORTID GetSrcPortID ();

    // Additional Public Declarations
      //## begin CLGXLNPAddressedFrame%3902E0940347.public preserve=yes
      //## end CLGXLNPAddressedFrame%3902E0940347.public

  protected:
    // Additional Protected Declarations
      //## begin CLGXLNPAddressedFrame%3902E0940347.protected preserve=yes
      //## end CLGXLNPAddressedFrame%3902E0940347.protected

  private:
    // Additional Private Declarations
      //## begin CLGXLNPAddressedFrame%3902E0940347.private preserve=yes
      //## end CLGXLNPAddressedFrame%3902E0940347.private

  private:  //## implementation
    // Additional Implementation Declarations
      //## begin CLGXLNPAddressedFrame%3902E0940347.implementation preserve=yes
      //## end CLGXLNPAddressedFrame%3902E0940347.implementation

};

//## begin CLGXLNPAddressedFrame%3902E0940347.postscript preserve=yes
//## end CLGXLNPAddressedFrame%3902E0940347.postscript

//## Class: CLGXLNPBroadcastFrame%390443D80096
//## Category: LGX LNP Helper%3902D7BA0353
//## Subsystem: Channel%3902D580003C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLGXLNPBroadcastFrame : public CLGXLNPFrame  //## Inherits: <unnamed>%3904615B0115
{
  //## begin CLGXLNPBroadcastFrame%390443D80096.initialDeclarations preserve=yes
  //## end CLGXLNPBroadcastFrame%390443D80096.initialDeclarations

  public:
    //## Constructors (generated)
      CLGXLNPBroadcastFrame();

    //## Constructors (specified)
      //## Operation: CLGXLNPBroadcastFrame%956588858
      CLGXLNPBroadcastFrame (unsigned char* pFrame, unsigned char nLength);

    //## Destructor (generated)
      virtual ~CLGXLNPBroadcastFrame();


    //## Other Operations (specified)
      //## Operation: Build%956588847
      bool Build (unsigned char nLength, unsigned char* pData);

      //## Operation: GetData%956588849
      unsigned char * GetData ();

      //## Operation: GetDataLength%956588851
      unsigned char GetDataLength ();

    // Additional Public Declarations
      //## begin CLGXLNPBroadcastFrame%390443D80096.public preserve=yes
      //## end CLGXLNPBroadcastFrame%390443D80096.public

  protected:
    // Additional Protected Declarations
      //## begin CLGXLNPBroadcastFrame%390443D80096.protected preserve=yes
      //## end CLGXLNPBroadcastFrame%390443D80096.protected

  private:
    // Additional Private Declarations
      //## begin CLGXLNPBroadcastFrame%390443D80096.private preserve=yes
      //## end CLGXLNPBroadcastFrame%390443D80096.private

  private:  //## implementation
    // Additional Implementation Declarations
      //## begin CLGXLNPBroadcastFrame%390443D80096.implementation preserve=yes
      //## end CLGXLNPBroadcastFrame%390443D80096.implementation

};

//## begin CLGXLNPBroadcastFrame%390443D80096.postscript preserve=yes
//## end CLGXLNPBroadcastFrame%390443D80096.postscript

// Class CLGXLNPFrame 

// Class CLGXLNPStateMachine 

// Class CLGXLNPAddressedFrame 

// Class CLGXLNPBroadcastFrame 

//## begin module%3902D5EF0168.epilog preserve=yes
//## end module%3902D5EF0168.epilog


#endif
