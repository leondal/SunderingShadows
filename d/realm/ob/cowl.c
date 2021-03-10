#include <std.h>
inherit "/d/common/obj/armour/coif_leather";
int charges;
int flag = 0;

void create() 
{
	::create();
    	set_name("cowl");
    	set_id(({"cowl", "Cowl", "cowl of concealment", "violet cowl", 
	"deep violet cowl"}));
    	set_short("%^BOLD%^%^MAGENTA%^C%^RESET%^%^MAGENTA%^"+
	"o%^BOLD%^%^MAGENTA%^w%^RESET%^%^MAGENTA%^l %^BOLD%^%^MAGENTA%^of "+
	"%^BOLD%^%^MAGENTA%^C%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^n%^RESET%^"+
	"%^MAGENTA%^c%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^"+
	"l%^RESET%^%^MAGENTA%^m%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^n%^BOLD%^"+
	"%^MAGENTA%^t%^RESET%^");
	set_obvious_short("a deep violet cowl");

	set_long("%^BOLD%^%^MAGENTA%^This fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^MAGENTA%^l"+
	"%^BOLD%^%^YELLOW%^e%^BOLD%^%^MAGENTA%^ss cowl is made from a thick "+
	"v%^RESET%^%^MAGENTA%^io%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^e%^BOLD%^"+
	"%^MAGENTA%^t fabric.  It has been stitched together perfectly, the result of "+
	"an obviously br%^BOLD%^%^YELLOW%^i%^BOLD%^%^MAGENTA%^ll%^BOLD%^%^WHITE%^i"+
	"%^BOLD%^%^YELLOW%^a%^BOLD%^%^MAGENTA%^nt tailor.  A m%^BOLD%^%^WHITE%^a"+
	"%^BOLD%^%^MAGENTA%^gn%^BOLD%^%^WHITE%^i%^BOLD%^%^MAGENTA%^f"+
	"%^BOLD%^%^WHITE%^i%^BOLD%^%^MAGENTA%^c%^BOLD%^%^WHITE%^e%^BOLD%^%^MAGENTA%^"+
	"nt gr%^BOLD%^%^YELLOW%^a%^BOLD%^%^MAGENTA%^c%^BOLD%^%^YELLOW%^e"+
	"%^BOLD%^%^MAGENTA%^f%^BOLD%^%^YELLOW%^u%^BOLD%^%^MAGENTA%^l "+
	"ea%^RESET%^%^MAGENTA%^gl%^BOLD%^%^MAGENTA%^e has been embroidered "+
	"onto the back of it, its wings stretched wide in mid soar.  This is apparently "+
	"the signature mark of the tailor responsible for its creation.  It fits "+
	"snugly and even though it is thick, you dont believe it would "+
	"offer much protection in the fray of combat.%^RESET%^");
	set_property("lore difficulty", 30);

	set_lore("%^BOLD%^%^MAGENTA%^This cowl is one of many created by a "+
	"tailor whos name was been forgotten with the passing of time.  "+
	"Legends suggest that he was a bard who wandered the realm quite "+
	"frequently, both adventuring and causing much trouble in local pubs "+
	"and with local wenches.  He is said to have imbued these cowls "+
	"with the ability to %^BOLD%^%^WHITE%^fade%^BOLD%^%^MAGENTA%^ "+
	"away from vision, should he ever need to get away without being "+
	"seen, then to %^BOLD%^%^WHITE%^emerge%^BOLD%^%^MAGENTA%^ "+
	"when the trouble had passed.  No one is for sure what eventually "+
	"befell the troubled man.%^RESET%^");

	set_value(15000);
    	set_property("enchantment",2);
    	set_wear((:TO,"wear_me":));
    	set_remove((:TO,"remove_me":));
    	set_size(-1);
	charges = random(10) + 12;//slightly more charges than a jade ring - Saide
	
}

void init()
{
	::init();
	add_action("fade", "fade");
	add_action("emerge", "emerge");
}

int wear_me() 
{
	if(ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) 
	{
		ETO->send_paralyzed_message("info",TP);
		return 0;
	}
	if(TP->query_highest_level() < 25) 
	{
		tell_object(ETO, "%^BOLD%^%^RED%^The cowl refuses to be "+
		"worn by one of your power!%^RESET%^");
		return 0;
	}
	tell_object(ETO, "%^BOLD%^%^MAGENTA%^You feel a powerful %^BOLD%^%^CYAN%^"+
	"energy%^BOLD%^%^MAGENTA%^ flow outward from the cowl as you slip it on.%^RESET%^");
	return 1;
}

int remove_me() 
{
	tell_object(ETO, "%^BOLD%^%^MAGENTA%^You remove the cowl and "+
	"feel the %^BOLD%^%^CYAN%^energy%^BOLD%^%^MAGENTA%^ leave you.%^RESET%^");
	if(flag == 1) 
	{
		flag = 0;
		if(ETO->query_magic_hidden()) ETO->set_magic_hidden(0);		
	}
	return 1;
}

int fade() 
{
	if(query_worn()) 
	{
		if(ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) 
		{
			ETO->send_paralyzed_message("info",TP);
			return 1;
		}
		if((int)TP->query_magic_hidden()) 
		{
			tell_object(ETO, "%^BOLD%^%^CYAN%^You are already faded from view!%^RESET%^");
			return 1;
		}
		if(charges > 0) 
		{
			flag = 1;
			tell_object(ETO,"%^BOLD%^%^MAGENTA%^You draw upon the %^BOLD%^%^CYAN%^"+
			"energy%^BOLD%^%^MAGENTA%^ of the cowl to fade from vision.%^RESET%^");
			tell_room(EETO, ETOQCN+"%^BOLD%^%^MAGENTA%^ fades away from vision.%^RESET%^", ETO);		
			TP->set_magic_hidden(1);
			charges = charges - 1;
			return 1;
		}
		if(charges <= 0) 
		{
			tell_object(ETO, "%^BOLD%^%^RED%^The cowl has spent all of its "+
			"energy.%^RESET%^");
			return 1;
		}	
	}
	else 
	{
		tell_object(ETO, "%^BOLD%^%^RED%^You must be wearing the cowl to use its "+
		"energy.%^RESET%^");	
		return 1;
	}			
}

int emerge() 
{
	if(query_worn()) 
	{
		if(!flag)
		{
			tell_object(ETO, "%^BOLD%^%^RED%^You are not currently using the "+
			"energy of the cowl.%^RESET%^");
			return 1;
		}
		if(flag == 1) 
		{
			tell_object(ETO,"%^BOLD%^%^MAGENTA%^You emerge back into vision.%^RESET%^");
			flag = 0;
			if(ETO->query_magic_hidden()) ETO->set_magic_hidden(0);
			tell_room(EETO, ETOQCN + "%^BOLD%^%^MAGENTA%^ emerges from nowhere!%^RESET%^",ETO);
			return 1;
		}
	}
	else 
	{
		tell_object(ETO, "%^BOLD%^%^RED%^You must be wearing the cowl to use its "+
		"energy.%^RESET%^");	
		return 1;
	}	
}

	

		


