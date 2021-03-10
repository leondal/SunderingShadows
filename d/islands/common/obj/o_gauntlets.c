// due to several complaints, I changed these from having to be single class, to a level 40 requirement to wear them - 7-21-06 - Ts
// str bonus changed to work on new stat system. Nienne, 09/07. Also lowered to 35, equivalent +5 item.
#include <std.h>;
inherit "/d/common/obj/armour/leather_gauntlets";

void create(){
   ::create();
   set_name("leather gauntlets");
   set_id(({"gauntlets","gauntlets of ogre strength","ogre gauntlets", "leather gauntlets"}));
   set_obvious_short("%^RESET%^%^ORANGE%^A pair of heavy leather gauntlets%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Gauntlets of %^BOLD%^%^BLACK%^O"+
       "%^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^e %^RED%^Strength%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Crafted from a tough thick leather, these "+
	"gauntlets have a %^RED%^wild%^ORANGE%^ and %^BOLD%^%^BLACK%^savage"+
	"%^RESET%^%^ORANGE%^ appearance to them.  The leather itself is "+
	"cracked and worn, showing little care that has been given to these"+
	" gauntlets.  Rough and hard %^BOLD%^%^BLACK%^tattooed%^RESET%^%^ORANGE%^"+
	" lines cut across the leather in a harsh interlocking design, with no"+
	" care for aesthetics. Square shaped %^RESET%^i%^BOLD%^%^BLACK%^r"+
	"%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^ studs have been "+
	"pressed across the hands and fingers of the gauntlets, adding to "+
	"the savage feel.");
   set_value(20000);
   set_lore("Almost any adventures knows of the famed Gauntlets of "+
	"Ogre Strength, though few know how they exactly came about. "+
	" Some seem to think that the gauntlets were made by a barbarian"+
	" shaman of Tempus Foehammer, to honor the physical power of the"+
	" War God.  Others seem to think that the gauntlets were made by "+
	"some crazed wizard who thought to lead a horde of goblinoids, "+
	"orcs, and ogres to crown herself the ruler of all.  No one is "+
	"quite sure what the history of these gauntlets are, only that"+
	" they are always in high demand.");
   set_property("lore",36);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_size(-1);
   set_wear((:TO,"wear":));
   set_remove((:TO,"remove_me":));
   set_item_bonus("strength",4);
   
}

int wear(){
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The gauntlets don't seem to fit you.");
     return 0;
   }
	tell_object(ETO,"%^ORANGE%^You feel a surge of power %^RED%^strengthening"+
		"%^RESET%^%^ORANGE%^ your body as you pull the gauntlets on.%^RESET%^.");
	tell_room(environment(ETO),"%^ORANGE%^Pulling on the leather gauntlets,"+
		" "+ETOQCN+" lets out a slight grunt.",ETO);
   return 1;
}

int remove_me(){
   	tell_object(ETO,"%^ORANGE%^You feel a surge of power %^RED%^leave"+
		"%^RESET%^%^ORANGE%^ your body as you pull the gauntlets off.%^RESET%^.");
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" releases a weary sigh"+
		" as "+ETO->QS+" pulls the gauntlets off.",ETO);
   return 1;
}