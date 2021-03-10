#include <std.h>
#include "/d/newbie/newbie.h"

inherit "/std/church";

void create(){
   ::create();
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
   set("short","%^BOLD%^%^RED%^Offestry Church");
   set_long("%^BOLD%^%^RED%^Offestry Church%^RESET%^
You are in the only church in the town of Offestry. The church is not "
"huge. Two rows of pews sit on the two sides of the monastery with a pulpit "
"down the end of the central aisle in the nave. An altar covered with an "
"altar cloth is below the stained glass in the chancel.  There is a room to "
"the north that draws your attention.  A sign over it reads %^BOLD%^Portals "
"to Temples.");
   set_exits(([
      "south":MAINTOWN"square",
      "north":MAINTOWN"portals",
      "east":MAINTOWN"healer",
	]));
   set_property("light",2);
   set_property("indoors",1);
//   set_property("no teleport",1);
   set_items((["church":"The home of the monks.",
      "sign":"You should read it.",
      "pew":"Two rows of wooden benches with backs.",
      "pulpit":"A simple wooden pulpit with a lectern on it.",
      "lectern":"A stand for the monks to read or sing.",
      "aisle":"The central long passageway between the two rows of pew.",
      "nave":"Where you are standing, the main chamber of the church.",
   "altar":"It looks like very nice wood covered with a piece of red altar "+
   "cloth. You see ghosts float down from above the altar "+
      "sometimes. You wonder if this is the place you will go to after your "+
      "death.",
   "altar cloth":"A piece of red cloth.",
      ({"glass","stained glass"}):"A large cross is painted on the glass.",
      "chancel":"The smaller chamber behind the screen with choir stalls "+
   "on the sides and an altar near the stained glass.",
      "choir stalls":"Some wooden bench for choirs to sing hymns."]));
     set_listen("default", "You hear the faint sounds of chanting from "+
        "within the chancel.");
     set_smell("default","The smell of incense fills your nostrils.");
}

void reset()
{
    object mat;
    ::reset();
    if(!present("matthew cinester", TO)) 
    {
        mat = find_object_or_load("/d/newbie/mon/matthew");
        if(objectp(mat)) mat->move(TO);
    }
}

//adding to give newbies a break to afford it so they will check for curses.
//Styx 7/28/01

int identify_curse(string str) {
   string item;
   object ob;

   if(!str) return 0;
   if(sscanf(str,"curse on %s",item) != 1) return 0;
   if(newbiep(TP)) {
      if(!TP->query_funds("gold",50))
      return notify_fail("As a newbie, you only need 50 gold to check your "
      "item for curses.\n");
   }
   if(!newbiep(TP) && !TP->query_funds("gold",500))
      return notify_fail("You need 500 gold to pay for the identification of a cursed item.\n");
   if(!ob = present(item,TP))
      return notify_fail("You do not have any "+item+".\n");

/*  This section looks redundant to me... *Styx*
if(!TP->query_funds("gold",500))
      return notify_fail("You need 500 gold to pay for the identification of a cursed item.\n");
*/
   else {
      if(newbiep(TP)) TP->use_funds("gold",50);
      if(!newbiep(TP)) TP->use_funds("gold",500);
      if(!ob->query_property("enchantment") || ob->query_property("enchantment") >= 0)
         tell_object(TP,"%^BOLD%^%^BLUE%^The "+item+" is not cursed!");
      else {
         tell_object(TP,"%^BOLD%^%^RED%^The "+item+" is cursed!");
      }
   return 1;
   }
}
