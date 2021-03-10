#include <std.h>
inherit "/d/common/obj/weapon/large_battle_axe.c";

void create(){
   ::create();
   set_name("wood axe");
   set_short("%^RESET%^%^GREEN%^Wood Axe%^RESET%^");
   set_id(({"axe","ax","wood axe","wood"}));
   set_long(
@OLI
   This is a large wood axe. The voadkyn rangers use it to clear
dead wood that might fall and hurt younger more vigorous trees. When
the forest is threatened however the rangers can take these up
one in each hand and turn to chopping evil rather than dead wood.
OLI
   );

   set_property("enchantment",3);
   set_hit((:TO,"hitme":)) ;
   set_value(75);
}

int hitme(object targ){
   if(!objectp(targ)){
      return random(2);
   }
   if(!random(10)){
      tell_room(environment(query_wielded()),"%^GREEN%^"+ETO->query_cap_name()+" swings the axe in a great chopping motion.",({ETO,targ}));
      tell_object(ETO,"%^GREEN%^You swing the axe in a great chopping motion.");
      tell_object(targ,"%^GREEN%^"+ETO->query_cap_name()+" swings at you with a great chopping motion.");
        return 0;
   }
   return 0;

}


