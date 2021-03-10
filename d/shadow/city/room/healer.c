//Octothorpe (6/4/16)
//Shadow, Healer

#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include "../defs.h"

inherit HEALER;

void create(){
   ::create();
   set_light(2);
   set_indoors(1);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("training",1);
   set_short("%^BOLD%^%^RED%^Hettman's House of Healing");
   set_long("%^BOLD%^%^RED%^Hettman's House of Healing%^RESET%^\n"+
      "This cramped shop serves as the healer of choice for "+
      "%^BOLD%^%^BLACK%^Shadow's %^RESET%^adventurer community. "+
      "%^ORANGE%^Shelves %^RESET%^line the walls filled to the brim "+
      "with numerous poultices, potions, salves, and jars. A "+
      "smattering of cots are scattered throughout the shop taking "+
      "up much of the floor space. Wounded and sick adventurers lie "+
      "sprawled on the cots, moaning and wincing as Hettman rushes "+
      "to and fro to attend to them.\n");
   set_items(([
      "shelves" : "Numerous %^ORANGE%^shelves %^RESET%^line the walls "+
         "throughout the shop. They are filled with a variety of "+
         "poultices, potions, salves, and jars containing remedies "+
         "that Hettman uses in his practice.",
      "cots" : "Half a dozen simple cots are found on the floor "+
         "throughout the shop in between shelves. At all hours of "+
         "the day one may find adventurers sprawled on them awaiting "+
         "treatment from Hettman.",
   ]));
   set_smell("default","The strong odor of herbs and balms turns "+
      "your stomach.");
   set_listen("default","You hear occasional moans and groans from "+
      "Hettman's patients.");
   set_exits(([
      "south" : ROOMS"shadway1"
   ]));
   set_name("Hettman");
}

void reset(){
   ::reset();
   if(!present("hettman")){
      new(MON"hettman")->move(TO);
   }
}