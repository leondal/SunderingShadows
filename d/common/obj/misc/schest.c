inherit "/d/common/obj/misc/chesti.c";

void create() {

    	::create();
	create_treasure_chest("random", "random");
	//Old stuff - using the treasure chest inherit now - Saide

    /*set_id( ({"schest","chest", "small chest"}) );
    set_name("schest");
    set("short", "A small chest");
    set("long", "A small chest.");
    set_open_long("A small chest.\nIt is open.");
    set_closed_long("A small chest.\nIt is closed.");
    set_no_clean(1);
    set_weight(10);
    set_value(1);
    set_max_internal_encumbrance(20);
    set_possible_to_close(1);*/
    //set_closed(1);
}
