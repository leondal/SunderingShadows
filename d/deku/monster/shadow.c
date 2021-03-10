inherit "std/monster";

create() {
  ::create();
  set_name("Shadow");
  set("id", ({"shadow", "Shadow"}) );
  set_short("Shadow");
  set("race", "undead");
  set_long("What are you talking about...Like you can see a shadow!!");
  set_gender("female");
  set_level(6);
  set_alignment(8);
  set_hd(6,1);
  set_body_type("human");
  set_overall_ac(4);
  set_class("fighter");
  set_size(2);
  set_stats("strength", 20);
  set_money("electrum",random(20));
  set_money("gold",random(50));
  set("aggressive",15);
  set_exp(75);
  set_hp(random(15)+40);
}
