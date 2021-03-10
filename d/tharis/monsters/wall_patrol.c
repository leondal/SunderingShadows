//Changed the second "unwield sword" to "unwield sword 2" so they didn't get 
//stuck in sword mode and with only one wielded.
//Changed heart_beat to try to stop errors and do_bow to avoid shooting invis.
//targets, commented in those sections - Styx 12/29/01
// revamping difficulty so they aren't instant death to mid levels *Styx* 10/05

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
	    set_name("Tharis archer");
                set_id( ({"patrol","an archer", "archer" }) );
	        set_race("human");
	        set_body_type("human");    
	        set_gender("male");
	        set_short("An archer");
           set_long("An Elite archer assigned to patrol the city walls.  He wears a full set of chain mail and intently watches the area for intruders.\n");  
           set_class("fighter"); 
/*	        set_level(24);  
	        set_hd(24,0);       
	        set_exp(2500);
                set_hp(150);
	        set_wielding_limbs( ({ "right hand", "left hand" }) );    
		set_overall_ac(3);
*/
	        set_level(15);  
	        set_hd(15,0);       
	        set_exp(1800);
                set_hp(120+random(20));
		set_overall_ac(3);
     		set_property("full attacks",1);
	        set("aggressive", 25);    
	        set_alignment(8);    
	        set_size(2);    
	        set_stats("intelligence",12);    
	        set_stats("wisdom",12);    
	        set_stats("strength",17);    
	        set_stats("charisma",10);    
	        set_stats("dexterity",14);    
	        set_stats("constitution",16);    
	        new(LRWEAPONDIR+"arrows")->move(TO);    
	        new(LRWEAPONDIR+"shortbow")->move(TO);    
	          command("wield bow");    
	        new(CWEAP"longsword")->move(TO);    
	        new(CWEAP"shortsword")->move(TO);    
	        add_money("electrum",random(80));    
	        add_money("gold",random(50)+100);    
	        enable_commands();
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
	if(count < 20)  return;  // was in check below, let's save doing those checks *Styx*
   if(objectp(query_weapon("right hand")))
	if((string)query_weapon("right hand")->query_name() != "longsword")
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
				command("unwield sword 2");
				command("wield bow");
			}
		} else 
			if((string)weapons[0]->query_name() == "shortbow"){
				if((object *)TO->query_attackers() != ({})){
					command("unwield bow");
					command("wield sword");
					command("wield sword 2");
				}
			}
		}
	if(!present("arrows"))
		new("/d/common/obj/lrweapon/arrows")->move(TO);
}

