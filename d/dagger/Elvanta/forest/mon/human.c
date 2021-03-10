inherit "/std/monster";

create() {
  ::create();
  set_name("human");
  set_id(({"human","Human"}));
  set("race","human");
  set_gender("male");
  set("short","Human");
set("long", "A well dressed man, seemingly harmless, until you see his eyes.");
set_level(16);
  set_body_type("human");
  set_class("fighter");
  set("aggressive",15);
  set_alignment(8);
  set_size(2);
set_hd(16,2);
//set_wielding_limbs(({"right hand", "left hand", "torso"}));
set_wielding_limbs(({"right hand", "left hand" }));
  new("/d/deku/misc/pouch")->move(this_object());
  add_money("silver",random(300));
  set_hp(89);
  new("/d/deku/weapons/short")->move(this_object());
  command("wield sword in right hand");
new("/d/dagger/Elvanta/forest/items/wpns/knife")->move(this_object());
command("wield knife in left hand");
new("/d/dagger/Elvanta/forest/items/armor/leather")->move(this_object());
command("wear armor");
set_exp(125);
}
