//Octothorpe (4/9/10)
//Faerzess Solution
//Based on Wizard Oil by Ares
///d/avatars/ares/wizard_oil.c

#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_id(({"phial","faerzress solution"}));
   set_obvious_short("%^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^"+
      "ck m%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^a%^BOLD%^%^BLACK%^l "+
      "ph%^RESET%^ia%^BOLD%^%^BLACK%^l%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^ph%^RESET%^ia%^BOLD%^BLACK%^l of "+
      "%^MAGENTA%^f%^RESET%^%^MAGENTA%^ae%^BOLD%^rzr%^RESET%^%^MAGENTA%^"+
	  "e%^BOLD%^ss %^BOLD%^%^BLACK%^solution%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This long, metal phial measures about a "+
      "foot in length and is quite warm to the touch.  Inside the phial "+
	  "small flakes of a curious %^BOLD%^%^MAGENTA%^gl%^RESET%^"+
	  "%^MAGENTA%^o%^BOLD%^w%^RESET%^%^MAGENTA%^i%^BOLD%^ng p%^RESET%^"+
	  "%^MAGENTA%^u%^BOLD%^rpl%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLACK%^"+
	  "material are suspended in a %^RESET%^%^RED%^red %^BOLD%^"+
	  "%^BLACK%^solution.%^RESET%^");
   set_lore("Phials such as this have been seen in the inventory of "+
      "Jezulfin in Seneca recently.  It is said that it is a product "+
	  "of the Underdark, and is being smuggled to the surface with some "+
	  "regularity.  It is unknown how exactly Jezulfin is able to get "+
	  "his hands on it, but it is obvious that it is done at great "+
	  "monetary expense.  Supposedly the contents of the phial are able "+
	  "to arrest the decay of some drowish artifacts that occurs when "+
	  "they are removed from the Underdark.  By %^BOLD%^apply%^RESET%^ing "+
	  "the solution on the item, the physical and magical integrity of "+
	  "the item should be restored temporarily, in most cases.");
   set_weight(3);
   set_value(0);
}

void init(){
   ::init();
   add_action("apply","apply");
   return;
}

//Borrowing following from Wizard Oil - Octothorpe 4/11/10
int apply(string str){
   object target;
   if(!stringp(str)){
      tell_object(TP,"%^BOLD%^You need to choose something to apply "+
	     "the solution to.%^RESET%^");
	  return 1;
   }
   str = replace_string(str,"to ","");
   if(!objectp(target = present(str,TP))){
      tell_object(TP,"%^BOLD%^You don't have a "+str+" in your inventory.%^RESET%^");
	  return 1;
   }
   if((int)target->query_property("phialable") != 1){
      tell_object(TP,"%^BOLD%^You don't think this solution will do "+
	     "much on this item.%^RESET%^");
	  return 1;
   }
   tell_object(TP,"%^RED%^As you uncork the phial, the red solution "+
      "shoots out of the container and spreads all over the "+
	  ""+target->query_short()+".%^RESET%^");
   tell_room(ETP,"%^RED%^"+TP->QCN+" uncorks the phial, allowing the "+
      "red solution inside to spread all over "+TP->QP+" "+
	  ""+target->query_short()+".%^RESET%^",TP);
   target->reset_counter();
   target->set_overallStatus(100);
   if((int)target->query_property("enchantment") < 5){
      target->remove_property("enchantment");
	  target->set_property("enchantment",5);
   }
   TO->remove();
   return 1;
}