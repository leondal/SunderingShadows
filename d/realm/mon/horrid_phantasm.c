#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;
string o_short;

void create() 
{
	object wpn1;
	int x;
   	::create();
	set_name("horrid phantasm");
		
	set_id(({"horrid phantasm", "phantasm", "a horrid phantasm"}));
			
	o_short = "%^BOLD%^%^WHITE%^A H%^BOLD%^%^RED%^o"+
	"%^BOLD%^%^WHITE%^rr%^BOLD%^%^RED%^i%^BOLD%^%^WHITE%^"+
	"d %^BOLD%^%^WHITE%^Ph%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^"+
	"nt%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^sm%^RESET%^";
	
	set_short(o_short);
		
	set_long("%^BOLD%^%^WHITE%^This phantom creature looks "+
	"as if it were once human, at least in a time long past.  "+
	"Its very outline is now faded and only by some unseen "+
	"force does it manage to remain here.  The features that you "+
	"can make out are warped and twisted at odd angles.  "+
	"It's face is smashed in as if in life "+
	"it suffered some type of brutal death.  The eyes, which "+
	"glare outward from it in immense anger, are a hollow "+
	"%^BOLD%^%^BLACK%^black%^BOLD%^%^WHITE%^.  The limbs "+
	"which jut out from its barely discernable torso are twisted "+
	"at odd angles.  The arms of this thing end in "+
	"long, half broken, vicious claws.%^RESET%^");

	set_race("phantasm");			
		
	set_body_type("human");
   	set_gender("neuter");
   	set_size(3);
   	set_alignment(9);
	x = 42 + random(4);
   	set_hd(x, 10);
   	set_level(x);
   	set_overall_ac(-20);
   	set_guild_level("fighter",x);
	set_mlevel("fighter", x);
   	set_max_hp(600 + random(100));
   	set_hp(query_max_hp());
	add_limb("left claw","left hand",0,0,0);
   	add_limb("right claw","right hand",0,0,0);
   	set_attack_limbs(({"left claw", "right claw"}));
	set_damage(3,8);
	set_attacks_num(6);
   	set_property("swarm",1);
	set_property("full attacks", 1);
   	set_property("no_bump",1);
   	set_stats("strength",18);
   	set_stats("dexterity",25);
   	set_stats("constitution",17);
   	set_stats("wisdom",7);
   	set_stats("intelligence",7);
   	set_stats("charisma",3);
   	set_mob_magic_resistance("average");
	set_property("weapon resistance", 3);
   	set_new_exp(35, "normal");
	set_attack_bonus(10);
	set("aggressive",25);
	set_property("death effects", "any");
}

void heart_beat()
{
	int mod;
	::heart_beat();
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!sizeof(TO->query_attackers())) return;
	if(random(25)) return;
	if(find_call_out("vulnerable_again") != -1) return;
	tell_room(ETO, "%^BOLD%^%^RED%^The horrid phantasm %^BOLD%^"+
	"%^CYAN%^GLOWS BRIGHTLY%^BOLD%^%^RED%^ with a red aura!%^RESET%^");
	TO->set_short(o_short + "%^BOLD%^%^WHITE%^ (%^BOLD%^%^RED%^"+
	" surrounded by a red aura%^BOLD%^%^WHITE%^ )%^RESET%^");
	TO->set_property("damage resistance", 100000);	
	//TO->set_attacks_num(3);
	mod = 2;// + random(2);
	call_out("vulnerable_again", (6 * mod));
	return;
}

void vulnerable_again()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	//TO->set_attacks_num(6);
	TO->set_short(o_short);
	TO->remove_property("damage resistance");
	tell_room(ETO, "%^BOLD%^%^RED%^The %^BOLD%^%^CYAN%^GLOWING"+
	"%^BOLD%^%^RED%^ aura around the phantasm fades away!%^RESET%^");
	return;
}

void die(object ob)
{
	if(!objectp(TO)) return;
	TO->set_short(o_short);
	::die(ob);
}


