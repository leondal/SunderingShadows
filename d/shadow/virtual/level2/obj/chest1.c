inherit "/std/bag_logic";

void create() {
  object money;
    ::create();
    set_id( ({"chest", "treasure chest", "goblin chest", "chest1"}) );
    set_name("chest");
    set("short", "A large lockable chest");
    set("long", "A large chest with a lock on it.\nIt is closed.");
    set_open_long("A large chest with a lock on it.\nIt is open.");
    set_closed_long("A large chest with a lock on it.\nIt is closed.");
    set_no_clean(1);
    set_weight(25);
    set_value(10);
    set_max_internal_encumbrance(100);
    set_possible_to_close(1);
    set_lock("locked");
    close_container("chest");
    set_property("magic hold", 10);
    set_key("gchestl2c1");
    money = new("std/obj/coins");
    money->set_money("silver", random(100));
    money->set_money("copper", random(1000));
    money->move(this_object());

}
