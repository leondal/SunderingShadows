//forest139
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest138",
"south":INRMS+"forest13"
]));
}