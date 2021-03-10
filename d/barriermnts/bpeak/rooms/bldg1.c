//bldg1
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;

void create(){
::create();
   set_property("indoors",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Inside a eating hall");
   set_short("%^RESET%^The inside of a large stone building%^RESET%^");
   set_smell("default","The smell of earth is strong here.");
   set_long((:TO,"ldesc":));
   set_items(([
   "chairs":"There are many chairs here ranging in size from very small to very"
" large.  A few of them are crudely made, while others look to be of the finest"
" craftsmanship.  The larger chairs all are covered with %^ORANGE%^furs"
" %^RESET%^and are obviously used, while the smaller chairs seem to go unnoticed.",
   "tables":"%^RESET%^%^ORANGE%^The tables here, like the rest of the furnishings"
" in this room, are mismatched and look to have come from several different sources.",
   ({"brackets","torch brackets"}):"%^BOLD%^%^BLACK%^Torch brackets line the edges of the room in ten foot intervals.  Each bracket holds a lit torch for lighting.%^RESET%^",
   ({"torch","torches"}):"%^YELLOW%^Each torch burns constantly and gives off a steady glow of light.%^RESET%^", 
   "roots":"%^BOLD%^%^WHITE%^This building has very obviously been built right against the mountainside.  The back wall is made entirely out of the earth of the mountain and roots hang out of it and dangle towards the floor.%^RESET%^", 
 ]));
   set_exits((["east":INRMS+"tcliff13"]));
   set_search("chairs","%^BOLD%^%^WHITE%^After looking over all the chairs, two"
" chairs stand out the most.  They sit over in the furthest corner and are carved"
" out of beautiful ivory.  Scrollwork traces up the delicately curved legs, and"
" the seats of the chairs are made of the finest silks.  The backs of the chairs"
" are carved into a gentle leaf pattern and the arches that mark the top of the"
" chairs have the words '%^GREEN%^to the friends of the people, may you live in"
" eternal happiness.%^WHITE%^' inscribed upon them.");
   set_search("tables","After looking over all the tables, one large table grabs"
" your attention as it sets in the middle of the room.  It is carved out of"
" %^ORANGE%^oak %^RESET%^and looks like it had made with love.  A family name is"
" inscribed on one of the legs of the table and the %^BLUE%^ink markings"
" %^RESET%^that line the bottom of the table look to be those of a childs hand."
"  This table obviously use to belong to a family of larger people...");
}
string ldesc(string str){
   return("%^RESET%^This room is obviously the dining area.  None of the chairs or"
" tables match, giving you the impression that the dining collection here is rather"
" several smaller collections stolen from whatever areas these giants have decided"
" to raid.  The walls of the building are smooth to the touch and the ceiling is"
" easily twenty feet tall.  The back wall of the building is made entirely out of"
" the %^ORANGE%^earth %^RESET%^of the %^BLUE%^mountain %^RESET%^that this building"
" sets against and a few %^BOLD%^%^WHITE%^roots %^RESET%^even stick out of it."
"  %^BOLD%^%^BLACK%^Torch brackets %^RESET%^line the other three walls at ten foot"
" intervals and each holds a large torch for lighting.  Crude and stinking"
" %^ORANGE%^furs %^RESET%^line the larger chairs, while the smaller ones seem to go"
" unnoticed.%^RESET%^ \n");
} 
void reset(){
   ::reset();
   if(!present("hill giant")){
      new(TMONDIR+"fgiant.c")->move(TO);
  }
}

