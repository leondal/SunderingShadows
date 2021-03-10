inherit "/std/bag_logic";

void create() {
    set_id( ({"bag","sack"}) );
    set_name("bag");
    set("short", "A small cloth bag");
    set_weight(5);
    set("long", "This is a simple cloth bag that you could put things in.\n");
    set_value(1);
    set_max_internal_encumbrance(10);
}
