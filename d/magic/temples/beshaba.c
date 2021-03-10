#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_indoors(0);
   set_name("A ruined stone building");
   set_short("%^BOLD%^%^MAGENTA%^A ruined stone building%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Little more than crumbled stone remains of "
      "this temple. Debris lies scattered across the floor, and the fresh "
      "scent of the outdoors seeps in through the fallen walls, entwining "
      "with a faint scent of %^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^s%^BOLD%^"
      "%^WHITE%^h %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^de%^GREEN%^c"
      "%^ORANGE%^ay%^BOLD%^%^BLACK%^. Black rats scurry across the marble "
      "floor, which is partially covered with a stained %^RESET%^%^RED%^m"
      "%^MAGENTA%^a%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^v%^RED%^e "
      "%^BOLD%^%^BLACK%^wool rug. Shattered pillars have been abandoned "
      "where they have fallen. Placed upon the destroyed altar, held high "
      "on a pair of black antlers, is a scorched %^RESET%^%^CYAN%^steel tablet "
      "%^BOLD%^%^BLACK%^defaced by deep %^RESET%^%^RED%^claw marks%^BOLD%^"
      "%^BLACK%^. Above this, suspended on the tips of the horn rack is the "
      "headless, %^RESET%^skeletal %^BOLD%^%^BLACK%^remains of a corpse.  Old %^RESET%^"
      "%^RED%^dried blood %^BOLD%^%^BLACK%^stains the horns, %^RESET%^%^CYAN%^"
      "tablet %^BOLD%^%^BLACK%^and the broken shards of a %^RESET%^mirror "
      "%^BOLD%^%^BLACK%^set under the antlers.\n%^RESET%^");
   set_items(([
      ({"debris","floor","marble","marble floor"}) : "Crumbled stone and dust "
         "litter the once smooth %^BOLD%^%^BLACK%^ma%^RESET%^%^MAGENTA%^r%^BOLD%^"
         "%^BLACK%^bl%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLACK%^fl%^MAGENTA%^o%^BLACK%^"
         "or%^RESET%^. The %^BOLD%^%^BLACK%^black marble %^RESET%^is shot through "
         "with thin veins of %^RED%^m%^MAGENTA%^a%^BOLD%^u%^RESET%^%^MAGENTA%^v"
         "%^RED%^e %^RESET%^and hints of its former beauty remain beneath the "
         "dust and the stained %^RED%^m%^MAGENTA%^a%^BOLD%^u%^RESET%^%^MAGENTA%^v"
         "%^RED%^e%^RESET%^ rug lying in tatters across the middle of the floor.",
      ({"wall","walls"}) : "The stone walls once towered high overhead, competing "
         "with the trees in their reach for the sky. Now, none stands more than six "
         "feet high, and huge chunks have fallen in various places. Their decrepit "
         "state leaves the ruins open to the elements.",
      ({"rats","black rat","rat","black rat"}) : "Black rats with eerie red eyes "
         "scurry across the floor, their claws scraping along the marble. Some "
         "crawl over the altar, and a few seem to be creating a nest in a "
         "sheltered corner of the wall.",
      ({"altar","horns","black horns","mirror","antlers","black antlers"}) : "A slab of %^BOLD%^%^BLACK%^black marble "
         "%^RESET%^polished to a high shine served as the altar in this fallen temple. "
         "Now, chunks are misses and corners have been smashed, but the %^BOLD%^"
         "%^BLACK%^black antlers %^RESET%^atop the altar still stand tall. Around their "
         "base lie shards of a shattered mirror, while the antlers hold "
         "a scorched %^RESET%^%^CYAN%^steel tablet %^RESET%^and %^BOLD%^skeletal "
         "remains%^RESET%^, hinting at some dark event here.",
      ({"tablet","steel tablet","claw marks"}) : "Balanced in the center of the antlers "
         "is a steel tablet that once bore writing of some sort. The message has been "
         "obliterated by the deep claw marks that have all but shredded the metal.",
      ({"corpse","remains","skeletal remains"}) : "A gruesome headless corpse has been "
         "impaled on the antlers, its flesh long since withered away. Many of the bones "
         "have been bleached white by the elements, making the aged, nearly black "
         "blood staining them stand out.",
      ({"blood","dried blood"}) : "Splatters of %^BOLD%^%^BLACK%^dr%^RESET%^%^RED%^i"
         "%^BOLD%^e%^BLACK%^d b%^RESET%^%^RED%^l%^BOLD%^o%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^d "
         "%^RESET%^cover the headless corpse and its surroundings. Whatever happened here, "
         "it is clear the corpse was the result of something horrific."
   ]));
   set_smell("default","The scent of ash and decay lingers in the air.");
   set_listen("default","The squeaking of rats can be heard as they scamper about.");
   set_exits(([
      "out":"/d/azha/theater/rooms/azp4"
   ]));
}