#include <std.h>
#include "../../antioch.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Adrerrard's Ration Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMS+"ration"]));
}

void reset()
{
	::reset();
if(!present("nuts"))
 new(OBJ+"nuts")->move(TO);
if(!present("dried fruits"))
 new(OBJ+"dried_fruits")->move(TO);
if(!present("iron rations"))
 new(OBJ+"iron_rations")->move(TO);
if(!present("standard rations"))
 new(OBJ+"standard_rations")->move(TO);
if(!present("dry rations"))
 new(OBJ+"dry_rations")->move(TO);
if(!present("dried meat"))
 new(OBJ+"dried_meat")->move(TO);
 if(!present("jerky"))
 new(OBJ+"rawhide")->move(TO);
if(!present("hard tack"))
 new(OBJ+"hardtack")->move(TO);
if(!present("waybread"))
 new(OBJ+"waybread")->move(TO);
if(!present("waterskin"))
 new(OBJ+"waterskin")->move(TO);
if(!present("cheese"))
 new(OBJ+"cheese")->move(TO);
if(!present("wine bottle"))
 new(OBJ+"wine_bottle")->move(TO);
}
