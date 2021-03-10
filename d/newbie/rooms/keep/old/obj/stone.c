#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("stone");
   set_id(({"keep_stone","stone","unusual stone","unusually shaped stone"}));
   set_short("An unusually shaped stone");
   set_long("This is a very unusually shaped stone. It is cut flat"+
   " on one side, but rounded and smoothed on the other, almost as"+
   " if it is supposed to fit into a groove or hole or something.");
   set_weight(3);
   set_value(0);
}
