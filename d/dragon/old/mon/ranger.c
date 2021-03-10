inherit "/std/monster";

create() {
  ::create();
  set_name("White Ranger");
  set_id(({"ranger","white ranger","White ranger","Ranger"}));
  set("race","human");
  set_gender("male");
  set("short","White Ranger");
  set("long","This ranger is the only good within the island.  He protects\n"+
             "the forest from any harm.");
  set_level(14);
  set_body_type("human");
  set_class("fighter");
  set("aggressive",0);
  set_alignment(1);
  set_size(2);
  set_hd(14,3);
  set_hp(137);
  set_exp(2075);
  set_wielding_limbs(({"right hand","left hand"}));
  add_money("gold",200);
  new("/d/deku/armours/leather1")->move(this_object());
  command("wear leather");
  new("/d/deku/armours/cloak")->move(this_object());
  command("wear cloak");
  new("/d/deku/weapons/short")->move(this_object());
  command("wield sword in right hand");
  new("/d/deku/weapons/short")->move(this_object());
  command("wield sword in left hand");
}
