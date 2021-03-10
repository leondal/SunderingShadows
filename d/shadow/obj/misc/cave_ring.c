#include <std.h>

inherit ARMOUR;

string cur_mood;
string old_min;
int notify;
string owner;

void create()   {
 ::create();
  set_name("cave ring");
  set_short("A rusty old ring");
  set_id(({"ring","cave ring"}));
  set_long("This is a strange looking ring with rust all over it.");
  set_weight(0);
  set_value(0);
  set_type("ring");
    set_limbs(({"right hand"}));
  set_ac(0);
  
}


