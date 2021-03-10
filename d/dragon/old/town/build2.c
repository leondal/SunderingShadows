//  /d/dragon/town/build2.c
#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
     set_short("Abandoned Building");
    set_long("%^BOLD%^%^BLUE%^
The house itself is a proud testament to its builder, standing against
the elements without the slightest sign of wear.  A candlelit jack-o-
lantern sneers through one curtained window.  This is the residence of
Ezekiel Devek the carpenter and wagon maker of %^CYAN%^Sanctuary%^BLUE%^.
    ");
    set_exits(([
       "south" : "/d/dragon/town/roadE3"
    ] ));
    set_items(([
    ] ));
  set_smell("default","The cigar smoke from the traveling merchants is overwhelming.");
}
