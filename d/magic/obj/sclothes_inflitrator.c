#include <std.h>
#include <domination.h>
inherit "/d/magic/obj/sclothes";

catch_tell(string str)
{
    if (!objectp(caster)) {
        dest_me();
        return;
    }
    tell_object(caster, "%^BOLD%^%^RED%^[I]%^RESET%^ " + str);
}
