//rooms for the wild elf encampment near Synoria
//coded for the aftermath of the tarrasque plot with
//descriptions from Amasaeele ~Circe~ 4/26/13

#include <std.h>
#include "../../elfisland1.h"

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(WOOD_BUILDING);
   set_name("Within a natural mound");
   set_short("%^RESET%^%^ORANGE%^Within a natural mound%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^You carefully push your way through the "
      "opening and find yourself inside the natural mound.  The scent of "
      "fresh %^YELLOW%^mold%^RESET%^%^ORANGE%^ and %^GREEN%^moss %^ORANGE%^"
      "fills your nose, mingled with the odor of sweat and just a hint of "
      "%^BOLD%^%^BLACK%^smoke%^RESET%^%^ORANGE%^.  %^GREEN%^Insects "
      "%^ORANGE%^scuttle in the fresh dirt, and a small group of "
      "%^BOLD%^%^GREEN%^fir%^YELLOW%^e%^GREEN%^fl%^YELLOW%^i%^GREEN%^es "
      "%^RESET%^%^ORANGE%^lend a soft glow to the otherwise shadowy area.  "
      "As you move forward, mold falls from the natural ceiling, held "
      "back only by the deep, criss-crossing %^RESET%^roots %^ORANGE%^of "
      "the %^GREEN%^oak trees%^ORANGE%^.  The ground appears sturdy enough "
      "though and is covered by straw mats and soft animal skins.  In the "
      "center of the mound sits a smoldering %^RED%^campfire%^ORANGE%^, "
      "the %^BOLD%^%^BLACK%^smoke %^RESET%^%^ORANGE%^drifting upwards "
      "through natural vents in the mound.  Hides, make-shift tools and "
      "toys lay scattered among the skins, suggesting that this must be "
      "a well-used area.%^RESET%^\n");
   set_light(2);
   set_indoors(1);
   set_smell("default","The scent of fresh mold and moss fills your nose, mingled with the odor of sweat and just a hint of smoke.");
   set_listen("default","You hear the faint crackle from a smoldering campfire and the scuttle of tiny insects in the fresh dirt.");
   set_items(([
      ({"tools","toys"}) : "These make-shift tools seem primitive at first "
         "glance.  Utensils for purposes such as smithing, fishing, and cooking, "
         "all made from sharpened sticks or stones, tied together by straps of "
         "fine leather or woven thread.  They can be dissembled and reassembled "
         "at a moment's notice, however, and you soon realize they are every bit "
         "as capable as their so-called civilized counterparts. The toys are of "
         "a similar quality, woven from straw or carved to the likeness of animals and birds.",
      "campfire" : "A carefully tended campfire occupies the center of the "
         "mound, placed within a circle of darkened stones.  A perfectly "
         "flat black stone lays on the heated coal, feeling sizzling hot.  "
         "A small basket contains nuts, vegetables, and herbs, ready for cooking."
   ]));
   set_exits(([
      "out": TOWN+"wild2"
   ]));
}