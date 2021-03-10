#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("guitar");
   set_short("A nice guitar");
   set_id(({"guitar","nice guitar","instrument"}));
   set_long("This is a nice guitar that has been made from pieces of"+
   " oak wood that have been smoothed, treated, and carefully fitted"+
   " together. The strings are prefectly tuned and have ivory knobs to"+
   " adjust them if needed.");
   set_weight(3);
   set_value(500);
}
int is_instrument(){return 1;}

string query_prof_type() { return "instrument"; }