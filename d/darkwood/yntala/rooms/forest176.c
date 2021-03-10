//forest176
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"south":INRMS+"forest164",
"north":INRMS+"forest175"
]));
}