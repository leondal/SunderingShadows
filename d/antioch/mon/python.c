//python.c

#include <std.h>

inherit WEAPONLESS;

object caught;
int flag;

void create(){
	::create();
	set_name("python");
	set_id(({"snake","python","Python"}));
	set_short("a small python");
	set_long(
@OLI
	This large snake has the thick, strong body of all 
constrictor snakes. The green and brown patterns along it's back 
make excellent camophlage.
OLI
	);
	set_body_type("snake");
	set_hd(5,8);
	set_hp(40);
	set_exp(120);
	set_attack_limbs(({"mouth"}));
	set_damage(2,7);
	set_hit_funcs((["mouth":(:TO,"constrict":)]));
	set_attacks_num(1);
	set_race("snake");
	set_funcs(({"release"}));
	set_func_chance(102);
	set_gender("female");
set_property("swarm",1);
	}

int constrict(object targ){
	if(targ->query_property("caught"))	
		return execute_attack();
	tell_room(ETO,"%^BOLD%^The constrictor successfully manages to grasp "+targ->query_cap_name()+" in it's thick coils!",targ);
	tell_object(targ,"%^BOLD%^The constrictor successfully manages to grasp you in it's thick coils!\n");
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
			caught->cause_typed_damage(caught, caught->return_target_limb(), roll_dice(2, 8), "bludgeoning");
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
