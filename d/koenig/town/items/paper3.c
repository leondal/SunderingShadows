#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("note");
  set_id( ({"note", "paper"}) );
  set_short("a small piece of paper");
  set_long("%^BOLD%^%^WHITE%^If you are brave and smart, you can travel the floors of the tower "+
"without much strife. If you look quite hard, and if you hold the right key or object to unbind the way, you might find a shortcut right to "+
"the top.");
  set_value(0);
  set_weight(1);
}
