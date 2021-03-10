#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("pearl anklet");
   set_short("%^BOLD%^%^WHITE%^Pearl Anklet%^RESET%^");
   set_id(({"pearl anklet","anklet"}));
   set_long("%^BOLD%^This is a delicate anklet made out of a double strand"+
   " of tiny white pearls. There is a %^YELLOW%^gold clasp%^WHITE%^ that"+
   " fastens it around your ankle.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"left leg"}));
   set_wear("%^BOLD%^You carefully fasten the pearl anklet.");
   set_remove("%^YELLOW%^You undo the gold clasp and remove the anklet.");
   set_value(325);
   set_size(random(3)+1);
}
