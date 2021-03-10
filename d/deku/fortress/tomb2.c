#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit TOMB;

void create() {
    ::create();
    set_long("%^BOLD%^%^WHITE%^You find yourself inside of a "+
    "building that is approximately fifteen feet square.  "+
    "The %^RESET%^%^BLUE%^walls%^BOLD%^%^WHITE%^ of this "+
    "building are made from an unknown, %^RESET%^%^BLUE%^dark "+
    "blue%^BOLD%^%^WHITE%^, substance that continually gives off "+
    "a faint %^CYAN%^glow%^BOLD%^%^WHITE%^.  The %^RESET%^"+
    "%^GREEN%^ceiling%^BOLD%^%^WHITE%^ is covered with a layer "+
    "of thick and wet %^RESET%^%^GREEN%^moss%^BOLD%^%^WHITE%^ that "+
    "masks the identity of whatever substance forms it.  "+
    "The %^MAGENTA%^floor%^BOLD%^%^WHITE%^ is covered with a "+
    "thick layer of %^MAGENTA%^dirt%^BOLD%^%^WHITE%^ that has "+
    "been padded down, suggesting that it is walked upon quite "+
    "often.  The layers of %^MAGENTA%^dirt%^BOLD%^%^WHITE%^ make "+
    "it impossible to determine the identity of the substance that "+
    "forms the floor.  A %^RED%^fountain of blood%^BOLD%^%^WHITE%^ "+
    "rests in the center, its crimson river flowing up and then "+
    "down where it is consumed before being spit back up.  A "+
    "%^CYAN%^glowing door%^BOLD%^%^WHITE%^ leads out of this "+
    "building to whatever lies beyond.%^RESET%^");
    
    set_items(([
    ({"fountain","fountain of blood","blood fountain"}) : "%^RED%^This fountain is made from a solid piece of ruby that extends up from the floor.  It finds no rest, nor peace, its crimson river is ever flowing, once up, then down, before being consumed at its base near the floor, and eventually spit back up.  A thought comes to you, that perhaps, if you were desperate enough, you could %^RESET%^drink%^RED%^ from its crimson river.%^RESET%^",
    ({"floor","dirt covered floor"}) : "%^MAGENTA%^The floor of this building is covered with layers of padded dirt that masks the identity of whatever substance it is formed from and suggest that it is walked upon quite often.  An ever-flowing %^RED%^ruby fountain%^MAGENTA%^ extends upward from the center of it.%^RESET%^",
    ({"ceiling"}) : "%^GREEN%^The ceiling of this building is covered with a thick and wet moss.  The moss masks the identity of the substance that forms the ceiling.%^RESET%^",
    ({"walls","wall","dark blue","dark blue substance","substance"}) : "%^BLUE%^The walls of this building are created from an unknown and dark blue substance.  Strangely, it continually gives off a faint %^CYAN%^glow%^RESET%^%^BLUE%^.%^RESET%^",
    ({"moss","thick moss","wet moss","thick and wet moss"}) : "%^GREEN%^This thick and wet moss covers the ceiling here, masking the identity of the substance that forms it.%^RESET%^",
    ({"dirt"}) : "%^MAGENTA%^Thick layers of padded dirt cover the floor here, masking the identify of the substance that forms it, and suggesting that the floor is walked upon quite often.%^RESET%^",
    ({"glow","faint glow"}) : "%^CYAN%^A faint glow is being continually given off by the walls of this building.%^RESET%^",
    ]));
    
    set_listen("default","%^RED%^A loud gurgling sound fills the room, emitted by the ever-flowing fountain.%^RESET%^");
    set_smell("default","%^BOLD%^%^GREEN%^The hideous odor of death lingers here and mixes with the foul scent of blood.%^RESET%^");
    
    set_exits(([
    "out" : GY_ROOMS+"grave6-5"
    ] ));
  
    set_door("glowing door",GY_ROOMS+"grave6-5","out");
    set_string("glowing door", "open", "%^CYAN%^The door swings "+
    "silently and effortlessly outward.%^RESET%^");
    set_door_description("glowing door","%^BOLD%^%^CYAN%^This "+
    "glowing door is made from an unknown substance.  It doesn't "+
    "appear to be solid yet somehow it manages to completely "+
    "obscure any attempt at viewing whatever may linger behind "+
    "it.%^RESET%^");
}

void reset() {
  ::reset();
  if(random(10) >= 5 && !present("zombie lord")) {
    new(GY_MOBS+"zombielord")->move(TO);
  }
}

void init() {
  ::init();
  add_action("drink_action","drink");
}

int drink_action(string str) {
  if(!str) return 0;
  if(str == "from fountain" || str == "blood" || str == "blood from fountain" || str == "fountain") {
    if(!TP->query_invis()) {
      tell_room(TO,TP->QCN+"%^RED%^ dips "+TP->QP+"%^RED%^ head into the fountain and takes a drink from its crimson river!%^RESET%^",TP);
    }
    tell_object(TP,"%^RED%^You dip your head into the fountain and take a drink of its crimson river and instantly you begin to feel ill!%^RESET%^");
    TP->add_poisoning(20 + random(21));
    TP->setPoisoner(TO);
    return 1;
  }
  return 0;
}
  