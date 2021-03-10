#include <std.h>
#include "../defs.h"
inherit "/std/comp_vend";

void create() {
   ::create();
   set_name("Hurzagh");
   set_id(({"hurzagh","Hurzagh","master alchemist","alchemist","comp vendor","components vendor","mage"}));
   set_short("%^RESET%^%^BLUE%^Hurzagh Mel'atevirr, master alchemist%^RESET%^");
   set_long("%^BLUE%^Hurzagh is particularly tall for his kind, but slender almost to the point of scrawniness.  "
"His %^RESET%^pale hair %^BLUE%^sits askew and untidy, and his hands are marked with %^ORANGE%^s%^RED%^ta"
"%^ORANGE%^i%^MAGENTA%^n%^ORANGE%^s%^BLUE%^, likely from the obscure materials he handles daily.  The clothes he "
"wears are well made, though a little ill-fitted to his lanky frame, and they don't show the same extravagance to "
"suggest him as a member of the uppermost houses.  Still, the %^YELLOW%^in%^BOLD%^%^WHITE%^s%^YELLOW%^ig%^BOLD%^"
"%^WHITE%^ni%^YELLOW%^a %^RESET%^%^BLUE%^pinned by his shoulder suggests he is not without some connections.%^RESET%^");
   set_gender("male");
   set_race("drow");
   set_body_type("human");
   set("aggressive",0);
   set_hd(18,2);
   set_level(22);
   set_class("mage");
   set_mlevel("mage",22);
   set_guild_level("mage",22);
   set_alignment(9);
   add_money("gold", random(500));
   set_mob_magic_resistance("average");
   set_overall_ac(-10);
   set_stats("strength",18);
   set_stats("intelligence",18);
   set_max_hp(200+random(50));
   set_hp(query_max_hp());
   set_exp(300);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person", "powerword stun", "magic missile", "magic missile", "wall of fire", "phantom guardians", "prismatic spray" }));
   set_property("no bow",1);
   set_components(100);
}