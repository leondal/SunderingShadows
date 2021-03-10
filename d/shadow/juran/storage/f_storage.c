#include <std.h>
#include "/d/common/common.h"

inherit "/d/common/inherit/gs_storage";

void create() {
  	::create();
   	set_property("no teleport",1);
    	set_properties((["light":1, "indoors":1]));
    	set_short("Fighters storage");
    	set_long("Fighter things are kept here.\n");

}

void reset() {
 	if (!present("weapsheath 1")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 2")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 3")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 4")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 5")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 6")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 7")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 8")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 9")) new(CSHEATH"sheath_randomizer")->move(TO);
 	if (!present("weapsheath 10")) new(CSHEATH"sheath_randomizer")->move(TO);
}
