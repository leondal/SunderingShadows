//inherit "/d/common/obj/misc/chesti.c";  - inherit is bad, I'll fix it later -ts
inherit "/std/bag_logic";
void create() {

    ::create();
   //create_treasure_chest("random",  "random");
    //Old stuff - now using the chest inherit to generate 
    //a random chest - Saide

set_id( ({"chest", "lkchest", "treasure chest", "orc chest", "orc treasure chest"}) );
    set_name("chest");
    set_short("A large lockable chest");
    set_long("A large chest with a lock on it.\nIt is closed.");
    set_open_long("A large chest with a lock on it.\nIt is open.");
    set_closed_long("A large chest with a lock on it.\nIt is closed.");
    set_no_clean(1);
    set_weight(25);
    set_value(10);
    set_max_internal_encumbrance(50);
    set_possible_to_close(1);
    set_closed(1);
    set_lock("locked");
   set_key("chest");
 }
