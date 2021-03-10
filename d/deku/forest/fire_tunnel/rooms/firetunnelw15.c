#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  There is an "+
    "%^BLUE%^opening%^RESET%^%^RED%^ in the barrier "+
    "to the west.  The tunnel of flames "+
    "continues east here.%^RESET%^");
    add_item("opening","%^BLUE%^This is a small opening "+
    "in the barrier surrounding the flames directly west of here.  "+
    "You could try to %^RED%^enter%^RESET%^%^BLUE%^ it, if you "+
    "were brave enough.%^RESET%^");
    set_exits(([
        "east" : FTUN_ROOMS"firetunnelw14"
    ] ));
}


void init() {
    ::init();
    add_action("enter","enter");
}

void enter(string str) {
    if(str == "opening") {
        tell_object(TP,"%^BLUE%^You run forward and jump "+
        "through the opening!%^RESET%^");
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+"%^BLUE%^ runs forward "+
            "and jumps through the opening in the barrier!"+
            "%^RESET%^",TP);
        }
        TP->move_player(FTUN_ROOMS"firetunnelw16");
        tell_room(ETP,TPQCN+"%^RED%^ bursts through the wall "+
        "of fire, but somehow unscathed.%^RESET%^",TP);
        return 1;
    }
    return 0;
}
