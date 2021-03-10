//inn_balcony.c - Coded by ~Circe~ 12/31/15
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Balcony of the Tropical Breeze Inn, Seneca");
   set_short("Balcony of the Tropical Breeze Inn, Seneca");
   set_indoors(0);
   set_property("light",3);
   set_long("%^BOLD%^%^MAGENTA%^Balcony of the Tropical Breeze Inn, Seneca%^RESET%^\n"
      "The balcony provides a breathtaking view of the %^CYAN%^skyline %^RESET%^of %^BOLD%^"
      "%^MAGENTA%^Seneca %^RESET%^with the %^BOLD%^%^BLUE%^ocean %^RESET%^stretching to "
      "the horizon. Rather than iron or stone, the railing is made from living "
      "%^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^a%^BOLD%^%^WHITE%^s%^RESET%^m%^BOLD%^%^GREEN%^i"
      "%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e %^RESET%^s%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^r"
      "%^BOLD%^%^WHITE%^u%^RESET%^b%^GREEN%^s %^RESET%^growing from each corner of the "
      "balcony. Their thin %^ORANGE%^trunks %^RESET%^have been enchanted to twist and "
      "grow, forming a lattice-work roof of %^GREEN%^vi%^BOLD%^b%^RESET%^%^GREEN%^ra%^BOLD%^n"
      "%^RESET%^%^GREEN%^t le%^BOLD%^a%^RESET%^%^GREEN%^ves %^RESET%^and delicate %^BOLD%^j"
      "%^RESET%^a%^BOLD%^s%^RESET%^m%^BOLD%^i%^RESET%^n%^BOLD%^e %^RESET%^b%^BOLD%^l%^RESET%^"
      "o%^BOLD%^s%^RESET%^s%^BOLD%^o%^RESET%^m%^BOLD%^s%^RESET%^. Dangling here and there "
      "from the %^ORANGE%^branches%^RESET%^ are slender %^CYAN%^w%^RESET%^i%^CYAN%^n%^BOLD%^d"
      "%^RESET%^%^CYAN%^c%^RESET%^h%^CYAN%^i%^BOLD%^m%^RESET%^%^CYAN%^es %^RESET%^and "
      "%^ORANGE%^cop%^YELLOW%^p%^RESET%^%^ORANGE%^er l%^YELLOW%^a%^RESET%^%^ORANGE%^nte"
      "%^YELLOW%^r%^RESET%^%^ORANGE%^ns %^RESET%^filled with %^BOLD%^stones %^RESET%^that "
      "glow with a warm %^ORANGE%^li%^YELLOW%^g%^RESET%^%^ORANGE%^ht%^RESET%^. The unique "
      "construction shields occupants from the heat of the sun and provides a measure of privacy. "
      "To the western side of the %^CYAN%^glass doors %^RESET%^stands an enormous "
      "%^ORANGE%^c%^YELLOW%^o%^RESET%^%^ORANGE%^p%^RESET%^p%^ORANGE%^er m%^YELLOW%^o%^RESET%^"
      "%^ORANGE%^s%^RESET%^a%^ORANGE%^ic t%^YELLOW%^u%^RESET%^%^ORANGE%^b %^RESET%^filled with "
      "%^CYAN%^st%^BOLD%^e%^RESET%^%^CYAN%^am%^RESET%^i%^CYAN%^ng w%^BOLD%^a%^RESET%^%^CYAN%^ter%^RESET%^. "
      "%^BOLD%^St%^RESET%^o%^BOLD%^ne st%^RESET%^e%^BOLD%^ps %^RESET%^ascend to the top of the "
      "tub, offering easy access, while a %^BOLD%^shelf %^RESET%^near the wall of the "
      "building provides an assortment of fragrant %^BOLD%^o%^YELLOW%^i%^RESET%^l%^BOLD%^s "
      "%^RESET%^and %^BOLD%^s%^CYAN%^o%^WHITE%^a%^YELLOW%^p%^WHITE%^s %^RESET%^alongside "
      "soft %^BOLD%^cloths %^RESET%^and %^CYAN%^towels%^RESET%^ for guests to use. The eastern half of the "
      "balcony houses a low wrought iron %^BOLD%^%^BLACK%^table%^RESET%^ with a %^BOLD%^"
      "hurricane vase%^RESET%^ centerpiece. A %^BOLD%^tile %^RESET%^with writing rests "
      "on top of the table, which is flanked on either side by an unusual %^BOLD%^%^BLACK%^"
      "low chair %^RESET%^fitted with a %^CYAN%^light blue cushion%^RESET%^.\n");
   set_smell("default","The fragrance of jasmine fills the air.");
   set_listen("default","The silence is broken by a gentle breeze and tinkling of windchimes.");
   set_items(([
      ({"skyline","ocean"}) : "From here, you can see the tops of the buildings all over "
         "Seneca, with only the mage and psion towers rising higher. No matter the time of "
         "day, people can be seen roaming the streets below. Toward the horizon, the ocean "
         "glitters, reflecting the light of the sun or stars.",
      ({"railing","shrubs","jasmine shrubs","shrub","roof"}) : "%^GREEN%^The construction "
         "of the railing and roof are most unusual, and it seems clear that magic - or a "
         "very talented gardener - was involved. The thin %^ORANGE%^trunks %^GREEN%^of the "
         "%^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^a%^BOLD%^%^WHITE%^s%^RESET%^m%^BOLD%^%^GREEN%^i"
         "%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e %^RESET%^s%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^r"
         "%^BOLD%^%^WHITE%^u%^RESET%^b%^GREEN%^s twist and wind around each other, forming "
         "impenetrable barriers and sturdy supports for the various windchimes and lanterns "
         "hanging among the delicate %^BOLD%^%^WHITE%^j%^RESET%^a%^BOLD%^s%^RESET%^m%^BOLD%^i"
         "%^RESET%^n%^BOLD%^e %^RESET%^b%^BOLD%^l%^RESET%^o%^BOLD%^s%^RESET%^s%^BOLD%^o%^RESET%^"
         "m%^BOLD%^s%^RESET%^%^GREEN%^. The railing rises about four feet all around the balcony "
         "with offshoots rising overhead to form a roof.%^RESET%^",
      ({"leaves","blossoms","jasmine blossoms","flowers","jasmine blossom"}) : "%^RESET%^%^GREEN%^"
         "Delicate %^BOLD%^%^WHITE%^j%^RESET%^a%^BOLD%^s%^RESET%^m%^BOLD%^i%^RESET%^n%^BOLD%^e "
         "%^RESET%^b%^BOLD%^l%^RESET%^o%^BOLD%^s%^RESET%^s%^BOLD%^o%^RESET%^m%^BOLD%^s%^RESET%^"
         "%^GREEN%^ are sprinkled among the vibrant %^BOLD%^leaves%^RESET%^%^GREEN%^. Each "
         "blossom has six %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^BOLD%^r"
         "%^RESET%^y %^BOLD%^w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e petals%^RESET%^%^GREEN%^ "
         "around a dainty %^YELLOW%^yellow center%^RESET%^%^GREEN%^.%^RESET%^",
      ({"chime","chimes","windchime","windchimes","wind chimes"}) : "Each windchime is "
         "made from %^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r %^RESET%^or "
         "%^ORANGE%^co%^YELLOW%^p%^RESET%^%^ORANGE%^per%^RESET%^, often set with %^CYAN%^b"
         "%^RESET%^e%^ORANGE%^a%^GREEN%^d%^MAGENTA%^s%^RESET%^ of various colors. They "
         "tinkle in the %^CYAN%^wind%^RESET%^, lending a light music to the space.",
      ({"lanterns","copper lanterns","copper lantern"}) : "%^ORANGE%^Scattered among the "
         "leaves are co%^YELLOW%^p%^RESET%^%^ORANGE%^per la%^YELLOW%^n%^RESET%^%^ORANGE%^te"
         "%^YELLOW%^r%^RESET%^%^ORANGE%^ns with decorative shapes cut into their sides, "
         "revealing the smooth %^RESET%^white stones%^ORANGE%^ inside. The stones have "
         "been enchanted to emit a warm %^YELLOW%^light%^RESET%^%^ORANGE%^.%^RESET%^",
      ({"tub","copper tub","mosaic tub","copper mosaic tub"}) : "The %^ORANGE%^c%^YELLOW%^"
         "o%^RESET%^%^ORANGE%^p%^RESET%^p%^ORANGE%^er m%^YELLOW%^o%^RESET%^%^ORANGE%^s"
         "%^RESET%^a%^ORANGE%^ic t%^YELLOW%^u%^RESET%^%^ORANGE%^b %^RESET%^is a wide, "
         "welcoming pool that would easily fit several humans who wish to relax. The "
         "smooth %^ORANGE%^co%^YELLOW%^p%^RESET%^%^ORANGE%^per %^RESET%^surface is "
         "rounded for comfort, while the decorative sides feature beautiful %^ORANGE%^"
         "m%^RESET%^o%^YELLOW%^s%^RESET%^%^ORANGE%^a%^RESET%^i%^ORANGE%^c%^YELLOW%^s"
         "%^RESET%^ from pieces of semi-precious gemstones fitted together. The water "
         "is kept steaming hot through enchantments placed on the tub itself.",
      ({"step","steps","stone steps"}) : "A simple set of four steps leads up to "
         "the tub. Like the floor of the inn, each step is made up of "
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"
         "fashioned into irregularly shaped tiles.  A faintly "
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"
         "%^RESET%^n grout fits the tiles together, making the "
         "steps smooth.",
      ({"shelf","oil","oils","soap","soaps"}) : "The shelf is made of wood and set within "
         "the stucco exterior of the inn. It supports several baskets filled with small "
         "cakes of soap in fanciful shapes like shells, flowers, and even birds. "
         "Standing between the baskets are small jars of oils and gels that can be used "
         "for massages or even to make bubbles within the tub. Each has its own fragrance, "
         "from sweet rose to spicy ginger.",
      ({"cloths","towel","towels"}) : "Small square cloths made of cotton are provided for "
         "guests to use when washing themselves, though most seem to enjoy the tub simply "
         "for relaxing. A stack of fluffy towels is available as well, each colored a "
         "different shade of blue.",
      "table" : "%^BOLD%^%^BLACK%^The low table is "
         "decorative and shaped from wrought iron. A smooth sheet of glass has been placed "
         "over the top, providing the perfect place for guests to leave their drinks. In "
         "the center of the table is a large hurricane vase filled with white stones. Sitting just "
         "in front of the lantern is a small %^RESET%^white tile%^BOLD%^%^BLACK%^ covered "
         "with writing.%^RESET%^",
      ({"vase","hurricane vase","centerpiece"}) : "The hurricane vase is filled with smooth "
         "white stones that have been marked with the names of various foods and drinks. "
         "Upon closer inspection, you realize that the vase is resting on a small wrought "
         "iron stand with an opening just the size of the stones.",
      ({"tile","menu"}) : "The small white tile is covered with smooth script detailing "
         "dishes that can be ordered from the restaurant below. To see what's available, "
         "you can read the menu. Then, when you are ready, you simply order what you want "
         "by sending the correct stone along with coins to cover the cost through the hole "
         "beneath the vase.",
      ({"chair","chairs","low chair","low chairs"}) : "The chairs are constructed from "
         "%^BOLD%^%^BLACK%^wrought iron %^RESET%^like the table. Unlike most chairs, "
         "these are low to the ground and stretch out far, allowing a person to stretch "
         "their legs before them. The back can be adjusted at different angles, and a "
         "%^CYAN%^light blue cushion%^RESET%^ covers both halves of the chair for comfort."
   ]));
   set_exits(([
      "north" : ROOMS"inn_suite"
   ]));
   set_door("glass doors","/d/attaya/newseneca/rooms/inn_suite","north",0);
   set_door_description("glass doors","%^RESET%^%^ORANGE%^A simple wooden frame polished "
      "to a glossy sheen supports the double doors that open onto the balcony. The "
      "%^CYAN%^glass %^ORANGE%^is nearly flawless, providing a clear view of the city sky.%^RESET%^");
