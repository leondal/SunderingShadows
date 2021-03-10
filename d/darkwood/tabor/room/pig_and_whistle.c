//seedier bar for Tabor - thieves fence, etc.  Circe 6/4/04

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
   set_name("The Pig and Whistle");
   set_short("The Pig and Whistle");
   set_long(
@CIRCE
%^BOLD%^The Pig and Whistle, Tabor%^RESET%^
%^ORANGE%^From the rough pine bar to the unvarnished bar stools, it is 
easy to see that this is probably a less than upscale bar.  There
are rushes on the floor to help soak up spilled ale, and a faint
stench of unwashed bodies lingers in the air.  Smoke from numerous 
pipes hangs thick in the air here, permeating your clothes and 
bathing the room in a thick haze.  Small, round tables are scattered 
about, and it's clear that several of them have been repaired 
many times over.  Patrons are sitting on barstools with mismatched 
legs and chairs with repaired backs, but most seem to be enjoying 
themselves.  A dartboard is nailed to the eastern wall with a chalk 
line on the floor before it.  A list has been pinned to the wall 
beside it.  A small doorway beside the bar leads back into what 
looks like a storage room.

%^RESET%^There is a menu on the bar you can read.
CIRCE
  );
  set_smell("default","You smell a pungent mixture of ale, sweat, and smoke.");
  set_listen("default","You hear the raucous laughter of patrons "+
     "and a babble of bawdy jokes.");
    set_items(([
       "bar" : "The rough pine bar looks to have been carved from a "+
          "tree, then plunked right in the bar room.  The top, "+
          "thankfully, has been planed and varnished so that patrons "+
          "don't get splinters, but it seems that's about as far as "+
          "the upkeep goes.",
       ({"stool","stools"}) : "The stools look to have been made of "+
          "pine once upon a time.  Now, many of the legs have been "+
          "replaced by oak, chestnut, even a broom handle here and there.  "+
          "There are six stools lined up in front of the bar.",
       ({"tables","table","round tables","small tables"}) : "Eight "+
          "round tables are crowded into the room, each big enough "+
          "to fit four people comfortably.  However, chairs have been "+
          "moved around here and there, and there is rarely a table "+
          "with four chairs.",
       "smoke" : "A thick haze that hangs in the air.  The smoke "+
          "rises from patrons with pipes, but it never seems to "+
          "disperse.  It makes it hard to see in here.",
    "menu" : "It looks like a list of drinks.  Read the menu to see "+
       "what's available.",
        ({"storage","storage room","doorway"}) : "Looks like a storage "+
          "room for the bar.  You might be able to enter the storage "+
          "room if Rosalyn wasn't watching.",
       "list" : "There is a faded sheet of parchment pinned near the "+
          "dartboard you could read."
  ]));
  set_exits( ([
    "south" : ROOMDIR+"gwy5",
    "storage" : ROOMDIR+"fencer",
    "enter" : ROOMDIR+"fencer"
  ]) );
  set_invis_exits(({"storage","enter"}));
}

void reset() {
    object ob;
  ::reset();
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("pig_and_whistle");
        ob->move(TO);
    }
    if(!present("barkeep")){
      find_object_or_load("/d/darkwood/tabor/mon/rosalyn")->move(TO);
    }
}

