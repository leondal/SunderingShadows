#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/weapon/light_rapier.c";

string owner;

void create()
{
	::create();
	set_name("serpent rapier");
	set_id(({ "rapier", "serpent tooth", "serpent rapier", "sword" }));
	set_short("%^RESET%^%^BLUE%^S%^BOLD%^%^CYAN%^e%^RESET%^%^BLUE%^r%^BOLD%^"+
		"%^CYAN%^p%^RESET%^%^BLUE%^e%^BOLD%^%^CYAN%^n%^RESET%^"+
		"%^BLUE%^t%^BOLD%^%^CYAN%^'%^RESET%^%^BLUE%^s %^BOLD%^"+
		"%^WHITE%^Tooth Rapier%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^An ivory blade rapier%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^A long slender iv%^YELLOW%^o%^WHITE%^ry"+
		" tooth has been set into a silver hilt.  The foot long "+
		"tooth is razor sharp and taper to a fine point.  The silver"+
		" hilt is a textured along the hand grip and has an oval weight"+
		" at the base, for balance.  An image of large %^CYAN%^serpent"+
		"%^WHITE%^ coiled about the hilt has been caved into the silvery"+
		" metal.  The textured scales help to created firm hand grips, "+
		"while the serpent's tail coils about the weight.  The head of "+
		"the serpent is carved with its mouth open, the iv%^YELLOW%^o"+
		"%^WHITE%^ry tooth set inside its jaws.  %^BLUE%^Sapphire%^WHITE%^"+
		" gems are set into the serpent's eyes giving it a life like "+
		"appearance.");
//    set_size(2);
	set_value(4500);
	set_property("enchantment",3);
	set_property("picking tool",10);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
}

int wieldme()
{
	if(owner != (string)TPQN) {
		tell_object(ETO,"The serpent's tooth pierces you as you try to wield it!");
		ETO->do_damage("torso",random(5)+2);
		return 0;
	}
	tell_object(ETO,"%^BLUE%^The serpent's tooth feels cool as you grip it.");
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^%^BLUE%^You release your grip on the tooth, missing the"+
	" feel of it in your hand already.");
	return 1;
}

int hitme(object targ)
{
    if(!objectp(targ)) return random(5)+1 ;
	if(!random(5)) {
		tell_object(targ,"%^CYAN%^"+ETO->QCN+"'s rapier"+
		" slices deeply into you!");
		tell_object(ETO,"%^CYAN%^You slice your rapier deeply into"+
		" "+targ->QCN+"!");
		tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" slices"+
		" "+ETO->QP+" rapier deeply into "+targ->QCN+"!",({ETO,targ}));
			set_property("magic",1);
			targ->do_damage("torso",random(4)+2);
			set_property("magic",-1);
		return 1;
	}
	if(!random(10)) {
		tell_object(targ,"%^BOLD%^"+ETO->QCN+" moves with lightning"+
		" speed and brings "+ETO->QP+" rapier up beneath your guard for a"+
		" powerful strike.");
		tell_object(ETO,"%^BOLD%^The serpent's tooth rapier snakes out with lightning"+
		" speed to strike beneath "+targ->QCN+"'s guard.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" moves"+
		" with lightning speed to bring "+ETO->QP+" rapier"+
		" up beneath "+targ->QCN+"'s guard.",({ETO,targ}));
			set_property("magic",1);
			targ->do_damage("torso",random(6)+3);
			set_property("magic",-1);
		return 1;
	}
	if(!random(20)) {
			tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+" moves in"+
				" quickly with "+ETO->QP+" rapier, landing a"+
				" couple of blows onto you!");
			tell_object(ETO,"%^BOLD%^%^GREEN%^You move in "+
				"quickly with your rapier, landing a "+
				"couple of blows onto "+targ->QCN+" .");
			tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+""+
			" moves in quickly with "+ETO->QCN+" rapier, landing a "+
			"couple of blows onto "+targ->QCN+".",({ETO,targ}));
				ETO->execute_attack();
			return 1;
		}
	}		
void set_owner(string str)
{
	owner = str;
}
