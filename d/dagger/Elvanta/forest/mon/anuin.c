
#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

create() {
int resist;
   ::create();
set_name("anuin");
  set_id( ({
"anuin", "statue"
  }) );
set("race", "statue");
     set_gender("female");
  set("short",
"A statue of Anuin"
     );
  set("long",
"%^BOLD%^WHITE%^A five foot elegantly carved white marble statue of the Goddess Anuin stands before you.  She is so exquisitly carved that you can almost see here breast rise and fall with each breath.%^RESET%^"
     );
set_level(25);
  set_body_type("human");
  set("aggressive", 18);
set_alignment(5);
  set_size( 2 );
     set_stats("intelligence", 14);
     set_stats("wisdom", 20);
set_stats("strength", 20);
set_stats("charisma", 21);
set_stats("dexterity", 18);
set_stats("constitution", 25);
set_overall_ac(1);
   set_max_mp(0);
   set_mp(query_max_mp());
set_hd(25,1);
set_hp(150);
set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
set_exp(900);
set_wielding_limbs( ({"left fog arm", "torso"}) );
     new("/d/antioch/obj/lust.c")->move(this_object());
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
resist = 15 + random(20) + random(20);
set_property("magical resistance", resist);
set_guild_level("mage", 15);
set_spell_chance(25);
set_spells(({"web"}));
add_money("electrum", random(10));
}
