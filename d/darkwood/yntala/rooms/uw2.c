//uw2
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"up":INRMS+"uw1",
"east":INRMS+"uw3"
]));
}