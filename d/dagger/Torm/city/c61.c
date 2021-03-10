//updated by Circe 10/26/03.  The unlock has been put in reset so that it won't lock during the daytime.
//updated for Rubicant's player house/shop going in *Styx*  5/06

#include <std.h>
#include "../tormdefs.h"
inherit whatever;

void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("%^BOLD%^%^RED%^Shop entrance%^RESET%^");
   set_door("double doors","/d/player_stores/rubicant/shop_main","north",0);
     set_string("double doors", "open", "The %^RED%^doors%^WHITE%^ open without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
     set_string("double doors", "close", "The %^RED%^doors%^WHITE%^ close solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
  set_long("%^BOLD%^%^RED%^Shop entrance%^RESET%^\n"
	"Just to the east is Torm's marketplace, bustling with vendors "
	"calling out their wares to the numerous people wandering about.  "
	"To the north of the road is a %^BOLD%^beautiful domed "
	"structure%^RESET%^ built with beautifully hewn slabs of "
	"%^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^n%^RESET%^i%^BOLD%^"
	"%^BLACK%^te%^RESET%^. Fluttering softly on the ocean breeze "
	"against the smooth walls are %^BOLD%^%^BLACK%^black "
	"tapestries%^RESET%^ with a %^BOLD%^%^RED%^scarlet "
	"silhouette%^RESET%^ of a female angel with wings and arms "
	"spread, her face tilted to the heavens. A large %^RED%^cherrywood "
	"sign%^WHITE%^ is mounted above a pair of magnificent %^RED%^"
	"double doors%^WHITE%^, proclaiming the name of the establishment "
	"in scarlet ink, '%^BOLD%^%^RED%^The Scarlet Angel%^RESET%^'."
  );
  set("night long", "%^BOLD%^%^RED%^Shop entrance%^RESET%^\n"
	"%^RESET%^%^BLUE%^Just to the east is Torm's marketplace, the "
	"bustling of the day replaced with the silence of night. To the "
	"north of the road is a %^BOLD%^%^WHITE%^beautiful domed "
	"structure%^RESET%^%^BLUE%^ built with beautifully hewn slabs of "
	"%^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^n%^RESET%^i%^BOLD%^"
	"%^BLACK%^te%^RESET%^%^BLUE%^ that are covered in large, "
	"intricate %^BOLD%^%^RED%^scarlet runes%^RESET%^%^BLUE%^ that "
	"seem to shimmer and glow slightly under the night sky.  "
	"Fluttering softly on the ocean breeze against the smooth walls "
	"are %^BOLD%^%^BLACK%^black tapestries%^RESET%^%^BLUE%^ with a "
	"%^BOLD%^%^RED%^scarlet silhouette%^RESET%^%^BLUE%^ of a female "
	"angel with wings and arms spread, her face tilted to the "
	"heavens.  A large %^RED%^cherrywood sign%^BLUE%^ is mounted "
	"above a pair of magnificent %^RED%^double doors%^BLUE%^, "
	"proclaiming the name of the establishment in scarlet ink, "
	"'%^BOLD%^%^RED%^The Scarlet Angel%^RESET%^%^BLUE%^.'%^RESET%^"
  );
  set_exits(([
     "east":TCITY+"c62",
     "west":TCITY+"c59",
     "north": "/d/player_stores/rubicant/shop_main",
  ]));
}

void reset(){
   ::reset();
   if(query_night() == 1) {
      set_open("door",0);
   }
   else {
      set_open("door",1);
   }
}

/* set_door("door",TCITY+"c60","north","masterkey");
  set_long(
  "Side street in Torm.\n"
    "  Torm's marketplace is just to the east, and you can hear the many people there talking and the calls of the vendors."
    "  A small wooden shop north of you here has a sign of a needle and thread over its door, proclaiming it as a tailor's shop."
  );
  set("night long",
  "%^BLUE%^"
  "This side street seems to collect the fog that has spread out over"+
  " the city this night, making it difficult to see.  The road runs"+
  " to the east and west, and there is a shop to the north that has"+
  " the tailor's sign of a needle and thread, but it appears to be"+
  " closed right now, best to come back in the morning."
  );
*/
