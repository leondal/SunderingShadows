//hid9
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid8",
"west":INRMS+"hid10"
]));
}