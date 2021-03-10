#include <std.h>
#include <daemons.h>
#include "secrets.h"
inherit MONSTER;

int dlevel;
object ob;

void makeem(object targ);

void create() {
    	::create();
    	set_name("dwarf supervisor");
    	set_id(({"monster","dwarf","dwarf supervisor","supervisor"}));
    	set_short("dwarf supervisor");
   	set_wimpy(20);
    	set_long("The dwarf is covered in dust and dirt like "+
    		"he has recently come from an underground dig.  He "+
    		"is naked from the waist up, but his long brown "+
    		"beard, chest, and back hair cover his torso as "+
    		"effectively as any shirt.  He wears simple leather "+
    		"breeches and low, hard, mud-covered boots.  His face "+
    		"and chest is cover with dirt, but he does not appear "+
    		"to have been sweating recently.  In addition to "+
    		"breeches he wears a simple leather cap and carries a hammer.");
    	set_body_type("humanoid");
    	dlevel = random(8) +10;
    	set_hd(dlevel,6);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(5);
    	set_race("dwarf");
    	set_gender("male");
    	set_overall_ac(7);
    	set_stats("strength",18);
    	set_stats("dexterity",14);
   	set_stats("intelligence",11);
    	set_stats("wisdom",11);
    	set_stats("charisma",9);
    	set_stats("constitution",19);
    	set_exp(dlevel*25);
    	set_max_hp((random(120)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_achats(3,({
			"%^ORANGE%^Dwarf supervisor grates: %^RESET%^AHHH, I needed a break!",
			"Dwarf supervisor yells for the guards.",
			"%^ORANGE%^Dwarf supervisor grates: %^RESET%^I plan on messing ya up a bit!",
			"%^ORANGE%^Dwarf supervisor grates: %^RESET%^Sorry, this is fun, but "+
				"I gotta make this quick and get back to work!",
			"%^ORANGE%^Dwarf supervisor grates: %^RESET%^My hammer's gonna dent "+
				"that head of yers!",
			"%^ORANGE%^Dwarf supervisor grates: %^BOLD%^%^RED%^TEMPUS AID ME NOW!!%^RESET%^"
    	}));
    	set_emotes(8,({
    		"Dwarf supervisor looks over the room very carefully and nods slowly.",
    		"Dwarf supervisor puts his ear to the ground and listens carefully.",
    		"%^ORANGE%^Dwarf supervisor grates: %^RESET%^This whole area "+
    			"is unstable, gots to come down it does!",
    		"%^ORANGE%^Dwarf supervisor grates: %^RESET%^just checkin' the "+
    			"place out, don't mind us.",
    		"%^ORANGE%^Dwarf supervisor grates: %^RESET%^This where we start?",
			"Dwarf supervisor stamps on the ground and nods knowingly.",
			"Dwarf supervisor taps his hammer against the ground and listens attentively.",
			"Dwarf supervisor coughs and harks up a large chunk of something "+
				"then turns his head and spits it to the side.",
			"%^ORANGE%^Dwarf supervisor grates: %^RESET%^Damn clients never know "+
				"their head from their arse.",
			"%^ORANGE%^Dwarf supervisor grates: %^RESET%^Everyone knows "+
				"granite is the best foundation...EVERYONE...Tempus help "+
				"me!\n%^ORANGE%^Dwarf supervisor grates: %^RESET%^The why "+
				"the hell they use so much gypsum!!\n\nDwarf supervisor rolls his eyes.",
			"%^ORANGE%^Dwarf supervisor grates: %^RESET%^Where is the rest of "+
				"that dad-blamed lazy-arse crew a' mine!",
    	}),0);
    	ob = new( CWEAP+"hammer_sm.c" );
     		ob->set_property("monsterweapon", 1);
     		ob->set_property("enchantment",2);
   		ob->move(TO);
    		command("wield hammer");
    	command("speak dwarvish");
    	command("speech grate");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(20);
  		set_size(1);
    	set_property("swarm",1);
    	set_speed(20);
		set_property("knock unconscious",1);
		
		call_out("makeem",0,TO);
}
void makeem(object targ){
	ob = new(SECR+"dwarf_work");
		ob->move(ETO);
		targ->add_follower(ob);

	if(!random(2)){
		ob = new(SECR+"dwarf_work");
			ob->move(ETO);
			targ->add_follower(ob);
	}
	if(!random(2)){
		ob = new(SECR+"dwarf_work");
			ob->move(ETO);
			targ->add_follower(ob);
	}
}
