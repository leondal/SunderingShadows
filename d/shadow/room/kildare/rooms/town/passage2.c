//passage2.c
#include <std.h>
#include "../../kildare.h"

inherit VAULT;

int items;
object ob;
string str;

void create()
{
items = 1;
   ::create();
   set_indoors(1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Small bedchamber");
   set_short("A bedchamber");
   set_long(
      "A small wooden door in the southern wall opens into this comfortable "+
      "bedchamber.  It is not lavishly decorated, but all the furnishings "+
      "look to be very well-made and cared-for.  A narrow bed set in the "+
      "northwestern corner has a light green rug laid out before it, while "+
      "the dresser across the room is topped by a long, crocheted doily.  "+
      "Everything in the room seems to be set a little lower than normal "+
      "for a human, as if the person who uses this room is either smaller "+
      "than the average man or cannot reach very high for some reason.  A "+
      "pot-bellied wood-burning stove stands in the southerwestern corner, "+
      "just beside a bookshelf.  There seems to be no chair in this room, "+
      "despite the small writing desk near a window on the northern wall."

   );
   set_items(([
      (({"rug","green rug"})) : "%^GREEN%^The rectangular rug in front "+
         "of the narrow bed is a light green color and has strange "+
         "tracks across it.  The tracks are about an inch wide each, "+
         "and the pair of them seems to run parallel to each other.",
      (({"bed","narrow bed"})) : "The narrow bed in the corner is "+
         "low to the ground.  It is covered with a cream-colored "+
         "blanket that blends well with the light green rug on the floor.",
      (({"dresser","doily","crocheted doily"})) : "%^BOLD%^A stark white, "+
         "intricate doily tops the simple wooden dresser on the eastern "+
         "wall.  The dresser has six drawers, all of which are neatly closed.",
      (({"stove","wood-burning stove","pot-bellied stove"})) : "%^BOLD%^%^BLACK%^A "+
         "rounded wood-burning stove made of iron sits in the southwestern "+
         "corner of the room, providing warmth and light.",
      (({"bookshelf","bookshelves","shelves","shelf"})) : "The wooden bookcase "+
         "standing by the stove has only two shelves and is filled with "+
         "old tomes.  A glance at the titles reveals that they seem to "+
         "be collections of lore about the dread perytons which are now "+
         "plaguing Kildare Glen.",
      (({"desk","writing desk"})) : "%^ORANGE%^The low writing desk along "+
         "the northern wall has two drawers and a smooth top for writing."
      ]));
   set_smell("default","The scent of burning wood fills the room.");
   set_listen("default","The quiet crackle of the flames is in the air.");
   set_search("drawer", (: TO, "search_desk" :) );
   set_search("drawers", (: TO, "search_desk" :) );
   set_search("desk", (:TO, "search_desk" :) );

   set_exits(([
      "south" : TROOMS"passage1"
      ]));
   set_door("small door",TROOMS"passage1","south","caldon room_key");
   set_door_description("small door","The small door is well-made and "+
      "very sturdy.  The brass doorknob has a small keyhole.");
   set_locked("small door",1,"lock");
   lock_difficulty("small door",20,"lock");
}

void search_desk() 
{
  if((items > 0)) { 
       switch(random(4)){
             case 0:
                    write("You search through the drawers of the desk but "+
                       "don't find anything of interest.");
                    tell_room(ETP,""+TPQCN+" searches through the desk "+
                       "drawers but doesn't seem to find anything.",TP);
                    break;
             case 1..2:
                    write("You search through the drawers and find a "+
                       "sheet of blank paper.");
                    tell_room(ETP,""+TPQCN+" searches through the desk "+
                       "drawers and finds some paper.",TP);
                    new("/d/tharis/obj/paper.c")->move(TO);
                    break;
             case 3:
                    write("Searching the desk, you find a nice writing quill.");
                    tell_room(ETP,""+TPQCN+" searches the desk drawers and "+
                       "finds a nice looking quill.",TP);
                    new(OBJ"quill.c")->move(TO);
                    break;
           }
           items = 0;
           return;
   }
       else {
         write("You find nothing of interest this time.");
         tell_room(ETP,""+TPQCN+" seems to be disappointed "+
            "from searching the desk.",TP);
         items = 0;
       }         
}
