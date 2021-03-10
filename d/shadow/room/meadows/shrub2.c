#include <std.h>
#include "meadow.h"
inherit ROOM;

int count;

void create()
{
   ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(GAME_TRACK);
   set_property("light",2);
   set_property("indoors",0);
   set_short("%^MAGENTA%^Blackberry Bushes%^RESET%^");
   set_long(
   "You have come across a patch of blackberry bushes. They appear to be"+
   " growing wild here and are all over the place. Some of the animals"+
   " appear to like them, you can see places where some of the berries"+
   " have been half-eaten, and the sweet smell of the berries is strong."
   );
   set("night long",
   "%^MAGENTA%^You have stumbled across a patch of blackberry bushes. They"+
   " seem to be growing wild here and cover most of the area. They are a"+
   " bit prickly and hard to wade through, but they smell delicious. You"+
   " can tell that animals and insects frequent this area from all the"+
   " half-eaten berries and ones that have been knocked to the ground."
   );
   set_smell("default","The sweet scent of blackberries is strong.");
   set_listen("default","You can hear animals moving about in the brush.");
   set_items(([
   ({"bushes","shrubs"}) : "There are small little scrub bushes all over"+
   " the place here, some of them growing in large patches. They are"+
   " hard and some are prickly, all of them seem to scratch you as you"+
   " pass them, and most catch at your armor and clothing. There are also"+
   " some blackberry bushes here.",
   "ground" : "The ground is soft dirt but also rather rocky, which is"+
   " why it does not allow much to grow here other than the tenacious"+
   " shrub bushes.",
   "blackberry bushes" : "%^MAGENTA%^There are many delicious looking and"+
   " very ripe blackberries on the bushes, just waiting to be picked.%^RESET%^",
   ({"berries","blackberries"}) : "%^MAGENTA%^Ripe and delicious looking"+
   " blackberries hang tantalizingly from the bushes.%^RESET%^",
   ]));
   set_exits(([
   "south" : ROOMS+"shrub1",
   "east" : ROOMS+"shrub3",
   ]));
   count = 5;
}

void init()
{
   ::init();
   add_action("pick","pick");
}

void pick(string str)
{
   if(str != "berries" && str != "blackberries" && str != "blackberry bushes" && str != "bushes") {
      tell_object(TP,"Pick what?");
      return 1;
   }
   if(count < 1) {
      tell_object(TP,"It looks like all the blackberries have already been picked.");
      return 1;
   }
   tell_object(TP,"%^MAGENTA%^You pick a handful of ripe blackberries.");
   tell_room(ETP,"%^MAGENTA%^"+TPQCN+" picks a handful of ripe blackberries.",TP);
   new(OBJ+"berries")->move(TP);
   count -= 1;
      if(count < 1) {
         add_item("blackberry bushes","There are many blackberry bushes"+
         " here, but it appears as though all the berries have been picked.");
         add_item("blackberries","You see some half-eaten berries that you"+
         " wouldn't want to touch, as well as some unripe ones, but all"+
         " the good berries have been picked already.");
         add_item("berries","You see some half-eaten berries that you"+
         " wouldn't want to touch, as well as some unripe ones, but all"+
         " the good berries have been picked already.");
      }
   return 1;
}
