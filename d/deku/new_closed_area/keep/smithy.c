#include <std.h>
      
inherit "/std/room";
      
void create() {
  ::create();
       set_light(2);
       set_indoors(1);
       set_short("Blacktongue's Smithy");
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
       set_long(
@GRAY
As soon as you enter this building you feel intense heat emanating
from the large forge in the center.  This large fire is fanned by
bellows located at its side.  The room is filled with old scraps
of metal, piles of ore, and strange metal working tools.  Here you
can buy and sell weapons.
%^YELLOW%^<help shop>%^RESET%^ will give you shop commands.
A large sign reads: %^RED%^Welcome to the Blacktongue's Smithy
GRAY
     );
 set_listen("default","The clang of metal reverberates through the store.");
 set_exits((["north":"/d/deku/keep/keepE7"])); 
      set_items(([
        ] ));
  }
void reset(){
  ::reset();
  if(!present("shopkeeper")) {
    new("/d/deku/keep/monster/tunturi")->move(TO);
  }
}
