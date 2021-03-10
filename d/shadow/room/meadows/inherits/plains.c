#include <std.h>
#include "../meadow.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(SAVANNAH);
   set_travel(FRESH_BLAZE);
   set_property("light",2);
   set_short("%^ORANGE%^Grassy Plains%^RESET%^");
   set_long(
   "%^YELLOW%^The plains around you are covered in four foot high dry"+
   " grass. The grass is a yellowish-green color and is thick and stiff,"+
   " but seems to be growing well on these dusty plains. You can tell"+
   " that animals must be moving about in sections by the way the grass"+
   " moves, but they are staying low to the ground and out of sight. Some"+
   " of the animals must be rather large judging by the way the grass"+
   " moves, it's best to be careful."
   );
   set("night long",
   "%^ORANGE%^The grassy plains spread out before you appear as"+
   " a %^BOLD%^%^CYAN%^bluish%^RESET%^-%^BOLD%^silver%^RESET%^%^ORANGE%^ under the light of the moon and stars. The wind"+
   " waves them back and forth like a thousand slender swords. Looking"+
   " closer you can tell that the grass is really a yellowish-green"+
   " shade, but it is also thick and sharp. The grass grows about four"+
   " feet tall and spreads out over a large area, concealing most of the"+
   " large predators that you sense are out there stalking you this night."
   );
   set_smell("default","The dust from the plains tickles your nose.");
   set_listen("default","The wind blows through the grass.");
   set_items(([
   "grass" : "%^YELLOW%^The grass is a rather ugly yellowish-green, normally"+
   " you would think any grass this color might be dying, but it appears"+
   " as though it has adapted to the rather dry and dusty plains here and"+
   " has managed to survive. It is thick and hard, with sharp edges, and is"+
   " the perfect cover for predators.",
   "ground" : "The ground is soft and dusty.",
   ]));
}

void reset()
{
   ::reset();
   if(present("monster")) return;
   if(!random(5)) return;
   if(query_night() == 1) {
      switch(random(19)) {
         case 0..5:
            new(MONS+"hyena")->move(TO);
            new(MONS+"hyena")->move(TO);
            break;
         case 6..8:
            new(MONS+"hyena")->move(TO);
            new(MONS+"hyena")->move(TO);
            new(MONS+"hyena")->move(TO);
            break;
         case 9..15:
            new(MONS+"bdog")->move(TO);
            new(MONS+"bdog")->move(TO);
            break;
         case 16..18:
            new(MONS+"bdog")->move(TO);
            new(MONS+"bdog")->move(TO);
            new(MONS+"bdog")->move(TO);
            break;
      }
   }
   else {
      switch(random(12)) {
         case 0..3:
            new(MONS+"spotted_lion")->move(TO);
            break;
         case 4..7:
            new(MONS+"cheetah")->move(TO);
            break;
         case 8..9:
            new(MONS+"antelope")->move(TO);
            break;
         case 10..11:
            new(MONS+"antelope")->move(TO);
            new(MONS+"antelope")->move(TO);
            break;
      }
   }
}
