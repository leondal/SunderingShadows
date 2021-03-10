

inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
  set_name("nuts");
  set_id(({"nuts","bag of nuts"}));
  set_strength(10);
  set_weight(1);
   set_short("A bag of nuts");
  set_destroy();
   set_long("This is a bag full of assorted nuts, they all look good.");
   set_my_mess("You enjoy the variety of nuts.");
   set_your_mess("eats a bag of nuts.");
  }
