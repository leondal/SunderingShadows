//forest123
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest130",
"north":INRMS+"forest122",
"southeast":INRMS+"forest124"
]));
}