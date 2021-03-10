//forest134
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"southwest":INRMS+"forest133",
"northeast":INRMS+"forest135",
"northwest":INRMS+"forest178"
]));
}