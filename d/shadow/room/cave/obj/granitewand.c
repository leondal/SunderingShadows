//granitewand.c
#include <std.h>

inherit OBJECT;

void create()   {
 ::create();
  set_name("granite cave wand");
  set_short("%^BOLD%^%^BLACK%^A gr%^WHITE%^a%^BLACK%^ni%^WHITE%^t%^BLACK%^e wand%^RESET%^");
  set_id(({"wand","cave wand","granite wand"}));
  set_long("This tapered wand is much heavier than it looks, and it seems "+
    "incredibly solid.  It is made entirely of white-veined black granite "+
    "that has been left rough.  After studying it a moment, there seem "+
    "to be words scrawled in the weight veins.");
  set("read",
    "Strong as the earth and natural as the wind are my colleagues.");
  set_weight(0);
  set_value(0);
  
}
