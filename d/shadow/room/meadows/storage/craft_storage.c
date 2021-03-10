#include <std.h>
#include "../meadow.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_short("Periodo's craft storage room");
   set_long("This is a storage area that you should not be in unless you're a wiz.");
}

void reset()
{
 ::reset();
 if(!present("finely crafted long bow"))
  new(OBJ+"longbow")->move(TO);
 if(!present("feathered arrows"))
  new(OBJ+"arrows")->move(TO);
 if(present("belt"))
  new(OBJ+"r_belt")->move(TO);
 if(!present("boots"))
  new(OBJ+"r_boots")->move(TO);
 if(!present("sheepskin tunic"))
  new(OBJ+"r_stunic")->move(TO);
 if(!present("sheepskin vest"))
  new(OBJ+"r_svest")->move(TO);
 if(!present("sheepskin leggings"))
  new(OBJ+"r_sleggings")->move(TO);
 if(!present("sheepskin gloves"))
  new(OBJ+"r_sgloves")->move(TO);
 if(!present("fur"))
  new(OBJ+"r_fur")->move(TO);
 if(!random(2) && !present("rabbitskin"))
  new(OBJ+"r_rabbit")->move(TO);
 if(!random(6) && !present("animalskin"))
  new(OBJ+"r_skin")->move(TO);
 if(!random(2) && !present("bearskin jacket"))
  new(OBJ+"bearjacket")->move(TO);
 if(!random(2) && !present("bearskin coat"))
  new(OBJ+"bearcoat")->move(TO);
 if(!random(2) && !present("bearskin boots"))
  new(OBJ+"bearboots")->move(TO);
 if(!random(4) && !present("antelope jerkin"))
  new(OBJ+"jerkin")->move(TO);
 if(!random(6) && !present("feathered mask"))
  new(OBJ+"mask")->move(TO);
 if(!random(10) && !present("antler helmet"))
  new(OBJ+"helmet")->move(TO);
}