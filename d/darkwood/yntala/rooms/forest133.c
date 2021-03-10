//forest133
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"southwest":INRMS+"forest132",
"northeast":INRMS+"forest134"
]));
}