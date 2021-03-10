inherit "/std/monster";
// fixing a number of obvious problems such as the inherit of saving_d, missing gender
// *Styx* 11/16/03, last change 9/21/02
// inherit "/daemon/saving_d";

create() {
  ::create();
  set_name("ghost");
  set_id(({"ghost"}));
  set_gender("male");
  set_race("ghost");
  set_short("A ghost");
  set("long","Ghosts are the spirits of evil humans who were so awful in\n"+
             "their badness that they have been rewarded by being given\n"+
             "undead status. They roam about hungering to draw the living\n"+
             "essences from the humanoids unfortunate enough to come across them.");
  set_body_type("human");
  set_level(9);
  set_size(2);
  set_alignment(9);
  set_hd(9,2);
  set("aggressive",18);
//  set_wielding_limbs(({"right hand"}));  not needed
  set_overall_ac(0);
  set_property("undead",1);
  set_hp(83);
  set_exp(675);
//  if("/daemon/saving_d"->saving_throw(this_player(),"spells")) steal_strength();
// this has been reported as erroring lately, last change to the file looks
// like 8/99 but there is no function in the file so I'm just commenting out.
// *Styx*  9/2002
}

