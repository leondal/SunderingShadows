//   /d/dragon/town/armorer.c
#include <std.h>
#include <objects.h>

int AL;

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_indoors(1);
  set_short("Armorer's shop");
    set_long("%^BOLD%^%^BLUE%^
The roof of this modest house seems to have been replaced recently, as
evidenced by its weather-worthy appearance.  The house itself is covered
with creepers and ivy.  This is the %^CYAN%^Sanctuary's %^BLUE%^Armory.  Here one
can sell, or buy many forms of armor.  As soon as you enter this house,
you feel intense heat emanating from a large forge located in the corner
of the room.  This very large fire is wafted by bellows to its side.
A large wooden %^RED%^sign%^BLUE%^ hangs behind the front counter.
    ");
  set_smell("default","The smell of oil and iron pervades in this area.");
  set_property("no attack",1);
     set_exits((["west":"/d/dragon/town/roadS1"]));
      set_items(([
  "sign" : "The sign reads: \n"+
           "        %^YELLOW%^Sanctuary's Mender-Open All Hours\n"+
           "        <%^RED%^help shop%^YELLOW%^> will give you a list of commands.\n",
"walls":"The walls are covered with various pieces of iron work -- some quite fancy",
 ] ));
  }
 void reset(){
 ::reset();
  if(!present("morgyr")) {
    new("/d/dragon/mon/morgyr")->move(this_object());
  }
  if(!present("pumpkin")) {
    new("/d/dragon/obj/misc/jack")->move(this_object());
  }
}

void init() {
  ::init();
  if(avatarp(TP)) return;
  AL = this_player()->query_alignment();
  if(present("morgyr")) {
    if((AL == 3) || (AL == 6) || (AL == 9)) {
      tell_room(environment(this_player()), "%^MAGENTA%^Morgyr says:%^RESET%^ Begone from this peaceful place evil spirit!");
      write("Morgyr shoves you out the door and you land upon your face.");
      this_player()->move_player("/d/dragon/town/roadS1");
      return 1;
    }
    tell_room(environment(this_player()), "%^MAGENTA%^Morgyr says: %^RESET%^You seem like reasonable people. You may enter!");
    return 1;
  }
}
