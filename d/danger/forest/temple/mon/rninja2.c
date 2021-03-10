#include <std.h>

inherit MONSTER;

object ob;

void create() {
   ::create();
   set_name("Woman");
   set_id(({"ninja","temple ninja","real ninja","woman","woman drapped in silk","guard"}));
   set_short("Woman drapped in fine silks");
   set_long(
   "This woman is one of many students that has taken residence here at this temple."+
   " Women come at an early age for many different reasons. Some are orphans,"+
   " others were outcasts, and some simply come seeking knowledge."+
   " During their training, the women usually become protectors of this sacred place,"+
   " like this woman standing before you. She is garbed in fine white silks"+
   " which wraps around her body leaving little of herself in view."+
   " She wears the silks in many layers, some tight and some loose,"+
   " making it quite easy for her to conceal small objects."+
   " She lets the silk cover the lower half of her face, but"+
   " wears a forehead protector to keep her hair up and out of her face."
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
