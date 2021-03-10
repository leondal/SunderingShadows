inherit "/std/bag_logic";

void create() {
   set_id(({"sack","ssack","small sack"}));
    set_name("small sack");
    set("short", "A small cloth sack");
    set_weight(5);
    set("long", "This is a small cloth sack. You could put things in it.\n");
    set_value(5);
    set_cointype("copper");
    set_max_internal_encumbrance(15);
}
