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
	set_name("candle importer");
	set_id(({"shop clerk","shopkeeper","clerk","importer","candle importer"}));
	set_short("A candle importer");
	set_long("This elderly woman sports long %^RESET%^gray locks "+
         "%^CYAN%^wound into a bun.  Despite her advanced years, she "+
         "seems capable enough, as do the young guards wandering past "+
         "her.  Her "+COLOR+" eyes %^RESET%^%^CYAN%^harbor a kindness "+
         "unusual in this city, though she seems unlikely to let any "+
         "unfair deals be passed her way.  Her cart features a wide "+
         "assortment of candles and wax, many primarily bearing the "+
         "same impression.");
      set_gender("female");
      set_storage_room("/d/dagger/tonovi/town/storage/candles");
      set_items_allowed("misc");
}