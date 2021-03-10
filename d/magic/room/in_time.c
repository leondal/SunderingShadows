#include <std.h>;
inherit ROOM;

void create(){
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set_property("no teleport",1);
   set_smell("default", "The air smells strangely flat.");
   set_listen("default", "You can't hear anything.");
   set_short("%^BOLD%^%^WHITE%^Inside a %^RESET%^s%^BOLD%^i%^RESET%^l"
      "%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^haze%^RESET%^");
   set_long("Aside from a faint sense of wrongness and a flash of silver, "
      "you are aware of nothing here. Time seems to be standing still.");
}
