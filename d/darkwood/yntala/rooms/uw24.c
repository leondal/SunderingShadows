//uw24
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"north":INRMS+"uw25",
"south":INRMS+"uw15"
]));
}