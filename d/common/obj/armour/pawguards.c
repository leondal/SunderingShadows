#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("pawguards");
   set_id(({"pawguards","leather pawguards"}));
   set_short("leather pawguards");
   set_long("A pair of leather pawguards, simple but sturdy.  Each of the two "
"forms a sturdy protection, fitted to cover a pair of lion-size paws with an "
"anklet to secure them above the foot.  They have a rough and unfinished look "
"about them, as if they were crafted in haste.");
   set_weight(3);
   set_type("leather");
   set_limbs(({"left forepaw","right forepaw"}));
   set_ac(0);
   set_value(10);
}
