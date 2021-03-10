#include <std.h>
inherit NPC;

create() {
  ::create();
  set_name("Liam");
  set_id(({"ranger","liam","druthan","white ranger","White ranger","Ranger"}));
  set_race("human");
  set_gender("male");
  set_short("Liam Druthan");
  set_long("Liam is a middle aged looking man. He has a dark shadow for sideburns that flow into a thick goatee around his mouth and chin. The top of his head is bald and shiney when the light hits it on the right angles. His face is highlighted with deep blue eyes and wrinkles that have set in over time. He is equipped with basic equipment, but is dressed in all white.");
  set("aggressive",0);
  set_alignment(1);
  set_size(2);
  set_hd(14,3);
  set_hp(137);
  set_exp(2075);
  add_dbs(({"ranger"}));
  add_money("gold",200);
  new("/d/common/obj/armour/leather")->move(this_object());
  command("wear leather");
  //new("/d/common/obj/armour/cloak")->move(this_object());
  //command("wear cloak");
  new("/d/common/obj/weapon/shortsword")->move(this_object());
  command("wield sword");
  new("/d/common/obj/weapon/shortsword")->move(this_object());
  command("wield sword");
}
