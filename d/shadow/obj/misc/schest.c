inherit "/std/bag_logic";

void create() {

    ::create();
    set_id( ({"schest","chest", "small chest"}) );
    set_name("schest");
    set("short", "A small chest");
    set("long", "A small chest.\nIt is closed.");
    set_open_long("A small chest.\nIt is open.");
    set_closed_long("A small chest.\nIt is closed.");
    set_no_clean(1);
    set_weight(10);
    set_value(1);
     set_max_internal_encumbrance(20);
    set_possible_to_close(1);
}
