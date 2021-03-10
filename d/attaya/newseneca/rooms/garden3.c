//garden3 - ~Circe~ 1/13/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"garden_inherit";

void create(){
   ::create();
   set_long(::query_long()+"\n%^RESET%^%^GREEN%^The most remote "+
      "part of the cathedral %^BOLD%^gardens%^RESET%^%^GREEN%^, "+
      "this little area is sheltered on all sides.  A %^ORANGE%^"+
      "wooded lot %^GREEN%^rises on the other side of the %^BOLD%^"+
      "%^BLACK%^fence %^RESET%^%^GREEN%^to the north, while a "+
      "%^BOLD%^%^WHITE%^marble rotunda %^RESET%^%^GREEN%^and the "+
      "%^ORANGE%^gazebo %^RESET%^%^GREEN%^rise to the west "+
      "and east respectively.  The %^BOLD%^"+
      "%^MAGENTA%^o%^YELLOW%^l%^WHITE%^e%^MAGENTA%^a%^YELLOW%^n"+
      "%^WHITE%^d%^MAGENTA%^e%^YELLOW%^r%^WHITE%^s %^RESET%^%^GREEN%^ grow "+
      "more thickly here, adding to the feeling of seclusion.%^RESET%^\n");
   set_exits(([
      "south" : ROOMS"garden2"
   ]));
   add_item("fence","%^BOLD%^%^BLACK%^The iron picket fence has "+
      "fleur-de-lis caps and is set with %^RESET%^stone columns "+
      "%^BOLD%^%^BLACK%^at intervals.%^RESET%^");
   add_item("rotunda","To the west, the circular roof of a "+
      "%^BOLD%^marble rotunda %^RESET%^rises above the %^BOLD%^"+
      "ole%^MAGENTA%^a%^WHITE%^nd%^MAGENTA%^e%^WHITE%^rs.%^RESET%^");
   add_item("lot","North of the fence here, a lot wooded with "+
      "%^GREEN%^palm %^RESET%^and %^ORANGE%^orange %^GREEN%^trees "+
      "%^RESET%^has been left undeveloped.");
   add_item("wooded lot","North of the fence here, a lot wooded with "+
      "%^GREEN%^palm %^RESET%^and %^ORANGE%^orange %^GREEN%^trees "+
      "%^RESET%^has been left undeveloped.");
}