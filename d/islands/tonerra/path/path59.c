#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit I_JUNGLE;

void create(){
  ::create();
  set_short("A trail in the jungle");
  set_long(
@VETRI
%^GREEN%^You are walking along a small trail leading through the
jungle. You quite surrounded by large trees and plants and could 
very easily lose your way. There is a crossing path here, leading
deeper into or perhaps out of the jungle. From deeper in the 
jungle, you hear sounds that you cannot identify and the density
of the plant life makes it difficult to see anything off the trail.
VETRI
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear movement in the jungle and wonder if it is the wind.");
  set_exits(([
    "northeast":PATH+"path58",
    "south":PATH+"path60",
    "northwest":PATH+"path62"
  ]));
}
