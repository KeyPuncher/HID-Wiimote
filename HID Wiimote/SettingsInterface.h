/*

Copyright (C) 2016 Julian L�hr
All rights reserved.

Filename:
	SettingsInterface.h

Abstract:
	Shared types and values for the Settings Device Interface, provided by the driver and used by the user mode dll.

*/
#pragma once

#include "WiimotePublic.h"

#include <initguid.h>

// {8259315A-7B87-4D02-83A3-20CBCDAD7647}
DEFINE_GUID(GUID_DEVINTERFACE_HIDWIIMOTE,
	0x8259315a, 0x7b87, 0x4d02, 0x83, 0xa3, 0x20, 0xcb, 0xcd, 0xad, 0x76, 0x47);

typedef struct _WIIMOTE_STATUS_IOCTL_DATA
{
	UCHAR LEDs;
	UCHAR BatteryLevel;
	WIIMOTE_EXTENSION Extension;

} WIIMOTE_STATUS_IOCTL_DATA, * PWIIMOTE_STATUS_IOCTL_DATA;

typedef struct _WIIMOTE_STATE_IOCTL_DATA
{
	WIIMOTE_DRIVER_MODE Mode;
	WIIMOTE_SETTINGS Settings;
	WIIMOTE_STATUS_IOCTL_DATA Status;

} WIIMOTE_STATE_IOCTL_DATA, *PWIIMOTE_STATE_IOCTL_DATA;

#define CUSTOM_FUNCTION_CODE(id) (0x800 | id)

#define HID_WIIMOTE_CTL_CODE(id)			CTL_CODE(FILE_DEVICE_KEYBOARD, CUSTOM_FUNCTION_CODE(id), METHOD_NEITHER, FILE_ANY_ACCESS)
#define HID_WIIMOTE_BUFFERED_CTL_CODE(id)	CTL_CODE(FILE_DEVICE_KEYBOARD, CUSTOM_FUNCTION_CODE(id), METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_WIIMOTE_GET_STATE				HID_WIIMOTE_BUFFERED_CTL_CODE(0x01)
#define IOCTL_WIIMOTE_READ_STATUS			HID_WIIMOTE_BUFFERED_CTL_CODE(0x02)

#define IOCTL_WIIMOTE_SET_MODE				HID_WIIMOTE_BUFFERED_CTL_CODE(0x10)
#define IOCTL_WIIMOTE_SET_XAXIS				HID_WIIMOTE_BUFFERED_CTL_CODE(0x11)
#define IOCTL_WIIMOTE_SET_YAXIS				HID_WIIMOTE_BUFFERED_CTL_CODE(0x12)
#define IOCTL_WIIMOTE_SET_MOUSEBUTTONSWITCHED			HID_WIIMOTE_BUFFERED_CTL_CODE(0x13)
#define IOCTL_WIIMOTE_SET_TRIGGERAMDSHOULDERSWITCHED	HID_WIIMOTE_BUFFERED_CTL_CODE(0x14)
#define IOCTL_WIIMOTE_SET_TRIGGERSPLIT		HID_WIIMOTE_BUFFERED_CTL_CODE(0x15)




