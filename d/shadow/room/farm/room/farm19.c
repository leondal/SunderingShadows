#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nA short %^ORANGE%^pathway "+
      "%^RESET%^is just north of here, leading to an "+
      "entrance into the unusual %^CYAN%^farmhouse%^RESET%^.\n");
   add_item(({"path","pathway"}),"The pathway is lined neatly "+
      "with %^RED%^m%^ORANGE%^u%^YELLOW%^l%^RESET%^%^GREEN%^t%^CYAN%^i"+
      "%^BOLD%^-%^BLUE%^c%^RESET%^%^MAGENTA%^o%^RED%^l%^ORANGE%^o"+
      "%^YELLOW%^r%^RESET%^%^GREEN%^e%^CYAN%^d cobblestone%^RESET%^.  "+
      "It leads a short way up to the %^CYAN%^farmhouse%^RESET%^, "+
      "and then continues on to the %^BOLD%^%^BLUE%^streams%^RESET%^.");  
   set_exits(([
      "north" : PATHS"path2",
      "west" : PATHS"farm18",
      "south" : PATHS"farm17",
      "southwest" : PATHS"farm16"
   ]));
}
