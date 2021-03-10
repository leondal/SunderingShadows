//ivorypipe.c
#include <std.h>

inherit "/d/common/obj/misc/pipe";

void create()
{
    ::create();
    set_name("ivory cave pipe");
    set_id(({ "pipe", "ivory pipe", "cave pipe", "ivory cave pipe" }));
    set_short("%^BOLD%^%^WHITE%^An ivory pipe%^RESET%^");
    set_long("This aged pipe is made of stark white ivory carved " +
             "with various symbols.  Most of them seem to be family crests " +
             "and have been filled with a smokey gray ink, causing them to " +
             "stand out in relief.  The stem of the pipe is very long and " +
             "protected by blackened ivory.\n" +
             "      %^BOLD%^You could pack or fill the pipe with tobacco, then smoke it.\n" +
             "              When you are finished, you could douse it.%^RESET%^"
             );
    set_weight(0);
    set_value(0);
    packed = 0;
    tobacco = 0;
    lit = 0;
    con_req = 0;
    sp_adjust = 0;
    hasmsgs = 0;
    tracker = 0;
    mymsgs = ({});
    yourmsgs = ({});
    intox = 0;
    mycharges = 0;
}
