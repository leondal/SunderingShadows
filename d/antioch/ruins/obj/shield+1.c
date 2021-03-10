#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/armour/buckler.c";

string owner;

void create()
{
	::create();
	set_name("scale shield");
	set_short("%^BOLD%^%^CYAN%^S%^BLUE%^e%^RESET%^%^BLUE%^r%^BOLD%^p"+
		"%^CYAN%^e%^RESET%^%^BLUE%^n%^BOLD%^%^CYAN%^t %^BLUE%^Scale"+
		" Buckler%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A blue scaled leather buckler%^RESET%^");
	set_id(({"buckler","scale buckler","serpent scale buckler","Serpent Scale Buckler","serpent_shield1"}));
	set_long(
	"%^BOLD%^%^CYAN%^This shield has been carefully pieced together by an expert craftsman."+
	" The serpent scales have been treated so that they shine with a %^BOLD%^%^BLUE%^sapphire%^CYAN%^"+
	" sparkle. They have been linked together edge to edge, with more scales"+
	" woven behind to give better protection."
	);
	set_type("thiefshield");
	set_limbs(({"right hand"}));
	set_weight(5);
	set_ac(1);
	set_property("enchantment",1);
	set_item_bonus("magic resistance",1);
	set_value(3000);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_struck((:TO,"strike_func":));
}

int wearme()
{
	if(owner != (string)TPQN) {
		tell_object(ETO,"This shield was made for "+owner+" and not for you!");
		return 0;
	}
	tell_object(ETO,"%^CYAN%^You feel confident as you slip the serpent scale"+
	" buckler over your arm.");
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel rather bare and unprotected"+
	" as you remove the buckler.");
	return 1;
}

void set_owner(string str)
{
	owner = str;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+ETO->QCN+""+
		" slaps "+who->QCN+" upside the head with "+ETO->QP+""+
		" buckler.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^You slap "+who->QCN+" upside the "+
		"head with your buckler.");
	tell_object(who,"%^BOLD%^%^CYAN%^"+ETO->QCN+" slaps you upside "+
		"the head with "+ETO->QP+" buckler.");
			who->do_damage("torso",random(5)+1);
}
}
