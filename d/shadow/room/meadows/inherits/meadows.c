#include <std.h>
#include "../meadow.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(MEADOWLANDS);
   set_travel(GAME_TRACK);
   set_property("light",2);
   set_property("indoors",0);
   set_short("%^BOLD%^%^GREEN%^Meadow Lands%^RESET%^");
   set_long(
   "%^BOLD%^%^GREEN%^The meadow lands are incredibly lush and beautiful, full of life."+
   " Dark green grass comes up as high as four feet in some places and"+
   " is filled with all sorts of insects and animals. There are wildflowers"+
   " that have sprouted up about the area, giving off a wonderful scent."+
   " Despite the beauty of this place you realize that it could quite"+
   " easily conceal many dangers and it's best to be on your guard.\n"
   );
   set("night long",
   "%^GREEN%^The night air blows a cool breeze across the meadow lands,"+
   " rustling the grass and arousing the crickets even louder. The grass"+
   " is dark and thick, making it hard to see whether or not your next"+
   " step will be safe. You never know what could be hiding under the"+
   " tall grass, or what might be out there waiting to ambush you.\n"
   );
   set_smell("default","The fragrant wildflowers are wonderful.");
   if(query_night() == 1) {
      set_listen("default","The crickets are chirping loudly.");
   }
   else {
      set_listen("default","Some birds are pouring their heart out in song.");
   }
   set_items(([
   "grass" : "%^GREEN%^The tall grass is dark and lush, reaching over"+
   " four feet high in some places. It is filled with crickets and"+
   " smaller animals, but you realize that it could also conceal something"+
   " more sinister.",
   ({"wildflowers","flowers"}) : "%^MAGENTA%^Wildflowers grow around the meadow lands,"+
   " often under the grass, although some have fought their way above"+
   " it where the grass is lower. They give off a wonderful fragrance.",
   "crickets" : "Numerous crickets are hiding and jumping about in the grass.",
   "birds" : "You can hear birds in the distance, but they seem to be"+
   " elusive when you turn about to look for them.",
   ]));
}

void reset()
{
   ::reset();
   if(present("monster")) return;
   if(random(3)) return;
   if(query_night() == 1) {
      switch(random(6)) {
         case 0:
            new(MONS+"firebeetle")->move(TO);
            break;
         case 1:
            new(MONS+"wererat")->move(TO);
            break;
         case 2:
            new(MONS+"wererat")->move(TO);
            new(MONS+"wererat")->move(TO);
            break;
         case 3:
            new(MONS+"flind")->move(TO);
            new(MONS+"flind")->move(TO);
            break;
         case 4:
            new(MONS+"flind")->move(TO);
            new(MONS+"flind")->move(TO);
            new(MONS+"flind")->move(TO);
            break;
         case 5:
            new(MONS+"wereboar")->move(TO);
            break;
      }
   }
   else {
      switch(random(10)) {
         case 0..3:
            new(MONS+"bhawk")->move(TO);
            new(MONS+"bhawk")->move(TO);
            break;
         case 4..5:
            new(MONS+"bhawk")->move(TO);
            new(MONS+"bhawk")->move(TO);
            new(MONS+"bhawk")->move(TO);
            break;
         case 6..8:
            new(MONS+"wereboar")->move(TO);
            break;
         case 9:
            new(MONS+"lbasilisk")->move(TO);
            break;
      }
   }
}
