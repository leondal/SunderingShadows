#include <std.h>
#include "../defs.h"
inherit INH+"alley";

void create(){ 
   ::create();
   set_long(""+ ::query_long() +"  To the northeast, you can see where this street meets with one of the main "
"thoroghfares of the city.%^RESET%^\n");

   add_item(({"houses","buildings","walls"}),"%^BLUE%^Upon either side of the road rise enclosed buildings, probably "
"belonging to the lowest-ranked houses.  They are well-made as far as construction goes, but they most definitely lack "
"the %^CYAN%^mag%^BOLD%^n%^RESET%^%^CYAN%^ific%^GREEN%^en%^CYAN%^ce %^BLUE%^and grace of the upper-class buildings"
".%^RESET%^");
   set_exits(([
     "west":ROOMS"alley7",
     "northeast":ROOMS"southeast2",
   ]));
}
