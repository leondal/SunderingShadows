#include <std.h>

inherit "/std/riding_animal.c";

private nosave int healingStuff;

void create(){
  ::create();
  set_id(({"nightmare","horse","nightmare steed"}));
  set_name("nightmare");
  set_short("Nightmare Steed");
  set_long(
@SEETH
The Nightmare steed looks like a war horse with fiery hooves and a flaming mane.
SEETH
);
  set_level(10);
  set_value(1000);
  set_race("horse");
  set_gender("male");
  set_body_type("equine");
  set_size(3);
  set_max_hp(10000);
  set_hd(10,2);
  set_hp(100);
  set_overall_ac(6);
  set_exp(1);
  set_max_distance(20);
  set_enter_room("rides in");
  set_exit_room("leaves riding a nightmare steed.");
  set_vehicle_short("Nightmare steed");
  set_attack_limbs(({"right forehoof","left forehoof"}));
  set_attacks_num(2);
  set_damage(2,6);
  healingStuff = 1;
}

int enter(string str){
  int lev, temp;
  
  lev = TP->query_level();

  if(TP->is_class("paladin") || TP->is_class("antipaladin")){
  	temp = query_hp();
   	set_level(lev);
   	set_hp(temp);
    set_damage(1,lev/2);
    if(lev>10 )
      	set_max_hp(10*lev); 
   	if(healingStuff || query_max_hp() < query_hp()){
   		set_hp(query_max_hp());
   		healingStuff = 0;
   	}
  }
if(!TP->is_class("antipaladin"))
    return notify_fail("The horse will not let you mount it!\n");
  else 
    return ::enter(str);
  return 1;
}
