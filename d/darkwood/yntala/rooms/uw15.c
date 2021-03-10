//uw15
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"down":INRMS+"uw16",
"east":INRMS+"uw14",
"north":INRMS+"uw24"
]));
}