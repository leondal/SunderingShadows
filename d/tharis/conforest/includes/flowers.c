#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
  set_property("indoors",1);
  set_property("light",2);
  set_short("The flower room");
  set_long("Various items are stored here.");
  set_property("no teleport",1);
  set_exits((["down" : ROOMS+"c5.c"]));
}

void reset()
{
::reset();
if(!present("tulip"))
 new(OBJ+"tulip")->move(TO);
if(!present("daisy"))
 new(OBJ+"daisy")->move(TO);
if(!present("rose"))
 new(OBJ+"rose")->move(TO);
if(!present("thistle"))
 new(OBJ+"thistle")->move(TO);
if(!present("daffodil"))
 new(OBJ+"daffodil")->move(TO);
}
