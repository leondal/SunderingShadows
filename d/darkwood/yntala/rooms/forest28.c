//forest28
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest27",
"east":INRMS+"forest29",
"south":INRMS+"forest232"
]));
}