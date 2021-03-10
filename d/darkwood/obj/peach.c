

inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
  set_name("peach");
   set_id(({"peach","golden peach","ripe peach","food"}));
  set_strength(5);
  set_weight(1);
   set_short("%^YELLOW%^A golden peach%^RESET%^");
  set_destroy();
   set_long("This is a delicious looking golden peach.");
   set_my_mess("The peach is sweet and practically dissolves in your mouth.");
   set_your_mess("eats a golden peach.");
  }
