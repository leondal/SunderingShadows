#include <std.h>
#include <daemons.h>
#include <magic.h>
#include "../ruins.h"
inherit "/d/common/obj/weapon/longsword.c";

int OWNED;
string owner;

void create()
{
	::create();
	set_name("Sword of Eternity");
	set_obvious_short("%^BOLD%^%^WHITE%^A shining longsword%^RESET%^");  // added by Styx 5/6/03
	set_short("%^WHITE%^%^BOLD%^Sword of %^BLUE%^E%^GREEN%^t"+
		"%^WHITE%^e%^YELLOW%^r%^BLUE%^n%^GREEN%^i%^YELLOW%^t%^WHITE%^y%^RESET%^");
	set_id(({"sword","sword of eternity","eternity sword","longsword"}));
	set_long(
	"%^BOLD%^%^WHITE%^Known as the Sword of Eternity, this is an ancient blade"+
	" of incredible power. It is a longsword with a pure white blade that's"+
	" razor sharp. The hilt of the sword is made of ivory and has a comfortable"+
	" grip. On the body of the hilt is an %^GREEN%^a%^BLUE%^n%^YELLOW%^c"+
	"%^CYAN%^i%^BLUE%^e%^GREEN%^n%^YELLOW%^t %^CYAN%^s%^GREEN%^y%^BLUE%^m"+
	"%^YELLOW%^b%^CYAN%^o%^GREEN%^l%^WHITE%^ that has been engraved"+
	" in %^BLACK%^ebony%^WHITE%^, the symbol of %^GREEN%^E%^BLUE%^t%^YELLOW%^e"+
	"%^CYAN%^r%^GREEN%^n%^BLUE%^i%^CYAN%^t%^YELLOW%^y%^WHITE%^. Although the sword is not very"+
	" large, it is rather heavy."
	);
	set_lore("The Sword of Eternity is a legendary blade that came to the"+
		" lands through questionable and unknown means.  The metal used"+
		" to craft the blade is like none no one has ever seen before.  "+
		"The white dense metal is stronger than steel or even adamantium."+
		"  What little is known about the blade has come mostly through "+
		"divination magics.  The blade seems to have entered the lands "+
		"around the early parts of the Second Century, wielded a elven "+
		"warrior named Ra'thalan.  Ra'thalan, if you recall, was one of"+
		" the famous seven heroes of the Third Crown Wars.  The bloody "+
		"and fierce battle between the drow and the elves started in the"+
		" north, but quickly moved as far south as what is now known as "+
		"the Tharis Forest.  Ra'thalan was able to use his new blade to "+
		"slice through hordes of drow and driders, seeking to push the "+
		"dark elves back below the surface.  The blade then was passed "+
		"on in Ra'thalan's family for centuries until around the later "+
		"part of the Fifth Century when the heir to the blade, Obethezen,"+
		" was killed, and his corpse looted.  From there the sword remained"+
		" in obscurity until surfacing in more recent time.  - Artifacts "+
		"and Heroes of the Crown Wars - Lithzeleliam Silverfalls");
	set_property("lore",14);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
	set_property("enchantment",4);
	set_value(1000);
}

void init()
{
	::init();
	if(!interactive(ETO)) return;
	if(interactive(TP) && TP == environment(TO) && !OWNED) {
		owner = TPQN;
		OWNED = 1;
	}
}

int wieldme()
{
	if((string)TPQN != owner) {
		tell_object(ETO,"%^BOLD%^The Sword of Eternity blazes as you try to"+
		" grip its hilt, scorching your hands!");
		tell_room(environment(ETO),"%^BOLD%^The Sword of Eternity blazes as"+
		" "+ETO->QCN+" tries to wield it!",ETO);
		set_property("magic",1);
		ETO->do_damage("torso",random(5)+20);
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		remove_property("magic");
		return 0;
	}
   if(ETO->query_property("evil item")) {
       tell_object(ETO,"The sword of eternity refuses to be wielded while you're using such evil items!");
       return 0;
   }
   tell_object(ETO,"%^YELLOW%^You feel the power of eternity flow through you"+
	" as you grip the hilt of the sword.");
   ETO->set_property("good item",1);
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^%^CYAN%^The power of eternity ebbs from you as"+
	" you release the sword.");
   ETO->set_property("good item",-1);
	return 1;
}

