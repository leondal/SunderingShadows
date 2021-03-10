#include <std.h>
#include <move.h>
inherit "/d/common/obj/misc/tobacco/cigar.c";

void create()
{
    ::create();
    set_name("cigar");
    set_id(({ "cigar", "medium cigar", "medium bodied cigar", "medium-bodied cigar" }));
    set_short("%^RESET%^%^ORANGE%^medium-bodied cigar%^RESET%^");
    set_long("%^RESET%^This is a hand rolled cigar measuring approximately five and a half inches long by just over half an inch wide, in the shape commonly called a corona.  Bundled, flue-cured leaves make up the filler of this cigar, while a perfect, %^RESET%^%^RED%^r%^ORANGE%^e%^RED%^d%^ORANGE%^d%^RED%^i%^ORANGE%^s%^RED%^h%^RESET%^-%^ORANGE%^b%^RED%^r%^ORANGE%^o%^RED%^w%^ORANGE%^n %^RESET%^leaf has been used as the wrapper.  The cigar itself smells of %^RESET%^%^ORANGE%^cedar%^RESET%^, %^BOLD%^%^WHITE%^cream%^RESET%^, and rich yet not overpowering %^BOLD%^%^BLACK%^tobacco%^RESET%^.\n\n%^RESET%^%^ORANGE%^Try smoking it. Douse it to put it out.%^RESET%^");
    lit = 0;
    hasmsgs = 1;
    tracker = 0;
    mymsgs = ({ "%^RESET%^%^ORANGE%^You enjoy the pungent, yet not overpowering, taste of the tobacco.%^RESET%^"});
    yourmsgs = ({"%^RESET%^%^ORANGE%^You smell the pungent, yet not overpowering aroma of the burning tobacco.%^RESET%^"});
    intox = 0;
}
