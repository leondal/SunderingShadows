#include <std.h>

inherit MONSTER;

object ob;

void create() {
   ::create();
   set_name("Woman");
   set_id(({"ninja","temple ninja","woman","woman in overcoat","guard"}));
   set_short("Woman in a long gray overcoat");
   set_long(
   "This woman is one of many students that has taken residence here at this temple."+
   " Women come at an early age for many different reasons. Some are orphans,"+
   " others were outcasts, and some simply come seeking knowledge."+
   " During their training, the women usually become protectors of this sacred place,"+
   " like this woman standing before you. She is dressed in the traditional"+
   " garb of the temple. A dark brown loose fitting body suit, which is tightned"+
   " at the wrists and ankles by bandages, with a gray overcoat and forehead protector."
   );
   set_class("fighter");
   set_guild_level("fighter", 15);
   set_mlevel("fighter", 15);
   set_exp(0);
   set_max_hp(50);
   set_hp(50);
   set_overall_ac(10);
   set_body_type("human");
   set_gender("female");
   set_race("human");
   set_alignment(3);
   set_property("full attacks", 1);
  set_stats("strength", 20);
  set_stats("dexterity", 20);
  set_stats("constitution", 10);
  set_stats("wisdom", 10);
  set_stats("intelligence", 10);
  set_stats("charisma", 11);
}

void die(object ob) {
   message("environment",
   "%^BOLD%^%^CYAN%^The clone dissappears in a puff of mist%^RESET%^!", environment(TO));
   TO->move("/d/shadowgate/void");
   ::die(ob);
}
