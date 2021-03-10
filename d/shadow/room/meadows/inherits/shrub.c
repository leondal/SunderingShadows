#include <std.h>
#include "../meadow.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(GAME_TRACK);
   set_property("light",2);
   set_property("indoors",0);
   set_short("Forest Brush");
   set_long(
   "You are walking along through some forest brush. It is pretty sparse,"+
   " but there is enough here to make finding a path rather difficult. The"+
   " brush tends to be prickly and scratches and catches at your legs as"+
   " you walk through it. You can hear animals scurrying about in the brush"+
   " around you, trying to get out of your way. Not all the animals in this"+
   " area might be so small and easily intimidated however."
   );
   set("night long",
   "%^GREEN%^Animals scurry about noisily in the brush around you, scattering to get"+
   " out of your way. It is dark now and harder to tell where you are going,"+
   " the brush seems a bit intimidating with all the dark shadows before"+
   " you. The bushes tend to scratch you as you pass and catch on your"+
   " clothing. Trying to find a path through here at night is definitely"+
   " a bit of an adventure."
   );
   set_smell("default","Animal musk hangs in the air.");
   set_listen("default","You can hear animals moving about in the brush.");
   set_items(([
   ({"bushes","shrubs"}) : "There are small little scrub bushes all over"+
   " the place here, some of them growing in large patches. They are"+
   " hard and some are prickly, all of them seem to scratch you as you"+
   " pass them, and most catch at your armor and clothing.",
   "ground" : "The ground is soft dirt but also rather rocky, which is"+
   " why it does not allow much to grow here other than the tenacious"+
   " shrub bushes.",
   ]));
}

void reset()
{
   ::reset();
   if(present("monster")) return;
   if(random(3)) return;
   if(query_night() == 1) {
      switch(random(6)) {
         case 0..2:
            new(MONS+"weasel")->move(TO);
            break;
         case 3..4:
            new(MONS+"weasel")->move(TO);
            new(MONS+"weasel")->move(TO);
            break;
         case 5:
            new(MONS+"weasel")->move(TO);
            new(MONS+"weasel")->move(TO);
            new(MONS+"weasel")->move(TO);
            break;
      }
   }
   else {
      switch(random(4)) {
         case 0..2:
            new(MONS+"muskrat")->move(TO);
            break;
         case 3:
            new(MONS+"muskrat")->move(TO);
            new(MONS+"muskrat")->move(TO);
            break;
      }
   }
}
