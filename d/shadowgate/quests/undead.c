
#include <std.h>

inherit "std/quest_ob";

string owner;

void create()
{
  ::create();
    set_name("Undead Quest");
    set_id( ({"quest_object","Undead Quest","boy"}) );
    set_short("a little boy");
    set_long("This is a terrified little boy.");
    set_quest_points(50);
}

void init()
{
    ::init();
    if(interactive(ETO) && !owner)  owner = ETO->query_name();
}

string query_owner(){ return owner; }
