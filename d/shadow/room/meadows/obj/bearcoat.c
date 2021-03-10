#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("bearskin coat");
   set_short("%^RESET%^%^ORANGE%^Bearskin coat%^RESET%^");
   set_id(({"coat","bearskin coat","bear coat","bear skin coat"}));
   set_long("%^ORANGE%^This is a thick coat made from the hide of a large brown"+
   " bear. The inside of the coat is smooth bearskin that has been"+
   " carefully cleaned and cured. The thick bear fur on the outside"+
   " keeps the wind out and the heat in. It reaches down to the knee.%^RESET%^");
   set_type("clothing");
    set_limbs(({"torso"}));
   set_weight(5);
   set_value(30);
   set_size(random(3)+1);
}
