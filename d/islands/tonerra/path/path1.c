#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit I_JUNGLE;

void create(){
  ::create();
  set_short("A trail in the jungle");
  set_long(
@VETRI
%^GREEN%^You are walking along a small trail leading into the
jungle. To the west, you can still see the beach and hear the
sounds of the water. You are quickly becoming surrounded by 
large trees and plants and most likely animals. Deeper in the 
jungle, you hear sounds that you cannot identify and the density
of the plant life makes it difficult to see anything off the trail.
VETRI
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear movement in the jungle and wonder if it is the wind.");
  set_exits(([
    "west":I_BEACH+"beach1",
    "southeast":PATH+"path2",
  ]));
}
