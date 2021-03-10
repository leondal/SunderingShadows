//rooms for the wild elf encampment near Synoria
//coded for the aftermath of the tarrasque plot with
//descriptions from Amasaeele ~Circe~ 4/26/13

#include <std.h>
#include "../../elfisland1.h"

inherit ROOM;

void create(){
   ::create();
   set_travel(FOOT_PATH);
   set_terrain(HEAVY_FOREST);
   set_name("A camp in the forest");
   set_short("%^RESET%^%^GREEN%^A camp in the forest%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^You have wandered deep into the "
      "%^GREEN%^woods %^ORANGE%^and find yourself surrounded by tall, "
      "healthy %^GREEN%^oak trees%^ORANGE%^.  %^GREEN%^Green grass "
      "%^ORANGE%^reaches up past your ankles and stretches through "
      "every part of this magnificent forest.  A small mound rises here, "
      "nestled safely between the tall %^GREEN%^oak trees %^ORANGE%^that "
      "obscure and restrict your view.  Around you, the area bears "
      "subtle hints of careful use.  Barely noticeable leather skins "
      "are strung up at uneven intervals among the tree-tops, "
      "doubling as cover and make-shift %^RESET%^hammocks%^ORANGE%^.  "
      "Tribal-looking ornaments, %^CYAN%^dre%^WHITE%^a%^CYAN%^m-cat"
      "%^RESET%^c%^CYAN%^hers%^ORANGE%^, and %^BOLD%^%^WHITE%^wind-chimes "
      "%^RESET%^%^ORANGE%^sway lazily in the %^CYAN%^breeze%^ORANGE%^.  You "
      "sense movement around you and feel as though you are being watched.%^RESET%^\n");
   set_light(2);
   set_indoors(0);
   set_smell("default","You smell the fresh scent of the woods around you mingled with the faintest hint of smoke.");
   set_listen("default","The area has grown quiet, save for the wind blowing through the heavy branches and the wind-chimes.");
   set_items(([
      "movement" : "Shadows in the woods whisper of large predators prowling "
         "the area.  Branches snap and sway above you, hinting of movement "
         "within the foliage.",
      ({"trees","forest"}) : "These magnificent oak trees are taller than "
         "average and stand firmly, with deep roots.  Here, barely noticeable "
         "leather skins are strung up at uneven intervals among the tree-tops, "
         "doubling as cover and make-shift hammocks.  Small camouflaged "
         "bundles are tied to lower branches, holding primitive tools and toys.  "
         "You also notice some claw-marks on the tree-trunks, suggesting this "
         "area is frequently visited by large predators.",
      ({"tools","toys"}) : "These make-shift tools seem primitive at first "
         "glance.  Utensils for purposes such as smithing, fishing, and cooking, "
         "all made from sharpened sticks or stones, tied together by straps of "
         "fine leather or woven thread.  They can be dissembled and reassembled "
         "at a moment's notice, however, and you soon realize they are every bit "
         "as capable as their so-called civilized counterparts. The toys are of "
         "a similar quality, woven from straw or carved to the likeness of animals and birds.",
      "mound" : "A small mound rises here, nestled safely between the trees.  "
         "Strangely enough, the faint scent of smoke seems to drift from within.  "
         "Looking closer, you notice a small opening that leads into the natural mound."
   ]));
   set_search("default","Looking closer, you realize you could enter the <mound> from "
      "here.  You can't help but wonder what type of welcome you might receive.");
   set_exits(([
      "mound" : TOWN+"wild3",
      "east" : TOWN+"wild1"
   ]));
   set_invis_exits(({"mound"}));
}