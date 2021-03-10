//forest153
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest161",
"northeast":INRMS+"forest154",
"southeast":INRMS+"forest152"
]));
}