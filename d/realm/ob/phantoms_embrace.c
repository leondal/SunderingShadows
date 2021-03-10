//Phantoms Embrace Armor - can be studded/breastplate/ or plate mail
//basically just another armor option - but has a special that will
//"look" like the wearer becomes "ethereal" and the attack 
//should do no damage - Saide 
#include <std.h>
inherit ARMOUR;
string atype, atype2;

void set_which_type(string str)
{
	switch (str)
	{
		case "studded leather":
			set_weight(25);
			set_type("leather");
			set_ac(3);
			atype = "studded leather";
			atype2 = "studded leather armor";
			set_id(({"leather", "studded", "studded leather", 	
			"suit of studded leather", "phantoms embrace", 
			"armor"}));
			break;
		case "breastplate":
			//breastplate
			set_weight(35);
		      set_ac(5);
			set_type("armour");
			atype = "breastplate";
			atype2 = atype;
			set_id(({"breastplate", "plate", "phantoms embrace", 
			"armor"}));
			break;
		case "plate mail":
			//plate mail
			set_type("armour");
			set_weight(40);
			set_ac(7);
			atype = "plate mail";
			atype2 = "suit of plate mail";
			set_id(({"suit of plate mail", "plate", "mail", 
			"plate mail", "phantoms embrace", "armor"}));
			break;
		default: 
			set_weight(25);
			set_type("leather");
			set_ac(3);
			atype = "studded leather";
			atype2 = "studded leather armor";
			set_id(({"leather", "studded", "studded leather", 	
			"suit of studded leather", "phantoms embrace", 
			"armor"}));
			break;
	}
	return;
}

string query_atype() { return atype; }

void create_armor(mixed str) 
{ 
	if(!str)
	{
		switch(random(3)) 
		{
			case 0:
				set_which_type("studded leather");
				break;
			case 1:
				set_which_type("breastplate");
				break;
			case 2:
				set_which_type("plate mail");
				break;
		}
	}
	else { set_which_type(str); }

	set_name(atype);
	
	set_obvious_short("%^BOLD%^%^CYAN%^An azure "+atype2+"%^RESET%^");
	
	set_short("%^BOLD%^%^WHITE%^Ph%^BOLD%^%^BLUE%^a"+
	"%^BOLD%^%^WHITE%^nt%^BOLD%^%^BLUE%^o%^BOLD%^%^WHITE%^"+
	"m's %^BOLD%^%^RED%^E%^BOLD%^%^CYAN%^m%^BOLD%^%^RED%^"+
	"b%^BOLD%^%^CYAN%^r%^BOLD%^%^RED%^a%^BOLD%^%^CYAN%^"+
	"c%^BOLD%^%^RED%^e %^BOLD%^%^WHITE%^"+
	capitalize(atype)+"%^RESET%^");

	set_long("%^BOLD%^%^BLUE%^This magnificent "+atype+
	" is almost %^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^"+
	"t%^BOLD%^%^CYAN%^h%^BOLD%^%^WHITE%^e%^BOLD%^"+
	"%^CYAN%^r%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^a"+
	"%^BOLD%^%^WHITE%^l%^BOLD%^%^BLUE%^.  It is "+
	"crafted from a strange %^BOLD%^%^CYAN%^"+
	"azure%^BOLD%^%^BLUE%^ material that appears "+
	"to be %^BOLD%^%^YELLOW%^w%^BOLD%^%^BLUE%^"+
	"e%^BOLD%^%^YELLOW%^a%^BOLD%^%^BLUE%^v"+
	"%^BOLD%^%^YELLOW%^i%^BOLD%^%^BLUE%^n"+
	"%^BOLD%^%^YELLOW%^g%^BOLD%^%^BLUE%^ in "+
	"and out of reality and manages to r%^BOLD%^"+
	"%^RED%^e%^BOLD%^%^BLUE%^fr%^BOLD%^%^RED%^"+
	"a%^BOLD%^%^BLUE%^ct any %^BOLD%^%^WHITE%^"+
	"light%^BOLD%^%^BLUE%^ that comes into "+
	"contact with it.  The chest of it depicts "+
	"the h%^BOLD%^%^CYAN%^au%^BOLD%^"+
	"%^BLUE%^nt%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^"+
	"ngly beautiful image of a %^BOLD%^%^WHITE%^serene "+
	"%^BOLD%^%^CYAN%^ph%^BOLD%^%^WHITE%^a%^BOLD%^"+
	"%^CYAN%^nt%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^"+
	"sm%^BOLD%^%^BLUE%^ outlined in a "+
	"%^BOLD%^%^RED%^deep crimson%^BOLD%^%^BLUE%^ "+
	"glow.%^RESET%^");
}

