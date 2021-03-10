//forest17
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest16",
"east":INRMS+"forest18"
]));
}