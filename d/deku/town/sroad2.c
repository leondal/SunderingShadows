#include <std.h>
inherit "/d/deku/inherits/sroadi";

void create() {
    ::create();
    set_long(TO->query_long()+" %^GREEN%^The road meets the south gates here or turns northwest, heading back to the north part of town.

To the west a sign over the door reads: %^ORANGE%^Verbobone Stables%^RESET%^");
    set_exits(([
       "south" : "/d/deku/town/sroad3",
       "northwest" : "/d/deku/town/sroad1",
       "west" : "/d/deku/town/stables",
       "north" : "/d/deku/town/portal",
    ] ));
    set_door("wooden gates","/d/deku/town/sroad3", "south");
	set_string("wooden gates", "open","%^MAGENTA%^The gates swing "+
    "slowly open.%^RESET%^");
	set_locked("wooden gates",0);
    set_open("wooden gates",1);
	set_door_description("wooden gates","%^MAGENTA%^These wooden "+
    "gates are made from several slabs of %^BOLD%^%^GREEN%^oak"+
    "%^MAGENTA%^ that have been tightly bound together with a thick "+
    "and course rope.%^RESET%^");
}
