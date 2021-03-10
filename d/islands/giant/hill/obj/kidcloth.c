#include "/d/islands/giant/giant.h"

inherit "/std/armour";

void create(){
   ::create();
   set_name("rags");
   set_id(({"rags","hides","clothes"}));
   set_short("Children's Clothes");
   set_long(
@TERRATO
   THese are the tattered rags the hill giant children call clothes.
they offer little or no protection in battle.  They are merely the
discarded hides that the adults no longer need.
TERRATO
   );
   set_weight(10);
   set_value(5);
   set_type("clothes");
   set_limbs(({"torso"}));
   set_ac(1);
   set_size(3);
}
