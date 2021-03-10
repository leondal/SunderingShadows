#include "../tomb.h"

inherit TOMBSTR;

void create(){
    ::create();
    set_long(::query_long()+"
%^BOLD%^%^MAGENTA%^One of the signs on the northern wall says 'Spellwarden'.
%^BOLD%^%^CYAN%^Huge door on the southern wall says 'Marble Laboratory'.
");
    set_exits(([
                   "north":ROOMS+"/spellwarden",
                   "south":ROOMS+"/mage_lab",
                   "east":ROOMS+"/fountain2",
                   ]));

    set_heart_beat(0);
}
