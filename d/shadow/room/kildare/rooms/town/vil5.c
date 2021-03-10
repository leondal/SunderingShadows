//vil5.c
#include <std.h>
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_property("no sticks",1);
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^A Simple Stone Building
%^RESET%^%^ORANGE%^This large stone room has been divided into several 
smaller rooms by curtains hung on wires strung from wall to 
wall.  A curtain along the west wall has been pulled back, and 
through it, three small mattresses on the floor can be seen.  
Each has a set of flannel sheets with a woolen blanket folded 
at its foot.  A shelf runs above the beds, holding clothes of 
several different sizes.  A similar curtain on the east only 
partially conceals a large wooden bed.  A metal chest is open 
at the foot of the bed and seems to hold only clothes.  A table 
surrounded by chairs stands near the fireplace in the northern 
wall not far from a door.  A tall cupboard on the other side of 
the door is open and holds many different plates, cups, and 
untensils.
CIRCE
   );
   set_items(([
      (({"stone","wall","floor"})) : "This building is made of the "+
         "dark gray stone of the mountain.  The floor is kept clean and "+
         "everything seems put away neatly.",
      (({"curtain","curtains","rooms"})) : "Light gray woolen curtains divide "+
         "the room into three sections.  Each has been pulled back, but they "+
         "would close to allow privacy for the occupants.",
      (({"mattresses","mattress","small mattresses"})) : "The western section "+
         "of the large room contains three small mattresses stuffed with rushes "+
         "lying upon the floor.  Each has a set of flannel sheets neatly tucking in "+
         "as well as a small pillow and a woolen blanket.",
      "shelf" : "The shelf above the small mattresses holds clothing that looks "+
         "like it might belong to several children of different sizes.  Woolen "+
         "sweaters are folded among leather breeches and a few small dresses.",
      (({"bed","wooden bed","large wooden bed","large bed"})) : "The eastern "+
         "portion of the room holds a large wooden bed frame topped by a mattress "+
         "filled with rushes.  The headboard is carved with images of nightingales "+
         "standing beside a river.",
      (({"chest","metal chest"})) : "The metal chest is open and reveals clothing "+
         "for what seems to be two people.  Folded neatly inside are pants, dresses, "+
         "shirts, and two cloaks.",
      (({"table","chairs"})) : "Near the northern wall, there is a large circular "+
         "table made from pine.  The legs are delicately carved and the table seems "+
         "fairly new.  There are six chairs surrounding the table.",
      (({"fireplace","fire place"})) : "The stone fireplace is set into the north "+
         "and fitted with an iron grate.  Behind the grate is a hook that holds a "+
         "large cauldron full of a lightly bubbling stew.",
      (({"cupboard","plates","cups","utensils"})) : "The tall wooden cupboard has "+
         "two wooden doors that can be closed to hide the clutter within.  Now, "+
         "though, it stands open and reveals stacks of plates, cups, and a tray "+
         "of forks, spoons, and knives, all stack on shelves."
      ]));

   set_exits(([
      "north" : TROOMS"vil7",
      "southeast" : TROOMS"path12"
      ]));
   set_door("back door",TROOMS"vil7","north",0);
   set_door("pine door",TROOMS"path12","southeast",0);

}
void reset()
{
        ::reset();
        if(!present("thalia")) {
                new(MON"thalia")->move(TO);
        }
}
