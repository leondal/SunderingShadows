#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit "/std/food.c";
object BOX;

int set_box(object where);

void create()
{
::create();
set_name("chocolate rose");
set_id(({"chocolate rose", "chocolate", "gift"}));
set_short("%^RED%^A chocolate rose");
set_long("%^BOLD%^WHITE%^Laying upon silver silken spun threads of candy rest a perfect%^RESET%^RED%^ rose%^RESET%^BOLD%^WHITE%^.  It looks as though a drop of morning dew has made its way to the heart of the chocolate flower.  You can smell the scent of delicate summer roses coming from the chocolate.  It almost looks too good to eat.");
set_weight(1);
set_value(25);
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
