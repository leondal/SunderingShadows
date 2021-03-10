//hid4
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"east":INRMS+"hid3",
"north":INRMS+"hid5",
"south":INRMS+"hid6",
]));
}