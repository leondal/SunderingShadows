//hid39
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"hid34",
"south":INRMS+"hid40"
]));
}