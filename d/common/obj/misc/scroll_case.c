#include <std.h>
#include <move.h>
inherit "/std/bag_logic";

void create()
{
    ::create();
    set_id( ({"scroll case", "case"}) );
    set_name("scroll case");
    set_short("A worn scroll case");
    set_weight(4);
    set_long("This is a wooden scroll case you can put scrolls into.");
    set_value(100);
    set_cointype("gold");
    set_max_internal_encumbrance(40);
    set_property("repairtype",({ "leatherwork","tailor","woodwork" }));
}

int item_allowed(object item)
{
    string *ids = ({}), stuff = ({ "scroll","paper","parchment" });
    int i;

    ids = item->query_id();

    for(i=0;i<sizeof(ids);i++)
    {
        if(member_array(ids[i],stuff) != -1) { return 1; }
    }

    write("You can only put scrolls, paper, and parchment in this.");
    return 0;
}
