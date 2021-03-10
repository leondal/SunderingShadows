//uw3
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_air_pocket(4);
set_exits(([
"west":INRMS+"uw2",
"east":INRMS+"uw4"
]));
}
