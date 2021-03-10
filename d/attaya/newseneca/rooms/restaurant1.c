//Free-standing restaurant for new Seneca, 
//featuring Hispanic food ~Circe~ 11/14/07

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",3);
    set_property("indoors",1);
    set_name("La Sangria, Seneca");
    set_short("La Sangria, Seneca");
    set_long("%^MAGENTA%^La Sangria, Seneca%^RESET%^\n"+
       "%^ORANGE%^This fashionable restaurant features stucco walls "+
       "painted a soft orange.  Round %^YELLOW%^tables %^RESET%^"+
       "%^ORANGE%^with %^MAGENTA%^c%^RESET%^u%^YELLOW%^s%^RESET%^h"+
       "%^MAGENTA%^i%^RESET%^o%^YELLOW%^n%^RESET%^e%^MAGENTA%^d "+
       "%^RESET%^%^ORANGE%^chairs are separated from each other by "+
       "archways painted %^MAGENTA%^purple %^ORANGE%^and decorated with "+
       "stenciled %^MAGENTA%^roses%^ORANGE%^.  Each %^YELLOW%^table "+
       "%^RESET%^%^ORANGE%^is topped by a pristine %^BOLD%^%^WHITE%^"+
       "white tablecloth %^RESET%^%^ORANGE%^with a %^GREEN%^taper "+
       "candle %^ORANGE%^in its center.  All along the walls, narrow "+
       "%^RESET%^shelves %^ORANGE%^have been run near the ceiling, and "+
       "each supports an assortment of small %^RED%^sculptures %^ORANGE%^"+
       "and %^RESET%^curios %^ORANGE%^spread among %^GREEN%^sprawling "+
       "ivy %^ORANGE%^in terracotta planters.  Typically, several servers "+
       "dressed in %^YELLOW%^vibrant %^GREEN%^c%^RED%^o%^BLUE%^l%^CYAN%^o"+
       "%^MAGENTA%^r%^YELLOW%^s %^RESET%^%^ORANGE%^are busy at work, "+
       "bringing menus and food to patrons.\n\n"+
       "%^RESET%^There is a menu here you can read.\n");
   set_smell("default","A pleasing blend of herbs and spices lingers in the air.");
   set_listen("default","The low murmur of voices and the clinking of dishes "+
       "rises above the sound of the ocean waves.");
   set_items(([
      "menu" : "You may read it if you like.",
      ({"wall","walls"}) : "%^ORANGE%^The stucco walls of the restaurant have "+
         "been painted a soft, warm orange.  It contrasts sharply with the "+
         "brilliant %^MAGENTA%^purple %^ORANGE%^of the archways.  "+
         "Along the edge of each archway, %^MAGENTA%^purple roses %^ORANGE%^"+
         "with scrolling %^GREEN%^stems %^ORANGE%^have been painted for added "+
         "decoration.%^RESET%^",
      ({"table","tables","chair","chairs"}) : "Most of the %^YELLOW%^tables "+
         "%^RESET%^are small and round, made from varnished oak.  Each has "+
         "matching chairs with colorful %^MAGENTA%^s%^RESET%^t%^YELLOW%^r"+
         "%^RESET%^i%^MAGENTA%^p%^RESET%^e%^YELLOW%^d %^RESET%^%^MAGENTA%^c"+
         "%^RESET%^u%^YELLOW%^s%^RESET%^h%^MAGENTA%^i%^RESET%^o%^YELLOW%^n"+
         "%^RESET%^s.  A couple of the alcoves have larger tables, meant for "+
         "parties of four or more.  Each table has been topped with a pristine "+
         "%^BOLD%^tablecloth %^RESET%^with a long %^GREEN%^taper candle%^RESET%^.",
      ({"archway","archways","alcove","alcoves"}) : "Cleverly designed walls "+
         "and archways help form semi-private dining alcoves for the tables.  "+
         "Some are left in the open, but many of them are at least somewhat "+
         "secluded.",
      ({"purple rose","roses","purple roses"}) : "%^MAGENTA%^Decorating the "+
         "outer edge of each archway is a series of purple roses with long, "+
         "scrolling %^GREEN%^stems%^MAGENTA%^.%^RESET%^",
      ({"tablecloth","candle","taper candle"}) : "The %^BOLD%^tablecloths "+
         "%^RESET%^are spotless and hang to just about the seat of the chairs.  "+
         "In the center of each is a tall %^GREEN%^taper candle %^RESET%^set "+
         "within a simple %^CYAN%^crystal candlestick%^RESET%^.",
      ({"shelves","shelf","curios","sculptures","ivy","planters"}) : "The narrow "+
         "shelf runs all the way around the top of the walls.  Its length is filled "+
         "with small statues made of wood, ivory, stone - every material imaginable.  "+
         "Spread among the statues are small curios - mugs, figurines, shells, "+
         "and the like - which seem to have been collected over time.  Sprawled "+
         "throughout are rich %^GREEN%^ivy vines %^RESET%^growing in %^ORANGE%^"+
         "terracotta planters%^RESET%^."
   ]));
  set_exits(([
    "north" : ROOMS"viento49"
  ]));
   set_door("restaurant door","/d/attaya/newseneca/rooms/viento49","north",0,0);
   set_door_description("restaurant door","%^ORANGE%^The door leading to the "+
      "street is curved at the top, and this side is painted the same deep "+
      "%^MAGENTA%^purple %^ORANGE%^as the archways.  Set near the top of the door "+
      "is a half-moon window allowing a tiny glimpse of the street beyond.%^RESET%^");
}

