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
	set_name("clothing merchant");
	set_id(({ "shop clerk","shopkeeper","clerk", "merchant","clothing merchant","tailor"}));
	set_short("A clothing merchant");
	set_long("This young woman is lithe of figure and dressed "+
         "tastefully in a thick brocade gown that showcases her "+
         "talents.  While she is not overly beautiful, her "+COLOR2+" hair "+
         "%^RESET%^%^CYAN%^has been brushed to a shine, suggesting "+
         "an interest in her appearance.  Her "+COLOR+" eyes %^RESET%^"+
         "%^CYAN%^appear cool and calculating, and it seems she "+
         "knows a deal when she hears one.");
      set_storage_room("/d/dagger/tonovi/town/storage/clothing");
      set_items_allowed("clothing");
      set_gender("female");
}