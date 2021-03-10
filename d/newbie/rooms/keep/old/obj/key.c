#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("skeleton key");
   set_short("A skeleton key");
   set_id(({"key","skeleton key","keep master_key"}));
   set_long("This is an iron key that is shaped into a skull"+
   " at the end of the handle.");
   set_lore("This key bears a tiny marking near the base of the "+
      "skull that labels it as belonging to the abandoned keep "+
      "just northeast of Offestry.  Once a grand place, the "+
      "keep has now fallen into disrepair at the hands of the "+
      "strange creatures known as xvarts.");
   set_property("lore difficulty",4);
   set_weight(5);
   set_value(0);
}
