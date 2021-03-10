//by Circe 12/29/04 to add random vendors to Tonovi
#include <std.h>
#include "../short.h"

inherit VENDOR;
string COLOR,COLOR2;

#define COLORS ({"%^BOLD%^%^BLUE%^blue","%^BOLD%^azure","%^YELLOW%^amber","%^ORANGE%^brown","%^BOLD%^%^BLACK%^gray","%^GREEN%^green","%^BOLD%^%^GREEN%^emerald"})

#define COLORS2 ({"%^YELLOW%^blonde","%^RESET%^wheat-colored","%^ORANGE%^brown","%^BOLD%^%^BLACK%^black","%^RED%^auburn","%^BOLD%^%^RED%^crimson"})

void create() {
   int i,j;
  ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   j = random(sizeof(COLORS2));
   COLOR2 = COLORS2[j];
   set_hd(12,2);
   set("aggressive", 0);
   set_level(12);
   set_class("fighter");
   set_mlevel("fighter", 12);
   set_guild_level("fighter",12);
   set_alignment(6);
   set_race("human");
   add_money("gold", random(50));
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_overall_ac(-9);
   set_stats("strength",16);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(100);
	set_name("tobacco vendor");
	set_id(({ "shop clerk","shopkeeper","clerk", "vendor","tobacco vendor"}));
	set_short("A tobacco vendor");
	set_long("This aging man bears the salty, leathery skin of a "+
         "sailor who has spent his life in the sun.  He is dressed in "+
         "rather dingy grays, making him at odds with the other merchants "+
         "in the bazaar.  He has short "+COLOR2+" hair %^RESET%^%^CYAN%^"+
         "and "+COLOR+" eyes%^RESET%^%^CYAN%^ that seem to possess a shrewd "+
         "quality.  Despite the state of his clothing, his goods "+
         "seem costly enough, and it is clear that he prides himself in "+
         "visiting the realms in their entirety to find the rarest of "+
         "tobaccos."
	);
      set_storage_room("/d/dagger/tonovi/town/storage/tobacco");
      set_items_allowed("misc");
      set_gender("male");
}