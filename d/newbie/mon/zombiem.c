// created by Styx for newbie cemetery

#include "/d/common/common.h"
#include <std.h>
inherit "/std/monster";

void create() {
  ::create();
  set_name("zombie");
  set_id(({"zombie","Zombie", "zombie mage", "mage"}));
  set_gender("male");
  set_race("zombie");
  set_short("Zombie mage");
  set_long("Created by evil magic users, this zombie's flesh is less rotted than the normal zombie but it is still a vile and wretched creature.  It's eyes have a dull, putrid, yellowish glow and it's hair is stringy and thin over a mostly bald scalp.");
  set_hd(4,2);
  set_body_type("human");
  set_property("undead",1);
  set_class("mage");
  set_guild_level("mage",4);
  add_search_path("/cmds/wizard");
  set_mlevel("mage",4);
  set_level(4);
  set_size(2);
  set_alignment(9);
  set_stats("intelligence",16);
  set_stats("wisdom",8);
  set_stats("strength",13);
  set_stats("charisma",3);
  set_stats("dexterity",9);
  set_stats("constitution",10);
  set_max_hp(query_hp());
  set("aggressive",17);
  add_money("gold", random(100)+50);
  new(CWEAP"dagger")->move(TO);
  command("wield dagger");
  set_overall_ac(8);
  set_hp(random(15)+40);
  set_exp(150);
  set_spells(({"vampiric touch", "magic missile", "blink", "chill touch", "scorcher"}));
  set_spell_chance(40);
  set_achats(3,
    ({  "The zombie growls menacingly and its %^RED%^eyes glow red%^RESET%^.",
	"%^ORANGE%^The zombie mutters something and shuffles closer to you.",
	"The zombie cackles evilly as it reaches for you."
    }) );
}
