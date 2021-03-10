#include <std.h>

inherit OBJECT;

void create()
{
   ::create();
   set_name("instrument");
   set_short("a generic musical instrument");
   set_id(({"instrument"}));
   set_long("This is a rather plain looking instrument");
   set_weight(5);
   set_value(750);
}

int is_instrument(){return 1;}

string query_prof_type() { return "instrument"; } // used to allow the sheath inherit to work with instrument cases

void init()
{
    ::init();
    if(!query_property("can_hold")) { set_property("can_hold","instrument"); }
    if(!pointerp(query_property("can_wear_limbs")))
    {
        remove_property("can_wear_limbs");
        set_property("can_wear_limbs",({"torso","waist"}));
    }
    if(!query_property("call_myself")) { set_property("call_myself",TO->query_short()); }
}