inherit "/std/bag_logic";

void create() {
  ::create();
    set_id( ({"sack","large sack"}) );
    set_name("large sack");
    set("short", "A large cloth sack");
    set_weight(5);
    set("long", "This is a large cloth sack. You could put things in it.\n");
    set_value(2);
    set_cointype("silver");
    set_max_internal_encumbrance(30);
}

int is_light_opaque() { return 1;}
