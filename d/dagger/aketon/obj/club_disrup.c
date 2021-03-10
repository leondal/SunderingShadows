#include <std.h>

inherit WEAPON;

void death_func(object vic);

void create(){
   ::create();

   set_name("club of disruption");
   set_short("Club of disruption");
   set_id( ({"club","disruption","club disruption"}) );
   set_long("This club is made of wood from the deep forest of the Dagger "
      "area. It looks very similar to the ordinary clubs used by many "
      "trolls, yet it radiates a strange magical arua that seems detering "
      "all undead and some ghostly creatures.");
   set_wc(1,6);
   set_size(1);
   set_large_wc(1,3);
   set_type("bludgeoning");
   set_prof_type("holy clublike");
   set_prof_level(25);
   set_weight(6);
   set_value(750);
   set_property("enchantment",3);
   set_property("magic",1);
   set_wield( (: TO,"wield_func" :) );
   set_hit( (: TO,"hit_func" :) );
}

int wield_func() {
   if( !interactive(TP) || wizardp(TP) )
      return 1;
   if( (int)TP->query_level() < 25 ) {
      notify_fail("You are not experienced enough.\n");
      return 0;
   }
   write("A strange feeling flashes through your body.");
   return 1;
}

void death_func(object vic) {
   tell_object(TP,"%^ORANGE%^"+vic->query_cap_name()+" receives a heavy "
      "blow as you strikes with the club!");
   tell_room(ETP,"%^ORANGE%^"+vic->query_cap_name()+" receives a heavy "
      "blow as "+TPQCN+" strikes with "+TP->query_possessive()+" club!",
      ({TP,vic}));
}

int hit_func(object vic) {
   string vic_race;
   if( !objectp(vic) )
      return 0;
   vic_race = vic->query_race();
   if( (int)vic->query_level() < 25 ) {
      switch(vic_race) {
         case "undead":
         case "skeleton":
         case "zombie":
         case "ghoul":
         case "shadow":
         case "wight":
         case "ghast":
            death_func(vic);
            return 10000;
            break;
         case "wraith":
            //well this is actually a save_roll
            if( (random(20)+1) < 20 ) {
               death_func(vic);
               return 10000;
            }
            break;
         case "mummy":
            if( (random(20)+1) < 17 ) {
               death_func(vic);
               return 10000;
            }
            break;
         case "spectre":
            if( (random(20)+1) < 14 ) {
               death_func(vic);
               return 10000;
            }
            break;
         case "vampire":
            if( (random(20)+1) < 11 ) {
               death_func(vic);
               return 10000;
            }
            break;
         case "ghost":
            if( (random(20)+1) < 8 ) {
               death_func(vic);
               return 10000;
            }
            break;
         case "lich":
            if( (random(20)+1) < 5 ) {
               death_func(vic);
               return 10000;
            }
            break;
      }
   }
   if( ALIGN->is_evil(vic) && !interactive(vic) )
      return roll_dice(3,3);
   return roll_dice(2,4);
}
