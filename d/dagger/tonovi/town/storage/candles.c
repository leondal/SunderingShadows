//storage room for Tonovi.  Circe 12/29/04
#include <std.h>
#include "../../short.h"
inherit ROOM;

#define OBJ "/d/barriermnts/lothwaite/obj/"+

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Candle Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : "/d/dagger/tonovi/town/bazaar5"]));
}

void reset()
{
	::reset();
if(!present("taper"))
 new(OBJ"taper")->move(TO);
if(!present("taper 2"))
 new(OBJ"taper")->move(TO);
if(!present("pillar") && !random(2))
 new(OBJ"pillar")->move(TO);
if(!present("pillar 2") && !random(2))
 new(OBJ"pillar")->move(TO);
if(!present("shaped") && !random(4))
 new(OBJ"shaped")->move(TO);
if(!present("scented") && !random(2))
 new(OBJ"scented")->move(TO);
if(!present("scented 2") && !random(2))
 new(OBJ"scented")->move(TO);
if(!present("sealing wax"))
 new(OBJ"sealing_wax")->move(TO);
if(!present("sealing wax 2"))
 new(OBJ"sealing_wax")->move(TO);
}
