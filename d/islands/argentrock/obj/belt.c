#include <std.h>
inherit "/d/common/obj/clothing/belt";

void create(){
   ::create();
   set_name("athlete's belt ");
   set_id(({"belt","leather belt","athlete's belt","patterned leather
belt"}));
   set_obvious_short("%^RESET%^pa%^ORANGE%^tt%^RESET%^erned l%^ORANGE%^ea%^RESET%^ther b%^ORANGE%^e%^RESET%^lt");
   set_short("%^RESET%^at%^ORANGE%^hl%^RESET%^ete's b%^ORANGE%^e%^RESET%^lt");
   set_lore("This belt is no doubt a fey'ri work.  Fey'ri"+
   " leather workers often compare themselves to the animals"+
   " in the forest.  In the case of this belt, it invokes "+
   "the spirit of the woodland creatures to add"+
   " physical prowess to the wearer.  ");
   set_property("lore difficulty",30);
   set_long("%^ORANGE%^This is a complex leather belt with "+
   "a %^BOLD%^large bronze rune%^RESET%^%^ORANGE%^ for the "+
   "buckle.  The leather has several patterns etched into it."+
   "  These patterns looks like the %^GREEN%^forest%^ORANGE%^"+
   " with lines that seem similar to tree branches and leaves."+
   "  There are several brands of animals in them like "+
   "%^ORANGE%^deer %^GREEN%^and %^ORANGE%^jaguars. ");
  
   set_size(-1);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",5);
   set_item_bonus("athletics",3);
}

int wear_me(){ 
  tell_object(ETO,"%^ORANGE%^You buckle up the belt and feel like %^RESET%^running%^ORANGE%^ a
marathon.");
  return 1;
}
