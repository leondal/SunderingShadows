inherit "/std/bag_logic";

void create() {
    set_id( ({"backpack","pack","bag"}) );
    set_name("backpack");
    set("short", "A leather backpack");
    set_weight(5);
    set("long", "This is a simple leather backpack that you could put things in.\n");
    set_value(2);
    set_max_internal_encumbrance(20);
}
