#include "/d/dagger/aketon/short.h"

inherit WEAPON;

create() {
   ::create();
   set_id( ({"flail","power","flail of power"}) );
   set_name("flail of power");
   set_short("%^RESET%^%^RED%^Flail of power");
   set_long("%^RED%^This flail looks similar to normal flails except that "
      "it is a little heavier and longer. A slight red arua radiates from "
      "the flail.");
   set_weight(17);
   set_size(2);
   set_value(850);
   set_wc(1,6);
   set_large_wc(2,4);
   set_type("bludgeoning");
   set_property("enchantment",random(3)+2);
   set_hit( (: TO,"hit_func" :) );
   set_prof_type("flail");
}

int hit_func(object vic) {
   object tp = query_wielded();
   if(random(10) > 5) {
      tell_object(tp,"%^RED%^You bash "+vic->query_cap_name()+" with "
         "POWER!");
      tell_room(environment(tp),"%^RED%^"+tp->query_cap_name()+" bashes "+
         vic->query_cap_name()+" with POWER!",({tp,vic}));
      tell_object(vic,"%^RED%^"+tp->query_cap_name()+" bashes you with "
         "POWER!");
      return roll_dice(2,6);
   }
   return roll_dice(1,6);
}
