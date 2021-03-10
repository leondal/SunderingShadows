//forest142
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest143",
"west":INRMS+"forest141"
]));
}