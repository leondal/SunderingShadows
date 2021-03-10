#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob;

void create() {
   ::create();
   set_id(({"gnoll","cleric"}));
   set_name("Gnoll Cleric");
   set_id(({"gnoll","cleric","gnoll cleric"}));
   set_short("A ferocius gnoll cleric");
   set_long("%^RESET%^This is a massive, heavily haired and angry gnoll. It stands"+
              " over seven feet in height and looks around hungrily. The creature is"+
              " gripping a long tipped %^BOLD%^%^YELLOW%^spear %^RESET%^and seems ready"+
			  " for battle. The gnoll is adorned with furs and leather armors, painted"+
			  " with some sort of %^RESET%^%^BLUE%^tribal paint %^RESET%^which adds to its"+
			  " feracity. It has some sort of symbol hanging around its neck."+
			  " It's %^BOLD%^%^RED%^red eyes %^RESET%^glare at you, and you are"+
			  " sure there is no parlaying with this beast!");
   set_class("cleric");
   set_guild_level("cleric",12);
   set_race("gnoll");
   set_body_type("humanoid");
   set_property("no bows",1);
   set_gender("male");
   set_hd(12,8);
   set_alignment(6);
   set_max_hp(185);
   set_hp(185);
   set_overall_ac(-2);
   set_size(3);
   set("aggressive",18);
   set_exp(12000);
   set_max_level(12);
   set_wielding_limbs(({"right hand","left hand"}));
   set_stats("strength",20);
   set_stats("constitution",20);
   set_stats("intelligence",14);
   set_stats("wisdom",19);
   set_stats("charisma",12);
   set_stats("dexterity",15);
   set_spells(({
      "limb attack",
      "cause blindness",
      "sticks into snakes",
      "flame strike",
   }));
   set_spell_chance(100);
}

