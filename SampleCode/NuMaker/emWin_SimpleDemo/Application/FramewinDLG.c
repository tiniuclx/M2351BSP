/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.46                          *
*        Compiled Dec 12 2017, 16:38:40                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END
#include "stdio.h"
#include "DIALOG.h"

#include "NuMicro.h"
#include "M2351TouchPanel.h"

/* Scheduler include files. */
//#include "FreeRTOS.h"
//#include "task.h"
//#include "semphr.h"

//extern xSemaphoreHandle psGUISemaphore;
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_0  (GUI_ID_USER + 0x05)
#define ID_BUTTON_1  (GUI_ID_USER + 0x06)
#define ID_BUTTON_2  (GUI_ID_USER + 0x07)
#define ID_BUTTON_3  (GUI_ID_USER + 0x08)
#define ID_BUTTON_4  (GUI_ID_USER + 0x09)
#define ID_EDIT_0  (GUI_ID_USER + 0x10)
#define ID_TEXT_0  (GUI_ID_USER + 0x20)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[8] =
{
#ifdef __DEMO_160x128__
    { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 160, 128, 0, 0x0  },
    { BUTTON_CreateIndirect, "+ 1", ID_BUTTON_0, 10, 6, 50, 20, 0, 0x0  },
    { BUTTON_CreateIndirect, "+ 10", ID_BUTTON_1, 10, 32, 50, 20, 0, 0x0 },
    { BUTTON_CreateIndirect, "- 1", ID_BUTTON_2, 10, 58, 50, 20, 0, 0x0 },
    { BUTTON_CreateIndirect, "- 10", ID_BUTTON_3, 10, 84, 50, 20, 0, 0x0 },
    { BUTTON_CreateIndirect, "Calibrate", ID_BUTTON_4, 90, 84, 60, 20, 0, 0x0 },
    { EDIT_CreateIndirect, "Edit", ID_EDIT_0, 80, 26, 60, 20, 0, 0x64 },
    { TEXT_CreateIndirect, "Result :", ID_TEXT_0, 80, 2, 50, 20, 0, 0x0 },
#else
    { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 320, 240, 0, 0x0  },
    { BUTTON_CreateIndirect, "+ 1", ID_BUTTON_0, 43, 38, 80, 20, 0, 0x0  },
    { BUTTON_CreateIndirect, "+ 10", ID_BUTTON_1, 43, 77, 80, 20, 0, 0x0 },
    { BUTTON_CreateIndirect, "- 1", ID_BUTTON_2, 45, 116, 80, 20, 0, 0x0 },
    { BUTTON_CreateIndirect, "- 10", ID_BUTTON_3, 46, 158, 80, 20, 0, 0x0 },
    { BUTTON_CreateIndirect, "Calibrate", ID_BUTTON_4, 204, 158, 80, 20, 0, 0x0 },
    { EDIT_CreateIndirect, "Edit", ID_EDIT_0, 204, 72, 80, 20, 0, 0x64 },
    { TEXT_CreateIndirect, "Result :", ID_TEXT_0, 151, 74, 50, 20, 0, 0x0 },
#endif
    // USER START (Optionally insert additional widgets)
    // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

int value;
char sBuf[20];
WM_HWIN g_hWin;
WM_HWIN CreateFramewin(void);

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    // USER START (Optionally insert additional variables)
    // USER END

    switch(pMsg->MsgId)
    {
        case WM_INIT_DIALOG:
            //
            // Initialization of 'Edit'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
            EDIT_SetText(hItem, "2351");
            value = 2351;
            // USER START (Optionally insert additional code for further widget initialization)
            // USER END
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id)
            {
                case ID_BUTTON_0: // Notifications sent by '+ 1'
                    switch(NCode)
                    {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            value += 1;
                            sprintf(sBuf, "%d    ", value);
                            hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
                            EDIT_SetText(hItem, sBuf);
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                            // USER START (Optionally insert additional code for further notification handling)
                            // USER END
                    }
                    break;
                case ID_BUTTON_1: // Notifications sent by '+ 10'
                    switch(NCode)
                    {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            value += 10;
                            sprintf(sBuf, "%d    ", value);
                            hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
                            EDIT_SetText(hItem, sBuf);
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                            // USER START (Optionally insert additional code for further notification handling)
                            // USER END
                    }
                    break;
                case ID_BUTTON_2: // Notifications sent by '- 1'
                    switch(NCode)
                    {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            value -= 1;
                            sprintf(sBuf, "%d    ", value);
                            hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
                            EDIT_SetText(hItem, sBuf);
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                            // USER START (Optionally insert additional code for further notification handling)
                            // USER END
                    }
                    break;
                case ID_BUTTON_3: // Notifications sent by '- 10'
                    switch(NCode)
                    {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            value -= 10;
                            sprintf(sBuf, "%d    ", value);
                            hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
                            EDIT_SetText(hItem, sBuf);
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                            // USER START (Optionally insert additional code for further notification handling)
                            // USER END
                    }
                    break;
                case ID_BUTTON_4: // Notifications sent by 'Calibrate'
                    switch(NCode)
                    {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            SYS_UnlockReg();
                            FMC_Open();
                            FMC_ENABLE_AP_UPDATE();
                            FMC_Write(__DEMO_TSFILE_ADDR__ + 0x1C, 0x0);
                            SYS_ResetCPU();
                            while(1) {};
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                            // USER START (Optionally insert additional code for further notification handling)
                            // USER END
                    }
                    break;
                case ID_EDIT_0: // Notifications sent by 'Edit'
                    switch(NCode)
                    {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_VALUE_CHANGED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                            // USER START (Optionally insert additional code for further notification handling)
                            // USER END
                    }
                    break;
                    // USER START (Optionally insert additional code for further Ids)
                    // USER END
            }
            break;
        // USER START (Optionally insert additional message handling)
        // USER END
        default:
            WM_DefaultProc(pMsg);
            //  xSemaphoreTake(psGUISemaphore, 10/portTICK_RATE_MS);
            break;
    }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateFramewin
*/
WM_HWIN CreateFramewin(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    g_hWin = hWin;
    return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
