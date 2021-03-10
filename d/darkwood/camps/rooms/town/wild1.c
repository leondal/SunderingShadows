//rooms for the wild elf encampment near Synoria
//coded for the aftermath of the tarrasque plot with
//descriptions from Amasaeele ~Circe~ 4/26/13

#include <std.h>
#include "../../elfisland1.h"

inherit VAULT;

void create(){
   ::create();
   set_travel(FOOT_PATH);
   set_terrain(HEAVY_FOREST);
   set_name("Deep in the forest");
   set_short("%^RESET%^%^GREEN%^Deep in the forest%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Green grass %^ORANGE%^reaches up past "
      "your ankles and stretches through every part of this magnificent "
      "%^BOLD%^%^GREEN%^forest%^RESET%^%^ORANGE%^.  You have wandered a "
      "little off the path and find yourself surrounded by tall, healthy "
      "%^GREEN%^oak trees %^ORANGE%^that restrict and obscure your view.  "
      "%^CYAN%^Wind %^ORANGE%^blows through heavy branches, making them "
      "sway gently.  Brightly colored %^MAGENTA%^bu%^CYAN%^t%^MAGENTA%^te"
      "%^BOLD%^r%^RESET%^%^MAGENTA%^fl%^YELLOW%^i%^RESET%^%^MAGENTA%^es "
      "%^ORANGE%^float around on the %^CYAN%^breeze%^ORANGE%^, breaking the "
      "sudden stillness of the woods around you.  As you peer into the "
      "forest, you can see that %^GREEN%^nature %^ORANGE%^is virtually "
      "untouched here.  You sense movement around you and feel as though "
      "you are being watched.  Perhaps it is time time to turn back before "
      "you get lost?%^RESET%^\n");
   set_light(2);
   set_indoors(0);
   set_smell("default","You smell the fresh scent of the woods around you.");
   set_listen("default","The area has grown quiet, save for the wind blowing through the heavy branches.");
   set_items(([
      "movement" : "Shadows in the woods whisper of large predators prowling "
         "the area.  Branches snap and sway above you, hinting of movement "
         "within the foliage.",
      ({"trees","forest"}) : "These magnificent oak trees are taller than "
         "average and stand firmly, with deep roots.  Nature is virtually "
         "untouched here. A small collection of feathers sway gently from a "
         "low branch just west of you.",
      ({"feather","feathers","collection"}) : "This is a small collection "
         "of tail-feathers, tied with a thin leather cord.  The characteristic "
         "feather of a hawk, pale gray striped with reddish-brown, is paired "
         "with the pure white feather of a dove.  Crossing these are two "
         "grayish blue feathers from a quail, pointing deeper into the forest.",
      ({"butterfly","butterflies"}) : "Multicolored butterflies drift on the breeze, "
         "fluttering through the low-hanging branches.  They brighten what is "
         "otherwise a rather dark section of the foreset."
   ]));
   set_search("default","The feathers are really the only thing that catches your attention here.");
   set_search("feathers","You take a closer look at the feathers, realizing "
      "that they must have some meaning.  Perhaps you should try to <observe> them.");
   set_exits(([
      "northeast" : TOWN+"road19",
      "west" : TOWN+"wild2"
   ]));
   set_invis_exits(({"west"}));
   set_pre_exit_functions(({"west"}),({"go_west"}));
}

void init(){
   ::init();
   add_action("observe_em","observe");
}

int observe_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to observe?");
      return 1;
   }
   if(str != "feather" && str != "feathers") return 0;
   if((string)TP->query_race() == "elf" || (int)TP->query_skill("academics") > 5){
      tell_object(TP,"You examine the feathers, trying to recall anything you might "
         "have heard about their symbolism.  You remember that hawk feathers usually "
         "suggest that an area is under the protection of followers of Nim'navanon.  "
         "Crossed with the pure white of the dove, it might symbolize an area of "
         "peace or unity.  Quails, similarly, are associated with family and "
         "protectiveness.  Their placement could indicate that something lies "
         "deeper in the forest to the west... but what?");
      tell_room(TO,""+TPQCN+" studies the feathers intently.",TP);
      return 1;
   }else{
      tell_object(TP,"You attempt to study the feathers but can make little sense of their meaning.");
      tell_room(TO,""+TPQCN+" looks confused as "+TP->QS+" studies the feathers.",TP);
      return 1;
   }
}

int go_west(){
   tell_object(TP,"You follow the directions of the feathers and push deeper into the forest.");
   return ::GoThroughDoor();
}
