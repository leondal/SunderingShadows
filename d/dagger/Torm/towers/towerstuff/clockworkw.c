#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit WEAPONLESS;
  object ob2;
create(){
::create();
  set_name("clockwork warrior");
  set_id(({
  "clockwork warrior","clockwork","warrior",
  }));
  set_short(
  "%^YELLOW%^Clockwork warrior%^RED%^"
  );
  set_long(
  "  This tall brass warrior hums and stumbles awkwardly around the room."
  "  Its sword hand seems very stable though, and the blades edge seemes recently sharpened to a razors edge."
  );
  set_race("construct");
  set_gender("neuter");
set_body_type("human");
  set_hd(20);
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
set_exp(15);
  set_attack_limbs(({"brass longsword"}));
  set_attacks_num(2);
  set_damage(2,6);
  set_base_damage_type("slashing");
}
void die(mixed ob){
  tell_room(ETO,"%^RED%^Smoke pours from a horrible gash in the warriors side and you hear a sharp metal snapping noise from somewhere inside it!");
  if(!(TO->query_property("DoNe"))){
  new(TOWS+"rubblew.c")->move(ETO);
  } else {
  new(TOWS+"rubble.c")->move(ETO);
  }
  TO->move("/d/shadowgate/void.c");
  ::die(ob);
}
