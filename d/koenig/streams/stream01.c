//stream01 - For the updated Koenig area - changed by Circe 11/21/03
#include <std.h>
#include "../koenig.h"

inherit ROOM;

void create() {
    	::create();
      set_terrain(SHORE);
      set_travel(RUTTED_TRACK);
    	set_property("light",2);
    	set_property("indoors",0);
    	set_short("The bank of a flowing stream");
    	set_long(
         "The village road fades away completely here at the %^ORANGE%^sandy banks %^RESET%^of "+
         "a rapidly flowing %^CYAN%^stream%^RESET%^.  Not far to the south, the stream becomes "+
         "quite deep and looks as though it would be dangerous to cross.  The village to the north "+
         "looks desolate compared with the beauty of the %^GREEN%^forest %^RESET%^just beyond it.  "+
         "On the other side of the stream to the south, you can see the beginnings of a "+
         "%^RED%^mountain range%^RESET%^."+
         "\n"
      ); 
     	set_smell("default","The fresh scent of water washes away the charred scent of the village.");
     	set_listen("default","You hear the rush of the rapidly flowing stream.");
    	set_exits(([
       	"northeast" : VILROOMS"k_road11",
       	"south": VILSTREAM"stream10"
    	] ));
    	set_items(([
         ({"bank","sandy bank","banks","sandy banks","sand"}) : "The sandy shore of the swiftly "+
            "moving river are a light tan in color.  The sand is rather coarse and glitters "+
            "iridescently in the light.",
         ({"stream","river","water"}) : "The clear water has a %^BOLD%^%^CYAN%^light blue %^RESET%^"+
            "cast to it.  Swimming against the stream are several small fish, all of whom dart away "+
            "at the first sign of you.",
         ({"village","buildings","building"}) : "The abandoned village to the north stands grim against "+
            "the backdrop of the temperate forest.",
         ({"forest","tree","trees"}) : "The forest rising above the village is filled with many different "+
            "types of trees.  Tall oaks, sycamores, and the like stand beneath the shady branches of the "+
            "taller evergreens.",
         ({"mountains","mountain range","mountain"}) : "Beyond the sandy shores of the stream, you can "+
            "see the foothills that rise to a mountain range not far to the south.  Their peaks rise "+
            "reddish-brown above the blues and greens of the land here."
    	] ));
}

