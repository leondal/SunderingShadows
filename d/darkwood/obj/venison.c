

inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
  set_name("fresh venison");
  set_id(({"venison","food"}));
  set_strength(10);
  set_weight(1);
  set_short("slice of venison");
  set_destroy();
  set_long("a slice of fresh venison");
  set_my_mess("you eat some venison");
  set_your_mess("eats a slice of venison");
  }
