#include <std.h> 
#include "../defs.h" 
inherit INH+"crossroad"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"  %^RESET%^%^ORANGE%^The air grows damp here and the walls look moist.  Ahead "
"you can see a wide %^BOLD%^%^BLUE%^river %^RESET%^%^ORANGE%^flowing swiftly across "
"the path.  Boulders have been arranged on either side of the river, narrowing it "
"considerably and making it even faster as the water is forced into the tight "
"constraints.  Thick wooden boards span the space between the boulders forming a "
"bridge of sorts, though the %^WHITE%^froth%^ORANGE%^ of the water has caused these "
"boards to become slick with spray.\n%^RESET%^"); 

add_item(({"rocks","boulders"}),"%^BOLD%^%^BLACK%^Large, carefully chosen "
"boulders have been piled up to either side of this underground river, narrowing "
"the water's passage while forming a small landing where one can stand on either side."); 

add_item(({"bridge","boards"}),"%^RESET%^%^ORANGE%^Thick planks stretch over the "
"churning water, providing a passage across the underground river.  Supported on "
"either side by large boulders, their surfaces are wet and there are no visible "
"signs of handholds, making this a dangerous crossing to say the least."); 

add_item(({"river","water"}),"%^BOLD%^%^BLUE%^A naturally formed underground river "
"cuts its way through the earth and intersects this hand carved passage. The water's "
"flow regulated by large boulders that have been piled up here to prevent the river "
"from flooding the passageways.");

   set_exits(([ 
"southwest":UPPER"cross12",
"northeast":UPPER"tonovitunnel/river01",
   ])); 
}
