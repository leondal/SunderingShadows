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
%^ORANGE%^This is the main street through the town of Verbobone. Buildings seem to line the street eastward and westward. Most of the buildings along the street are constructed of wo%^GREEN%^od %^ORANGE%^with t%^RED%^h%^ORANGE%^a%^RED%^t%^ORANGE%^c%^RED%^h%^ORANGE%^e%^RED%^d %^ORANGE%^r%^RED%^o%^ORANGE%^o%^RED%^f%^ORANGE%^s and %^WHITE%^white washed %^ORANGE%^or s%^WHITE%^t%^ORANGE%^u%^WHITE%^c%^ORANGE%^c%^WHITE%^o%^ORANGE%^e%^WHITE%^d %^ORANGE%^w%^WHITE%^al%^ORANGE%^l%^WHITE%^s%^ORANGE%^.%^WHITE%^

%^ORANGE%^The sign over the south door reads: %^MAGENTA%^Seath's Magic Shop%^WHITE%^
%^ORANGE%^The sign over the north door reads: %^GREEN%^Verbobone Exchange%^WHITE%^
"
    );
    set_exits(([
       "west" : "/d/deku/town/road6",
       "south" : "/d/deku/town/magic",
       "north" : "/d/deku/town/exchange",
       "east" : "/d/deku/town/road8"
    ] ));
    set_items(([
    ] ));
}
