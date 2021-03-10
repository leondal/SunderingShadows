//uw11
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"north":INRMS+"uw5",
"west":INRMS+"uw12"
]));
}