#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A garden in Aketon");
   set_long("%^GREEN%^A garden in Aketon%^RESET%^\n"+
   "This section of garden seems to be a bit more wild than the rest."+
   " Directly in front of you is a small plot that contains an unusual"+
   " and somewhat rare plant known as a shooting star. Growing in a"+
   " circular trough around the central pot are white flowers known as"+
   " spring beauties. In a larger pot closer to the center of the room"+
   " is a plant known as the showy milkweed. On the southwest corner"+
   " is a large circle of willow blue stars that seem to be prospering."+
   " East of the willow blue stars is another long trough, this one"+
   " filled with bowman's-root. The north side is taken up with a long"+
   " trough that is completely filled with a strange plant called goat's"+
   " beard. On the far east side of the garden is trough filled with"+
   " yellow sundrops and a few sunflowers on either end to greet the"+
   " sun as it rises each morning.");
   set_smell("default","The smells of the are garden pleasant.");
   set_listen("default","The wind rustles gently through the leaves.");
   set_items(([
   "shooting star" : "%^BOLD%^%^MAGENTA%^The shooting star has a thick"+
   " %^GREEN%^green stalk%^MAGENTA%^ that rises straight up. At the"+
   " very top are several slender stems that bend over with the weight"+
   " of the flowers they hold. The flowers themselves are a light"+
   " lavender and have five petals that fold back away from the center"+
   " of the flower, which hangs down. The central part is a %^YELLOW%^yellow"+
   " bulb%^MAGENTA%^ rimmed in %^WHITE%^white%^MAGENTA%^ with %^RESET%^%^MAGENTA%^dark"+
   " purple center%^BOLD%^. Several %^WHITE%^white stamen%^MAGENTA%^"+
   " protrude from the bulb, coming together at the ends and pointing"+
   " towards the ground. The overall effect is rather similar to a"+
   " a bright shooting star trailing through a purple sky.%^RESET%^",
   "spring beauties" : "%^BOLD%^These flowers are quite delicate looking"+
   " and have five petals that tend to curve upwards at the ends. The"+
   " backs of the petals are a solid white, while the front is striped"+
   " with %^MAGENTA%^pink veins%^WHITE%^. A %^YELLOW%^yellow stamen%^WHITE%^"+
   " protrudes from the center. The flowers begin closed up so that"+
   " all you see is their solid white backs, but they slowly open up"+
   " as they come into full bloom.%^RESET%^",
   ({"milkweed","showy milkweed"}) : "%^BOLD%^The plant has several"+
   " very large %^GREEN%^slick green leaves%^WHITE%^ with a thick stalk"+
   " coming up the center. Near the top a smaller stalk will split off"+
   " to hold a ball made of a multitude of delicate star shaped flowers"+
   " that each have a %^MAGENTA%^light purple%^WHITE%^ stripe running"+
   " down the center of their petals. It is a very pretty and quite"+
   " unusual looking plant.%^RESET%^",
   ({"blue stars","willow blue stars"}) : "%^BOLD%^%^CYAN%^The willow"+
   " blue stars are a fast growing plant that tends to expand outwards."+
   " This one is kept contained in a circular trough of earth, but it"+
   " is absolutely teeming with blue stars. The leaves are a slender"+
   " %^RESET%^%^GREEN%^dark green%^BOLD%^%^CYAN%^ and the ends of the"+
   " stalk are covered in a small light blue flowers that are star"+
   " shaped with five tiny petals that extend outward.%^RESET%^",
   ({"bowmans root","bowman's-root","bowmans-root","bowman's root"}) : "%^BOLD%^The"+
   " bowman's-root normally grows wild, but it is rather pretty and"+
   " fitting in this section of the garden. There are simply hundreds"+
   " of tiny white star shaped flowers whose edges are all lined in"+
   " %^RESET%^%^MAGENTA%^dark purple%^BOLD%^%^WHITE%^. All the flowers"+
   " are extended from very delicate stems, and there are only a few"+
   " %^GREEN%^green leaves%^WHITE%^ anywhere.%^RESET%^",
   ({"goat's beard","goats beard"}) : "%^BOLD%^The goats beard plant"+
   " is almost six feet tall and seems to be doing well. The tops of"+
   " the long stalks are covered in many fuzzy white plumes that branch"+
   " outwards, kind of resembling a goat's beard. The rest of the plant"+
   " has many smaller %^RESET%^%^GREEN%^dark green leaves%^BOLD%^%^WHITE%^."+
   " It is definitely an unusual plant.%^RESET%^",
   ({"sundrops","yellow sundrops"}) : "%^YELLOW%^The sundrops grow close"+
   " to the ground and have many slender %^RESET%^%^GREEN%^dark green"+
   " leaves%^YELLOW%^. The flowers reach upwards and have five"+
   " overlapping yellow petals that create a circle. The center of the"+
   " flowers is filled with several stamen that are covered in yellow"+
   " pollen. It is a pretty little plant.%^RESET%^",
   "sunflowers" : "%^YELLOW%^There are a few tall sunflowers with their"+
   " centers full of ripening seeds, and the yellow petals stretching out"+
   " over the sides. They grow on tall %^RESET%^%^GREEN%^dark green stalks%^YELLOW%^"+
   " and will turn to face wherever the sun is.%^RESET%^",
   ]));
   set_exits( (["west":RPATH3+"3three3"]) );
}
