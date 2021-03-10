#include <std.h>

inherit WEAPONLESS;

void create()
{
	::create();
   	set_name("giant bloated maggot");
   	set_id( ({ "maggot", "bloated maggot" }) );
   	
	set_gender("male");

   	set_short("%^RESET%^%^ORANGE%^A giant bloated maggot%^RESET%^");

   	set_long("%^BOLD%^%^YELLOW%^This ugly bloated creature "+
	"looks as if it is about to rip apart with tremendous force.  "+
	"Its bulbous grotesque body ripples with every movement "+
	"it makes.  An enormous mouth rests at one end of its "+
	"body, gaping open rudely, with suction like grips "+
	"surrounding it.  A terrible odor is given off by it, "+
	"almost like a mixture of rotted meat heavily tainted "+
	"by death.%^RESET%^");

   	set_body_type("larva");
	set_race("maggot");

	add_limb("mouth", 0, 0, 0, 0);
	add_limb("body", 0, 0, 0, 0);
	set_attack_limbs(({"mouth"}));
   	set_alignment(9);
     	set_property("swarm",1);
   	set_property("full attacks",1);
     	set("aggressive",26);
}

void scale_to(int lev)
{
	int mod;
	if(!intp(lev)) return;
	set_hd(lev, 1);
	set_mlevel("fighter", lev);
	set_guild_level("fighter", lev);
	mod = lev / 10;
	set_overall_ac(0 - (mod+4));
	set_stats("intelligence",6);
   	set_stats("wisdom",6);
   	set_stats("strength",17+mod);
   	set_stats("charisma",6);
   	set_stats("dexterity",10);
   	set_stats("constitution",10+mod);
	set_hp((15*lev)+random(lev));
	set_max_hp(query_hp());
	set_max_level(lev+5);
	mod = lev - 5;
	if(mod < 1) mod = 1;
	set_new_exp(mod, "very low");
}

