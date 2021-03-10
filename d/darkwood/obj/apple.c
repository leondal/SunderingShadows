

inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
  set_name("apple");
   set_id(({"apple","red apple","ripe apple","food"}));
  set_strength(5);
  set_weight(1);
   set_short("%^BOLD%^%^RED%^A red apple%^RESET%^");
  set_destroy();
   set_long("This is a large red apple, it has no bruises on it and looks delicious.");
   set_my_mess("You eat a delicious apple.");
   set_your_mess("eats a red apple.");
  }
