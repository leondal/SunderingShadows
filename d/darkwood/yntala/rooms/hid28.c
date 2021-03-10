//hid28
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"hid27",
"southeast":INRMS+"hid29",
]));
}