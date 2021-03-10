//uw13
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"west":INRMS+"uw14",
"down":INRMS+"uw22",
"east":INRMS+"uw12"
]));
}