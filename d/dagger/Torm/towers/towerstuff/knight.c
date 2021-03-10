#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit WEAPONLESS;
create(){
::create();
  set_name("phantom knight");
  set_id(({
  "knight","phantom knight","phantom",
  }));
  set_short(
  "%^BOLD%^%^WHITE%^Phantom knight%^BOLD%^%^RED%^"
  );
  set_long(
  "  This is the faded remains of a noble warrior, slain in these halls."
  "  The pale white creature is hardly visible when you look at it, the features imposible to make out with certainty."
  "  It drifts aimlessly about, not remembering what it should be doing, only knowing and praying that it is released from this pitiful state."
  );
  set_race("phantom");
  set_body_type("humanoid");
 set_gender("neuter");
  set_property("swarm",1);
  set_attack_bonus(20);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_property("no bows",1);
  set_property("no dominate",1);
  set_hd(random(10)+15);
  set_max_hp(query_hd()*8);
  set_hp(query_max_hp());
  set_overall_ac(0);
set_size(2);
  set_stats("strength",19);
  set_exp(query_max_hp()*6);
  set_attack_limbs(({"phantom sword"}));
  set_attacks_num(2);
  set_base_damage_type("slashing");
  set_hit_funcs((["phantom sword":(:TO,"hit":)]));
  set_damage(1,12);
}
int hit(object vic){
  tell_object(vic,"%^CYAN%^The blade seems to chill your soul as it passes through you.");
  tell_room(environment(vic),"%^CYAN%^"+vic->query_cap_name()+" seems paler as the phantoms blade passed through "+vic->query_objective()+".",({vic}));
  return 1;
}
void init(){
  if((string)TP->query_race() !="phantom"){
  if(wizardp(TP)) return 1;
  kill_ob(TP,1);
  tell_object(TP,"%^BOLD%^%^WHITE%^The phantom begs for release.");
  }
}
void die(mixed ob){
  tell_room(ETO,"%^BOLD%^%^WHITE%^The phantom fades away into the air with a sigh of relief.");
  TO->move("/realms/grumesh/workroom.c");
  ::die(ob);
}
