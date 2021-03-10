#include <std.h>

inherit MONSTER;
// object ob;  don't need this

void create() {
   ::create();
   set_name("azmeylvriin");
   set_id(({"drow","azmeylvriin","assassin","demon"}));
   set_short("%^BOLD%^%^BLACK%^Azmeylvriin%^RESET%^");
   set_long(
      "Azmeylvriin appears to be an average drow at first glance. He has jet black skin and snow white hair that contrasts greatly."+
      " However, after looking further you notice his eyes are not just red, but are reflecting a burning fire from within."+
     " His body radiates an almost tangible field of intense heat and it appears"+
     " all he comes in contacts with is only a few seconds from melting."
   );
   set_class("fighter");
   set_guild_level("fighter",39);
   set_class("thief");
   set_guild_level("thief",35);
   set_mob_magic_resistance("average");
   set_race("drow");
   set_body_type("humanoid");
   set_gender("male");
   set_property("no hold", 1);
   set_property("no paralyze", 1);
   set_hd(39,6);
   set_alignment(9);
   set_max_hp(3500);
   set_hp(3500);
   set_overall_ac(-20);
   set_size(2);
   set_exp(100000);
   set_property("full attacks", 1);
   set_thief_skill("move silently",95);
   set_thief_skill("hide in shadows",95);
   add_search_path("/cmds/thief");
   set("aggressive", "aggressive");
   set_scrambling(1);
   set_max_level(23);
}

void aggressive() {
   if(avatarp(TP) && TP->query_invis()) return 1;
   force_me("say %^BOLD%^%^BLUE%^It's over for you.");
   force_me("kill "+TP->query_name());
   return;
}
