//river2
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"river.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest250"
]));
}