//scave3
#include <std.h>;
#include "../yntala.h"
inherit INRMS+"scave2.c";

void create(){
::create();
set_exits(([
"south":INRMS+"scave2",
"north":INRMS+"scave4",
]));
}