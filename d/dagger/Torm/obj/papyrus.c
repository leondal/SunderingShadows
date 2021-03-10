#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("papyrus");
   set_id(({"paper","papyrus","sheet of papyrus"}));
   set_short("sheet of papyrus");
   set_long("This is a sheet of papyrus, a fragile material made from the processed bark of certain trees and shrubs.");
   set_value(1);
}

string query_long(string str) {
   string hold = ::query_long(str);
   if(stringp(query("read"))) {
      hold += " It has writing on it.";
   }
   return hold;
}
