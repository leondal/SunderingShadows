//Changed to use Ares' new strength code - Cythera 6/06
//Cap changed to 15, due to enchantment level update Octothorpe 5/11/09
#include <std.h>
inherit "/std/armour";
#include "/d/antioch/ruins/ruins.h"

void create() {
	::create();
   	set_name("bracelets");
	set_short("%^BOLD%^%^CYAN%^Bracelets of %^BLUE%^P"+
		"%^CYAN%^o%^BLUE%^w%^CYAN%^e%^BLUE%^r%^RESET%^");
     	set_obvious_short("%^BOLD%^%^CYAN%^A pair of light blue metal bracelets%^RESET%^");
  	set_id(({"bracelets","bracelets of power","Bracelets of Power"}));
        set_property("repairtype",({ "jewel" }));
        set_long(
	"%^BOLD%^%^CYAN%^These bracelets are made of a lovely sky blue metal,"+
	" power almost seems to flow through them as you watch. They are each"+
	" an inch wide at least and are perfect circles, exactly alike. %^RESET%^"
	);
	set_lore("Credited to a human enchanter by the name of Marco "+
		"Kanius, the bracelets of power were crafted to aid his "+
		"fellow friends and allies against the forces of darkness."+
                "  Marco realized the problems that would ensue should "+
                "those dark of heart and soul ever find a pair of his "+
		"bracelets.  Calling upon his arcane might, and with a "+
		"prayer to Mystra, Marco was able to further enchant the "+
		"bracers to only bond with those pure of heart and soul.  "+
		"Others it seems though were jealous of Marco's creation "+
		"and sought to steal his research notes to create their "+
		"own artifacts of power.  An attack on Marco's tower on "+
		"the cold winters night of the 14th of Colddays 547 "+
		"caused a massive explosion that destroyed the tower and"+
		" its owner.  No one knows if the forces working against"+
		" Marco in the creation of similar bracelets of power "+
		"were able to retrieve his notes or not.");
	set_property("lore",14);
	set_weight(5);
	set_value(2000);
	set_ac(0);
	set_size(-1);
	set_property("enchantment",3);
	set_item_bonus("strength",1);
	set_type("clothing");
	set_limbs(({"left arm","right arm"}));
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme() {
    if(ALIGN->is_evil(ETO)) {
      tell_object(ETO,"The bracelets will not be worn by someone with your evil nature!");
      return 0;
    }
    if(ETO->query_property("evil item")) {
       tell_object(ETO,"The bracelets refuse to be worn while you're using such evil items.");
       return 0;
    }
    if(ETO->query_highest_level() < 15) {
      tell_object(ETO,"You are not experienced enough to use this equipment.");
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^CYAN%^You feel the bracelets strengthen your arms as"+
	" you slip them over your wrists.");
    ETO->set_property("good item",1);
	return 1;
}

int removeme() {
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel weak once more as you remove"+
	" the bracelets.");
    ETO->set_property("good item",-1);
	return 1;
}