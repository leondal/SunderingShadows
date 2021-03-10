#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

inherit MONSTER;

int build,reload;
string *outs,*exit_dir;

void do_check();
void do_bow();

int count;

create() {    
	::create();
set_name("timot");
set_id( ({ "timot", "a statue"}) );
set("race", "statue");
	        set_gender("male");
set_short("Timot, the greatest elven archer in the history of the known world");
set_long("%^BOLD%^RED%^A statue of a running archer carved from bloodstone by the hands of a master stands here.  Timot, the last of the great elven archers from the war of the wizards is honoured by this statue.  It stands five feet, six inches tall and the carving has captured the look of intense concentration and desperation upon the elven face.  He carries a bow, poised for battle, and a quiver of deadly arrows rests upon his back.%^RESET%^");
	set_level(21);
	set_hd(21,0);
	        set_exp(1500);    
	        set_body_type("human");    
	        set_class("fighter");    
	        set("aggressive", 25);    
	        set_alignment(7);    
	        set_size(2);    
	set_stats("intelligence", 18);
	set_stats("wisdom", 18);
	set_stats("strength", 23);
	set_stats("charisma", 25);
	set_stats("dexterity", 25);
	set_stats("constitution", 25);
	set_hd(21,1);
	set_hp(120);
	        set_max_hp(query_hp());    
	        set_max_sp(query_hp());    
	        set_sp(query_max_sp());	    
	        set_wielding_limbs( ({ "right hand", "left hand" }) );    
	        new(LRWEAPONDIR+"arrows")->move(this_object());    
	        new(LRWEAPONDIR+"shortbow")->move(this_object());    
	        command("wield bow in right hand and left hand");    
	        new(WEAPONDIR+"longsword")->move(this_object());    
	        new(WEAPONDIR+"longsword")->move(this_object());    
	        new(ARMORDIR+"chain")->move(this_object());    
	        command("wear armor");    
	        add_money("electrum",random(10));    
	        add_money("silver",random(10));    
	        add_money("gold",random(50));    
	        add_money("copper",random(20));    
	        enable_commands();
}
void start_heart(){	
	set_heart_beat(1);
	}
	
void heart_beat(){
	count++;
   	do_check();
	if((string)query_weapon("right hand")->query_name() != "longsword" && count > 5)
		do_bow();
	::heart_beat();
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
				command("unwield sword");
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
		new("/d/shadow/obj/lrweapon/arrows")->move(TO);
}

