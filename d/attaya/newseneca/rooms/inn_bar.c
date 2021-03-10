//inn_restaurant.c by ~Circe~ 1/4/16
#include <std.h>/
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_name("Lounge of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Lounge of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Lounge of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "%^RESET%^%^MAGENTA%^Four broad steps lead down into this sunken lounge with "
      "a completely different atmosphere than the rest of the inn. Gone are the "
      "cheerful %^BOLD%^%^BLUE%^g%^CYAN%^l%^WHITE%^o%^GREEN%^b%^BLUE%^e%^CYAN%^s "
      "%^RESET%^%^MAGENTA%^of light and fanciful %^CYAN%^beach paintings%^MAGENTA%^. "
      "%^RED%^Wine%^MAGENTA%^ and %^ORANGE%^ale casks%^MAGENTA%^ that have been "
      "sliced in half hang from the ceiling, each surrounding a single %^RESET%^sphere "
      "%^MAGENTA%^glowing dimly. The lights bathe the room in %^BOLD%^%^BLACK%^shadows"
      "%^RESET%^%^MAGENTA%^, offering some measure of anonymity to the southern "
      "side of the lounge. The entire south wall is covered with rough %^ORANGE%^"
      "wooden racks %^MAGENTA%^supporting %^RESET%^barrels %^MAGENTA%^and %^ORANGE%^"
      "casks %^MAGENTA%^of all manner of alcohol. Along the western wall is the "
      "%^BOLD%^%^BLACK%^wooden bar%^RESET%^%^MAGENTA%^, so dark it is nearly "
      "black - perfect for hiding beer stains. The furniture is simple but "
      "well made, crafted of %^ORANGE%^dark wood%^MAGENTA%^ and %^BOLD%^%^BLACK%^"
      "padded leather%^RESET%^%^MAGENTA%^. Filling most of the space are collections "
      "of small tables, armchairs, and couches. In the northern half of the room, they "
      "are all arranged facing the pentagonal %^CYAN%^stage %^MAGENTA%^set into "
      "the northwestern corner. A series of enchanted %^BOLD%^%^CYAN%^spotlights "
      "%^RESET%^%^MAGENTA%^are available, and performers can make good use of the "
      "%^BOLD%^%^BLACK%^velvet curtains%^RESET%^%^MAGENTA%^ that may be pulled to "
      "shield them from view. Almost out of sight, one corner of a %^ORANGE%^prop "
      "box %^MAGENTA%^peeks out from behind the curtain when it is fully open.%^RESET%^\n\n"
      "%^CYAN%^A sign on the bar presents a menu you could read.%^RESET%^\n");
   set_smell("default","The heady fragrance of wine and ale hangs in the air.");
   set_listen("default","Voices engaged in conversation reach your ears.");
   set_items(([
      ({"floor","stone","rug"}) : "While the floor of the lounge is made up of the "
         "same locally quarried stone as the rest of the inn, it has been covered "
         "here by a deep %^RED%^maroon rug %^RESET%^stretching nearly from wall to "
         "wall. Here and there, smaller throw rugs have been added, though you are "
         "not sure whether it is a decorative choice or simply to hide stains.",
      ({"light","lights","glowing sphere","spheres","ceiling"}) : "The ceiling is "
         "difficult to see thanks to the shadows cast by the unique lighting. Barrels "
         "have been slice in half to serve as shades for the dimly glowing magical "
         "spheres that dangle from the center of each one. The lights seem to "
         "respond to the mood of those sitting near them, dimming to cloak clandestine "
         "meetings ... or perhaps that's just a trick of mind.",
      ({"shadow","shadows"}) : "Despite the stationary lights, the shadows shift and move, "
         "almost as if by firelight.",
      ({"racks","rack","wooden racks","wooden rack","barrels","casks"}) : "A series of "
         "wooden racks along the southern wall store an impressive amount of alcohol. "
         "You see wine, ale, beer, and mead among smaller casks stored on shelves "
         "constructed between the larger racks.",
      ({"bar","wooden bar"}) : "Stained a rich brown that is almost black, the wooden "
         "bar is rather simple in design. The lines are clean and the top smooth, offering "
         "an efficient place for the bartender to serve patrons. A few padded barstools stand before it.",
      ({"furniture","chairs","armchairs","chair","armchair","table","tables","couch","couches"}) :
         "The arrangement of the furniture makes it easy for those who are interested "
         "to see the show on the stage, while those who are meeting for business "
         "dealings or camaraderie can find more secluded seating at the tables in "
         "the southern end of the bar. All of the furniture coordinates, with dark "
         "wood frames and leather cushions in maroon, hunter green, or black.",
      "stage" : "The small wooden stage in the northwestern corner could accommodate "
         "a few players, but certainly not a full production. It is often used by singers, "
         "musicians, and storytellers, as well as the occasional poet.",
      ({"spotlight","spotlights"}) : "The ingeniously crafted spotlights are cylinders "
         "of wrought iron with shades in the front that can be raised or lowered through "
         "a series of pulleys. They take a bit of practice to use, but a master can "
         "create any sort of mood using the bright enchanted light within.",
      ({"curtain","curtains","velvet curtain","velvet curtain"}) : "%^BOLD%^%^BLACK%^The "
         "thick black velvet curtains can be pulled to cover any portion of the stage, "
         "giving performers a chance to change scenes or prepare without an audience. "
         "A thick %^RESET%^silver rope %^BOLD%^%^BLACK%^is found at each end.%^RESET%^",
      ({"props","prop box"}) : "Filled almost to bursting, the large wooden chest holds "
         "props of all sorts from feather boas and masks to wooden swords and cheap "
         "ballgowns. While many performers bring their own supplies, those that do not "
         "can often find what they need here."
   ]));
   set_exits(([
      "east" : ROOMS"inn_main"
   ]));
}

