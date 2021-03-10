#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"  %^BOLD%^%^BLUE%^The man-made archways of brick and mortar come to "
"an end here, where a tunnel leads off into the %^BLACK%^darkness%^BLUE%^.  The %^WHITE%^spider "
"webs %^BLUE%^grow thick and tangled to the north, making it difficult to progress.\n%^RESET%^");
   set_exits(([ 
"north":UPPER"t1r1",
"east":UPPER"tunnel37",
   ])); 
}