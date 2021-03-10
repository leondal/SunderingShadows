#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit "/std/food.c";

void create()
{
::create();
set_name("%^BOLD$%RED$%Candycane");
set_id(({"candycane"}));
set_short("%^BOLD%^RED%^A candycane");
set_long("%^RED%^You hold a twelve inch long candycane, striped red and white and smelling delightfully of crisp mint.");
set_value(2);
set_weight(1);
set_strength(1);
set_my_mess("As you lick the candycane a minty taste fills your mouth");
set_your_mess(" licks on a candycane");
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
