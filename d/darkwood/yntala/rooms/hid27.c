//hid27
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"hid26",
"southwest":INRMS+"hid28",
]));
}