//frpath1
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fredge.c";

void create(){
::create();
set_exits(([
"east":"/d/barriermnts/bpeak/rooms/bpath2",
"southwest":INRMS+"frpath2",
]));
}