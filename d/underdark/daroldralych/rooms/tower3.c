#include <std.h>
#include "../defs.h"
inherit INH+"tower";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^Within the Black Spire%^RESET%^\n"
"%^BLUE%^This long, narrow store offers only a little room for customers, in front of the polished %^RED%^zurk%^MAGENTA%^"
"hw%^RED%^ood %^BLUE%^benchtop.  Behind the counter remains the majority of the room's space, in which numerous shelves "
"and cupboards run the length of the room.  They are stacked with boxes and packages, jars and bottles, all of which are "
"filled with such a variety of %^ORANGE%^s%^GREEN%^ub%^ORANGE%^st%^RED%^a%^MAGENTA%^n%^CYAN%^ce%^MAGENTA%^s %^BLUE%^that "
"you can't even begin to discern them all.  Aside from this, the room appears similar to the rest of the tower, enclosed "
"in %^BOLD%^%^BLACK%^glo%^RESET%^ss%^BOLD%^%^BLACK%^y %^RESET%^%^BLUE%^obsidian %^RESET%^%^BLUE%^that sheds %^ORANGE%^m"
"%^YELLOW%^u%^RESET%^%^ORANGE%^t%^RESET%^e%^ORANGE%^d %^BLUE%^light around the area.  Only one exit is apparent, through "
"the large archway that leads back to the centre of the spire.%^RESET%^\n");

   add_item(({"archway","obsidian archway"}),"%^BLUE%^A broad archway of matching mirror-smooth %^BOLD%^%^BLACK%^obsi"
"%^RESET%^di%^BOLD%^%^BLACK%^an %^RESET%^%^BLUE%^leads back into the centre of the spire.%^RESET%^");
   add_item(({"bench","benchtop","counter"}),"%^BLUE%^A polished %^RED%^zurk%^MAGENTA%^hw%^RED%^ood %^BLUE%^counter "
"segregates the small front section of the room from the shelves and cupboards in the rear.%^RESET%^");
   add_item(({"shelves","cupboards"}),"%^BLUE%^Behind the countertop, most of the room is filled with rows of shelves and "
"cupboards, all of which are covered in countless containers in all shapes and sizes.%^RESET%^");
   add_item(({"jars","boxes","packages","bottles","substances","containers"}),"%^BLUE%^Covering the shelves and filling "
"the cupboards are numerous boxes and packages, jars and bottles, all filled with such a variety of %^ORANGE%^s%^GREEN%^ub"
"%^ORANGE%^st%^RED%^a%^MAGENTA%^n%^CYAN%^ce%^MAGENTA%^s %^BLUE%^that you can't even begin to discern what they all are.  "
"Offcuts of varied %^GREEN%^p%^BOLD%^l%^RESET%^%^GREEN%^a%^ORANGE%^nt%^GREEN%^s%^BLUE%^, animal specimens and pieces "
"thereof, %^RESET%^d%^BOLD%^u%^RESET%^sts%^BLUE%^, %^CYAN%^liqu%^BOLD%^i%^RESET%^%^CYAN%^ds%^BLUE%^, and countless other "
"things that are clearly to be used for alchemical or magical purposes.%^RESET%^");
   set_exits(([
     "north":ROOMS"tower2",
   ]));
}

void reset(){
   ::reset();
   if(!present("hurzagh")) new(MON"hurzagh")->move(TO);
}