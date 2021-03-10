#include <std.h>
#include <objects.h>
inherit ROOM;
void create() {
  room::create();
  set_light(2);
  set_indoors(1);
set_short("Elvanta's Armour Shop");
   set_long(
@GRAY
This building is also enclosed within the tree, and is the
Elvanta Armoury.  Here you can sell, or buy many forms of armour.
Also, accessories, such as helmets and gloves may be found.
%^YELLOW%^<help shop>%^RESET%^ will give a list of shop commands.
GRAY
     );
  set_smell("default","The smell of oil and iron pervades in this area.");
  set_property("no attack",1);
set_exits(([
"north" : "/d/dagger/Elvanta/forest/room116"
]));
      set_items(([
"walls":"The walls are covered with various pieces of iron work -- some quite fancy",
 ] ));
  }
 void reset(){
 ::reset();
if(!present("binabik"))
new("/d/dagger/Elvanta/forest/mon/binabik")->move(this_object());
}
