//harpy.c

#include <std.h>
#include <daemons.h>

inherit "/d/tharis/monsters/wfwander";

string *my_charmed, sung_to;
int singing;

void create(){
	::create();
	set_name("harpy");
	set_id(({"harpy","Harpy","bird"}));
	set_short("a terribly smelly harpy!");
	set_long(
@OLI
	This horrid looking creature has the torso and head of a rather
heinous female, and the lower body of a large bird. The creature smells
of offal and revolts you to look at. 
OLI
	);
	set_base_damage_type("slashing");
	set_damage(1,6);
	set_attack_limbs(({"right claw","left claw","mouth"}));
	set_attacks_num(3);
	set_body_type("human");
	remove_limb("left foot");
	remove_limb("right foot");
	add_limb("left claw","left leg",0,0,0);
	add_limb("right claw","left leg",0,0,0);
	add_limb("left wing","torso",0,0,0);
	add_limb("right wing","torso",0,0,0);
	set_hd(12,8);
	set_hp(70);
	set_exp(1800);
	set_gender("female");
   set_race("harpy");
	set_overall_ac(2);
        set_emotes(20,({"The harpy's smell makes you queazy.","The heinous appearance of the harpy makes you retch."}),0);
	my_charmed = ({});
	sung_to = ({});
	add_money("gold",random(100));
	set_funcs(({"singing"}));
	set_func_chance(102);
	set_alignment(9);
}

void init(){
	::init();
	
	if(ALIGN->is_good(TP) && !TP->query_invis())
		call_out("do_sing",1,TP);
}

void do_sing(object ob){
   if(!objectp(ob)) return;
	if( (singing && ALIGN->is_good(ob)) || (!ob->query_invis() && ALIGN->is_good(ob))){
		singing = 1;
		sung_to += ({ob->query_name()});
		tell_object(ob,"%^BOLD%^%^CYAN%^The harpy starts to sing to you in an amazing voice!");
		if(!SAVING_D->saving_throw(ob,"spell",0)){
			if(member_array((string)ob->query_race(), ({"elf","beastman","half-elf"})) == -1){
				my_charmed += ({(string)ob->query_name()});
				ob->set_paralyzed(100,"%^BOLD%^You are mesmerized by the lovely song of the harpy!");
				tell_object(ob,"%^BOLD%^%^CYAN%^You become mesmerized by the harpy's song!");
				tell_room(ETO,"%^BOLD%^%^CYAN%^"+ob->query_cap_name()+" has become charmed by the lovely song of the harpy!",ob);
				return;
			} 
		}
		tell_object(ob,"%^BOLD%^%^CYAN%^Your mind beats back the charm of the harpy's song!");
		kill_ob(ob,1);
			
	}
}

void heart_beat(){
	int i;
	object ob;
	string *tmp;
	::heart_beat();
	
	if(!objectp(TO)) return;
	tmp = ({});
	if(query_attackers() == ({}) && sizeof(my_charmed)){
		tell_room(ETO,"%^BOLD%^The battle done, the harpy turns on her charmed victims!");
		for(i = 0;i < sizeof(my_charmed);i++)
			if(ob = present(my_charmed[i],ETO)){
				kill_ob(ob,1);
				tmp += ({my_charmed[i]});
			}
		my_charmed = ({});
	}
	if(query_attackers() == ({}) && !sizeof(my_charmed))
		singing = 0;
	tmp = ({});
	
	for(i=0;i<sizeof(sung_to);i++){
		if(!present(sung_to[i],ETO)){
			tmp += ({sung_to[i]});
		}
	}
	sung_to -= ({tmp});
}

void remove_stuff(){
	int i;
	object ob;
	
	for(i = 0;i< sizeof(my_charmed);i++)
		if(ob = present(my_charmed[i],ETO))
			ob->remove_paralyzed();
	sung_to = ({});
	charmed = ({});
}

void die(object thing){
	remove_stuff();
	return ::die(thing);
}

void set_paralyzed(int a, string b){
	remove_stuff();
	singing = 0;
	return ::set_paralyzed(a,b);
}

void singing(object targ){
	set_func_chance(0);
	
	execute_attack();
	
if (!objectp(targ)) return;
//
				
		do_sing(targ);
	
	set_func_chance(102);
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
