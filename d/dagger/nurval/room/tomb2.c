#include "../tomb.h"

inherit TOMBSTR;

void create(){
    ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLUE%^A sign in the eastern wall says 'Trading Company'.
");
    set_exits(([
                   "north":ROOMS+"/necro34",
                   "south":ROOMS+"/fountain",
                   "east":ROOMS+"/trader",
                   ]));
    set_heart_beat(0);
}
