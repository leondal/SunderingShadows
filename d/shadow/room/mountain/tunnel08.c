#include <std.h>
#include "../cave.h"

inherit BTUNNEL;

void create() {
   ::create();
   set_long(
      "%^RESET%^%^ORANGE%^These tunnel walls are jagged and dangerous.  One slip"+
      " and you could easily be badly hurt by falling on a protruding rock. "+
      " This tunnel appears to have been crudely dug or expanded to be passable"
      " enough for humanoids and is clearly not dwarven work.  There are quite a"
      " few more rocks in this room."
   );

   set_search("default","You see a pile of rocks stacked up in an suspicious fashion.  Maybe you should search it?");
   set_search("rocks","You search the rocks and remove them to discover the entrance to an alcove to the south!");
   set_exits( ([
      "northwest" : TUNNEL+"tunnel07",
      "east" : TUNNEL+"tunnel09",
      "south" : TUNNEL+"alcove"
   ]) );
   set_invis_exits(({"south"}));
}
