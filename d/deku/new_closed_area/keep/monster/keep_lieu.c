#include <std.h>

inherit "/std/monster";

create() {
  ::create();
  set_name("keep lieutenant");
  set_id(({"lieutenant","klieutenant","orc","orc guard"}));
  set("short","Keep Lieutenant");
  set("long","This is a Lieutenant of Keep Blacktongue.  Obviously an orc because"
             "of his extreme smell and stupid look.  Dressed in well-worn leather "
             "armor, he looks like he's seen better days too.  He is larger than "
             "the than the normal Keep guards and looks a little smarter too.");
  set_race("orc");
  set_gender("male");
  set_level(7);
  set_body_type("human");
  set_class("fighter");
  set("aggressive", 0);
  set_alignment(6);
  set_size(2);
  set_hd(7,1);
  set_stats("strength",19);
  set_stats("intelligence",12);
  set_stats("wisdom",5);
  set_stats("charisma",4);
  set_stats("dexterity", 13);
  set_stats("constitution",15);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/common/obj/weapon/longsword")->move(this_object());
  command("wield longsword");
  set_overall_ac(2);
  set_hp(60);
  add_money("silver", random(50));
  add_money("copper", 5);
}
