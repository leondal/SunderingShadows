//Shroud of Auros Devar - Gives various bonuses depending on the scene 
//embroidered on the back which changes on occassion - random room 
//emotes *RARELY* (hopefully) based on the scene

#include <std.h>
inherit ARMOUR;
string *SCENES = ({"%^BOLD%^%^CYAN%^A wizard surrounded by a protective ward%^RESET%^",
		"%^BOLD%^%^RED%^A minotaur cleaving hordes of kobolds in twain%^RESET%^", 
		"%^BOLD%^%^GREEN%^A human boy striking at orcs with perfect accuracy%^RESET%^"});
int which, count;

void do_bonus(int now, int then)
{
	switch(then)
	{
		case 0:
			TO->remove_property("magic resistance");
			break;
		case 1:
			TO->remove_property("damage bonus");
			break;
		case 2:
			TO->remove_property("attack bonus");
		default:
			break; //first time it happens (no bonus is set until now)
	}	
	switch(now)
	{
		case 0:
			TO->set_property("magic resistance", 20);
			break;
		case 1:
			TO->set_property("damage bonus", 5);
			break;
		case 2:
			TO->set_property("attack bonus", 5);
			break;
	}
}
	
void create() 
{
    	::create();
	set_weight(10);
    	set_value(4);
	set_property("enchantment", 3);
	which = random(3);
	set_name("a thick black shroud");

	set_id(({"robe", "shroud", "black shroud", "black robe", 
	"auros shroud", "auros robe", "auros devar shroud", 
	"shroud of auros devar", "robe of auros devar"}));

	set_obvious_short("%^BOLD%^%^BLACK%^A thick black shroud%^RESET%^");

	set_short("%^BOLD%^%^BLACK%^Shroud of A%^BOLD%^%^YELLOW%^o%^BOLD%^%^BLACK%^"+
	"'%^BOLD%^%^YELLOW%^r%^BOLD%^%^BLACK%^u%^BOLD%^%^YELLOW%^s %^BOLD%^"+
	"%^BLACK%^D%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^v%^BOLD%^%^RED%^a%^BOLD%^"+
	"%^BLACK%^r%^RESET%^");

	set_long((:TO, "mylong":));

	set_property("lore difficulty", 40);

	set_lore("%^BOLD%^%^BLACK%^This shroud was hand crafted by "+
	"Ao'rus Devar himself many years ago, sometime before he cast "+
	"aside his mortal shell.  It was imbued by a magic which would "+
	"randomly aid the wearer in battle - as a method of intimidation "+
	"he embroidered the robe with a magical thread which allowed "+
	"the scene on it to change - hopefully in the midst of battle - "+
	"to the further advantage of the wearer.  After casting aside "+
	"his mortal shell he gave this shroud to one of underlings."+
	"%^RESET%^");

    	set_type("clothing");
	set_size(-1);
	set_limbs( ({ "torso" }) );
	set_wear((:TO, "wear_me":));
	set_remove((:TO, "remove_me":));
    	set_ac(1);
	count = 0;
	do_bonus(which, -1);
}

int wear_me()
{
	if(ETO->query_highest_level() < 30)
	{
		tell_object(ETO, "%^BOLD%^%^BLACK%^The shroud refuses to be worn "+
		"by someone as weak as you!%^RESET%^");
		return 0;
	}
	if((int)TO->query_property("enchantment") > 0) 
	{
		set_heart_beat(1);
	}	
	tell_object(ETO, "%^BOLD%^%^WHITE%^You carefully tie the "+
	"%^RESET%^%^MAGENTA%^deep v%^BOLD%^io%^RESET%^%^MAGENTA%^l"+
	"%^BOLD%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^ sash around "+
	"your waist.%^RESET%^");
	return 1;
}

int remove_me()
{
	tell_object(ETO, "%^BOLD%^%^WHITE%^You carefully untie the "+
	"%^RESET%^%^MAGENTA%^deep v%^BOLD%^io%^RESET%^%^MAGENTA%^l"+
	"%^BOLD%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^ sash.%^RESET%^");
	return 1;
}

string mylong()
{
	return "%^BOLD%^%^BLACK%^This thick black shroud has been %^BOLD%^%^RED%^"+
	"tailored%^BOLD%^%^BLACK%^ into a robe.  It is %^BOLD%^%^WHITE%^f%^BOLD%^"+
	"%^YELLOW%^a%^BOLD%^%^WHITE%^s%^BOLD%^%^YELLOW%^h%^BOLD%^%^WHITE%^i%^BOLD%^"+
	"%^YELLOW%^o%^BOLD%^%^WHITE%^n%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^"+
	"d%^BOLD%^%^BLACK%^ from a perfect ebon material, that has hints of "+
	"%^BOLD%^%^YELLOW%^gold %^BOLD%^%^BLACK%^intertwined throughout.  It "+
	"is outlined in a contrasting %^BOLD%^%^WHITE%^ivory%^BOLD%^%^BLACK%^ "+
	"thread, that creates the illusion of the rest of the shroud being "+
	"much darker than it actually is.  The sash that ties it closed "+
	"is a %^RESET%^%^MAGENTA%^deep v%^BOLD%^io%^RESET%^%^MAGENTA%^l"+
	"%^BOLD%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ hue.  "+
	"%^BOLD%^%^YELLOW%^E%^BOLD%^%^WHITE%^m%^BOLD%^%^YELLOW%^b"+
	"%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^i"+
	"%^BOLD%^%^YELLOW%^d%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^"+
	"r%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^d%^BOLD%^%^BLACK%^"+
	" on the back of it, in perfect detail, is "+
	SCENES[which]+"%^BOLD%^%^BLACK%^. %^RESET%^";
}

