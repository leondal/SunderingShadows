#include <std.h>
#include <daemons.h>
#include "secrets.h"
inherit MONSTER;

int dlevel;
object ob;

void create() {
    	::create();
    	set_name("dwarf worker");
    	set_id(({"monster","dwarf","dwarf worker","worker"}));
    	set_short("dwarf worker");
   	set_wimpy(15);
    	set_long("The dwarf is covered in dust and dirt like "+
    		"he has recently come from an underground dig.  He "+
    		"is naked from the waist up, but his long brown "+
    		"beard, chest, and back hair cover his torso as "+
    		"effectively as any shirt.  He wears simple leather "+
    		"breeches and low, hard, mud-covered boots.  His face "+
    		"and chest is cover with sweat streaked dirt and he carries a hammer. ");
    	set_body_type("humanoid");
    	dlevel = random(6) + 7;
    	set_hd(dlevel,6);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
    	add_search_path("/cmds/fighter");
      set_wielding_limbs(({"right hand","left hand"}));
    	set_size(1);
   	set_stats("intelligence",10);
    	set_stats("wisdom",11);
    	set_stats("strength",17);
    	set_stats("charisma",8);
    	set_stats("dexterity",13);
    	set_stats("constitution",19);
    	set_alignment(5);
    	set_race("dwarf");
    	set_overall_ac(8);
    	set_exp(dlevel*20);
    	set_max_hp((random(90)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_property("full attacks",1);
      ob = new(CWEAP+"hammer_sm.c");
    		ob->set_property("monsterweapon", 1);
    	   ob->set_property("enchantment",2);
			ob->move(TO);
    		command("wield hammer");
    	set_max_level(8);
    	command("speak dwarvish");
    	command("speech grumble");
    	set_property("swarm",1);
    	if(present("supervisor")) command("protect supervisor");
}