//fpath45
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"north":INRMS+"fpath44",
]));
}