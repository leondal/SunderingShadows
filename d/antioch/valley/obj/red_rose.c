#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("red rose");
   set_short("%^BOLD%^%^RED%^A large red rose%^RESET%^");
   set_id(({"rose","red rose","large rose","large red rose"}));
   set_long("%^BOLD%^%^RED%^This red rose is much larger than normal and"+
   " is quite beautiful in full bloom. The petals are incredibly soft"+
   " but easy to bruise. It gives off a wonderful fragrance.");
   set_weight(1);
   set_value(1);
   set_cointype("copper");
}

// void save_me(string file) {return 1;}
