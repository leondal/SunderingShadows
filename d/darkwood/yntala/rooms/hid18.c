//hid18
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"east":INRMS+"hid19",
"north":INRMS+"hid17",
]));
}