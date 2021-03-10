//Updated by ~Circe~ 8/13/15 to add the swamp

#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_long(
      "%^ORANGE%^A sandy wasteland shore\n "
       "You are on a barren shore alongside the %^CYAN%^Sa%^BOLD%^"
	   "%^WHITE%^a%^RESET%^%^CYAN%^krune S%^BOLD%^%^WHITE%^e%^RESET%^"
	   "%^CYAN%^a%^ORANGE%^.  The earth appears cracked and dead with "
	   "no vegetation other than an occasional unusually large cactus.  "
	   "A wicked wind bites at your face, blowing sand into your eyes.  "
	   "Here and there a %^YELLOW%^sulfurous mist %^RESET%^%^ORANGE%^"
	   "spews from a new fissure in the ground.  The lifeless wasteland "
	   "continues for what seems like leagues towards the west.\n\n%^BOLD%^%^BLACK%^To the east, an %^RESET%^eerie "
       "swamp%^BOLD%^%^BLACK%^ spreads across the land. Twisted, dead "
       "trees stretch up from the stale water, dotted here and there by "
       "diseased %^RESET%^%^GREEN%^lily pads%^BOLD%^%^BLACK%^.%^RESET%^\n"
    );
    add_item("swamp","The swamp stretches as far as the eye can see, "
       "an endless waste of foul water broken by decaying trees and diseased lily pads.");
    set_exits( ([
        "north":"/d/laerad/wasteland/waste102",
        "east":"/d/laerad/swamp/swamp02",
        "west":"/d/laerad/wasteland/waste96"
    ]) );
}
