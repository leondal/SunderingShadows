#include <std.h>
#include "../dragon.h";

inherit BGRAVE;
int open;


void create() {
   ::create();
   set_property("light",0);
   set_property("indoors",0);
   set_short("Graveyard of Sanctuary");
   set_long(
      "%^BOLD%^%^BLUE%^You are within the city's graveyard. Old tombstones are strewn about in"+
      " a haphazard fashion. Most were placed here ages ago, and only a few still"+
      " now have writing or dates that can be made out. It seems unusually dark"+
      " and gloomy here, because of the overwhelming shadow of the church. To"+
      " the south you see the huge hole that leads to the Temple of Alphonsus, and to"+
      " the east are signs of a large iron fence that once divided the graveyard from the city."+
      " There is a dug up coffin here."
   );
   set_exits(([
      "south" : TOWN+"grave3"
   ] ));
   set_items(([
      "coffin":"This coffin has been dug up out of it's grave and now lies exposed to the surface. You can open it if you try hard enough."
   ] ));
   open = 0;
}


void init () {
  ::init();
  add_action("open_it", "open");
}

int open_it(string str) {
  if (!str) {
    notify_fail("Open what?\n");
    return 0;
  }
  if (str != "coffin") {
    notify_fail("You can not open that!\n");
    return 0;
  }
  if (open) return notify_fail("It is open already.\n");
  open = 1;
  write("As you open the coffin of the fallen hero, the smell of");
  write("death and corrosion fills the air around you.");
  write("\n");
  write("A heavily armored undead warrior arrises from the coffin");
  write("and attacks.");
  say(TPQCN+" opens the lid of the coffin.\n");
  say("A foul smell fills the air as the open coffin");
  say("reveals an undead warrior posed to attack.");
  new(MON+"balkour")->move(TO);
  return 1;
}

void reset(){
   ::reset();
   if(!present("tombstone"))
   new("/d/dragon/old/obj/misc/tstone1")->move(TO);
   if(open) {
      open = 0;
      return 1;
   }
}
