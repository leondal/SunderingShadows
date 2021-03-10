#include <std.h>

inherit "/std/riding_animal";


void create(){
  ::create();
  set_id(({"horse","nightmare"}));
  set_name("nightmare");
  set_short("nightmare");
  set_long(
  "  This pure black horse is an incarnation of evil.  Its glowing eyes promise nothing but death and its just barely kept in line by its rider."
  	);
  set_level(10);
  set_value(1000);
  set_race("horse");
  set_gender("male");
  set_body_type("equine");
  set_size(3);
  set_max_hp(200);
  set_hd(10,2);
  set_hp(200);
  set_overall_ac(-6);
  set_exp(1000);
  set_max_distance(20);
  set_enter_room("rides in");
  set_exit_room("leaves riding a shadowbeast");
  set_vehicle_short("nightmare");
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
