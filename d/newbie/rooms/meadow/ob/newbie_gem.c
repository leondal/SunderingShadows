// /d/tonerra/obj/gem.c

#include <std.h>

inherit OBJECT;

string which_newbie;

void create()
{
   ::create();
   set_name("small black gem");
   set_long("%^BOLD%^%^BLACK%^This is a small black gem. It has been polished to a "+
   "luster and is perfectly smooth. The type of gem is unknown but perhaps it has "+
   "some value to someone.%^RESET%^");
   set_short("A small black gem");
   set_id(({"gem", "black gem", "small gem", "small black gem", "newbiemeadowob"}));
   set_weight(0);
   set_value(10);
}

string query_belongs_to() { return which_newbie; }
void set_belongs_to(string str)
{
    if(!stringp(str)) return;
    which_newbie = str;
}

int is_gem(){return 1;}
