//meadowedge5
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadowedge.c";

void create(){
::create();
set_exits(([
"west":INRMS+"meadow2",
"northwest":INRMS+"meadowedge6",
"southwest":INRMS+"meadowedge4"
]));
}