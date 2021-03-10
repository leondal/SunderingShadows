#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit WEAPONLESS;
  object ob2;
create(){
::create();
  set_name("glass golem");
  set_id(({
  "golem","glass golem",
  "stained glass warrior","warrior"
  }));
  set_short(
  "%^BOLD%^%^WHITE%^Stained %^RED%^glass%^YELLOW%^ warrior%^BOLD%^%^RED%^"
  );
  set_long(
  "  This strange creature appears to be a mobile stained glass window."
  "It's incredibly thin and looks very fragile, but its sword is so sharp it thins at the edges to a blade that could slice steel."
  );
  set_race("construct");
  set_gender("neuter");
set_body_type("human");
  set_property("no dominate",1);
  set_hd(20);
  set_property("magic",1);
  set_max_hp(200);
  set_hp(200);
  set_overall_ac(-10);
set_size(2);
set_stats("strength",12);
set_stats("intelligence",7);
  set_stats("dexterity",25);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
  set_exp(10000);
  set_property("no bows",1);
  set_attack_limbs(({"stained glass sword"}));
  set_attacks_num(1);
  set_damage(10,10);
  set_base_damage_type("slashing");
}
void die(mixed ob){
  tell_room(ETO,"%^BOLD%^%^WHITE%^The golem smashes into tiny fragments with the final blow and it's pieces are scattered across the floor.");
  new(TOWS"pileofglass.c")->move(ETO);
  TO->move("/d/shadowgate/void.c");
  ::die(ob);
}
