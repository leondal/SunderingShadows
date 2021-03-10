#include <std.h>

// inherit "/std/riding_animal";  changing to be a real war horse so it gets the right riding profs, etc. *Styx*
inherit "/d/common/mounts/war_horse";


void create(){
  ::create();
//  set_id(({"horse","war horse", }));
//  set_name("war horse");
//  set_short("War horse");
  set_long(
  "The horseman in the employ of the city of Torm get some of the best war horses you've seen around."
  "  This massive beasts' eyes glint with more intelligence than a few of the people you've met and its training leads it to defend its rider to the death without fear."
  	);
/* let the inherit handle all this now
  set_level(10);
  set_value(1000);
  set_race("horse");
  set_gender("male");
  set_body_type("equine");
  set_size(3);
  set_max_hp(100);
  set_hd(10,2);
  set_hp(100);
  set_overall_ac(3);
  set_exp(1000);
  set_max_distance(20);
  set_enter_room("rides in");
  set_exit_room("leaves riding a war horse");
  set_vehicle_short("war horse");
  set_attack_limbs(({"right forehoof","left forehoof"}));
  set_attacks_num(2);
  set_damage(1,10);
*/  
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
