//forest11
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"east":INRMS+"river4",
"west":INRMS+"forest12"
]));
}