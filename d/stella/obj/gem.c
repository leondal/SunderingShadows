#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("diamond");
  set_id( ({"diamond", "gem"}) );
  set_short("a sparkling diamond");
  set_long("This looks like it might be a very valuable gem!");
  set_value(500+random(1000));
  set_weight(2);
}
