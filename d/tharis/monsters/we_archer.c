//several changes (noted) to attempt to elimate errors in debug.log-Styx 12/23/01
//also added more checks for valid objects
//we_archer.c, by Tristan

#include <std.h>
#include "/d/common/common.h"

inherit "/d/tharis/monsters/fwander";

void do_check();
void do_bow();
int evil(object thing);
object ob;

int count;

void create(){
	::create();
	
	set_name("elven archer");
	set_id(({"archer","elf","elven archer","e_archer"}));
	set_short("An elven archer");
	set_long( (: TO, "ldesc" :) );
	set_alignment(1);
	set_race("elf");
	set_class("ranger");
	set_gender("male");
	set_body_type("human");
	set_hd(20,8);
	set_exp(3500);
	set_hp(150+random(20));
	set_overall_ac(-5);
	set_wielding_limbs(({"right hand","left hand"}));
	if(!random(5)) {
	   add_money("gold",random(100)+50);
	   add_money("electrum",random(50));
	}
	ob = new(CLRWEAP"shortbow");
	  ob->set_property("monsterweapon",1);
	  ob->move(TO);
	  command("wield bow");
	ob = new(CLRWEAP"arrows");
	  ob->set_property("monsterweapon",1);
	  ob->move(TO);
        set_property("full attacks",1);
	ob = new(CWEAP"longsword");
	   ob->set_property("monsterweapon",1);	
	   ob->move(TO);
	ob = new(CWEAP"longsword");
	   ob->set_property("monsterweapon",1);	
	   ob->move(TO);
	set_stats("strength",17);
	set_stats("dexterity",17);
        set_max_level(25);
}

void start_heart(){	
	set_heart_beat(1);
}
	
void heart_beat(){
	::heart_beat();
//moved stuff below from before to after the ::heart_beat() to let heart_beat 
//finish before trying to do them.
	
	count++;
//added following check for valid object & environment first.
	if(objectp(TO) && objectp(ETO))  do_check();
        if(count < 5)   return;
	if(objectp(query_weapon("right hand")))
	   if((string)query_weapon("right hand")->query_name() != "longsword")
		do_bow();
}

void do_bow(){
   int i,j, y,z;
   object ob, *inven, *living_bad;
   string exit,*paths, *ids;
   living_bad = ({});
   
   if(ETO && objectp(ETO)){
   	paths = ETO->query_destinations();
	if(j = sizeof(paths)){
	   for(i=0;i<j;i++){
		if(ob = find_object_or_load(paths[i]) && objectp(ob)){
		   inven = all_inventory(ob);
		   z = sizeof(inven);
		   for(y=0;y<z;y++)
		   if(living(inven[y]) && evil(inven[y])){
			living_bad += ({inven[y]});
		   }
		   if(z = sizeof(living_bad)){
		     y = random(z);
//added check for invis.  Put it here rather than excluding them from living_bad
//so if there is an elf 2 etc. it will have the target id right - Styx 12/29/01
		     if(living_bad[y]->query_invis())  break;  
		     exit = ETO->query_direction(paths[i]);
		     if(!interactive(living_bad[y])){	
			ids = living_bad[y]->query_id();
			command("shoot "+ids[0]+" 1 "+exit);
		     }
		     else
		     command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
		     break;
		   }
	        }
	   }
	}
   }
   count = 0;
}

int evil(object thing){
	if((int)thing->query_alignment() == 3 || (int)thing->query_alignment() == 6 || (int)thing->query_alignment() == 9)
	    return 1;
	return 0;
}

void do_check(){
	object *weapons;
	int i;
	weapons = TO->query_wielded();
	if(sizeof(weapons)){
		if((string)weapons[0]->query_name() != "shortbow"){
			if((object *)TO->query_attackers() == ({})){
				command("unwield sword");
				command("unwield sword 2");  //was just unwield sword, so didn't work
				command("wield bow in right hand and left hand");
			}
		} else 
			if((string)weapons[0]->query_name() == "shortbow"){
				if((object *)TO->query_attackers() != ({})){
					command("unwield bow");
					command("wield sword in right hand");
					command("wield sword 2 in left hand");
				}
			}
		}
	if(!present("arrows"))
		new(CLRWEAP"arrows")->move(TO);
}

void init(){
	::init();
	if(!TP->query_invis() && evil(TP)){
		kill_ob(TP,1);
	}
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
                            if(ALIGN->is_good(inven[i])){
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
   return("This elven archer twinkles in and out of view as his brown leather "
"armor, leggings, and boots camouflage him well.  His sharp ears and angled "
"face are worn, yet beautiful.  The time of warring here has left him tired.  "
"Being sent to help reclaim this forest for good by his elders, he fights evil "
"with the sole purpose of good.");
}
