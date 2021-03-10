//greenrobe.c

#include <std.h>

inherit PARMOUR;

void create(){
   ::create();
   set_name("bright green robes");
   set_id(({"robe","robes","green robes","bright green robes","mage robes"}));
   set_short("%^BOLD%^%^GREEN%^bright green robe%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^These robes are made from an elegant "+
      "yet unknown fabric.  They are long and flowing and are lined "+
	  "with a metallic %^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e"+
	  "%^RESET%^r %^BOLD%^%^GREEN%^thread.  There are various "+
	  "pockets found within the folds of the robe, no doubt "+
	  "allowing one to secret away various object of import.%^RESET%^");      
   /*set_long(
@OLI
These robes are made from a metallic green material. The robe seems
to offer some protection to the wearer. There is a small pocket in
these robes where you can store something. It looks like it is made
for a book or a bag or something light.
OLI
   );*/
   set_property("enchantment",2);
   set_weight(5);
   set_value(300);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_max_internal_encumbrance(21);
   //set_wear((:TO,"wear_stuff":));
}
