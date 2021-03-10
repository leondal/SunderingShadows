//hid34
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid33",
"southeast":INRMS+"hid35",
"southwest":INRMS+"hid39",
]));
}