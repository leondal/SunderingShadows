//forest159
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest158",
"south":INRMS+"forest160"
]));
}