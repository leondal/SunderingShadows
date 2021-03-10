#include "/d/common/common.h"
#include <std.h>
#include "../graveyard.h"
inherit MONSTER;

object ob;

void create() {
  ::create();
  set_name("zombie");
  set_id(({"zombie","Zombie", "zombie mage", "mage","undead"}));
  set_gender("male");
  set_race("zombie");
  set_short("%^RESET%^%^GREEN%^A rotting zombie%^RESET%^");
  set_long("%^GREEN%^This zombie's flesh is %^ORANGE%^sickly %^GREEN%^and %^BLUE%^rotted%^GREEN%^, with bits "
"of skin hanging off it.  It is clad in %^ORANGE%^tattered rags %^GREEN%^that may once have been clothing, and "
"emits an utterly %^MAGENTA%^putrid %^GREEN%^smell.  Its eyes have a dull, %^YELLOW%^yellowish "
"%^RESET%^%^GREEN%^glow and its %^BOLD%^%^BLACK%^hair %^RESET%^%^GREEN%^is stringy and thin over a mostly bald "
"scalp.  The zombie shambles around on stiff legs, clutching tattered sheets of %^WHITE%^parchment %^GREEN%^in "
"one rotting hand.%^RESET%^");
  set_hd(4,2);
  set_body_type("human");
  set_property("undead",1);
  set_property("swarm",1);
  set_class("mage");
  set_mlevel("mage",3);
  set_guild_level("mage",3);
  add_search_path("/cmds/wizard");
  set_level(3);
  set_size(2);
  set_alignment(9);
  set_stats("intelligence",16);
  set_stats("wisdom",8);
  set_stats("strength",13);
  set_stats("charisma",3);
  set_stats("dexterity",9);
  set_stats("constitution",10);
  set_hp(random(15)+35);
  set_max_hp(query_hp());
  set("aggressive",20);
  add_money("gold", random(50)+50);
  new(CWEAP"dagger")->move(TO);
  command("wield dagger");
  new(OBJ2"boots")->move(TO);
  command("wear boots");
  set_overall_ac(8);
  set_hp(random(15)+40);
  set_exp(110);
  set_spells(({"vampiric touch","vampiric touch","magic missile","magic missile","chill touch"}));
  set_spell_chance(40);
  ob=new("/d/magic/scroll");
  ob->set_spell(1);
  ob->move(TO);
  ob=new("/d/magic/safe_scroll");
  ob->set_spell(2);
  ob->move(TO);
  set_achats(3, 
    ({  "%^RED%^The zombie growls menacingly and its eyes glow red.%^RESET%^", 
        "%^ORANGE%^The zombie mutters something and shuffles closer to you.%^RESET%^", 
        "%^GREEN%^The zombie cackles evilly as it reaches for you.%^RESET%^"
    }) );
  set_new_exp(1, "very low");
}
