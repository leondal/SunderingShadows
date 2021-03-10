//comp shop for the planar enclave ~Circe~ 10/27/08
#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("Empyreal Crystals");
   set_short("%^RESET%^%^MAGENTA%^Empyreal Crystals");
   set_long("%^RESET%^%^MAGENTA%^Empyreal Crystals%^RESET%^\n"+
      "This shop is circular in design, matching the workroom "+
      "below.  Its curved %^MAGENTA%^cry%^BOLD%^st%^RESET%^"+
      "%^MAGENTA%^alli%^BOLD%^n%^RESET%^%^MAGENTA%^e walls "+
      "%^RESET%^feature carved recesses fitted with clear "+
      "%^BOLD%^%^CYAN%^glass drawers%^RESET%^.  Within each, "+
      "%^BOLD%^%^RED%^m%^MAGENTA%^y%^YELLOW%^r%^GREEN%^i%^CYAN%^a"+
      "%^RED%^d %^BLUE%^c%^BLACK%^r%^MAGENTA%^y%^YELLOW%^s%^RED%^t"+
      "%^GREEN%^a%^CYAN%^l%^WHITE%^s %^RESET%^rest for sale, "+
      "each draw holding a different type, cut, and color.  "+
      "Echoing the bowed walls is the simple round %^BOLD%^%^CYAN%^cr"+
      "%^RESET%^%^CYAN%^ys%^BOLD%^tal-topped table %^RESET%^in "+
      "the center.  It features four %^BOLD%^%^BLACK%^iron chairs %^RESET%^with "+
      "%^YELLOW%^c%^GREEN%^o%^CYAN%^l%^BLUE%^o%^MAGENTA%^r%^RED%^f"+
      "%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^l%^CYAN%^l%^GREEN%^y "+
      "%^YELLOW%^s%^RESET%^%^ORANGE%^t%^BOLD%^r%^RESET%^%^ORANGE%^i"+
      "%^BOLD%^p%^RESET%^%^ORANGE%^e%^BOLD%^d cushions%^RESET%^ where "+
      "a customer might relax while doing business.\n\n"+
      "%^RESET%^<help shop> will give you help on how to use the shop.\n");
   set_listen("default","The low moan of the wind breaks the silence.");
   set_smell("default","A light fragrance of ozone resides in the air here.");
   set_items( ([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^MAGENTA%^"+
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
         "%^CYAN%^and fitted with "+
         "%^YELLOW%^c%^GREEN%^o%^CYAN%^l%^BLUE%^o%^MAGENTA%^r%^RED%^f"+
         "%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^l%^CYAN%^l%^GREEN%^y "+
         "%^YELLOW%^s%^RESET%^%^ORANGE%^t%^BOLD%^r%^RESET%^%^ORANGE%^i"+
         "%^BOLD%^p%^RESET%^%^ORANGE%^e%^BOLD%^d cushions%^RESET%^%^CYAN%^."+
         "%^RESET%^",
      ({"stairs","staircase"}) : "%^RESET%^%^MAGENTA%^The cry%^BOLD%^st%^RESET%^"+
         "%^MAGENTA%^alli%^BOLD%^n%^RESET%^%^MAGENTA%^e staircase is "+
         "made of the same material as the walls of the building.  A "+
         "%^BOLD%^velvet rope %^RESET%^%^MAGENTA%^has been placed "+
         "around it so that customers do not fall.%^RESET%^",
      ({"drawer","drawers","glass drawers","crystals"}) : "Each of the "+
         "glass drawers is filled with crystals that are pre-sorted "+
         "for ease of location.  Some of the drawers stand empty, "+
         "likely waiting on a new shipment, as it doesn't seem any "+
         "of the crystals are actually cut here."
    ]));
    set_exits(([
        "down" : "/d/shadow/room/city/portal/workroom"
    ]));
}

void reset(){
   ::reset();
   if(!present("andrei")) {
      find_object_or_load("/d/shadow/mon/andrei")->move(TO);
   }
}
