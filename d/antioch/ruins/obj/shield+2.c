#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/armour/shield.c";

string owner;

void create()
{
	::create();
	set_name("serpent scale shield");
	set_short("%^RESET%^%^BLUE%^Shield of %^BOLD%^S%^CYAN%^e%^BLUE%^"+
		"r%^CYAN%^p%^BLUE%^e%^CYAN%^n%^BLUE%^t %^RESET%^%^BLUE%^"+
		"Scales%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^A steel shield with %^BOLD%^blue scales%^RESET%^");
	set_id(({"shield","serpent scale shield","shield of serpent scales","scale shield","serpent shield","Shield of Serpent Scales","serpent_shield2"}));
	set_long("%^BOLD%^%^BLUE%^This round shield is framed in "+
		"%^WHITE%^br%^CYAN%^ig%^WHITE%^ht %^CYAN%^st%^WHITE%^ee"+
		"%^CYAN%^l%^BLUE%^, from which large serpent scales are "+
		"attached to it. The scales are laid out in an overlapping"+
		" pattern, and are tightly fastened to the shield. The "+
		"%^RESET%^%^BLUE%^dark blue%^BOLD%^ scales look very clean"+
		" and well cared for.  A steel band wraps around the outer "+
		"edge of this medium shield, adding further protection.  "+
		"The steel is engraved with images of interlocking serpents "+
		"of %^RESET%^dark blue%^BOLD%^.  A cabochon cut %^CYAN%^blue "+
		"topaz%^BLUE%^ is set into the center of the shield, encased "+
		"in a %^WHITE%^br%^CYAN%^ig%^WHITE%^ht %^CYAN%^st%^WHITE%^ee"+
		"%^CYAN%^l%^BLUE%^ mounting.");
	set_lore("The Serpent Shield is said to have been made from the "+
		"scales from the Immortal Serpent, Svrrl.  Svrrl is rumored "+
		"to be a planar creature trapped here by a wizard of Old Antioch."+
		"  With the city in ruins, it's rumored that Svrrl is trapped "+
		"here in this world, and not to pleased about that.  There are "+
		"further rumors that each night Svrrl is restored to life and "+
		"health, thus always trapped here.  To have a shield made from"+
		" her scales is a glorious feat indeed!");
	set_property("lore",12);
	set_type("shield");
	set_limbs(({"right hand"}));
	set_ac(0);
	set_weight(10);
	set_value(4000);
	set_property("enchantment",2);
	set_item_bonus("magic resistance",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func()
{
	if(owner != (string)TPQN) {
		tell_object(ETO,"This shield was made for "+owner+" and not for you!");
		return 0;
	}
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" straps on a "+
		"%^RESET%^%^BLUE%^blue scaled shield%^BOLD%^ to "+ETO->QP+" arm."+
		"  The %^CYAN%^blue topaz%^BLUE%^ gem in the center of the shield"+
		" begins to glow softly.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You strap on the shield to your arm.  "+
		"The %^CYAN%^blue topaz%^BLUE%^ in the center of the shield sheds"+
		" a soft glow");
	return 1;
}

int remove_func()
{
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" removes "+
		""+ETO->QP+" %^RESET%^%^BLUE%^blue scaled shield.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You remove the shield, causing"+
		" the %^CYAN%^gem%^BLUE%^ to lose its glow");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^A spray of"+
		" %^BLUE%^sp%^WHITE%^ar%^BLUE%^ks%^CYAN%^ flares out of"+
		" "+ETOQCN+"'s shield as "+ETO->QS+" bashes "+who->QCN+" with it!",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^A spray of %^BLUE%^sp%^WHITE%^ar"+
		"%^BLUE%^ks%^CYAN%^ flares out of the gem as you bash"+
		" "+who->QCN+" with the shield%^RESET%^");
	tell_object(who,"%^BOLD%^%^CYAN%^A spray of %^BLUE%^sp%^WHITE%^"+
		"ar%^BLUE%^ks%^CYAN%^ flares out of "+ETOQCN+"'s shield as"+
		" "+ETO->QS+" bashes you with it!");
			who->do_damage("torso",random(7)+1);
	}
}
void set_owner(string str)
{
	owner = str;
}
