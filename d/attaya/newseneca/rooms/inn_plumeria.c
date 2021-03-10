//inn_plumeria.c by ~Circe~ 1/2/16
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Guest Room of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Guest Room of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Guest Room of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "%^RESET%^%^ORANGE%^Bookshelves stretching from floor to ceiling along the southern "
      "wall dominate this cozy room. A %^GREEN%^window seat%^ORANGE%^ is nestled among "
      "the %^YELLOW%^books%^RESET%^%^ORANGE%^, providing a wide, padded place for a "
      "reader to recline. The wide, arched %^CYAN%^window %^ORANGE%^is open to the "
      "elements, allowing the tropical breeze to bring both the soothing fragrance "
      "of the %^BOLD%^%^BLUE%^ocean%^RESET%^%^ORANGE%^ and the muffled sounds of "
      "the city streets. The eastern wall features a %^RESET%^s%^BOLD%^t%^RESET%^"
      "%^ORANGE%^o%^YELLOW%^n%^RESET%^e %^ORANGE%^f%^RESET%^i%^BOLD%^r%^YELLOW%^e"
      "%^RESET%^%^ORANGE%^p%^RESET%^l%^BOLD%^a%^YELLOW%^c%^RESET%^%^ORANGE%^e "
      "with a pile of %^RESET%^wood %^ORANGE%^stacked nearby, ready to be fed to "
      "the %^RED%^fl%^BOLD%^a%^RESET%^%^RED%^m%^ORANGE%^e%^RED%^s%^ORANGE%^. The "
      "bed is large enough for two but more humble than much of the inn. It is "
      "topped with a handmade %^CYAN%^s%^GREEN%^c%^YELLOW%^r%^RESET%^%^GREEN%^a"
      "%^CYAN%^p %^ORANGE%^q%^GREEN%^u%^YELLOW%^i%^RESET%^%^GREEN%^l%^CYAN%^t"
      "%^ORANGE%^ in homey shades of %^CYAN%^blue%^ORANGE%^, %^GREEN%^green%^ORANGE%^, "
      "and %^YELLOW%^yellow%^RESET%^%^ORANGE%^. The southwestern corner has "
      "been arranged as a small conversation nook with two %^RESET%^chairs %^ORANGE%^"
      "facing each other over a wooden chest atop a rustic rug. Each chair has a "
      "thin throw %^GREEN%^blanket %^ORANGE%^resting over its arm, and the "
      "scuffmarks on the chest top make it clear that it often serves as a footrest. "
      "Rather than the enchanted globes that brighten the rest of the inn, this "
      "room has been outfitted with wall sconces holding %^BOLD%^%^WHITE%^beeswax "
      "candles%^RESET%^%^ORANGE%^.%^RESET%^\n");
   set_smell("default","The air is filled with the fragrance of aging books and fireplace memories.");
   set_listen("default","The soft hum of the city rises from the streets.");
   set_items(([
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth.",
      ({"southern wall","south wall","bookshelves","shelves"}) : "No sign of the "
         "southern wall is visible as bookshelves stretch from floor to ceiling the "
         "entire length of the room. The bookshelves have been crafted from light "
         "pine and still retain a hint of their evergreen scent. They are piled high with books.",
      "books" : "This place is truly a book lover's dream. While not approaching the "
         "grand libraries, this small room contains one of the greatest private collections of books "
         "known to the realm. Citizens of the realm have donated the books, with "
         "the majority coming from the monks of the Cathedral. The monks are known "
         "to copy every book before they give it away, leaving some to speculate "
         "that the catacombs beneath the Cathedral must house a vast library. Here, "
         "you can peruse books on most any subject - histories and lineages, literature "
         "and poetry, religious tomes, and even the collected transcriptions of "
         "letters between various important individuals.",
      ({"fireplace","stone fireplace","wood"}) : "The fireplace is made from locally "
         "quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne%^RESET%^, just like the floor. The "
         "stones here have been made somewhat more regular and fitted together with "
         "a darker %^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout, though perhaps that is a remant from the fires that "
         "burn within. Wedges of wood wait in a neat pile by the fireplace.",
      ({"bed","quilt","scrap quilt"}) : "The bed looks warm and inviting, covered "
         "with a lovingly crafted quilt in a nine patch and rails pattern.",
      ({"chair","chairs"}) : "The chairs are coordinating rather than matching. "
         "One has a wooden frame with dark green leather cushions, while the other "
         "is an overstuffed plush armchair upholstered in floral fabric.",
      ({"blanket","blankets"}) : "The throw blankets are thin and hand knit from "
         "squishy green yarn. The design is rather simple, embellished only by "
         "cabling around the border.", 
      ({"sconce","wall sconce","sconces","wall sconces","candles","beeswax candles"}) : 
         "Thick beeswax candles are placed in wall sconces made of copper and glass "
         "throughout the room. They offer a naturally flickering light that provides "
         "a warm glow to the whole area.",
      ({"window","window seat","seat"}) : "The window in the southern wall is a wide "
         "arch that offers a gorgeous view of the ocean glinting in the distance. "
         "The bookshelves have been crafted around the window, curving without losing "
         "an inch of space. A thick cushion covered with green fabric stretches "
         "across the window seat and even climbs a short distance up each side, give a "
         "reader a great place to relax in comfort."
   ]));
   set_exits(([
      "west" : ROOMS"inn_stairs2",
   ]));
   set_door("plumeria door","/d/attaya/newseneca/rooms/inn_stairs2","west",0);
}

