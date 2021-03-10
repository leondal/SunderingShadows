//uw2
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"north":INRMS+"uw23",
"south":INRMS+"hid2",
]));
}