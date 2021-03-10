//barracks_women - Barracks for new Seneca
//~Circe~ 12/7/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Women's Dormitory of the Guard Barracks, Seneca");
   set_short("%^BOLD%^%^WHITE%^Women's Dormitory of the Guard Barracks, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Women's Dormitory of the Guard Barracks, Seneca%^RESET%^\n"+
      "Running north and south, this long room has been filled with "+
      "rows of %^ORANGE%^bunkbeds%^RESET%^ with thin %^BOLD%^"+
      "mattresses%^RESET%^.  Each bed features a neatly tucked %^BLUE%^"+
      "blue blanket %^RESET%^and a pair of %^BOLD%^%^BLACK%^footlockers "+
      "%^RESET%^at the end.  Additionally, each bed has a narrow "+
      "%^ORANGE%^shelf %^RESET%^in place of a headboard where "+
      "guardsmen may stow small items.  The %^RED%^brick walls "+
      "%^RESET%^are unbroken on all sides, save by the %^ORANGE%^"+
      "wooden door %^RESET%^set within a protruding %^ORANGE%^"+
      "wooden wall %^RESET%^on the southern end that leads to a "+
      "small %^ORANGE%^staircase%^RESET%^.  Taking a quick "+
      "count, you realize that fewer women must live in the "+
      "barracks than men.\n");
   set_smell("default","The clean fragrance of the ocean is masked somewhat by the aroma of soldiers.");
   set_listen("default","Chatter from the guardsmen mixes with the noise of Seneca.");
   set_items(([
      ({"beds","bunkbeds","bed","bunkbed"}) : "Each bunkbed is quite "+
         "narrow and fitted with a thin mattress.  Still, each looks "+
         "clean and well-tended, and it is obvious that the health and "+
         "care of the guardsmen is as important as the job they do.",
      ({"blanket","blankets"}) : "%^BLUE%^Each blanket is made from "+
         "blue wool.  They are far from soft, though they are - "+
         "thankfully - not the scratchiest either.  Each has been "+
         "pulled taut and tucked in neatly, turned back and ready for "+
         "the bed's occupant to return after a hard day's work.%^RESET%^",
      ({"locker","lockers","footlocker","footlockers"}) : "%^BOLD%^"+
         "%^BLACK%^Each of the footlockers is crafted from blackened "+
         "wood and set with an iron lock.  None of them are open, and "+
         "each lock is securely fastened.  A pair of the small "+
         "rectangular lockers sits at the foot of each bunkbed.%^RESET%^",
      "shelf" : "The narrow shelf at the head of each bed is a place "+
         "for guardsmen to store small items.  Some have trinkets "+
         "lying there, but you notice that most are only in use when "+
         "the guardsman is in the bed asleep.",
      ({"wall","walls","brick","brick walls"}) : "The walls are plain %^RED%^red "+
         "brick %^RESET%^and unadorned.  They do little to make this "+
         "room more comfortable, but they do seem sturdy.",
   ]));
   set_exits(([
      "down" : ROOMS"barracks_common1"
   ]));
   set_door("stairway door","/d/attaya/newseneca/rooms/barracks_common1","down",0,0);
   set_door_description("stairway door","The door at the top of the stairs "+
      "is narrow and wooden with only a small brass handle.");
}