int hitme(object targ)
{
	object myspl;

      if(!objectp(targ))  return 0;
	if(!random(6)) {
		set_property("magic",1);
		tell_object(ETO,"%^BOLD%^%^CYAN%^You slice the %^WHITE%^Sword of Eternity%^CYAN%^"+
		" deeply into "+targ->QCN+".");
		tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+" slices "+ETO->query_possessive()+""+
		" %^WHITE%^Sword of Eternity%^CYAN%^ deeply into you.");
		tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" slices "+ETO->query_possessive()+""+
		" %^WHITE%^Sword of Eternity%^CYAN%^ deeply into "+targ->QCN+".",({ETO,targ}));
		targ->do_damage("torso",random(3)+2);
		remove_property("magic");
		return 1;
	}
    if(!random(40)) {
		set_property("magic",1);
		if((int)targ->query_stoneSkinned() > 0) {
                        while(objectp(myspl = MAGIC_D->get_spell_from_array(targ->query_property("spelled"),"iron body"))) {
                                remove_property_value("spelled", ({myspl}));
                                myspl->dest_effect();
                        }
                        while(objectp(myspl = MAGIC_D->get_spell_from_array(targ->query_property("spelled"),"stoneskin"))) {
				remove_property_value("spelled", ({myspl}));
				myspl->dest_effect();
			}
			tell_object(ETO,"%^BOLD%^%^BLUE%^The %^WHITE%^Sword of Eternity%^BLUE%^"+
			" destroys "+targ->QCN+"'s armour of diamond and granite,"+
			" leaving "+targ->QO+" vulnerable once more.");
			tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s"+
			" %^WHITE%^Sword of Eternity%^BLUE%^ pulses as it touches you.\n"+
			" %^BOLD%^%^WHITE%^The force protecting you breaks apart, leaving"+
			" you vulnerable once again.");
			tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s"+
			" %^WHITE%^Sword of Eternity%^BLUE%^ destroys "+targ->QCN+"'s"+
			" armour of diamond and granite.",({ETO,targ}));
			targ->do_damage("torso",random(3)+3);
			remove_property("magic");
			return 1;
		}
		tell_object(ETO,"%^BOLD%^The Sword of Eternity flickers and cleanly"+
		" slices through "+targ->QCN+", tearing at "+targ->query_possessive()+" soul.");
		tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s Sword of Eternity"+
		" flickers, and slices cleanly through you, tearing deeply at your soul.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+"'s Sword of Eternity"+
		" flickers, passing straight through "+targ->QCN+"!",({ETO,targ}));
		targ->do_damage("torso",random(4)+5);
		remove_property("magic");
		return 1;
	}
	if(!random(20)) {
		set_property("magic",1);
		tell_object(ETO,"Eternity slows, everything seems to be standing still"+
		" except for you.\n"+
		"%^BOLD%^You take the opportunity to get another attack in before the"+
		" world resumes its pace.");
		tell_object(targ,"%^BOLD%^"+ETO->QCN+" moves with impossible"+
		" speed, seeming to be everywhere at once as "+ETO->QS+""+
		" attacks you.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" moves with impossible"+
		" speed, seeming to be everywhere at once as "+ETO->QS+""+
		" attacks "+targ->QCN+".",({ETO,targ}));
		ETO->execute_attack();
		remove_property("magic");
		return 1;
	}
	if(!random(30)) {
		set_property("magic",1);
		tell_object(ETO,"%^YELLOW%^The power of Eternity travels through the"+
		" sword into you, healing your wounds.");
		tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+"'s"+
		" %^WHITE%^Sword of Eternity%^YELLOW%^ glows for a moment, and "+ETO->QS+""+
		" seems refreshed.",ETO);
		ETO->do_damage("torso",(-1)*(random(5)+10));
		remove_property("magic");
		return 1;
	}
}

void set_owner(string str)
{
	owner = str;
	OWNED = 1;
}
