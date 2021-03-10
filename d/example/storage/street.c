#include <std.h>
#include "../example.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);
   set_name("Example Street");
   set_short("Example Street");
   set_long("%^BOLD%^Example Street, Anytown%^RESET%^\n"+
      "This is a sample street to help illustrate how headers "+
      "and inherits can be beneficial in an area.\n");
   set_listen("default","You hear the slow crackling sound of "+
      "minds frying.");
   set_smell("default","Hmm...what's that ozone smell?");
   set_items(([
      "stuff" : "This would be whatever stuff you could see."
   ]));
}
