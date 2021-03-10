/*Added 10/4/03 by Circe.  Added room name and updated code to current standards.  Changed road to use inherits.  Four rooms were added to make the desert connect correctly.*/

#include <std.h>

inherit "/d/darkwood/room/road2";

void create() {
    ::create();
    set_short("%^RESET%^%^MAGENTA%^An %^MAGENTA%^Anc%^ORANGE%^i%^MAGENTA%^en%^ORANGE%^t %^MAGENTA%^P%^ORANGE%^l%^MAGENTA%^aza%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^An %^MAGENTA%^Anc%^ORANGE%^i%^MAGENTA%^en%^ORANGE%^t %^MAGENTA%^P%^ORANGE%^l%^MAGENTA%^aza%^RESET%^
%^RESET%^%^GREEN%^You stand in small clearing on the %^MAGENTA%^road%^GREEN%^ in the middle of countryside. To the north spires of the great city of Shadow could be seen. To the south, a dark forest in the far distance. The road here bends around a %^ORANGE%^mon%^BOLD%^%^ORANGE%^u%^RESET%^%^ORANGE%^me%^BOLD%^%^ORANGE%^n%^ORANGE%^t%^RESET%^%^ORANGE%^,%^GREEN%^ several %^BOLD%^%^BLACK%^a%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^cien%^RESET%^%^WHITE%^t%^BOLD%^%^BLACK%^,%^RESET%^%^GREEN%^ covered in %^MAGENTA%^v%^GREEN%^i%^MAGENTA%^ne%^GREEN%^s %^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^tone %^WHITE%^benches%^GREEN%^ stand in the place for adventurers to rest. The place is sereve and quiet.%^RESET%^
");
    set_smell("%^MAGENTA%^You smell some flowers%^RESET%^");
    set_exits(
              (["north" : "/d/darkwood/room/road17",
                "south" : "/d/darkwood/room/road19",]) );
}

void reset()
{
    ::reset();
    if(!present("statue",TO))
        new("/d/shadow/obj/misc/"+"statue")->move(TO);
}


