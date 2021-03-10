
#include <std.h>

inherit "std/quest_ob";

string owner;

void create()
{
  ::create();
    set_name("boy");
    set_id( ({"quest_object","Muileann Quest","boy"}) );
    set_short("%^BOLD%^%^WHITE%^A little boy%^RESET%^");
    set_long("%^RESET%^This is a %^BOLD%^%^BLACK%^terrified%^RESET%^ little boy. His face is smeared with %^RED%^blood%^RESET%^, %^ORANGE%^dirt%^RESET%^ and %^BOLD%^tears%^RESET%^, and he is dressed in %^RESET%^%^GREEN%^tatte%^ORANGE%^%^GREEN%^red r%^ORANGE%^a%^GREEN%^gs%^RESET%^. He has a %^BOLD%^haunted%^RESET%^ look in his eyes. This boy has seen too much.");
    set_quest_points(20);
}

void init()
{
    ::init();
    if(interactive(ETO) && !owner)  owner = ETO->query_name();
}

string query_owner(){ return owner; }

void save_me(string file){return 1;}
