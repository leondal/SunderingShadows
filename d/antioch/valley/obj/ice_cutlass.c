//Added Lore - Cythera 4/05
//Set to inherit from /d/common/ - Octothorpe 12/16/09
#include <std.h>
#include <daemons.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/scimitar.c";

int OWNED;
string owner;

void create()
{
	::create();
	set_name("%^BOLD%^%^BLUE%^Cutlass of Ice%^RESET%^");
	set_id(({"cutlass","sword","cutlass of ice","sword of ice","+
		""ice cutlass","ice sword","frozen sword","ice blade","+
		""frozen blade","blade of ice","blade"}));
	set_short("%^BOLD%^%^BLUE%^Cutlass of Ice%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A cutlass made of ice%^RESET%^");
	set_long("%^BOLD%^%^CYAN%^Misty vapors rise off the blade of this cutlass."+
		"  The blade is actually made from a solid piece of ice that"+
		" has been warded to never melt.  The ice blade is crystal "+
		"clear, showing that only the purest water was used in its "+
		"creation.  The blade is set into a hilt made from a winter "+
		"blue metal.  The hilt is wrapped with a "+
		"%^BOLD%^%^WHITE%^white fur%^CYAN%^, to give "+
		"some comfort to the wielder.  A small miniature orb of "+
		"%^BLUE%^blue topaz%^CYAN%^ rests in the pommel of the blade."+
		"  Deep within the orb the image of a snowflake is housed within"+
		" the icy blue gem.");
	set_weight(8);
	set_lore("The Ice Cutlass or as its more commonly known Cold Heart "+
		"of Love is a blade that is devoted to Auril.  The Cutlass "+
		"was rumored to first have been wielded by a fallen ranger of"+
		" Auril, one Jarthow Urdethan, an elven male whose heart turned"+
		" cold and icy after finding his true love in the arms of another."+
		"  Jarthow was said to once have been a ranger of Mielikki and in "+
		"love with one of her priestesses.  The two, being elves, carried on"+
		" a long romance that lasted many many many years.  It was not "+
		"uncommon for Jarthow to take flight into the forests to spend "+
		"time alone with the trees and his goddess presence.  On one "+
		"such wandering through the woods he came upon a pool deep within"+
		" the woods.  There he found his lovely priestess engaged in a "+
		"scandalous affair with a low ranking half-elf priest of "+
		"Lathanders faith. Jarthow felt betrayed by his love, his goddess"+
		" and everything that he once believed in.  He turned his back on "+
		"everything he knew and allowed his heart to grow cold to those he"+
		" once called friends.  He found his place in Auril's service as her"+
		" Slayer of Love, a grim cold figure that preyed on young lovers"+
		" seeking to end their romances in what ever way he could.  Some "+
		"claim that Jarthow is still out there stalking young lovers.");
	set_property("lore",14);
	set_type("slashing");
	set_size(2);
        set_property("enchantment",3+random(2));
	set_wc(2,4);
	set_large_wc(1,10);
	set_value(800);
	set_prof_type("ice cutlass");
	set_hit((:TO,"hitme":));
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
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
		if((string)ETO->query_diety() == "auril") {
			tell_object(ETO,"This does not belong to you.");
			return 0;
		}
		tell_object(ETO,"By attempting to wield a weapon that is not yours you"+
		" bring the icey wrath of Auril down upon you!");
		set_property("magic",1);
		ETO->do_damage("torso",random(50)+75);
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		remove_property("magic");
		return 0;
	}
	if(ETO->query_level() < 15) {
		tell_object(ETO,"You are too inexperienced to wield this"+
		" weapon.");
		return 0;
	}
	if((string)ETO->query_diety() == "auril") {
		tell_object(ETO,"%^BOLD%^%^BLUE%^The chilling hilt of"+
		" the cutlass is a pleasure to you.");
         ETO->set_property("evil item",1);
		return 1;
	}
	else {
		tell_object(ETO,"%^BLUE%^The sword is cold to your touch"+
		" and gripping it hurts you.");
		set_property("magic",1);
		ETO->do_damage("torso",random(8)+1);
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		remove_property("magic");
         ETO->set_property("evil item",1);
		return 1;
	}
}

int removeme()
{
	if((string)ETO->query_diety() == "auril") {
		tell_object(ETO,"%^BOLD%^%^BLUE%^You carefully store your trusty"+
		" cutlass to the side for a moment.");
         ETO->set_property("evil item",-1);
		return 1;
	}
	else {
		tell_object(ETO,"%^BLUE%^Your hand warms again as you"+
		" unwield the cutlass.");
         ETO->set_property("evil item",-1);
		return 1;
	}
}

int hitme(object targ)
{
	int place;

	if(!objectp(targ)) return 1;

	place = environment(query_wielded());

	if(!random(25)) {
                if((string)targ->query_diety() != "auril") {
			tell_object(ETO,"%^BOLD%^%^BLUE%^"+targ->query_cap_name()+""+
			" turns a bluish shade as your cutlass bites into"+
			" "+targ->query_objective()+".");
			tell_object(targ,"%^BOLD%^%^BLUE%^As "+ETO->query_cap_name()+"'s"+
			" cutlass slices into you, you feel much colder.");
			tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+targ->query_cap_name()+""+
			" turns a bluish shade as "+ETO->query_cap_name()+"'s"+
			" cutlass bites into "+targ->query_subjective()+".",({ETO,targ}));
			targ->do_damage(random(8)+5);
			return 1;
		}
		else {
			tell_object(ETO,"%^BOLD%^%^CYAN%^"+targ->query_cap_name()+""+
			" turns a slight bluish shade as your cutlass bites"+
			" into "+targ->query_objective()+", but smiles and"+
			" seems unaffected.");
			tell_object(targ,"%^BOLD%^%^CYAN%^As "+ETO->query_cap_name()+"'s"+
			" cutlass slices into you, you feel the chill presence"+
			" of your goddess and are healed by the icy touch.");
			tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+targ->query_cap_name()+""+
			" turns a light bluish shade as "+ETO->query_cap_name()+"'s"+
			" cutlass bites into "+targ->query_objective()+", but"+
			" "+targ->query_subjective()+" smiles and seems"+
			" unharmed.",({ETO,targ}));
			targ->do_damage("torso",-(random(10)+1));
			return 1;
		}
	}
	if(!place->query_property("indoors")) {
		if(!random(30)) {
			if(!(string)targ->query_diety() == "auril") {
				tell_object(ETO,"%^BOLD%^Chill winds arise and tear"+
				" at "+targ->query_cap_name()+".");
				tell_object(targ,"%^BOLD%^Chill winds arise and tear"+
				" at you, freezing you to the core.");
				tell_room(environment(ETO),"%^BOLD%^Chill winds arise"+
				" and tear viciously at "+targ->query_cap_name()+".",({ETO,targ}));
				targ->do_damage("torso",random(15)+5);
				return 1;
			}
			else {
				tell_object(targ,"%^BOLD%^%^CYAN%^Chill winds rise"+
				" up and enfold you in their embrace.");
				tell_object(ETO,"%^BOLD%^%^CYAN%^Chill winds arise"+
				" and enfold "+targ->query_cap_name()+", but"+
				" "+targ->query_subjective()+" seems unharmed by them.");
				tell_room(environment(ETO),"%^BOLD%^%^CYAN%^Chill"+
				" winds arise and enfold "+targ->query_cap_name()+","+
				" gently caressing "+targ->query_objective()+".",({ETO,targ}));
				targ->do_damage("torso",-(random(15)+1));
				return 1;
			}
		}
	}
	if((string)ETO->query_diety() == "auril") {
		if(!random(40)) {
			if(!place->query_property("indoors")) {
				if((string)WEATHER_D->Check_Weather(ETO) != "%^BOLD%^%^CYAN%^It is clear.") {
					if(!(string)targ->query_diety() == "auril") {
						tell_object(ETO,"%^BOLD%^With the power of the"+
						" cutlass you call forth hale from the sky to"+
						" batter "+targ->query_cap_name()+".");
						tell_object(targ,"%^BOLD%^Hale begins to rain"+
						" down from the sky and batter you!");
						tell_room(environment(ETO),"%^BOLD%^Hale"+
						" pours down from the sky, strangely it only"+
						" batters "+targ->query_cap_name()+".",({ETO,targ}));
						targ->do_damage("torso",random(15)+8);
						return 1;
					}
				}
			}
		}
		if(!random(400)) {
			if(!(string)targ->query_diety() == "auril") {
				tell_object(ETO,"%^BOLD%^%^CYAN%^You pray to the"+
				" Frostmaiden and "+targ->query_cap_name()+""+
				" shimmers a pale blue.");
				tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+targ->query_cap_name()+""+
				" begins to shimmer a pale blue.",({ETO,targ}));
				if(!"daemon/saving_d"->saving_throw(targ,"spell",-3)) {
					tell_object(ETO,"%^BOLD%^%^BLUE%^Icicles form"+
					" on "+targ->query_cap_name()+", freezing"+
					" "+targ->query_objective()+".");
					tell_object(targ,"%^BOLD%^%^BLUE%^Power washes"+
					" over you and icicles begin to form on your"+
					" skin as you become frozen.");
					tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+
					"Icicles begin to form on "+targ->query_cap_name()+""+
					" as "+targ->query_subjective()+" freezes.",({ETO,targ}));
					targ->set_paralyzed(25,"You are frozen!");
					targ->do_damage("torso",random(20)+10);
					return 1;
				}
				else {
					tell_object(ETO,"%^BOLD%^%^CYAN%^"+targ->query_cap_name()+""+
					" shivers from the incredible cold.");
					tell_object(targ,"%^BOLD%^%^CYAN%^You feel a"+
					" coldness wash over you and you shiver in pain.");
					tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+targ->query_cap_name()+""+
					" shivers from the incredible cold.",({ETO,targ}));
					targ->do_damage("torso",random(20)+10);
					return 1;
				}
			}
		}
	}
}
