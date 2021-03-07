//path6.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>

#include "../koenig.h"
inherit PATH;

void create()
{
   ::create();
   set_long(
	"This is a %^ORANGE%^ro%^BOLD%^c%^RESET%^%^ORANGE%^ky p%^BOLD%^a%^RESET%^%^ORANGE%^th %^WHITE%^that winds slowly through the %^GREEN%^foothills %^WHITE%^of the mountains. The path has been mostly cleared of the larger rocks, but smaller stones make for rough traveling. The surrounding area is also ro%^BOLD%^%^BLACK%^ck%^RESET%^y, not many %^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^l%^BOLD%^ant%^RESET%^%^GREEN%^s %^WHITE%^seem to like the mountain climate, but a few %^BOLD%^%^GREEN%^bushes %^RESET%^appear to be growing here. A cool %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^ind %^WHITE%^seems to be constantly blowing, and you can hear it whistling through the %^BOLD%^peaks %^RESET%^far above. The path here isn't very steep, and it stays relatively close to the sheer %^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^u%^RESET%^n%^BOLD%^%^BLACK%^t%^RESET%^a%^BOLD%^%^BLACK%^i%^RESET%^n cl%^BOLD%^%^BLACK%^if%^RESET%^f.\n");
	set_search("default","There are a lot of rocks and dust on the trail, but"+
	   " not much else.");
   set_search("default","A few bushes look out of place.");
   set_exits(([
   "west" : VILSTREAM"path5",
   "southeast" : VILSTREAM"path7",
   ]));
   set_items(([
	({"mountains","mountain"}) : "The mountain range rising to the south and east separates this land from the Tsarven empire to the south.  Rising far to the north are the Echoes Mountains, and these foothills form the majority of the land in between the two ranges.",
	({"path","rocky path"}) : "This path has really just been picked clear of the larger rocks. It is still littered with pebbles and isn't very smooth. It looks like it may once have gotten a fair bit of use, but not for a while.",
	({"cliff","sheer cliff","cliff face","mountain cliff"}) : "To the east is the sheer cliff face of the mountains. It is tall and steep, not even the most expert climber could climb that. It reaches high into the air, disappearing far above the clouds.",
      ({"bush","bushes"}):"%^RESET%^%^GREEN%^A few bushes look like they might be hiding something.",
      "hole":"%^BOLD%^%^BLACK%^There is a large hole in the cliff face, perhaps you can enter it?%^RESET%^",
   ]));
   set_search("bushes","You move the bushes out of the way and find a hole in the cliff face.");
}
void init(){
  ::init();
  add_action("enter","enter");
}
int enter(string str){
   if(str == "hole"){
   tell_object(TP,"%^RESET%^%^ORANGE%^You scramble over the rocks, through the bushes and into the hole.%^RESET%^");
   tell_room(ETP,""+TPQCN+" scrambles over the rocks, through the bushes, and into the hole.",TP);
   this_player()->move_player(INRMS+"cr1.c");
   return 1;
   }
}

