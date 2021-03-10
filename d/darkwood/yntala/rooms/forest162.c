//forest162
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"forest169",
"northwest":INRMS+"forest163",
"south":INRMS+"forest155"
]));
}