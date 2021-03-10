#include <std.h>

inherit MONSTER;

void create() {
   ::create();
   set_name("drow");
   set_id(({"drow","warrior","drow warrior"}));
   set_short("%^BOLD%^%^BLACK%^Drow Warrior%^RESET%^");
   set_long(
      "%^BOLD%^%^BLACK%^Pointy ears, angular features, and slender form are among the identical features these drow have in common with the surface elves. However, the red glowing eyes and dark skin are the obvious and among the few physical differences that seperate drow from elf. These drow must be from some nearby city as they are geared for battle and appear to be standing guard."
   );
   set_class("fighter");
   set_guild_level("fighter",35);
   set_mlevel("fighter",35);
   set_race("drow");
   set_body_type("humanoid");
   set_gender("male");
   set_hd(15,6);
   set_alignment(9);
   set_max_hp(587);
   set_hp(587);
   set_overall_ac(-15);
   set_size(2);
   set_exp(30000);
   set_property("full attacks",1);
   set_mob_magic_resistance("average");
   set_stats("strength",25);
   set_stats("dexterity", 18);
   set_stats("wisdom",11);
   set_stats("dexterity",18);
   set_stats("constitution",15);
   set_stats("charisma",9);
   set_stats("intelligence",15);
   set_func_chance( ({"flashit","rushit","rushit"}) );
   add_search_path("/cmds/fighter");
   set("aggressive", 25);
}

void rushit(object targ) {
   TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
   TO->force_me("flash "+targ->query_name());
}
