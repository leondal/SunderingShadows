#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("aster");
  set_id( ({"aster", "flower"}) );
  set_short("%^MAGENTA%^A Beautiful Aster%^RESET%^");
  set_long("This beautiful, delicate flower is a perfect specimen of an "+
     "%^MAGENTA%^aster%^RESET%^. Six %^BOLD%^snow white %^RESET%^petals "+
     "tipped with %^RED%^crimson %^RESET%^radiate from the %^YELLOW%^golden colored "+
     "%^RESET%^center, giving it an appearance of a six pointed star. It is said that "+
     "these flowers grow from ground stained with %^YELLOW%^Lathander's "+
     "%^RESET%^%^RED%^blood%^RESET%^, spilt in battle against the forces of evil.  "+
     "This is one of the church of Lathander's most honored and beloved symbols.");
  set_weight(1);
  set("value", 1);
}
