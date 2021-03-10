#include <std.h>

//definitions for directory variables
#define KEEPR  "/d/deku/keep/rooms/"
#define KEEPM  "/d/deku/keep/monster/"
#define KEEPO  "/d/deku/keep/obj/"
#define KEEPP  "/d/deku/keep/potion/"
#define STAIRWELL "/d/deku/keep/stairwell"
#define DUNGEON "/d/deku/keep/dungeon"
#define JAIL "/d/deku/keep/jail"
#define CELL "/d/deku/keep/cell"
#define TUNNEL "/d/deku/keep/tunnel"
#define TUNNELU "/d/deku/keep/tunnelui"
#define TUNNELUW "/d/deku/keep/tunnel_water"
#define TUNNELBUR "/d/deku/keep/burial_chamberi"
#define MOB_TREASURE "/d/deku/keep/monster/treasure"
#define KEEP_ENCOUNTERS_D "/d/deku/keep/keep_encounters_d"
#define WEREWOLF "/d/deku/keep/monster/werewolfi"
#define GUARD "/d/deku/keep/monster/guard"
#define TOWERI1 "/d/deku/keep/towerI1"
#define TOWERI2 "/d/deku/keep/towerI2"
#define UB "/d/deku/keep/barrack_upI"
#define BB "/d/deku/keep/barrackI"
#define KEEP "/d/deku/keep/keep"
#define HTOWER "/d/deku/keep/htowerI"


//Defines for mobs - rooms they should NOT enter//
#define NO "/d/deku/keep/rooms/towerNW2"
#define NO2 "/d/deku/keep/rooms/towerN2"
#define NO3 "/d/deku/keep/rooms/towerNE2"
#define NO4 "/d/deku/keep/rooms/towerE2"
#define NO5 "/d/deku/keep/rooms/towerSE2"
#define NO6 "/d/deku/keep/rooms/towerSW2"
#define NO7 "/d/deku/keep/rooms/towerW2"
#define NO8 "/d/deku/keep/rooms/telair1"
#define NO9 "/d/deku/keep/rooms/blacktonguelair11"
#define NO10 "/d/deku/keep/rooms/jail1"
#define NO11 "/d/deku/keep/rooms/spectre1"
#define NO12 "/d/deku/keep/rooms/siere1"
#define NO13 "/d/deku/keep/rooms/shaltul1"
#define NO14 "/d/deku/keep/rooms/tunnel1"

//misc area definitions - Saide

#define M_DOOR "%^BOLD%^%^BLACK%^This door is made from a heavy metal, it has a barred window near the top of it.  You could easily peer through the bars to see what's behind it.%^RESET%^"
#define I_DOOR "%^BOLD%^%^WHITE%^This door is made from a heavy iron, it has a barred window near the top of it.  You could easily peer through the bars to see what's behind it.%^RESET%^"
#define RD_DESC "%^RED%^This door is roughly 3' square and made from a solid metal that has rusted over the course of time.%^RESET%^"
#define RD_OPEN_DESC "%^RED%^The door opens with a %^BLUE%^LOUD%^RESET%^%^RED%^ shriek!%^RESET%^"
#define LITEMS ({"hieroglyphic symbols","symbols","hieroglyphics","hieroglyphic"})
#define RA "deku_werewolf_lair_gnome_remains"
#define BPA "deku_werewolf_lair_bone_parchment"

//Keep Daemons

#define SEARCH_D "/d/deku/keep/searches.c"
#define MOB_TR_D "/d/deku/keep/treasure.c"