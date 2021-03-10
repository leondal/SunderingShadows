//Edric, the firbolg jeweler
//Lothwaite
//Circe 6/16/04
#include <std.h>
#include "../lothwaite.h"

inherit VENDOR;

void create(){
   ::create();
   set_name("edric");
   set_short("Edric, Jeweler of the Winds of Fortune");
   set_id(({"edric","Edric","jeweler","Edric the jeweler","edric the jeweler","shopkeeper"}));
   set_long("Edric is a hulking firbolg standing over fourteen feet "+
      "tall.  He is dressed simply after the fashion of his people, "+
      "in %^ORANGE%^hide pants %^CYAN%^with the %^ORANGE%^fur %^CYAN%^"+
      "still worn on the outside.  His "+
      "broad, muscular chest is covered with a simple sleeveless "+
      "%^RESET%^tunic %^CYAN%^decorated with %^YELLOW%^gold braid "+
      "embroidered knots%^RESET%^%^CYAN%^.  %^ORANGE%^Cloth "+
      "boots %^CYAN%^reach to his knees, tying with leather cording.  "+
      "His long %^RED%^red hair %^CYAN%^is kept out of his face by "+
      "a flat %^ORANGE%^leather headband%^CYAN%^, and he wears a full, "+
      "%^RED%^hick beard%^CYAN%^ that would make a dwarf proud.  "+
      "His wrists are covered in %^RESET%^metal bands %^CYAN%^about "+
      "eight inches wide that are decorated with etched scrollwork "+
      "and images of %^ORANGE%^bears%^CYAN%^."
   );
   set_race("firbolg");
   set_gender("male");
   set_nwp("jewelling",20);
   set_items_allowed("clothing");
   set_hd(25,4);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-12);
   set_alignment(4);
   set_class("mage");
   set_class("fighter");
   set_mlevel("mage",25);
   set_mlevel("fighter",25);
   set_level(25);
   set_stats("intelligence",18);
   set_stats("wisdom",18);
   set_stats("charisma",16);
   set_stats("strength",19);
   set_stats("constitution",8);
   set_stats("dexterity",14);
   set_property("full attacks",1);
   set_spells(({
      "meteor swarm",
	"monster summoning vii",
	"chain lightning",
      "lightning bolt",
      "magic missile"
	}));
   set_spell_chance(60);
   set_exp(100);
   set("aggressive",0);
   add_money("gold",random(50));
   set_storage_room(STORAGE"jeweler_shop.c");
   force_me("speech say with a thick rolling accent");
}
