//bagpipes.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("bagpipes");
   set_short("Well-made bagpipes");
   set_id(({"bagpipes","well-made bagpipes","pipes","instrument"}));
   set_long("This bulky instrument is made of a skin bag fitted with three "+
      "long reeded pipes.  It has a slender blowpipe, through which the musician "+
      "can produce the necessary force to play the instrument, and it has a "+
      "a long chanter, which is fitted with several holes.  By placing his "+
      "fingers on various holes, the musician can produce a variety of notes.  "+
      "The music of the bagpipe is an acquired taste, and it produces a hollow, "+
      "buzzing harmony.");
   set_weight(5);
   set_value(750);
}
int is_instrument(){return 1;}
