#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("assistant");
   set_id( ({"assistant", "cook","assistant head cook"}) );
  set_short("%^RESET%^%^ORANGE%^The assistant head cook%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^He's UGLY even for an ogre, and looking to help slice and dice you, what more do you need to know?%^RESET%^");
   set_race("ogre");
  set_gender("male");
  set_body_type("human");
  set_hd(10,20);
  set_size(2);
  set_stats("strength", 18);
  set_stats("constitution", 20);
  set_stats("dexterity", 12);
  set_stats("wisdom", 13);
  set_stats("intelligence", 12);
  set_stats("charisma", 1);
  set_alignment(9);
  set("aggressive", 1);
  set_max_hp(100);
  set_hp(100);
  set_overall_ac(5);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/carvknife.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/kitknife.c")->move(this_object());
  command("wield carving knife in right hand");
  command("wield kitchen knife in left hand");
  set_class("fighter");
  set_new_exp(12, "normal");
  add_money("gold", 50);
  set_emotes(10, ({"%^MAGENTA%^
  The assistant head cook sings: %^RESET%^Oho, Oho, here's a fine fat feast for our Master.
                        A grand sizzling dish to set before the Erl-King.
                        Light the fires, my dears, and heat the pots!"}), 0);
}
