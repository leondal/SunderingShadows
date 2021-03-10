#include <std.h>
inherit MONSTER;

string time;

void create()
{
  ::create();
  set_name("scarlet");
  set_id( ({"scarlet", "patron", "Scarlet"}) );
  set_race("half-elf");
  set_gender("female");
  set_short("%^RESET%^%^ORANGE%^Scarlet the Patron%^RESET%^");
  set_long("%^RESET%^Scarlet wears very little but what she does wear is blood-red and trimmed with fur. She notices your glance and her pouty full lips begin to smile. Judging by her stance, I wouldn't advise you to think her weak.");
  set_level(8);
  set_body_type("elf");
  set("aggressive",1);
  set_alignment(4);
  set_size(2);
  set_hd(4,2);
  set_new_exp(10, "normal");
  set_hp(35);
  set_property("strength", "magic");
  set_wielding_limbs( ({"right hand"}) );
  new("/d/common/obj/weapon/scourge.c")->move(this_object());
  command("wield whip in right hand");
  add_money("silver", random(40));
  add_money("gold", random(10));
}
