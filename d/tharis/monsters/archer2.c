//updated to not shoot invis. targets and fixed other things - Styx 1/13/02
#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

int build,reload;
string *outs,*exit_dir;

void do_check();
void do_bow();

int count;

void create() {    
	::create();
	    set_name("archer");
	        set_id(({"an archer","archer"}));
	        set_race("human");
	        set_gender("male");
	        set_short("An archer");
	        set_long("An elite archer assigned to guard the city walls.  He wears sturdy looking banded armor and looks quite alert and prepared to defend the city.\n");            
	        set_level(14);  
	        set_hd(14,0);       
	        set_exp(1500);
	        set_hp(100+random(20));
	        set_body_type("human");    
	        set_class("fighter");    
	        set("aggressive", 25);    
	        set_alignment(8);    
	        set_size(2);    
	        set_stats("intelligence",12);    
	        set_stats("wisdom",12);    
	        set_stats("strength",18);    
	        set_stats("charisma",10);    
	        set_stats("dexterity",14);    
	        set_stats("constitution",16);    
	        set_max_hp(query_hp());    
	        set_wielding_limbs( ({ "right hand", "left hand" }) );    
                set_overall_ac(2);
	        new(CLRWEAP"arrows")->move(TO);    
	        new(CLRWEAP"shortbow")->move(TO);    
	        command("wield bow in right hand and left hand");    
	        new(CWEAP"longsword")->move(TO);    
	        add_money("electrum",random(10));    
	        add_money("silver",random(10));    
	        add_money("gold",random(50));    
	        enable_commands();
	        set_max_level(20);
}
void start_heart(){	
	set_heart_beat(1);
}
	
void heart_beat(){
		::heart_beat();
//moved stuff below from before to after the ::heart_beat() to let heart_beat 
//finish before trying to do them.
	
	count++;
	if(objectp(TO))  do_check();       //added check for valid object first.
	if(objectp(query_weapon("right hand")))
	if((string)query_weapon("right hand")->query_name() != "longsword" && count > 5)
		do_bow();
}

void do_bow(){
	int i,j, y,z;
	object ob, *inven, *living_bad;
	string exit,*paths, *ids;
	
	living_bad = ({});
	if(ETO){
		paths = ETO->query_destinations();
		if(j = sizeof(paths)){
			for(i=0;i<j;i++){
			
				if(ob = find_object_or_load(paths[i])){
				
					inven = all_inventory(ob);
					z = sizeof(inven);
				
					for(y=0;y<z;y++)
						if(interactive(inven[y])){
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



void do_check(){
	object *weapons;
	int i;
	
	weapons = TO->query_wielded();
	
	if(sizeof(weapons)){
		if((string)weapons[0]->query_name() != "shortbow"){
			if((object *)TO->query_attackers() == ({})){
				command("unwield sword");
				command("wield bow");
			}
		} else 
			if((string)weapons[0]->query_name() == "shortbow"){
				if((object *)TO->query_attackers() != ({})){
					command("unwield bow");
					command("wield sword");
				}
			}
		}
	if(!present("arrows"))
		new(CLRWEAP"arrows")->move(TO);
}

