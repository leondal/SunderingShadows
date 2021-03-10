//Coded by Bane//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"two handed sword","sword"}));
   set_name("two handed sword");
   set_short("A two handed sword");
   set_long(
       "This is a shiny, well kept two handed sword. "
   );
   set_weight(15);
   set_size(3);
  set_value(800);
   set_wc(1,10);
   set_large_wc(3,6);
   set_type("slash");
    set_property("enchantment",3);
}
