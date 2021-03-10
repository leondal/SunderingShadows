#include <std.h>
#include "../piratedefs.h"
inherit HEALER;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_name("Loreman's Leachery");
    set_short("Loreman's Leachery");
    set_long("%^BOLD%^Loreman's Leachery%^RESET%^\n"
"This drab little healer's store is the only one for miles around.  The place itself is grungy and most "
"unappealing, with %^ORANGE%^dirt%^RESET%^ and %^BLACK%^%^BOLD%^grime%^RESET%^ covering almost every visible "
"surface.  There are several jars of obnoxious herbs and balms laying about, along with a few jars of "
"%^GREEN%^leeches%^RESET%^.  Just how badly do you want to be healed in a place like this?");
    set_smell("default","The strong odor of vinegar and other herbs burns at your nostrils.");
    set_listen("default","The dulled noise of the street outside still reach your ears.");
    set_exits(([
	"northwest":COVE"path8"
    ]));

   set_name("Loreman");
   set_cl_price(40);
   set_cs_price(90);
   set_cc_price(200);
   set_np_price(300);
   set_bp_price(75);
   set_cb_price(300);
}

void reset(){
   ::reset();
   if(!present("loreman"))
     find_object_or_load(MON"loreman")->move(TO);
}
