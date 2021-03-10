inherit "/std/monster";
inherit "/daemon/saving_d";

create() {
  ::create();
  set_name("ghost");
  set_id(({"ghost"}));
  set_gender();
  set("race","ghost");
  set("short", "A ghost");
  set("long","Ghosts are the spirits of evil humans who were so awful in\n"+
               "their badness that they have been rewarded by being given\n"+
             "undead status. They roam about hungering to draw the living\n"+
             "essences from humans.");
  set_body_type("human");
  set_level(30);
  set_size(2);
  set_alignment(9);
  set_hd(30,2);
  set("aggressive",18);
  set_wielding_limbs(({"right hand"}));
  set_overall_ac(0);
  set_hp(53);
  set_exp(675);
  if("/daemon/saving_d"->saving_throw(this_player(),"spells")) steal_strength();
}

