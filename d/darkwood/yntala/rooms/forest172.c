//forest172
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest173",
"east":INRMS+"forest171"
]));
}