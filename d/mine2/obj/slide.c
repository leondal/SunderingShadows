#include <std.h>

inherit OBJECT;

create()
{
  ::create();
  set_weight(5000);
  set_id(({ "slide", "rock slide" }));
  set_name("rock slide");
  set_short("A rock slide");
  set_long("The rock slide is very large and accures often.  It stands about"
" 50 feet tall, and covers the enterance to the cave.   The rock slide "
"is made out of granit, which prohibits you from moveing even a single piece.  "
"There is a sign stuck half way out from under it, that has something writen on "
"it.");
}

void init()
{
  ::init();
   add_action("cave","mine");
}

int cave(string str)
{
   write("You can not enter the cave!  The cave is being blocked by the rock slide!");
return 1;
}
