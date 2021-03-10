//gboa.c

#include "summoned_monster.h"

inherit WEAPONLESS;

object caught;
int flag;

void create(){
	::create();
	set_name("giant boa constrictor");
	set_id(({"snake","boa","Boa","giant","giant boa"}));
   set_short("snake");
	set_long(
@OLI
	This large snake has the thick, strong body of all 
constrictor snakes. The green and brown patterns along its back 
make excellent camouflage. The enormous size of this creature is 
truly intimidating.
OLI
	);
	set_body_type("snake");
	set_hd(8,8);
	set_hp(60);
	set_exp(1000);
	set_attack_limbs(({"mouth"}));
	set_damage(2,7);
	set_hit_funcs((["mouth":(:TO,"constrict":)]));
	set_attacks_num(1);
	set_race("snake");
	set_funcs(({"release"}));
	set_func_chance(102);
	set_gender("female");
	}

int constrict(object targ){
	string capname;
	capname = targ->query_cap_name();
	if(targ->query_property("caught")) {	
/*  	  return execute_attack();  
 changing to do damage since was bugging and I think was looping from already being in attack round, could have maybe changed to be a special instead, but requiring a hit seems like a fair enough alternative - *Styx*, 11/11/02
*/
          tell_object(targ,"%^BOLD%^RED%^The snake's coils tighten around you!");
          tell_room(ETO,"%^BOLD%^RED%^The snake's coils tighten around "+capname+"!",targ);
          targ->do_damage("torso",roll_dice(2,4));
          return 1;
        }
	tell_room(ETO,"%^BOLD%^The constrictor successfully manages to grasp "+targ->query_cap_name()+" in its thick coils!",targ);
	tell_object(targ,"%^BOLD%^The constrictor successfully manages to grasp you in its thick coils!\n");
	caught = targ;
	targ->set_property("caught",1);
	flag = 1;
	targ->set_disabled(20);
}
	
	
void release(object targ){
    int str, need;

	if(flag){
		if(caught && objectp(caught)){
			tell_object(caught,"%^BOLD%^The constrictor squeezes you hard!\n");
			caught->do_damage(caught->return_target_limb(),roll_dice(2,10));
			str = caught->query_stats("strength");
			switch (str){
				case 1: case 2: 
					need = 1;
					break;
				case 3: 
					need = 2;
					break;
				case 4: case 5:
					need = 3;
					break;
				case 6: case 7:
					need = 4;
					break;
				case 8: case 9:
					need = 5;
					break;
				case 10: case 11:
					need = 6;
					break;
				case 12: case 13:
					need = 7;
					break;
				case 14: case 15:
					need = 8;
					break;
				case 16:case 17: case 18: 
					need = str - 7;
					break;
				case 19:
					need = 16;
					break;
				case 20: case 21:
					need = 17;
					break;
				case 22: case 23:
					need = 18;
					break;
				case 24: case 25:
					need = 19;
					break;
				}
			if(random(20) < need){
				tell_object(caught,"%^BOLD%^%^BLUE%^With a grunt you break free of the snake!\n");
				tell_room(ETO,"%^BOLD%^%^BLUE%^With a grunt "+caught->query_cap_name()+" break free of the snake!\n", caught);
				caught->set_disabled(0);
				caught = 0;
				flag = 0;
			} else {
				tell_room(ETO,"%^BOLD%^"+caught->query_cap_name()+" struggles to get loose of the snake!",caught);
				tell_object(caught,"%^BOLD%^You struggle to get loose of the snake!\n");
			}
		} else {
			flag = 0;
			caught = 0;
		}
	} else {
		set_func_chance(0);
		execute_attack();
	}
}
