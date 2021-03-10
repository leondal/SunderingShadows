//Octothorpe (1/15/17)
//Shadow, Mage Tower Foyer
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("Foyer of the Shadow Mage Tower");
   set_short("%^MAGENTA%^Foyer of the %^BOLD%^%^BLACK%^Shadow"+
      " %^RESET%^%^MAGENTA%^Mage Tower");
   set_long("%^MAGENTA%^Foyer of the %^BOLD%^%^BLACK%^Shadow"+
      " %^RESET%^%^MAGENTA%^Mage Tower\n"+
      "%^MAGENTA%^Entering the foyer you are confronted by a "+
      "decorative staircase that leads to a balcony. The walls are "+
      "made from %^BOLD%^%^BLACK%^p%^RESET%^a%^BOLD%^%^BLACK%^le "+
      "gr%^RESET%^a%^BOLD%^%^BLACK%^y sto%^RESET%^n%^BOLD%^%^BLACK%^e "+
      "%^RESET%^%^MAGENTA%^and covered in beautifully painted "+
      "%^RESET%^murals%^MAGENTA%^. Above the main door, set into a "+
      "wide alcove, is a massive statue of %^BOLD%^%^BLUE%^Kismet, "+
      "Lady of Mysteries%^RESET%^%^MAGENTA%^. Looking straight upwards "+
      "creates a dizzying effect as a narrow white stone staircase looms "+
      "overhead, spiraling around and ever upward. Drifting down from "+
      "this vast space is a haunting and sporadic %^BOLD%^melody"+
      "%^RESET%^%^MAGENTA%^, and it takes you a moment to realize "+
      "the music is played by the %^CYAN%^wind %^MAGENTA%^itself, "+
      "caught in %^RESET%^piping %^MAGENTA%^somewhere far above. A "+
      "few %^ORANGE%^benches %^MAGENTA%^and %^GREEN%^plants "+
      "%^MAGENTA%^complete the space.%^RESET%^\n\n"+
      "%^CYAN%^Behind the staircase is a set of intricately designed "+
      "%^RESET%^double doors %^CYAN%^that lead into the library. A "+
      "%^RESET%^small archway %^CYAN%^is set into the side of the "+
      "staircase itself and could easily go unnoticed.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^GREEN%^Hints of %^RESET%^%^GREEN%^"+
      "floral %^BOLD%^and %^RESET%^%^GREEN%^fauna %^BOLD%^linger in "+
      "the air, fresh and clean.%^RESET%^");
   set_listen("default","%^BOLD%^%^CYAN%^A %^RESET%^haunting melody "+
      "%^BOLD%^%^CYAN%^drifts down from far overhead.%^RESET%^");
   set_items(([
      "staircase" : "%^RESET%^%^CYAN%^The stairs are "+
         "tiled in small pieces of %^MAGENTA%^c%^BLUE%^o%^GREEN%^l"+
         "%^ORANGE%^o%^CYAN%^r%^MAGENTA%^fu%^CYAN%^l g%^ORANGE%^l"+
         "%^GREEN%^a%^BLUE%^s%^MAGENTA%^s%^CYAN%^. The awe-inspiring "+
         "mosaic depicts a %^YELLOW%^bright sun %^RESET%^%^CYAN%^at "+
         "the bottom and a dark %^BOLD%^%^WHITE%^crescent moon "+
         "%^RESET%^%^CYAN%^near the top, both surrounded by dozens "+
         "of %^BOLD%^%^WHITE%^st%^RESET%^%^CYAN%^a%^BOLD%^r%^WHITE%^"+
         "s%^RESET%^%^CYAN%^. A simple %^BOLD%^%^BLACK%^black "+
         "banister %^RESET%^%^CYAN%^leads the way upwards and fans "+
         "out, circling the balcony above.%^WHITE%^",
      "statue" : "%^BOLD%^%^BLUE%^This %^RESET%^marble statue "+
         "%^BOLD%^%^BLUE%^is truly a wonder to behold. A sense of "+
         "%^RESET%^%^BLUE%^power %^BOLD%^radiates from it, but the "+
         "power's essence is within the art itself and the creator's "+
         "ability to capture the face of a Goddess. This portrayal "+
         "of the %^RESET%^%^BLUE%^Lady of Mysteries %^BOLD%^defies "+
         "senses: So %^MAGENTA%^otherworldly %^BLUE%^and %^MAGENTA%^"+
         "strange %^BLUE%^is this divine being, yet so realistic are "+
         "the graceful sweeps of %^RESET%^stone %^BOLD%^%^BLUE%^and "+
         "the delicate curvature of her feminine physique. Long "+
         "%^BLACK%^dark hair %^BLUE%^lashes around her torso and "+
         "her %^RESET%^%^CYAN%^silken robes %^BOLD%^%^BLUE%^cling and "+
         "tug, caught in the %^RESET%^frenzy %^BOLD%^%^BLUE%^of a "+
         "spell. Her arms are raised, her palms turned up. Her upwards "+
         "gaze %^RESET%^%^GREEN%^smolders %^BOLD%^%^BLUE%^with an "+
         "intense assuredness in her magic, and an %^RESET%^"+
         "%^MAGENTA%^incantation %^BOLD%^%^BLUE%^parts her perfectly "+
         "chiseled lips.%^RESET%^",
      ({"mural","murals"}) : "%^RESET%^%^CYAN%^The murals are quite "+
         "realistic, and in fact did one just move? They're highly "+
         "colorful, and there are eight in total, depicting the eight "+
         "schools of magic practiced here.%^WHITE%^",
      ({"spire", "white staircase"}) : "%^RESET%^%^CYAN%^A white "+
         "staircase spirals upwards at a steep angle. Although "+
         "they're rather high above your head, you catch glimpses "+
         "of the %^YELLOW%^golden pipes %^RESET%^%^CYAN%^which must "+
         "be the source of the haunting music that drifts down.%^WHITE%^",
      "floor" : "%^RESET%^%^CYAN%^The floor is covered in square "+
         "stones that range in color from %^BOLD%^%^BLACK%^p%^RESET%^"+
         "a%^BOLD%^%^BLACK%^le gr%^RESET%^a%^BOLD%^%^BLACK%^y "+
         "%^RESET%^%^CYAN%^to %^BOLD%^%^MAGENTA%^d%^RESET%^%^MAGENTA%^"+
         "u%^BOLD%^sky pu%^BLACK%^r%^RESET%^%^MAGENTA%^p%^BOLD%^le"+
         "%^RESET%^%^CYAN%^. It is very clean.%^WHITE%^",
      ({"benches","plants"}) : "%^RESET%^%^CYAN%^Placed around the "+
         "room, these small accents break up the formality of the "+
         "grand foyer.%^WHITE%^"
   ]));
   set_exits(([
      "east" : ROOMS"magecourt",
      "archway" : ROOMS"magearchway",
      "north" : ROOMS"magelibrary",
      "up" : ROOMS"mage2ndlanding"
   ]));
}
