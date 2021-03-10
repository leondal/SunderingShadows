#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
  set_name("ceramic bone armor");
  set_id(({"armor","ceramic bone armor","bone armor","ceramic armor"}));
  set_short("Ceramic bone armor");
  set_long(
  "  This dull white armor is made from the powdered bones of those who fall resisting Phederias hordes."
  "  It looks incredibly hard but brittle and you wonder how long it could hold its form before breaking."
  "  A sense of evil radiates from a single %^RED%^rune%^RESET%^ carved into the left shoulder plate."
       );
    set_weight(35);
  set_wear((:TO,"wearme":));
  set_value(200);
    set_type("armour");
    set_limbs( ({ "torso" }) );
  set_ac(8);
}
void heart_beat(){
  if(!objectp(ETO))return ;
  if(!TO->query_worn()) return;
  if((int)TO->query_ac() < 8){
  tell_object(ETO,"\nThe rune glows bright red for a brief second, then fades away and your armor turns to dust!");
  tell_room(environment(ETO),"\nThe red rune on "+ETO->query_cap_name()+"s armor glows %^BOLD%^%^RED%^bright red %^RESET%^for a brief second then fades and his armor falls from "+ETO->query_objective()+" in a cloud of bone dust!",ETO);
  TO->remove();
  }
}
int wearme(){
  if((int)ETO->query_highest_level()>10){
  set_heart_beat(1);
  return 1;
  }
  tell_object(ETO,"The armor refuses to be worn by one as weak as you!");
  return 0;
}
