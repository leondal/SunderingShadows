#include <std.h>
#include "../defs.h"
inherit MONSTER;

// Coral Sea Area - Created January 2009 by Ari

object ob;

void create(){
	::create();
	set_name("captain zeralquin");
	set_id(({"captain","zeralquin","zeralquin","Captain Zeralquin",
		"captain zeralquin","undead"}));
	set_race("half-drow");
	set_gender("male");
	
	set_short("Captain Zeralquin");
	set_long("%^RESET%^%^CYAN%^A rugged, fierce looking man in life, "+
		"Captain Zeralquin is no less daunting in death.  Clad in "+
		"armor made of %^GREEN%^seaweed %^CYAN%^and %^RESET%^shell"+
		"%^CYAN%^, he seems a fitting addition to this underwater "+
		"realm.  A thick captain's coat, thigh high boots and sharp "+
		"looking leather pants complete the ensemble.  Void of the "+
		"traditional tri-corner captain's hat, his %^BOLD%^%^BLACK%^"+
		"dark dreadlocks %^RESET%^%^CYAN%^swirl around him in a nest "+
		"of %^RESET%^shell %^CYAN%^and %^BOLD%^%^WHITE%^bone %^RESET%^"+
		"%^CYAN%^adorned ropes that look almost alive as they float "+
		"in the water.  Skin dark as pitch peels back from a sharp "+
		"nose, cheeks and the chin bone revealing a yellowed and "+
		"cracked skull beneath.  Though this hardly stands out "+
		"against the demonic glow of his %^RED%^red eyes%^CYAN%^.  "+
		"It dawns upon you then that Zeralquin was never completely "+
		"human.%^RESET%^");
	
	set_size(2);
	set_body_type("human");
	set_alignment(9);
	set_level(30);
	set_hd(20,2);
	set_max_hp(random(300)+1300);
	set_hp(query_max_hp());
	set_overall_ac(-5);
	set_mob_magic_resistance("average");
	set_property("swarm",1);
	set_class("ranger");
	set_mlevel("ranger",22);
	set_guild_level("ranger",22);
		add_search_path("/cmds/ranger");
	set_exp(12000);
	set_max_level(30);
	set_property("no stealing",1);
	set("aggressive","agg_func");
	set_property("water breather",1);
		
	set_stats("strength",18);
	set_stats("intelligence",18);
	set_stats("wisdom",14);
	set_stats("dexterity",18);
	set_stats("constitution",15);
	set_stats("charisma",10);
	
	ob = new(OBJ"kelpwrap");
		ob->move(TO);
		command("wear armor");
	ob = new(OBJ"belaypin");
		ob->move(TO);
		if(random(6)) ob->set_property("monsterweapon",1);
		command("wield pin");
	ob = new(OBJ"sharkskinwhip");
		ob->move(TO);
		if(random(6)) ob->set_property("monsterweapon",1);
		command("wield whip");
	ob = new(OBJ"coral_compass");
		ob->move(TO);
	set_property("add kits",24);
	
	set_achats(10,({"%^BOLD%^%^BLUE%^Captain Zeralquin turns just "+
			"in time to avoid an attack and brings his weapons "+
			"about driving them home!%^RESET%^",
		"%^BOLD%^%^CYAN%^With a swift dive, Zeralquin comes up "+
			"right behind you!",
		"%^BOLD%^%^GREEN%^The currents shift suddenly, forcing you "+
			"to regain yourself!",
		"%^BOLD%^%^BLACK%^Zeralquin's hair appears to come to life, "+
			"lashing forward to confuse and distract you!"}));
}

void agg_func(){
	if(TP->query_invis()){return;}
		force_me("emote swims forward, his weapons aimed right "+
			"at you!");
		force_me("kill "+TP->query_name());
		force_me("whirl");
	return;
}

void heart_beat(){
	::heart_beat();
		if(!objectp(TO)){return;}
		if(!objectp(ETO)){return;}
		if(!objectp(TO) || !objectp(ETO)) return;
		if(query_hp()< 200 && present("vial",TO)){
			force_me("quaff vial");
			force_me("quaff vial");
			force_me("quaff vial");
		}
}
