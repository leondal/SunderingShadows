//forest150
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest141",
"northwest":INRMS+"forest151",
"southwest":INRMS+"forest179"
]));
}