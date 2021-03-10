//This item is intended to be an artifact in the game.
//Please do NOT clone it for any player. -Obsidian

#include "/d/dagger/aketon/short.h"

inherit ARTIFACT;

void create(){
   ::create();
   set_name("brass awlpike");
   set_short("%^YELLOW%^brass awlpike");
   set_long("%^YELLOW%^This is an awlpike made of pure brass. You realize "
      "it is one of the rare artifact weapons that can be found.");
   set_id( ({"awlpike","brass awlpike","brass","pike","artifact"}) );
   set_type("pierce");
   set_weight(12);
   set_value(1000);
   set_size(3);
   set_wc(1,6);
   set_large_wc(1,12);
   set_property("enchantment",2);
   while(query_property("enchantment") < 0) {
      remove_property("enchantment");
      set_property("enchantment",2);
   }
   set_hit( (: TO,"more_hit" :) );
   set_prof_type("polearm");
   set_prof_level(20);
   set_item_name("awlpike");
   set_item_location(RPATH1+"1five5");
}

int more_hit(object vic) {
   object tp = query_wielded();
   if(random(10) == 0) {
      tell_object(tp,"%^YELLOW%^You poke "+vic->query_cap_name()+
         " sharply!");
      tell_room(environment(tp),"%^YELLOW%^"+tp->query_cap_name()+
         " pokes "+vic->query_cap_name()+" sharply!",({tp,vic}));
      tell_object(vic,"%^YELLOW%^"+tp->query_cap_name()+" pokes you "
         "sharply!");
      return roll_dice(2,10);
   }
   return roll_dice(2,5);
}
