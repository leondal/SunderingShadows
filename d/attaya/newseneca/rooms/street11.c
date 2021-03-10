//street11 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"To the west rises the impressive %^BOLD%^"+
      "Castillo Blanco%^RESET%^, which casts its long shadow over the "+
      "%^BOLD%^%^BLACK%^jail %^RESET%^to the south.\n");
   set_exits(([
      "west" : ROOMS"street10",
      "east" : ROOMS"street12",
      "south" : ROOMS"jail_main"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/jail_main","south",0,0);
   set_door_description("door","The door to the south is made of thick "+
      "%^ORANGE%^wooden planks %^RESET%^bound with %^BOLD%^%^BLACK%^"+
      "iron%^RESET%^.  A small, %^BOLD%^%^BLACK%^barred window %^RESET%^"+
      "is near the top of the door.");
   add_item("jail","The jail on the southern side of the road is crafted "+
      "from pale stone, making it roughly match the grand building to the "+
      "west.  The jail has no windows and only a single, %^BOLD%^"+
      "%^BLACK%^reinforced %^RESET%^door.");
   add_item("castillo","The building to the south is a beautiful three-"+
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
      "belltower %^RESET%^rises high overhead, ending in a spire.");
   add_item("castillo blanco","The building to the south is a beautiful three-"+
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
      "belltower %^RESET%^rises high overhead, ending in a spire.");
}