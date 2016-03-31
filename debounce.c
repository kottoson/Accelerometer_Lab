#include "debounce.h"
#include "timerA.h"


void InitializeSwitch(SwitchDefine *Switch,char *SwitchPort,unsigned char SwitchBit)
{
	Switch->CurrentState = DbExpectHigh;
	Switch->SwitchPort = SwitchPort;
	Switch->SwitchPortBit = SwitchBit;
	Switch->TimerSnapshot = g1msTimer;
}

SwitchStatus GetSwitch(SwitchDefine *Switch)
{
	return Low;
}

SwitchStatus Debouncer(SwitchDefine *Switch)
{
	SwitchStatus CurrentSwitchReading = Low;
	DbState NextState = DbExpectHigh;

	// First, determine the current inputs.
	volatile DbState thing = Switch-> CurrentState;

	// Next, based on the input values and the current state, determine the next state.
	switch (Switch->CurrentState) {
		case DbExpectHigh:
			if (!(*(Switch->SwitchPort) & Switch->SwitchPortBit)) {
				NextState = DbValidateHigh;
				//CurrentSwitchReading = Low;
				Switch->TimerSnapshot = g1msTimer;
			}
			else {
				NextState = DbExpectHigh;
				CurrentSwitchReading = Low;
			}
		break;
		case DbValidateHigh:
			if (g1msTimer - Switch->TimerSnapshot >= HIGH_THRESHOLD) {
				if (!(*(Switch->SwitchPort) & Switch->SwitchPortBit)) {
					NextState = DbExpectLow;
					CurrentSwitchReading = High;
				} else {
					NextState = DbExpectHigh;
					CurrentSwitchReading = Low;
				}
			} else {
				NextState = DbValidateHigh;
				CurrentSwitchReading = Low;
			}
		break;
		case DbExpectLow:
			if (!(*(Switch->SwitchPort) & Switch->SwitchPortBit)) {
				NextState = DbExpectLow;
				CurrentSwitchReading = High;
			} else {
				NextState = DbValidateLow;
				CurrentSwitchReading = High;
				Switch->TimerSnapshot = g1msTimer;
			}
		break;
		case DbValidateLow:
			if (g1msTimer - Switch->TimerSnapshot >= LOW_THRESHOLD) {
				if (!(*(Switch->SwitchPort) & Switch->SwitchPortBit)) {
					NextState = DbExpectLow;
					CurrentSwitchReading = High;
				} else {
					NextState = DbExpectHigh;
					CurrentSwitchReading = Low;
				}
			} else {
				NextState = DbValidateLow;
				CurrentSwitchReading = Low;
			}
		break;
		default: NextState = DbExpectHigh;
	}

	// Perform the output function(s) based on the inputs and current state.
	//currently this is handled by the rotary encoder state machine
	if (CurrentSwitchReading == High) /*Do something*/;
	else /*Do something*/;

	// Finally, update the current state with the next state.
	Switch->CurrentState = NextState;

	return CurrentSwitchReading;
}
