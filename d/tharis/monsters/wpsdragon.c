//Added mouth as a limb because weaponless gags and the mob doesn't fight back 
//at all if an attack limb isn't a valid limb.  Also made other changes as noted
//to try to stop the errors in debug.log - Styx 12/23/01
//psdragon.c

#include <std.h>

inherit "/d/tharis/monsters/wfwander";

void create(){
	::create();
	
	set_name("pseudodragon");
	set_id(({"pseudodragon","dragon","psuedo","psdragon"}));
	set_short("A very small dragon");
	set_long(
@OLI
	You look at this dragon, which stands about 1.5 feet tall, and 
think how cute.  Then you get over its relative size and notice 
the sharp teeth in its mouth and the horns protruding from its
neck area.  Its scales are small and overlap in such a way that 
it almost looks like skin at a casual glance.  Every now and then 
you notice that its skin is changing color.
OLI
	);
	set_hd(8,8);
	set_stats("strength",18);
	set_hp(64+random(25));
	set_body_type("dragon");              //moved up to before the limb settings
	add_limb("mouth", "head", 0, 0, 0);  //mouth wasn't a valid limb before
//added foreclaws to attack limbs, was too wimpy for 5k exp. even with the special
	set_attack_limbs(({"mouth", "right foreclaw", "left foreclaw"}));   
	set_damage(2,9);                     //changed to be 2,9 from 1,9
	set_attacks_num(2);                  //changed to 2 attacks
	set_base_damage_type("piercing");
	set_exp(5000);
	set_race("pseudodragon");
	set_gender("male");
	set_funcs(({"tail"}));
	set_func_chance(50);
	set_alignment(1);
	}

void tail(object targ){
	if(!objectp(TO) || !objectp(targ))  return;
	if(random(20)+5 > (int)("daemon/bonus_d"->monster_thaco( TO->query_hd()) )-(int)(targ->query_ac())){
		
		tell_room(ETO,"%^BOLD%^%^RED%^Launching himself into the air the small dragon turns and dives toward "+targ->query_cap_name()+" and lashes at "+targ->query_objective()+" with his tail!",targ);
		tell_object(targ,"%^BOLD%^%^YELLOW%^The small dragon lauches himself into the air and turns on you, lashing at you with it's tail!!\n");
		tell_room(ETO,"%^BOLD%^%^RED%^The glaive like tip of the tail cuts deeply into "+targ->query_cap_name()+"!",targ);
		tell_object(targ,"%^BOLD%^%^YELLOW%^The glaive like tip of the tail cuts deeply into you!\n");
		targ->do_damage(targ->return_target_limb(),roll_dice(3,6));
		if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",-5)){
			targ->set_paralyzed(60,"%^BOLD%^You feel the poison creeping toward your heart and brain!");
			call_out("kill_em",61,targ);
		}
	} else {
		tell_room(ETO,"%^BOLD%^%^RED%^Launching himself into the air the small dragon turns and dives toward "+targ->query_cap_name()+" and lashes at "+targ->query_objective()+" with his tail!",targ);
		tell_object(targ,"%^BOLD%^%^YELLOW%^The small dragon lauches himself into the air and turns on you lashing at you with its tail!!\n");
		tell_room(ETO,"%^BOLD%^%^GREEN%^The tail whips around and misses its target, the dragon however recovers quickly and resumes the attack!");
	}
}

void kill_em(object targ){
	if(!objectp(targ) || !objectp(TO)) return;
	if(random(100) < 35){
		tell_object(targ,"%^BOLD%^%^RED%^The poison reaches your heart and you feel it slow to stopping.\n");
		tell_object(targ,"%^BOLD%^%^RED%^Your lungs seem to be collapsing as if there is no more air in the world.\n");
		tell_object(targ,"%^BOLD%^%^RED%^Your brain shuts down! You slip from consciousness.......... and life!");
		targ->do_damage(targ->return_target_limb(),100000);
		targ->set_attackers(({TO}));
		targ->continue_attack();
		return;
	} else {
		tell_object(targ,"%^BOLD%^%^CYAN%^You feel your body fighting off the poison flowing through it!\n");
		tell_object(targ,"%^BOLD%^%^CYAN%^You feel you will live!");
	}
}

void init(){
	::init();
	
	if(ALIGN->is_evil(TP) && !TP->query_invis())
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
                                 inven[i]->kill_ob(TP,1);
                             }
                        }
                }
        }
        swarm = 0;
     }
	return ::kill_ob(victim,which);
}
