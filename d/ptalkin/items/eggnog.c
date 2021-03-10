
//WATER

inherit "/std/drink.c";

#include <std.h>

void create(){
  ::create();
set_name("eggnog");
set_id(({"eggnog", "egg nog", "gift"}));
set_type("alcoholic");
  set_strength(10);
 set_weight(0);
set_short("%^YELLOW%^eggnog");
set_value(5);
  set_destroy();
set_long("%^YELLOW%^You hold in your hand, a mug of rich eggnog, made from the finest eggs, milk, rum and cinnamon.  The smell alone sends your sense spiralling.");
set_my_mess("You take a gulp of eggnog and grin at the smooth rich taste.");
set_your_mess("gulps down some rich eggnog");
  }
