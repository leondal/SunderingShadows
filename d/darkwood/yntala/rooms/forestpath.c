#include <std.h>
#include "/d/darkwood/yntala/yntala.h"
inherit CROOM;

void create()
{

::create();
  set_property("light",1);
  set_travel(RUTTED_TRACK);
  set_terrain(HEAVY_FOREST);
  set_name("A path to an ancient forest");
  set_short("%^RESET%^%^ORANGE%^A hidden pathway%^RESET%^");
   set_long((:TO,"ldesc":));
  set_smell("default","You smell dank vegetation.%^RESET%^");
  set_listen("default","The wind whistles through the trees.");
  set_items(([
     ({"floor","forest floor"}):"%^BOLD%^%^BLACK%^Shadows dance across the forest floor, making it difficult to see much.%^RESET%^",
     ({"forest","tree","trees"}):"%^RESET%^%^ORANGE%^The trees here are old and gnarled, twisted in deformed ways that give off a %^BOLD%^%^BLACK%^spooky %^RESET%^%^ORANGE%^feeling.%^RESET%^",
     ({"light","lights"}):"%^RESET%^%^BLUE%^The only %^RESET%^light %^BLUE%^that manages to make its way through the dense %^GREEN%^canopy %^BLUE%^looks more like fine %^RESET%^spiderwebs %^BLUE%^falling from the sky.",
      "fallen trees":"%^GREEN%^Many fallen trees litter the ground here, most are %^ORANGE%^rotting %^GREEN%^and covered with moss.%^RESET%^",
       "path":"%^RESET%^%^ORANGE%^The path here is small and hard to follow.  Leaves and forest debris litter the ground, but you think you can follow it further west.%^RESET%^",
       "brush":"%^RESET%^%^GREEN%^The brush here is scraggly and unhealthy.",
       "shadows":"%^BOLD%^%^BLACK%^Shadows dance in and out of the trees and brush.%^RESET%^",
]));
   set_exits(([
      "west":INRMS+"forest240",
      "east":"/d/darkwood/room/road11",
   ]));
}
string ldesc(string str){
   return("%^RESET%^%^ORANGE%^This is a small hidden pathway that twists its way between tall, %^BOLD%^%^BLACK%^foreboding %^RESET%^%^GREEN%^trees.  %^ORANGE%^The %^GREEN%^brush %^ORANGE%^on either side of you makes it almost impossible to pass, and the path doesn't seem to have been used much at all.  Little %^RESET%^light %^ORANGE%^makes its way down here, and the %^BOLD%^%^BLACK%^shadows %^RESET%^%^ORANGE%^give out an eerie feeling.  Further west, the trees take on an even more twisted form, growing in gnarled, abused ways as they compete for what little light is left."
"%^RESET%^\n");
} 


