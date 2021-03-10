//updated by Circe 6/26/04 in response to numerous bug reports
#include <std.h>
inherit "/std/food";

#define FISH ([ "brim":2, "mackeral":3, "blue fish":5, "trout":10, "flounder":12, "bass":15 ])

void create() {
int i;
string myfish,*fishes;
   ::create();
   fishes = keys(FISH);
   myfish = fishes[random(sizeof(fishes))];
   set_name("a fish");
   set_my_mess("You eat the messy raw fish.");
   set_your_mess("gnaws on a messy raw fish.");
   set_short("a "+myfish+"");
   set_long("A good-sized "+myfish+" that would "+
         "probably provide some nourishment.  Its scales are "+
         "iridescent and it appears quite fresh.");
   set_id(({"fish",""+myfish+""}));
   set_raw(5);
//set_raw added by Circe 12/10/04 to allow cooking of fish
   set_strength(FISH[myfish]);
   set_weight(5);
}
