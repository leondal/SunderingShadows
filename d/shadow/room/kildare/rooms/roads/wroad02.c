//wroad02.c
#include <std.h>
#include "../../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("abandoned trail");
   set_short("Abandoned Trail");
   set_long(
      "The mountainside here is rather steep and large %^BOLD%^%^BLACK%^boulders "+
      "%^RESET%^jut out from the mountain.  %^GREEN%^Tall evergreens %^RESET%^"+
      "sprout from the rock, and between them, a narrow %^BLUE%^trail %^RESET%^"+
      "weaves its way.  It is difficult to tell if the trail is naturally made "+
      "or was carved at one point, but it has clearly not seen much use in many "+
      "years.  Occasional side paths branch off of the main trail, but they "+
      "do not appear to go far.  Just to the northeast, a low fence runs along "+
      "the ridge.  Beyond it, many sheep are grazing on the coarse grass among "+
      "the hills."
   );
   set("night long",
      "%^GREEN%^The meandering %^BOLD%^trail %^RESET%^%^GREEN%^wanders over "+
      "the mountainside, its course difficult to see in the night.  Large "+
      "%^BOLD%^%^BLACK%^boulders %^RESET%^%^GREEN%^standing alongside the "+
      "trail cast %^BOLD%^%^BLACK%^ominous shadows %^RESET%^%^GREEN%^that "+
      "shift and fade with the %^YELLOW%^moonlight%^RESET%^%^GREEN%^.  The "+
      "full %^BOLD%^evergreens %^RESET%^%^GREEN%^lining the path provide "+
      "what little guidance they can to keep your feet from straying off the "+
      "path.  Sporadic paths shunting off in either direction make the "+
      "direction you are travelling anything but certain.  Just northeast "+
      "of here, a low stone fence runs along the ridge."
   );
   set_items(([
      (({"mountain","mountainside"})) : "The dark gray stone of the mounain "+
         "is broken often by tufts of coarse green grass.",
      (({"boulder","boulders"})) : "Large boulders of all shapes and sizes "+
         "stand in the way, causing the path to twist and turn as it moves "+
         "along the mountainside.",
      (({"evergreen","evergreens","trees"})) : "Towering evergreen trees "+
         "reach high overhead.  Some of the branches seem sickly, with "+
         "brown needles and occasional bald patches.  The trees higher "+
         "up the mountainside seem in worse shape, while those heading "+
         "downwards seem healthier.",
      (({"trail","path","pathway"})) : "The narrow rocky trail snakes "+
         "its way between tall evergreens and massive boulders.  It "+
         "seems partially natural, but looks to have been well-worn "+
         "at one point in time as well.",
      (({"side path","side paths"})) : "Narrow paths branching off to "+
         "either side of the trail seem to end almost as abruptly as "+
         "they begin.  It looks almost as though the rock proved too "+
         "resilient in those directions and the path chose an easier "+
         "route.",
      (({"fence","stone fence"})) : "A low, dark gray stone fence "+
         "creates a barrier around some of the hills to the east.  "+
         "Not far away, though, there seems to be a crumbled portion "+
         "that you could surely jump."
      ]));
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","A strong breeze muffles the sounds around you.");
   set_exits(([
      "southwest" : ROADS"wroad03",
   ]));

}
   void init() {
      ::init();
      add_action("jump_fence","jump");
}

int jump_fence(string str) {
   if(str != "fence") {
      tell_object(TP,"Jump what?");
   return 1;
   }
   tell_object(TP,"You place both hands on the stone fence and hop over.");
   tell_room(ETP,""+TPQCN+" places both hands on the low fence and hops over it.",TP);
   TP->move("/d/shadow/room/kildare/rooms/roads/wroad01");
   TP->force_me("look");
   TP->force_me("emote comes hopping over the fence.");
   return 1; 
}
