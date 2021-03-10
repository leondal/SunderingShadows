#include <std.h>
#include <move.h>
#include "/d/common/common.h"
#define VALUE 200

inherit "/d/common/obj/potion/healing.c";

void create() {
  ::create();
   set_name("bluish-white vial");
   set_short("A kit of bluish-white healing vials");
   set_id(({"bluish-white","vial","potion","kit","kitxyz","bluish-white healing vials","bluish-white vials"}));
   set_value(VALUE);
  set_long("%^CYAN%^The pale bluish-white liquid contained in this kit's "
"vials is smooth but bitter. %^YELLOW%^The case can hold "
      "many vials, each one slipping into a pocket where tubes poke "
      "through valved holes in the cork.  The tubes from each vial are "
      "connected to a central one, allowing the user to quickly <quaff>"
      "or <drink> several doses by tipping it up or simply sucking the "
      "liquid through the central tube.  There seems to be a small "
      "flapper inside the drinking tube that prevents the potion from "
      "seeping out but gives way under suction or when held for drinking"
      "seeping out but gives way under suction or when held for drinking.  "
"You will find the case itself will vaporize if all the vials are emptied."
"\nYou can <take # from kit> to split up the kit or you can "
 "<combine kit with kit #> to combine two kits.");
set("color", "bluish-white");
}

int new_do_effect(object drinker) {
   if(!objectp(drinker)) return 1;
   tell_object(drinker, "The potion seems to cool your body.");
   drinker->add_hp((int)drinker->query_max_hp()/10);
  return 1;
}
