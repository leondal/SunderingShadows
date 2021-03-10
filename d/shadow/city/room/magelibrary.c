//Octothorpe (1/18/17)
//Shadow, Mage Tower Library
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("Library of the Shadow Mage Tower");
   set_short("%^YELLOW%^Library of the %^BOLD%^%^BLACK%^Shadow "+
      "%^RESET%^%^YELLOW%^Mage Tower");
   set_long("%^YELLOW%^Library of the %^BOLD%^%^BLACK%^Shadow "+
      "%^RESET%^%^YELLOW%^Mage Tower\n"+
      "%^RESET%^The sheer number of %^ORANGE%^books %^WHITE%^and "+
      "%^ORANGE%^scrolls %^WHITE%^gathered here is impressive. They "+
      "line the walls, towering so high that two tiers of walkways "+
      "circle the room, giving access to the highest shelves. It "+
      "would be nearly impossible to categorize and organize this "+
      "expansive wealth of %^BOLD%^%^MAGENTA%^knowledge %^RESET%^and, "+
      "as such, it is difficult to find much of anything. The room is "+
      "primarily made from %^BOLD%^meticulously %^RESET%^%^ORANGE%^c"+
      "%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rv%^BOLD%^%^BLACK%^e"+
      "%^RESET%^%^ORANGE%^d wo%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^"+
      "d%^WHITE%^, it's impressive patterns and designs unlike anything "+
      "you've seen before. Unobtrusive %^MAGENTA%^rugs %^WHITE%^line "+
      "the floor to muffle any footsteps, and the room is indeed rather "+
      "%^BOLD%^%^BLACK%^quiet%^RESET%^. Above the highest shelves, "+
      "large panels of glass let natural %^YELLOW%^light %^RESET%^"+
      "spill into the room. And after %^BOLD%^%^BLACK%^dark%^RESET%^, "+
      "%^BOLD%^enchanted orbs %^RESET%^spread a soft %^YELLOW%^gl"+
      "%^RESET%^%^ORANGE%^o%^BOLD%^w %^RESET%^over the room. Many "+
      "%^ORANGE%^tables %^WHITE%^are situated around the room, "+
      "accommodating small groups as well as individual scholars.\n\n"+
      "%^BOLD%^A narrow circular staircase sits in the corner, leading "+
      "up to a loft which overlooks the main library floor.%^RESET%^\n");
   set_smell("default","%^ORANGE%^It smells wonderfully of %^BOLD%^"+
      "%^WHITE%^old %^RESET%^%^ORANGE%^parchment.%^RESET%^");
   set_listen("default","%^CYAN%^A soft %^WHITE%^murmuring %^CYAN%^"+
      "of voices is heard over the %^WHITE%^whisper %^CYAN%^of turning "+
      "pages.%^RESET%^");
   set_items(([
      ({"books","scrolls","shelves"}) : "%^RESET%^%^CYAN%^Some of the "+
         "books and scrolls look so old that you're afraid touching "+
         "them would turn them to %^WHITE%^dust%^CYAN%^. Others are so "+
         "new you can still smell the fresh %^BOLD%^%^BLACK%^ink"+
         "%^RESET%^%^CYAN%^. They line the shelves by the thousands, "+
         "and offer as many genres. Any serious scholar would happily "+
         "call this place heaven.%^WHITE%^",
      "woodwork" : "%^RESET%^%^CYAN%^Nearly every bit of %^ORANGE%^"+
         "wood %^CYAN%^in this room has been intricately carved into "+
         "something. Amongst the myriad of designs are strange "+
         "patterns, eerie faces, lovely floral wreaths, legendary "+
         "animals, angels and demons. While there is a sense of "+
         "symmetry to the woodwork, it is hard to settle your gaze "+
         "on just one section. It's truly %^BOLD%^magnificent%^RESET%^"+
         "%^CYAN%^.%^WHITE%^",
      ({"windows","panels","glass"}) : "%^RESET%^%^CYAN%^The windows "+
         "sit high above the floor, allowing natural %^BOLD%^light "+
         "%^RESET%^%^CYAN%^to flood into the room.%^WHITE%^",
      ({"lights","orbs"}) : "%^RESET%^%^CYAN%^The softly %^BOLD%^gl"+
         "%^RESET%^o%^BOLD%^%^CYAN%^w%^RESET%^in%^BOLD%^%^CYAN%^g "+
         "or%^RESET%^b%^BOLD%^%^CYAN%^s %^RESET%^%^CYAN%^are placed "+
         "on %^BOLD%^%^BLACK%^wrought iron posts %^RESET%^%^CYAN%^"+
         "and are reminiscent of street lamps. They are spread "+
         "throughout the room, providing ample lighting for "+
         "studying.%^WHITE%^",
      ({"staircase","balcony"}) : "%^RESET%^ %^CYAN%^In the corner of "+
         "the room, blending in with the library's splendid woodwork, "+
         "is this easily overlooked, lovely %^BOLD%^ornament%^RESET%^"+
         "%^CYAN%^. Cut from %^ORANGE%^d%^BOLD%^%^BLACK%^a%^RESET%^"+
         "%^ORANGE%^rk wo%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^d "+
         "%^CYAN%^that matches the rest of the room, the narrow "+
         "staircase spirals far overhead to a small %^BOLD%^balcony "+
         "%^RESET%^%^CYAN%^area that overlooks the main floor. It "+
         "is difficult to tell what's above from this vantage "+
         "point.%^WHITE%^",
      ({"rugs","floor","floors"}) : "%^RESET%^%^CYAN%^These simple "+
         "and unobtrusive %^ORANGE%^d%^BOLD%^%^BLACK%^a%^RESET%^"+
         "%^ORANGE%^rk bro%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^n "+
         "r%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^gs %^CYAN%^are made "+
         "to muffle sound, nothing more or less. They cover a floor "+
         "made from %^BOLD%^%^BLACK%^dark gray stone%^RESET%^"+
         "%^CYAN%^.%^WHITE%^",
      "ceiling" : "%^RESET%^%^CYAN%^The entirety of the room is "+
         "covered in intricately designed %^ORANGE%^woodwork"+
         "%^CYAN%^, and the ceiling is no exception. Divided into large, "+
         "rectangular panels, the images above were carefully carved "+
         "and then painted. Depicted are the %^BOLD%^eight %^RESET%^"+
         "%^CYAN%^schools of magic most widely studied in the realms.%^WHITE%^"
   ]));
   set_exits(([
      "south" : ROOMS"magefoyer",
      "up" : ROOMS"magetea",
   ]));
}
