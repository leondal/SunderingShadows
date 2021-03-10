#include <std.h> 
#include "../defs.h" 
inherit ROOM; 

void create(){ 
::create(); 
set_property("light",-1); 
set_property("indoors",1); 
set_terrain(NAT_CAVE); 
set_travel(PAVED_ROAD); 

set_name("A narrow underground passage"); 
set_short("%^RESET%^%^ORANGE%^A narrow underground passage%^RESET%^");
 
set_long("%^WHITE%^A narrow underground passage%^RESET%^\n"
"%^RESET%^%^ORANGE%^This narrow passage cuts its way under the "
"surface of the Yniam Planes toward the Charu Mountains.  All around you "
"can be seen instances of chisel and pick marks gouging into the "
"%^WHITE%^sandstone rock%^ORANGE%^.  They mar the wall, floor and ceiling's "
"surfaces, revealing where this passage was enlarged to allow travel along "
"what was once an underground %^BLUE%^river%^ORANGE%^.  Here and there, "
"%^RED%^iron hooks %^ORANGE%^have been driven into the stone, the lanterns "
"that used to hang from them long since vanished, casting this passage into "
"darkness but for the faint glow of %^CYAN%^phosphorescent "
"%^ORANGE%^lichen.%^RESET%^"); 

set_smell("default","A damp order hangs in the air."); 
set_listen("default","The occasional drip of water falls somewhere up ahead."); 

set_items(([ 

({"chisel","pick","marks","gouges"}):"%^RESET%^%^CYAN%^Looking closely "
"at the marks in the walls, you notice patches of lichen seem to be "
"growing in several of them.", 

({"walls","wall","floor","ceiling","sandstone"}):"%^RESET%^%^CYAN%^The "
"walls, floor and ceiling all appear to have been widened by the use of "
"pick and chisel.  Small gouges in the stone provide places for the "
"lichen that lights this underground passage, to grow.",

({"hooks","lanterns"}):"%^RESET%^%^RED%^Small iron hooks extend from a "
"few spots along the passage.  Rusted and mostly useless, they likely "
"once held lanterns to light the way for those working on this place. ",

({"moss","lichen"}):"%^RESET%^%^CYAN%^Small patches of phosphorescent "
"lichen can be seen in some of the deeper chisel marks.  The plant's "
"faint glow providing just enough light to make it hard to see.%^RESET%^",


])); 
} 
