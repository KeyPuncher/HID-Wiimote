/*

Copyright (C) 2017 Julian L�hr
All rights reserved.

Filename:
	State.h

Abstract:
	Public managed class that represents the current state of a Wiimote Device including its settings.

*/
#pragma once

#include "Status.h"

#include "../HID Wiimote/DeviceInterfacePublic.h"

namespace HIDWiimote
{
	namespace UserModeLib
	{
		public enum class DriverMode { Gamepad, PassThrough,  IRMouse, DPadMouse, GamepadAndIRMouse };

		public ref class State
		{
		public:
			State();
			State(const WIIMOTE_STATE_IOCTL_DATA & StateData);

			property DriverMode Mode;
			property Status^ Status;
			property System::Boolean EnableWiimoteXAxisAccelerometer;
			property System::Boolean EnableWiimoteYAxisAccelerometer;
			property System::Boolean SwapMouseButtons;
			property System::Boolean SwapTriggerAndShoulder;
			property System::Boolean SplitTrigger;
			property System::Boolean MapTriggerAsAxis;
			property System::Boolean MapTriggerAsButtons;
		};
	}
}

