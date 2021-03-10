#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/brewing/herb_special_inherit";

void create(){
   ::create();
   set_herb_name("spirit essence");
   set_name("spirit essence");
   set_id(({"essence","Essence","spirit's essence","spirit essence","ball of fog","fog"}));
   set_short("%^BLACK%^%^BOLD%^s%^RESET%^%^WHITE%^pi%^BLACK%^%^BOLD%^r%^RESET%^%^WHITE%^it %^BLACK%^%^BOLD%^e%^RESET%^%^WHITE%^ss%^BLACK%^%^BOLD%^e%^RESET%^%^WHITE%^nc%^BLACK%^%^BOLD%^e%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^ball of fog%^RESET%^");
   set_long("%^GREEN%^This %^WHITE%^hazy%^GREEN%^ ball of fog is only partly substancial, and is almost "
"impossible to keep hold of.  The smoke around it is constantly in motion, swirling around the core, "
"which is the only near-solid portion of the essence.%^RESET%^");
   set_value(1240);
   set_weight(1);
   set_lore("%^WHITE%^%^BOLD%^Portions of a spirit like this are often disregarded as mere smoke, and "
"indeed most people have no use for them.  However, they are particularly valuable items to certain "
"magi, particularly necromancers, and they will often pay quite a decent sum to obtain such samples for "
"various experiments.%^RESET%^");
   set_property("lore difficulty",14);
}
