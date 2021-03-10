//Main Deku Header
//All future areas on deku will
//use the directory /d/deku/monster for monsters
///d/deku/weapons for weapons
///d/deku/armours for armours
//and /d/deku/misc for misc stuff - Saide 3/09
#include "deku.h"

#define DEKU_WEP "/d/deku/weapons/"+
#define DEKU_ARM "/d/deku/armours/"+
#define DEKU_MON "/d/deku/monster/"+
#define DEKU_MISC "/d/deku/misc/"+

#define F_ROOMS "/d/deku/forest/dforest"+
#define FTRAIL "/d/deku/inherits/foresttraili"
//#define MAIN_TRAIL "/d/deku/inherits/foresttraili"
#define NFTRAIL "/d/deku/inherits/nblocki"
#define WFTRAIL "/d/deku/inherits/wblocki"
#define EFTRAIL "/d/deku/inherits/eblocki"
#define SFTRAIL "/d/deku/inherits/sblocki"
#define SHORETRAIL "/d/deku/inherits/shoreblocki"
#define LAKEBANK "/d/deku/inherits/lakebanki"
#define NTFTRAIL "/d/deku/inherits/ntblocki"
#define STFTRAIL "/d/deku/inherits/stblocki"
#define ETFTRAIL "/d/deku/inherits/etblocki"
#define WTFTRAIL "/d/deku/inherits/wtblocki"
#define RIVERBANK "/d/deku/inherits/riverbanki"
#define FTUNNEL "/d/deku/inherits/foresttuni"
#define FPLAINS "/d/deku/inherits/foresttoplainsi"
#define P_ROOMS "/d/deku/plains/"+
#define CAT_ROOMS "/d/deku/catacombs/"+

//Tunnel of Flames Stuff

#define FIRE_TUNI "/d/deku/inherits/flametunneli"
#define FTUN_ROOMS "/d/deku/forest/fire_tunnel/rooms/"+
#define FIRE_TEMPI "/d/deku/inherits/flametemplei"

//Catacombs of the Dead Stuff

#define CAT_HW_F "/d/deku/inherits/catacombs_hallw_1i"
#define CAT_HW_S "/d/deku/inherits/catacombs_hallw_2i"
#define CAT_HW_T "/d/deku/inherits/catacombs_hallw_3i"
#define CAT_HW_FO "/d/deku/inherits/catacombs_hallw_4i"
#define CAT_ROOM_ONE_F "/d/deku/inherits/cat_first_room_i"
#define CAT_SR_ONE "/d/deku/inherits/cat_first_sr_i"

#define SD "/d/common/daemon/randstuff_d"
#define FENC "/d/deku/inherits/forest_encounters_d.c"
#define TRCALC "/d/deku/inherits/area_treasure_d.c"

#define CAMPS "deku_bandit_camps"
#define INV_C_ROOMS ({FTUNNEL,FTRAIL,NFTRAIL,EFTRAIL,SFTRAIL,\
SHORETRAIL,LAKEBANK,NTFTRAIL,STFTRAIL,ETFTRAIL,WTFTRAIL,\
RIVERBANK,FTUNNEL})
#define INV_ROOMS ({"2-5","3-4","4-3","5-3","6-3",\
"6-3","7-3","8-3","8-4","8-5","8-6","8-7","8-8","8-9",\
"9-4","10-4","11-1","11-2","11-3","11-5","12-5","13-5",\
"14-5","15-5","21-2","23-5","24-4","25-3","26-3","27-3",\
"28-4","28-5","27-6","27-7","27-8","29-5","33-5","34-5",\
"35-4","36-3","36-2","35-1","35-15","37-17"})

#define NOGO_ROOMS (({"/d/deku/forest/dforest11-al1",\
"/d/deku/forest/forest3","/d/deku/forest/forest2i",\
"/d/deku/forest/forest1","/d/deku/forest/dforest11-al2",\
"/d/deku/forest/dforest11-al2a"}))

#define SAFE_NAMES (({"hag","abomination"}))
#define DOOMED_ROOMS (({"37-15","37-16","37-17","37-18","37-19",\
"37-20","37-21","37-22","36-14","36-15","36-16","35-13","35-14",\
"35-16","34-12","34-13","34-14","34-15","34-16","33-12","33-13",\
"33-14","33-15","33-16","32-12","32-13","32-14","32-15","32-16"}))
