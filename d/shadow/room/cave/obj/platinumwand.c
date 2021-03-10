#include <std.h>

inherit OBJECT;

void create()   {
 ::create();
  set_name("platinum cave wand");
  set_short("%^BOLD%^%^WHITE%^A platinum wand%^RESET%^");
  set_id(({"wand","cave wand","platinum wand"}));
  set_long("This strange wand seems to be made of solid platinum "+
    "that glistens as if wet.  The wand is about an inch thick at the "+
    "base and tapers to a small point, around which miniscule letters "+
    "are carved.");
  set("read",
    "Smooth and shimmering my companions must be.");
  set_weight(0);
  set_value(0);
  
}
