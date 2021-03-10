//Octothorpe (1/24/09)
//Underdark Mining Caverns, Kobold Cavern Master Room Inherit

#include <std.h>
#include "../defs.h"
inherit CROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",0);
   set_property("no teleport",1);
   set_travel(SLICK_FLOOR);
   set_terrain(NAT_TUNNEL);

   set_name("%^BOLD%^A d%^CYAN%^a%^BOLD%^%^WHITE%^mp passageway"+
      "%^RESET%^");
   set_short("%^BOLD%^A d%^CYAN%^a%^BOLD%^%^WHITE%^mp passageway"+
      "%^RESET%^");
   set_long("%^BOLD%^A d%^CYAN%^a%^BOLD%^%^WHITE%^mp passageway"+
      "%^RESET%^\n "+
      "%^BOLD%^Rivulets of %^RESET%^%^CYAN%^wa%^RESET%^t%^BOLD%^%^CYAN%^"+
      "er %^WHITE%^stream down cracks in the limestone, creating a "+
      "tiny stream in the middle of the passage. Due to the drainage, "+
      "the walls of the tunnel have been worn to a smooth patina. In "+
      "someplaces however, small ripples are found in the limestone. "+
      "Scrawled on the dry patches of limestone are a series of crude "+
      "paintings. This tunnel slopes gradually, causing the path ahead "+
      "to descend deeper into the depths of the earth.%^RESET%^\n");
   set_items(([
      ({"rivulets","water","rivulets of water","stream"}):"%^RESET%^"+
         "%^CYAN%^Wa%^RESET%^t%^BOLD%^%^CYAN%^er %^WHITE%^seeps through "+
         "the limestone from the upper reaches of the Underdark. The "+
         "rivulets flow down and form a tiny stream that runs down the "+
         "middle of the tunnel.",
      "limestone" : "%^BOLD%^The limestone has been worn smooth by "+
         "countless years of seeping water, and perhaps the past "+
         "existence of an underground river at one point of time. On "+
         "the few dry patches of limestone there are crude paintings "+
         "scrawled by an untrained hand, amounting to nothing more "+
         "than stick figures and misshaped blobs.",
      ({"tunnel","passageway","passage"}):"%^BOLD%^This passageway snakes "+
         "through the solid limestone, probably the result of eons of "+
         "seeping or flowing water. It slopes downward at a slight, "+
         "but discernable grade.",
      "paintings" : "%^BOLD%^These cave paintings appear to be the "+
         "result of either a member of an uncivilized race, someone "+
         "of little skill, or both. The logic of the series of paintings "+
         "is not immediately apparent. There are a large amount of small "+
         "stick figures with tails around a large winged blob, that "+
         "might resemble a dragon of some sort.",
   ]));
   set_smell("default","The smell of wet limestone and damp dogs fills "+
      "the tunnel.");
   set_listen("default","Dripping and flowing water break the silence.");
}

