//street10 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"Just south of here you see the magnificent "+
      "pale stone building%^RESET%^ known as the %^BOLD%^Castillo Blanco"+
      "%^RESET%^, which houses the %^YELLOW%^Council of "+
      "Seneca%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"street9",
      "east" : ROOMS"street11",
//      "south" : ROOMS"townhall_entry"
   ]));
   add_item(({"building","castillo","castillo blanco"}),"The building to the south is a beautiful three-"+
      "story structure.  The bottom level exhibits a symmetrical design "+
      "with an %^BOLD%^arched doorway %^RESET%^in the middle braced by "+
      "a recessed archway on either side housing a %^BOLD%^statue%^RESET%^.  "+
      "The second floor features paired %^BOLD%^columns %^RESET%^supporting "+
      "the roof overhead.  Behind the columns, grand %^ORANGE%^wooden "+
      "doors %^RESET%^plated with %^YELLOW%^gold %^RESET%^can be seen.  "+
      "The top story has three tall, arched %^BOLD%^%^GREEN%^s%^CYAN%^t"+
      "%^YELLOW%^a%^RED%^i%^MAGENTA%^n%^BLUE%^e%^BLACK%^d %^RESET%^%^MAGENTA%^g%^CYAN%^l"+
      "%^BOLD%^%^GREEN%^a%^BLUE%^s%^RED%^s %^RESET%^%^GREEN%^w%^YELLOW%^"+
      "i%^MAGENTA%^n%^WHITE%^d%^BLUE%^o%^RED%^w%^CYAN%^s %^RESET%^overlooking "+
      "a %^BOLD%^railed balcony%^RESET%^.  Finally, a tiered %^BOLD%^"+
      "belltower %^RESET%^rises high overhead, ending in a spire.  "+
      "%^BOLD%^Watching the happenings of the building, it does "+
      "not seem as though common citizens are allowed inside.%^RESET%^");
   add_item("statue","There are two statues.  You could take a closer "+
      "look at the left statue or the right one.");
   add_item("left statue","The statue on the left is of an aging woman "+
      "with flowing hair that reaches past her waist.  She is carrying "+
      "an open book in her right hand, but her eyes are cast up toward the "+
      "sky.  A slender, spiralling staff is in her left hand, the top "+
      "set with a sparkling %^MAGENTA%^ame%^BOLD%^t%^RESET%^%^MAGENTA%^"+
      "hyst%^RESET%^.  The statue is titled, 'Wisdom.'"); 
   add_item("right statue","The statue on the right is of a robust young "+
      "man with curly hair and well-muscled shoulders.  He wears a "+
      "breastplate and bears a shield.  In his right hand is a very "+
      "real-looking %^BOLD%^mithril sword%^RESET%^.  A plaque at the "+
      "base of this statue titles it, 'Strength.'");
   add_item("belltower","Rising high over the city of Seneca is an "+
      "impressive belltower made of the same white stone as the rest of "+
      "Castillo Blanco.  The bell cannot be seen within, but you have heard "+
      "that it has a very distinctive sound and only rings out in times of "+
      "battle - unlike the church bell, which tolls the time.");
}