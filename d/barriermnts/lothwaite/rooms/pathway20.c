//pathway20.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  Here, the path diverges and heads in several different "+
      "directions.  A sign post has been pounded into the ground and has a ring of "+
      "flowers growing around it.\n");
   add_item("flowers","The colorful flowers seem to do well here in the breezy valley.  "+
      "Brilliant lady's slippers and bluebells add a burst of color to the green backdrop.");
   add_item("ring of flowers","The colorful flowers seem to do well here in the breezy valley.  "+
      "Brilliant lady's slippers and bluebells add a burst of color to the green backdrop.");
   set_exits(([
      "northwest" : PATHEXIT"pathway18",
      "northeast" : PATHEXIT"pathway21",
      "southwest" : PATHEXIT"pathway19",
      "southeast" : PATHEXIT"pathway22"
   ]));
}

void reset(){
   ::reset();
   if(!present("sign")){
      new(OBJ"vilsign")->move(TO);
   }
}