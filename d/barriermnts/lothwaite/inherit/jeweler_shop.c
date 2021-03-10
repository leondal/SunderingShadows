//storage room for Edric in Lothwaite.  Circe 6/21/04
#include <std.h>
#include "../lothwaite.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Winds of Fortune Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : PATHEXIT"jeweler"]));
}

void reset()
{
	::reset();
if(!present("pendant"))
 new(OBJ"pendant")->move(TO);
if(!present("pendant 2"))
 new(OBJ"pendant")->move(TO);
if(!present("pendant 3"))
 new(OBJ"pendant")->move(TO);
if(!present("comb"))
 new(OBJ"comb")->move(TO);
if(!present("comb 2") && !random(2))
 new(OBJ"comb")->move(TO);
if(!present("abrigon"))
 new(OBJ"abrigon")->move(TO);
if(!present("abrigon 2"))
 new(OBJ"abrigon")->move(TO);
if(!present("abrigon 3") && !random(3))
 new(OBJ"abrigon")->move(TO);
if(!present("white flower clasp") && !random(2))
 new(OBJ"flower_clasp")->move(TO);
if(!present("four heart clasp") && !random(2))
 new(OBJ"heart_clasp")->move(TO);
if(!present("white snowflake clasp") && !random(2))
 new(OBJ"snowflake_clasp")->move(TO);
if(!present("armband"))
 new(OBJ"armband")->move(TO);
if(!present("armband 2"))
 new(OBJ"armband")->move(TO);
}
