#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit "/std/bag_logic";
void create() {
    object money;

    ::create();
    set_id( ({"bag", "bag of holding"}) );
    set_name("bag");
    set("short", "A large bag");
    set("long", "This large black bag is shadowy in texture and the insides "
	"of it seem far larger than the outside.");
    set_open_long("A bag of holding\nIt is open.");
    set_closed_long("A bag of holding\nIt is closed.");
    set_no_clean(1);
    set_weight(10);
    set_value(500);
set_max_internal_encumbrance(200);
    set_possible_to_close(1);
}
