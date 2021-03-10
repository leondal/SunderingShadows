//chapel2.c - Path to the chapel.  Circe 8/16/04
#include <std.h>
#include "../lothwaite.h"
inherit PATHEXIT"chapel1";

void create(){
   ::create();
   set_long( ::query_long()+"\n%^GREEN%^A small %^ORANGE%^footpath %^GREEN%^"+
      "heads away from the chapel here, leading to a large %^RESET%^ring "+
      "of stones %^GREEN%^to the southeast.\n");
   add_item("footpath","%^ORANGE%^The footpath has been left in "+
      "its natural state, worn simply by countless feet rather "+
      "than artificially made.  It least to a large ring of stones.");
   add_item(({"ring of stones","stones","ring"}),"To the southeast stands an open "+
      "field with a ring of stones, each of which stand well over "+
      "30 feet high.  They stand proudly against the sky, but "+
      "you cannot make out any more about them from here.");
   set_exits(([
      "north" : PATHEXIT"chapel1",
      "southwest" : PATHEXIT"chapel3",
      "southeast" : PATHEXIT"stones1"
   ]));
}