#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^Off to the northwest you can see what appears to be a popular spot in town. There are"+
      " several ways to enter and exit the building, implying that many of the villagers head this way. Off to"+
      " the southeast is a larger opening in what appears to be the middle of town. There are several paths stemming"+
      " from that clearing. The path here is wide and well defined as far as paths in this village goes. Off to the"+
      " right and left of the path is several feet of tall grass before the thick of the forest defines a more solid"+
      " boundary."
   );
   set_items( ([
      "grass":"Between the thick of the forest and the path, there is several feet of tall grass." 
   ]) );
   set_exits( ([
      "northwest" : TOWN+"road09",
      "southwest" : TOWN+"road12",
      "southeast" : TOWN+"center",
   ]) );
}
