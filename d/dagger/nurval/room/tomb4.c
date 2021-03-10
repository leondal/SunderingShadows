#include "../tomb.h"

inherit TOMBSTR;

void create(){
    ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLUE%^Northern gates out of the pyramid are closed.
");
    set_exits(([
                   "north":ROOMS+"/fountain",
                   ]));
    set_heart_beat(0);
}
