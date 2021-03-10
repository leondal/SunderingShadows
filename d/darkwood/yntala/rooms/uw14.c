//uw14
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"west":INRMS+"uw15",
"east":INRMS+"uw13"
]));
}