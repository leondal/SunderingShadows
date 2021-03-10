#include <std.h>
#include "../../elfisland1.h";

inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^This part of the trail is covered in much plant life from the forest as if it is more"+
      " hidden rather than defended. The foot worn dirt path is covered with tall grass here and bushes do not allow"+
      " you to see exactly where the edges of the path are."+ 
      " The way west isn't really defined and hard to see, but with enough looking you"+
      " can find the path into this more spacious part of the forest."
   );
   set_items( ([
      "grass":"Between the thick of the forest and the path, there is several feet of tall grass." 
   ]) );
   set_exits( ([
      "northeast" : TOWN+"road08",
      "southeast" : TOWN+"road10",
      "west" : TOWN+"road13",
   ]) );
}
