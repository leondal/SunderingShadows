#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^ORANGE%^");
    set_long(
"%^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^own of %^BOLD%^V%^RESET%^%^GREEN%^erbobone%^ORANGE%^
This is the broadway street going through the town of Verbobone. Buildings seem to endlessly line the street to the south. Toward the north the street ends at a large house. Most of the buildings along the street are constructed of wo%^GREEN%^od %^ORANGE%^with t%^RED%^h%^ORANGE%^a%^RED%^t%^ORANGE%^c%^RED%^h%^ORANGE%^e%^RED%^d %^ORANGE%^r%^RED%^o%^ORANGE%^o%^RED%^f%^ORANGE%^s and %^WHITE%^white washed %^ORANGE%^or s%^WHITE%^t%^ORANGE%^u%^WHITE%^c%^ORANGE%^c%^WHITE%^o%^ORANGE%^e%^WHITE%^d %^ORANGE%^w%^WHITE%^al%^ORANGE%^l%^WHITE%^s%^ORANGE%^..

%^ORANGE%^The sign over the western door reads: %^GREEN%^Verbobone Church
%^ORANGE%^The sign over the eastern door reads: %^RED%^Information Office
"
);
    set_exits(([
      "west":"/d/deku/town/church",
       "east" : "/d/deku/town/info_office",
       "south" : "/d/deku/town/road10",
       "north" : "/d/deku/town/road12"
    ] ));
    set_items(([
    ] ));
}
