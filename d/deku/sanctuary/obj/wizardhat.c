//changed by Circe to be mage only on Shar's request - 10/25/03
//After talking to Dinji - Combined all wizardhats into file with random chance of colors - Cytehra 3/05
//removed AC point - cloth hat. nienne, 05/07
#include <std.h>
inherit ARMOUR;
#define COLORS ({"%^BOLD%^%^BLACK%^pitch black","%^BOLD%^%^WHITE%^snow white","%^BOLD%^%^RED%^cardinal red","%^RESET%^%^RED%^blood red","%^BOLD%^%^BLUE%^bright blue","%^RESET%^%^BLUE%^midnight blue","%^BOLD%^%^RED%^crimson","%^RESET%^%^RED%^scarlet red","%^BOLD%^%^BLUE%^royal blue","%^BLUE%^navy blue","%^BOLD%^%^BLACK%^jet black","%^BOLD%^%^BLACK%^charcoal gray","%^BOLD%^%^WHITE%^ghostly white","%^BOLD%^%^WHITE%^brilliant white"})
int j;
string str, COLOR;

void create(){
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	set_name("wizard's hat");
	set_id(({ "hat", "wizard hat" }));
        set_short("%^RESET%^%^CYAN%^A "+COLOR+"%^RESET%^%^CYAN%^ suede wizard's hat%^RESET%^");
        set_long("%^CYAN%^This "+COLOR+" %^RESET%^%^CYAN%^hat is modelled after the "+
		"classical wizard's hat.  The tall conical hat is made out of"+
                " "+COLOR+" %^RESET%^%^CYAN%^suede.  The body of the hat itself is rather"+
		" soft, allowing it to drape in soft folds, though the point at "+
		"the top still remains very stiff and straight.  A wide brim helps"+
		" to shield the wearer from the elements and bright lighting.  "+
                "A matching "+COLOR+" %^RESET%^%^CYAN%^velvet band with a decorative %^YELLOW%^"+
		"brass %^RESET%^%^CYAN%^buckle is set in the center of the hat, "+
		"where the crown meets the brim.\n%^RESET%^");
	set_weight(3);
	set_value(1500);
	set_lore(
@AVATAR
These types of hats are often found among various wizards, who like to dress to impress.  The style of the hat is a classical one, one that every man, woman and child knows.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
      if((ETO->is_class("mage")) && (!ETO->is_class("cleric")) && (!ETO->is_class("fighter")) && (!ETO->is_class("thief"))){
	tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^CYAN%^You place the "+COLOR+"%^RESET%^%^CYAN%^ suede hat on your head, topping off your wizard's apparel.");
	return 1;
      }
	if((string)ETO->id("kelun")){ 
	return 1;
	} 
      tell_object(ETO,"The wizard hat refuses to sit right upon your head!");
      return 0;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^CYAN%^%^You remove the "+COLOR+"%^RESET%^%^CYAN%^ suede hat, and feel less like a wizard.");
	return 1;
}