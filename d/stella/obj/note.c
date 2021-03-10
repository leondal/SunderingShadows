#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("note");
  set_id( ({"note"}) );
  set_short("a note");
  set_long("Beware the Mundanoid!!  Do NOT feed him!");
  set_value(0);
  set_weight(1);
}
