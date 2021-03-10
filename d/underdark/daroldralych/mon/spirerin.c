#include <std.h>
#include <langs.h>
#include "../defs.h"
inherit "/std/scribe";

void create() {
   ::create();
   set_name("Spirerin");
   set_id(({ "shop clerk","mail clerk","clerk","scribe","spirerin","Spirerin"}));
   set_short("%^RESET%^%^BLUE%^Spirerin Phaeraan, the scribe%^RESET%^");
   set_long("%^BLUE%^Behind the counter stands this youthful looking drow male.  His hair is cropped to "
"shoulderlength, a common style within the city, bound at the nape of his neck with a %^ORANGE%^leather band"
"%^BLUE%^.  He seems to constantly have some book or other in his hands, his intelligent %^BOLD%^%^BLACK%^dark "
"eyes%^RESET%^%^BLUE%^ scanning its pages.%^RESET%^");
   set_gender("male");
   set_race("drow");
   set_body_type("human");
   set("aggressive",0);
   set_hd(18,2);
   set_level(18);
   set_class("mage");
   set_mlevel("mage", 18);
   set_guild_level("mage",18);
   set_alignment(9);
   add_money("gold", random(500));
   set_property("magic resistance",15);
   set_overall_ac(5);
   set_stats("strength",18);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_exp(300);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person", "powerword stun", "magic missile", "magic missile", "wall of fire", "phantom guardians", "prismatic spray" }));
   set_property("no bow",1);
   set_scribe_name("spirerin");
   set_region("juran");
}