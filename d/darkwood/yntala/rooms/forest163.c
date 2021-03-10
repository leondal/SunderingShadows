//forest163
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest164",
"southeast":INRMS+"forest162"
]));
}