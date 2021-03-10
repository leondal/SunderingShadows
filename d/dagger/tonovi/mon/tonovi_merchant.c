//by Circe 12/29/04 to add random vendors to Tonovi
#include <std.h>
#include "../short.h"

inherit VENDOR;
string COLOR,COLOR2;

#define COLORS ({"%^BOLD%^%^BLUE%^blue","%^BOLD%^azure","%^YELLOW%^amber","%^ORANGE%^brown","%^BOLD%^%^BLACK%^gray","%^GREEN%^green","%^BOLD%^%^GREEN%^emerald"})

#define COLORS2 ({"%^YELLOW%^blonde","%^RESET%^wheat-colored","%^ORANGE%^brown","%^BOLD%^%^BLACK%^black","%^RED%^auburn","%^BOLD%^%^RED%^crimson"})

void make_me();

void create() {
   int i,j;
  ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   j = random(sizeof(COLORS2));
   COLOR2 = COLORS2[j];
   make_me();
   set_hd(12,2);
   set("aggressive", 0);
   set_level(12);
   set_class("fighter");
   set_mlevel("fighter", 12);
   set_guild_level("fighter",12);
   set_alignment(5);
   set_race("human");
   add_money("gold", random(50));
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_overall_ac(-9);
   set_stats("strength",16);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(100);
   set_storage_room("/d/dagger/tonovi/town/storage/tobacco");
}

void make_me() {
   switch(random(5)) {
      case 0:
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
	break;
     case 1:
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
	break;
     case 2:
	set_name("perfume dealer");
	set_id(({"shop clerk","shopkeeper","clerk","perfume dealer","dealer"}));
	set_short("A perfume dealer");
	set_long("This young man is dressed in the rather unusual "+
         "manner of those from Azha.  His legs are clad in puffy "+
         "pantaloons, while his stylish jacket could only be called "+
         "a kameez.  The turban wound around his head reveals only "+
         "a tiny glimpse of his "+COLOR2+" hair%^RESET%^%^CYAN%^, "+
         "and a shining gem dangles upon his forehead, just above "+
         "his "+COLOR+" eyes%^RESET%^%^CYAN%^.  He stands at a small "+
         "cart fitted with shelves displaying small bottles of "+
         "fragrances from all over the realms.");
      set_gender("male");
      set_storage_room("/d/dagger/tonovi/town/storage/fragrance");
      set_items_allowed("misc");
	break;
     case 3:
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
	break;
     case 4:
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
      set_items_allowed("misc");
	break;
   }
}

	
   