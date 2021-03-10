//treant.c

#include <std.h>

inherit WEAPONLESS;

void make_me();
void remove_summoned(object ob);

object *summoned;

void create(){
	::create();
	
	set_name("treant");
	set_id(({"tree","treant"}));
    set_property("alignment adjustment",-5);
	set("short","A grand treant");
	set("long",
@OLI
	This treant has seen many many years of glory in this forest. It has 
stood the test of time. It has a thick base and knarled trunk that show that is has
seen many fights and survived. Its heavy foliage provides a large area of shade.
OLI
	);
	set_overall_ac(0);
	set_race("tree");
	add_limb("trunk","trunk",0,0,0);
	add_limb("right limb","trunk",0,0,0);
	add_limb("foliage","trunk",0,0,0);
	add_limb("root","trunk",0,0,0);
	add_limb("left limb","trunk",0,0,0);
	set_funcs(({"summon"}));
	set_func_chance(80);
	make_me();
	set_attack_limbs(({"right limb","left limb"}));
	set_attacks_num(2);
	set_alignment(7);
	set_invis();
	summoned = ({});
        set_property("no bows",1);
	}
	
void make_me(){
	int i;
	i = random(7);
	set_hd(i+10,8);
	set_exp(2000 + 600*i);
	set_hp(query_hd()*8);
	switch (query_hd()){
		case 10:
		case 11:
			set_damage(2,8);
			
			break;
		case 12:
		case 13:
			set_damage(3,6);
			break;
		case 14:
		case 15:
			set_damage(4,6);
			break;
		default:
			set_damage(5,6);
	}
   set_max_level(query_hd()+8);
}


void summon(object obj){
	int i,j;
	object ob;
	
	j = random(3);
	
	
	for(i=0;i<j;i++) {
		ob = new("/d/tharis/monsters/tree");
		ob->set_attackers((object)TO->query_attackers());
		summoned += ({ob});
		ob->set_caller(TO);
           ob->move(environment(TO));
		tell_room(ETO,"%^BOLD%^%^GREEN%^A tree uproots itself to come to the aid of the treant!");
	}
	set_func_chance(0);
}

void init(){
	if((int)TP->query_alignment() == 3 || (int)TP->query_alignment() == 6 || (int)TP->query_alignment() == 9){
		if(TO->query_invis()){
			tell_room(ETO,"%^BOLD%^%^GREEN%^You see a treant rise to protect its forest from evil!");
		 	TO->set_invis();
		 }
		kill_ob(TP,1);
		}
}

void die(object ob){
	int i;
	for(i=0;i<sizeof(summoned);i++)
		if(objectp(summoned[i]))
			summoned[i]->remove();
	return ::die(ob);
}

void remove_summoned(object ob){
	if(member_array(ob,summoned) != -1)
		summoned -= ({ob});
}

void heart_beat(){
	if((object *)TO->query_attackers() == ({})){
		if(!query_invis()){
			set_invis();
			set_func_chance(80);
		}
	}
	::heart_beat();
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

int test_heart(){ return 1;}
