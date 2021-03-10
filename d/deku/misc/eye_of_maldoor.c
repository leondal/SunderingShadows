#include <std.h>
inherit OBJECT;
int DI_WAIT = 0; //7200
int DM_WAIT = 0; //14400
int di_charges, dm_charges;

void create()
{
	::create();
	set_id(({"eye", "eye of maldoor", "ruby", "small ruby", 
	"ruby eye", "gem", "gem of maldoor", "ruby gem"}));
	set_obvious_short("%^BOLD%^%^RED%^A small oval shaped ruby%^RESET%^");

	set_short("%^BOLD%^%^YELLOW%^E%^BOLD%^%^RED%^y%^BOLD%^%^YELLOW%^"+
	"e %^BOLD%^%^RED%^of M%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^"+
	"ld%^BOLD%^%^BLACK%^oo%^BOLD%^%^RED%^r%^RESET%^");
	
	set_long("%^BOLD%^%^RED%^This small oval shaped ruby "+
	"looks quite fr%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^g"+
	"%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^"+
	"e%^BOLD%^%^RED%^, though it radiates an "+
	"%^BOLD%^%^CYAN%^a%^BOLD%^%^BLUE%^u%^BOLD%^%^CYAN%^"+
	"r%^BOLD%^%^BLUE%^a%^BOLD%^%^RED%^ that suggests "+
	"otherwise.  It is almost flawless in its "+
	"design, bearing no markings or imperfections "+
	"that you can see, save one.  It appears "+
	"to be somewhat %^BOLD%^%^WHITE%^foggy%^BOLD%^%^RED%^"+
	" on the inside and no amount of polishing "+
	"makes it go away.  You believe you can make out "+
	"a word floating within the %^BOLD%^%^WHITE%^"+
	"fog%^BOLD%^%^RED%^, somehow actually "+
	"within the ruby, as if it were a tangible "+
	"thing, instead of just writing.%^RESET%^");


	set_lore("%^RED%^Some say this ruby was the "+
	"actual eye of a wizard who died ages ago.  "+
	"You are unsure if this is true, but the legends "+
	"say that he removed his right eye and "+
	"enchanted it to look like an ordinary "+
	"ruby.  He supposedly used an extraordinary "+
	"magic on it, to allow for it to constantly "+
	"replenish itself with the ability "+
	"to detect invisible beings and the ability "+
	"to dispel the magic of the wizards "+
	"enemies.  It was believed lost, "+
	"ages ago, buried deep in the earth, "+
	"in some forgotten tomb.%^RESET%^");
	set_property("lore difficulty", 20);

	set_read("%^BOLD%^%^WHITE%^Gaze into me...%^RESET%^");
	set_language("common");
	di_charges = 3;
	dm_charges = 2;
	set_weight(2);
	set_value(2000);
	set_heart_beat(1);
}

void heart_beat()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!living(ETO)) return;
	DI_WAIT++;
	DM_WAIT++;
	if(DI_WAIT >= 7200)
	{
		DI_WAIT = 0;
		if(di_charges < 3) di_charges++;
	}
	if(DM_WAIT >= 14400)
	{
		DM_WAIT = 0;
		if(dm_charges < 2) dm_charges++;
	}
	return;
}

void init()
{
	::init();
	add_action("gaze_into", "gaze");
	add_action("manipulate_things", "manipulate");
}

