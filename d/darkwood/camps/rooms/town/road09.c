#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^This wide path extends in two directions. It goes on to southeast, which appears to lead"+
      " to a clearing. It also runs to the northwest which leads up to a tree with multiple wide doorways. Around the"+
      " base of the tree is a tiny set of steps that lead up to the many doorways. The tree itself is surrounded by"+
      " tall grass on all sides except the path that leads from the largest doorway of the tree."
   );
   set_items( ([
      "tree":"This large tree has several doorways, implying that many villagers visit this spot." 
   ]) );
   set_exits( ([
      "enter" : TOWN+"market",
      "southeast" : TOWN"road08",
   ]) );
}
