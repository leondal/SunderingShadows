#include <std.h>
#include <move.h>
inherit "/d/common/obj/misc/tobacco/cigar.c";

void create()
{
    ::create();
    set_name("cigar");
    set_id(({ "cigar", "full cigar", "full bodied cigar", "full-bodied cigar" }));
    set_short("%^RESET%^%^ORANGE%^full-bodied cigar%^RESET%^");
    set_long("%^RESET%^This is a hand rolled cigar measuring approximately five and a half inches long by just over half an inch wide, in the shape commonly called a corona.  Bundled, flue-cured leaves make up the filler of this cigar, while a perfect, %^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^k %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^w%^BOLD%^%^BLACK%^n %^RESET%^leaf has been used as the wrapper.  The cigar itself smells of %^BOLD%^%^BLACK%^peat%^RESET%^, %^BOLD%^%^WHITE%^cream%^RESET%^, and darkly fired %^BOLD%^%^BLACK%^tobacco%^RESET%^.\n\n%^RESET%^%^ORANGE%^Try smoking it. Douse it to put it out.%^RESET%^");
    lit = 0;
    hasmsgs = 1;
    tracker = 0;
    mymsgs = ({ "%^RESET%^%^ORANGE%^You enjoy the full, creamy taste of the tobacco.%^RESET%^"});
    yourmsgs = ({"%^RESET%^%^ORANGE%^You smell the full, almost overpowering aroma of the burning tobacco.%^RESET%^"});
    intox = 0;
}
