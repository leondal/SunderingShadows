//forestpaths.c - near the paths

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_short("%^GREEN%^Sparse forest%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
   set_long( (: TO, "ldesc" :) );
   set_smell("default","The air smells fresh and clean.");
   set_listen("default","You hear crickets and birds chirping.");
   set_items( ([ 
      ({"trees","pine trees"}): "%^CYAN%^The trees are a little thinner here near the edge of the forest.", 
      ({"ivy", "ferns", "undergrowth"}):"%^GREEN%^The ivy is a dark green and ferns more plentiful.%^RESET%^", 
     "path":"%^ORANGE%^This part of the path seems to be more heavily traveled.%^RESET%^" 
   ]) );
}

string ldesc(string str) {
   return("This area of the forest is even more sparse in vegetation.  "
     "%^CYAN%^Long-needled pine trees %^RESET%^tower over other smaller "
     "evergreens and a few deciduous trees including oaks and sassafras.  Pine "
     "needles and fallen leaves cushion your steps but twigs interspersed with "
     "them frequently snap underfoot as you walk along.  The acidic soil from "
     "the decaying vegetable matter limits the undergrowth to a few varieties "
     "of %^GREEN%^ivy and ferns%^RESET%^.  The trees seem to be thinning and "
     "there is a more heavily traveled %^ORANGE%^path %^RESET%^here.");
}