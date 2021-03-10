//Revamped Leaf Cloak with Lore now - Cy 10/31/05

#include <std.h>
inherit ARMOUR;

#define seasons ({"spring","summer","autumn","winter"})

int j;
string str, season;

void create(){
     	::create();
	j = random(sizeof(seasons));
      season = seasons[j];
	set_lore("Drawing upon the connection to nature and the cycle of the seasons,"+
                 " the natives of Tonerra fashion a series of four cloaks.  Gathering"+
                 " the leaves during each equinox and solstice, the women of Tonerra "+
                 "weave together these impressive cloaks for their hunters and warriors."+
                 "  The famed enchantress of Tonerra then infuses the mystic powers of"+
                 " nature and the island with each cloak, protecting the leaves from "+
                 "decay and rot.  Each of the four cloaks are rumored to also have "+
                 "further powers that can be unlocked with the right ritual - a "+
                 "ritual the natives will never reveal to any outsiders.\n");
   	set_property("lore difficulty",12);
   	set_weight(5);
	set_ac(0);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));  
      set_value(2500);
	set_property("enchantment",3);
	set_type("clothing");
	set_limbs(({"neck"}));
   	switch(season){
case "spring":
	TO->set_long("%^BOLD%^%^GREEN%^This cloak has been made by weaving"+
		" together various small tender l%^YELLOW%^e%^GREEN%^a%^YELLOW%^"+
		"v%^GREEN%^e%^YELLOW%^s%^GREEN%^, like those found on a tree in"+
		" the spring. The leaves are woven in a fashion where"+
		" each individual one can be made out.  They all seem unbroken"+
		" and unblemished, which is odd seeing how they are woven together."+
		" A twisted length of young green vines serves as a way to tie"+
		" the cloak around one's neck.\n%^RESET%^");
   	TO->set_name("cloak of spring's rebirth");
   	TO->set_obvious_short("%^BOLD%^%^GREEN%^A cloak made of small "+
		"b%^YELLOW%^r%^GREEN%^i%^YELLOW%^g%^GREEN%^h%^YELLOW%^t%^GREEN%^"+
		" green leaves%^RESET%^");
   	TO->set_short("%^BOLD%^%^GREEN%^Cloak of %^YELLOW%^S%^GREEN%^p%^YELLOW%^"+
		"r%^GREEN%^i%^YELLOW%^n%^GREEN%^g%^YELLOW%^'%^GREEN%^s "+
		"Rebirth%^RESET%^");
   	TO->set_id(({"cloak","leaf cloak","cloak of spring's rebirth","cloak of leaves"}));
	break;
case "summer":
      TO->set_long("%^RESET%^%^GREEN%^This cloak has been made by weaving"+
		" together various large lush %^BOLD%^%^GREEN%^l%^RESET%^"+
		"%^GREEN%^e%^BOLD%^a%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^"+
		"%^GREEN%^s, like those found on a tree in"+
		" the summer. The leaves are woven in a fashion where"+
		" each individual one can be made out.  They all seem unbroken"+
		" and unblemished, which is odd seeing how they are woven together."+
		" A twisted length of leafy green vines serves as a way to tie"+
		" the cloak around one's neck.\n%^RESET%^");  
   	TO->set_name("cloak of summer's fertility");
   	TO->set_short("%^RESET%^%^GREEN%^Cloak of %^BOLD%^%^GREEN%^S%^GREEN%^u%^BOLD%^m"+
                "%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^'"+
                "%^RESET%^%^GREEN%^s Fertility%^RESET%^");
   	TO->set_obvious_short("%^RESET%^%^GREEN%^A cloak made of lush green leaves%^RESET%^");
   	TO->set_id(({"cloak","leaf cloak","cloak of summer's fertility","cloak of leaves"}));   
      break;
case "autumn":
      TO->set_long("%^RESET%^%^GREEN%^This cloak has been made by weaving"+
		" together various crisp %^RED%^l%^ORANGE%^e%^YELLOW%^a"+
		"%^RESET%^%^RED%^v%^ORANGE%^e%^YELLOW%^s%^RESET%^%^GREEN%^,"+
		" like those found on a tree in the autumn. The leaves "+
		"are woven in a fashion where each individual one can be "+
		"made out.  They all seem unbroken"+
		" and unblemished, which is odd seeing how they are woven together."+
		" A twisted length of %^ORANGE%^woody vines%^GREEN%^ serves"+
		" as a way to tie the cloak around one's neck.\n%^RESET%^");
   	TO->set_name("cloak of autumn's bounty");
   	TO->set_short("%^RESET%^%^GREEN%^Cloak of %^RED%^A%^ORANGE%^u"+
		"%^YELLOW%^t%^RESET%^%^RED%^u%^ORANGE%^m%^YELLOW%^n%^RESET%^"+
		"%^RED%^'%^ORANGE%^s%^GREEN%^ Bounty%^RESET%^");
   	TO->set_obvious_short("%^RESET%^%^GREEN%^A cloak made of %^RED%^a"+
		"%^ORANGE%^u%^YELLOW%^t%^RESET%^%^RED%^u%^ORANGE%^m%^YELLOW%^"+
		"n%^RESET%^%^GREEN%^ leaves%^RESET%^");
   	TO->set_id(({"cloak","leaf cloak","cloak of autumn's bounty","cloak of leaves"}));
      break;
case "winter":
      TO->set_long("%^RESET%^%^GREEN%^This cloak has been made by weaving"+
		" together various withered %^BOLD%^%^WHITE%^l%^RESET%^e"+
		"%^BOLD%^a%^RESET%^v%^BOLD%^e%^RESET%^s%^GREEN%^, like "+
		"those found around a tree in"+
		" the winter.  Thin needles of pine are intermixed with the"+
		" withered white leaves.  The leaves are woven in a fashion where"+
		" each individual one can be made out.  They all seem unbroken"+
		" and unblemished, which is odd seeing how they are woven together."+
		" A twisted length of %^RESET%^withered vines%^GREEN%^ serves as a way to tie"+
		" the cloak around one's neck.\n%^RESET%^");
   	TO->set_name("cloak of winter's rest");
   	TO->set_short("%^RESET%^%^GREEN%^Cloak of %^BOLD%^%^WHITE%^W%^RESET%^"+
		"i%^BOLD%^n%^RESET%^t%^BOLD%^e%^RESET%^r%^BOLD%^'%^RESET%^s "+
		"%^GREEN%^Rest%^RESET%^");
   	TO->set_obvious_short("%^RESET%^%^GREEN%^A cloak made of %^RESET%^withered white"+
                "%^GREEN%^ leaves%^RESET%^");
   	TO->set_id(({"cloak","leaf cloak","cloak of winter's rest","cloak of leaves"}));
      break;
	}
}
int wear_func(){
	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" looks"+
		" pensive and thoughtful as "+ETO->QS+" slips on a leafy cloak.",ETO);
     	tell_object(ETO,"%^BOLD%^%^GREEN%^You slip the cloak on, "+
		"feeling like you have a deeper connection to nature.%^RESET%^");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" frowns "+
		"deeply as "+ETO->QS+" removes the leafy cloak from"+
		" "+ETO->QP+" shoulders.",ETO);
     	tell_object(ETO,"%^GREEN%^Slipping the cloak off, you feel "+
		"like your deeper connection to nature has been broken.");
     	return 1;
}
