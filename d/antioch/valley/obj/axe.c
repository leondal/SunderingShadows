//Added lore and changed to inherit battle_axe Cythera 4/05\\
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/battle_axe.c";

int FLAG, OWNED;
string owner;

void create()
{
	::create();
	set_name("battle axe");
	set_id(({"axe","axe of brambles and thorns","ranger axe","+
		""axe of thorns","axe of brambles","axe of mielikki","+
		""battle axe"}));
	set_short("%^BOLD%^%^GREEN%^Axe of Brambles and Thorns%^RESET%^");
    set_obvious_short("%^BOLD%^%^GREEN%^A medium axe%^RESET%^");
	set_long(
	    "%^BOLD%^%^GREEN%^	Axe of Brambles and Thorns\n%^WHITE%^"+
	    "The blade of the axe is decorated with flowery runes. \n"+
	    "The handle of the axe is carved with patterns of \n"+
	    "brambles and thorns. On the very bottom of the handle \n"+
	    "is a picture of a white unicorn on a green field,\n"+
	    "the symbol of the former Lady of the Forest.%^RESET%^"
	);
	//set_weight(7);
	//set_type("slash");
	//set_size(2);
	//set_wc(1,8);
	//set_large_wc(1,8);
        set_property("enchantment",3+random(2));
   	//set_prof_type("medium axe");
	set_value(350);
	set_lore("The Axe of Bramble and Thorns was a common "+
		"weapon seen on a band of rangers devoted to the nature"+
		" named the Thorns of Nature.  Taking a more sever "+
		"approach to the encroachment upon forests than some "+
		"of their more lenient brothers, the Thorns often came "+
		"into conflict with loggers and hunters and even their "+
		"fellow rangers and faithful.  The Thorns of "+
		"Nature though were able to put their differences aside "+
		"when it came to hunting down their eternal foes, followers"+
		" of ancient god of the beast.  The Axes of Bramble and Thorns was seen as a "+
		"badge of honor with the Thorns of Nature.");
	set_property("lore",10);
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
	int align;

	align = ETO->query_alignment();

	if((string)TPQN != owner) {
		if((string)ETO->query_diety() == "mielikki") {
			tell_object(ETO,"This axe is not yours, you should know better.");
			return 0;
		}
		tell_object(ETO,"You are not the owner of this fine weapon, how dare"+
		" you try to wield it!");
		set_property("magic",1);
		ETO->do_damage("torso",((int)TP->query_hp()-1));
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		remove_property("magic");
		return 0;
	}
	if((string)ETO->query_diety() == "mielikki" && (string)TPQN == owner) {
		tell_object(ETO,"%^BOLD%^%^GREEN%^You feel confident as"+
		" you wield this treasured weapon.");
		FLAG = 1;
		return 1;
	}
	if((string)ETO->query_diety() == "malar" || (string)ETO->query_diety() == "talos") {
		tell_object(ETO,"%^GREEN%^The sacred axe of Mielikki"+
		" refuses your foul touch!");
		set_property("magic",1);
		ETO->do_damage("torso",random(10)+5);
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		remove_property("magic");
		return 0;
	}
	if(align == 3 || align == 6 || align == 9) {
		tell_object(ETO,"%^GREEN%^You cannot wield this axe until"+
		" you purge the evil from your soul.");
		return 0;
	}
	else {
		tell_object(ETO,"The axe has a nice balance to it.");
		return 1;
	}
}

int removeme()
{
	if((string)ETO->query_diety() == "mielikki") {
		tell_object(ETO,"%^BOLD%^%^GREEN%^That peaceful presence"+
		" fades away as you release the axe.");
		FLAG = 0;
		return 1;
	}
	else {
		tell_object(ETO,"You put the axe aside for now.");
		FLAG = 0;
		return 1;
	}
}

int hitme(object targ)
{
	int place;

	if(!objectp(targ)) return 1;

	place = environment(query_wielded());
	if(!random(10)) {
		tell_object(ETO,"%^BOLD%^You swing with your axe and as"+
		" "+targ->query_cap_name()+" dodges, you quickly reverse"+
		" the swing and land a crushing blow on "+targ->query_objective()+".");
		tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+" swings"+
		" "+ETO->query_possessive()+" axe at you and you dodge out of"+
		" the way, but "+ETO->query_subjective()+" quickly reverses"+
		" the swing and lands a crushing blow on you.");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+""+
		" swings "+ETO->query_possessive()+" axe at "+targ->query_cap_name()+","+
		" who dodges out of the way, but then "+ETO->query_subjective()+""+
		" quickly reverses the swing to land a crushing blow.",({ETO,targ}));
		targ->do_damage("torso",random(8)+4);
		return 1;
	}
	if(!random(20)) {
		tell_object(ETO,"%^CYAN%^Your axe whistles through the air"+
		" as you bring it swiftly down in an over-hand chop on"+
		" "+targ->query_cap_name()+".");
		tell_object(targ,"%^CYAN%^"+ETO->query_cap_name()+"'s axe"+
		" whistles in the air as "+ETO->query_subjective()+" brings"+
		" it swiftly down in an over-hand chop on you.");
		tell_room(environment(ETO),"%^CYAN%^"+ETO->query_cap_name()+"'s axe"+
		" whistles in the air as "+ETO->query_subjective()+" brings"+
		" it swiftly down in an over-hand chop on"+
		" "+targ->query_cap_name()+".",({ETO,targ}));
		targ->do_damage(random(10)+6);
		return 1;
	}
	if(FLAG == 1) {
		if(!random(30)) {
			tell_object(ETO,"%^GREEN%^You bellow your anger about"+
			" the injustice done to the lands and begin swinging"+
			" furiously at "+targ->query_cap_name()+", connecting"+
			" forcefully with "+targ->query_objective()+".");
			tell_object(targ,"%^GREEN%^"+ETO->query_cap_name()+""+
			" bellows something about "+ETO->query_possessive()+""+
			" anger for the injustice done to the lands and begins"+
			" swinging "+ETO->query_possessive()+" axe furiously"+
			" at you and connects rather forcefully.");
			tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+""+
			" bellows something about "+ETO->query_possessive()+""+
			" anger for the injustice done to the lands and begins"+
			" swinging "+ETO->query_possessive()+" axe furiously"+
			" at "+targ->query_cap_name()+" and connects with"+
			" "+targ->query_objective()+" rather forcefully.",({ETO,targ}));
			targ->do_damage("torso",random(12)+10);
			return 1;
		}
		if(!random(75)) {
			if(!place->query_property("indoors")) {
				tell_object(ETO,"%^BOLD%^%^GREEN%^You feel a familiar,"+
				" soothing presence and are able to focus more clearly.\n"+
				"%^RESET%^%^GREEN%^Spotting an opening in "+targ->query_cap_name()+"'s"+
				" defense you move in and deliver a brutal hit.");
				tell_object(targ,"%^GREEN%^"+ETO->query_cap_name()+""+
				" spots an opening in your defense and delivers"+
				" a brutal hit on you.");
				tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+""+
				" focuses for a moment and spots an opening in"+
				" "+targ->query_cap_name()+"'s defense, moving in"+
				" quickly "+ETO->query_subjective()+" delivers a"+
				" brutal hit.",({ETO,targ}));
				targ->do_damage("torso",random(25)+10);
				return 1;
			}
		}
		if(!random(3)) {
			targ->do_damage("torso",random(4)+1);
			return 1;
		}
	}
}
