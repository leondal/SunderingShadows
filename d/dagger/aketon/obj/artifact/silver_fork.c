//This item is intended to be an artifact in the game.
//Please do NOT clone it for any player. -Obsidian

#include "/d/dagger/aketon/short.h"

inherit ARTIFACT;

void create(){
   ::create();
   set_name("silver fork");
   set_short("%^RESET%^%^BOLD%^Silver fork");
   set_long("%^BOLD%^This is a fork made of pure silver. You realize that "
      "this is one of the rare artifact weapons that can be found.");
   set_id( ({"fork","silver fork","silver","artifact"}) );
   set_type("pierce");
   set_weight(10);
   set_value(1000);
   set_size(3);
   set_wc(1,8);
   set_large_wc(2,4);
   set_property("enchantment",3);
   while(query_property("enchantment") < 0) {
      remove_property("enchantment");
      set_property("enchantment",3);
   }
   set_hit( (: TO,"more_hit" :) );
   set_prof_type("fork");
   set_prof_level(25);
   set_item_name("fork");
   set_item_location(RPATH1+"1five3");
}

int more_hit(object vic) {
   object tp = query_wielded();
   if(random(10) > 7) {
      tell_object(tp,"%^BOLD%^You strike "+vic->query_cap_name()+
         " hard!");
      tell_room(environment(tp),"%^BOLD%^"+tp->query_cap_name()+" strikes "+
         vic->query_cap_name()+" hard!",({tp,vic}));
      tell_object(vic,"%^BOLD%^"+tp->query_cap_name()+" strikes you hard!");
      return roll_dice(2,8);
   }
   return roll_dice(1,8);
}
