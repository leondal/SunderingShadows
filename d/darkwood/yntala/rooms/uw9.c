//uw9
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"bunderwater.c";

void create(){
::create();
set_exits(([
"north":INRMS+"uw8",
"south":INRMS+"uw10"
]));
}