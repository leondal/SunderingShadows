//Barding

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();

    set_name("horse barding");
    set_id(({"barding","horse barding"}));
    set_short("horse barding");
    set_long(
@OLI
    This heavy plate and chain barding covers a horse quite well. The
head is covered thoroughly. The body has ample protection, with carefully
shaped plates covering the flanks and rear. From the plates hang
protective chain linking. The neck is protected with a heavy and flexible
chain mail. The upper legs are covered with small plates linked with thick 
leather. The bottom of the legs are still unprotected.
OLI
    );
    set_weight(200);
    set_size(2);
    set_ac(15);
    set_limbs(({"torso","right foreleg","left foreleg","right rear leg","left rear leg","head"}));
    set_value(2000);
}

int do_struck(int damage, object weapon, object attacker) {
  int die_roll, rider_skill;
  object who, rider;

  who=query_worn();
  if (!objectp(who)) return 0;
  if (!objectp(rider=who->query_current_rider())) return 0;
   if (!rider_skill=rider->query_skill("athletics")) return 0;
  if (!objectp(environment(who)) || !objectp(environment(rider))) return -damage;  // Something's broken!
   if (environment(who) != environment(rider)) return 0; // No saves here.
  die_roll=random(20)+1;
  if (die_roll == 1) return 0; 
  if ( (die_roll == 20 ) || ((die_roll + rider_skill - (damage / 19)) >= 20) ) {

   //// deflect here
       tell_room(environment(who),"%^MAGENTA%^"+rider->QCN+" maneuvers  "+who->QCN+" skillfully, deflecting the force of "+attacker->query_cap_name()+"'s blow.",({rider,who,attacker}));
       tell_object(rider,"You steer your mount skillfully and drive "+attacker->QCN+"'s blow off target.");
       tell_object(attacker,"%^MAGENTA%^"+rider->query_cap_name()+" skillfully manages to ride "+who->query_cap_name()+" to deflect your blow.");
    return -damage; // Maybe less in the future if this is unbalanced.

   } else {
    return 0;
    }
}

int is_metal() { return 1; }
