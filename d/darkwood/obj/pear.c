

inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
  set_name("pear");
   set_id(({"pear","ripe pear","food","juicy pear"}));
  set_strength(5);
  set_weight(1);
   set_short("A ripe pear");
  set_destroy();
   set_long("This ripe pear looks incredibly juicy, and you can smell the sweet fragarance coming from it.");
   set_my_mess("The pear is as sweet and juicy as you imagined it would be.");
   set_your_mess("eats a juicy pear.");
  }
