#include <std.h>
inherit "/std/bag_logic";

void create() {
    object money;

    ::create();
    set_id( ({"chest","large chest","bushchest"}) );
    set_name("chest");
    set("short", "%^BOLD%^%^RED%^A large chest%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^This is a large wooden chest. It looks quite old.\n%^RESET%^It is closed.");
    set_open_long("%^RESET%^%^ORANGE%^This is a large wooden chest. It looks quite old.\n%^RESET%^It is open.");
    set_closed_long("%^RESET%^%^ORANGE%^This is a large wooden chest. It looks quite old.\n%^RESET%^It is closed.");
    set_no_clean(1);
    set_weight(10000);
    set_value(0);
    set_max_internal_encumbrance(200);
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/heal2.c")->move(this_object());
      new("/d/koenig/town/items/raging_heal.c")->move(this_object());
      new("/d/koenig/town/items/raging_heal.c")->move(this_object());
      new("/d/koenig/town/items/raging_heal.c")->move(this_object());
      new("/d/koenig/town/items/raging_heal.c")->move(this_object());
      new("/d/koenig/town/items/raging_heal.c")->move(this_object());
    set_possible_to_close(1);
}
