#include <std.h>

inherit ROOM;
#include "../areadefs.h"

void create() {
    ::create();
    set_terrain(HUT);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("outdoors",1);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^");
    set_long("
%^ORANGE%^You walk to the edge of the b%^BOLD%^ea%^RESET%^%^ORANGE%^c%^BOLD%^h %^RESET%^%^ORANGE%^to where it meets the %^GREEN%^jun%^BOLD%^g%^RESET%^%^GREEN%^le %^ORANGE%^and you notice some interesting things. First of all against a %^BOLD%^%^GREEN%^la%^RESET%^%^GREEN%^r%^BOLD%^g%^RESET%^%^GREEN%^e %^BOLD%^pa%^RESET%^%^GREEN%^l%^BOLD%^m tr%^RESET%^%^GREEN%^e%^BOLD%^e %^RESET%^%^ORANGE%^lays the %^WHITE%^f%^BOLD%^res%^RESET%^h co%^BOLD%^r%^RESET%^p%^BOLD%^s%^RESET%^e %^ORANGE%^of what appears a well-equipped adventurer. His %^BOLD%^%^RED%^bl%^RESET%^%^RED%^o%^BOLD%^o%^RESET%^%^RED%^d %^BOLD%^s%^RESET%^%^RED%^t%^BOLD%^ai%^RESET%^%^RED%^n%^BOLD%^s %^RESET%^%^ORANGE%^the the sand around him. Not far away from him stands %^BOLD%^%^BLACK%^a %^RESET%^%^RED%^ma%^BOLD%^%^BLACK%^n c%^RESET%^%^RED%^le%^BOLD%^%^BLACK%^ani%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^g %^RESET%^%^RED%^h%^BOLD%^%^BLACK%^is dag%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^rs%^ORANGE%^. The cliff blocking you off from the beach to the north of you is bigger now, and the only way out from here is the way you came. The noise from the wind and the waves makes this part of the beach
very %^CYAN%^remote %^ORANGE%^indeed.%^RESET%^
");

     set_listen("default","The wind gusts loudly here and "+
                "and the waves crash loudly.");
 
    set_exits(([

       "east" : ROOMS+"senbeach3",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet "+
         "tall, are bending in the powerful winds that rip over the "+
         "island.",
         "beach" : "The beach here is rippled from the effects of a "+
         "recent tide.  The sand is very finely granulated.",
         "corpse" : "The bloody corpse of some unlucky adventurer lays "+
         "against one of the large palm trees. He has multible stab "+
         "wounds covering his body."
    ] ));
}

void reset()
{
  ::reset();
  if(!present("assassin"))
  new(MON+"assassin2.c")->move(TO);
}
