#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Balcony upon the tree");
   set_long("%^GREEN%^Balcony upon the tree%^RESET%^
Few leaves are here to block your view. As you peer around from this "
      "not so large balcony, you see a large tree stands not far away to "
      "the northwest. Below you is the busy city and all walks of life. "
      "Crowds of people travel through the broadways of the tree "
       "branches down there. Shops line the streets. Troops of city "
      "patrols and guards are all around to defend the city from invaders "
       "from nearby rival cities. Peering far away, you see a mountain range "
      "towards the far north and the sea at your east.");
   set_items( (["balcony":"This balcony is actually some wood board which "
      "are extended outside the main tree trunk, and surrounded by some "
      "wood as handrail.",
   "leaves":"Few leaves are here.",
      "tree":"You see buildings and people on the tree.",
      "city":"Many people there. It is noisy.",
      "people":"Most of them are elf.",
      "broadways":"Those are the city streets.",
      "shops":"All kinds of shops.",
      "streets":"The streets are build on the main branches of the tree.",
      ({"troops","guards","patrols"}):"They are responsible for the safe "
      "of the city.",
      "mountain":"Towards the far north...",
      "sea":"Saakrune sea is the only known ocean of the realms."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city coming from below.");
   set_exits( (["south":RPATH1+"1three7",
      "west":RPATH1+"1three2"]) );
}
