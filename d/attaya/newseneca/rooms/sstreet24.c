//sstreet24 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"North of here is a %^ORANGE%^wooden fence "+
      "%^RESET%^surrounding the %^GREEN%^stable grounds %^RESET%^, "+
      "above which you can sometimes see horses and other mounts.  "+
      "The south seems oddly open, as the %^BOLD%^"+
      "town walls %^RESET%^do not cover this stretch of the street, "+
      "and you can see the %^YELLOW%^beach %^RESET%^far below the "+
      "edge of the cliff on which %^BOLD%^Seneca %^RESET%^stands.\n");
   set_exits(([
      "east" : ROOMS"sstreet23",
      "west" : ROOMS"sstreet25"
   ]));
   add_item("fence","%^ORANGE%^The fence to the north stands about "+
      "seven feet tall, making it impossible for most to see directly "+
      "over it.  However, you can see the far end of the stable yard, "+
      "and you can occasionally see the heads of mounts passing by.%^RESET%^");
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