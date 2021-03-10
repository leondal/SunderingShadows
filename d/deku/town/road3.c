#include <std.h>
inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^ORANGE%^");
    set_long(
        "%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^ORANGE%^
This is the main street through the town of Verbobone. Buildings seem to line the street eastward. Towards the west, past the open gates you can see the dark, shadowy forest. Most of the buildings are constructed of wo%^GREEN%^od %^ORANGE%^with t%^RED%^h%^ORANGE%^a%^RED%^t%^ORANGE%^c%^RED%^h%^ORANGE%^e%^RED%^d %^ORANGE%^r%^RED%^o%^ORANGE%^o%^RED%^f%^ORANGE%^s and %^WHITE%^white washed %^ORANGE%^or s%^WHITE%^t%^ORANGE%^u%^WHITE%^c%^ORANGE%^c%^WHITE%^o%^ORANGE%^e%^WHITE%^d %^ORANGE%^w%^WHITE%^al%^ORANGE%^l%^WHITE%^s%^ORANGE%^.. A recently patched together %^WHITE%^road turns to the south%^ORANGE%^ here.

To the north a sign over the door reads: %^GREEN%^General Store%^RESET%^
"
        );
    set_exits(([
       "west" : "/d/deku/town/road2",
       "north" : "/d/deku/town/general",
       "east" : "/d/deku/town/road4",
       "south" : "/d/deku/town/sroad1",
    ] ));
    set_door("wooden gates","/d/deku/town/road2", "west");
	set_string("wooden gates", "open","%^MAGENTA%^The gates swing "+
    "slowly open.%^RESET%^");
	set_locked("wooden gates",0);
    set_open("wooden gates",1);
	set_door_description("wooden gates","%^MAGENTA%^These wooden "+
    "gates are made from several slabs of %^BOLD%^%^GREEN%^oak"+
    "%^MAGENTA%^ that have been tightly bound together with a thick "+
    "and course rope.%^RESET%^");
    set_items(([
    ] ));
}
