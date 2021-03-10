#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("lizard");
  set_id(({"lizard","Lizard"}));
  set_gender("male");
  set("short","Lizard");
    set("long","This is good example of a surface lizard that grew 8 feet long.");
  set_level(5);
  set_race("lizard");
  set_class("fighter");
  set("aggressive",10);
  set_body_type("quadruped");
  set_size(3);
  set_hd(5,3);
  set_hp(35);
  set_exp(50);
  set_overall_ac(4);
  set_alignment(5);
  add_money("gold",random(40));
  new("/d/common/obj/misc/pouch")->move(TO);
}
