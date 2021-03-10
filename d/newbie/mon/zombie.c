#include "/d/common/common.h"
#include <std.h>
inherit "/std/monster";

void create() {
  ::create();
  set_name("zombie");
  set_id(({"zombie","Zombie", "undead"}));
  set_gender("male");
  set_race("zombie");
  set_short("Zombie");
  set_long("Created by evil magic users, this zombie's flesh is less rotted than the normal zombie but it is still a vile and wretched undead creature.  Its eyes have a dull, putrid, yellowish glow and its hair is stringy and thin over a mostly bald scalp.");
  set_hd(5,1);
  set_property("undead",1);
  set_body_type("human");
  set_class("fighter");
  set_level(4);
  set_size(2);
  set_alignment(9);
  set_stats("intelligence",16);
  set_stats("wisdom",8);
  set_stats("strength",14);
  set_stats("charisma",3);
  set_stats("dexterity",9);
  set_stats("constitution",10);
  set_hp(random(15)+50);
  set_max_hp(query_hp());
  set("aggressive",17);
  add_money("gold", random(100)+25);
  new(CWEAP"mace")->move(TO);
  command("wield mace");
  set_overall_ac(8);
  set_exp(80);
  set_achats(1,
	({ "%^RED%^The zombie's eyes seem to glow red.",
	   "The zombie lunges toward your throat!"
	}) );
}
