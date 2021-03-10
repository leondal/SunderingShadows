#include <std.h>

inherit "/std/riding_animal";


void create(){
  ::create();
  set_id(({"war horse","horse","warhorse","steed","skeletal","skeletal steed"}));
  set_name("skeletal steed");
  set_short("Skeletal steed");
  set_long(
@OLI
  	The steed stands as large as a paladin's War horse. Its bones shine white with an
  eerie glint. The saddle across its back is well used and worn. Who rides such a beast?
OLI
  	);
  set_level(10);
  set_value(1000);
  set_race("horse");
  set_gender("male");
  set_body_type("equine");
  set_size(3);
     set_riding_level(15);
  set_max_hp(200);
  set_hd(10,2);
  set_hp(200);
  set_overall_ac(-6);
  set_exp(8000);
  set_max_distance(20);
  set_enter_room("rides in");
  set_exit_room("leaves riding a skeletal steed.");
  set_vehicle_short("skeletal steed");
  set_attack_limbs(({"right forehoof","left forehoof"}));
  set_attacks_num(2);
  set_damage(2,10);
  
}


int kill_ob(object victim, int which){
	int hold;
	hold = ::kill_ob(victim, which);
	
	if(objectp(owner) && member_array(victim, (object *)owner->query_attackers()) == -1)
	if(hold){
		owner->kill_ob(victim,which);
	} 
	return hold;
}
