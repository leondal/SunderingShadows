#include <std.h>

inherit MONSTER;

void create()
{
	::create();
   	set_name("skeleton");
   	set_id( ({ "skeleton","skeleton guard" }) );
   	set_race("undead");
   	set_gender("male");
   	set_short("A skeleton");
   	set_long("%^BOLD%^%^WHITE%^This skeletal creature is the "+
   	"unliving remains of what was once a human.  Its body is "+
   	"nothing more than bones, some which have tattered "+
   	"bits of rotting flesh attached and some which have "+
   	"been picked clean.  Much of its body is caked with "+
   	"the remains of armor that was once made from a dark "+
   	"leather, but has faded over the course of time.  The "+
   	"armor has began the process of decaying and now "+
   	"remains only in tatters.  The eye sockets of this "+
   	"creature are a dull black, with a slight %^RED%^"+
   	"ember of red%^BOLD%^%^WHITE%^, inset into its "+
   	"contrasting white skull.%^RESET%^");
   	set_body_type("human");
   	set_alignment(9);
   	set_size(2);
   	set_hd(22 + random(4),1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",17 + random(2));
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_hp(query_hd() * 14 + random(11));
   
   	new("/d/common/obj/weapon/shortsword")->move(TO);
     	command("wield sword");
   	if(query_hd() > 9) 
	{
   		new("/d/common/obj/weapon/shortsword")->move(TO);
     		command("wield sword");
   	}
   	add_money("electrum",random(10));
   	add_money("silver",random(10));
   	add_money("gold",random(5));
   	add_money("copper",random(20));
   	set_property("undead",1);
   	set_property("swarm",1);
   	set_property("no death",1);
   	set_property("full attacks",1);
   	set_overall_ac(7);
   	set_property("no paralyze",1);
   	set("aggressive",26);
   	set_max_level(18);
}

void scale_to(int lev)
{
	int mod;
	if(!intp(lev)) return;
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

