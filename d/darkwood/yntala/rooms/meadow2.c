//meadow2
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadow.c";

void create(){
::create();
set_exits(([
"north":INRMS+"meadowedge6",
"south":INRMS+"meadowedge4",
"east":INRMS+"meadowedge5",
"west":INRMS+"centermed",
"northwest":INRMS+"meadow1",
"southwest":INRMS+"meadow3"
]));
}