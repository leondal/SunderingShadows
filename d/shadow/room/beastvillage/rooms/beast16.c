#include <std.h> 
#include "../defs.h" 
inherit INH+"northbeast"; 

void create(){ 
   ::create(); 

    set_long("%^YELLOW%^A narrow path in the mountains%^RESET%^\n"
"%^RESET%^%^ORANGE%^Branching away from the main mountain road is this small path.  It "
"winds around the side of a rocky outcrop to reveal a swiftly flowing mountain %^CYAN%^"
"stream%^ORANGE%^, leading steeply down from the high %^YELLOW%^Charu Mountains "
"%^RESET%^%^ORANGE%^toward a lush and %^BOLD%^%^GREEN%^fertile valley %^RESET%^"
"%^ORANGE%^below. Though steep, the path is wide and free of brambles, likely kept that "
"way by the %^BOLD%^%^CYAN%^spring flooding %^RESET%^%^ORANGE%^that comes with "
"%^BOLD%^%^WHITE%^snowmelt%^RESET%^%^ORANGE%^.  Rocks, stones and water logged pieces "
"of wood line the path to the side where the river traverses, forming a border on one "
"side, while the other sports small %^GREEN%^shrubs %^ORANGE%^and the occasional pine, "
"oak or spruce tree.  Further on you can see a small protected %^GREEN%^valley "
"%^ORANGE%^stretching off to the north.%^RESET%^\n");
   set_exits(([ 
"northwest":"/d/shadow/room/pass/pass28",
"southwest":ROOMS"beast15",
   ])); 
}