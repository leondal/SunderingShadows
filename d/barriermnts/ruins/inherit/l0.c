// level 0 default

#include <std.h>
#include "../inherit/ruins.h"
inherit CROOM;

object ob;
int items;

void create() {
    items = 1;
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",-1);
    set_name("Darkened basement of an abandoned building");
    set_short("%^BLACK%^%^BOLD%^Darkened basement of an abandoned building%^RESET%^");
    set_smell("default","Tendrils of mist tickle your nose with an old, musty smell.");
    set_listen("default","Thick silence fills the air around you.");
    set_items(([
      "floor" : "%^BLUE%^The floor feels solid and level beneath your feet, though it is impossible to "
"see through the thick layer of %^WHITE%^mist%^BLUE%^ wafting around your legs.  Hopefully there is "
"nothing nasty hidden beneath it.%^RESET%^",
      ({"walls","wall"}) : "%^BLUE%^The walls are difficult to see, shrouded in %^BLACK%^%^BOLD%^shadows "
"%^RESET%^%^BLUE%^that seem to move constantly.  They are crafted of strong stone, darkened by decades "
"of dirt and weathering.  In a few places, however, you can still make out the markings of patterns "
"along the walls, as if they have been somehow preserved over the ages.%^RESET%^",
      "roof" : "%^BLUE%^The roof reaches high above your head, shrouded in "
"%^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ and %^ORANGE%^dust%^BLUE%^.  Ornate bordering from nearby "
"walls traces along the ceiling's edges.%^RESET%^",
      ({"fog","mist","mists"}) : "%^BLUE%^Thick %^WHITE%^mist%^BLUE%^ conceals the entire floor from "
"sight, swirling in thick tendrils around your feet.  There's no telling what might be hidden beneath "
"it.%^RESET%^",
      ({"shadows","shadow"}) : "%^BLACK%^%^BOLD%^Shadows%^RESET%^%^BLUE%^ move and shift all around you, "
"cloaking the walls and the ceiling above.%^RESET%^"
    ]));
    set_search("default","Where do you want to search?");
    set_search("fog",(:TO,"search_fog":));
    set_search("mist",(:TO,"search_fog":));
    set_search("mists",(:TO,"search_fog":));
}

void reset() {
    ::reset();
    items = 1;
}

int search_fog(string str) {
    if (!items) {
      tell_object(TP,"It seems like someone has searched around here already.");
      return 1;
    }
    switch(random(100)) {
      case 0..12:
      ob = new("/std/obj/coins");
      ob->set_money("gold",random(12)*random(13));
      ob->set_money("electrum",random(12)*7);
      ob->move(ETP);
      tell_object(TP,"You find a few coins someone must have dropped.");
      tell_room(ETP,""+TP->QCN+" searches through the mists and seems to find something.",TP);
      break;

      case 13..22:
      ob = new("/d/common/obj/potion/healing");
      ob->set_uses(random(5)+6);
      ob->move(ETP);
      tell_object(TP,"You find some unbroken bottles someone must have dropped.");
      tell_room(ETP,""+TP->QCN+" searches through the mists and seems to find something.",TP);
      break;

      case 23..29:
      ob = new("/d/magic/scroll");
      ob->set_av_spell(random(2)+5);
      ob->move(ETP);
      tell_object(TP,"You find a rolled-up sheet of parchment someone must have dropped.");
      tell_room(ETP,""+TP->QCN+" searches through the mists and seems to find something.",TP);
      break;

      case 30..34:
      tell_object(TP,"You pull your hand back quickly when something under the fog brushes against it.");
      tell_room(ETP,""+TP->QCN+" searches around under the mists, then quickly pulls back "+TP->QP+
" hand.",TP);
      break;

      case 35..44:
      tell_object(TP,"A sharp pain stings through your hand!");
      TP->do_damage("torso",roll_dice(1,6));
      if(!"daemon/saving_d"->saving_throw(TP,"paralyzation_poison_death")) { 
        TP->add_poisoning(30);
        tell_object(TP,"The bite on your hand begins to burn!");
      }
      tell_object(TP,"You pull your hand back quickly, brushing the fog aside to reveal a sharp-fanged "
"lizard!");
      tell_room(ETP,""+TP->QCN+" winces and pulls "+TP->QP+" hand back quickly, brushing the fog aside "
"to reveal a sharp-fanged lizard!",TP);
      tell_room(ETP,"The lizard hisses at you and scuttles away under the fog.");
      break;

      case 45..99:
      tell_object(TP,"You don't find anything.");
      tell_room(ETP,""+TP->QCN+" searches around but looks disappointed.",TP);
      break;
      }
    items = 0;
    return 1;
}
