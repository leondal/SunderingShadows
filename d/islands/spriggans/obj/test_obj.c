//gnome_emerald.c - by Circe for the Bracers of the Forgotten Folk
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("emerald");
   set_id(({"gem"}));
   set_short("Test gem");
   set_long("This is a test to see if an item can be dropped or "+
      "targetted by its name, even if that name is not one of "+
      "the ids.");
   set_weight(1);
}