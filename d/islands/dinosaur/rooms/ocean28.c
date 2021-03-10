#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit OCEAN;

void create(){
    ::create();
    set_short("%^BOLD%^%^CYAN%^Oceanic cliffs%^RESET%^");
    set_long(
      "Here on the south end of the island, you are on the fingerlike cliffs that reach out into the ocean.  From here you can see gigantic shapes in the water under the rocky cliffs, cliffs that don't seem to be the most sturdy."
    );
    set_listen("default", "You can hear the waves crash on the cliffs, eroding them away as time passes.");
    set_smell("default", "The sea air is strong on the breeze.");
    set_items( ([
      "water" : "In the water you can see several large moving shapes.",
      "shapes" : "They seem to be, well, large.",
      "cliffs" : "Some of these rocks look like they could give way at any moment.",
    ]) );
    set_exits( ([
      "northeast" : RPATH "ocean25",
      "south" : RPATH "ocean29",
      "southwest" : RPATH "ocean32",
    ]) );
}
