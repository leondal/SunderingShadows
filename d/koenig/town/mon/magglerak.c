//added random weapons with chance of being magical  Styx 7/29/01

#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("magglerak");
  set_id(({"magglerak","image","image of magglerak", "sister"}));
  set("race","human");
  set_gender("female");
  set("short","%^RESET%^An Image of %^GREEN%^Magglerak%^RESET%^");
  set("long","Like her sisters, Magglerak is so ghastly looking, when\n"+
                 "looked upon by her, any creature becomes weak with fright.");
  set_level(8);
  set_body_type("human");
  set_class("mage");
  set("aggressive", 30);
  set_alignment(8);
  set_size(2);
  set_hd(10,1);
  set_mlevel("mage", 10);
  set_guild_level("mage",10);
  add_search_path("/cmds/mage");
  set_stats("intelligence",18);
  set_stats("wisdom",13);
  set_stats("strength",9);
  set_stats("charisma",1);
  set_stats("dexterity",12);
  set_stats("constitution",10);
  set_overall_ac(6);
  set_hp(74);
  set_wielding_limbs(({"right hand", "left hand"}));
  set_wimpy(5);
  set_wimpydir("out");
  set_emotes(8,({"%^MAGENTA%^Magglerack says:%^RESET%^ You will pay foolish mortal!"}), 1);
  add_money("gold",random(200));
  set_spells(({"magic missile", "chill touch", "magic missile", "blink" }));
  set_spell_chance(85);
  set_new_exp(10, "high");
  RANDGEAR->arm_me(TO, "edgeds", 20, random(3));
}
