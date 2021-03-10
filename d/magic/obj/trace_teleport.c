#include <std.h>

inherit OBJECT;

string fname;
object caster;

void init()
{
    ::init();
    tell_object(caster, "%^BOLD%^%^WHITE%^Do you want to memorize the destination?\nType %^GREEN%^yes%^WHITE%^ to memorize, anything else to ignore it.");
    input_to("mem_dest");
}

void setup_mem(string str, object tp)
{
    fname = str;
    caster = tp;
}

void mem_dest(string str)
{
    if(str != "yes")
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^You decide to let the trace be.");
        TO->remove();
        return;
    }

    tell_object(caster,"%^BOLD%^%^WHITE%^What woud you like to remember the trace as?\nDefault name is %^ORANGE%^trace%^WHITE%^.");
    input_to("mem_dest2");
}

void mem_dest2(string str)
{
    string dname;
    mapping remembered;
    string * sortrem;

    if (!(regexp(str, "[A-Za-z0-9]+"))) {
        dname = "trace";
    } else {
        dname = str;
    }

    if (!remembered = caster->query_rem_rooms()) {
        remembered = ([]);
    }
    if (!sortrem = caster->query_rem_rooms_sort()) {
                sortrem = ({});
    }

    remembered[dname] = fname;
    sortrem = distinct_array(({ dname }) + sortrem);
    caster->set_rem_rooms(remembered, sortrem);

    tell_object(caster,"%^BOLD%^%^WHITE%^You memorize " + fname->query_short() + "%^RESET%^%^BOLD%^ as %^ORANGE%^" + dname + "%^RESET%^.");

    TO->remove();
}
