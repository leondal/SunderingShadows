#include <std.h>
#include "../defs.h"

inherit MONSTER;

int build,reload;
string *outs,*exit_dir;

void do_check();
void do_bow();

int count;

create() { 
	object obj;   
	::create();
	set_name("shade archer");
	set_id(({"shade","shade archer","archer","dream mon"}));
	set_short("%^BOLD%^%^BLACK%^A shade archer%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Composed of a shadowy substance, this"+
		" shade has a humanoid apperance.  From the waist up the "+
		"shade's features are somewhat defined. Being composed of "+
		"shadows, the shade's features will never be full exposed."+
		"  The shade has a quiver of arrows strapped to its back "+
		"and carries a bow in its hand.\n  ");
	set_race("shade");
	set_gender("neuter");
	set_body_type("human");
    	set_level(20);  
	set_hd(20,0);       
	set_exp(3000);
	set_max_level(32);
	set_hp(170+random(50));    
	set_class("fighter");    
	set("aggressive", 25);    
	set_alignment(8);    
	set_size(2);
	set_property("no steal",1);   
	set_stats("intelligence",12);    
	set_stats("wisdom",12);    
	set_stats("strength",18);    
	set_stats("charisma",10);    
	set_stats("dexterity",17);    
	set_stats("constitution",16);
	set_property("swarm",1);    
	set_max_hp(query_hp());    
	set_overall_ac(-3);
	add_attack_bonus(5);
	set_speed(30);
	set_nogo(({ROOMDIR"pedestal"}));
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
		switch(random(10)){
default:
	obj=new(OBJ"mithrilbow");
	if(random(5))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"mithrilarrows");
	obj->move(TO);
	command("wield bow");
break;
case 5..9:
	obj=new(OBJ"yewbow");
	if(random(5))
{
	obj->set_property("monsterweapon",1);
}
	obj->move(TO);
	obj=new(OBJ"yewarrows");
	obj->move(TO);
	command("wield bow");
break;
		}
	obj=new("/d/antioch/valley/obj/shadow_blade.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
   	add_money("electrum",random(500));    
	add_money("silver",random(1000));    
	add_money("gold",random(200));    
	enable_commands();
	set_max_level(30);
	set_emotes(10,({
		"%^BOLD%^%^BLACK%^The shade archer tests the strength of his bow string."+
		"%^BOLD%^%^GREEN%^The shade counts the arrows in his quiver."
    	}),1);
    if(!random(10)) {
      obj = new("/d/common/obj/brewing/herb_special_inherit");
      obj->set_herb_name("dream fragment");
      obj->move(TO);
    }

}
void start_heart(){	
	set_heart_beat(1);
}
	
void heart_beat(){
		::heart_beat();
	count++;
	if(objectp(TO))  do_check();       //added check for valid object first.
	if(objectp(query_weapon("right hand")))
	if((string)query_weapon("right hand")->query_name() != "blade" && count > 5)
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
		if((string)weapons[0]->query_name() != "bow"){
			if((object *)TO->query_attackers() == ({})){
				command("unwield blade");
				command("wield bow");
			}
		} else 
			if((string)weapons[0]->query_name() == "bow"){
				if((object *)TO->query_attackers() != ({})){
					command("unwield bow");
					command("wield blade");
				}
			}
		}
}

