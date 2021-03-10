#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("horseshoes");
   set_id(({"horseshoes","steel horseshoes"}));
   set_short("steel horseshoes");
   set_long("A pair of steel horseshoes, simple but sturdy.  Each of the pair "
"forms a neat arc, the ends slightly parted to allow fitting below the front of "
"the hoof.  They have a rough and unfinished look about them, as if they were "
"crafted in haste.");
   set_weight(3);
   set_type("clothing");
   set_limbs(({"left hoof","right hoof"}));
   set_ac(0);
   set_value(10);
}

void init() { // to set valid wear limbs for minoutaurs and centaurs
   if(userp(ETO)) 
   {
     if((string)ETO->query_race() == "centaur")  TO->set_limbs(({"left forehoof","right forehoof"}));
     if((string)ETO->query_race() == "minotaur") TO->set_limbs(({"left hoof","right hoof"}));
   }
}