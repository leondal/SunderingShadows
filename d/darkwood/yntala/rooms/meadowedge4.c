//meadowedge4
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadowedge.c";

void create(){
::create();
set_exits(([
"north":INRMS+"meadow2",
"west":INRMS+"meadow3",
"northeast":INRMS+"meadowedge5",
"northwest":INRMS+"centermed",
"southwest":INRMS+"meadowedge3"
]));
}