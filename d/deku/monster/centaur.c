#include <std.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("centaur");
  set_id(({"skeleton","centaur","centaur skeleton"}));
  set_race("undead");
  set_gender("male");
  set_short("Centaur Skeleton");
  set_long("These monsters were half man and half horse when alive but "
      "have been killed and made undead by someone or something.");
  set_body_type("centaur");
  set("aggressive",18);
  set_alignment(9);
  set_size(2);
  set_hd(8,1);
  set_stats("strength",16);
  set_stats("charisma", 10);
  set_stats("dexterity",15);
  set_stats("constitution",14);
  set_stats("wisdom",13);
  set_stats("intelligence",9);
  set_hp(70 + random(21));
  set_exp(query_max_hp() * 10);
  set_property("undead",1);
  new("/d/common/obj/weapon/club_lg")->move(TO);
  command("wield club");
  if(!random(4)) new("/d/common/obj/misc/pouch")->move(TO);
  add_money("silver",random(100));
  add_money("gold",random(20));
}