int gaze_into(string str)
{
	string tmp;
	if(!objectp(TO)) return 0;
	if(!objectp(ETO)) return 0;
	if(!living(ETO)) return 0;
	if(!str) return 0;
	if(str == "into gem" ||
	str == "into ruby" ||
	str == "into eye" ||
	str == "into maldoors eye" ||
	str == "into maldoor eye" ||
	str == "into maldoor gem" ||
	str == "into maldoors gem" ||
	str == "into gem" ||
	str == "into gem of maldoor" ||
	str == "into ruby" ||
	str == "into ruby eye")
	{
		tell_object(ETO, "%^BOLD%^%^CYAN%^You gaze into the "+
		"%^BOLD%^%^RED%^ruby%^BOLD%^%^CYAN%^.%^RESET%^");

		tell_room(EETO, TPQCN+"%^BOLD%^%^CYAN%^ seems to "+
		"stare into a %^BOLD%^%^RED%^ruby%^BOLD%^%^CYAN%^ "+
		"in "+TPQP+" possession.%^RESET%^", ETO);

		tell_object(ETO, "%^BOLD%^%^CYAN%^A muffled voice whispers "+
		"to you:  %^RESET%^Manipulate me and I shall grant you power!"+
		"%^RESET%^");

		tmp = "%^BOLD%^%^RED%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n";
		tmp += "%^BOLD%^%^GREEN%^Manipulate Invisible Beings %^RESET%^: "+
		"%^BOLD%^%^WHITE%^"+di_charges +"%^RESET%^ left.%^RESET%^\n";
		tmp += "%^BOLD%^%^WHITE%^Manipulate Magic Protections %^RESET%^: "+
		"%^BOLD%^%^WHITE%^"+dm_charges + "%^RESET%^ left.%^RESET%^\n";
		tmp += "%^BOLD%^%^RED%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^";
		tell_object(ETO, tmp);
		return 1;
	}
	return 0;
}

void epic_failure(object victim)
{
	object env;
	if(!objectp(TO)) return;
	if(objectp(victim)) 
	{
		env = environment(victim);
		if(objectp(env)) 
		{
			tell_object(victim, "%^BOLD%^%^RED%^An %^BOLD%^%^YELLOW%^"+
			"I%^BOLD%^%^RED%^N%^BOLD%^%^YELLOW%^S%^BOLD%^%^RED%^A"+
			"%^BOLD%^%^YELLOW%^N%^BOLD%^%^RED%^E voice screams inside "+
			"your head as the ruby %^BOLD%^%^WHITE%^E%^BOLD%^%^YELLOW%^"+
			"X%^BOLD%^%^WHITE%^P%^BOLD%^%^YELLOW%^L%^BOLD%^%^WHITE%^O"+
			"%^BOLD%^%^YELLOW%^D%^BOLD%^%^WHITE%^E%^BOLD%^%^YELLOW%^S"+
			"%^BOLD%^%^RED%^!%^RESET%^");
			victim->do_damage("torso", roll_dice(10, 20));
			tell_room(env, "%^BOLD%^%^RED%^The ruby carried by "+
			victim->QCN+"%^BOLD%^%^RED%^ Explodes violently!"+
			"%^RESET%^", victim);
		}
	}
	TO->remove();
}

int manipulate_things(string str)
{
	int lev;
	if(!str) return 0;
	if(!objectp(TO)) return 0;
	if(!objectp(ETO)) return 0;
	if(!living(ETO)) return 0;
	if(str == "invisible beings") 
	{	
		if(di_charges > 0)
		{
			tell_object(ETO, "%^BOLD%^%^CYAN%^A muffled voice whispers to "+
			"you: %^RESET%^YES!!   That's it...");
			if(!random(500)) 
			{
				epic_failure(ETO);
				return 1;
			}
			else
			{
				lev = 10 + random(31);
				new("/cmds/spells/d/_detect_invisibility")->use_spell(ETO, ETO, lev, lev, "mage");
				di_charges--;
				return 1;		
			}
		}
		else
		{
			tell_object(ETO, "%^BOLD%^%^RED%^The ruby fails to respond "+
			"to your attempt.%^RESET%^");
			return 1;
		}
	}
	if(str == "magic protections")
	{
		if(dm_charges > 0)
		{
			tell_object(ETO, "%^BOLD%^%^CYAN%^A muffled voice whispers to "+
			"you: %^RESET%^YES!!   That's it...");
			if(!random(500)) 
			{
				epic_failure(ETO);
				return 1;
			}
			else
			{
				lev = 10 + random(31);
				new("/cmds/spells/d/_dispel_magic")->use_spell(ETO, 0, lev, lev, "mage");
				dm_charges--;
				return 1;		
			}
		}
		else
		{
			tell_object(ETO, "%^BOLD%^%^RED%^The ruby fails to respond "+
			"to your attempt.%^RESET%^");
			return 1;
		}
	}
	return 0;
}

int isMagic()
{
	int x;
	x = ::isMagic();
	return x + 4;
}
