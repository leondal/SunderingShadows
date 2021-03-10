//Octothorpe (2/1/17)
//Three Coins Inn Second Floor Balcony
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Second Floor Balcony, Three Coins Inn, Shadow");
   set_short("%^BOLD%^%^WHITE%^Second Floor Balcony, Three Coins "+
      "Inn, Shadow%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Second Floor Balcony, Three Coins "+
      "Inn, Shadow%^RESET%^\n"+
      "%^BOLD%^%^BLACK%^From here, you have a nice view of the %^RESET%^"+
      "stone courtyard %^BOLD%^%^BLACK%^below. The %^CYAN%^v%^RESET%^"+
      "%^CYAN%^a%^BOLD%^st sky %^BLACK%^spreads open above you. A "+
      "narrow, covered stone staircase leads up to another floor where "+
      "the inn's restaurant is found. Three %^ORANGE%^ar%^WHITE%^c"+
      "%^RESET%^%^ORANGE%^h%^BOLD%^%^WHITE%^e%^ORANGE%^d d%^WHITE%^"+
      "o%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^r%^ORANGE%^s %^BLACK%^"+
      "open into the guest rooms. Each room features a small %^RESET%^"+
      "shuttered window%^BOLD%^%^BLACK%^, the sills lined with "+
      "%^MAGENTA%^flowers%^BLACK%^. A %^RESET%^%^ORANGE%^runner "+
      "%^BOLD%^%^BLACK%^wraps around the length of the balcony, "+
      "muffling any loud footsteps. As it does below, %^GREEN%^ivy "+
      "%^BLACK%^climbs the stone walls, adding a nice complement to "+
      "the simple but elegant decorations. Staircases lead to both the "+
      "courtyard and the street.\n");
   set_smell("default","%^GREEN%^The faint scents of %^BOLD%^food "+
      "%^RESET%^%^GREEN%^and %^BOLD%^flowers %^RESET%^%^GREEN%^mingle "+
      "here.%^RESET%^");
   set_listen("default","%^RESET%^The soft %^BOLD%^murmur %^RESET%^of "+
      "conversation drifts up from the courtyard.");
   set_items(([
      "courtyard" : "%^RESET%^%^GREEN%^This outdoor courtyard looks "+
         "like a comfortable area to relax and enjoy the open air. Ivy "+
         "climbs the stone archways that lead off to the left or right. "+
         "Some small chairs have been set up for lounging, and the decor "+
         "is simple but elegant. A nice rug covers the tile floor.%^RESET%^",
      "staircase" : "%^RESET%^%^GREEN%^A narrow passage of steps, "+
         "covered by an arch of light stonework, leads upwards and "+
         "opens into the restaurant on the top floor. Softly %^BOLD%^"+
         "glowing orbs %^RESET%^%^GREEN%^light the way, but the "+
         "staircase is still a bit %^BOLD%^%^BLACK%^dim%^RESET%^"+
         "%^GREEN%^.%^RESET%^",
      ({"doors","door"}) : "%^RESET%^%^GREEN%^Three doors denote the "+
         "colors of Shadow's emblem, the %^BOLD%^%^WHITE%^silver"+
         "%^RESET%^%^GREEN%^, %^YELLOW%^gold %^RESET%^%^GREEN%^and "+
         "%^ORANGE%^copper %^GREEN%^rings. They are rounded at the "+
         "top, and are otherwise plain.%^RESET%^",
      ({"windows","window","flowers"}) : "%^RESET%^%^GREEN%^Painted in "+
         "the same colors as the doors they pair with, these windows "+
         "are quaint, with shutters that can be opened or closed. "+
         "%^WHITE%^Small flowers %^GREEN%^fill the window boxes, adding "+
         "a bit of charm to the windows.%^RESET%^",
      ({"ivy","walls","lanterns"}) : "%^RESET%^%^BOLD%^%^GREEN%^Ivy "+
         "%^RESET%^%^GREEN%^climbs the walls in some spots, adding a "+
         "touch of color to the light %^BOLD%^%^BLACK%^stonework%^RESET%^"+
         "%^GREEN%^, while %^BOLD%^%^WHITE%^silver lanterns %^RESET%^"+
         "%^GREEN%^hang at evenly spaced intervals in others. They "+
         "provide a comfortable light to the area that is neither too "+
         "bright nor too dim.%^RESET%^",
      "decor" : "%^RESET%^%^GREEN%^Potted %^BOLD%^trees %^RESET%^"+
         "%^GREEN%^and %^BOLD%^flowers %^RESET%^%^GREEN%^are tucked "+
         "into small alcoves and corners, while curious, perfectly "+
         "%^BOLD%^%^BLACK%^rounded stones %^RESET%^%^GREEN%^of varying "+
         "sizes are arranged here and there.%^RESET%^",
      "runner" : "%^RESET%^%^GREEN%^Made from a tough material meant "+
         "to weather storms, this is a simple %^ORANGE%^brown runner "+
         "%^GREEN%^that repeats the image of %^BOLD%^%^WHITE%^t"+
         "%^ORANGE%^h%^RESET%^%^ORANGE%^r%^BOLD%^e%^WHITE%^e "
         "in%^ORANGE%^t%^RESET%^%^ORANGE%^e%^BOLD%^r%^WHITE%^loc"+
         "%^ORANGE%^k%^RESET%^%^ORANGE%^i%^BOLD%^n%^WHITE%^g "+
         "ri%^ORANGE%^n%^RESET%^%^ORANGE%^g%^BOLD%^s%^RESET%^"+
         "%^GREEN%^.%^RESET%^"
   ]));
   set_exits(([
      "gold" : ROOMS"3coinsgold",
      "silver" : ROOMS"3coinssilver",
      "copper" : ROOMS"3coinscopper",
      "up" : ROOMS"3coinsrest",
      "down" : ROOMS"3coinscourt"
   ]));
   set_door("gold door",ROOMS"3coinsgold","gold",0,0);
   set_door_description("gold door","%^YELLOW%^This wooden door is "+
      "painted gold. The top of the door is rounded, but otherwise "+
      "it is plain.%^RESET%^");
   set_door("silver door",ROOMS"3coinssilver","silver",0,0);
   set_door_description("silver door","%^BOLD%^%^WHIET%^This wooden "+
      "door is painted silver. The top of the door is rounded, but "+
      "otherwise it is plain.%^RESET%^");
   set_door("copper door",ROOMS"3coinscopper","copper",0,0);
   set_door_description("copper door","%^ORANGE%^This wooden door is "+
      "painted copper. The top of the door is rounded, but otherwise "+
      "it is plain.%^RESET%^");
}
