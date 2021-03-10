#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit WEAPONLESS;
  object ob2;
create(){
::create();
  set_name("dough golem");
  set_id(({
  "golem","dough golem",
  }));
  set_short(
  "Dough golem"
  );
  set_long(
  "  This great mound of sticky dough moves on its own power, and a sense of melovolance exudes from it."
  "  What ever force has inhabited this batch of bread seems quite intent on your demise!"
  );
  set_race("construct");
  set_gender("neuter");
set_body_type("human");
  set_property("magic",1);
  set_hd(20);
  set_max_hp(200);
  set_hp(200);
  set_overall_ac(-10);
set_size(2);
  set_property("weapon resistance",2);
  set_property("no death",1);
  set_property("no bows",1);
  set_stats("strength",20);
set_stats("intelligence",7);
  set_stats("dexterity",25);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
set_exp(15);
  set_attack_limbs(({"doughy right fist","doughy left fist"}));
  set_attacks_num(2);
  set_damage(2,10);
  set_base_damage_type("magebludgeoning");
}
void die(mixed ob){
  tell_room(ETO,"%^BOLD%^%^WHITE%^The dough runs away from the last wound and suddenly the whole creature seems to melt and collapses.");
  ::die(ob);
}
