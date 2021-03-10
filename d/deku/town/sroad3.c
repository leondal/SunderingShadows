#include <std.h>
inherit "/d/deku/inherits/sroadi";

void create() {
    ::create();
    set_long(TO->query_long()+" The road meets the south gates here.The forest sprawls out around the city to the south.");
    set_exits(([
       "south" : "/d/deku/forest/dforest21-2",
       "north" : "/d/deku/town/sroad2",
    ] ));
    set_door("wooden gates","/d/deku/town/sroad2", "north");
	set_string("wooden gates", "open","%^MAGENTA%^The gates swing "+
    "slowly open.%^RESET%^");
	set_locked("wooden gates",0);
    set_open("wooden gates",1);
	set_door_description("wooden gates","%^MAGENTA%^These wooden "+
    "gates are made from several slabs of %^BOLD%^%^GREEN%^oak"+
    "%^MAGENTA%^ that have been tightly bound together with a thick "+
    "and course rope.%^RESET%^");
    if(!present("guard")) {
        new("/d/deku/monster/gguard")->move(TO);
        new("/d/deku/monster/gguard")->move(TO);
    }
}

void reset() {
    ::reset();
    if(!present("guard")) {
        new("/d/deku/monster/gguard")->move(TO);
        new("/d/deku/monster/gguard")->move(TO);
    }
}
