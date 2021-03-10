#include <std.h>
#include "/d/dagger/drow/short.h"
inherit "/std/bag_logic";
void create() {
    object money;

    ::create();
    set_id( ({"chest", "large chest"}) );
    set_name("chest");
   set_key("chestkey");
    set("short", "A large chest");
    set("long", "A large chest.\nIt is closed.");
    set_open_long("A large chest.\nIt is open.");
    set_closed_long("A large chest.\nIt is closed.");
    set_no_clean(1);
    set_weight(200000);
    set_value(2);
    set_max_internal_encumbrance(100);
    set_possible_to_close(1);
    new( "/d/shadow/obj/potion/extra_heal.c" )->move(TO);
    new( "/d/shadow/obj/potion/extra_heal.c" )->move(TO);
    new( "/d/shadow/obj/potion/invisible.c" )->move(TO);
   toggle_closed();
   set_lock("locked");
   TO->set_lock_difficulty(65);
}
