//forest148
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"forest149",
"west":INRMS+"forest147"
]));
}