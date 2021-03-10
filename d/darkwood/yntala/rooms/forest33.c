//forest33
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest3.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest179",
"southwest":INRMS+"forest32"
]));
}