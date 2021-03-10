#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("stone");
   set_id(({"keep_stone","stone","unusual stone","unusually shaped stone"}));
   set_short("%^BOLD%^%^BLACK%^An unusually shaped stone%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a very unusually shaped stone. It is cut flat on one side, but rounded "
"and smoothed on the other, almost as if it is supposed to fit into a groove or hole or something. "
"Perhaps if you hold onto it a while you will find some purpose for it?%^RESET%^");
   set_weight(1);
   set_value(0);
}
