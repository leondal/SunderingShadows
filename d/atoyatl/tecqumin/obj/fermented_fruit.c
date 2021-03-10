//Coded by Lujke


#include <std.h>
inherit "/std/food.c";

void create() {
    ::create();
    set_name("mushy red fruit");
    set_id( ({"fruit","red fruit", "mushy red fruit", "mushy fruit", "boozefruit", "booze fruit"
              "food" }) );
    set_short("%^ORANGE%^mushy %^BOLD%^%^RED%^r%^RESET%^%^RED%^e"
      +"%^BOLD%^d fru%^BLACK%^i%^RESET%^t");
    set_weight(1);
    set_long("This mushy, %^ORANGE%^overripe%^BOLD%^%^RED%^ r%^RESET%^%^RED%^e%^BOLD%^d fru%^BLACK%^i%^RED%^t%^RESET%^ is about the size of a peach, but shaped more like a strawberry. It has clearly gone off, and the middle is soft and squishy, with liquid pooling in the very centre.");
    set_my_mess("You bite into the fruit. It's overripe and tastes like it. The middle is soft and has started to ferment. You feel slightly more intoxicated after eating it.");
    set_your_mess("bites into the fruit and makes an interesting face");
}

int eat(string str){
  int result;
  TP->add_intox(200 + random(150));
  return ::eat(str);
}
