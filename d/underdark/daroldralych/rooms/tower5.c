#include <std.h>
#include "../defs.h"
inherit INH+"tower";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^Within the Black Spire%^RESET%^\n"
"%^BLUE%^Numerous wooden %^RED%^sh%^ORANGE%^e%^RED%^lves %^BLUE%^line the rear wall of this small store, drawing your "
"gaze.  Sitting atop them are a wealth of %^RESET%^scrolls%^BLUE%^, some stacked carefully while others have been rolled "
"and tied.  The uppermost shelves sport lines of %^ORANGE%^b%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^ks%^BLUE%^, each "
"different from the last but kept in a strictly ordered line all the way along.  In front of this sits a polished counter "
"of %^RED%^zurk%^MAGENTA%^hw%^RED%^ood%^BLUE%^, upon which is a written list.  Aside from this, the room resembles the "
"rest of the tower, enclosed in %^BOLD%^%^BLACK%^glo%^RESET%^ss%^BOLD%^%^BLACK%^y %^RESET%^%^BLUE%^obsidian %^RESET%^"
"%^BLUE%^that sheds %^ORANGE%^m%^YELLOW%^u%^RESET%^%^ORANGE%^t%^RESET%^e%^ORANGE%^d %^BLUE%^light around the area.  Only "
"one exit is apparent, through the small archway that leads back to the centre of the spire.%^RESET%^\n");

   add_item(({"archway","obsidian archway"}),"%^BLUE%^A small archway of matching mirror-smooth %^BOLD%^%^BLACK%^obsi"
"%^RESET%^di%^BOLD%^%^BLACK%^an %^RESET%^%^BLUE%^leads back into the centre of the spire.%^RESET%^");
   add_item(({"shelves","books","scrolls","parchment","parchments"}),"%^BLUE%^Numerous shelves line the rear wall of the "
"store.  Easily half of the shelves are stacked with %^WHITE%^scrolls %^BLUE%^and curled %^ORANGE%^parchm%^YELLOW%^e"
"%^RESET%^%^ORANGE%^nt%^BLUE%^, some of which %^BOLD%^%^WHITE%^g%^RESET%^l%^BOLD%^%^BLACK%^e%^RESET%^a%^BOLD%^%^WHITE%^m "
"%^RESET%^%^BLUE%^faintly in the dim light with lines of iridescent ink, specifically designed for use in the dark.  "
"Above these, upon the uppermost shelves, rows of %^ORANGE%^b%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^ks%^BLUE%^ are all set "
"in precise order, ranging from the old and tattered to the pristine.%^RESET%^");
   add_item(({"counter","zurkhwood counter","list","bench"}),"%^BLUE%^A counter of polished %^RED%^zurk%^MAGENTA%^hw"
"%^RED%^ood %^BLUE%^stands before you.  There is a %^RESET%^list%^BLUE%^ written with prices, sitting on top of the "
"bench.%^RESET%^");
   set_exits(([
     "west":ROOMS"tower4",
   ]));
}

void reset(){
   ::reset();
   if(!present("zekcyrl")) new(MON"zekcyrl")->move(TO);
}