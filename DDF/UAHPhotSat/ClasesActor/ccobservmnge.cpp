

#include <public/ccobservmng_iface_v1.h>





// ******************************* CONSTRUCTOR ************************************



CCObservMng::CCObservMng(TEDROOMComponentID id,
		TEDROOMUInt32 roomNumMaxMens,
		TEDROOMPriority roomtaskPrio,
		TEDROOMStackSizeType roomStack,
		CEDROOMMemory *pActorMemory ) : 

		CEDROOMComponent(id,EDROOMprioMINIMUM+1,roomNumMaxMens,
				roomtaskPrio,roomStack, pActorMemory ),

		// *********** Timing service access point *********

		EDROOMtimingSAP(this, 5,&pActorMemory->TimingMemory),

		// *******************  Timers  ********************

		ObservTimer(&EDROOMtimingSAP, 2 ),
		AttCtrlTimer(&EDROOMtimingSAP, 2 ),

		// ***************	Top State  *****************

		edroomTopState(*this)


{


}


//**************************************************************************
//**************************   PUBLIC METHODS  *****************************



//************************** EDROOMConfig **********************************


int CCObservMng::EDROOMConfig()
{


 return 0; 
}



//************************** EDROOMStart **********************************

int CCObservMng::EDROOMStart()
{


	//****************** Timing Task Start*****************

	EDROOMtimingSAP.Start();

	//***************** CEDROOMComponent::EDROOMStart*********

	CEDROOMComponent::EDROOMStart(); 	// Call to EDROOMStart method of CEDROOMComponent

	return 0;
}


//**************************************************************************
//***************************    PROTECTED METHODS *************************



//*****************************  EDROOMBehaviour ***************************



void CCObservMng::EDROOMBehaviour()
{

	edroomTopState.EDROOMInit();
	edroomTopState.EDROOMBehaviour();

}




//********************* ComponentIsFinished **********************************


#ifdef _EDROOM_SYSTEM_CLOSE

bool CCObservMng::EDROOMIsComponentFinished()
{


	return ( CEDROOMComponent::EDROOMIsComponentFinished());

}

#endif


//****************** EDROOMMemory::SetMemory *******************************

void CCObservMng::CEDROOMMemory::SetMemory(TEDROOMUInt32 numMessages_ ,
		CEDROOMMessage * MessagesMem_,
		bool * MessagesMemMarks_,
		TEDROOMUInt32 numberOfNodes_,
		CEDROOMQueue::CQueueNode * QueueNodesMem_,
		bool * QueueNodesMemMarks_)
{

		CEDROOMComponentMemory::SetMemory( numMessages_,MessagesMem_, MessagesMemMarks_,
			numberOfNodes_,QueueNodesMem_, QueueNodesMemMarks_, QueueHeads);

		TimingMemory.SetMemory(5,TimerInf,&TimerInfMarks[0],TimeOutMsgs,&TimeOutMsgsMarks[0]);


}

