#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("assistant underling");
  set_id( ({"assistand underling","underling"}) );
  set_short("%^RESET%^%^GREEN%^An Assistant Underling%^RESET%^");
   set_long("This guy is a bit smaller than the assistant cook but just as UGLY. He is readying the pots and such and licking his lips...at YOU!");
  set_race("goblin");
  set_gender("male");
  set_size(1);
  set_stats("strength", 14);
  set_stats("constitution", 18);
  set_stats("dexterity", 17);
  set_stats("wisdom", 10);
  set_stats("intelligence", 8);
  set_stats("charisma", 2);
  set_alignment(3);
  set("aggressive", 10);
  set_body_type("human");
  set_class("fighter");
  set_hd(5,4);
  set_max_hp(45);
  set_hp(45);
  set_overall_ac(8);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/kitknife.c")->move(this_object());
  command("wield knife in left hand");
  set_new_exp(10, "normal");
  add_money("gold", 25);
  set_emotes(10, ({"%^ORANGE%^The underling licks his lips as he eyes you over like a roast cutlet.%^RESET%^\n","%^BOLD%^%^WHITE%^The underling readies the pots in haste.%^RESET%^\n"}), 0);
}
