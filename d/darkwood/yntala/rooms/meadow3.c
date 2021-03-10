//meadow3
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadow.c";

void create(){
::create();
set_exits(([
"north":INRMS+"centermed",
"south":INRMS+"meadowedge3",
"east":INRMS+"meadowedge4",
"west":INRMS+"meadowedge2",
"northwest":INRMS+"meadow4",
"northeast":INRMS+"meadow2"
]));
}