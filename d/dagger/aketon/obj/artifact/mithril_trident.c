//This item is intended to be an artifact in the game.
//Please do NOT clone it for any player. -Obsidian

#include "/d/dagger/aketon/short.h"

inherit ARTIFACT;

create() {
    ::create();
   set_name("mithril trident");
   set_short("%^RESET%^%^CYAN%^Mithril trident");
   set_long("%^CYAN%^This is a trident made of light mithril. You realize "
      "that this is one of the rare artifact weapons that can be found.");
   set_id( ({"trident","mithril","mithril trident","artifact"}) );
   set_weight(7);
   set_size(2);
   set_value(800);
   set_wc(1,6);
   set_large_wc(3,4);
   set_type("pierce");
   set_property("enchantment",2);
   while(query_property("enchantment") < 0) {
      remove_property("enchantment");
      set_property("enchantment",2);
   }
   set_hit( (: TO,"more_hit" :) );
   set_prof_type("fork");
   set_prof_level(15);
   set_item_name("trident");
   set_item_location(RPATH1+"1three1a");
}

int more_hit(object vic) {
   object tp = query_wielded();
   if(random(10) > 7) {
      tell_object(tp,"%^CYAN%^You pierce through "+vic->query_cap_name()+
         "'s defence!");
      tell_room(environment(tp),"%^CYAN%^"+tp->query_cap_name()+" pierces "
         "through "+vic->query_cap_name()+"'s defence!",({tp,vic}));
      tell_object(vic,"%^CYAN%^"+tp->query_cap_name()+" pierces through "
         "your defence!");
      return roll_dice(2,6);
   }
   return roll_dice(1,6);
}
