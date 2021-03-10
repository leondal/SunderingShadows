#include <std.h>

inherit OBJECT;

void init() {
    ::init();
    add_action("enter", "enter");
}

void init_castle() {
    move("LOCATION");
    set_name("castle");
    set("id", ({ "castle", "castle of NAME", "the castle of NAME" }));
    set("short", 0);
    set("long",
      "High Mortal NAME has built a castle here and welcomes all to enter "
      "and explore its halls."
    );
    environment(this_object())->set_no_clean(1);
}

int get() { return 0; }
   
int drop() { return 1; }

string affect_environment() { return "NAME has built a castle here."; }

string query_owner() { return "NAME"; }

int clean_up() { return 0; }
