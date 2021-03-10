//meadowedge3
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadowedge.c";

void create(){
::create();
set_exits(([
"north":INRMS+"meadow3",
"northeast":INRMS+"meadowedge4",
"northwest":INRMS+"meadowedge2"
]));
}