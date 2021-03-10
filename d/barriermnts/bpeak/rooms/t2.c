//t2.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"transition";
int searched;

void create(){
::create();
set_exits(([
"southwest":INRMS+"t3","north":INRMS+"t1","west":"/d/player_houses/kiya/rooms/path4"
]));
set_invis_exits(({"west"}));

set_search("rocks","%^BOLD%^%^BLACK%^With a closer examination of the rocks lining the path, you notice a %^YELLOW%^concealed%^BOLD%^%^BLACK%^ trail amongst them leading to the west.");
}
