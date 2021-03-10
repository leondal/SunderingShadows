//hid29
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"hid26",
"south":INRMS+"hid43",
"east":INRMS+"hid42",
]));
}