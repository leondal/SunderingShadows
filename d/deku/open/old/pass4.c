#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_short("%^BOLD%^%^BLACK%^Shadowlord forest");
    set_long(
@KAYLA
%^BOLD%^%^BLACK%^To the north gray granite pillars support the overhanging weight of the second level of the triumphal arch, forming an aisle through the musty darkness of the gatehouse.  A large set of iron gates to the north secure the entrances.  The gates hang open and creak loudly as they swing in the wind.
KAYLA
    );
    set_smell("default","The mist carries the smell of death and decay.");
    set_listen("default","You hear sounds of a muffled cry or perhaps just the wind.");
    set_exits(([
       "north" : "/d/deku/fortress/foyer",
       "south" : "/d/deku/open/pass5",
       "west" : "/d/deku/open/road1"
    ] ));
    set_items(([
    ] ));
}