//   new(MON"baker_tile")->move(TO);
}

void reset(){
   ::reset();
   if(!present("baker_tile111")){
      new(MON"baker_tile")->move(TO);
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
      obj = present("baker_tile111");
      if(!objectp(obj)) {
         tell_object(TP,"The tile seems to be missing!");
         return 1;
      }
      say(""+TPQCN+" reads over the menu on the tile.");
      message("Ninfo","The menu reads:\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n",TP);
      message("Ninfo","\n%^RESET%^%^MAGENTA%^                       Sweet Treats%^RESET%^\n\n",TP);
      message("Ninfo","\t%^BOLD%^%^MAGENTA%^Raspberry Tarts%^RESET%^ \t"+
         " "+(int)obj->get_price("raspberry tarts")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Glazed Beignets%^RESET%^ \t"+
         "  "+(int)obj->get_price("glazed beignets")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^BLACK%^Chocolate Eclair%^RESET%^ \t"+
         "  "+(int)obj->get_price("chocolate eclair")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^WHITE%^Cream Puffs%^RESET%^ \t\t"+
         "  "+(int)obj->get_price("cream puffs")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^RED%^Fruit Tart %^RESET%^\t\t"+
         "  "+(int)obj->get_price("fruit tart")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Cinnamon Pinwheels%^RESET%^ \t"+
         "  "+(int)obj->get_price("cinnamon pinwheels")+" silver pieces\n",TP);
      message("Ninfo","\t%^YELLOW%^Cookie Platter%^RESET%^ \t\t"+
         "  "+(int)obj->get_price("cookie platter")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^RED%^Apple Turnover %^RESET%^\t\t"+
         "  "+(int)obj->get_price("apple turnover")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^GREEN%^Attaya Lime Pie %^RESET%^\t"+
         "  "+(int)obj->get_price("attaya lime pie")+" silver pieces\n",TP);
      message("Ninfo","\n%^RESET%^%^MAGENTA%^                       Savory Snacks%^RESET%^\n\n",TP);
      message("Ninfo","\t%^YELLOW%^Buttered Bread%^RESET%^ \t\t"+
         " "+(int)obj->get_price("buttered bread")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^RED%^Tomato Bruschetta%^RESET%^ \t"+
         " "+(int)obj->get_price("tomato bruschetta")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^GREEN%^Cucumber Sandwiches %^RESET%^\t"+
         " "+(int)obj->get_price("cucumber sandwiches")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Croquetas %^RESET%^\t\t"+
         " "+(int)obj->get_price("croquetas")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^WHITE%^Papas Rellenas%^RESET%^ \t\t"+
         " "+(int)obj->get_price("papas rellenas")+" silver pieces\n",TP);
      message("Ninfo","\t%^YELLOW%^Seneca Turnover%^RESET%^ \t"+
         " "+(int)obj->get_price("seneca turnover")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^WHITE%^Fried Plantains%^RESET%^ \t"+
         "  "+(int)obj->get_price("fried plantains")+" silver pieces\n",TP);
      message("Ninfo","\n%^RESET%^%^MAGENTA%^                          Drinks%^RESET%^\n\n",TP);
      message("Ninfo","\t%^BOLD%^%^BLACK%^Coffee%^RESET%^ \t\t\t"+
         " "+(int)obj->get_price("coffee")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Hot Chocolate%^RESET%^ \t\t"+
         "  "+(int)obj->get_price("hot chocolate")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^WHITE%^Milk %^RESET%^\t\t\t"+
         "  "+(int)obj->get_price("milk")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^ORANGE%^Orange Juice %^RESET%^\t\t"+
         " "+(int)obj->get_price("orange juice")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^CYAN%^Water %^RESET%^\t\t\t"+
         "  "+(int)obj->get_price("water")+" silver pieces\n",TP);
      message("Ninfo","\t%^BOLD%^%^WHITE%^White Wine %^RESET%^\t\t"+
         " "+(int)obj->get_price("white wine")+" silver pieces\n",TP);
      message("Ninfo","\t%^RESET%^%^RED%^Red Wine %^RESET%^\t\t"+
         " "+(int)obj->get_price("red wine")+" silver pieces\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n",TP);
      message("Ninfo","<buy dish_name> gets you the food.\n",TP);
      return 1;
   }
}