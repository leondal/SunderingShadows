//forest135
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"southwest":INRMS+"forest134",
"east":INRMS+"forest136"
]));
}