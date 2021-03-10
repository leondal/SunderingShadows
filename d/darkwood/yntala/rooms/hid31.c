//hid31
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"east":INRMS+"hid32",
"southeast":INRMS+"hid30"
]));
}