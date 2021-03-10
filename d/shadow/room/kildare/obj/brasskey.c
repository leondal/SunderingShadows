#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("brass key");
   set_short("A fancy brass key");
   set_id(({"key","brass key","caldon room_key"}));
   set_long("This long brass key is quite heavy and ornate, "+
      "complete with scrollwork at the end.");
   set_weight(5);
   set_value(0);
}
