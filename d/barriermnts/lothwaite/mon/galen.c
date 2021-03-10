//Galen, the Tallow Chandler
//Lothwaite
//Circe 6/16/04
#include <std.h>
#include "../lothwaite.h"

inherit VENDOR;

void create(){
   ::create();
   set_name("galen");
   set_short("Galen, the Tallow Chandler");
   set_id(({"galen","chandler","tallow chandler","Galen"}));
   set_long("Galen is an aged human, appearing to be around eighty "+
      "years old.  The top of his head is bald and rather shiny "+
      "from working around the tallow all day, while the rest of his "+
      "head is covered in long, thing %^RESET%^gray hair %^CYAN%^"+
      "that falls to his shoulders.  He wears a pair of %^YELLOW%^"+
      "round spectacles %^RESET%^%^CYAN%^with thin %^YELLOW%^brass "+
      "rims %^RESET%^%^CYAN%^that seem always to slip to the end "+
      "of his rather small nose.  His wide eyes are always a little "+
      "%^BOLD%^watery%^RESET%^%^CYAN%^, and they are a light %^BOLD%^"+
      "azure shade%^RESET%^%^CYAN%^, the color of the afternoon sky.  Galen "+
      "wears a simple %^ORANGE%^brown tunic %^CYAN%^with darker "+
      "%^ORANGE%^breeches%^CYAN%^, all covered by a stark %^BOLD%^"+
      "%^WHITE%^white coat%^RESET%^%^CYAN%^.  He shuffles around "+
      "the room, making candles all day, which he seems to find "+
      "relaxing.  His hands, though wrinkled, still look steady."
   );
   set_race("human");
   set_gender("male");
   set_items_allowed("misc");
   set_hd(20,4);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-12);
   set_alignment(4);
   set_class("mage");
   set_class("cleric");
   set_mlevel("mage",20);
   set_mlevel("cleric",20);
   set_level(20);
   set_stats("intelligence",18);
   set_stats("wisdom",18);
   set_stats("charisma",16);
   set_stats("strength",9);
   set_stats("constitution",8);
   set_stats("dexterity",14);
   set_spells(({
      "meteor swarm",
	"flame strike",
	"mystic bolt",
	"limb attack",
	"monster summoning vii",
	"chain lightning",
	}));
   set_spell_chance(100);
   set_exp(100);
   set("aggressive",0);
   add_money("gold",random(50));
   set_storage_room(STORAGE"chandler.c");
   force_me("speech speak in a thin, raspy voice");
}

