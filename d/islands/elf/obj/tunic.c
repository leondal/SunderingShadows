//shirt for vamp elf coded by hades 9/26/20
#include <std.h>

inherit "/d/common/obj/clothing/magerobe.c";

void create(){
   ::create();
   set_name("Noble's Tunic");
   set_id(({"tunic","noble's tunic","green robes","bright green robes","mage robes"}));
   set_short("%^BOLD%^%^GREEN%^bright green robe%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^These robes are made from an elegant "+
      "yet unknown fabric.  They are long and flowing and are lined "+
	  "with a metallic %^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e"+
	  "%^RESET%^r %^BOLD%^%^GREEN%^thread.  There are various "+
	  "pockets found within the folds of the robe, no doubt "+
	  "allowing one to secret away various object of import.%^RESET%^");   

   set_lore("This is rumored to be in a style of elven nobles worn"+
   " long ago.  This one likely was worn by a diplomat.  "+
   "Gold elf diplomats were both regal and capable.");   

   set_property("enchantment",4+random(3));
   set_item_bonus("charisma",2);
   set_item_bonus("influence", 2);
   set_wear((: TO, "wearme" :));
   set_remove((: TO, "removeme" :));
}

int wearme()
{
    tell_object(ETO, "%^GREEN%^You pull the tunic on and feel important.");
    return 1;
}
int removeme()
{
    tell_object(ETO, "%^GREEN%^You feel like a filthy commoner without the tunic on.");
    return 1;
}

