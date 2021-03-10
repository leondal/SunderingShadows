//westlow.c
#include <std.h>
#include "../kildare.h"

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
     "Here in the foothills of Echoes Mountains, the ground is a little "+
     "rocky, but the %^GREEN%^grass %^RESET%^grows tall and green.  Farther "+
     "up the mountainside, tall %^ORANGE%^evergreens %^RESET%^stand against "+
     "the sky and massive %^BOLD%^%^BLACK%^boulders %^RESET%^seem to form "+
     "rings and barriers, forcing the footpath to twist.  Here, though, travel "+
     "is smoother, and the trees recede into the background, allowing a full "+
     "view of the %^BOLD%^%^CYAN%^sky%^RESET%^.  The %^BOLD%^%^BLUE%^trail "+
     "%^RESET%^here is wide and not very well-defined, as the grass has "+
     "grown over most of it, but it seems safe enough.  Strange %^ORANGE%^cairns "+
     "%^RESET%^are partially hidden within the grass along the trail."
   );
   set("night long",
      "%^BOLD%^%^GREEN%^The foothills of Echoes Mountains rise and fall "+
      "all around here, but a wide, well-worn footpath navigates over "+
      "them easily.  In the %^YELLOW%^moonlight%^GREEN%^, the tall grass "+
      "glows %^WHITE%^silvery %^GREEN%^green and seems to push back the "+
      "ominious shadows created by the tall %^RESET%^%^GREEN%^evergreens "+
      "%^BOLD%^and %^BOLD%^%^BLACK%^boulders %^GREEN%^higher up the "+
      "mountainside.  The wide night sky is expansive, and the lack of trees "+
      "and boulders makes the foothills here easy to navigate.  Small "+
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
      (({"evergreen","evergreens","trees"})) : "All the evergreens are "+
         "higher on the mountain, leaving the area here with a clear "+
         "view of the sky.",
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

}
