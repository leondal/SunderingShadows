//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit ARMOUR;

/*#include "/std/money.c";
string class;
int  real_str;
None of this seems to be used, so taking it out - Circe
*/

void create(){
   ::create();
   set_name("gloves");
   set_id(({"gloves","glove","pair of gloves","work gloves","leather gloves"}));
   set_short("pair of heavy leather work gloves");
   set_long("This pair of gloves is made of heavy leather meant "+
      "to withstand the rigors of working outdoors.  The gloves are "+
      "deep brown and fairly basic, although a very thin layer of "+
      "wool has been added as a lining, making them a little bit "+
      "more comfortable.");
   set_type("clothing");
   set_limbs(({"right hand","left hand"}));
   set_weight(1);
   set_size(random(3)+1);
   set_value(4);
}
