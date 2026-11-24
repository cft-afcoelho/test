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
                     // _tend = Timeout_ms * DAUT_Ct_1MS + call(C6TC_Se_GetTime, \first).result, with DAUT_Ct_1MS = 1000000 (ns)
                     // Loop exits on the first available message: all the previous receptions are unavailable and before timeout
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync) - 1) call(DANW_Se_FIUL_Receive_ST_Sync, i).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE;
                     ∀ i ∈ [1, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(C6TC_Se_GetTime, i).result < _tend;
                     // Message available at the first reception
                     nbcalls(DANW_Se_FIUL_Receive_ST_Sync) ≡ 1;
                     // Message available after several unavailable receptions
                     nbcalls(DANW_Se_FIUL_Receive_ST_Sync) > 1;
                     // Message available at the last reception just before timeout (boundary)
                     call(C6TC_Se_GetTime, nbcalls(DANW_Se_FIUL_Receive_ST_Sync) - 1).result ≡ _tend - 1;
                     Timeout_ms ≡ minof(unsigned int);
                     Timeout_ms ∈ (minof(unsigned int), maxof(unsigned int));
                     Timeout_ms ≡ maxof(unsigned int);
                     // call(C6TC_Se_GetTime, 0).result ≡ maxof(unsigned long long int) is not tested: time shall be ever increasing
                     call(C6TC_Se_GetTime, 0).result ≡ minof(unsigned long long int);
                     call(C6TC_Se_GetTime, 0).result ∈ (minof(unsigned long long int), maxof(unsigned long long int));
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
                     CheckMsgValue ≡ TRUE;
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
                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_DONE;
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
                     TxMsg ≡ DADC_Ce_ST_RendezVousMsg_OK;
                     TxMsg ≡ minof(unsigned char);
                     TxMsg ≡ maxof(unsigned char);
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
                  ldsof(allcall(C6TC_Se_GetTime).result) = {
                     // Message available at first reception
                     {\genarrayof(unsigned long long int, 2) \fill (minof(unsigned long long int)) \with [1] = 1},
                     // Message available after 3 unavailable receptions (_tend = 10001000)
                     {\genarrayof(unsigned long long int, 5) \fill (1000) \with [1] = 2000, [2] = 3000, [3] = 4000, [4] = 5000},
                     // Message available at last reception just before timeout (_tend = 1000000)
                     {\genarrayof(unsigned long long int, 4) \fill (minof(unsigned long long int)) \with [1] = 500000, [2] = 999999, [3] = 1000000},
                     // Maximal timeout
                     {\genarrayof(unsigned long long int, 3) \fill (123456789) \with [1] = 123456790, [2] = 123456791}
                  };
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).result) = {
                     {\genarrayof(C6CT_Te_FIULRxStatus, 1) \fill (C6CT_Ct_FIUL_RX_AVAILABLE)},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 4) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE) \with [3] = C6CT_Ct_FIUL_RX_AVAILABLE},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 3) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE) \with [2] = C6CT_Ct_FIUL_RX_AVAILABLE},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 2) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE) \with [1] = C6CT_Ct_FIUL_RX_AVAILABLE}
                  };
                  ldsof(Timeout_ms) = {
                     minof(unsigned int),
                     10,
                     1,
                     maxof(unsigned int)
                  };
               }

               tuple tuple_1(CheckMsgValue)
               {
                  ldsof(CheckMsgValue) = {
                     TRUE
                  };
               }

               tuple tuple_2(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  ldsof(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result) = {
                     C6CT_Ct_FIUL_TX_DONE
                  };
               }

               tuple tuple_3(TxMsg)
               {
                  ldsof(TxMsg) = {
                     DADC_Ce_ST_RendezVousMsg_OK,
                     minof(unsigned char),
                     maxof(unsigned char)
                  };
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
                     // C6TC_Se_GetTime and DANW_Se_FIUL_Receive_ST_Sync are not called when the transmission fails
                     nbcalls(C6TC_Se_GetTime) ≡ 0;
                     nbcalls(DANW_Se_FIUL_Receive_ST_Sync) ≡ 0;
                     Timeout_ms ≡ minof(unsigned int);
                     Timeout_ms ∈ (minof(unsigned int), maxof(unsigned int));
                     Timeout_ms ≡ maxof(unsigned int);
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
                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_CMD_FULL;
                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_PORT_FULL;
                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_NOT_DONE_DROPPED;
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
                     TxMsg ≡ DADC_Ce_ST_RendezVousMsg_OK;
                     TxMsg ≡ minof(unsigned char);
                     TxMsg ≡ maxof(unsigned char);
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
                  ldsof(allcall(C6TC_Se_GetTime).result) = {
                     // Not called when the transmission fails
                     {\genarrayof(unsigned long long int, 2) \fill (minof(unsigned long long int)) \with [1] = 1},
                     {\genarrayof(unsigned long long int, 2) \fill (minof(unsigned long long int)) \with [1] = 1},
                     {\genarrayof(unsigned long long int, 2) \fill (minof(unsigned long long int)) \with [1] = 1}
                  };
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).result) = {
                     // Not called when the transmission fails
                     {\genarrayof(C6CT_Te_FIULRxStatus, 1) \fill (C6CT_Ct_FIUL_RX_AVAILABLE)},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 1) \fill (C6CT_Ct_FIUL_RX_AVAILABLE)},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 1) \fill (C6CT_Ct_FIUL_RX_AVAILABLE)}
                  };
                  ldsof(Timeout_ms) = {
                     minof(unsigned int),
                     1000,
                     maxof(unsigned int)
                  };
               }

               tuple tuple_1(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  ldsof(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result) = {
                     C6CT_Ct_FIUL_TX_NOT_DONE_CMD_FULL,
                     C6CT_Ct_FIUL_TX_NOT_DONE_PORT_FULL,
                     C6CT_Ct_FIUL_TX_NOT_DONE_DROPPED
                  };
               }

               tuple tuple_2(TxMsg)
               {
                  ldsof(TxMsg) = {
                     DADC_Ce_ST_RendezVousMsg_OK,
                     minof(unsigned char),
                     maxof(unsigned char)
                  };
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
                     // _tend = Timeout_ms * DAUT_Ct_1MS + call(C6TC_Se_GetTime, \first).result, with DAUT_Ct_1MS = 1000000 (ns)
                     // All the receptions but the last one are unavailable and before timeout
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync) - 1) call(DANW_Se_FIUL_Receive_ST_Sync, i).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE;
                     ∀ i ∈ [1, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(C6TC_Se_GetTime, i).result < _tend;
                     // Message received with dropped message(s)
                     call(DANW_Se_FIUL_Receive_ST_Sync, \last).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE ∧ nbcalls(DANW_Se_FIUL_Receive_ST_Sync) ≡ 1;
                     call(DANW_Se_FIUL_Receive_ST_Sync, \last).result ≡ C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE ∧ nbcalls(DANW_Se_FIUL_Receive_ST_Sync) > 1;
                     // Timeout reached without any message
                     call(DANW_Se_FIUL_Receive_ST_Sync, \last).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE ∧ call(C6TC_Se_GetTime, \last).result ≡ _tend;
                     call(DANW_Se_FIUL_Receive_ST_Sync, \last).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE ∧ call(C6TC_Se_GetTime, \last).result > _tend;
                     Timeout_ms ≡ minof(unsigned int);
                     Timeout_ms ∈ (minof(unsigned int), maxof(unsigned int));
                     Timeout_ms ≡ maxof(unsigned int);
                     // call(C6TC_Se_GetTime, 0).result ≡ maxof(unsigned long long int) is not tested: time shall be ever increasing
                     call(C6TC_Se_GetTime, 0).result ≡ minof(unsigned long long int);
                     call(C6TC_Se_GetTime, 0).result ∈ (minof(unsigned long long int), maxof(unsigned long long int));
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
                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_DONE;
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
                     TxMsg ≡ DADC_Ce_ST_RendezVousMsg_OK;
                     TxMsg ≡ minof(unsigned char);
                     TxMsg ≡ maxof(unsigned char);
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
                     // Only one byte is expected (ExpectedSize = sizeof(BYTE)), OppositeStatus = call(DANW_Se_FIUL_Receive_ST_Sync, \last).out(Data)[0]
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(DANW_Se_FIUL_Receive_ST_Sync, i).out(Data)[0] ≡ DADC_Ce_ST_RendezVousMsg_OK;
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(DANW_Se_FIUL_Receive_ST_Sync, i).out(Data)[0] ≡ minof(unsigned char);
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(DANW_Se_FIUL_Receive_ST_Sync, i).out(Data)[0] ≡ maxof(unsigned char);
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
                  ldsof(allcall(C6TC_Se_GetTime).result) = {
                     // Message with dropped message(s) at first reception
                     {\genarrayof(unsigned long long int, 2) \fill (minof(unsigned long long int)) \with [1] = 1},
                     // Message with dropped message(s) after 2 unavailable receptions (_tend = 10001000)
                     {\genarrayof(unsigned long long int, 4) \fill (1000) \with [1] = 2000, [2] = 3000, [3] = 4000},
                     // Null timeout: timeout reached after the first reception (_tend = 5000)
                     {\genarrayof(unsigned long long int, 2) \fill (5000) \with [1] = 5001},
                     // Timeout reached exactly (boundary, _tend = 1000000)
                     {\genarrayof(unsigned long long int, 4) \fill (minof(unsigned long long int)) \with [1] = 400000, [2] = 800000, [3] = 1000000},
                     // Timeout exceeded (_tend = 2001000)
                     {\genarrayof(unsigned long long int, 3) \fill (1000) \with [1] = 1500000, [2] = 2500000},
                     // Maximal timeout with dropped message(s)
                     {\genarrayof(unsigned long long int, 2) \fill (123456789) \with [1] = 123456790}
                  };
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).result) = {
                     {\genarrayof(C6CT_Te_FIULRxStatus, 1) \fill (C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE)},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 3) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE) \with [2] = C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 1) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE)},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 3) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE)},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 2) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE)},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 1) \fill (C6CT_Ct_FIUL_RX_AVAILABLE_WITH_DROPPED_MESSAGE)}
                  };
                  ldsof(Timeout_ms) = {
                     1000,
                     10,
                     minof(unsigned int),
                     1,
                     2,
                     maxof(unsigned int)
                  };
               }

               tuple tuple_1(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  ldsof(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result) = {
                     C6CT_Ct_FIUL_TX_DONE
                  };
               }

               tuple tuple_2(TxMsg)
               {
                  ldsof(TxMsg) = {
                     DADC_Ce_ST_RendezVousMsg_OK,
                     minof(unsigned char),
                     maxof(unsigned char)
                  };
               }

               tuple tuple_3(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data))
               {
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data)) = {
                     // One byte per call, uniform so that the last call value is deterministic
                     {{DADC_Ce_ST_RendezVousMsg_OK}, {DADC_Ce_ST_RendezVousMsg_OK}, {DADC_Ce_ST_RendezVousMsg_OK}, {DADC_Ce_ST_RendezVousMsg_OK}},
                     {{minof(unsigned char)}, {minof(unsigned char)}, {minof(unsigned char)}, {minof(unsigned char)}},
                     {{maxof(unsigned char)}, {maxof(unsigned char)}, {maxof(unsigned char)}, {maxof(unsigned char)}}
                  };
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
                     // _tend = Timeout_ms * DAUT_Ct_1MS + call(C6TC_Se_GetTime, \first).result, with DAUT_Ct_1MS = 1000000 (ns)
                     // Loop exits on the first available message: all the previous receptions are unavailable and before timeout
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync) - 1) call(DANW_Se_FIUL_Receive_ST_Sync, i).result ≡ C6CT_Ct_FIUL_RX_UNAVAILABLE;
                     ∀ i ∈ [1, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(C6TC_Se_GetTime, i).result < _tend;
                     // Message available at the first reception
                     nbcalls(DANW_Se_FIUL_Receive_ST_Sync) ≡ 1;
                     // Message available after several unavailable receptions
                     nbcalls(DANW_Se_FIUL_Receive_ST_Sync) > 1;
                     // Message available at the last reception just before timeout (boundary)
                     call(C6TC_Se_GetTime, nbcalls(DANW_Se_FIUL_Receive_ST_Sync) - 1).result ≡ _tend - 1;
                     Timeout_ms ≡ minof(unsigned int);
                     Timeout_ms ∈ (minof(unsigned int), maxof(unsigned int));
                     Timeout_ms ≡ maxof(unsigned int);
                     // call(C6TC_Se_GetTime, 0).result ≡ maxof(unsigned long long int) is not tested: time shall be ever increasing
                     call(C6TC_Se_GetTime, 0).result ≡ minof(unsigned long long int);
                     call(C6TC_Se_GetTime, 0).result ∈ (minof(unsigned long long int), maxof(unsigned long long int));
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
                     CheckMsgValue ≡ FALSE;
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
                     call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result ≡ C6CT_Ct_FIUL_TX_DONE;
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
                     TxMsg ≡ DADC_Ce_ST_RendezVousMsg_OK;
                     TxMsg ≡ minof(unsigned char);
                     TxMsg ≡ maxof(unsigned char);
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
                     // Message value is not checked: an unexpected value shall not raise an error
                     // Only one byte is expected (ExpectedSize = sizeof(BYTE)), OppositeStatus = call(DANW_Se_FIUL_Receive_ST_Sync, \last).out(Data)[0]
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(DANW_Se_FIUL_Receive_ST_Sync, i).out(Data)[0] ≡ DADC_Ce_ST_RendezVousMsg_OK;
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(DANW_Se_FIUL_Receive_ST_Sync, i).out(Data)[0] ≡ minof(unsigned char);
                     ∀ i ∈ [0, nbcalls(DANW_Se_FIUL_Receive_ST_Sync)) call(DANW_Se_FIUL_Receive_ST_Sync, i).out(Data)[0] ≡ maxof(unsigned char);
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
                  ldsof(allcall(C6TC_Se_GetTime).result) = {
                     // Message available at first reception
                     {\genarrayof(unsigned long long int, 2) \fill (minof(unsigned long long int)) \with [1] = 1},
                     // Message available after 3 unavailable receptions (_tend = 10001000)
                     {\genarrayof(unsigned long long int, 5) \fill (1000) \with [1] = 2000, [2] = 3000, [3] = 4000, [4] = 5000},
                     // Message available at last reception just before timeout (_tend = 1000000)
                     {\genarrayof(unsigned long long int, 4) \fill (minof(unsigned long long int)) \with [1] = 500000, [2] = 999999, [3] = 1000000},
                     // Maximal timeout
                     {\genarrayof(unsigned long long int, 3) \fill (123456789) \with [1] = 123456790, [2] = 123456791}
                  };
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).result) = {
                     {\genarrayof(C6CT_Te_FIULRxStatus, 1) \fill (C6CT_Ct_FIUL_RX_AVAILABLE)},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 4) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE) \with [3] = C6CT_Ct_FIUL_RX_AVAILABLE},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 3) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE) \with [2] = C6CT_Ct_FIUL_RX_AVAILABLE},
                     {\genarrayof(C6CT_Te_FIULRxStatus, 2) \fill (C6CT_Ct_FIUL_RX_UNAVAILABLE) \with [1] = C6CT_Ct_FIUL_RX_AVAILABLE}
                  };
                  ldsof(Timeout_ms) = {
                     minof(unsigned int),
                     10,
                     1,
                     maxof(unsigned int)
                  };
               }

               tuple tuple_1(CheckMsgValue)
               {
                  ldsof(CheckMsgValue) = {
                     FALSE
                  };
               }

               tuple tuple_2(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result)
               {
                  ldsof(call(DANW_Se_FIUL_Transmit_ST_Sync, 0).result) = {
                     C6CT_Ct_FIUL_TX_DONE
                  };
               }

               tuple tuple_3(TxMsg)
               {
                  ldsof(TxMsg) = {
                     DADC_Ce_ST_RendezVousMsg_OK,
                     minof(unsigned char),
                     maxof(unsigned char)
                  };
               }

               tuple tuple_4(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data))
               {
                  ldsof(allcall(DANW_Se_FIUL_Receive_ST_Sync).out(Data)) = {
                     // One byte per call, uniform so that the last call value is deterministic
                     {{DADC_Ce_ST_RendezVousMsg_OK}, {DADC_Ce_ST_RendezVousMsg_OK}, {DADC_Ce_ST_RendezVousMsg_OK}, {DADC_Ce_ST_RendezVousMsg_OK}},
                     {{minof(unsigned char)}, {minof(unsigned char)}, {minof(unsigned char)}, {minof(unsigned char)}},
                     {{maxof(unsigned char)}, {maxof(unsigned char)}, {maxof(unsigned char)}, {maxof(unsigned char)}}
                  };
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
