#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^This footworn path seems to be connecting the gathering place to the south to the tree"+
      " to the north. The tree has a very broad set of stairs for many people to walk up and down with plenty of room."+
      " The stairs head very high up into the tree, near the branches of the tree. There is a high railing on both sides"+
      " of the staircase to ensure no one falls off the side."+
      " The doorway to the tree is wide and open and does not appear to have an opening and closing door. Around the"+
      " base of the tree there is a small garden growing. There are several different types of flowers being grown here,"+
      " from blue roses to tulips."
   );
   set_items( ([
      "tree":"This is a tall hollowed out tree, the wide opening is a sign of importance.",
      ({ "garden", "flowers" }):"There is an array of beautiful flowers being grown around the base of the tree.",
   ]) );
   set_exits( ([
      "stairs" : TOWN+"healer",
      "south" : TOWN+"center",
   ]) );
}
