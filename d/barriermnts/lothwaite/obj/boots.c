//boots.c - for Lothwaite, Circe 12/19/04
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_id(({"boots","leather boots","tall leather boots"}));
   set_name("tall leather boots");
   set_short("%^RESET%^%^ORANGE%^tall leather boots%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^These tall boots are made of supple, dark "+
      "brown leather oiled to protect against the elements.  They are "+
      "made to lace all the way up to the knees, offering protection "+
      "from cold and brambles.  The soles are rather hard, but it "+
      "seems as though these boots would be better for walking than "+
      "riding.%^RESET%^"
   );
   set_value(40);
   set_size(3);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
}