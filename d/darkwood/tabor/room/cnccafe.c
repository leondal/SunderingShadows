//Edited the cafe to reflect Cythera's new waitress, 
//Hessa, who took over from Seif. Lujke November 25/05
//chessboard by Lujke added by Circe 4/22/05
//updated by Circe 5/30/04 with colors, etc.
// Cafe of the Crown and Castle, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// cnccafe.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Cafe of the Crown and Castle, Tabor");
    set_long(
@TABOR
%^BOLD%^Cafe of the Crown and Castle, Tabor%^RESET%^
%^CYAN%^This is the %^MAGENTA%^cafe %^CYAN%^of the inn, probably one of the finest places to eat in
all of Tabor outside of the %^YELLOW%^Great Hall %^RESET%^%^CYAN%^in %^BOLD%^%^WHITE%^Caer Tabor%^RESET%^%^CYAN%^.  However, Amergin
is frequently hired to cater the larger Royal feasts.  The chef of this
cafe is a %^BOLD%^Tsarvani %^RESET%^%^CYAN%^from Verhedin who is a master of that cuisine.  Some
of the %^BOLD%^Tsarvani cuisine %^RESET%^%^CYAN%^is a bit hard to take, so they also offer a few
standard %^MAGENTA%^luxury dishes %^CYAN%^as well.  Either way, this is the best food in
all of Tabor and perhaps anywhere north of Verhedin.

%^RESET%^There is a menu here you can read.

The hall of the inn is to the north.
TABOR
  );
  set_smell("default","You smell the aroma of exotic food.");
  set_listen("default","You hear the sounds of plates clanging.");
  
  set_items(([
    "menu" : "You may read it if you like."
  ]));
  set_exits(([
    "north" : ROOMDIR+"cnchall"
  ]));
}

void reset() {
  ::reset();
   if(!present("hessa"))   // Seif was replaced by Hessa, 
                           //Courtesy of Cythera. Lujke November 25/05
      find_object_or_load("/d/darkwood/tabor/mon/seif")->move(TO);
    if(!present("chessboard")) new(OBJDIR+"tabor_chess")->move(TO);
}

int read(string str) {
    object ob;
    int i;

  if(str!="menu")
    return 0;
    ob = present("hessa", TO); // Seif was replaced by Hessa, 
                           //Courtesy of Cythera. Lujke November 25/05
    if (!objectp(ob)){  // This check added due to a bug when someone tried to read the menu
                        // when the bartender wasn't present. Lujke December 31 2005
      write("The cafe has no staff present to show you the menu!\n");
      return 1;
    }
// This section removed when Cythera brought Seif's replacement Hessa to life
// Lujke November 25/05
//    if(!ob) {
//        write("You cannot read the menu, as it is splattered with blood.");
//        return 1;
//    }
    write("The following great foods and drinks are served here at the cafe.");
   
    write("%^BLUE%^BOLD%^  ~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~\n");
    write("                %^BOLD%^%^WHITE%^Our Delicious Entrees%^RESET%^\n");
    write("\t%^RED%^Chilled Monkey Brains%^RESET%^         "+
	      ""+(int)ob->get_price("chilled monkey brains") + " silver");
    write("\t%^BOLD%^%^MAGENTA%^Pigs Feet%^RESET%^                     "+
	      ""+(int)ob->get_price("pigs feet") + " silver");
    write("\t%^RED%^Beef Tenderloin%^RESET%^               "+
	      ""+(int)ob->get_price("beef tenderloin") + " silver");
    write("\t%^GREEN%^Spiced Deer Eyes%^RESET%^              "+
	      ""+(int)ob->get_price("spiced deer eyes") + " silver");
    write("\t%^ORANGE%^Tandoori Chicken%^RESET%^              "+
	      ""+(int)ob->get_price("tandoori chicken") + " silver");
    write("\t%^ORANGE%^Lamb Masala%^RESET%^                   "+
	      ""+(int)ob->get_price("lamb masala") + " silver");
    write("\t%^BOLD%^Cheese Naan%^RESET%^                    "+
	      ""+(int)ob->get_price("cheese naan") + " silver");
    write("\t%^YELLOW%^Curry Pot Pie%^RESET%^                 "+
	      ""+(int)ob->get_price("curry pot pie") + " silver");
    write("\tTabouli%^RESET%^                       "+
	      ""+(int)ob->get_price("tabouli") + " silver");
    write("%^BLUE%^BOLD%^  ~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~\n");
    write("               %^BOLD%^%^WHITE%^Our Delectable Desserts%^RESET%^\n");
    write("\t%^YELLOW%^Baklava%^RESET%^                       "+
	      ""+(int)ob->get_price("baklava") + " silver");
    write("\t%^MAGENTA%^Blackberry Custard%^RESET%^             "+
	      ""+(int)ob->get_price("blackberry custard") + " silver");
    write("\t%^YELLOW%^Caerveron%^RESET%^                      "+
	      ""+(int)ob->get_price("caerveron") + " silver");
    write("\t%^MAGENTA%^Roasted Dates%^RESET%^                 "+
	      ""+(int)ob->get_price("roasted dates") + " silver");
    write("%^BLUE%^BOLD%^  ~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~\n");
    write("                 %^BOLD%^%^WHITE%^Non-Alcoholic Drinks%^RESET%^\n");
    write("\t%^BOLD%^%^MAGENTA%^Mango Lassi%^RESET%^                   "+
	      ""+(int)ob->get_price("mango lassi") + " silver");
    write("\t%^BOLD%^%^GREEN%^Sikanjabin%^RESET%^                    "+
	      ""+(int)ob->get_price("sikanjabin") + " silver");
    write("\t%^ORANGE%^Jasmine Tea%^RESET%^                   "+
	      ""+(int)ob->get_price("jasmine tea") + " silver");
    write("\t%^BOLD%^%^MAGENTA%^%^Rose Water%^RESET%^                     "+
	      ""+(int)ob->get_price("rose water") + " silver");
    write("%^BLUE%^BOLD%^  ~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~\n");
    write("                   %^BOLD%^%^WHITE%^Alcoholic Drinks%^RESET%^\n");
    write("\t%^BOLD%^%^RED%^Spiced Wine%^RESET%^                   "+
	      ""+(int)ob->get_price("spiced wine") + " silver");
    write("\t%^MAGENTA%^Tsarven Mead%^RESET%^                  "+
	      ""+(int)ob->get_price("tsarven mead") + " silver");
    write("%^BLUE%^BOLD%^  ~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~@~");
    write("<buy dish_name> will get you the food or drink.");
    return 1;
}
