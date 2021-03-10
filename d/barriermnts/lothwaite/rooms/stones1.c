//stones1.c - Footpath to ring of stones.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"
inherit ROOM;

void create(){
   ::create();
   set_indoors(0); 
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("A worn footpath");
   set_short("A worn footpath");
   set_long("%^ORANGE%^This narrow footpath seems to have been "+
      "worn over time by countless firbolgs going to visit the "+
      "%^RESET%^ring of stones %^ORANGE%^just to the southeast.  "+
      "Sparse %^GREEN%^grass %^ORANGE%^grows along the edges of "+
      "the path, which has been left dirt rather than being "+
      "paved in any way.  The path travels northwest to the well-made "+
      "%^BOLD%^%^BLACK%^flagstone path %^RESET%^%^ORANGE%^that leads "+
      "to the chapel and southeast to the %^RESET%^ring of stones"+
      "%^ORANGE%^.\n");
   set_items(([
      ({"path","pathway"}) : "%^BOLD%^%^BLACK%^The flagstone pathway "+
         "is made of fantastic slate the color of a moonlit night sky.  "+
         "The stones have been perfectly fitted together and not a single "+
         "blade of grass peeks through.  Unlike the rustic feel of the "+
         "rest of the village, this pathway seems to convey a feeling "+
         "of solemnity.%^RESET%^",
      ({"footpath","foot path","dirt path"}) : "The path here is simple "+
         "and rustic.  It has been worn over the years by the feet "+
         "of countless firbolg visitors to the ring of stones.",
      "grass" : "Only a few blades of grass grow alongside the path.",
      ({"ring of stones","stones","ring"}) : "To the southeast stands an open "+
         "field with a ring of stones, each of which stand well over "+
         "30 feet high.  They stand proudly against the sky, and you "+
         "cannot go further without entering the ring of stones."
   ]));
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","The sound of the wind muffles most other noises in the valley.");
   set_exits(([
      "northwest" : PATHEXIT"chapel2",
      "southeast" : PATHEXIT"stones2"
   ]));
   set_pre_exit_functions(({"southeast"}),({"enterring"}));
}

int enterring(){
   if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 0;
   }
   tell_object(TP,"A feeling of solemnity settles over you as you "+
      "step between two stones and enter the circle.");
   if(!TP->query_invis()){
      tell_room(TO,""+TPQCN+" steps between two stones and enters "+
         "the ring of stones.",TP);
   }
   return 1;
}