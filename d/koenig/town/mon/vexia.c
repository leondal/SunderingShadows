//added random weapons with chance of being magical  Styx 7/29/01

#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("vexia");
  set_id(({"vexia","image","image of vexia", "sister"}));
  set("race","human");
  set_gender("female");
  set("short","An image of %^MAGENTA%^Vexia%^RESET%^");
  set("long","Like her sisters, Vexia is so ghastly looking, when\n"+
               "looked upon by her, any creature weakens with fright.");
  set_level(11);
  set_body_type("human");
  set_class("mage");
  set_guild_level("mage",11);
  set("aggressive", 30);
  set_alignment(8);
  set_size(2);
  set_hd(14,1);
  set_stats("intelligence",18);
  set_stats("wisdom",13);
  set_stats("strength",9);
  set_stats("charisma",1);
  set_stats("dexterity",9);
  set_stats("constitution",10);
  set_hp(114);
  set_new_exp(10, "high");
  set_wielding_limbs(({"right hand", "left hand"}));
  set_emotes(8,({"%^MAGENTA%^Vexia screeches: %^RED%^You will pay foolish mortal!%^RESET%^"}), 1);
  add_money("gold",random(300)+50);
  set_spells(({"acid arrow","hideous laughter","lightning bolt", "blink",
  "magic missile"}));
  set_spell_chance(70);
  RANDGEAR->arm_me(TO, "bluntm", 20, random(3));
}
