//Octothorpe (1/22/17)
//Shadow, Mage Tower Lab
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit "/std/lab";

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("The Laboratory of the Shadow Mage Tower");
   set_short("%^YELLOW%^The Laboratory of the %^BOLD%^%^BLACK%^Shadow "+
      "%^RESET%^%^YELLOW%^Mage Tower%^RESET%^");
   set_long("%^YELLOW%^The Laboratory of the %^BOLD%^%^BLACK%^Shadow "+
      "%^RESET%^%^YELLOW%^Mage Tower%^RESET%^\n"+
      "%^BOLD%^%^WHITE%^Numerous work stations are set up around the "+
      "room, allowing for practical alchemists to pursue their "+
      "experiments. Hard lines and cold surfaces abound, giving the "+
      "room a %^RESET%^sterile %^BOLD%^appearance. Metal %^BLACK%^"+
      "cabinets %^WHITE%^hold varying sizes of %^RESET%^vials %^BOLD%^"+
      "and %^RESET%^jars%^BOLD%^, along with other implements which "+
      "could aid in the art of alchemy. The room is kept impeccably "+
      "clean and organized beyond a few %^RESET%^%^ORANGE%^books "+
      "%^BOLD%^%^WHITE%^that are scattered around. The bare walls and "+
      "floors are white, causing a stark contrast against the %^RESET%^"+
      "b%^BOLD%^%^BLACK%^la%^RESET%^c%^BOLD%^%^BLACK%^k %^RESET%^m"+
      "%^BOLD%^%^BLACK%^ar%^RESET%^b%^BOLD%^%^BLACK%^le %^WHITE%^"+
      "countertops. Bright light shines from within %^RESET%^metal "+
      "cylinders %^BOLD%^above each of the stations, providing ample "+
      "light. Some lockers along the right wall allow for the storage "+
      "of a mage's most precious commodity - components.");
   set_smell("default","%^BOLD%^%^MAGENTA%^It smells like alchemy.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The room is perfectly "+
      "silent.%^RESET%^");
   set_items(([
      ({"stations","work stations"}) : "%^RESET%^%^CYAN%^Each station "+
         "holds basic tools of the trade: an alembic, crucible, a "+
         "mortar and pestle, a retort and a ring stand, and a small "+
         "stand for holding glass vials upright.%^RESET%^",
      ({"cabinets","vials","jars","implements"}) : "%^RESET%^%^CYAN%^"+
         "Tall cabinets lined with shelves hold various shapes and "+
         "sizes of jars and vials. The doors are %^WHITE%^glass"+
         "%^CYAN%^, allowing a clear look inside.%^RESET%^",
      "books" : "%^RESET%^%^CYAN%^Books scattered about with titles "+
         "such as 'The Path of the Alchemist' and 'A Dozen Practical "+
         "Applications for Dream Fragments' lend a helping hand to an "+
         "alchemist who is in need of a quick reference.%^RESET%^",
      ({"floors","walls","ceiling"}) : "%^RESET%^%^CYAN%^Everything is "+
         "kept white and sterile.%^RESET%^",
      ({"lights","cylinders"}) : "%^RESET%^%^CYAN%^Cylindrical "+
         "%^WHITE%^metal canisters %^CYAN%^hold a %^BOLD%^%^WHITE%^"+
         "white light %^RESET%^%^CYAN%^that almost appears as %^BOLD%^"+
         "%^WHITE%^flame%^RESET%^%^CYAN%^. It is likely is some "+
         "%^MAGENTA%^alchemical process %^CYAN%^that has created such "+
         "a marvel.%^RESET%^",
      ({"lockers","cubbies"}) : "%^RESET%^%^CYAN%^Lockable iron "+
         "compartments can be purchased here, offering a place for a "+
         "mage to hold their spare components.%^RESET%^"
   ]));
      set_exits(([
      "east" : ROOMS"mage3rdlanding",
   ]));
   set_door("wooden door",ROOMS"mage3rdlanding","east",0,0);
   set_door_description("wooden door","%^RESET%^%^CYAN%^It is a door "+
      "that's made from %^ORANGE%^wood%^CYAN%^. There is nothing "+
      "extraordinary about it.%^RESET%^");
   setOwner("none");
   setLabId("shadow");
   {
       object ob;
       ob=new("/d/magic/obj/mirror");
       ob->move(TO);
   }
}
