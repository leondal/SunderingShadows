//forest169
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"forest170",
"southwest":INRMS+"forest162"
]));
}