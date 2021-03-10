//forest177
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest170",
"south":INRMS+"forest178"
]));
}