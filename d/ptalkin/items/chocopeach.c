#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit "/std/food.c";
object BOX;

int set_box(object where);

void create()
{
::create();
set_name("chocolate peach");
set_id(({"peach", "chocolate peach", "gift"}));
set_id(({"chocolate"}));
set_short("%^ORANGE%^A chocolate peach");
set_long("%^ORANGE%^Here is a golden coloured chocolate peach.  Handcrafted by experts, the colours blend together and you can almost see the pale gold fuzz upon it.  A rich aroma of fresh peaches and a hint of liqueur rises from the chocolate.");
set_weight(1);
set_value(20);
set_strength(1);
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
