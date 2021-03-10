//forest141
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest142",
"north":INRMS+"forest140",
"west":INRMS+"forest150"
]));
}