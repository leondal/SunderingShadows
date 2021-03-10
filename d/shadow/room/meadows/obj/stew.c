#include <std.h>
inherit "/std/food";

void create()
{
   ::create();
   set_name("fish stew");
   set_short("A bowl of fish stew");
   set_id(({"stew","fish stew","bowl of stew","bowl of fish stew","food"}));
   set_long("This is a steaming bowl of fish stew. It is thick and creamy"+
   " with many other vegetables and spices added to it. There are many"+
   " pieces of fish, they all look white and flakey and delicious.");
   set_weight(2);
   set_value(3);
   set_cointype("copper");
   set_strength(10);
   set_destroy();
   set_my_mess("The fish stew is absolutely delicious with just the right amount of seasoning.");
   set_your_mess("devours a bowl of fish stew.");
}
