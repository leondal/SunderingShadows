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
	set_name("jeweler");
	set_id(({"shop clerk","shopkeeper","clerk","jeweler","wandering jeweler"}));
	set_short("A wandering jeweler");
	set_long("This middle-aged vendor features a wide variety of "+
         "jewelry at her stall.  Her wares seem ever-changing, "+
         "all dependent upon the best deals in the land at the time.  "+
         "Streaks of silver have begun to highlight her "+COLOR2+" "+
         "hair%^RESET%^%^CYAN%^, and her "+COLOR+" eyes %^RESET%^"+
         "%^CYAN%^look to have seen much in this life.  Two tall, "+
         "stout personal guards stand near her stall to keep those "+
         "who might be light of fingers away.");
      set_gender("female");
      set_storage_room("/d/dagger/tonovi/town/storage/jewelry");
      set_items_allowed("clothing");
}
