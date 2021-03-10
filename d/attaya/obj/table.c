#include <std.h>
#include <daemons.h>

inherit OBJECT;


void create(){
    ::create();

    set_name("table");
    set_id(({"table","black table"}));
    set_short("A long black table");
    set_long(
      "The long black table consists of an onyx slab mounted upon a sturdy walnut frame.  A very thin gold band runs around the outside edge of the table."
    );
    set_weight(100000);
    set_value(10000);
}
