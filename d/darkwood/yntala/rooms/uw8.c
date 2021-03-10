//uw8
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"bunderwater.c";

void create(){
::create();
set_exits(([
"north":INRMS+"uw7",
"south":INRMS+"uw9"
]));
}