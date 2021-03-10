//house4.c - Coded by Circe 1/1/04
#include <std.h>
inherit VAULT; 

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("A quaint house"); 
   set_short("A quaint house"); 
   set_long( (: TO, "ldesc" :) );
   set_smell ("default","The light frangrance of wildflowers fills the air.");
   set_listen ("default","You can hear the trees whistling with a light breeze outside."); 
   set_items(([ 
      "couch" : "%^MAGENTA%^The couch is a deep maroon with %^RESET%^"+
         "light gray stripes%^MAGENTA%^.  It is wide and looks quite "+
         "comfortable, although it has become a little threadbare over "+
         "the years.  It, like the rest of the house, seems well-cared-"+
         "for, though.",
      ({"fireplace","fire","fire place"}) : "The fireplace set within "+
         "the northern wall burns with a %^RED%^bright fire%^RESET%^ "+
         "year round.  It provides light and fuel for cooking, although "+
         "it can become a bit warm in the summer.  The fireplace is made "+
         "of plain gray stone.",
      ({"table","end table"}) : "A simple wooden table stands beside the "+
         "couch.  It is made of a light blonde wood and looks to have been "+
         "hand carved.  It is rather rustic, but has been highly polished.  "+
         "A cut glass vase rests on top of it, holding %^YELLOW%^w%^MAGENTA%^i"+
         "%^RED%^l%^BLUE%^d%^CYAN%^f%^GREEN%^l%^YELLOW%^o%^MAGENTA%^w%^RED%^"+
         "e%^BLUE%^r%^CYAN%^s%^RESET%^.",
      ({"vase","flowers","wildflowers"}) : "The cut glass vase looks a little "+
         "out of place in the room, as it is of very high quality.  It has been "+
         "cut in the manner of crystal and sparkles in the light.  It holds a "+
         "fantastic bouquet of %^YELLOW%^w%^MAGENTA%^i"+
         "%^RED%^l%^BLUE%^d%^CYAN%^f%^GREEN%^l%^YELLOW%^o%^MAGENTA%^w%^RED%^"+
         "e%^BLUE%^r%^CYAN%^s%^RESET%^.",
      ({"doorway","hall","rooms","doors"}) : "The narrow hallway leading to "+
         "the east is carpetted with a light gray rug.  The rug is a little "+
         "more narrow than the hallway, revealing highly polished wood on "+
         "either side.  Both of the doorways are closed, but you would assume "+
         "those are probably bedrooms.",
      ({"counter","kitchen","utensils"}) : "The small kitchen to the south has "+
         "been painted bright yellow and holds all the tools the family needs "+
         "for cooking and eating meals.  There are a few stools at the counter, "+
         "and it seems likely they take their meals there."
   ]));
   set_exits(([
      "west" : "/d/koenig/fields/room/house3",
   ]));
   set_door("door","/d/koenig/fields/room/house3","west",0);
   set_door_description("door","A simple wooden door set with a "+
      "small window near the top.");
}

void init(){
   ::init();
   if(!present("alonso")){
      new("/d/koenig/mon/alonso")->move(TO);
   }
}

string ldesc() {
   if(query_night()) {
     return(
      "This small wooden house is quaint but comfortable.  "+
      "A long, low %^MAGENTA%^couch %^RESET%^rests before a "+
      "%^YELLOW%^fireplace %^RESET%^set within the northern wall.  "+
      "An %^ORANGE%^end table %^RESET%^just beside it holds a "+
      "%^BOLD%^%^BLUE%^vase %^RESET%^filled with %^YELLOW%^w%^MAGENTA%^i"+
      "%^RED%^l%^BLUE%^d%^CYAN%^f%^GREEN%^l%^YELLOW%^o%^MAGENTA%^w%^RED%^"+
      "e%^BLUE%^r%^CYAN%^s%^RESET%^.  To the east, an empty doorway "+
      "leads down a short hall, and two rooms break off from the hall, "+
      "though their doors are closed.  A long %^YELLOW%^counter %^RESET%^"
      "to the south separates this living room from the kitchen, which has "+
      "been painted a %^YELLOW%^cheery yellow %^RESET%^and holds all the "+
      "utensils the family would need for cooking.  The curtains have been "+
      "pulled closed against the night, and a fire provides the only light "+
      "in the room.\n"
     );
   } else {
     return(
      "This small wooden house is quaint but comfortable.  "+
      "A long, low %^MAGENTA%^couch %^RESET%^rests before a "+
      "%^YELLOW%^fireplace %^RESET%^set within the northern wall.  "+
      "An %^ORANGE%^end table %^RESET%^just beside it holds a "+
      "%^BOLD%^%^BLUE%^vase %^RESET%^filled with %^YELLOW%^w%^MAGENTA%^i"+
      "%^RED%^l%^BLUE%^d%^CYAN%^f%^GREEN%^l%^YELLOW%^o%^MAGENTA%^w%^RED%^"+
      "e%^BLUE%^r%^CYAN%^s%^RESET%^.  To the east, an empty doorway "+
      "leads down a short hall, and two rooms break off from the hall, "+
      "though their doors are closed.  A long %^YELLOW%^counter %^RESET%^"
      "to the south separates this living room from the kitchen, which has "+
      "been painted a %^YELLOW%^cheery yellow %^RESET%^and holds all the "+
      "utensils the family would need for cooking.\n"
     );
   }
}
