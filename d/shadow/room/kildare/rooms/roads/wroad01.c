//wroad01.c
#include <std.h>
#include "../../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("fenced paddock");
   set_short("A Fenced Paddock");
   set_long(
      "%^BOLD%^%^GREEN%^A Fenced Paddock\n"+
      "%^RESET%^%^GREEN%^The grass growing in this rocky paddock is short "+
      "and coarse, though the sheep grazing here seem content enough.  "+
      "The gray stone of the mountainside is broken here by great patches "+
      "of grass, and a few small bushes lie along the fence.  The low stone "+
      "fence has a strange green moss growing between the stones and seems "+
      "to have stood undisturbed for countless years.  Sheep of all shades "+
      "of gray, from nearly white to almost midnight black, dot the rolling "+
      "paddock.  The fence surrounding the paddock comes to an end here, in "+
      "this sliver of a valley.  It seems few sheep venture this far west."
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
         "creates a barrier around this paddock among the rocky hills.  "+
         "Not far away, though, there seems to be a crumbled portion "+
         "that has fallen into disrepair.  Few sheep seem to venture "+
         "this far west, so perhaps the shepherds haven't noticed or "+
         "bothered to repair it.  It is so low that you could surely "+
         "jump over it."
      ]));
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","A strong breeze muffles the sounds around you.");
   set_exits(([
      "northeast" : TROOMS"pad12",
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
   TP->move("/d/shadow/room/kildare/rooms/roads/wroad02");
   TP->force_me("look");
   TP->force_me("emote comes hopping over the fence.");
   return 1; 
}
