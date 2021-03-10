#include <std.h>
inherit "/d/common/obj/armour/helm";

#define MAXUSES 1000

int detect, x;

void create() {
   ::create();
   set_name("helm of true sight");
   set_id(({"helm","helm of true sight", "black iron helm", "cold black iron helm" }));
   set_obvious_short("%^BOLD%^%^BLACK%^A cold black iron helm adorned with %^BLUE%^sapphires%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Helm of %^BLUE%^T%^CYAN%^r%^RESET%^%^CYAN%^u"+
       "%^BLUE%^e%^BOLD%^ S%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^g%^CYAN%^h"+
       "%^RESET%^%^CYAN%^t%^RESET%^");
   set_long("%^CYAN%^This helm is made from %^BOLD%^%^BLACK%^cold black iron%^RESET%^%^CYAN%^"+
      ". The design is small and compact, with a streamline styling. The top of the helm is"+
      " smooth and without decoration, as is much of the helm, save for the faceguard."+
      " The %^BOLD%^%^BLACK%^iron %^RESET%^%^CYAN%^rolls down to fit over the forehead,"+
      " eyes, and nose of the wearer. %^BOLD%^%^BLUE%^S%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p"+
      "%^BOLD%^h%^CYAN%^i%^RESET%^%^CYAN%^e%^BLUE%^s%^CYAN%^ are set into two sockets that "+
      "you would imagine is made for the eyes to see through, but you could not imagine how."+
     " Where the metal stops over the nose is the extent of the protection for the face, as "+
     "the rest is left open so the wearer can be heard when speaking.%^RESET%^");
   set_lore("This is the Helm of True Sight. Created by the mercenary Alvin Cortnint. He made "+
      "several in order to keep his employees well equiped to deal with other wizards. The "+
      "key word to the true power of this helm was detect, the rest you do not "+
      "remember.");
   set_property("lore",12);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("sight bonus",5);
   set_value(15000);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

void init() {
	::init();
        add_action("detect","detect");
        x = (int)ETO->query_size();
        add_action("look_at","look");
        set_size(x);
}

int detect(string str) {
	if(TP->query_bound() || TP->query_unconscious() ||TP->query_paralyzed()) 
	{
      	TP->send_paralyzed_message("info",TP);
      	return 1;
   	}
   	if(!query_worn()) return notify_fail("Wear it first.\n");
	if(detect < MAXUSES) 
	{
   		if(!str) return notify_fail("Detect what?\n");
		if(str != "invisibility") return notify_fail("You can not detect that!\n");
		tell_room(ETO,"%^BOLD%^%^BLUE%^The sapphires in the helmet shimmer briefly.",TO);
   		new("/cmds/spells/d/_detect_invisibility")->use_spell(ETO,ETO,50,100,"mage");
   		detect +=1;
  		return 1;
   	}
   	else
   	{
   		tell_object(ETO,"The helm does not have enough power to do that.");
   	}
   	return 1;
}
 
int wearme(){
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The helm doesn't seem to fit you.");
     return 0;
   }
        tell_object(ETO,"%^BOLD%^%^BLUE%^You now see the world"+
        " through the sapphires and everything is clear.");
        return 1;
}

int removeme()
{
        tell_object(ETO,"%^BOLD%^%^CYAN%^As you remove the helm the world"+
        " becomes a shadowed mystery again.");
        return 1;
}

int look_at(string str)
{
        if(!query_worn()) {
                return 0;
        }
        else {
                tell_object(ETO,"%^BOLD%^%^BLACK%^You see everything in shades"+
                " of %^BOLD%^%^BLUE%^b%^RESET%^%^CYAN%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^.");
                return 0;
        }
}
