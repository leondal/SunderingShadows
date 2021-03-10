#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit I_JUNGLE;

void create(){
  ::create();
  set_short("A trail in the jungle");
  set_long(
@VETRI
%^GREEN%^You are walking along a small trail leading through the
jungle. You are quickly becoming surrounded by large trees and 
plants and could very easily lose your way. From deeper in the 
jungle, you hear sounds that you cannot identify and the density
of the plant life makes it difficult to see anything off the trail.
This part of the trail seems more defined, as if it is used more
often than some of the others.
VETRI
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear movement coming from the small village.");
  set_exits(([
    "south":PATH+"path9",
    "northeast":PATH+"path11",
  ]));
}
