//forest237
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest246",
"northeast":INRMS+"forest238",
"south":INRMS+"forest236"
]));
}