//storage room for Cornelia in Tabor.  Circe 6/1/04
#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Cornelia's Crystal Creations Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMDIR+"jeweler"]));
}

void reset()
{
	::reset();
if(!present("crystal necklace"))
 new(OBJDIR+"c_crystal")->move(TO);
if(!present("crystal necklace 2"))
 new(OBJDIR+"c_crystal")->move(TO);
if(!present("crystal strand"))
 new(OBJDIR+"c_strand")->move(TO);
if(!present("crystal strand 2"))
 new(OBJDIR+"c_strand")->move(TO);
if(!present("cabochon ring"))
 new(OBJDIR+"c_ring")->move(TO);
if(!present("crushed bracelet"))
 new(OBJDIR+"c_bracelet")->move(TO);
if(!present("petal earrings"))
 new(OBJDIR+"c_earrings")->move(TO);
if(!present("petal earrings 2"))
 new(OBJDIR+"c_earrings")->move(TO);
if(!present("cufflinks"))
 new(OBJDIR+"c_cufflinks")->move(TO);
if(!present("clasp"))
 new(OBJDIR+"c_clasp")->move(TO);
if(!present("clasp 2"))
 new(OBJDIR+"c_clasp")->move(TO);
}
