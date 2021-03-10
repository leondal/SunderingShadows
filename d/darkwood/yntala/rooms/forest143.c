//forest143
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"forest144",
"west":INRMS+"forest142"
]));
}