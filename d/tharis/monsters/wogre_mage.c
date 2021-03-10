//removed scorcher from spell list due to bugs with it & changed body type to
//human in case that was causing some of them. - Styx 12/23/01

//wOgre.c

#include <std.h>

inherit "/d/tharis/monsters/fwander";

void create(){
	object ob;
	::create();
	
	set_name("ogre mage");
	set_id(({"ogre","ogre mage","mage","Ogre"}));
	set_short("Ogre mage");
	set_long( (: TO, "ldesc" :) );
	set_hd(10,8);
	set_hp(80);
	set_exp(1200);
	set_body_type("human");
	set_race("ogre mage");
	set_gender("male");
        set_size(3);
	set_stats("intelligence",18);
	set_stats("strength",19);
	set_stats("wisdom",19);
	set_stats("constitution",18);
	set_stats("wisdom",6);
	set_stats("charisma",1);
    set_class("mage");
    set_mlevel("mage",15);
   set_guild_level("mage",15);
	set_spells(({"fireball","lightning bolt","cone of cold","magic missile"}));
	set_mob_magic_resistance("average");
	set_wielding_limbs(({"right hand","left hand"}));
	set_overall_ac(2);
	ob = new("/d/tharis/obj/greenrobe");
	   if(random(20)) ob->set_property("monsterweapon", 1);
	   ob->move(TO);
	   command("wear robe");
        set_max_level(18);
        ob = new("/d/tharis/obj/katana");
	  if(random(5)) ob->set_property("monsterweapon", 1);
          ob->move(TO);
	command("wield katana");
	set_spell_chance(50);
	set_alignment(3);
}

void init(){
	::init();
	
	if(ALIGN->is_good(TP) && !TP->query_invis())
		kill_ob(TP,1);
	}
	
int kill_ob(object victim, int which){
	object *inven;
	int i,k;
	if(!swarm){
  	if(victim == TP && interactive(TP)){

           swarm = 1;
                inven = all_inventory(environment(TO));
                k = sizeof(inven);
                for(i=0;i<k;i++){
                        if(living(inven[i])){
                            if(ALIGN->is_evil(inven[i])){
                            	 if(inven[i] != TP)
                                 	inven[i]->kill_ob(TP,1);
                             }
                        }
                }
        }
        swarm = 0;
     }
	return ::kill_ob(victim,which);
}

string ldesc(string str) {
   return("This sharply cut creature is quite impressive.  A bluish brown "
     "skin is streched tightly across his sharp face.  You realize that "
     "just as the elven rangers have come to help in the battle these "
     "creatures have come much farther to join the the evil side.");
}
