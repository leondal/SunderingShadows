#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";

   void create(){
   ::create();
   set_name("%^BOLD%^%^WHITE%^Pearl breastplate%^RESET%^");
   set_id(({"plate","pearl breastplate","breastplate"}));
   set_short("%^BOLD%^%^WHITE%^A white breastplate%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is a very pretty breastplate"
" that has been painstakingly covered with thousands of tiny"
" white pearls for decoration.  In the center of the breastplate,"
" %^RESET%^grey %^BOLD%^%^WHITE%^pearls have been arranged into"
" the shape of a seashell, making it nice to look at in addition"
" to the protection it offers.\n%^RESET%^");
   set_value(500);
}
