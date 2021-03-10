#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit "/std/food.c";
object BOX;

int set_box(object where);

void create()
{
::create();
set_name("chocolate tree");
set_id(({"chocolate tree", "tree", "gift"}));
set_short("%^GREEN%^chocolate tree");
set_long("%^BOLD%^RED%^Nestled deep within spun red gold fibres, lies a handmade chocolate.  Crafted in the shape of an evergreen tree, with tiny candied birds placed upon it, the chocolate looks too good to eat.  However, the rich odour assails your senses and you can gobble it down anytime you want.");
set_weight(1);
set_strength(1);
set_value(30);
set_my_mess("As you eat the chocolate, a slow grin of appreciation lights your face.");
set_your_mess(" eats a chocolate and smiles");
}

void init() {
  ::init();
	add_action("eat", "eating");
}

int set_box(object where) {
    BOX= where;
}

int eating(string str) {
  if (!str) {
     notify_fail("eat what ?? \n");
     return 0;
    }
  if ( str != "chocolate" ) {
	notify_fail("Nothing here to eat like "+str+" !!\n");
     return 0;
     }
  destruct(BOX);
 
return 0;
}
