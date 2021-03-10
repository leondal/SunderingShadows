#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/armour/hide.c";

string owner;

void create()
{
	::create();
	set_name("serpent skin");
	set_short("%^BOLD%^%^BLUE%^A ball of serpent scales%^RESET%^");
	set_id(({"serpent skin","ball","ball of scales","skin","hide","serpent hide","serpent_hide"}));
	set_long("%^BOLD%^%^CYAN%^This ball of serpent scales is "+
		"tightly wound.  Able to fit in ones hands the light blue"+
		" scales shimmer with %^BLUE%^d%^RESET%^%^BLUE%^e%^BOLD%^e"+
		"%^RESET%^%^BLUE%^p%^BOLD%^e%^RESET%^%^BLUE%^r%^BOLD%^ "+
		"blue%^CYAN%^ shades.%^RESET%^\n");
	set_lore("The Serpent Skin is a creation of Antioch's famed"+
		" Tanner, Mydan.  Mydan is said to often create odd "+
		"suits of armor from rare and unique skins and hides"+
		" that people find.  This hide is rumored to have come"+
		" from Svrrl, the Immortal Serpent of Antioch, some "+
		"claim.  They say that Svrrl was a left over experiment"+
		" of a mage of Old Antioch, those some whisper that she "+
		"is really a creature from another plane, forever trapped"+
		" here.");
	set_property("lore",13);
   set_property("enchantment",3);
	set_item_bonus("magic resistance",7);
	set_value(5000);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	if(owner != (string)TPQN) {
		tell_object(ETO,"This hide armor was made for "+owner+", not you!");
		return 0;
	}
		tell_object(ETO,"%^BOLD%^%^BLUE%^The ball begins to uncoil"+
			" and wrap around your body, offering you their protection.");
		tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The ball of %^CYAN%^"+
			"serpent scales%^BLUE%^ in "+ETOQCN+"'s hands begins to "+
			"expand and uncoil, wraping around "+ETO->QP+" torso "+
			"tightly!",ETO);
		set_short("%^BOLD%^%^CYAN%^S%^BLUE%^e%^RESET%^%^BLUE%^r"+
			"%^BOLD%^%^CYAN%^p%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^"+
			"n%^CYAN%^t%^BLUE%^'%^RESET%^%^BLUE%^s%^BOLD%^%^CYAN%^"+
			" Skin%^RESET%^");
		set_obvious_short("%^BOLD%^%^CYAN%^A suit of serpent scaled armor");
		set_long("%^BOLD%^%^BLUE%^This suit of torso armor is unlike any"+
			" armor you have seen before.  The %^CYAN%^light blue%^BLUE%^ "+
			"scales wrap around ones body, in a serpentine fashion.  "+
			"The bands of leather are spaced out evenly, never fully "+
			"encasing ones body.  In fact the armor allows the garments"+
			" one wears under the leather to be seen, somewhat.  The scales"+
			" of are %^CYAN%^light blue%^BLUE%^ in color, though have a "+
			"%^RESET%^%^BLUE%^deeper blue%^BOLD%^ luster over them.  "+
			"The scales are tightly woven together offering solid "+
			"protection, while being lightweight and very flexible.  "+
			"The armor looks very comfortable. \n%^RESET%^");
		return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^%^BLUE%^The scales slide off of your body"+
		" and begin to coil up into a ball.");
        tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s armor begins to slither off"+
		" of "+ETO->QP+" body and coil itself into a ball!",ETO);
			set_short("%^BOLD%^%^BLUE%^A ball of serpent scales%^RESET%^");
			set_long("%^BOLD%^%^CYAN%^This ball of serpent scales is "+
				"tightly wound.  Able to fit in ones hands the light blue"+
				" scales shimmer with %^BLUE%^d%^RESET%^%^BLUE%^e%^BOLD%^e"+
				"%^RESET%^%^BLUE%^p%^BOLD%^e%^RESET%^%^BLUE%^r%^BOLD%^ "+
				"blue%^CYAN%^ shades.%^RESET%^\n");
	return 1;
}

void set_owner(string str)
{
	owner = str;
}
