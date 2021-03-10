#include <std.h>
#include "../dragon.h";

inherit BPRISON;

void create () {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This small cell does not consist of very much."+
      " There is a small cot and a barrel full of waste. Other than that,"+
      " there is nothing here."
   );
   set_items( ([
      "cot" : "This is a small bed that prisoners slept on.",
      "barrel" : "This barrel is full of human waste.",
   ]) );
   set_exits( ([
      "east" : TOWER+"prison06",
   ]) );
}