int qc() { return count; }


void heart_beat()
{
	int x;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(EETO)) return;
	if(!query_worn()) return;
	count++;
	if(count > 1800) 
	{
		x = random(3);
		count = 0;
		if(x != which)
		{
			tell_object(ETO, "%^BOLD%^%^WHITE%^You feel a sudden "+
			"movement on the back of your "+
			"%^BOLD%^%^BLACK%^shroud%^BOLD%^%^WHITE%^!%^RESET%^");
			do_bonus(x, which);
			which = x;
			if(!ETO->query_invis()) 
			{
				tell_room(EETO, "%^BOLD%^%^MAGENTA%^The scene embroidered on the "+
				"back of the shroud worn by "+ETOQCN+
				" suddenly changes into "+SCENES[which]+"!%^RESET%^", ETO);
			}
			return;	
		}
	}
	if(ETO->query_invis()) return;
	if(random(5000) < 4985) return;
	switch(which) 
	{
		case 0:
			switch(random(11)) 
			{
				case 0..3:
					tell_object(ETO, "%^BOLD%^%^BLUE%^You hear the "+
					"quiet laughter of "+
					"a jolly old man.%^RESET%^");

					tell_room(EETO, "%^BOLD%^%^BLUE%^A jolly laughter "+
					"escapes the lips of the wizard "+
					"embroidered on the back of "+ETOQCN+"%^BOLD%^"+
					"%^BLUE%^'s shroud.%^RESET%^", ETO);
					return;
					break;
				case 4..7:
					tell_object(ETO, "%^BOLD%^%^YELLOW%^You suddenly "+
					"smell the pungent "+
					"aroma of tobacco.%^RESET%^");

					tell_room(EETO, "%^BOLD%^%^YELLOW%^The wizard "+
					"embroidered on the back "+
					"of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s shroud "+
					"pulls out a pipe and takes a few "+
					"puffs.%^RESET%^", ETO);
					return;
					break;
				case 8..10:
					tell_object(ETO, "%^BOLD%^%^GREEN%^You hear "+
					"a quick chanting.%^RESET%^");
					
					tell_room(EETO, "%^BOLD%^%^GREEN%^The wizard "+
					"embroidered on the back "+
					"of "+ETOQCN+"%^BOLD%^%^GREEN%^'s suddenly chants a loud phrase "+
					"- renewing the protective ward around himself!%^RESET%^", ETO);
					return;
					break;
			}
			break;
		case 1:
			switch(random(11))
			{
				case 0..3:
					tell_object(ETO, "%^BOLD%^%^RED%^You hear a "+
					"suddenly ferocious "+
					"roar!%^RESET%^");
					
					tell_room(EETO, "%^BOLD%^%^RED%^The minotaur "+
					"embroidered on the back "+
					"of "+ETOQCN+"%^BOLD%^%^RED%^'s shroud suddenly roars ferociously!"+
					"%^RESET%^", ETO);
					return;
					break;
				case 4..7:
					tell_object(ETO, "%^BOLD%^%^MAGENTA%^You hear "+
					"a loud snort.%^RESET%^");
				
					tell_room(EETO, "%^BOLD%^%^MAGENTA%^The minotaur "+
					"embroidered on the back "+
					"of "+ETOQCN+"%^BOLD%^%^MAGENTA%^'s shroud snorts "+
					"loudly as its cleaves "+
					"another kobold in twain!%^RESET%^", ETO);
					return;				
					break;
				case 8..10:
					tell_object(ETO, "%^BOLD%^%^BLACK%^The clamber "+
					"of battle suddenly "+
					"erupts all around you but dies back "+
					"down in an instant!%^RESET%^");
				
					tell_room(EETO, "%^BOLD%^%^BLACK%^The minotaur "+
					"embroidered on the back "+
					"of "+ETOQCN+"%^BOLD%^%^BLACK%^'s shroud almost "+
					"appears overwhelmed by a "+
					"group of kobolds, then suddenly charges them!%^RESET%^", ETO);
					return;
					break;
			}
			break;
		case 2:
			switch(random(11))
			{
				case 0..3:
					tell_object(ETO, "%^BOLD%^%^YELLOW%^You hear the "+
					"sound of a young "+
					"boy giggling.%^RESET%^");
					
					tell_room(EETO, "%^BOLD%^%^YELLOW%^The human "+
					"boy embroidered on the "+
					"back of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s shroud giggles softly to "+
					"himself.%^RESET%^", ETO);
					return;
					break;
				case 4..7:
					tell_object(ETO, "%^BOLD%^%^GREEN%^You hear what "+
					"sounds like "+
					"steel striking against steel.%^RESET%^");
			
					tell_room(EETO, "%^BOLD%^%^GREEN%^The human boy "+
					"embroidered on the "+
					"back of "+ETOQCN+"%^BOLD%^%^GREEN%^'s shroud suddenly strikes "+
					"a large orc three times with a steel dagger!%^RESET%^", ETO);
					return;
					break;
				case 8..10:
					tell_object(ETO, "%^BOLD%^%^MAGENTA%^You hear the sigh of a "+
					"young boy.%^RESET%^");
					
					tell_room(EETO, "%^BOLD%^%^MAGENTA%^The human boy embroidered on "+
					"the back of "+ETOQCN+"%^BOLD%^%^MAGENTA%^'s shroud sighs "+
					"softly to himself.%^RESET%^", ETO);
					return;
					break;
			}
			break;
	}
			
	return;
}

