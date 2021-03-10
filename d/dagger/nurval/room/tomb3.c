#include "../tomb.h"

inherit TOMBSTR;

void create(){
    ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLUE%^A sign in the southern wall says 'Shrine of Nilith'.
");
    set_exits(([
                   "south":ROOMS+"/shrine",
                   "west":ROOMS+"/fountain",
                   "east":ROOMS+"/village",
                   ]));
    set_heart_beat(0);
}
