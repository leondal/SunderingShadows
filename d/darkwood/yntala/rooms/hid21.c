//hid21
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"southwest":INRMS+"hid401",
"north":INRMS+"hid20",
]));
}