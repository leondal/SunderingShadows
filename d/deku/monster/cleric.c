#include <std.h>
inherit "/std/monster";

create(){
  ::create();
  set_name("cleric");
  set_id( ({"drow", "drowelf", "cleric", "darkelf"}) );
  set_race("drow");
  set_gender("female");
  set_short("A female drow elf");
  set_long("This drow's snow white hair is bound up into a braid contrasting "
	"ebony skin that seems to almost soak up the surrounding light.  As her "
	"gray eyes fall onto you, a smirk crosses her lips.  With her dark "
	"travelworn clothing and serpent whip she seems as if she could handle "
	"herself in combat.  About her neck hangs a jet black disk trimmed in "
	"a ring of purple.");
  set_class("cleric");
  set_mlevel("cleric",14 + random(3));
  set_guild_level("cleric",query_level());
  set_exp(query_level() * 150 + random(51));
  set_alignment(6);
  set_stats("intelligence",15);
  set_stats("constitution",14);
  set_stats("dexterity",15);
  set_stats("charisma",14);
  set_stats("wisdom",20);
  set_stats("strength",16);
  set_overall_ac(0);
  new("/d/deku/armours/ring")->move(TO);
  command("wear ring");
  //new("/d/deku/armours/cloak1")->move(TO);
  //command("wear cloak");
  set("aggressive", 18);
  set_hp(query_level() * 8 + random(31));
  set_spell_chance(70);
  set_diety("shar");
  set_sphere("Darkness/Loss");
  set_spells(({"darkbolt","flame strike","cause serious wounds","hold person"}));
  switch(random(3)) {
//        case 0..1:  new("/d/deku/weapons/whip")->move(TO);  change to use /d/common one
        case 0..1:  new("/d/common/obj/weapon/scourge.c")->move(TO);
		 break;
	case 2:  new("/d/deku/weapons/serpentwhip")->move(TO);
		 break;
  }
  command("wield whip");
  add_money("gold",random(100));
  set_mob_magic_resistance("average");
}
