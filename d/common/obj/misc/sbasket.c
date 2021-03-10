inherit "/std/bag_logic";

void create() {
  ::create();
   set_id(({"basket","sbasket"}));
    set_name("small basket");
    set("short", "A small wicker basket");
    set_weight(4);
    set("long", "This is a simple wicker basket that you could put things in.\n");
    set_value(5);
    set_cointype("copper");
    set_max_internal_encumbrance(10);
}
