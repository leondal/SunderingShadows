//bow for archers
#include <std.h>
inherit "/d/common/obj/lrweapon/longbow";

create(){
   ::create();
   set_id(({ "long bow","longbow", "bow","elven longbow","masterwork bow" }));
   set_name("elven longbow");
   set_short("%^RESET%^%^GREEN%^An elven longbow%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^A fine bow%^RESET%^");
   set_long("%^ORANGE%^This bow is created from a light wood. "+
   " It is almost %^YELLOW%^gold%^RESET%^ %^ORANGE%^in hew.  The whole bow is "+
   "elegantly etched with patterns of animals, "+
   "plants and the seasons.  These patterns seem "+
   "placed exactly as if to form runes.   The bow "+
   "almost seems to %^YELLOW%^sparkle%^RESET%^%^ORANGE%^ in light.%^RESET%^");
      set("value", 120);
	  set_property("lore difficulty",35);
	  set_property("enchantment",2); 
	  set_lore("This is undoubtedly a master crafted "+
	  "longbow from an elven woodworker.  There are "+
	  "telling signs that this bow was created in the "+
	  "gold elf fashion.  The bow bears the insigna of "+
	  "Ashta'Rathai a gold elf citadel that was"+
	  " run by a vanished clan.");
}
