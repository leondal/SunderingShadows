inherit "/std/monster";

void create() {
  ::create();
  set_name("root");
  set_id(( { "root", "roots"} ));
  set("race", "race");
  set_gender("neuter");
  set("short", "Root");
  set("long","These are roots from the tree above.  The tree roots are "
      "Vexia's first guards, activated by a spell she was able to develop.");
  set_alignment(5);
  set_body_type("snake");
  set("aggressive", 20);
  set_size(2);
  set_hd(6,15);
  set_hp(45);
  set_overall_ac(4);
  set_exp(150);
}
