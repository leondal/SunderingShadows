#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({"stone","tombstone"}));
    set_short("Balkour's Tombstone");
    set_long(
    "This stone marks the grave of the fallen hero, Balkour. The "
    "stone is made of pure gold in memory of the sacrifice he made "
    "for the town of Sanctuary. There is an inscription carved into "
    "the gold."
    );
    set_weight(100000);
    set_value(1000000);
}
void init() {
    ::init();
    add_action("read_fun","read");
  }
void read_fun(string str) {
  if(str !="inscription" && str !="stone" && str !="tombstone")
    return 0;
    tell_room(environment(TP),TPQCN +" reads the inscription.",TP);
   tell_object(TP,"It reads: Balkour gave his life for the town of Sanctuary and for that he remains immortal in our hearts.");
    return 1;
  }
