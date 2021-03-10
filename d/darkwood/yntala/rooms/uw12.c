//uw12
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"west":INRMS+"uw13",
"east":INRMS+"uw11"
]));
}