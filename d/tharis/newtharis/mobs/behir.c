//behir.c
//corrected typo on strength, it was only getting 18 when it was supposed
//to get 20 so changed it to 19 after fixing the typo to keep from making a
//huge change to the monster - Styx 12/22/01

#include <std.h>

inherit MONSTER;

object caught, stomach;
int cast;

void set_caught(object targ);

void create(){
	::create();

	set_property("strength","electricity");
	set_property("strength","poison");
	set("aggressive",19);
	set_name("Behir");
	set_id(({"Behir","behir","monster","magical beast"}));
	set("short","A Behir");
	set("long",
@OLI
	This is a long snake like creature. It has a dozen legs protruding from
its sinuous reptilian body. This crocodilian-headed creature has a blue
under-belly. There are two large horns bending over the head. The extremely
hard scales are of a dusty blue color. An extremely fast animal, it lunges
quickly to kill you.
OLI
	);
	set_overall_ac(4);
	set_hd(12,4);
	set_hp(108);
	set_exp(10000);
	set_size(4);
	set_funcs(({"attack"}));
	set_func_chance(102);
	set_race("behir");
	set_gender("male");
	set_body_type("snake");
	set_wielding_limbs(({"mouth"}));
	add_limb("leg 1","leg 1",96,0,4);
	add_limb("leg 2","leg 2",96,0,4);
	add_limb("leg 3","leg 3",96,0,4);
	add_limb("leg 4","leg 4",96,0,4);
	add_limb("leg 5","leg 5",96,0,4);
	add_limb("leg 6","leg 6",96,0,4);
	add_limb("leg 7","leg 7",96,0,4);
	add_limb("leg 8","leg 8",96,0,4);
	add_limb("leg 9","leg 9",96,0,4);
	add_limb("leg 10","leg 10",96,0,4);
	add_limb("leg 11","leg 11",96,0,4);
	add_limb("leg 12","leg 12",96,0,4);
	set_property("swarm",1);
	set_stats("strength",19);
	set_stats("dexterity",21);
	set_stats("intelligence",21);
	add_money("gold",random(150));
	cast = 0;
	stomach = new("/d/tharis/obj/stomach");
	stomach->set_owner(TO);
	new("/d/tharis/obj/jaws")->move(TO);
	command("wield jaws in mouth");
}



void attack(object targ){

		if(!cast){
			tell_room(ETO,"%^BOLD%^%^YELLOW%^A 20' bolt of lightning"+
					" shoots from the Behir at "+targ->query_cap_name()+"!",targ);
			tell_object(targ,"%^BOLD%^%^YELLOW%^A bolt of lightning shoots from the"+
					" Behir toward you!\n");
			tell_room(ETO,"%^BOLD%^%^YELLOW%^The bolt slams into "+targ->query_cap_name()+"!",targ);
			tell_object(targ,"%^BOLD%^%^YELLOW%^The bolt slams into you!\n");
			if("daemon/saving_d"->saving_throw(targ,"spell",0)){
            set_property("magic",1);
            targ->do_damage(targ->return_target_limb(),12);
            remove_property("magic");
            }
			else{
				set_property("magic",1);
				targ->do_damage(targ->return_target_limb(),24);
				cast = 1;
				call_out("reset_cast",240);
				remove_property("magic");
			}
			return;
			}

		if(random(20) == 0){
			if(targ->query_size() < 3){
				tell_room(ETO,"%^BOLD%^%^RED%^The Behir rushes at "+targ->query_cap_name()+" and "+
				"catches "+targ->query_objective()+" off guard enough to swallow "+targ->query_objective()+
				" whole!",targ);
				tell_object(targ,"%^BOLD%^%^RED%^The Behir rushes at you and catches you in its mouth!"+
				" It then manages to swallow you whole!\n");
				targ->move_player(stomach);
				tell_object(targ,"%^BOLD%^%^RED%^You feel that survival in here will not be long!\n");
				return;
			}
		}
		if(caught){
			if(targ != caught)
				tell_object(targ,"%^BOLD%^The Behir hisses at you as it continues to squeeze "+caught->query_cap_name()+"!\n");
			tell_object(caught,"%^BOLD%^The behir continues to squeeze the spikes of it underbelly into you!!\n");
			tell_room(ETO,"%^BOLD%^%^RED%^The behir continues to squeeze "+caught->query_cap_name()+"!",caught);
			caught->do_damage(caught->return_target_limb(),random(6)+1);
			caught->do_damage(caught->return_target_limb(),random(6)+1);
			caught->do_damage(caught->return_target_limb(),random(6)+1);
			caught->do_damage(caught->return_target_limb(),random(6)+1);
			caught->do_damage(caught->return_target_limb(),random(6)+1);
			caught->do_damage(caught->return_target_limb(),random(6)+1);
			tell_object(caught,"%^BOLD%^Having stabbed you the behir releases his grip!\n");
			tell_room(ETO,"%^BOLD%^"+caught->query_cap_name()+" is released by the behir!",caught);
			set_func_chance(0);
			execute_attack();
			set_func_chance(102);
			set_caught(0);
			return;
		}
		set_func_chance(0);
		execute_attack();
		if(!caught)
			execute_attack();
		set_func_chance(102);
	}

void set_caught(object targ){caught = targ;}

void heart_beat(){
	object *inven;
	int i,j;


	if(query_hp() < 1){
		if(stomach){
			inven = all_inventory(stomach);
			i = sizeof(inven);
			for(j = 0; j < i;j ++){
				if(living(inven[j])){
					tell_object(inven[j],"%^BOLD%^As the behir dies you fall from the stomach as friends cut the stomach open!\n");
					inven[j]->move_player(ETO);
					inven[j]->add_attacker(TO);
					TO->add_attacker(inven[j]);
				} else {
					tell_room(ETO,"%^BOLD%^"+inven[j]->query_short()+" falls from the stomach of the behir!");
					inven[j]->move(ETO);
				}
			}
			stomach->remove();
		}
	}
		::heart_beat();
}

void reset_cast(){cast = 0;}

object query_caught(){ return caught;}
