//Updated by Circe 5/30/04 with color, etc.
// Bar room of the Crown and Castle, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// cncbar.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void init() {
  ::init();
  add_action("read", "read");
}

void create() {
  ::create();
   set_travel(DIRT_ROAD);
   set_terrain(CITY);
   set_property("light", 2);
   set_property("indoors", 1);
   set_short("Bar room of the Crown and Castle, Tabor");
   set_long(
@MELNMARN
%^BOLD%^Bar room of the Crown and Castle, Tabor%^RESET%^
%^CYAN%^This is the %^ORANGE%^bar room %^CYAN%^of the Crown and Castle Inn, where the patrons
of the inn are served %^BOLD%^drinks %^RESET%^%^CYAN%^and %^WHITE%^spirits%^CYAN%^.  In front of you is a long,
very solid looking %^ORANGE%^oak bar %^CYAN%^with %^ORANGE%^stools %^CYAN%^in front of it.  Near the bar
are some %^BOLD%^%^BLUE%^tables%^RESET%^%^CYAN%^, all soldily made, if not exactly undamaged.  Bars
often take a lot of damage, and this inn seems to have chosen utility
over luxury for their furnishings and attire.  Other than that, the
furnishings are sparse, but you will probably never find better %^YELLOW%^liquor%^RESET%^%^CYAN%^
in the whole of the Kingdom.

%^RESET%^There is a menu on the bar you can read.  There is also a list near the dartboard.

The hall is to the south.
MELNMARN
  );
  set_smell("default","You smell the odor of beer and sweat.");
  set_listen("default","You hear the sounds of glasses clanging.");
  
  set_items(([
    "bar" : "The twelve foot bar is made of solid oak with no "+
       "carvings or decoration.  The front of the bar looks solid, "+
       "but the back has been left open and fitted with shelves "+
       "which are lined with high quality liquor.",
    ({"stool","stools"}) : "The tall stools before the bar look "+
       "as if they all were made of the same oaken wood at one "+
       "time.  Now, however, several of the legs have been replaced "+
       "with what looks like pine.  They are still very well cared "+
       "for and in great shape, if not completely coordinated.",
    ({"table","tables"}) : "There are eight round tables places at "+
       "somewhat regular intervals around the room.  Each of these "+
       "tables has six chairs surrounding it.  Two smaller, square "+
       "tables are placed in two of the corners.  These two tables "+
       "have only two chairs each, making them a little more cozy, "+
       "though the bar is not exactly a romantic place.",
    "menu" : "It looks like a list of drinks.  Read the menu to see "+
       "what's available."
  ]));
  set_exits( ([
    "south" : ROOMDIR+"cnchall"
  ]) );
}

void reset() {
    object ob;
  ::reset();
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("crown_and_castle_bar");
        ob->move(TO);
    }
    if(!present("tamir")){ // changed from wiegand when the bar got a 
                          // new barkeep, thanks to Cythera.
                          // Lujke November 25/05
       find_object_or_load("/d/darkwood/tabor/mon/wiegand")->move(TO); 
    }
}

int read(string str)
{
        object obj;
        int i;
        string *names;
    if(str == "list" && obj = present("dartboard")) {
        names = obj->query_mastery_list();
        if(sizeof(names) < 1){
           write("%^BOLD%^No one has yet mastered darts at this bar!\n"+
              "Will you be the first?");
           return 1;
        }else{
        write("The following individuals are recognized as having "+
        "mastered the game of darts.");
        for(i = 0;i < sizeof(names);i++) {
            tell_object(TP,""+names[i]+"\n");
        }
        }
        return 1;
    }
//        removed this section when Wiegand's replacement Tamir was brought to life by Cythera
//        Lujke November 25/05
//        if(!present("wiegand")) {
//                write("The menu is smeared with the blood of the bartender!");
//                return 1;
//        }
  	 obj = present("tamir"); // changed from Wiegand Nov 25/05 Lujke
        if(str == "menu") {
                say(""+TPQCN+" reads over the menu.");
                message("Ninfo","The menu is on a small sign on the bar, and it"+
                " lists these drinks:\n"+
                "%^GREEN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n\n",TP);
                message("Ninfo","                  %^BOLD%^%^BLUE%^Non-Alcoholic Drinks\n\n",TP);
                message("Ninfo","\t%^YELLOW%^Ginger Tea%^RESET%^        \t\t"+
                " "+(int)obj->get_price("ginger tea")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^WHITE%^Coconut Milk%^RESET%^                     "+
                " "+(int)obj->get_price("coconut milk")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^CYAN%^Water%^RESET%^                             "+
                ""+(int)obj->get_price("water")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^BLACK%^Coffee%^RESET%^                            "+
                ""+(int)obj->get_price("coffee")+" silver pieces\n\n",TP);
                message("Ninfo","%^GREEN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"+
                "*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n\n",TP);
                message("Ninfo","                  %^BOLD%^%^BLUE%^  Alcoholic Drinks\n\n",TP);
                message("Ninfo","\t%^BOLD%^%^RED%^Pomegranate Wine%^RESET%^                 "+
                ""+(int)obj->get_price("pomegranate wine")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^MAGENTA%^Blinkdog%^RESET%^                         "+
                ""+(int)obj->get_price("blinkdog")+" silver pieces\n",TP);
                message("Ninfo","\t%^MAGENTA%^Purple Ale%^RESET%^                      "+
                " "+(int)obj->get_price("purple ale")+" silver pieces\n",TP);
                message("Ninfo","\t%^ORANGE%^Delorn's Delight%^RESET%^                 "+
                ""+(int)obj->get_price("delorn's delight")+" silver pieces\n\n",TP);
                message("Ninfo","%^GREEN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"+
                "*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
                message("Ninfo","<buy drink_name> gets you a drink.\n",TP);
                return 1;
        }
}

