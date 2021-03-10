
#include <std.h>

inherit "std/quest_ob";

string owner;

void create()
{
  ::create();
    set_name("Muileann Quest");
    set_id( ({"quest_object","Muileann Quest","boy"}) );
    set_short("a little boy");
    set_long("This is a terrified little boy.");
    set_quest_points(20);
}

void init()
{
    ::init();
    if(interactive(ETO) && !owner)  owner = ETO->query_name();
}

string query_owner(){ return owner; }
