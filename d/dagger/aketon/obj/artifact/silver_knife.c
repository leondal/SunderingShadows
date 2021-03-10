//This item is intended to be an artifact in the game.
//Please do NOT clone it for any player. -Obsidian

#include "/d/dagger/aketon/short.h"

inherit ARTIFACT;

void create(){
   ::create();
   set_name("silver knife");
   set_short("%^RESET%^%^BOLD%^Silver knife");
   set_long("%^BOLD%^This is a knife made of pure silver. You realize "
      "it is one of the rare artifact weapons that can be found.");
   set_id( ({"knife","silver knife","silver","artifact"}) );
   set_type("piercing");
   set_weight(5);
   set_value(800);
   set_size(1);
   set_wc(1,3);
   set_large_wc(1,2);
   set_property("enchantment",2);
   while(query_property("enchantment") < 0) {
      remove_property("enchantment");
      set_property("enchantment",2);
   }
   set_hit( (: TO,"more_hit" :) );
   set_prof_type("tool");
   set_prof_level(20);
   set_item_name("knife");
   set_item_location(RPATH1+"1five3");
}

int more_hit(object vic) {
   object tp = query_wielded();
   if(random(10) == 8) {
      tell_object(tp,"%^BOLD%^You poke "+vic->query_cap_name()+
         " hard!");
      tell_room(environment(tp),"%^BOLD%^"+tp->query_cap_name()+" pokes "+
         vic->query_cap_name()+" hard!",({tp,vic}));
      tell_object(vic,"%^BOLD%^"+tp->query_cap_name()+" pokes you hard!");
      return roll_dice(6,3);
   }
   return roll_dice(3,3);
}
