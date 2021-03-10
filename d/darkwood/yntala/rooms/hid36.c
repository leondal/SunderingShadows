//hid36
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"hid33",
"northwest":INRMS+"hid37"
]));
}