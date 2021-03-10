//uw5
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"west":INRMS+"uw4",
"east":INRMS+"uw6",
"south":INRMS+"uw11"
]));
}