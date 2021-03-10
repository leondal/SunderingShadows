
#include <std.h>
#include "../vesprus.h"

inherit VAULT;

void create(){
    ::create();
    set_name("northern docks");
    set_short("%^BOLD%^Northern Docks");
    set_long(
@OLI
    %^BOLD%^Northern Docks, by the city wall
    Warf Street%^RESET%^
Here by the docks of the port of Vesprus, people bustle about. Even in the
dark of night the docks teem with activity. Loads of cargo of every type 
gathered from around the continent are hauled here. Also being a city 
highly dependant on the outside world of manufactured goods, many items
are shipped in. To the north are the city walls and the beginning of Walled
avenue. To the south extends Warf Street and its chaos.
OLI
        );
    set_smell("default","The smells of fish, boat tar, and human offal mingle together to accost your senses.");
    set_listen("default","The bustle of people around you, mixes with the shouts of sailors and the creaking of the ships.");
    set_items((["cargo":"%^RESET%^%^ORANGE%^Different odd sized boxes are stacked and line the edges of the streets here as people bustle about, moving them up and down the pier.%^RESET%^",
      ({"walls","city walls"}):"The city walls stretch high above you to the north and line the eastern side of Walled Avenue.  The walls look to be made of solid blocks of granite, each slab stacked upon the other so tightly that it is doubtful even a piece of parchment could be wedged between them.",
      "city":"%^RESET%^%^CYAN%^The city rises high above you to the northwest.  Night or day, it seems to have a peaceful, yet magical presence about it.  A large tower looms above all else in the center of town.%^RESET%^",
      "tower":"%^YELLOW%^The tower sets high in the center of town.  From here you can just make out its arched entrances high above even the inner city walls.  The tower seems to constantly glow, making it look as though it were reflecting the sunlight during the day, and lit with its own inner magic at night.%^RESET%^",
              ]));
    set_exits(([
              "north":VESPRUSROOMS"ws1",
              "south":VESPRUSROOMS"dr2",
              "pier":VESPRUSROOMS"pier1",
              ]));
}





