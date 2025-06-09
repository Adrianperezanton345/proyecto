#include <public/cccameramng_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCCameraMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCCameraMng &act,
	 Pr_Time & EDROOMpVarVNextTimeOut ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	CameraCtrl(EDROOMcomponent.CameraCtrl),
	CameraTimer(EDROOMcomponent.CameraTimer),
	AttitudeTimer(EDROOMcomponent.AttitudeTimer),
	CPeriod(0,100000),
	VNextTimeOut(EDROOMpVarVNextTimeOut)
{
}

CCCameraMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	CameraCtrl(context.CameraCtrl),
	CameraTimer(context.CameraTimer),
	AttitudeTimer(context.AttitudeTimer),
	CPeriod(0,100000),
	VNextTimeOut(context.VNextTimeOut)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCCameraMng::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		// Check trigger for signal EDROOMSignalTimeout

		 case (EDROOMSignalTimeout): 

				if (*Msg->GetPInterface() == AttitudeTimer)
				{

					//Next transition is  DoAttitude
					edroomCurrentTrans.localId= DoAttitude;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

			 break;

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	CCCameraMng::EDROOM_CTX_Top_0::FDoAttitudeCtrl()

{
   //Define absolute time
  Pr_Time time;
	 

pus_service129_do_attitude_ctrl();
 
VNextTimeOut+=CPeriod;
 
time=VNextTimeOut;
   //Program absolute timer 
   AttitudeTimer.InformAt( time ); 
}



void	CCCameraMng::EDROOM_CTX_Top_0::FInit()

{
   //Define absolute time
  Pr_Time time;
 
 time.GetTime();
 time+=CPeriod;
 
 VNextTimeOut=time;

pus_service129_init();
   //Program absolute timer 
   AttitudeTimer.InformAt( time ); 
}



void	CCCameraMng::EDROOM_CTX_Top_0::FProgCamera()

{
   //Define interval
  Pr_Time interval;
 
pus_service129_start_observation();
   //Program relative timer 
   CameraTimer.InformIn( interval ); 
}



void	CCCameraMng::EDROOM_CTX_Top_0::FToReady()

{

pus_service129_end_observation();

}



bool	CCCameraMng::EDROOM_CTX_Top_0::GLastImage()

{

return true;

}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCCameraMng::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCCameraMng&act):
		EDROOM_CTX_Top_0(act,
			VNextTimeOut)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCCameraMng::EDROOM_SUB_Top_0::EDROOMBehaviour()
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
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//Next Transition is DoAttitude
			case (DoAttitude):
				//Execute Action 
				FDoAttitudeCtrl();
				//Memory Transition 
				edroomNextState = edroomCurrentState;
				edroomCurrentTrans.localId = EDROOMMemoryTrans;
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

				//Go to the state Ready
			case (Ready):
				//Arrival to state Ready
				edroomCurrentTrans=EDROOMReadyArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCCameraMng::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCCameraMng::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Ready

	// ***********************************************************************



TEDROOMTransId CCCameraMng::EDROOM_SUB_Top_0::EDROOMReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