void reset() {
  ::reset();
   if(!present("server"))
      find_object_or_load("/d/attaya/newseneca/mon/restaurant_server")->move(TO);
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
   
    write("%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("                    %^YELLOW%^Appetizers\n");
    write("\t%^RED%^Gazpacho%^RESET%^                    "+
	      ""+(int)ob->get_price("gazpacho") + " gold");
    write("\t%^YELLOW%^Seneca Bread%^RESET%^                "+
	      ""+(int)ob->get_price("seneca bread") + " gold");
    write("\t%^ORANGE%^Beef Empanadas%^RESET%^              "+
	      ""+(int)ob->get_price("beef empanadas") + " gold");
    write("\t%^GREEN%^Anchovy-stuffed Olives%^RESET%^      "+
	      ""+(int)ob->get_price("anchovy-stuffed olives") + " gold");
    write("%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("                      %^YELLOW%^Entrees\n");
    write("\t%^YELLOW%^Paella%^RESET%^                      "+
	      ""+(int)ob->get_price("paella") + " gold");
    write("\t%^BOLD%^%^MAGENTA%^Habas con Jamon%^RESET%^             "+
	      ""+(int)ob->get_price("habas con jamon") + " gold");
    write("\t%^ORANGE%^Estofado%^RESET%^                    "+
	      ""+(int)ob->get_price("estofado") + " gold");
    write("\t%^RED%^Plato Seneca%^RESET%^                "+
	      ""+(int)ob->get_price("plato seneca") + " gold");
    write("\t%^BOLD%^%^RED%^Suquet%^RESET%^                      "+
	      ""+(int)ob->get_price("suquet") + " gold");
    write("\t%^ORANGE%^Filet with Mushrooms%^RESET%^        "+
	      ""+(int)ob->get_price("filet with mushrooms") + " gold");
    write("%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("                      %^YELLOW%^Desserts\n");
    write("\t%^YELLOW%^Flan%^RESET%^                        "+
	      ""+(int)ob->get_price("flan") + " gold");
    write("\t%^ORANGE%^Churros%^RESET%^                     "+
	      ""+(int)ob->get_price("churros") + " gold");
    write("\t%^BOLD%^Mato Cheese%^RESET%^                 "+
	      ""+(int)ob->get_price("mato cheese") + " gold");
    write("\t%^ORANGE%^Turron%^RESET%^                      "+
	      ""+(int)ob->get_price("turron") + " gold");
    write("%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("                %^YELLOW%^Non-alcoholic Drinks\n");
    write("\t%^CYAN%^Water%^RESET%^                       "+
	      ""+(int)ob->get_price("water") + " gold");
    write("\t%^ORANGE%^Horchata%^RESET%^                    "+
	      ""+(int)ob->get_price("horchata") + " gold");
    write("\t%^BOLD%^%^BLACK%^Cafe con Leche%^RESET%^              "+
	      ""+(int)ob->get_price("cafe con leche") + " gold");
    write("\t%^BOLD%^%^GREEN%^Granizado%^RESET%^                   "+
	      ""+(int)ob->get_price("granizado") + " gold");
    write("\t%^ORANGE%^Orange Juice%^RESET%^                "+
	      ""+(int)ob->get_price("orange juice") + " gold");
    write("%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("                  %^YELLOW%^Alcoholic Drinks\n");
    write("\t%^RED%^Seneca Select%^RESET%^               "+
	      ""+(int)ob->get_price("seneca select") + " gold");
    write("\t%^BOLD%^Sangria Blanca%^RESET%^              "+
	      ""+(int)ob->get_price("sangria blanca") + " gold");
    write("\t%^ORANGE%^Mango Sangria%^RESET%^               "+
	      ""+(int)ob->get_price("mango sangria") + " gold");
    write("\t%^BOLD%^%^MAGENTA%^Cava%^RESET%^                        "+
	      ""+(int)ob->get_price("cava") + " gold");
    write("%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~");
    write("%^BOLD%^<buy dish_name> will get you the food or drink.%^RESET%^");
    return 1;
}