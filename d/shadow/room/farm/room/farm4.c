#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^BOLD%^%^BLUE%^stream %^RESET%^"+
      "rushes by to the west, leading over a section of "+
      "rocky falls southwest of here.  The %^GREEN%^farmyard "+
      "%^RESET%^spreads out to the east.\n");
   set_exits(([
      "northeast" : PATHS"farm1",
      "east" : PATHS"farm5",
      "south" : PATHS"farm7",
      "southeast" : PATHS"farm8"
   ]));
   add_item(({"falls","rocky falls","waterfall"}),"The rocky "+
      "waterfalls make passage in the stream to the southwest "+
      "impossible.  They are rather beautiful, though, with the "+
      "%^BOLD%^%^CYAN%^light blue water %^RESET%^cascading over "+
      "%^BOLD%^pristine white rocks%^RESET%^, a strange "+
      "juxtaposition with the eclectic farmyard.");
}

void reset(){
   ::reset();
   if(!present("goose") && !random(3)){
      new(MON"goose")->move(TO);
   }
}