//forest230
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest231",
"south":INRMS+"forest29"
]));
}