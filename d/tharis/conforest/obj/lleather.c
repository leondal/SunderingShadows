#include <std.h>
inherit "/std/armour";

void create()
{
  ::create();
  set_name("leather");
  set("id",({"leather","leather armor","armor","armour","lleather"}));
  set("short", "A large suit of leather armor");
  set("long","This armor is made of leather, hardened in "+
	"boiling oil and then shaped into breastplate and "+
	"shoulder protectors. The rest of the "+
   "suit is made of softer, more flexible materials.");
  set_weight(20);
  set("value",8);
  set_type("leather");
  set_size(3);
  set_limbs( ({ "torso" }) );
  set_ac(2);
}
