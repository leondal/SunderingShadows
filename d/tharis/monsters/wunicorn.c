//unicorn.c

#include <std.h>

inherit "/d/tharis/monsters/wfwander";

void create(){
	::create();
	
	set_name("unicorn");
	set("id",({"unicorn","Unicorn","horse"}));
	set_short("A white unicorn");
	set("long",
@OLI
	This white horselike creature is truly magnificent, having both beauty 
and grace. A long spiraled horn protrudes from the center of her forehead.
Her coat is a little shaggy from the rugged life she's led.  You notice 
that she shows signs of battle. You boggle at the idea of such a creature 
in battle.
OLI
	);
	set_hd(8,9);
	set_level(13);
	set_hp(60);
	set_alignment(7);
	set_exp(1000);
	set_attacks_num(3);
	set_overall_ac(2);
	set_damage(1,12);
	set_base_damage_type("bludgeoning");
	set_attack_limbs(({"right hoof","left hoof","horn"}));
	set_body_type("equine");
	set_race("unicorn");
	set_gender("female");
	add_limb("horn","head",0,0,0);
	add_money("gold",random(100));
	add_money("platinum",random(10));
	set_funcs(({"charge"}));
	set_func_chance(30);
	}
	
void charge(object targ){
	if(!targ) return;
	
	::set_paralyzed(3,"You as stiff as stone");
	if(random(20)+1 > (int)("daemon/bonus_d"->monster_thaco( TO->query_hd()) ) - (int)(targ->query_ac())){
		tell_room(ETO,"%^BOLD%^%^RED%^The unicorn step back from the fight.");
		tell_room(ETO,"%^BOLD%^%^RED%^As she does so she lowers her head and charges back into the fight!");
		call_out("do_charge",2,targ,1);
	} else {
		tell_room(ETO,"%^BOLD%^%^RED%^The unicorn step back from the fight.");
		tell_room(ETO,"%^BOLD%^%^RED%^As she does so she lowers her head and charges back into the fight!");
		call_out("do_charge",2,targ,0);
	}
}

void do_charge(object targ, int flag){
   if(!objectp(targ)) return;
	tell_room(ETO,"%^BOLD%^%^RED%^The unicorn targets firmly on "+targ->query_cap_name()+"!!",targ);
	tell_object(targ,"%^BOLD%^%^RED%^The unicorn targets you as she charges into the fight!\n");
	if(flag){
		tell_room(ETO,"%^BOLD%^The unicorn impales "+targ->query_cap_name()+" with her spiral horn!");
		tell_object(targ,"%^BOLD%^You feel a flood of pain as the horn is run deply into you body.!\n");
		tell_object(targ,"%^BOLD%^Your breath leaves you and you feel yourself go limp for a moment!\n");
		targ->set_paralyzed(20,"You are recovering from the impact of the unicorn's charge!");
		targ->do_damage(targ->return_target_limb(),roll_dice(3,12));
		return;
	} else {
		tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" barely manages to avoid the charge, diving out of the way!",targ);
		tell_object(targ,"%^BOLD%^You quickly dive out of the way of the charging unicorn!");
		tell_room(ETO,"%^BOLD%^%^GREEN%^ The unicorn charges through the fight and tries to stop but can't due to her momentum!");
		::set_paralyzed(30,"You as stiff as stone");
	}
}

void set_paralyzed(int time,string message){return 1;}
	
void init(){
	::init();
	
	if(!TP->query_invis() && ALIGN->is_evil(TP)){
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
                            	if(inven[i] != TP && !interactive(inven[i]))
                                 	inven[i]->kill_ob(TP,1);
                             }
                        }
                }
        }
        swarm = 0;
     }
	return ::kill_ob(victim,which);
}
