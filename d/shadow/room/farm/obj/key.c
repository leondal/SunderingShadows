#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("iron key");
   set_short("A thick iron key");
   set_id(({"key","iron key","thick iron key","piaf_house_key"}));
   set_long("This is a thick iron key, rather simple in design.  "+
      "It has a wide ring at the end that probably once held "+
      "a length of twine or leather to help the owner keep up "+
      "with it, but that is now gone.");
   set_weight(1);
   set_value(0);
}
