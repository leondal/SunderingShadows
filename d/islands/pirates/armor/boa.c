// OK, was going ot change these but seems they're just alternate-flavor items for fullplate so leaving alone... Nienne, 09/08.
#include <std.h>
inherit "/std/armour";

void create() {
   ::create();
   set_name("bracers");
   set_id(({"bracers","armor","bracers of armor"}));
   set_obvious_short("plated bracers");
   set_short("Bracers of Armor");
   set_long(
      "These bracers are made from plates of steel. The plates have been curved"+
      " and pieced together to form these remarkably durable and heavy guards."+
      " The bracers are slightly longer than average bracers, covering the wearer's"+
      " wrist and running along the forearm all the way to the elbow."
   );
   set_weight(50);
   set_value(1000);
   set_type("armour");
   set_limbs(({"torso"}));
   set_ac(1);
}
