#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("dark gauntlets");
   set_short("A pair of dark gauntlets");
   set_id(({"gauntlets","pair of dark gauntlets","dark gauntlets"}));
   set_long("These are a pair of mithril gauntlets that have been "+
      "infused with the ash of cremated slaves, giving it a dark, "+
      "ominous feel.  They are typically worn by the Dark Order of "+
      "Knights.  The inside is lined with a gray cotton, and the gauntlets "+
      "have been highly polished and are in good shape.");
   set_weight(2);
   set_value(10);
   set_ac(1);
   set_type("armor");
   set_limbs(({"right hand","left hand"}));
   set_wear("%^BOLD%^%^BLACK%^The blackened mithril conforms to your hands.");
   set_remove("You slide your hands out of the mithril gauntlets.");
}
