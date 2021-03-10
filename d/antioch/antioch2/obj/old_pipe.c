#include <std.h>
#include "../antioch.h"
inherit "/d/common/obj/misc/pipe";

void create()
{
    ::create();
    set_name("ancient pipe");
    set_id(({ "pipe", "A pipe", "wooden pipe", "a pipe" }));
    set_short("An ancient pipe");
    set_long(
        "This pipe looks like it is very old and well used. It appears to" +
        " be quite sturdy, however, and has withstood the marks of time.\n" +
        "		You can pack or fill it with tobacco and then smoke it.\n"+
        "		You can also douse it to put it out.\n"
        );
    set_weight(1);
    set_value(20);
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
