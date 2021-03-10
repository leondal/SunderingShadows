#include "/d/dagger/aketon/short.h"

inherit WEAPON;

string owner;

void create() {
   ::create();
   set_name("dagger of deceit");
   set_id( ({"dagger","deceit","deceiver","dagger of deceit"}) );
   set_short("%^RESET%^%^BLUE%^Dagger of deceit");
   set_long("%^BLUE%^This dagger is almost entirely black in color "
      "except the shiny, silver pointing tip. A weird symbol of a dancing "
      "clown is carved into the surface of the blade. You can feel the "
      "strong black magic arua from the dagger.");
   set_weight(3);
   set("value",350);
   set_wc(1,4);
   set_large_wc(1,3);
   set_size(1);
   set_type("piercing");
   set_property("enchantment",2);
   set_wield( (: TO,"wield_func" :) );
   set_hit( (: TO,"hit_func" :) );
   set_prof_type("deceiver");
}

int hit_func(object vic) {
   object tp = query_wielded();
   if(!random(50) && tp->is_class("thief") ) {
      set_property("magic",1);
       tell_object(tp,"You successfully move yourself into a position "
         "exposing "+vic->query_cap_name()+"'s back.\n%^BOLD%^"+
         vic->query_cap_name()+" was obviously watching "+
         vic->query_possessive()+" back and catches you.");
      tell_room(environment(tp),tp->query_cap_name()+" has positioned "
         +tp->query_objective()+"self behind "+vic->query_cap_name()+
         "'s back.\n%^BOLD%^You see "+tp->query_cap_name()+" miss a back "
         "stab attempt on "+vic->query_cap_name()+".",({tp,vic}));
      tell_object(vic,"You suddenly notice that "+tp->query_cap_name()+
         " has moved and your back is exposed.\n%^BOLD%^"+
         tp->query_cap_name()+" stabs you in the back!");
      return roll_dice(8,tp->query_class_level("thief"));
      remove_property("magic");
   }
   if(!random(10)) {
      tell_object(tp,"%^BLUE%^You almost fumble with your dagger!");
      tell_room(environment(tp),"%^BLUE%^You see "+tp->query_cap_name()+
         " hurts "+tp->query_objective()+"self as "+tp->query_subjective()+
         " fumbles with the dagger.",({tp,vic}));
      tell_object(vic,"%^BLUE%^"+tp->query_cap_name()+" slashes "+
         tp->query_possessive()+" dagger into your flash!");
      return roll_dice(3,4);
   }
   return roll_dice(2,4);
}

int wield_func() {
   if(!interactive(TP))
      return 1;
   if( (int)TP->query_level() < 15 ) {
      notify_fail("%^BLUE%^Be gone puny one!\n");
      return 0;
   }
   if( (string)TPQN != owner ) {
      write("%^BLUE%^You are not the chosen one.");
      TO->remove();
      return 0;
   }
   return 1;
}

void init() {
   ::init();
   if(interactive(TP) && TP == ETO && !owner)
   owner = TPQN;
}
