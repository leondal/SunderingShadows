//forest126
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest125",
"east":INRMS+"forest127"
]));
}