//hid43
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid29",
"southeast":INRMS+"hid44",
]));
}