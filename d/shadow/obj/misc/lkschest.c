//	chest.c
//	a lockable treasure chest
//	written by Descartes 21 October 1992

inherit "/std/bag_logic";

void create() {
    object money;

    ::create();
    set_id( ({"chest", "treasure chest", "orc chest", "orc treasure chest"}) );
    set_name("chest");
    set("short", "An orc treasure chest");
    set("long", "A huge chest with a lock on it.\nIt is closed.");
    set_open_long("A huge chest with a lock on it.\nIt is open.");
    set_closed_long("A huge chest with a lock on it.\nIt is closed.");
    set_no_clean(1);
    set_weight(2000);
    set_value(100);
    set_max_internal_encumbrance(2000);
    set_possible_to_close(1);
    set_lock("locked");
    set_property("magic hold", 10);
    set_key("orc_treasure");
    money = new("std/obj/coins");
    money->set_money("platinum", random(5));
    money->set_money("gold", random(100));
    money->set_money("electrum", random(500));
    money->set_money("silver", random(1000));
    money->set_money("copper", random(100));
    money->move(this_object());
}
