//hid32
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"west":INRMS+"hid31",
"east":INRMS+"hid33"
]));
}