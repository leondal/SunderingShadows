#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("Melkior's Crystals");
   set_short("%^RESET%^%^GREEN%^Melkior's Crystals");
   set_long("%^RESET%^%^GREEN%^Melkior's Crystals%^RESET%^\n"+
      "This shop is circular in design, matching the workroom "+
      "below.  Its curved %^GREEN%^cry%^BOLD%^st%^RESET%^"+
      "%^GREEN%^alli%^BOLD%^n%^RESET%^%^GREEN%^e walls "+
      "%^RESET%^feature carved recesses fitted with clear "+
      "%^BOLD%^%^CYAN%^glass drawers%^RESET%^.  Within each, "+
      "%^BOLD%^%^RED%^m%^MAGENTA%^y%^YELLOW%^r%^GREEN%^i%^CYAN%^a"+
      "%^RED%^d %^BLUE%^c%^BLACK%^r%^MAGENTA%^y%^YELLOW%^s%^RED%^t"+
      "%^GREEN%^a%^CYAN%^l%^WHITE%^s %^RESET%^rest for sale, "+
      "each draw holding a different type, cut, and color.  "+
      "Echoing the bowed walls is the simple round %^BOLD%^%^CYAN%^cr"+
      "%^RESET%^%^CYAN%^ys%^BOLD%^tal-topped table %^RESET%^in "+
      "the center.  It features four %^BOLD%^%^BLACK%^iron chairs %^RESET%^with "+
      "%^RED%^deep cr%^BOLD%^i%^RESET%^%^RED%^mson%^RESET%^ cushions where "+
      "a customer might relax while doing business.\n\n"+
      "%^RESET%^<help shop> will give you help on how to use the shop.\n");
   set_listen("default","The low moan of the wind breaks the silence.");
   set_smell("default","A light fragrance of ozone resides in the air here.");
   set_items( ([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^GREEN%^"+
         "The smooth walls and floor of this building are carved from "+
         "smooth crystal, translucent and pure.  They are almost "+
         "soft to the touch, and the floor seems to muffle the sound "+
         "of footsteps, almost as if absorbing them.  The walls of "+
         "this room are curved to make a perfect circle.%^RESET%^",
      ({"table","tables","chair","chairs"}) : "%^CYAN%^The tables are "+
         "made with %^BOLD%^%^BLACK%^wrought iron bases %^RESET%^"+
         "%^CYAN%^fashioned into swirls and topped with %^BOLD%^azure "+
         "crystal%^RESET%^%^CYAN%^.  The two chairs bracing each "+
         "table are likewise made of %^BOLD%^%^BLACK%^iron %^RESET%^"+
         "%^CYAN%^and fitted with %^RED%^deep cr%^BOLD%^i%^RESET%^"+
         "%^RED%^mson%^RESET%^%^CYAN%^ cushions.%^RESET%^",
      ({"stairs","staircase"}) : "%^RESET%^%^GREEN%^The cry%^BOLD%^st%^RESET%^"+
         "%^GREEN%^alli%^BOLD%^n%^RESET%^%^GREEN%^e staircase is "+
         "made of the same material as the walls of the building.  A "+
         "%^BOLD%^velvet rope %^RESET%^%^GREEN%^has been placed "+
         "around it so that customers do not fall.%^RESET%^",
      ({"drawer","drawers","glass drawers","crystals"}) : "Each of the "+
         "glass drawers is filled with crystals that are pre-sorted "+
         "for ease of location.  Some of the drawers stand empty, "+
         "likely waiting on a new shipment, as it doesn't seem any "+
         "of the crystals are actually cut here."
    ]));
    set_exits(([
        "down" : "/d/dagger/tonovi/town/cguilds/psions/workroom"
    ]));
}

void reset(){
   ::reset();
   if(!present("melkior")) {
      find_object_or_load("/d/dagger/tonovi/mon/melkior")->move(TO);
   }
}
