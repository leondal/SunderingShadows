//inn_restaurant.c by ~Circe~ 1/2/16
#include <std.h>/
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Bakery of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Bakery of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Bakery of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "%^RESET%^%^ORANGE%^Nestled behind the %^RESET%^stairway %^ORANGE%^leading up "
      "to the guestrooms, this quaint bakery caters to visitors and residents of %^YELLOW%^"
      "Seneca %^RESET%^%^ORANGE%^alike. A large %^BOLD%^%^WHITE%^co%^MAGENTA%^q%^WHITE%^ui"
      "%^BLACK%^n%^WHITE%^a co%^BLACK%^u%^WHITE%^nt%^MAGENTA%^e%^WHITE%^r%^RESET%^%^ORANGE%^ "
      "takes up much of the room. Its %^BOLD%^%^WHITE%^marble top %^RESET%^%^ORANGE%^is "
      "filled with displays of the delicious %^YELLOW%^pastries %^RESET%^%^ORANGE%^"
      "available for customers to buy. A %^RESET%^door %^ORANGE%^behind the counter "
      "leads into what must be the kitchen where these fragrant treats are made, and "
      "the rest of the small space is taken up by the few %^BOLD%^%^BLACK%^bistro tables"
      "%^RESET%^%^ORANGE%^ and chairs that are scattered around. The bakery is always "
      "crowded, though it seems that most everyone takes their food elsewhere, often "
      "to the bar. In contrast to the %^BOLD%^%^BLUE%^ocean %^RESET%^%^ORANGE%^theme "
      "that dominates the rest of the inn, the room is decorated with fluffy %^BOLD%^%^WHITE%^"
      "sheep %^RESET%^%^ORANGE%^wearing %^RESET%^chef's hats %^ORANGE%^and holding "+
      "%^YELLOW%^rolling pins%^RESET%^%^ORANGE%^. An artist has handpainted the "
      "images on the walls, creating fanciful scenes. Near the entrance is a comical "
      "sculpture of a %^BOLD%^%^BLACK%^black sheep%^RESET%^%^ORANGE%^ wearing an "
      "%^CYAN%^apron %^ORANGE%^and bearing a sign that reads, %^MAGENTA%^'%^BOLD%^Tropical "
      "Treats%^RESET%^%^MAGENTA%^'%^ORANGE%^. The %^CYAN%^menu %^ORANGE%^has been painted "
      "on the wall above the counter, and to its left is an incongruous tattered %^GREEN%^banner "
      "%^ORANGE%^that does not match the rest of the decor.%^RESET%^\n");
   set_smell("default","The air is filled with enticing aromas - cinnamon, apple, and even cheese.");
   set_listen("default","Voices engaged in conversation reach your ears.");
   set_items(([
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth.",
      ({"globe","globes","glass globe","glass globes"}) : "The "+
         "globes are made of blown glass in shades of %^BOLD%^%^BLUE%^"+
         "blue %^RESET%^and %^BOLD%^%^GREEN%^green%^RESET%^, "+
         "reminiscent of the %^CYAN%^sea%^RESET%^ while the softly "+
         "glowing %^BOLD%^white light %^RESET%^brings to mind "+
         "images of whitecaps.  They do not have any sort of flame "+
         "within, but seem to have been enchanted to provide "+
         "illumination.",
      ({"counter","coquina counter"}) : "The counter is made of the same material "
         "as the walls surrounding Seneca. The soft limestone is made from pieces "
         "of broken shells, given it a muted colorful look and unique texture.",
      ({"marble","marble top","countertop"}) : "The smooth white marble top is always "
         "cool to the touch and supports trays and small towers displaying the treats - "
         "savory and sweet - available for purchase.",
      ({"banner","tattered banner","daggerdale banner","Daggerdale banner"}) : "%^RESET%^%^GREEN%^"
         "The %^BOLD%^green banner%^RESET%^%^GREEN%^ is in tatters but hangs proudly "
         "on the wall alonside the menu. The banner shows an image of a %^YELLOW%^Roc"
         "%^RESET%^%^GREEN%^ in flight clutching two pairs of crisscrossed %^RESET%^"
         "daggers%^GREEN%^ in either talon, the symbol for the fallen town of %^CYAN%^"
         "Daggerdale%^GREEN%^. Kairi's family once owned the %^ORANGE%^bakery %^GREEN%^"
         "there, and their recipes have been passed down through the generations. She "
         "still uses many of them today.%^RESET%^",
      ({"display","displays","pastry","pastries"}) : "Silver trays line the countertop "
         "and are stacked on slender rods, offering a tantalizing view of the pastries "
         "for sell. You see a mix of savory and sweet items, all golden brown and many "
         "glistening with sugar.",
      ({"door","kitchen"}) : "The wooden door in the southern wall is set on special "
         "hinges that allow it to swing back and forth, making it easier for the bakers "
         "to carry their confections into the showroom. Although Kairi usually mans the "
         "front counter, she has several bakers helping her day and night.",
      ({"table","tables","bistro tables","chair","chairs"}) : "Small wrought iron tables "
         "and chairs line the sides of the bakery. They do not seem overly comfortable, but "
         "they provide a place for a quick meal or to wait for larger orders.",
      ({"sheep","paintings","images"}) : "The sheep have been anthropomorphized to a "
         "certain degree, granting them smiles and letting them stand upright. They each "
         "wear a little chef's hat, and some hold rolling pins or piping hot pastries.",
      ({"sculpture","black sheep"}) : "The black sheep looks almost like one of the painted "
         "sheep come to life. His smile is infectious, and the little blue apron he wears "
         "is decorated with painted tropical flowers. The sign has been painted to reveal "
         "the name of the bakery - Tropical Treats.",
      "menu" : "The menu is painted over the counter. You could read it to find out what "
         "pastries are for sale today."
   ]));
   set_exits(([
      "north" : ROOMS"inn_main"
   ]));
}

void reset(){
   ::reset();
   if(!present("Kairi Kevynson")){
      new(MON"inn_baker")->move(TO);
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
      obj = present("Kairi Kevynson");
      if(!objectp(obj)) {
         tell_object(TP,"The baker must have stepped out for a moment.");
         return 1;
      }
      say(""+TPQCN+" reads over the menu on the tile.");
      message("Ninfo","The menu reads:\n",TP);
      message("Ninfo","%^BOLD%^%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
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
      message("Ninfo","%^BOLD%^%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
      message("Ninfo","<buy dish_name> gets you the food.\n",TP);
      return 1;
   }
}
