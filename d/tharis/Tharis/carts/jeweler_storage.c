#include <std.h>
#define OBJ "/d/tharis/obj/rings/"+
inherit ROOM;

void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
    set_property("no teleport",1);
    set_short("Yseult's Storage Room");
    set_long("Various metals and gems are stored here.  You, "+
       "however, should not be here.");
}
void reset() {
::reset();
   if(!present("bronze torque"))
	new(OBJ"bronze_torque")->move(TO);
   if(!present("fairy tale"))
	new(OBJ"fairy_tale")->move(TO);
   if(!present("peacock brooch"))
	new(OBJ"peacock_brooch")->move(TO);
   if(!present("golden roses"))
	new(OBJ"rose_anklet")->move(TO);
   if(!present("bangle bracelet"))
      new(OBJ"bangle_bracelet")->move(TO);
   if(!present("braided bracelet"))
      new(OBJ"braided_bracelet")->move(TO);
   if(!present("luxurious pendant"))
      new(OBJ"pendant_royal")->move(TO);
   if(!present("three-stone pendant"))
      new(OBJ"pendant_three")->move(TO);
   if(!present("claw earrings"))
      new(OBJ"claw_earrings")->move(TO);
   if(!present("coiffe"))
      new(OBJ"coiffe")->move(TO);
   if(!present("fibula"))
      new(OBJ"fibula")->move(TO);
   if(!present("ring brooch"))
      new(OBJ"ring_brooch")->move(TO);
}
