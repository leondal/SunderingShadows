//meadowedge7
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadowedge.c";

void create(){
::create();
set_exits(([
"south":INRMS+"meadow1",
"southeast":INRMS+"meadowedge6",
"southwest":INRMS+"meadowedge8"
]));
}