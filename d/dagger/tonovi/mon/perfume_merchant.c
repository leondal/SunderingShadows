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
}