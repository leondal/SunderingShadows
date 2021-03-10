//meadowedge1
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadowedge.c";

void create(){
::create();
set_exits(([
"east":INRMS+"meadow4",
"west":INRMS+"thornroom",
"northeast":INRMS+"meadowedge8",
"southeast":INRMS+"meadowedge2"
]));
}