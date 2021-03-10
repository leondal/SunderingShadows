#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("guard");
  set_id(({"guard","fortress guard"}));
  set_gender("male");
  set("short","Fortress guard");
  set("long", "This is a follower of the Evil Shadowlord.  Dressed in black\n"+
              "leather with his cape draping over it, this figure is very much alive,\n"+
             "but his skin is pure white.");
  set_level(9);
  set_class("fighter");
  set("aggressive",18);
  set_size(2);
  set_race("human");
  set_hd(9,3);
  set_hp(92);
  set_alignment(9);
  set_body_type("human");
  set_new_exp(10, "low");
  set_overall_ac(4);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/common/obj/armour/leather")->move(TO);
  command("wear leather");
  new("/d/common/obj/weapon/longsword")->move(TO);
  command("wield longsword");
}
