#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("assistant cook");
   set_id( ({"assistant cook", "cook","assistant"}) );
  set_short("%^RESET%^%^ORANGE%^An assistant cook%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This is one very UGLY little guy, and he is looking at you and the pots with a rather %^BOLD%^sinister%^RESET%^%^GREEN%^ grin.%^RESET%^");
  set_race("goblin");
  set_gender("male");
  set_body_type("human");
  set_size(1);
  set_alignment(3);
  set_stats("strength", 12);
  set_stats("constitution", 10);
  set_stats("dexterity", 14);
  set_stats("wisdom", 9);
  set_stats("intelligence", 7);
  set_stats("charisma", 2);
  set("aggressive", 10);
  set_hd(10,5);
  set_max_hp(85);
  set_hp(85);
  set_overall_ac(6);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/carvknife.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/kitknife.c")->move(this_object());
  command("wield carving knife in right hand");
  command("wield kitchen knife in left hand");
  set_class("fighter");
  set_new_exp(12, "normal");
  add_money("gold", 50);
  set_emotes(10, ({"%^MAGENTA%^
The assistant cook sings: %^RESET%^Light the fires and heat the pots,
                      Sizzle the fat in the waiting vats.
                      Mince and stew and roast and batter,
                      Pour the juice in the Erl-King's platter!"}), 0);
}
