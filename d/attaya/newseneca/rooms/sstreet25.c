//sstreet25 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"An %^GREEN%^open area %^RESET%^to the north "+
      "is surrounded by a %^BOLD%^white picket fence%^RESET%^.  "+
      "The south seems oddly open, as the %^BOLD%^"+
      "town walls %^RESET%^do not cover this stretch of the street, "+
      "and you can see the %^YELLOW%^beach %^RESET%^far below the "+
      "edge of the cliff on which %^BOLD%^Seneca %^RESET%^stands.\n");
   set_exits(([
      "east" : ROOMS"sstreet24",
      "west" : ROOMS"sstreet26",
      "north" : ROOMS"jousting1"
   ]));
   set_door("gate","/d/attaya/newseneca/rooms/jousting1","north",0,0);
   set_door_description("gate","The gate through the %^BOLD%^white "+
      "picket fence %^RESET%^is wide, easily allowing a horse or two "+
      "to pass through.  It has a %^BOLD%^%^BLACK%^wrought iron latch%^RESET%^.");
   add_item("area","The area to the north is a %^GREEN%^grassy stretch "+
      "%^RESET%^of land surrounded by %^ORANGE%^wooden benches %^RESET%^"+
      "far to the sides.  The central portion has been roped off, and it "+
      "looks as if some sort of contest takes place there.");
   add_item("fence","%^BOLD%^The white picket fence to the north is relatively "+
      "short.  It has a gate set within it to allow access to the grounds "+
      "beyond.%^RESET%^");
   add_item("beach","Seneca stands on the edge of a cliff overlooking "+
      "a portion of the beach below.  From here, you can see a small "+
      "stretch of %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand and %^CYAN%^waves %^RESET%^"+
      "pounding the shore far below you.");
   add_item("cliff","Seneca stands on the edge of a cliff overlooking "+
      "a portion of the beach below.  From here, you can see a small "+
      "stretch of %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand and %^CYAN%^waves %^RESET%^"+
      "pounding the shore far below you.");
   remove_item("wall");
   remove_item("walls");
   remove_item("coquina");
   remove_item("coquina walls");
}