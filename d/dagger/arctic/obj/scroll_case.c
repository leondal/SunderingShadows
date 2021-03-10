#include <std.h>
#include <move.h>
inherit "/std/bag_logic";

void create()
{
    ::create();
    set_id( ({"scroll case", "case"}) );
    set_name("scroll case");
    set_short("A worn scroll case");
    set_weight(5);
    set_long("This aged leather tube has been hardened by boiling then oiled to "
        "protect against the elements.  There is a soft leather cap on one end "
        "that can be closed to prevent moisture from getting inside.  This scroll "
        "case could hold scrolls, paper, parchment, or any other paper like "
        "items that could be rolled up to fit inside.  ");
    set_value(100);
    set_cointype("gold");
    set_max_internal_encumbrance(30);
    set_open_long( ""+TO->query_long()+"%^CYAN%^The cap is open.\n%^RESET%^");
    set_closed_long( ""+TO->query_long()+"%^CYAN%^The cap is closed.\n%^RESET%^");
    set_possible_to_close(1);
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
