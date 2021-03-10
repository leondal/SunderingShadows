//Free-standing restaurant for new Seneca, 
//featuring seafood ~Circe~ 4/13/08

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",3);
    set_property("indoors",1);
    set_name("El Pescado, Seneca");
    set_short("El Pescado, Seneca");
    set_long("%^BOLD%^%^BLUE%^El Pescado, Seneca%^RESET%^\n"+
       "Perched atop the %^BOLD%^%^BLACK%^rocky cliffs %^RESET%^"+
       "overlooking the %^BOLD%^%^BLUE%^sea%^RESET%^ below, pure "+
       "%^BOLD%^ivory stucco walls%^RESET%^ set with large, "+
       "glassless arched %^CYAN%^windows%^RESET%^ enclose this "+
       "cozy restaurant.  To give privacy, each of the %^ORANGE%^"+
       "wooden tables%^RESET%^ is tastefully separated by tall "+
       "%^BOLD%^%^BLACK%^wrought iron screens%^RESET%^ set with "+
       "countless small %^BOLD%^%^RED%^tealight candles %^RESET%^"+
       "in %^BOLD%^f%^RESET%^r%^BOLD%^o%^RESET%^s%^BOLD%^t%^RESET%^"+
       "e%^BOLD%^d %^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e"+
       "%^BOLD%^ c%^RESET%^u%^BOLD%^p%^RESET%^s.  A single tall "+
       "%^BOLD%^%^RED%^pillar candle%^RESET%^ set within a %^BOLD%^"+
       "s%^RESET%^%^ORANGE%^e%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^"+
       "h%^ORANGE%^e%^BOLD%^l%^RESET%^l-filled hurricane shade "+
       "is centered atop the crisp %^BOLD%^linen tablecloth %^RESET%^"+
       "lining each table.  Tiny %^CYAN%^seascape oil paintings "+
       "%^RESET%^dot the walls amid elegant %^BOLD%^%^BLACK%^"+
       "wrought iron scrollwork sconces%^RESET%^ that hold "+
       "sleek %^BOLD%^beeswax candles%^RESET%^ which cast "+
       "their soft %^YELLOW%^glow %^RESET%^upon the room.  Overhead, "+
       "the ceiling has been fitted with %^BOLD%^l%^RESET%^a%^BOLD%^t"+
       "%^RESET%^t%^BOLD%^i%^RESET%^c%^BOLD%^e%^RESET%^, and "+
       "fragrant %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^a"+
       "%^BOLD%^%^WHITE%^s%^RESET%^m%^BOLD%^%^GREEN%^"+
       "i%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e %^RESET%^v%^BOLD%^"+
       "%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e%^RESET%^s "+
       "have been trained upon it, covering the white lattice "+
       "nearly completely.  Known as pink jasmine, the vines "+
       "sprout flawless %^BOLD%^snowy white blooms %^RESET%^"+
       "with five petals, but each of the small buds awaiting "+
       "its chance to blossom is colored a beautiful %^BOLD%^"+
       "%^MAGENTA%^pink%^RESET%^.  A large half-circle "+
       "%^BOLD%^shelf %^RESET%^crafted from matching stucco "+
       "is placed into the wall not far from the door.  There, "+
       "an enchanted %^YELLOW%^golden harp %^RESET%^plays gentle "+
       "%^CYAN%^melodies %^RESET%^of its own accord, completing "+
       "the serene atmosphere of this oceanview restaurant.\n\n"+
       "%^RESET%^There is a menu here you can read.\n");
   set_smell("default","The rejuvenating fragrance of the ocean "+
       "mingles with the aroma of spices and the sweet scent of jasmine.");
   set_listen("default","The crashing of the surf below provides "+
       "a pleasant backdrop to the music of the harp.");
   set_items(([
      "menu" : "You may read it if you like.",
      ({"sea","ocean"}) : "%^BOLD%^%^BLUE%^Through the open "+
         "windows, you can see the crashing of the %^WHITE%^s"+
         "%^CYAN%^ur%^WHITE%^f %^BLUE%^on the %^YELLOW%^beach "+
         "%^BLUE%^far below the cliffs.%^RESET%^",
      ({"wall","walls"}) : "The walls are well-made ivory stucco "+
         "that provides a soft backdrop to the decorations of "+
         "the restaurant.",
      ({"window","windows"}) : "Each of the windows is tall and "+
         "arched, left %^CYAN%^glassless %^RESET%^to provide an "+
         "uninterrupted view of the %^BOLD%^%^BLUE%^sea%^RESET%^ "+
         "below as well as allow in the refreshing breeze.  "+
         "Thick %^BOLD%^%^BLACK%^black shutters %^RESET%^are fitted "+
         "to each window, allowing for protection in the event of "+
         "a storm.",
      ({"table","tables","wooden tables"}) : "The tables are an "+
         "assortment of shapes but each is made of the same "+
         "%^ORANGE%^warm wood %^RESET%^varnished to a high "+
         "shine and covered with a crisp linen tablecloth.",
      ({"screen","screens","iron screens","wrought iron screens"}) :
         "The screens are made of thin %^BOLD%^%^BLACK%^wrought "+
         "iron %^RESET%^and thickly woven into scrollwork to "+
         "provide elegant separation between the tables.  "+
         "Each screen is dotted with %^BOLD%^f%^RESET%^r%^BOLD%^o%^RESET%^s%^BOLD%^t%^RESET%^"+
         "e%^BOLD%^d %^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e"+
         "%^BOLD%^ c%^RESET%^u%^BOLD%^p%^RESET%^s that hold "+
         "tiny %^BOLD%^%^RED%^red tealight candles%^RESET%^.",
      "candles" : "There are several different types of candles "+
         "around the room.  Small %^BOLD%^%^RED%^red tealights "+
         "%^RESET%^grace the screens while thicker %^BOLD%^%^RED%^"+
         "scarlet pillars %^RESET%^top the tables.  Finally, "+
         "pristine %^BOLD%^beeswax candles %^RESET%^placed in "+
         "wall sconces add to the illumination.",
      ({"tealight candle","tealight candles","cups","frosted white cups"}) :
         "Decorating the screens are countless small "+
         "%^BOLD%^f%^RESET%^r%^BOLD%^o%^RESET%^s%^BOLD%^t%^RESET%^"+
         "e%^BOLD%^d %^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e"+
         "%^BOLD%^ c%^RESET%^u%^BOLD%^p%^RESET%^s that hold %^BOLD%^"+
         "%^RED%^scarlet tealight candles%^RESET%^, their flickering "+
         "flames dancing and giving the illusion of so many faeries "+
         "bearing tiny lanterns to light the way.",
      ({"pillar candle","shade","hurricane shade"}) : "Centered "+
         "on each of the tables is a %^CYAN%^hurricane shade "+
         "%^RESET%^filled with %^BOLD%^s%^RESET%^%^ORANGE%^e"+
         "%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^h%^ORANGE%^e"+
         "%^BOLD%^l%^RESET%^l%^YELLOW%^s%^RESET%^ and surrounding "+
         "a thick %^BOLD%^%^RED%^ruby pillar candle%^RESET%^.  "+
         "The hurricane lamps seem to be mostly for decoration "+
         "and atmosphere, as most of the illumination comes "+
         "from the candles in the wall sconces.",
      ({"tablecloth","linen tablecloth"}) : "%^BOLD%^A crisp linen "+
         "tablecloth is spread upon each table, positioned "+
         "diagonally to allow some of the %^RESET%^%^ORANGE%^"+
         "wood %^BOLD%^%^WHITE%^to show.  The flawless white "+
         "cloth suggests some sort of magical cleaning is used "+
         "to keep them in such fantastic shape.%^RESET%^",
      ({"paintings","oil paintings","seascape oil paintings","painting"}) :
         "The oil paintings are different sizes and spread around "+
         "the walls of the restaurant.  Each one shows a %^CYAN%^"+
         "seascape%^RESET%^, some simply of the %^BOLD%^%^BLUE%^"+
         "ocean itself %^RESET%^while others are complete with "+
         "%^GREEN%^sea oats %^RESET%^and %^ORANGE%^sand dunes"+
         "%^RESET%^.  A few of the more fanciful ones depict "+
         "creatures such as %^BOLD%^mermaids %^RESET%^and "+
         "%^BOLD%^%^BLACK%^dolphins%^RESET%^.",
      ({"sconces","sconce","iron sconces","scrollwork sconces","beeswax candles"}) :
         "Fairly simple in design, the %^BOLD%^%^BLACK%^sconces "+
         "%^RESET%^are an eclectic collection of scrollwork, "+
         "bars, and other patterns, with no two sconces matching "+
         "exactly.  Each is fitted with a tall %^BOLD%^beeswax "+
         "candle %^RESET%^that casts a soft glow over the room.",
      ({"lattice","vines","jasmine vines","pink jasmine"}) :
         "Panels of lattice hang from the ceiling and are draped "+
         "thickly with climbing %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^a"+
         "%^BOLD%^%^WHITE%^s%^RESET%^m%^BOLD%^%^GREEN%^"+
         "i%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e %^RESET%^v%^BOLD%^"+
         "%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^e%^RESET%^s "+
         "that blossom with delicate %^BOLD%^snowy blooms%^RESET%^.  "+
         "Their light fragrance adds a sweet, heady aroma to the "+
         "air, and the small %^BOLD%^%^MAGENTA%^pink buds %^RESET%^"+
         "add to the romance.",
      ({"blossoms","blossom","blooms","bloom"}) : "Each of the "+
         "jasmine blossoms is star-shaped, featuring five slender "+
         "petals gathered around a center.",
      ({"shelf","harp","golden harp"}) : "%^YELLOW%^Perched upon "+
         "a shelf near the door is a beautiful golden harp.  Much "+
         "like a piece of a fairy tale, the harp has an elegant "+
         "design that glitters in the light, and it has been "+
         "bewitched to play gentle melodies of its own accord.  "+
         "The harp rests upon a simple half-circle shelf finished "+
         "in the same stucco as the walls.%^RESET%^"
   ]));
   set_exits(([
      "west" : ROOMS"rockypath3"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/rockypath3","west",0,0);
   set_door_description("door","%^ORANGE%^The thick door of the "+
      "restaurant has %^BOLD%^%^BLACK%^iron-bound%^RESET%^%^ORANGE%^ "+
      "planks and rises to an arch at the top.  A large glassless "+
      "window set near the top has a matching %^BOLD%^%^BLACK%^iron "+
      "grate%^RESET%^%^ORANGE%^.%^RESET%^");
}


void reset() {
  ::reset();
   if(!present("server"))
      find_object_or_load("/d/attaya/newseneca/mon/restaurant_server2")->move(TO);
}


void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    object ob;
    int i;

  if(str!="menu")
    return 0;
    ob = present("server", TO); 
    if (!objectp(ob)){  
      write("The restaurant has no staff present to show you the menu!\n");
      return 1;
    }
    write("The following great foods and drinks are served here at the restaurant.");
    write("%^BOLD%^%^RED%^@%^GREEN%^~~~~~~~~~~~~~~~~~~~~~~~%^RED%^@ %^WHITE%^Entrees%^RED%^ @%^GREEN%^~~~~~~~~~~~~~~~~~~~~~~~%^RED%^@%^RESET%^\n");
    write("\t%^BOLD%^%^MAGENTA%^Shrimp Skewers%^RESET%^                      "+
	      ""+(int)ob->get_price("shrimp skewers") + " gold");
    write("\t%^GREEN%^Salmon Salad%^RESET%^                        "+
	      ""+(int)ob->get_price("salmon salad") + " gold");
    write("\t%^BOLD%^Stuffed Mussels%^RESET%^                     "+
	      ""+(int)ob->get_price("stuffed mussels") + " gold");
    write("\t%^BOLD%^%^MAGENTA%^Garlic Prawns%^RESET%^                       "+
	      ""+(int)ob->get_price("garlic prawns") + " gold");
    write("\t%^RED%^Chorizo and Prawn Soup%^RESET%^              "+
	      ""+(int)ob->get_price("chorizo and prawn soup") + " gold");
    write("\t%^YELLOW%^Suquet%^RESET%^                              "+
	      ""+(int)ob->get_price("suquet") + " gold");
    write("\t%^BOLD%^Grouper a la Mallorquina%^RESET%^            "+
	      ""+(int)ob->get_price("grouper a la mallorquina") + " gold");
    write("\t%^BOLD%^%^RED%^Caldereta de Langosta%^RESET%^               "+
	      ""+(int)ob->get_price("caldereta de langosta") + " gold");
    write("\t%^YELLOW%^Spiced Clams%^RESET%^                        "+
	      ""+(int)ob->get_price("spiced clams") + " gold");
    write("\t%^RED%^Filet a la Mussels Vinaigrette%^RESET%^      "+
	      ""+(int)ob->get_price("filet a la mussels vinaigrette") + " gold");
    write("\t%^MAGENTA%^Pulpo a Feira%^RESET%^                       "+
	      ""+(int)ob->get_price("pulpo a feira") + " gold");
    write("\t%^ORANGE%^Tuna Empanadillas%^RESET%^                   "+
	      ""+(int)ob->get_price("tuna empanadillas") + " gold");
    write("\t%^YELLOW%^Herb-crusted Tilapia%^RESET%^                "+
	      ""+(int)ob->get_price("herb-crusted tilapia") + " gold");
    write("\t%^BOLD%^Lasagne Blanco%^RESET%^                      "+
	      ""+(int)ob->get_price("lasagne blanco") + " gold\n");
    write("%^BOLD%^%^RED%^@%^GREEN%^~~~~~~~~~~~~~~~~~~~~~~~%^RED%^@ %^WHITE%^Desserts%^RED%^ @%^GREEN%^~~~~~~~~~~~~~~~~~~~~~~%^RED%^@%^RESET%^\n");
    write("\t%^ORANGE%^Bread Pudding%^RESET%^                        "+
	      ""+(int)ob->get_price("bread pudding") + " gold");
    write("\t%^BOLD%^%^GREEN%^Attaya Lime Pie%^RESET%^                     "+
	      ""+(int)ob->get_price("attaya lime pie") + " gold");
    write("\t%^YELLOW%^Creme Brulee%^RESET%^                        "+
	      ""+(int)ob->get_price("creme brulee") + " gold");
    write("\t%^BOLD%^%^BLACK%^Chocolate Heaven%^RESET%^                    "+
	      ""+(int)ob->get_price("chocolate heaven") + " gold");
    write("\t%^MAGENTA%^Berry Cheesecake%^RESET%^                    "+
	      ""+(int)ob->get_price("berry cheesecake") + " gold");
    write("\t%^ORANGE%^Mango Sorbet%^RESET%^                         "+
	      ""+(int)ob->get_price("mango sorbet") + " gold\n");
    write("%^BOLD%^%^RED%^@%^GREEN%^~~~~~~~~~~~~~~~~~%^RED%^@ %^WHITE%^Non-Alcoholic Drinks%^RED%^ @%^GREEN%^~~~~~~~~~~~~~~~~%^RED%^@%^RESET%^\n");
    write("\t%^BOLD%^%^CYAN%^Ice Water%^RESET%^                             "+
	      ""+(int)ob->get_price("ice water") + " gold");
    write("\t%^BOLD%^%^MAGENTA%^Jasmine Tea%^RESET%^                           "+
	      ""+(int)ob->get_price("jasmine tea") + " gold");
    write("\t%^ORANGE%^Orange Granizado%^RESET%^                     "+
	      ""+(int)ob->get_price("orange granizado") + " gold");
    write("\t%^BOLD%^%^BLACK%^Chocolate Caliente%^RESET%^                   "+
	      ""+(int)ob->get_price("chocolate caliente") + " gold\n");
    write("%^BOLD%^%^RED%^@%^GREEN%^~~~~~~~~~~~~~~~~~~~%^RED%^@ %^WHITE%^Alcoholic Drinks%^RED%^ @%^GREEN%^~~~~~~~~~~~~~~~~~~%^RED%^@%^RESET%^\n");
    write("\t%^BOLD%^Vino Blanco %^RESET%^                         "+
	      ""+(int)ob->get_price("vino blanco") + " gold");
    write("\t%^MAGENTA%^Vino Tinto%^RESET%^                           "+
	      ""+(int)ob->get_price("vino tinto") + " gold");
    write("\t%^BOLD%^%^RED%^Sangria%^RESET%^                              "+
	      ""+(int)ob->get_price("sangria") + " gold");
    write("\t%^BOLD%^%^BLACK%^Granizado de Cafe%^RESET%^                    "+
	      ""+(int)ob->get_price("granizado de cafe") + " gold");
    write("\t%^BOLD%^%^GREEN%^Margarita%^RESET%^                            "+
	      ""+(int)ob->get_price("margarita") + " gold\n");
    write("%^BOLD%^%^RED%^@%^GREEN%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RED%^@%^RESET%^");
    write("%^BOLD%^<buy dish_name> will get you the food or drink.%^RESET%^");
    return 1;
}