//stormwand.c
#include <std.h>

inherit OBJECT;

void create()   {
 ::create();
  set_name("storm cave wand");
  set_short("%^BOLD%^%^BLUE%^A wand of storms%^RESET%^");
  set_id(({"wand","cave wand","storm wand"}));
  set_long("The form of this wand seems to constantly change.  What "+
    "appear to be dark, nearly black clouds move swiftly along the "+
    "length of the tapered wand, revealing at times a message hidden "+
    "within.");
  set("read",
    "Boundless energy binds my friends to me.");
  set_weight(0);
  set_value(0);
  
}