int read(string str)
{
        object obj,obj2;
        int i;
        string *names;
    if(str == "list" && obj2 = present("dartboard")) {
        names = obj2->query_mastery_list();
        if(sizeof(names) < 1){
           write("%^BOLD%^No one has yet mastered darts at this bar!\n"+
              "Will you be the first?");
           return 1;
        }else{
        write("The following individuals are recognized as having "+
        "mastered the game of darts.");
        for(i = 0;i < sizeof(names);i++) {
            tell_object(TP,"%^GREEN%^"+(i+1)+" %^BOLD%^%^WHITE%^- "+
               "%^YELLOW%^"+capitalize(names[i])+"\n");
        }
        }
        return 1;
    }
        if(!present("barkeep")) {
                write("The menu is smeared with the blood of the bartender!");
                return 1;
        }
  	  obj = present("barkeep");
        if(str == "menu") {
                say(""+TPQCN+" reads over the menu.");
                message("Ninfo","The menu is on a small sign on the bar, and it"+
                " lists these drinks:\n",TP);
                message("Ninfo","%^ORANGE%^------------------%^YELLOW%^> %^GREEN%^Non-Alcoholic Drinks %^YELLOW%^<%^RESET%^%^ORANGE%^------------------\n",TP);
                message("Ninfo","\t%^YELLOW%^Squealing Pansy%^RESET%^        \t\t"+
                " "+(int)obj->get_price("squealing pansy")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^MAGENTA%^Strawberry %^YELLOW%^Lemonade%^RESET%^             "+
                " "+(int)obj->get_price("strawberry lemonade")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^BLUE%^Daydream%^RESET%^                         "+
                ""+(int)obj->get_price("daydream")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^MAGENTA%^Ginger Peach Cocktail%^RESET%^            "+
                ""+(int)obj->get_price("ginger peach cocktail")+" silver pieces\n",TP);
                message("Ninfo","%^ORANGE%^--------------------%^YELLOW%^> %^GREEN%^Alcoholic Drinks %^YELLOW%^<%^RESET%^%^ORANGE%^--------------------\n",TP);
                message("Ninfo","\t%^ORANGE%^Stout Ale%^RESET%^                        "+
                ""+(int)obj->get_price("stout ale")+" silver pieces\n",TP);
                message("Ninfo","\t%^MAGENTA%^Witch's Brew%^RESET%^                     "+
                ""+(int)obj->get_price("witch's brew")+" silver pieces\n",TP);
                message("Ninfo","\t%^ORANGE%^Hairball%^RESET%^                        "+
                " "+(int)obj->get_price("hairball")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^BLACK%^Dirty Dog%^RESET%^                        "+
                ""+(int)obj->get_price("dirty dog")+" silver pieces\n",TP);
                message("Ninfo","%^ORANGE%^--------------------------%^YELLOW%^> %^GREEN%^Shots %^YELLOW%^<%^RESET%^%^ORANGE%^-------------------------\n",TP);
                message("Ninfo","\t%^BOLD%^%^WHITE%^Whiskey%^RESET%^                          "+
                ""+(int)obj->get_price("whiskey")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^GREEN%^Tequila%^RESET%^                          "+
                ""+(int)obj->get_price("tequila")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^BLACK%^Vodka%^RESET%^                            "+
                ""+(int)obj->get_price("vodka")+" silver pieces\n",TP);
                message("Ninfo","\t%^YELLOW%^Cognac%^RESET%^                           "+
                ""+(int)obj->get_price("cognac")+" silver pieces\n",TP);
                message("Ninfo","%^ORANGE%^--------------------------%^YELLOW%^> %^GREEN%^Foods %^YELLOW%^<%^RESET%^%^ORANGE%^-------------------------\n",TP);
                message("Ninfo","\t%^BOLD%^Fish and Chips%^RESET%^                   "+
                ""+(int)obj->get_price("fish and chips")+" silver pieces\n",TP);
                message("Ninfo","\t%^RED%^Blood Pudding%^RESET%^                    "+
                ""+(int)obj->get_price("blood pudding")+" silver pieces\n",TP);
                message("Ninfo","\t%^ORANGE%^Meat Pie%^RESET%^                         "+
                ""+(int)obj->get_price("meat pie")+" silver pieces\n",TP);
                message("Ninfo","\t%^RED%^Roasted Venison%^RESET%^                  "+
                ""+(int)obj->get_price("roasted venison")+" silver pieces\n",TP);
                message("Ninfo","%^ORANGE%^------------------------------------------------------------\n",TP);
                message("Ninfo","<buy item_name> gets you the food or drink.\n",TP);
                return 1;
        }
}
