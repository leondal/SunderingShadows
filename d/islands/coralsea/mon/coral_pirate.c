#include <std.h>
#include "../defs.h"
inherit MONSTER;

// Coral Sea Area - Created January 2009 by Ari

object ob;

create() {
	::create();
	set_name("undead pirate");
	set_id(({"pirate","undead pirate","zombie","fishrinn"}));
	set_gender("male");
	set_race("undead");
	set_short("undead pirate");
	set_body_type("human");
	set_alignment(6);
	set_hd(22,10);
	set_stats("strength",22);
	set_stats("aggressive",3);
	set_size(2);
	set_property("swarm",1);
	set_wielding_limbs(({"right hand","left hand"}));
	set_overall_ac(-3);
	set_hp(300+random(100));
	set_exp(3500);
	set_max_level(30);
	set_property("water breather",1);
	set("aggressive","agg_func");
		add_search_path("/cmds/ranger");
	
	force_me("message in swims in.");
    force_me("message out swims $D.");
	
	set_nogo(({ROOMS"coral_s2",ROOMS"coral_s10",ROOMS"coral_s8",
		ROOMS"coral_s4",ROOMS"coral_s1",ROOMS"coral_t1",
		ROOMS"coral_w7"}));
	
	if(random(2)) {  
    set_long("%^RESET%^%^CYAN%^These are the %^BOLD%^%^BLACK%^"+
		"bloated remains %^RESET%^%^CYAN%^of a dead pirate who "+
		"still lingers amongst the husk of its ruined ship, serving "+
		"her faithfully even in death.  The creature has thick, "+
		"puffy skin that is cracked and broken, revealing jagged "+
		"fractured %^WHITE%^bones %^CYAN%^below and water-swollen "+
		"%^MAGENTA%^tissue%^CYAN%^ between.  Tiny %^WHITE%^fish "+
		"%^CYAN%^dart in and out of these holes, nibbling at the "+
		"%^BOLD%^%^BLACK%^rotting flesh %^RESET%^%^CYAN%^and slowly "+
		"reducing the creature to little more then bone and unholy "+
		"energy.  Scraps of cloth and stringy bits of hair still "+
		"cling to the corpse, while the occasional flash of a "+
		"%^MAGENTA%^jewel %^CYAN%^or a bit of %^WHITE%^metal "+
		"%^CYAN%^can be witnessed amongst the ruined wreckage of "+
		"this undead being's flesh.%^RESET%^");
	}
	else {
	set_long("%^RESET%^%^CYAN%^Bits of skin cling to the pale, "+
		"ashy %^WHITE%^bones %^CYAN%^of this undead pirate.  Still "+
		"haunting the remains of its broken ship, this creature "+
		"moves through the waters with fierce determination.  "+
		"%^BOLD%^%^BLACK%^Unholy energy %^RESET%^%^CYAN%^holding "+
		"it together despite the constant movement and tugging of "+
		"waves.  Small %^WHITE%^fish %^CYAN%^dart in and out of the "+
		"body cavity, gobbling up what little remains of the "+
		"%^MAGENTA%^flesh%^CYAN%^ that once encased the skeleton "+
		"and leaving the bones polished and glossy.  A few scraps "+
		"of %^BOLD%^%^BLACK%^cloth %^RESET%^%^CYAN%^and the "+
		"occasional glint of %^MAGENTA%^jewelry %^CYAN%^can still "+
		"be seen upon this undead being.%^RESET%^");
	}

	if(random(2)){
	ob = new(OBJ"pikeofthedepths");
		if(random(4)) ob->set_property("monsterweapon",1);
		ob->move(TO);
	ob = new(OBJ"coralscape");
		if(random(8)) ob->set_property("monsterweapon",1);
		ob->move(TO);
	command("wield pike");
	command("wear armor");
	}
	else{
	ob = new(OBJ"sharkskinwhip");
		if(random(4)) ob->set_property("monsterweapon",1);
		ob->move(TO);
	ob = new(OBJ"belaypin");
		if(random(4)) ob->set_property("monsterweapon",1);
		ob->move(TO);
	ob = new(OBJ"coralscape");
		if(random(8)) ob->set_property("monsterweapon",1);
		ob->move(TO);
	command("wield pin");
	command("wield whip");
	command("wear armor");
	}
}

void agg_func(){
	if(TP->query_invis()){return;}
		force_me("emote glows with the %^BOLD%^%^BLACK%^unholy "+
			"light%^RESET%^ of %^RED%^death%^RESET%^!");
		force_me("kill "+TP->query_name());
		force_me("rush "+TP->query_name());
	return;
}

void heart_beat(){
   ::heart_beat();
   		if(!objectp(TO)){return;}
		if(!objectp(ETO)){return;}
		if(base_name(ETO) == ROOMS"coral_b2" || 
			base_name(ETO) == ROOMS"coral_b5" || 
			base_name(ETO) == ROOMS"coral_s4" || 
			base_name(ETO) == ROOMS"coral_s8" || 
			base_name(ETO) == ROOMS"coral_s10" || 
			base_name(ETO) == ROOMS"coral_s2"){
		tell_room(ETO,"%^BOLD%^%^BLACK%^The pirate swims "+
			"off, looking for treasure.%^RESET%^");
		TO->move("/d/shadowgate/void");
		TO->remove();
	}
}

