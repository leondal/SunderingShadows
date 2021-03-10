//hid42
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"west":INRMS+"hid29",
"northeast":INRMS+"hid41",
]));
}