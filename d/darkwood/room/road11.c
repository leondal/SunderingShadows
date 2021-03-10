#include <std.h>

inherit "/d/darkwood/room/road8.c";

void create() {
    ::create();
    set_long(
"%^GREEN%^You are on the Royal Southern Road entering a dark forest. The light of the sun is almost blotted out by the near-perfect shade of the trees all round you. The thick growth of bushes beneath the trees looks as though it might be hiding any number of unsavory creatures or things. You are haunted by shadows and sounds that seem very unnatural and they all seem to be coming from the path to the west. Perhaps it would be a good idea to move on.

"
);
    set_exits(
              (["north" : "/d/darkwood/room/road10",
                "south" : "/d/darkwood/room/road12",
                 "west":"/d/darkwood/yntala/rooms/forestpath",]) );

}
void reset(){
   ::reset();
    if(!present("sign"))
      new("/d/common/obj/areas/yntala_sign.c")->move(TO);
}
