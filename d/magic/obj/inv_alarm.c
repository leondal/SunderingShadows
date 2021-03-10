#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit "/d/magic/obj/alarm";

object *select_livings()
{
    object * livings;
    int clevel = query_property("spell")->query_clevel();

    livings = all_living(ETO);
    livings -= ({ TO });
    livings -= ({ caster });
    livings -= caster->query_followers();
    livings = filter_array(livings, (: !avatarp($1) :));
    livings = filter_array(livings, (: $1->query_invis() || $1->query_hidden() :));

    return livings;
}
