//inn_common.c by ~Circe~ 12/22/15
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_name("Common Quarters of the Tropical Breeze Inn, Seneca");
   set_short("%^BOLD%^%^MAGENTA%^Common Quarters of the Tropical Breeze Inn, Seneca%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Common Quarters of the Tropical Breeze Inn, Seneca%^RESET%^\n"+
      "A wide archway in the northern wall leads to the %^ORANGE%^stairway%^RESET%^ "
      "winding through the %^BOLD%^%^MAGENTA%^Tropical Breeze%^RESET%^. This room "
      "features the same %^BOLD%^st%^RESET%^o%^BOLD%^ne fl%^RESET%^o%^BOLD%^or"
      "%^RESET%^ as the rest of the inn, and the beds are crafted from unfinished "
      "%^BOLD%^driftwood %^RESET%^that matches the bannister. Each bed is made up "
      "with a simple set of %^RESET%^%^CYAN%^cotton sheets %^RESET%^and a thin "
      "%^CYAN%^b%^BOLD%^l%^RESET%^%^GREEN%^a%^BOLD%^n%^BLUE%^k%^RESET%^%^CYAN%^e"
      "%^BOLD%^t%^RESET%^ perfect for the tropical weather. Though the room offers "
      "little privacy, each rental gives the guest access to a locked %^BOLD%^%^BLACK%^"
      "iron-bound chest%^RESET%^ at the end of the bed. Guests may also wash away the "
      "dust and weariness of travel at one of the two %^ORANGE%^wash stands%^RESET%^ "
      "bracing the archway. Wide open %^BOLD%^%^BLUE%^windows%^RESET%^ set into the "
      "southern wall offer a view of the rooftops of %^YELLOW%^Seneca%^RESET%^, with "
      "the faintest glimmer of the %^BOLD%^%^CYAN%^ocean%^RESET%^ in the distance.\n");
   set_smell("default","The light fragrance of the sea seems to linger here.");
   set_listen("default","The soft murmur of conversation rises from the floor below.");
   set_items(([
      ({"floor","stone"}) : "The stone floor is made up of "+
         "locally quarried %^BOLD%^st%^RESET%^o%^BOLD%^ne %^RESET%^"+
         "fashioned into irregularly shaped tiles.  A faintly "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
         "%^RESET%^n grout fits the tiles together, making the "+
         "floor smooth.",
      ({"globe","globes","glass globe","glass globes"}) : "The "+
         "globes are made of blown glass in shades of %^BOLD%^%^BLUE%^"+
         "blue %^RESET%^and %^BOLD%^%^GREEN%^green%^RESET%^, "+
         "reminiscent of the %^CYAN%^sea%^RESET%^ while the softly "+
         "glowing %^BOLD%^white light %^RESET%^brings to mind "+
         "images of whitecaps.  They do not have any sort of flame "+
         "within, but seem to have been enchanted to provide "+
         "illumination.",
      ({"bannister","driftwood","driftwood bannister"}) : "The roughly finished "+
         "bannister is worn smooth in places from countless hands.  It is "+
         "bleached white from the sun, echoing the floor tiles.",
      ({"bed","beds","sheets","blanket","blankets"}) : "Each bed is built on a "
         "simple driftwood frame and fitted with a comfortable mattress of a "
         "higher quality than that seen in many inns. The sheets are soft "
         "cotton, and the woolen blankets are thin enough for the climate. "
         "Each is dyed a shade of %^CYAN%^bl%^BOLD%^u%^RESET%^%^CYAN%^e %^RESET%^or "
         "%^GREEN%^gr%^CYAN%^e%^GREEN%^en%^RESET%^ reminiscent of the ocean.",
      ({"window","windows"}) : "The windows in the southern wall are wide and "
         "open to the elements, though they do have painted shutters that can be "
         "closed in case of inclement weather. Peering through the windows gives "
         "you a great view of the tiled rooftops of Seneca, as well as the faint "
         "sheen of the ocean in the distance.",
      ({"shutter","shutters"}) : "The wooden shutters are solid oak painted a "
         "deep %^BLUE%^midnight blue%^RESET%^. They could be pulled closed if necessary.",
      ({"stand","stands","wash stand","wash stands"}) : "The wash stand to the "
         "left of the archway is painted a cheery %^YELLOW%^yellow %^RESET%^while "
         "its counterpart is %^BOLD%^%^CYAN%^sky blue%^RESET%^. Each has a "
         "%^BOLD%^ceramic basin %^RESET%^and %^BOLD%^pitcher %^RESET%^filled "
         "with %^CYAN%^clean water %^RESET%^so that guests may wash themselves "
         "without waiting for the lavatory. Several cakes of soap shaped like "
         "%^BOLD%^se%^CYAN%^a%^WHITE%^she%^RESET%^l%^BOLD%^ls %^RESET%^are arranged "
         "in a small dish, and a shelf below the basin holds %^BOLD%^%^BLUE%^hand "
         "towels%^RESET%^. If you choose, you could %^BOLD%^%^CYAN%^wash %^RESET%^in the basin."
   ]));
   set_exits(([
      "north" : ROOMS"inn_stairs"
   ]));
}

void init(){
   ::init();
   add_action("wash_em","wash");
}

int wash_em(string str){
   if(!str){
      tell_object(TP,"You might want to try washing in the basin.");
      return 1;
   }
   if(str == "in basin" || str == "in the basin"){
      tell_object(TP,"Using the soap and lukewarm water, you scrub your "+
         "face and wash your hands, then rinse throroughly.  You dry "+
         "your hands and face on one of the warm towels on the shelf.  "+
         "Ahh...much better.  It feels good to get rid of that grime.");
      tell_room(ETP,""+TPQCN+" washes "+TP->QP+" face and hands in "+
         "the basin.",TP);
      TP->set("long");
      return 1;
   }
   tell_object(TP,"You want to wash where??");
   return 1;
}