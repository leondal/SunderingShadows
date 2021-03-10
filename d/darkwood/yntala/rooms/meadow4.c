//meadow4
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadow.c";

void create(){
::create();
set_exits(([
"north":INRMS+"meadowedge8",
"south":INRMS+"meadowedge2",
"east":INRMS+"centermed",
"west":INRMS+"meadowedge1",
"northeast":INRMS+"meadow1",
"southeast":INRMS+"meadow3"
]));
}