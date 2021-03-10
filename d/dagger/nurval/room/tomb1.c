#include "../tomb.h"

inherit TOMBSTR;

void create(){
    ::create();
    set_long(::query_long()+"
%^BOLD%^%^MAGENTA%^One of the signs on the northern wall says 'Healer'.
%^BOLD%^%^CYAN%^Huge door on the southern wall says 'Bank'.
");
    set_exits(([
                   "north":ROOMS+"/healer",
                   "west":ROOMS+"/necro20",
                   "south":ROOMS+"/bank",
                   "east":ROOMS+"/fountain",
                   ]));
    set_heart_beat(0);
}
