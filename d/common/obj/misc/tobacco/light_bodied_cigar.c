#include <std.h>
#include <move.h>
inherit "/d/common/obj/misc/tobacco/cigar.c";

void create()
{
    ::create();
    set_name("cigar");
    set_id(({ "cigar", "light cigar", "light bodied cigar", "light-bodied cigar" }));
    set_short("%^RESET%^%^ORANGE%^light-bodied cigar%^RESET%^");
    set_long("%^RESET%^This is a hand rolled cigar measuring approximately five and a half inches long by just over half an inch wide, in the shape commonly called a corona.  Bundled, flue-cured leaves make up the filler of this cigar, while a perfect, %^RESET%^%^ORANGE%^light tan %^RESET%^leaf has been used as the wrapper.  The cigar itself smells of %^RESET%^%^ORANGE%^oak%^RESET%^, %^BOLD%^%^WHITE%^cream%^RESET%^, and lightly fired %^BOLD%^%^BLACK%^tobacco%^RESET%^.\n\n%^RESET%^%^ORANGE%^Try smoking it. Douse it to put it out.%^RESET%^");
    lit = 0;
    hasmsgs = 1;
    tracker = 0;
    mymsgs = ({ "%^RESET%^%^ORANGE%^You enjoy the light and creamy taste of the tobacco.%^RESET%^"});
    yourmsgs = ({"%^RESET%^%^ORANGE%^You smell the light and creamy aroma of the burning tobacco.%^RESET%^"});
    intox = 0;
}
