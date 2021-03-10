#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-2);
   set_property("indoors",1);
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_name("A dark cavern");
   set_short("A dark cavern");
   set_smell("default","The thick, heavy stench of dampness and decay fills the cavern.");
   set_listen("default","A constant stream of chatter, screeching, grumbling and general rabble surrounds you.");

   set_items(([
     ({"cave","cavern","walls","ground","roof","ceiling"}):"The cavern is formed of dull stone, still jagged "
"in many places and probably not shaped by mortal hands.  A pathway works its way around the cavern, nothing "
"more than a trail that has been cleared through the piles of trash and miscellaneous crap filling the rest "
"of the cavern.",
     ({"goblins","kobolds","hobgoblins","bugbears","creatures","beasts"}):"All around you is a crowd of "
"creatures, constantly coming and going, pushing and shoving past one another.  With them comes a terrible "
"odor, and a constant racket of noise filling the cavern."
   ]));
}

void reset() {
   ::reset();
   switch(random(10)) {
     case 0:
     tell_room(TO,"%^ORANGE%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the crowd before you can even react.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^RED%^A gang of bugbears shoves past, talking and laughing raucously amongst themselves "
"as the goblins and kobolds scatter out of their way.%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^BLACK%^%^BOLD%^A horrid smell emanates from a pile of trash beside the path.  It almost "
"smells like something died in there.  Ugh.%^RESET%^");
     break;
     case 4..5:
     tell_room(TO,"%^CYAN%^A fight breaks out between several goblins, over something they found in a pile of trash nearby.%^RESET%^");
     break;
     case 6..7:
     tell_room(TO,"%^BLUE%^Something wet and slimy drips down on you from the roof above.%^RESET%^");
     break;
     case 8:
     tell_room(TO,"%^YELLOW%^A dying screech of some small creature echoes through the cavern from the other "
"end.%^RESET%^");
     break;
     case 9:
     tell_room(TO,"%^GREEN%^A group of kobolds scurry through the crowd, weaving around the larger creatures "
"and screeching between themselves as they go.%^RESET%^");
     break;
   }
}