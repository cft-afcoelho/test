/*
┌────────────────────────────────────────────────────────────────┐
│ DCSL compiler 1.19.4                                           │
│ input file: DADC_Se_ST_RendezVousSync.dcsl.vo.c                │
│                                                                │
│                                                                │
│ This program has been generated automatically                  │
│ It will be further processed by other tools.                   │
│                                                                │
│ FUNCTION: DADC_Se_ST_RendezVousSync                            │
│                                                                │
│ The test vectors for a function.                               │
│                                                                │
│                                                                │
│ It is a non-finalized template that must be edited.            │
│ PLEASE EDIT ONLY THE MARKED-UP PLACES AND THE AUTHORIZED LINES │
│ ANY OTHER MODIFICATION WILL PRODUCE A NON-CONSISTENT FILE      │
│                                                                │
└────────────────────────────────────────────────────────────────┘
*/

function DADC_Se_ST_RendezVousSync
{

   /*
   ┌──────────────────────────────────────────────────────────┐
   │           D E F I N I T I O N   O F  T E S T S           │
   └──────────────────────────────────────────────────────────┘
   */

   tests
   {

      /*
      ┌────────────────────────────────────────┐
      │ Definitions of local literal constants │
      │ which can be used for all testcases    │
      └────────────────────────────────────────┘
      */
      litconstdef
      {
      }

      /*
      ┌─────────────────────────────────────┐
      │ Common definitions and declarations │
      │ useful for all testcases:           │
      │                                     │
      └─────────────────────────────────────┘
      */

      declarations
      {

         /* Declarations of local variables */
      }

      /*
      ┌────────────────────────────────────────────────────┐
      │ TESTCASE OF CONTRACT RendezVous_Success_MsgChecked │
      └────────────────────────────────────────────────────┘
      */
      testcase tc_RendezVous_Success_MsgChecked
      { /* start of testcase of RendezVous_Success_MsgChecked */

         designspec
         {
            RendezVous_Success_MsgChecked;
         }

         instances
         {

            dataspec
            {

               tuple tuple_0(allcall(C6TC_Se_GetTime).result, allcall(DANW_Se_FIUL_Receive_ST_Sync).result, Timeout_ms)
               {
                  design
                  {
                     ∀ i ∈ [0, nbcalls(C6TC_Se_GetTime))
                       call(C6TC_Se_GetTime, i + 1).result > call(C6TC_Se_GetTime, i).result; //section: usage domain
                        ∃ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync))
                           (
                              (
                                 (call(DANW_Se_FIUL_Receive_ST_Sync, i).result ≢  C6CT_Ct_FIUL_RX_UNAVAILABLE) ∨ (call(C6TC_Se_GetTime, i + 1).result ≥ _tend)
                              )
                           ); //section: usage domain
                     call(DANW_Se_FIUL_Receive_ST_Sync, \last).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE; //section: decision
                  }

                  domain
                  {
                     ∀poccur ∈ [0, nbcalls(C6TC_Se_GetTime)) call(C6TC_Se_GetTime, poccur).result ∈ [minof(unsigned long long int), maxof(unsigned long long int)]; //rational: based on type
                     ∀poccur ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) 
                     call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE
                     ∨ call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE
                     ∨ call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE; //rational: based on type
                     Timeout_ms ∈ [minof(unsigned int), maxof(unsigned int)]; //rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_1(CheckMsgValue)
               {
                  design
                  {
                     CheckMsgValue ≡ (1); // section: decision
                  }

                  domain
                  {
                     CheckMsgValue ∈ [minof(unsigned char), maxof(unsigned char)]; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_2(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  design
                  {
                     call(DANW_Se_FIUL_Transmit_ST_Sync, \first).result ≡ C6CT_Ct_FIUL_TX_DONE; // section: decision
                  }

                  domain
                  {

                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_DONE
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_CMD_FULL
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_PORT_FULL
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_DROPPED; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_3(TxMsg)
               {
                  design
                  {
                     // The free variables of this tuple don't appear in a precondition
                     // They contribute only to the elaboration of the outputs
                  }

                  domain
                  {
                     TxMsg ∈ [minof(unsigned char), maxof(unsigned char)]; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               combinedtuple
               {
                  /* By default, tuple with free variable in decision section */
                  tuple_1, tuple_2
               }
            }

            dataset
            {

               tuple tuple_0(allcall(C6TC_Se_GetTime).result, allcall(DANW_Se_FIUL_Receive_ST_Sync).result, Timeout_ms)
               {
                  ldsof(allcall(C6TC_Se_GetTime).result) = {};
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).result) = {};
                  ldsof(Timeout_ms) = {};
               }

               tuple tuple_1(CheckMsgValue)
               {
                  ldsof(CheckMsgValue) = {};
               }

               tuple tuple_2(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  ldsof(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result) = {};
               }

               tuple tuple_3(TxMsg)
               {
                  ldsof(TxMsg) = {};
               }

               combinedtuple
               {
                  /* By default, tuple with free variable in decision section */
                  tuple_1, tuple_2
               }
            }
         }
      } /* end of testcase of RendezVous_Success_MsgChecked */

      /*
      ┌──────────────────────────────────────────────┐
      │ TESTCASE OF CONTRACT MESSAGE_NOT_TRANSMITTED │
      └──────────────────────────────────────────────┘
      */
      testcase tc_MESSAGE_NOT_TRANSMITTED
      { /* start of testcase of MESSAGE_NOT_TRANSMITTED */

         designspec
         {
            MESSAGE_NOT_TRANSMITTED;
         }

         instances
         {

            dataspec
            {

               tuple tuple_0(allcall(C6TC_Se_GetTime).result, allcall(DANW_Se_FIUL_Receive_ST_Sync).result, Timeout_ms)
               {
                  design
                  {
                     ∀ i ∈ [0, nbcalls(C6TC_Se_GetTime))
                       call(C6TC_Se_GetTime, i + 1).result > call(C6TC_Se_GetTime, i).result; //section: usage domain
                        ∃ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync))
                           (
                              (
                                 (call(DANW_Se_FIUL_Receive_ST_Sync, i).result ≢ C6CT_Ct_FIUL_RX_UNAVAILABLE) ∨ (call(C6TC_Se_GetTime, i + 1).result ≥ _tend)
                              )
                           ); //section: usage domain
                  }

                  domain
                  {
                     ∀poccur ∈ [0, nbcalls(C6TC_Se_GetTime)) call(C6TC_Se_GetTime, poccur).result ∈ [minof(unsigned long long int), maxof(unsigned long long int)]; //rational: based on type
                     ∀poccur ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) 
                     call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE
                     ∨ call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE
                     ∨ call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE; //rational: based on type
                     Timeout_ms ∈ [minof(unsigned int), maxof(unsigned int)]; //rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_1(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  design
                  {
                     call(DANW_Se_FIUL_Transmit_ST_Sync, \first).result ≢ C6CT_Ct_FIUL_TX_DONE; // section: decision
                  }

                  domain
                  {

                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_DONE
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_CMD_FULL
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_PORT_FULL
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_DROPPED; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_2(TxMsg)
               {
                  design
                  {
                     // The free variables of this tuple don't appear in a precondition
                     // They contribute only to the elaboration of the outputs
                  }

                  domain
                  {
                     TxMsg ∈ [minof(unsigned char), maxof(unsigned char)]; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               combinedtuple
               {
                  /* no tuple with free variable in decision section */
               }
            }

            dataset
            {

               tuple tuple_0(allcall(C6TC_Se_GetTime).result, allcall(DANW_Se_FIUL_Receive_ST_Sync).result, Timeout_ms)
               {
                  ldsof(allcall(C6TC_Se_GetTime).result) = {};
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).result) = {};
                  ldsof(Timeout_ms) = {};
               }

               tuple tuple_1(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  ldsof(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result) = {};
               }

               tuple tuple_2(TxMsg)
               {
                  ldsof(TxMsg) = {};
               }

               combinedtuple
               {
                  /* no tuple with free variable in decision section */
               }
            }
         }
      } /* end of testcase of MESSAGE_NOT_TRANSMITTED */

      /*
      ┌────────────────────────────────────────────────────┐
      │ TESTCASE OF CONTRACT RendezVous_ReceivedMsgDropped │
      └────────────────────────────────────────────────────┘
      */
      testcase tc_RendezVous_ReceivedMsgDropped
      { /* start of testcase of RendezVous_ReceivedMsgDropped */

         designspec
         {
            RendezVous_ReceivedMsgDropped;
         }

         instances
         {

            dataspec
            {

               tuple tuple_0(allcall(C6TC_Se_GetTime).result, allcall(DANW_Se_FIUL_Receive_ST_Sync).result, Timeout_ms)
               {
                  design
                  {
                     ∀ i ∈ [0, nbcalls(C6TC_Se_GetTime))
                       call(C6TC_Se_GetTime, i + 1).result > call(C6TC_Se_GetTime, i).result; //section: usage domain
                        ∃ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync))
                           (
                              (
                                 (call(DANW_Se_FIUL_Receive_ST_Sync, i).result ≢ C6CT_Ct_FIUL_RX_UNAVAILABLE) ∨ (call(C6TC_Se_GetTime, i + 1).result ≥ _tend)
                              )
                           ); //section: usage domain
                     call(DANW_Se_FIUL_Receive_ST_Sync, \last).result ≢ C6CT_Ct_FIUL_RX_AVAILABLE; //section: decision
                  }

                  domain
                  {
                     ∀poccur ∈ [0, nbcalls(C6TC_Se_GetTime)) call(C6TC_Se_GetTime, poccur).result ∈ [minof(unsigned long long int), maxof(unsigned long long int)]; //rational: based on type
                     ∀poccur ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) 
                     call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE
                     ∨ call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE
                     ∨ call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE; //rational: based on type
                     Timeout_ms ∈ [minof(unsigned int), maxof(unsigned int)]; //rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_1(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  design
                  {
                     call(DANW_Se_FIUL_Transmit_ST_Sync, \first).result ≡ C6CT_Ct_FIUL_TX_DONE; // section: decision
                  }

                  domain
                  {

                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_DONE
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_CMD_FULL
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_PORT_FULL
                     ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_DROPPED; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_2(TxMsg)
               {
                  design
                  {
                     // The free variables of this tuple don't appear in a precondition
                     // They contribute only to the elaboration of the outputs
                  }

                  domain
                  {
                     TxMsg ∈ [minof(unsigned char), maxof(unsigned char)]; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_3(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data))
               {
                  design
                  {
                     // The free variables of this tuple don't appear in a precondition
                     // They contribute only to the elaboration of the outputs
                  }

                  domain
                  {
                     ∀poccur ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) ∀k ∈ [0, call(DANW_Se_FIUL_Receive_ST_Sync, (__DANW_Se_FIUL_Receive_ST_Sync_cpt - 1)).out(Size)) (call(DANW_Se_FIUL_Receive_ST_Sync, poccur).out(Data))[k] ∈ [minof(unsigned char), maxof(unsigned char)]; //rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               combinedtuple
               {
                  /* no tuple with free variable in decision section */
               }
            }

            dataset
            {

               tuple tuple_0(allcall(C6TC_Se_GetTime).result, allcall(DANW_Se_FIUL_Receive_ST_Sync).result, Timeout_ms)
               {
                  ldsof(allcall(C6TC_Se_GetTime).result) = {};
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).result) = {};
                  ldsof(Timeout_ms) = {};
               }

               tuple tuple_1(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  ldsof(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result) = {};
               }

               tuple tuple_2(TxMsg)
               {
                  ldsof(TxMsg) = {};
               }

               tuple tuple_3(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data))
               {
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data)) = {};
               }

               combinedtuple
               {
                  /* no tuple with free variable in decision section */
               }
            }
         }
      } /* end of testcase of RendezVous_ReceivedMsgDropped */

      /*
      ┌────────────────────────────────────────────────────┐
      │ TESTCASE OF CONTRACT RendezVous_Success_NoMsgCheck │
      └────────────────────────────────────────────────────┘
      */
      testcase tc_RendezVous_Success_NoMsgCheck
      { /* start of testcase of RendezVous_Success_NoMsgCheck */

         designspec
         {
            RendezVous_Success_NoMsgCheck;
         }

         instances
         {

            dataspec
            {

               tuple tuple_0(allcall(C6TC_Se_GetTime).result, allcall(DANW_Se_FIUL_Receive_ST_Sync).result, Timeout_ms)
               {
                  design
                  {
∀ i ∈ [0, nbcalls(C6TC_Se_GetTime))
                       call(C6TC_Se_GetTime, i + 1).result > call(C6TC_Se_GetTime, i).result; //section: usage domain
∃ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync))
                (
                    (
                        (call(DANW_Se_FIUL_Receive_ST_Sync, i).result ≢ C6CT_Ct_FIUL_RX_UNAVAILABLE) ∨ (call(C6TC_Se_GetTime, i + 1).result ≥ _tend)
                    )
                ); //section: usage domain
call(DANW_Se_FIUL_Receive_ST_Sync, \last).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE; //section: decision
                  }

                  domain
                  {
∀poccur ∈ [0, nbcalls(C6TC_Se_GetTime)) call(C6TC_Se_GetTime, poccur).result ∈ [minof(unsigned long long int), maxof(unsigned long long int)]; //rational: based on type
∀poccur ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) 
call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE
 ∨ call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE
 ∨ call(DANW_Se_FIUL_Receive_ST_Sync, poccur).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE; //rational: based on type
Timeout_ms ∈ [minof(unsigned int), maxof(unsigned int)]; //rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_1(CheckMsgValue)
               {
                  design
                  {
                     CheckMsgValue ≡ (0); // section: decision
                  }

                  domain
                  {
                     CheckMsgValue ∈ [minof(unsigned char), maxof(unsigned char)]; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_2(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  design
                  {
                     call(DANW_Se_FIUL_Transmit_ST_Sync, \first).result ≡ C6CT_Ct_FIUL_TX_DONE; // section: decision
                  }

                  domain
                  {

                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_DONE
 ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_CMD_FULL
 ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_PORT_FULL
 ∨ call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_DROPPED; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_3(TxMsg)
               {
                  design
                  {
                     // The free variables of this tuple don't appear in a precondition
                     // They contribute only to the elaboration of the outputs
                  }

                  domain
                  {
                     TxMsg ∈ [minof(unsigned char), maxof(unsigned char)]; // rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               tuple tuple_4(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data))
               {
                  design
                  {
                     // The free variables of this tuple don't appear in a precondition
                     // They contribute only to the elaboration of the outputs
                  }

                  domain
                  {
∀poccur ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) ∀k ∈ [0, call(DANW_Se_FIUL_Receive_ST_Sync, (__DANW_Se_FIUL_Receive_ST_Sync_cpt - 1)).out(Size)) (call(DANW_Se_FIUL_Receive_ST_Sync, poccur).out(Data))[k] ∈ [minof(unsigned char), maxof(unsigned char)]; //rational: based on type
                  }

                  additional
                  {
                     // Users shall identify the additional constraints
                     // from design and domain constrains identified above
                     // in according to the equivalence method classes
                  }
               }

               combinedtuple
               {
                  /* By default, tuple with free variable in decision section */
                  tuple_1, tuple_2
               }
            }

            dataset
            {

               tuple tuple_0(allcall(C6TC_Se_GetTime).result, allcall(DANW_Se_FIUL_Receive_ST_Sync).result, Timeout_ms)
               {
                  ldsof(allcall(C6TC_Se_GetTime).result) = {};
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).result) = {};
                  ldsof(Timeout_ms) = {};
               }

               tuple tuple_1(CheckMsgValue)
               {
                  ldsof(CheckMsgValue) = {};
               }

               tuple tuple_2(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  ldsof(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result) = {};
               }

               tuple tuple_3(TxMsg)
               {
                  ldsof(TxMsg) = {};
               }

               tuple tuple_4(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data))
               {
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data)) = {};
               }

               combinedtuple
               {
                  /* By default, tuple with free variable in decision section */
                  tuple_1, tuple_2
               }
            }
         }
      } /* end of testcase of RendezVous_Success_NoMsgCheck */
   } /* end deftest */

} /* end function design */

