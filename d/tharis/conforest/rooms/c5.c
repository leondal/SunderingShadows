#include <std.h>
#include "../defs.h"
inherit HEALER;

void create()
{
  ::create();
   set_property("fill waterskin",1);
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^A Beautiful Garden%^RESET%^");
  set_long("In front of a large, still lake lies a "+
	"gently bubbling spring.  Around the edges of "+
	"the spring are dozens of brightly colored flowers.  The "+
	"garden is divided by both type of flower and color.  Each "+
	"flower is beautiful by itself, but the garden as a whole is "+
	"breathtaking.  A small sign leans against a nearby tree.");
  set_smell("default","The various fragrances from the garden blend "+
	"pleasantly together.");
   set_listen("default","Splashing water echoes through the trees as the "+
	"spring bubbles gently.");
  set_items(
    ([
    "spring":"A small spring, about 4 feet in diameter, is steadily "+
	"bubbling.  Along the edges is a large, circular flower garden.",
    ({"garden","flower","flowers"}):"Several species of flowers sprout "+
	"out from the neatly tended earth.  The soil is dark and moist, "+
	"allowing the plants to grow healthy and firm.  Some of the "+
	"blooms are among the largest you have ever seen.",
    "lake":"A gentle fog hangs over the still waters.  Across the "+
	"lake, the forest rises up along the side of a mountain range.",
    "sign":"For healing supplies, you can <%^YELLOW%^read list%^RESET%^>.  "+
 	"To purchase flowers, just type <%^YELLOW%^list%^RESET%^>."
    ]) );
  set_exits(
    ([
    "north" : ROOMS+"c7",
    "south" : ROOMS+"c3",
    "west" : ROOMS+"c4"
    ]) );
  set_name("Deladrenia");
  if(query_night() == 1)
  {
  set_cl_price(30);
  set_cs_price(60);
  set_cc_price(150);
  set_np_price(225);
  set_bp_price(90);
  set_cb_price(150);
  }
  else
  {
  set_cl_price(20);
  set_cs_price(45);
  set_cc_price(100);
  set_np_price(150);
  set_bp_price(60);
  set_cb_price(225);
  }
}
void reset()
{
  ::reset();
  if(!present("deladrenia")) 
  {
    new(MONS+"deladrenia")->move(this_object());
  }
}

void init() {
  ::init();
  add_action("drink_fun","drink");
}

int drink_fun(string str) {
   if(!str) return 0;
   if(str == "water from lake" || str == "water from the lake") {
     if(!TP->add_quenched(20)) {
       return notify_fail("Your stomach is sloshing already!\n");
     }
     tell_object(TP,"You crouch down and drink some water from the lake.");
     tell_room(TO,TPQCN+" crouches down to drink some water from the lake.",TP);
     return 1;
   }
   if(str == "water from spring" || str == "water from the spring") {
     if(!TP->add_quenched(20)) {
       return notify_fail("Your stomach is sloshing already!\n");
     }
     tell_object(TP,"You cup your hands to catch some water from the spring.  It's nice and cool to drink.");
     tell_room(TO,TPQCN+" cups "+TP->QP+" hands to catch some water from the spring to drink.",TP);
     return 1;
   }
   return notify_fail("You could probably try to drink water from the lake or spring.\n");
}
