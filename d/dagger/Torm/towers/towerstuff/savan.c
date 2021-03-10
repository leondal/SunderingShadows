#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit WEAPONLESS;
create(){
::create();
  set_name("phantom knight");
  set_id(({
  "knight","phantom knight","phantom",
  "savan","phantom paladin","savan the phantom paladin",
  }));
  set_short(
  "%^BOLD%^%^WHITE%^Savan the phantom paladin%^BOLD%^%^RED%^"
  );
  set_long(
  "  This faded, transparent woman is still dressed in the armor she wore in life."
  "  A symbol of the holy order of paladins is still visible, although faded and colorless, on her surcoat."
  "  The pale white creature is hardly visible when you look at it, the features imposible to make out with certainty."
  );
  set_race("phantom");
  set_body_type("humanoid");
 set_gender("neuter");
  set_property("swarm",1);
  set_attack_bonus(20);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_property("no bows",1);
  set_property("no rush",1);
  set_property("no dominate",1);
  set_hd(30);
  set_max_hp(400);
  set_hp(400);
  set_overall_ac(-15);
set_size(2);
  set_stats("strength",19);
  set_exp(10000);
  set_attack_limbs(({"phantom sword"}));
  set_attacks_num(4);
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
  TO->move("/d/shadowgate/void.c");
  ::die(ob);
}
