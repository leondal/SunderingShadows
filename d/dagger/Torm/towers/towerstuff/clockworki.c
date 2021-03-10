#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit WEAPONLESS;
  object ob2;
create(){
::create();
  set_name("clockwork insect");
  set_id(({
  "clockwork insect","clockwork","insect",
  }));
  set_short(
  "%^YELLOW%^Clockwork insect%^RED%^"
  );
  set_long(
  "  This strange flying toy buzzes about the room with gossamer wings."
  "  Light reflects off its shiney brass shell, and you can get a glimpse of a key winding down on the contructs back as it flies madly about."
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
  set_attack_limbs(({"brass mandibles"}));
  set_attacks_num(10);
  set_damage(1,3);
  set_base_damage_type("slashing");
}
void die(mixed ob){
  tell_room(ETO,"%^RED%^The clockwork insect starts smoking and crashes into a wall, dropping to the floor in a heap of rubble!");
  if(!(TO->query_property("DoNe"))){
  new(TOWS+"rubblei.c")->move(ETO);
  } else {
  new(TOWS+"rubble.c")->move(ETO);
  }
  TO->move("/d/shadowgate/void.c");
  ::die(ob);
}
