#include <std.h>
#include "../piratedefs.h"

inherit HEALER;

void create() {
    ::create();
    set_light(3);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Loreman's Leachery");
    set_long("Loreman's Leachery is the only healer for miles "+
       "the place is grungy and most unappealing. "+
      "There are several jars of obnoxious herbs "+
      "and balms laying about along with a few jars of leeches."
    );
     set_smell("default", "The strong odor of vinegar.");
    set_listen("default", "You hear the screams of "+
      "the more injured patrons.");
    set_exits( ([
	"northwest" : CAVES"cove7"
      ] ));

set_name("Loreman");
set_cl_price(120);
set_cs_price(145);
set_cc_price(200);
set_np_price(500);
set_bp_price(300);
set_cb_price(250);
}

void reset(){
    ::reset();
    if(!present("loreman")) 
	new(MON"loreman")->move(TO);
}
