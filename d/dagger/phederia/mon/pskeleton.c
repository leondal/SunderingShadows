#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("phederian skeleton");
  set_id(({"skeleton","phederian skeleton","pskeleton"}));
  set_short("%^BOLD%^%^MAGENTA%^Skeleton%^BOLD%^%^RED%^");
  set_long(
  "  This horrible creature is the still living bones of a humanoid whos flesh has been flayed away."
  "   Bright red blood courses up and down the creatures bones as if pulsing from an unseen heart and the old eyes of the person stare disconcertingly out."
  "  Its teeth clack togeather and it reaches a boney hand towards you!"
  );
  set_hd(20,8);
  set_attacks_num(1);
  set_property("swarm",1);
  set_attack_limbs(({"boney hand","bare teeth"}));
  set_gender("neuter");
  set_damage(2,4);
  set_stats("strength",18);
  set_hp(50+random(50));
  set_max_hp(query_hp());
  set_moving(1);
  set_speed(20);
  set_race("undead");
  set_body_type("humanoid");
  set_ac(2);
  set_exp(query_hp()*10);
  set_property("swarm",1);
  set_mob_magic_resistance("average");
}
int query_watched(){
  return 20;
}
