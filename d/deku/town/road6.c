#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^");
    set_long(
"%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^WHITE%^
%^ORANGE%^This is the main street through the town of Verbobone. Buildings seem to line the street eastward and westward. Most of the buildings along the street are constructed of wood with t%^RED%^h%^ORANGE%^a%^RED%^t%^ORANGE%^c%^RED%^h%^ORANGE%^e%^RED%^d %^ORANGE%^r%^RED%^o%^ORANGE%^o%^RED%^f%^ORANGE%^s and %^WHITE%^white washed %^ORANGE%^or %^WHITE%^s%^ORANGE%^t%^WHITE%^ucco%^ORANGE%^ed w%^WHITE%^al%^ORANGE%^ls.%^WHITE%^

%^ORANGE%^To the south a sign over the door reads: %^BOLD%^Wheelwright Shop%^RESET%^
%^ORANGE%^To the north a sign over the door reads: %^BOLD%^%^BOLD%^%^MAGENTA%^T%^RESET%^%^MAGENTA%^he %^BOLD%^V%^RESET%^%^MAGENTA%^erre %^BOLD%^B%^RESET%^%^MAGENTA%^ar%^RESET%^
"
    );
    set_exits(([
       "west" : "/d/deku/town/road5",
        "north" : "/d/deku/town/water",
       "south" : "/d/deku/town/wheel",
       "east" : "/d/deku/town/road7"
    ] ));
    set_items(([
    ] ));
}
