//updated by Circe 6/7/04 with new lore by Shar
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("lion pelt");
   set_short("A spotted lion's pelt");
   set_id(({"pelt","lion pelt","lion_pelt","spotted lion's pelt","lion's pelt"}));
   set_long("This is the sleek coat of a large spotted lion. The coat is"+
   " a light brown shade with black spots. It is very soft.");
   set_lore(
@CIRCE
The hide of a lion, the King of the Beasts, is prized by many tanner and trappers.  Garments made of the lions hide are quite popular among the faithful of Torm as well as many young noblemen of Tabor.
CIRCE
   );
   set_property("lore difficulty",5);
   set_value(450);
   set_cointype("gold");
   set_weight(2);
}
