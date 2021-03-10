#include <std.h>
inherit "/d/common/obj/jewelry/circlet";

void create(){
   ::create();
   set_name("ice tiara");
   set_id(({"tiara","ice tiara","tiara of cold","glistening ice tiara"}));
   set_short("%^RESET%^%^CYAN%^tiara of cold%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^glistening ice tiara%^RESET%^");
   set_lore("This tiara seems to be a"+
   " creation of some kind of curse.  "+
   "The product of a heart so cold that the world around it would freeze. ");
   set_property("lore difficulty",30);
   set_long("%^CYAN%^This tiara is made completely of ice.  "+
   "The fingers of the tiara are icicles.   The "+
   "object seems unable to melt.  The coldness in"+
   " it is such that tends to freeze anything that"+
   " touches it.  This seems unfit to be worn by a living being.%^RESET%^");
   set_size(2);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",5);
   set_item_bonus("cold resistance",5);
   set_item_bonus("fire resistance",-5);
}
int wear_me(){
  tell_object(ETO,"%^CYAN%^You don the tiara and a chill goes down your spine.");
  return 1;
}
