#include <std.h>
inherit "/realms/pegasus/bodies/crustation.c";

void create()
{
  object ob;
  ::create();
  set_property("magic resistance", 50);
  set_name("Crystal Scorpion");
  set_id( ({"crystal scorpion", "Crystal Scorpion", "scorpion"}) );
  set_short("%^RESET%^%^GREEN%^The Crystal Scorpion%^RESET%^");
  set_long("%^RESET%^You find it hard to believe that this is the same figurine that you tried to pick up. This %^BOLD%^%^GREEN%^crystal figure%^RESET%^ now stands at least 6-feet tall and looks to be ready for a %^BOLD%^%^RED%^fight%^RESET%^. Even worse, it appears to be guarding the only exit out of here!");
  set_body("crustation");
  set_race("crystal scorpion");
  set_gender("male");
  set_size(3);
  set_hd(10,6);
  set_stats("strength", 20);
  set_stats("constitution", 20);
  set_stats("dexterity", 20);
  set_stats("wisdom", 6);
  set_stats("intelligence", 5);
  set_stats("charisma", 10);
  set_class("mage");
  set_guild_level("mage", 15);
  set_spell_chance(20);
  set_spells( ({"color spray"}) );
  set("aggressive", 10);
  set_wielding_limbs( ({"tail"}) );
  set_max_hp(92);
  set_hp(92);
  set_overall_ac(4);
  set_new_exp(12, "normal");
  set_emotes(20, ({
     "%^BOLD%^%^WHITE%^The Crystal Scorpion moves about, thrashing its deadly tail.\n",
     "%^BOLD%^%^RED%^The Crystal Scorpion circles you slowly.\n",
     "%^BOLD%^%^BLACK%^Suddenly the scorpion rushes in at you!\n",
     "%^BOLD%^%^WHITE%^The Crystal Scorpion tauntingly blocks your escape east, claws clacking and tail thrashing.\n"}), 0);
  new("/d/koenig/town/mon/weapons/stinger.c")->move(this_object());
  command("wield stinger in tail");
  ob = new("/d/magic/scroll");
  ob->move(TO);
}
