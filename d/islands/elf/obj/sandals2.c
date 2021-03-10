#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
   ::create();
   set_name("ice sandals");
   set_id(({"sandal","sandals","ice sandals","frozen sandals"}));
   set_short("%^RESET%^%^MAGENTA%^ice sandals%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^frozen sandals%^RESET%^");
   set_lore("This footwear looks like sandals made out of ice."+
   "  They are extremely cold to the touch.  The Straps are"+
   " not solid they have some give to them.  This seems odd "+
   "because they are translucent ice.  ");
   set_property("lore difficulty",30);
   set_long("%^MAGENTA%^These sandals are a byproduct "+
   "of the frozen maidens that haunt glaciers.  The "+
   "intense cold that curses the island embodies these"+
   " items of clothing.  As such they seem to have a "+
   "bit of power to them to resist the cold..%^RESET%^");
  
   set_size(1+random(3));
   set_value(2000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",3);
   set_item_bonus("cold resistance",5);
}

int wear_me(){ 
  tell_object(ETO,"%^CYAN%^You slip your feet into the sandals and they chill your feet.");
  return 1;
}
