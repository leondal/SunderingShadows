#include <std.h>

inherit "/d/common/obj/clothing/belt.c";



void create(){
   ::create();
   set_name("seaweed belt");
   set_id(({ "belt", "seaweed", "seaweed belt" }));
   set_short("%^RESET%^%^GREEN%^S%^CYAN%^e%^GREEN%^aweed Belt");
   set_obvious_short("%^RESET%^%^GREEN%^S%^CYAN%^e%^GREEN%^aweed belt");
   set_long("This belt refused to decay.  Most of the "+
   "leather and stitching is torn.  The belt seems to "+
   "have willed itself to remain in one piece by holding"+
   " together with strips of seaweed.  It gives of a resentful aura.");
   set_value(1000);
   set_lore("This belt is vaguely seemed to be the "+
   "craft of a long gone human empire that once "+
   "flourished in the area of danger.   It ended "+
   "suddenly by some kind of earthquake or flood. "+
   " Only the style of the buckle gives hint as to the origin.");
   set_size(-1);
   TO->set_property("enchantment",4+random(2));
   set_item_bonus("survival",2);
   set_item_bonus("electricity resistance",-5);
   set_item_bonus("charisma",-1);
   set_item_bonus("slashing resistance",10);

}
