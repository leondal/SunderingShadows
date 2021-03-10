//sprite.c

#include  <std.h>

inherit MONSTER;

void do_check();
void do_bow();
int evil(object thing);

int count;

void create(){
	object ob;
	::create();
	
	set_name("sprite");
	set_id(({"sprite"}));
	set_short("A small sprite");
	set("long",
@OLI
	This small forest creature looks weak and frail. He dresses in small 
brown trousers and tree colored tunic. He flitters around lightly on his
danty wings. However, when provoked by his hatred for evil, he relishes 
it's demise.
OLI
	);
	set_class("ranger");
	set_body_type("human");
	set_race("sprite");
	set_gender("male");
	set_wielding_limbs(({"right hand","left hand"}));
	set_alignment(4);
	set_hd(23,0);
set_hp(85);
set_max_hp(query_hp());
	set_exp(500);
	add_money("gold",random(100));
	add_money("silver",random(50));
	set_overall_ac(2);
	new("/d/shadow/obj/lrweapon/shortbow")->move(TO);
	command("wield bow in right hand and left hand");
	ob=new("/d/shadow/obj/lrweapon/arrows");
	ob->set_wc(1,3);
	ob->set_large_wc(1,3);
	ob->move(TO);
	new("/d/shadow/obj/weapon/dagger")->move(TO);
	set_emotes(10,({"The sprite flutters around"}),0);
		}

void start_heart(){	
	set_heart_beat(1);
	}
	
void heart_beat(){
	 

	do_check();
	count++;
	if((string)query_weapon("right hand")->query_name() != "dagger" && count >5)
		do_bow();
	if((object *)TO->query_attackers() == ({})){
		if(random(20) < 5)
			set_invis();
	}
	::heart_beat();
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
						exit = ETO->query_direction(paths[i]);
						if(!interactive(living_bad[y])){	
							ids = living_bad[y]->query_id();
							command("shoot "+ids[0]+" 1 "+exit);
						}
						else
							command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
						if(random(10) < 5)
							living_bad[y]->set_paralyzed((random(6)+1) * 10,"You are under some kind of sleep.");
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
				command("unwield dagger");
				command("wield bow in right hand and left hand");
			}
		} else 
			if((string)weapons[0]->query_name() == "shortbow"){
				if((object *)TO->query_attackers() != ({})){
					command("unwield bow");
					command("wield dagger in right hand");
				}
			}
		}
	if(!present("arrows"))
		new("/d/shadow/obj/lrweapon/arrows")->move(TO);
}

void init(){
	::init();
	
	if(evil(TP) && !TP->query_invis()){
		if(!query_invis())
			set_invis();
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
                                 inven[i]->kill_ob(TP,1);
                             }
                        }
                }
        }
        swarm = 0;
     }
	return ::kill_ob(victim,which);
}
