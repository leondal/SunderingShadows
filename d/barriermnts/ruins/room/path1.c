#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"path";

void create() {
    ::create();
    set_long("%^GREEN%^The forest is spread along the edges of this narrow %^ORANGE%^dirt path "
"%^GREEN%^that winds further up into the mountain range, disappearing from view.  Walls of "
"%^BLACK%^%^BOLD%^stone%^RESET%^%^GREEN%^ begin to close in around you, reaching up to the sky.  Large "
"boulders and scatterings of undergrowth cover the mountainsides around you, and a few scattered "
"%^BOLD%^pinetrees%^RESET%^%^GREEN%^ dot their edges.  The path itself looks as though it has seen "
"little use for many years.  To the south, the mountainsides part to reveal a grand building, of a very "
"old and archaic design.%^RESET%^\n");
   set("night long","%^BLUE%^The forest is sprawled in small patches here, revealing the night sky above "
"this narrow %^ORANGE%^dirt side-path%^BLUE%^, that winds further up into the mountain range and "
"disappears from view.  %^BLACK%^%^BOLD%^Dark shadows%^RESET%^%^BLUE%^ dot the mountainsides around you, "
"that seem to close in around you in the darkness.  The rising mountains are dotted with sparse "
"%^GREEN%^trees %^BLUE%^and %^BLACK%^%^BOLD%^boulders%^RESET%^%^BLUE%^, leaving no shelter anywhere you "
"can see.  To the south, the mountainsides part to reveal a grand building, of a very old and archaic "
"design.%^RESET%^\n");
    set_exits(([
      "northeast" : ROOMS+"path2",
      "south" : ROOMS+"path0"
    ]));
    add_item("building","%^GREEN%^To the south stands a grand building, that looks as though it were "
"abandoned long ago.  It is of an old archaic design, with great stone walls and a pair of tall %^BLACK%^%^BOLD%^ashen doors%^RESET%^%^GREEN%^.%^RESET%^");
    add_item("cathedral","%^GREEN%^Before you stands a grand building, that looks as though it were "
"abandoned long ago.  It is of an old archaic design, with great stone walls and a pair of tall %^BLACK%^%^BOLD%^ashen doors%^RESET%^%^GREEN%^.%^RESET%^");
}
