//hid41
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"southwest":INRMS+"hid42",
"east":INRMS+"hid401",
]));
}