#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
    ::create(); 
    set_long(""+::query_long()+"  %^BOLD%^%^BLUE%^To the south, "
"the solid granite of this tunnel ends, met by dirt walls and wooden "
"supports.\n");
    set_exits(([ 
      "south":UPPER"tonovitunnel/tunnel26",
      "northwest":UPPER"tunnel28",
    ])); 
}