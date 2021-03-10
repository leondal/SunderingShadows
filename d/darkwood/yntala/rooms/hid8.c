//hid8
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"west":INRMS+"hid7",
"south":INRMS+"hid9"
]));
}