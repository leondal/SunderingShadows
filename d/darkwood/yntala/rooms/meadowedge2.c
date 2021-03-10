//meadowedge2
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadowedge.c";

void create(){
::create();
set_exits(([
"north":INRMS+"meadow4",
"east":INRMS+"meadow3",
"southeast":INRMS+"meadowedge3",
"northwest":INRMS+"meadowedge1"
]));
}