void create() 
{
    	::create();
	create_armor(0);
	set_property("lore difficulty", 30);

	set_lore("%^BOLD%^%^RED%^This armor was created by an "+
	"enchanter in the service of a long forgotten king.  "+
	"It is believed that he imbued them with a "+
	"conjured likeness of a lover who died young.  "+
	"The conjuration was pleased and strengthened "+
	"the armor for the enchanter with a powerful "+
	"magic that would protect the wearer in combat.  "+
	"Some legends suggest that the wearer might even "+
	"briefly slip away into the ethereal plane to "+
	"avoid an attack entirely.  What happened to the "+
	"enchanter in the end is entirely unknown, but "+
	"he did imbue several different types of armor "+
	"for the forgotten king, in order to allow "+
	"all of kings servants to benefit from the "+
	"magic.%^RESET%^");
	set_size(random(3) + 1);
	set_property("enchantment", 4);
  	set_value(8000);
    	set_limbs( ({ "torso" }) );
	set_wear((:TO, "wear_me":));
	set_struck((:TO,"strike_me":));
	set_remove((:TO, "remove_me":));
}

int wear_me()
{
	if(ETO->query_highest_level() < 30)
	{
		tell_object(ETO, "%^BOLD%^%^WHITE%^The "+atype+
		"refuses to yield itself to one of your power!%^RESET%^");
		return 0;
	}
	tell_object(ETO, "%^BOLD%^%^WHITE%^You feel a serene "+
	"feeling wash over you as you don the "+atype+".%^RESET%^");
	return 1;
}

int remove_me()
{
	tell_object(ETO, "%^BOLD%^%^WHITE%^The serene feeling "+
	"leaves you.%^RESET%^");
	return 1;
}

int strike_me(int damage, object what, object who)
{
	int x = 0;
	if(!objectp(ETO)) return 0;
	if(!objectp(who)) return 0;
	if(!objectp(EETO)) return 0;
	if(!objectp(what)) return 0;
	if(!random(45)) return 0;
	switch(random(20)) 
	{
		case 0..18:
			tell_object(ETO, "%^BOLD%^%^WHITE%^As "+
			who->QCN+"%^BOLD%^%^WHITE%^'s "+
			what->QCN+"%^BOLD%^%^WHITE%^ "+
			"makes contact with your "+atype+
			" you feel the blow weakened by a "+
			"%^BOLD%^%^CYAN%^PHANTOM"+
			"%^BOLD%^%^WHITE%^ force!%^RESET%^");

			tell_object(who, "%^BOLD%^%^WHITE%^As "+
			"your "+what->QCN+"%^BOLD%^%^WHITE%^ "+
			"makes contact with "+ETOQCN+"%^BOLD%^"+
			"%^WHITE%^'s "+atype+" you feel the blow "+
			"weakened by a %^BOLD%^%^CYAN%^"+
			"PHANTOM%^BOLD%^%^WHITE%^ force!%^RESET%^");

			tell_room(EETO, "%^BOLD%^%^WHITE%^As "+
			who->QCN+"%^BOLD%^%^WHITE%^'s "+what->QCN+
			"%^BOLD%^%^WHITE%^ makes contact with "+
			ETOQCN+"%^BOLD%^%^WHITE%^ the blow "+
			"seemes weakened!%^RESET%^", ({who, ETO}));
			x -= (damage/2);
			break;
		case 19:
			tell_object(ETO, "%^BOLD%^%^CYAN%^"+
			"As "+who->QCN+"%^BOLD%^%^CYAN%^ "+
			"makes contact with "+who->QP+
			" "+what->QCN+"%^BOLD%^%^CYAN%^ "+
			"your "+atype+" pulls you briefly "+
			"into the ethereal plane, allowing "+
			"the blow to pass harmlessly "+
			"through you!%^RESET%^");
	
			tell_object(who, "%^BOLD%^%^CYAN%^As your "+
			what->QCN+"%^BOLD%^%^CYAN%^ makes contact with "+
			ETOQCN+"%^BOLD%^%^CYAN%^ "+ETO->QS+" appears "+
			"ethereal for a brief moment and your blow "+
			"passes through "+ETO->QO+" harmlessly!%^RESET%^");

			tell_room(EETO, "%^BOLD%^%^CYAN%^As "+
			who->QCN+"%^BOLD%^%^CYAN%^'s "+what->QCN+
			"%^BOLD%^%^CYAN%^ makes contact with "+
			ETOQCN+"%^BOLD%^%^CYAN%^, "+ETO->QS+
			"appears ethereal for a brief moment and "+
			"the blow passes through "+ETO->QO+" "
			"harmlessly!%^RESET%^", ({ETO, who}));
			x -= damage;
			break;
	}
	return x;

}

