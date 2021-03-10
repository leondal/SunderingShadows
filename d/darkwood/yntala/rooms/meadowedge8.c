//meadowedge8
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadowedge.c";

void create(){
::create();
set_exits(([
"south":INRMS+"meadow4",
"east":INRMS+"meadow1",
"northeast":INRMS+"meadowedge7",
"southeast":INRMS+"centermed",
"southwest":INRMS+"meadowedge1"
]));
}