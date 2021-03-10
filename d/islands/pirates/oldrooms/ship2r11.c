#include <std.h>
#include "../piratedefs.h"

inherit ROOM;
int emptybilge;

void create(){
::create();

set_property("indoors",1);
set_property("light",-2);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);

set_short("Hold");
set_long( (:TO,"long" :) );

set_smell("default","The air smells stale and there is the faint scent of something rotting.");
 set_listen("default","You can hear water lapping against the hull and the clawing of tiny paws.");
set_items(([
   "bilge":"This water is disgusting but you make out something "+
   "shimmering at the bottom. There seems to be a pump "+
                  "here that can empty the bilge.",
   "crates":"These are filled with spices and linen.",
   "barrels":"These contain water.",
         ]));

    set_exits(([
      "up":CAVES"ship2r2",
    ]));
    set_search("default", "You can't help but notice that the bilge could be "
       "used as a place to stash things.");
}

void init(){
 ::init();
add_action("empty","empty");
}

int empty(string str){
  object equipment;
  if(!str) return notify_fail("Empty what?\n");
  if(str !="bilge") return notify_fail("You can't do that.\n");
  if(emptybilge) return notify_fail("That's already empty.\n");
  if(present("pirate")) {
     write("%^BOLD%^The pirate isn't going to let you do that!");
     return 1;
  }
  else{
   tell_object(TP,"You empty the bilge");
   tell_room(ETP,""+TPQCN+" empties the bilge",TP);
   emptybilge=1;

   equipment = new(OBJ+"gemknow")->move(TO);
   "/d/common/daemon/randstuff_d"->treas_chest(TO,5,random(750)+500);
   tell_object(TP,"You find a gem and a chest falls out of the bilge!"); 
   tell_room(ETP,TPQCN+" finds something in the bilge.",TP);
   return 1;
  }
}


string long(string str){
if (emptybilge==0){
str = "%^BOLD%^Hold%^RESET%^\nYou have descended into the darkness of the ship's hold. "+
      "Crates are stacked high here and there are several barrels "+
      "on the port side. The central bilge contains some very "+
"filthy water.\n";

}else{
str = "%^BOLD%^Hold%^RESET%^\nYou have descended into the darkness of the ship's hold. "+
    "Crates are stacked high here and there are several barrels "+
 "on the port side. The central bilge is empty."
"\n";
}
return str;
}

void reset(){
::reset();
  if(!random(3)) 
     emptybilge=0;
}
