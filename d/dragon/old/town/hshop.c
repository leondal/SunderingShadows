
#include <std.h>
#include <objects.h>
#include <money.h>
      
inherit ROOM;

int num;

void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_property("no attack", 1);
  set_short("Sanctuary's magical store");
  set_long(
@GRAYHAWK
%^BLUE%^%^BOLD%^This small building is the establishment of the local %^YELLOW%^Herbalist%^BLUE%^.
Hanging from the counter and along the walls of this well-tended 
residence are several sprigs of garlic and wolfsbane tied together
in bundles.  Wind chimes dangle from the house's eaves, tinkling
and whistling in the wind.  A grimacing pumpkin with firelit 
eyes sits in the window.  A sign next to the counter lists the 
services provided by the herbalist.
GRAYHAWK
  );
  set_smell("default","The room is filled with mingled smells of various herbs.");
  set_exits(([
    "west":"/d/dragon/town/roadS2"
  ]));
  set_items(([
    "sign":"\n"+
      "%^RED%^***************************************************************%^RESET%^\n"+
      "%^GREEN%^                     SERVICES PROVIDED:%^RESET%^\n"+
      "\n"+
      "     Natural potions of healing                      10 gold\n"+
      "         This natural healing, Molly applies herself.\n"+
      "         Type <%^YELLOW%^nheal%^RESET%^> to get Molly to help you.\n"+
      "\n"+
      "     Exotic black roses                              10 gold\n"+
      "          This natural healing flower, Molly grows herself\n"+
      "          Type <%^YELLOW%^brose%^RESET%^> to purchase a black rose.\n"+
      "\n"+
      "%^RED%^***************************************************************%^RESET%^\n",
    "shelves":"These shelves are stacked with the components so vital to survive."
  ] ));
  num = 0;
}

void reset(){
  ::reset();
  if(!present("molly")) {
    new("/d/dragon/mon/molly")->move(this_object());
  }
  if(!present("pumpkin")) {
    new("/d/dragon/obj/misc/jack")->move(this_object());
  }
}

void init() {
  int AL; 
  ::init();
  add_action("natural_heal","nheal");
  add_action("black_rose","brose");
//  if(avatarp(TP)) return;
  AL = TP->query_alignment();
  if(present("molly")) {
    if((AL == 3)||(AL == 6)||(AL==9)) {
      tell_room(TO,"%^MAGENTA%^Molly says:%^RESET%^ Begone from this peaceful place evil spirit!!");
      write("Molly shoves you out the door and you land upon your face.");
      TP->move_player("/d/dragon/town/roadS2");
      TP->set_paralyzed(random(10));
      return;
    }
    tell_room(TO,"%^MAGENTA%^Molly says: %^RESET%^You seem like a reasonable person. You may enter.");
    return;
  }
  return;
}

int natural_heal() {
  if(!present("molly")){
    write("These services cannot be performed without Molly's attendance.");
    return 1;
  }
  if(!TP->query_funds("gold",10)){
    write("%^MAGENTA%^Molly says: %^RESET%^You don't have enough money!");
    return 1;
  }
  tell_room(TO,"%^MAGENTA%^Molly says: %^RESET%^So you would like my services young "+TP->query_race()+".\n");
  TP->add_hp(roll_dice(1,4)+1);
    TP->use_funds("gold",10);
  write("Molly looks around her residence, and brings out a potion of natural healing and wastes no time applying it to your wounds.");
  return 1;
}

int black_rose() {
  if(!present("molly")) {
    write("These services cannot be performed without Molly's attendance.");
    return 1;
  }
  if(num > 5) {
    tell_room(TO,"%^MAGENTA%^Molly says: %^RESET%^I am very sorry, but we are all sold out of the exotic black roses.");
    return 1;
  }
  if(!TP->query_funds("gold",10)){
    write("%^MAGENTA%^Molly says: %^RESET%^You don't have enough money!");
    return 1;
  }
  tell_room(TO,"%^MAGENTA%^Molly says: %^RESET%^So you would like to purchase one of my exotic black roses.");
  new("/d/dragon/obj/misc/brose")->move(TP);
  TP->use_funds("gold",10);
  num = num + 1;
  return 1;
}
