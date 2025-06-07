#include <public/ccobsmng_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCObsMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCObsMng &act,
	 Pr_Time & EDROOMpVarVNextTimeOut ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	Obs_Mng_Ctrl(EDROOMcomponent.Obs_Mng_Ctrl),
	ObservTimer(EDROOMcomponent.ObservTimer),
	AttCtrlTimer(EDROOMcomponent.AttCtrlTimer),
	CImageInterval(0,500000),
	VNextTimeOut(EDROOMpVarVNextTimeOut)
{
}

CCObsMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	Obs_Mng_Ctrl(context.Obs_Mng_Ctrl),
	ObservTimer(context.ObservTimer),
	AttCtrlTimer(context.AttCtrlTimer),
	CImageInterval(0,500000),
	VNextTimeOut(context.VNextTimeOut)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCObsMng::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	CCObsMng::EDROOM_CTX_Top_0::FDoActtitudeCtrl()

{

pus_service129_do_attitude_ctrl();

}



void	CCObsMng::EDROOM_CTX_Top_0::FEndObservation()

{

VNextTimeOut.GetTime();


}



void	CCObsMng::EDROOM_CTX_Top_0::FExecObsMng_TC()

{
   //Handle Msg->data
  CDTCHandler & varSSObsMng_TC = *(CDTCHandler *)Msg->data;
 
 
	varSSObsMng_TC.ExecTC();

}



void	CCObsMng::EDROOM_CTX_Top_0::FInit()

{
   //Define absolute time
  Pr_Time time;
	 
	//Timing Service useful methods
	 
	//time.GetTime(); // Get current monotonic time
	//time.Add(X,Y); // Add X sec + Y microsec
time.GetTime(); // Get current monotonic time   
time+=Pr_Time(0,100000); // Add X sec + Y microsec    
 
   //Program absolute timer 
   AttCtrlTimer.InformAt( time ); 
}



void	CCObsMng::EDROOM_CTX_Top_0::FProgAttitudeCtrl()

{
   //Define absolute time
  Pr_Time time;
	 
	//Timing Service useful methods
	 
	//time.GetTime(); // Get current monotonic time
	//time.Add(X,Y); // Add X sec + Y microse
 
VNextTimeOut+= Pr_Time(0,10000); // Add X sec + Y microsec 
time=VNextTimeOut; 
   //Program absolute timer 
   AttCtrlTimer.InformAt( time ); 
}



void	CCObsMng::EDROOM_CTX_Top_0::FProgTakeImage()

{
   //Define interval
  Pr_Time interval;
	 
	//Timing Service useful methods
	 
	//time.GetTime(); // Get current monotonic time
	//time.Add(X,Y); // Add X sec + Y microsec
	interval=CImageInterval;
   //Program relative timer 
   ObservTimer.InformIn( interval ); 
}



void	CCObsMng::EDROOM_CTX_Top_0::FTakeImage()

{

pus_service129_take_image();

}



void	CCObsMng::EDROOM_CTX_Top_0::FToObservation()

{

pus_service129_start_observation();

}



bool	CCObsMng::EDROOM_CTX_Top_0::GLastImage()

{

pus_service129_is_last_image();

}



bool	CCObsMng::EDROOM_CTX_Top_0::GReadyToObservation()

{

return pus_service129_is_observation_ready();

}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCObsMng::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCObsMng&act):
		EDROOM_CTX_Top_0(act,
			VNextTimeOut)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCObsMng::EDROOM_SUB_Top_0::EDROOMBehaviour()
{

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIArrival();

	do
	{

		//Take next transition

		switch(edroomCurrentTrans.localId)
		{

			//Next Transition is Init
			case (Init):
				//Execute Action 
				FInit();
				//Next State is StandBy
				edroomNextState = StandBy;
				break;
			//To Choice Point DoAttCtrl
			case (DoAttCtrl):

				//Execute Action 
				FDoActtitudeCtrl();
				//Evaluate Branch ReadyToObs
				if( GReadyToObservation() )
				{
					//Execute Action 
					FToObservation();

					//Branch taken is DoAttCtrl_ReadyToObs
					edroomCurrentTrans.localId =
						DoAttCtrl_ReadyToObs;

					//Next State is Observation
					edroomNextState = Observation;
				 } 
				//Default Branch ProgAttCtrl
				else
				{
					//Execute Action 
					FProgAttitudeCtrl();

					//Branch taken is DoAttCtrl_ProgAttCtrl
					edroomCurrentTrans.localId =
						DoAttCtrl_ProgAttCtrl;

					//Next State is StandBy
					edroomNextState = StandBy;
				 } 
				break;
			//To Choice Point IsLastImage
			case (IsLastImage):

				//Execute Action 
				FTakeImage();
				//Evaluate Branch LastImage
				if( GLastImage() )
				{
					//Execute Actions 
					FEndObservation();
					FProgAttitudeCtrl();

					//Branch taken is IsLastImage_LastImage
					edroomCurrentTrans.localId =
						IsLastImage_LastImage;

					//Next State is StandBy
					edroomNextState = StandBy;
				 } 
				//Default Branch NoLastImage
				else
				{

					//Branch taken is IsLastImage_NoLastImage
					edroomCurrentTrans.localId =
						IsLastImage_NoLastImage;

					//Next State is Observation
					edroomNextState = Observation;
				 } 
				break;
			//Next Transition is ExecObsMng
			case (ExecObsMng):
				//Msg->Data Handling 
				FExecObsMng_TC();
				//Next State is StandBy
				edroomNextState = StandBy;
				break;
		}

		//Entry into the Next State 
		switch(edroomNextState)
		{

				//Go to the state I
			case (I):
				//Arrival to state I
				edroomCurrentTrans=EDROOMIArrival();
				break;

				//Go to the state StandBy
			case (StandBy):
				//Arrival to state StandBy
				edroomCurrentTrans=EDROOMStandByArrival();
				break;

				//Go to the state Observation
			case (Observation):
				//Execute Entry Action 
				FProgTakeImage();
				//Arrival to state Observation
				edroomCurrentTrans=EDROOMObservationArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCObsMng::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCObsMng::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  StandBy

	// ***********************************************************************



TEDROOMTransId CCObsMng::EDROOM_SUB_Top_0::EDROOMStandByArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == AttCtrlTimer)
				{

					//Next transition is  DoAttCtrl
					edroomCurrentTrans.localId = DoAttCtrl;
					edroomCurrentTrans.distanceToContext = 0 ;
					edroomValidMsg=true;
				 }

				break;

			case (SSObsMng_TC): 

				 if (*Msg->GetPInterface() == Obs_Mng_Ctrl)
				{

					//Next transition is  ExecObsMng
					edroomCurrentTrans.localId= ExecObsMng;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Observation

	// ***********************************************************************



TEDROOMTransId CCObsMng::EDROOM_SUB_Top_0::EDROOMObservationArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == ObservTimer)
				{

					//Next transition is  IsLastImage
					edroomCurrentTrans.localId = IsLastImage;
					edroomCurrentTrans.distanceToContext = 0 ;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



