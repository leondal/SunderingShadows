#include <std.h>
#include <objects.h>
      
inherit "/std/room";
      
      void create() {
          room::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
       set_light(2);
       set_indoors(1);
       set_short("Searn's Fine Swords");
       set_long(
@GRAY
As soon as you enter this large building, you feel intense
heat emanating from a big forge in the center.  The very
large fire is wafted by bellows to the side.  The various
anvils, hammers, and other trappings can only mean you
are inside a blacksmith's shop.  Here you can buy and sell weapons.
%^YELLOW%^<help shop>%^RESET%^ will give you shop commands.
A large sign reads: %^RED%^Welcome to Searn's Fine Swords
GRAY
     );
 set_listen("default","The clang of metal reverberates through the store.");
  set_property("no attack",1);
      set_exits((["west":"/d/deku/new/town1"])); 
      set_items(([
        ] ));
  }
void reset(){
  ::reset();
  if(!present("shopkeeper")) {
    new("/d/deku/monster/saern")->move(this_object());
  }
}
