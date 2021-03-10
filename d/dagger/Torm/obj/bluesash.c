#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("blue silk sash");
   set_short("%^BOLD%^%^CYAN%^Blue silk sash%^RESET%^");
   set_id(({"silk sash","sash","blue silk sash","blue sash"}));
   set_long("%^BOLD%^%^CYAN%^This sash is made out of high quality silk"+
   " that has been dyed a light shade of blue. The ends of the sash have"+
   " been embroidered with aquamarine beads. It is meant to be worn around"+
   " the waist and tied in some fashion.");
   set_weight(1);
set_type("ring");
   set_limbs(({"waist"}));
   set_wear("%^BOLD%^%^CYAN%^You carefully knot the blue silk sash around your waist.");
   set_remove("%^CYAN%^You untie the silk sash and let it hang free.");
   set_value(65);
}
