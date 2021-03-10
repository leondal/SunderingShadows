//newteye.c - Object for Koenig.  Might tie in with quest later on.  Circe 11/22/03
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("eye of newt");
   set_short("A tiny eyeball");
   set_id(({"eye","eyeball","eye of newt","newt eye"}));
   set_long(
      "This tiny eyeball is about the size and shape of a small pea.  "+
      "It is brilliant white in color and has a deep black iris set within "+
      "it.  There is no telling that its use might be or why someone would "+
      "keep this."
   );
   set_lore("The eyes of amphibians such as newts have long been used by "+
      "wizards in the creation of new spells, especially divinations.");
   set_property("lore difficulty",7);
   set_weight(1);
   set_value(5);
}
