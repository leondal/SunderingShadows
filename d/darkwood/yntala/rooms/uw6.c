//uw6
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"west":INRMS+"uw5",
"down":INRMS+"uw7"
]));
}