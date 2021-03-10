//storage room for Galen in Lothwaite.  Circe 6/16/04
#include <std.h>
#include "../lothwaite.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Tallow Chandler Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : PATHEXIT"candle"]));
}

void reset()
{
	::reset();
if(!present("taper"))
 new(OBJ"taper")->move(TO);
if(!present("taper 2"))
 new(OBJ"taper")->move(TO);
if(!present("pillar"))
 new(OBJ"pillar")->move(TO);
if(!present("pillar 2"))
 new(OBJ"pillar")->move(TO);
if(!present("shaped"))
 new(OBJ"shaped")->move(TO);
if(!present("shaped 2"))
 new(OBJ"shaped")->move(TO);
if(!present("scented"))
 new(OBJ"scented")->move(TO);
if(!present("scented 2"))
 new(OBJ"scented")->move(TO);
if(!present("sealing wax"))
 new(OBJ"sealing_wax")->move(TO);
if(!present("sealing wax 2"))
 new(OBJ"sealing_wax")->move(TO);
if(!present("sealing wax 3"))
 new(OBJ"sealing_wax")->move(TO);
if(!present("sealing wax 4"))
 new(OBJ"sealing_wax")->move(TO);
}