void reset(){
   ::reset();
   if(!present("Ferran Ironbringer")){
      new(MON"inn_barkeep")->move(TO);
   }
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   object obj;
   int i;

   if(str == "menu") {
      obj = present("Ferran Ironbringer");
      if(!objectp(obj)) {
         tell_object(TP,"The barkeep must have stepped out for a moment.");
         return 1;
      }
      say(""+TPQCN+" reads over the menu.");
      message("Ninfo","The menu reads:\n",TP);
      message("Ninfo","%^RESET%^%^RED%^-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-%^RESET%^\n",TP);
      message("Ninfo","\n%^BOLD%^%^BLACK%^                         Alcohol%^RESET%^\n\n",TP);
      message("Ninfo","\t%^RESET%^%^RED%^Dwarven Ale%^RESET%^\t\t"+
         " "+(int)obj->get_price("dwarven ale")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Lager%^RESET%^\t\t\t"+
         " "+(int)obj->get_price("lager")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Attaya Ale%^RESET%^\t\t"+
         " "+(int)obj->get_price("attaya ale")+" silver pieces\n",TP);
      message("Ninfo","\t%^YELLOW%^Mead%^RESET%^\t\t\t"+
         " "+(int)obj->get_price("mead")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^RED%^Apple Cider%^RESET%^\t\t"+
         "  "+(int)obj->get_price("apple cider")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^WHITE%^Chardonnay%^RESET%^\t\t"+
         " "+(int)obj->get_price("chardonnay")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^RED%^Merlot%^RESET%^\t\t\t"+
         " "+(int)obj->get_price("merlot")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^MAGENTA%^Malbec%^RESET%^\t\t\t"+
         " "+(int)obj->get_price("malbec")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^MAGENTA%^Mulberry Wine%^RESET%^\t\t"+
         " "+(int)obj->get_price("mulberry wine")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^MAGENTA%^Pomegranate Wine%^RESET%^\t"+
         "  "+(int)obj->get_price("pomegranate wine")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^MAGENTA%^Currant Wine%^RESET%^\t\t"+
         " "+(int)obj->get_price("currant wine")+" silver pieces\n",TP);
      message("Ninfo","\n%^BOLD%^%^BLACK%^                   Non-Alcoholic Drinks%^RESET%^\n\n",TP);
      message("Ninfo","\t%^RESET%^%^CYAN%^Water%^RESET%^\t\t\t"+
         "  "+(int)obj->get_price("water")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^RED%^Raspberry %^YELLOW%^Lemonade%^RESET%^\t"+
         " "+(int)obj->get_price("raspberry lemonade")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Coffee%^RESET%^\t\t\t"+
         " "+(int)obj->get_price("coffee")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Cappuccino%^RESET%^\t\t"+
         " "+(int)obj->get_price("cappuccino")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^BLACK%^Espresso%^RESET%^\t\t"+
         " "+(int)obj->get_price("espresso")+" silver pieces\n\n",TP);
      message("Ninfo","%^RESET%^%^RED%^-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-%^RESET%^\n",TP);
      message("Ninfo","<buy dish_name> gets you the food.\n",TP);
      return 1;
   }
}
