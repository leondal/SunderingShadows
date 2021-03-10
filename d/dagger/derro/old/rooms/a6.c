#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
  set_property("light",2);
  set_property("fill waterskin",1);
  set_short(
  "Hot springs"
  );
  set_long(
  "%^BOLD%^Hot springs%^RESET%^ \n"+
  "  As you come through the bushes you notice a large steaming pool here."
  "  Hot water cascades down from a crack 30 feet up the rockface."
   "  This area seems so peaceful you hardly notice the great mountains that loom on all sides."
 " Steam from the springs makes the rocks slippery and the chill in the air bites a little deeper as you move away from its heat."
  "\n"
  );
  set_smell("default",  "Sulfur bubbles up from the springs"  );
  set_listen("default",  "Bubbles pop and gurgle as they surface in the hot spring."  );
  set_items(([
  "brush":"Small patches of scrubby vegetation make passage difficult off the path.",
  "water":"The water is boiling hot when it comes out of the spring but quickly cools to manageable temperature in the cold air.",
  "mountains":"Foreboding looking mountains overshadow this little clearing.",
   "rocks":"They're slick with condensed moisture from the steam of the hotspring.",
  "spring":"Hot water pours from a crack in the rockface.  It must be heated from a source far under these inactive volcanos.",
  "pool":"This is a naturally formed rock bowl about 20 feet across and 6 ft. deep in its middle.  There is a dark hole at the bottom of the pool where it must drain back to where ever the water comes from.  The water itself is warm to the touch through most of the pool and only very hot where it pours down from the spring.",
  "water":"Boiling hot as it comes out of the spring and only warm to the touch at the edge of the pool.",
  "crack":"Hot water pours from the crack far up the wet rockface.",
  ]));
  set_exits(([
  "west":ROOMS+"a3",
  "south":ROOMS+"a7"
  ]));
}
void init(){
  ::init();
  add_action("drink","drink");
  add_action("swim","swim");
  add_action("touch","touch");
  add_action("touch","check");
}

int touch(string str){
  if ((str=="water")||(str=="pool")){
  tell_object(TP,"%^The water at the edge is pleasantly warm and makes you wonder if you want to go for a swim.");
  tell_room(ETP,""+TPQCN+" bends down to feel the water temperature.",TP);
  return 1;
  }
}

int swim(){
  tell_object(TP,"The water looks just too inviting and you dive in to the incredibly perfect bath.");
  tell_room(ETP,""+TPQCN+" dives into the pool.",TP);
  return 1;
}

int drink(string str){
  if(str != "water" && str != "pool")  return 0;
  if(!str) return 0;     
  if(!TP->add_quenched(50)){
  write("You are so full of water already that makes you ill just thinking about it.");
  return 1;
  }
  write("You take a large drink of the warm mineral tasting water.");
  tell_room(TO,TPQCN+" takes a large drink from the pool and seems to savor the flavor.",TP);
  return 1;
}
