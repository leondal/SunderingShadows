//frpath4
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fredge.c";

void create(){
::create();
set_exits(([
"north":INRMS+"frpath3",
"south":INRMS+"frpath5",
]));
}