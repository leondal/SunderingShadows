#include <std.h>
#include <objects.h>
      
inherit "/std/room";
      
      void create() {
          room::create();
       set_light(2);
       set_indoors(1);
       set_short("Sanctuary's Weapon Shop");
       set_long("%^BLUE%^%^BOLD%^
This shop is lavishly decorated, but you wouldn't know that from the
outside.  Two badly rusted two-handed swords are crossed above the
counter, on the south wall.  The room resembles an old shrine, with 
the skeleton of a large animal constructed as the counter top.
%^YELLOW%^<help shop>%^BLUE%^ will give you shop commands.
      ");
 set_listen("default","The clang of metal reverberates through the store.");
  set_property("no attack",1);
      set_exits((["east":"/d/dragon/town/roadSW2"])); 
      set_items(([
        ] ));
  }
void reset(){
  ::reset();
  if(!present("shopkeeper")) {
    new("/d/dragon/mon/shop_k")->move(this_object());
  }
  if(!present("pumpkin")) {
    new("/d/dragon/obj/misc/jack")->move(this_object());
  }
}
