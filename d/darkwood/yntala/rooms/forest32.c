//forest32
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest3.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"forest33",
"south":INRMS+"forest31"
]));
}