#include <std.h>
inherit "/std/monster";

void create()
{
  ::create();
  set_property("strength", "magic");
  set_name("zombie");
  set_id( ({"zombie"}) );
  set_short("%^BOLD%^%^GREEN%^A S%^RESET%^%^GREEN%^h%^BOLD%^ambli%^RESET%^%^GREEN%^n%^BOLD%^g Zombie%^RESET%^");
  set_long("%^RESET%^This creature of the undead is dressed in %^BOLD%^%^BLACK%^old%^RESET%^ and %^BOLD%^%^BLACK%^tattered clothing%^RESET%^ that looks to have been very %^BOLD%^expensive%^RESET%^ and %^BOLD%^elegant%^RESET%^ at one time. It now tries to play the %^BOLD%^%^BLACK%^organ%^RESET%^, sometimes doing rather well and other times failing miserably.");
  new("/d/common/obj/potion/poison.c")->move(this_object());
  set_gender("male");
  set_race("undead");
  set_body_type("human");
  set_property("undead",1);
  set_alignment(5);
  set_class("fighter");
  set_wielding_limbs(({"left hand","right hand"}));
  new("/d/koenig/town/mon/weapons/pclaws1.c")->move(this_object());
  command("wield claws in left hand");
  set_level(8);
  set_hd(8,6);
  set_max_hp(70);
  set_hp(70);
  set_overall_ac(4);
  set_size(2);
  set_new_exp(10, "normal");
  new("/d/koenig/town/mon/weapons/pclaws1.c")->move(this_object());
  command("wield claws in right hand");
}
