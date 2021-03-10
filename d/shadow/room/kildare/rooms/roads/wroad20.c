//wroad20.c
#include <std.h>
#include "../../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);
   set_name("abandoned trail");
   set_short("Abandoned Trail");
   set_long(
      "The trail climbing along Echoes Mountains comes to the treeline "+
      "here.  The %^GREEN%^evergreens %^RESET%^form a barrier blocking "+
      "much of the sky higher up, but here they end, leaving the ground "+
      "below to %^BOLD%^%^GREEN%^grass %^RESET%^and soil.  The %^BOLD%^%^BLACK%^"+
      "boulders %^RESET%^which dominate much of the upper mountains die out "+
      "here as well, and the footpath becomes much more easily travelled.  "+
      "It is wider and not less defined, as the foothills lower on "+
      "the mountain seem much more navigable.  %^ORANGE%^Cairns %^RESET%^"+
      "line the trail at intervals, nearly hidden in the tall grass."
   );
   set("night long",
      "%^BOLD%^%^GREEN%^The trail winding up the mountainside comes "+
      "to the treeline here, a strange place where higher up there are "+
      "numerous %^WHITE%^evergreens %^GREEN%^and just below nothing but "+
      "rolling foothills covered with %^RESET%^%^GREEN%^grass%^BOLD%^.  "+
      "The %^YELLOW%^moonlight %^GREEN%^on the grass causes it to glow "+
      "%^WHITE%^silvery %^GREEN%^green, making all the land below look "+
      "magical in comparison with the dark shadows of %^BOLD%^%^BLACK%^"+
      "boulders %^GREEN%^and trees above.  Small "+
      "piles of rocks called %^RESET%^%^ORANGE%^cairns %^BOLD%^%^GREEN%^are "+
      "placed at the edge of the trail at uneven intervals."
   );
   set_items(([
      (({"mountain","mountainside"})) : "The gray stone of the mountain is "+
         "broken here by dirt and tall, green grass that covers the foothills.  "+
         "Higher up the mountainside, tall evergreens and boulders block out "+
         "much of the sun, allowing little grass to grow there.",
      (({"boulder","boulders"})) : "%^BOLD%^%^BLACK%^The boulders create "+
         "tall, round shadows higher up the mountainside.",
      (({"evergreen","evergreens","trees","treeline"})) : "Here at the "+
         "treeline, the evergreens create an imposing border between "+
         "the mountains above and the pleasant foothills below.",
      (({"trail","path","pathway"})) : "The wide, grassy trail moving "+
         "over the foothills is barely defined at all.  The hills seem "+
         "safe enough to travel on, and it is barely a shadow of a path "+
         "that remains here.",
      (({"cairn","cairns"})) : "Small piles of stones in all shades of "+
         "gray from pure white to ebon have been created at various places "+
         "along the trail.  Cairns are often used by people in the "+
         "wilderness to mark their way or leave behind information.  "+
         "If you took a moment, you might be able to observe it for "+
         "its meaning.",
      (({"grass","tall grass","green grass"})) : "The grass here is lush "+
         "and deep green, creating a soft pathway.  It covers most of the "+
         "foothills, with occasional rocky patches."
      ]));
   set_smell("default","You smell the clean air of the foothills.");
   set_listen("default","Occasional bird calls drift in on the breeze.");
   set_exits(([
      "northeast" : ROADS"wroad19",
      "south" : ROADS"wroad21"
      ]));
}

   void init() {
      ::init();
      add_action("observe_cairn","observe");
}

int observe_cairn(string str) {
   if(str != "cairn") {
   return 0;
   }
   if(TP->is_class("ranger") || TP->is_class("druid")) {
      tell_object(TP,"The cairn is marked with a sign of warning, "+
         "though it seems to be weathered and old.  It seems a band "+
         "of orcs once marauded throughout these foothills.");
      return 1;
   }
   else{
      tell_object(TP,"You can decipher no meaning from the "+
         "strange pile of stones!");
      tell_room(ETP,""+TPQCN+" kneels down and studies a cairn, "+
         "but looks confused.",TP);
      return 1;
      }
}
