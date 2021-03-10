#include "/d/shadow/mon/melnmarn.h"
#include "../tormdefs.h"
#include <std.h>
inherit ROOM;

void create() {
  ::create();
    set_properties((["light":2, "indoors":1]));
    set_short("Gilles' clothing rack storage area");
    set("long", "Only supplies and such here.\n");
    set_property("no teleport",1);
    set_exits( (["up" : TCITY+"c60"]) );
}

void reset() {

::reset();
  if(!present("sailors trousers")) new(OBJ+"pantsc.c")->move(TO);
  if(!present("leather pants")) new(OBJ+"pantsl.c")->move(TO);
  if(!present("pantaloons")) new(OBJ+"pantsp.c")->move(TO);
  if(!present("black silk shirt")) new(OBJ+"silkshirtb.c")->move(TO);
  if(!present("white silk shirt")) new(OBJ+"silkshirtw.c")->move(TO);
  if(!present("green silk shirt")) new(OBJ+"silkshirtg.c")->move(TO);
  if(!present("red silk shirt")) new(OBJ+"silkshirtr.c")->move(TO);
   if(!present("blue silk shirt")) new(OBJ+"silkshirtbb.c")->move(TO);
   if(!present("silk dress")) new(OBJ+"silkdress.c")->move(TO);
   if(!present("red silk sash")) new(OBJ+"silksash.c")->move(TO);
   if(!present("blue silk sash")) new(OBJ+"bluesash.c")->move(TO);
  if(!present("boots")) new(OBJ+"rboots.c")->move(TO);
  if(!present("sandal")) new(OBJ+"sandal.c")->move(TO);
  if(!present("hose")) new(OBJ+"hose.c")->move(TO);
  if(!present("gloves")) new(OBJ+"gloves.c")->move(TO);
   if(!present("perfume")) new(OBJ+"perfume")->move(TO);
}

