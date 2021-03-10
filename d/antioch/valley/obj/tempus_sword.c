//Added Lore and inherit bastard_two- Cythera 4/05\\
#include <std.h>
#include <daemons.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/bastard_two.c";

int FLAG, OWNED;
string owner;

void create()
{
	::create();
   	set_obvious_short("%^BOLD%^%^WHITE%^A titanium two handed bastard sword%^RESET%^");
	set_name("%^RESET%^%^WHITE%^Sword of %^RED%^Honor%^RESET%^");
	set_id(({"sword","sword of honor","sword of tempus","two handed sword""+
		","bastard sword","two handed bastard sword","titanium sword"}));
	set_short("%^RESET%^%^WHITE%^Sword of %^RED%^Honor%^RESET%^");
	set_long(
"\n	%^BOLD%^%^WHITE%^Merely looking upon this sword inspires honor and courage \n"+
"	deep within your heart. This blade is crafted from purest \n"+
"	titanium and honed razor sharp.  On the hilt is a blazing \n"+
"	%^RESET%^silver sword%^BOLD%^ on a %^RED%^blood"+
	" red%^WHITE%^ field, holy symbol of Tempus.\n"
	);
	set_lore("The faith of Law has always been full of warriors,"+
		" generals, and mercenaries.  The Sword of Honor though "+
		"was reserved for an elite group of warriors devoted to "+
		"Law, the Battleblades.  The Battleblades were made up "+
		"on those warriors who best illustrated the path of War and"+
		" Battle that Law outlined in his doctrine.  In the past "+
		"a trio of white robes priests of Law were on hand at every"+
		" war, to judge the warriors and general's actions.  When they"+
		" found someone who demonstrated the path of War that Law"+
		" favored, they inducted that person into the order on the spot."+
		"  The Battleblades crossed social classes, gender, and racial "+
		"barriers, anyone could become a member of the Battleblades.  "+
		"Their great two-handed bastard swords, known as the Sword of Honor,"+
		" was a symbol of this elite band they were part of now.");
	set_property("lore",13);
	//set_weight(10);
	//set_size(3);
	//set_type("slash");
	//set_wc(2,6);
	//set_large_wc(2,8);
	set_value(1500);
        set_property("enchantment",3+random(2));
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
		if((string)ETO->query_diety() == "tempus") {
			tell_object(ETO,"This is not your sword, it will not obey you.");
			return 0;
		}
		tell_object(ETO,"For trying to wield a weapon that is not yours you"+
		" have incurred the wrath of Tempus!!");
		set_property("magic",1);
		ETO->do_damage("torso",random(50)+75);
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		remove_property("magic");
		return 0;
	}
	if((string)ETO->query_diety() == "tempus") {
		tell_object(ETO,"%^RED%^You feel honored to wield a"+
		" holy sword of Tempus.");
		FLAG = 1;
		return 1;
	}
	else {
		tell_object(ETO,"Your heart swells with courage as you"+
		" wield the %^BOLD%^Sword of Honor%^RESET%^.");
		return 1;
	}
}

int removeme()
{
	if((string)ETO->query_diety() == "tempus") {
		tell_object(ETO,"%^BOLD%^%^RED%^After a long day of"+
		" fighting you put down your sword.");
		FLAG = 0;
		return 1;
	}
	else {
		tell_object(ETO,"You feel a little less couragous as you"+
		" put aside your blade.");
		FLAG = 0;
		return 1;
	}
}

int hitme(object targ)
{
	int Tlvl, Mlvl, MAX, HP;

	if(!objectp(targ)) return 1;

	Tlvl = targ->query_level();
	Mlvl = ETO->query_level();
	HP = ETO->query_hp();
	MAX = ETO->query_max_hp();

	if(!random(20)) {
		tell_object(ETO,"The sword seems to lend extra strength"+
		" to your swing against "+targ->query_cap_name()+".");
		tell_object(targ,""+ETO->query_cap_name()+" swings at you"+
		" with incredible strength.");
		tell_room(environment(ETO),""+ETO->query_cap_name()+" puts"+
		" extra strength behind "+ETO->query_possessive()+" swing"+
		" against "+targ->query_cap_name()+".",({ETO,targ}));
		targ->do_damage("torso",random(8)+5);
		return 1;
	}
	if(Tlvl > Mlvl) {
		if(!random(35)) {
			tell_object(ETO,"%^BOLD%^%^RED%^Courage swells in your"+
			" chest as you face "+targ->query_cap_name()+" and slice"+
			" deeply into "+targ->query_objective()+".");
			tell_object(targ,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+""+
			" grins as "+ETO->query_subjective()+" slices deeply"+
			" into you.");
			tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+""+
			" grins broadly as "+ETO->query_subjective()+" slices"+
			" "+ETO->query_possessive()+" sword deeply into "+targ->query_cap_name()+".",({ETO,targ}));
			targ->do_damage("torso",random(10)+6);
			return 1;
		}
	}
	if(FLAG == 1) {
		if(!random(30)) {
			tell_object(ETO,"%^BOLD%^You belt out a cry to Tempus"+
			" and rush at "+targ->query_cap_name()+"!");
			tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+""+
			" belts out a cry to Tempus and rushes at you!");
			tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+""+
			" belts out a cry to Tempus and rushes at "+targ->query_cap_name()+"!",({ETO,targ}));
			targ->do_damage("torso",random(12)+5);
			return 1;
		}
		if(HP < (MAX/2)) {
			if(!random(100)) {
			if((string)WEATHER_D->Check_Weather(ETO) == "%^BOLD%^%^CYAN%^It is clear.") {
				tell_object(ETO,"%^YELLOW%^Glory swells within your"+
				" heart as a beam of light shoots down from the sky,"+
				" encasing your sword in light and honor.\n"+
				" %^WHITE%^You continue to couragously fight "+targ->query_cap_name()+".");
				tell_object(targ,"%^YELLOW%^A beam of light shoots"+
				" down from the sky, encasing "+ETO->query_cap_name()+"'s"+
				" sword in a golden light.\n"+
				" %^WHITE%^"+ETO->query_cap_name()+" is encouraged"+
				" and begins fighting you more feverently.");
				tell_room(environment(ETO),"%^YELLOW%^A beam of light"+
				" shoots down from the sky, encasing "+ETO->query_cap_name()+"'s"+
				" sword in a golden light.\n%^WHITE%^"+ETO->query_cap_name()+""+
				" begins to fight "+targ->query_cap_name()+" even"+
				" more feverently as "+ETO->query_possessive()+""+
				" spirits are lifted.",({ETO,targ}));
				targ->do_damage("torso",random(10)+15);
				ETO->do_damage("torso",-(random(10)+5));
				return 1;
			}
			else {
				tell_object(ETO,"%^YELLOW%^You feel the approval of"+
				" Tempus as you stand your ground against "+targ->query_cap_name()+""+
				" and slowly beat "+targ->query_objective()+" back.");
				tell_object(targ,"%^YELLOW%^"+ETO->query_cap_name()+""+
				" gets a surge of energy and begins to beat you back.");
				tell_room(environment(ETO),"%^YELLOW%^The tide of the"+
				" battle changes and "+ETO->query_cap_name()+" begins"+
				" to beat "+targ->query_cap_name()+" back.",({ETO,targ}));
				targ->do_damage("torso",random(10)+10);
				return 1;
			}
		}
		}
		if(!random(3)) {
			targ->do_damage("torso",random(4)+2);
			return 1;
		}
	}
}
