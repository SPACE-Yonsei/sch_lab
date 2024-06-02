/*
**
**      GSC-18128-1, "Core Flight Executive Version 6.6"
**
**      Copyright (c) 2006-2019 United States Government as represented by
**      the Administrator of the National Aeronautics and Space Administration.
**      All Rights Reserved.
**
**      Licensed under the Apache License, Version 2.0 (the "License");
**      you may not use this file except in compliance with the License.
**      You may obtain a copy of the License at
**
**        http://www.apache.org/licenses/LICENSE-2.0
**
**      Unless required by applicable law or agreed to in writing, software
**      distributed under the License is distributed on an "AS IS" BASIS,
**      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**      See the License for the specific language governing permissions and
**      limitations under the License.
**
*/

#include "cfe_tbl_filedef.h" /* Required to obtain the CFE_TBL_FILEDEF macro definition */
#include "sch_lab_table.h"
#include "cfe_sb.h" /* Required to use the CFE_SB_MSGID_WRAP_VALUE macro */

/*
** Include headers for message IDs here
*/
#include "ci_lab_msgids.h"
#include "to_lab_msgids.h"

#include "sample_app_msgids.h"
#include "hk_msgids.h"

#if 0
#include "sc_msgids.h"
#include "hs_msgids.h"
#include "fm_msgids.h"
#include "ds_msgids.h"
#include "lc_msgids.h"
#endif

/*
    User Defined MID headers
*/

#include "as_app_msgids.h"
#include "ci_lab_msgids.h"
#include "control_app_msgids.h"
#include "ds_msgids.h"
#include "gps_app_msgids.h"
#include "imu_app_msgids.h"
#include "logic_app_msgids.h"
#include "sim_app_msgids.h"
#include "to_lab_msgids.h"
#include "vol_app_msgids.h"


/*
** SCH Lab schedule table
** When populating this table:
**  1. The entire table is processed (SCH_LAB_MAX_SCHEDULE_ENTRIES) but entries with a
**     packet rate of 0 are skipped
**  2. You can have commented out entries or entries with a packet rate of 0
**  3. If the table grows too big, increase SCH_LAB_MAX_SCHEDULE_ENTRIES
*/

SCH_LAB_ScheduleTable_t SCH_TBL_Structure = {.Config = {
                                                 {CFE_SB_MSGID_WRAP_VALUE(CFE_ES_SEND_HK_MID), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(CFE_EVS_SEND_HK_MID), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(CFE_TIME_SEND_HK_MID), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(CFE_SB_SEND_HK_MID), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(CFE_TBL_SEND_HK_MID), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(CI_LAB_MID_HOUSEKEEPING_REQ), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(TO_LAB_MID_GROUNDCMD_REQ), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(SAMPLE_APP_MID_HOUSEKEEPING_REQ), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(HK_MID_HOUSEKEEPING_REQ), 4, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(HK_MID_SENDCOMBINEDPKT_REQ), 4, 0},
                                                 
                                                 //User Defined HK MID GOES HERE
                                                 {CFE_SB_MSGID_WRAP_VALUE(AS_APP_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(CI_LAB_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(CONTROL_APP_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(DS_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(GPS_APP_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(IMU_APP_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(LOGIC_APP_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(SIM_APP_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(TO_LAB_MID_HOUSEKEEPING_REQ), 1, 0},
                                                 {CFE_SB_MSGID_WRAP_VALUE(VOL_APP_MID_HOUSEKEEPING_REQ), 1, 0},

                                                 //User Defined Data Request MID GOES HERE
                                                {CFE_SB_MSGID_WRAP_VALUE(GPS_APP_MID_GPS_DATA_REQ), 1, 0},
                                                {CFE_SB_MSGID_WRAP_VALUE(AS_APP_MID_AS_DATA_REQ), 1, 0},
                                                {CFE_SB_MSGID_WRAP_VALUE(IMU_APP_MID_IMU_DATA_REQ), 1, 0}, 
                                                {CFE_SB_MSGID_WRAP_VALUE(VOL_APP_MID_VOL_DATA_REQ), 1, 0},
                                                {CFE_SB_MSGID_WRAP_VALUE(LOGIC_APP_MID_OP_DATA_REQ), 1, 0},
                                                {CFE_SB_MSGID_WRAP_VALUE(CI_LAB_MID_ECHO_DATA_REQ), 1, 0},

                                                // Housekeeping Request GOES HERE
                                                {CFE_SB_MSGID_WRAP_VALUE(HK_MID_SENDCOMBINEDPKT_REQ), 1, 0}


                                                
#if 0
                {CFE_SB_MSGID_WRAP_VALUE(SC_SEND_HK_MID),       4, 0},
                {CFE_SB_MSGID_WRAP_VALUE(SC_1HZ_WAKEUP_MID),    1, 0},  /* Example of a 1hz packet */
                {CFE_SB_MSGID_WRAP_VALUE(HS_SEND_HK_MID),       0, 0},  /* Example of a message that wouldn't be sent */
                {CFE_SB_MSGID_WRAP_VALUE(FM_SEND_HK_MID),       4, 0},
                {CFE_SB_MSGID_WRAP_VALUE(DS_MID_HOUSEKEEPING_REQ),       4, 0},
                {CFE_SB_MSGID_WRAP_VALUE(LC_SEND_HK_MID),       4, 0},
#endif
                                             }};

/*
** The macro below identifies:
**    1) the data structure type to use as the table image format
**    2) the name of the table to be placed into the cFE Table File Header
**    3) a brief description of the contents of the file image
**    4) the desired name of the table image binary file that is cFE compatible
*/
CFE_TBL_FILEDEF(SCH_TBL_Structure, SCH_LAB_APP.SCH_LAB_SchTbl, Schedule Lab MsgID Table, sch_lab_table.tbl)
