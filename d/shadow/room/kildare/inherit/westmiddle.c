//westmiddle.c
#include <std.h>
#include "../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
   set_name("abandoned trail");
   set_short("Abandoned Trail");
   set_long(
      "The slope of the mountainside is fairly pronounced, "+
      "making travel difficult.  Large collections of %^BOLD%^%^BLACK%^boulders, "+
      "%^RESET%^some rising well over fifteen feet in the air, force "+
      "the path to take a severely winding course here.  Their shadows "+
      "cool the path and provide some cover, which is needed as the %^GREEN%^trees "+
      "%^RESET%^are thin here.  %^ORANGE%^Cairns %^RESET%^are scattered sporadically along the "+
      "edge of the trail, though some seem to have been overturned "+
      "and scattered.  A few side paths branch off in places, "+
      "ending quickly and seeming to lead nowhere."
   );
   set("night long",
      "%^BOLD%^%^GREEN%^The %^RESET%^%^GREEN%^trail %^BOLD%^becomes more "+
      "difficult to follow under the night sky, with %^BOLD%^%^BLACK%^boulders "+
      "%^BOLD%^%^GREEN%^standing over fifteen feet tall casting their strange, "+
      "shifting shadows on the ground in the %^YELLOW%^moonlight%^GREEN%^.  "+
      "The few towering %^WHITE%^evergreens "+
      "%^GREEN%^seem to grow more plentiful further up the mountainside, "+
      "but here they are too far from the trail to provide much direction.  "+
      "Small piles of stones called %^RESET%^%^ORANGE%^cairns %^BOLD%^%^GREEN%^"+
      "are scattered along the trail, but many have been kicked over or "+
      "scattered by careless feet."
   );
   set_items(([
      (({"mountain","mountainside"})) : "The dark gray stone of the mountain "+
         "is broken often by tufts of coarse green grass.",
      (({"boulder","boulders"})) : "%^BOLD%^%^BLACK%^The boulders here are "+
         "huge, some reaching well over fifteen feet tall.  Their height "+
         "creates large shadows on the ground in between them even during "+
         "the brightest daylight, and creates an abyssal blackness at night.",
      (({"evergreen","evergreens","trees"})) : "Towering evergreen trees "+
         "reach high overhead, though they are fewer here than just up "+
         "the mountainside.  An occasional branch looks sickly and brown "+
         "but the trees seem very healthy for the most part.",
      (({"trail","path","pathway"})) : "The narrow rocky trail snakes "+
         "its way between tall evergreens and massive boulders.  It "+
         "seems partially natural, but looks to have been well-worn "+
         "at one point in time as well.",
      (({"side path","side paths"})) : "Narrow paths branching off to "+
         "either side of the trail seem to end almost as abruptly as "+
         "they begin.  It looks almost as though the rock proved too "+
         "resilient in those directions and the path chose an easier "+
         "route.",
      (({"cairn","cairns"})) : "Small piles of stones in all shades of "+
         "gray from pure white to ebon have been created at various places "+
         "along the trail.  Cairns are often used by people in the "+
         "wilderness to mark their way or leave behind information.  "+
         "If you took a moment, you might be able to observe it for "+
         "its meaning."
      ]));
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","Occasional bird calls drift in on the breeze.");

}
