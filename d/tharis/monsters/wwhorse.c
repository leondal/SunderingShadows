#include <std.h>

inherit "/std/riding_animal";



void create(){
  ::create();
  set_id(({"war horse","horse","warhorse","steed",}));
  set_name("war horse");
  set_short("Great White war horse");
  set_long(
@OLI
  	This magnificent steed shines in the light of good. Marvelous to look 
  upon the shiny coat is grand to behold. The mane is thick and full with
  braids. 
OLI
  	);
  set_level(10);
  set_value(1000);
  set_race("horse");
  set_gender("male");
    set_riding_level(15);
  set_body_type("equine");
  set_size(3);
  set_max_hp(200);
  set_hd(10,2);
  set_hp(200);
  set_overall_ac(-6);
  set_exp(8000);
  set_max_distance(20);
  set_enter_room("rides in");
  set_exit_room("leaves riding a white war horse.");
  set_vehicle_short("White war horse");
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
