#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit "/std/food.c";

void create()
{
::create();
set_name("%^ORANGE%^Gingerbreadman");
set_id(({"gingerbreadman", "gingerbread", "man", "gift"}));
set_short("%^ORANGE%^Gingerbreadman");
set_long("%^ORANGE%^A delicious smelling gingerbread man, covered in red and white icing.  A small face peeks at you with a big grin.  Tiny buttons adorn a cleverly iced tunic, and small little boots are iced upon his feet.  He smells of cinnamon and cloves and would make a very nice snack.");
set_weight(1);
set_strength(1);
set_value(3);
set_my_mess("As you take a chomp, cinnamon and spices fills your senses");
set_your_mess("takes a chomp out of the gingerbreadman.");
}

void init() {
  ::init();
	add_action("eat", "eating");
}

int eating(string str) {
  if (!str) {
     notify_fail("eat what ?? \n");
     return 0;
    }
 
}
