//basic mage robes by ~Circe~
//converted from 1AC to +1, nienne 05/07
#include <std.h>

inherit "/d/common/obj/clothing/magerobe.c";

#define COLORS ({"%^BOLD%^%^WHITE%^snow white",\
"%^BOLD%^%^RED%^crimson red",\
"%^RED%^scarlet red",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^GREEN%^forest green",\
"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^BLUE%^royal blue",\
 "%^BLUE%^midnight blue", \
"%^YELLOW%^sunshine yellow",\
"%^ORANGE%^tan",\
"%^ORANGE%^dark orange",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^BOLD%^%^CYAN%^teal green",\
"%^MAGENTA%^dark violet",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^BOLD%^%^BLACK%^raven black",\
"%^BOLD%^%^CYAN%^sea green",\
"%^BOLD%^%^WHITE%^pale cream",\
"%^RESET%^smokey gray"})

void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
    	set_name("robe");
    	set_id(({"robe","armor","robes","mage robes"}));
    	set_short("%^RESET%^"+COLOR+" cotton robes%^RESET%^");
    	set_long("These simple robes are made of layered "+COLOR+" "+
         "cotton%^RESET%^.  Each layer is a slightly different shade, "+
         "giving the robes added depth.  The robes feature two "+
         "large pockets lined with matching "+COLOR+" silk%^RESET%^, "+
         "perfect for keeping items close at hand.  While not overly "+
         "elaborate, the robes are well-made and look as though they "+
         "would offer some amount of protection.");
    set_lore("While appearing to be but a simple robe, these robes "+
         "actually feature a minor enchantment that keeps them solely "+
         "for the use of those who practice the arcane arts.  This "+
         "cantrip is known by all magi who craft items, and they "+
         "use it as a way to keep those things that benefit them "+
         "out of the hands of warriors and rogues.");
    set_property("lore difficulty",8);
    set_size(random(3)+1);
    set_weight(5);
    set_value(215);
    set_type("clothing");
    set_limbs(({"torso"}));
   set_property("enchantment",1);
//    set_ac(1);
    set_max_internal_encumbrance(21);
    set_wear((:TO,"wear_stuff":));
}

int wear_stuff(){
   if(!TP->is_class("bard") && !TP->is_class("psion") && !TP->is_class("mage") && !TP->is_class("sorcerer")) {
      tell_object(ETO,"%^BOLD%^%^RED%^The magic within these robes "+
         "prevents you from wearing them.");
      return 0;
   }
   return 1;
}
