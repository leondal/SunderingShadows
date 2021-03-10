//forest246
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest245",
"west":INRMS+"forest247",
"southeast":INRMS+"forest237"
]));
}