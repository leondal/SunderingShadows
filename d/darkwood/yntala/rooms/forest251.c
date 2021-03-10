//forest251
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest250",
"south":INRMS+"forest252"
]));
}