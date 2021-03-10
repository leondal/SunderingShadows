// Cart from Offestry to Tabor. Nienne, 11/05.
#include <std.h>
#include "../../newbie.h"
inherit ROOM;

void driving(object targ, int num);

void create(){
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_name("A shaky little mining cart");
    set_short("%^BOLD%^%^BLACK%^A shaky little mining cart%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A shaky little mining cart%^RESET%^\n"
"%^BLUE%^You are sitting in a rather small, shabby wooden mining cart.  Judging by the little piles of "
"%^ORANGE%^rubble %^BLUE%^in the corners, it is probably used more as often to transport mined stones than "
"people.  It travels along an old track through a %^BOLD%^%^BLACK%^carved tunnel %^RESET%^%^BLUE%^in the "
"mountainside, though just how safe the track is, you really can't tell...%^RESET%^\n");
    set_smell("default","The smells of hard-packed dirt and stale air surround you.");
    set_listen("default","You hear the cart wheels grate against the metal of the tracks.");

    set_items(([
      "tracks":"%^BLUE%^These are old and made of what looks like steel, although it's questionable just how secure they are.%^RESET%^",
      ({"rock","walls"}):"%^BLUE%^The walls are composed mostly of rock but occasionally you see something glimmer brightly.%^RESET%^",
      "cart":"%^BLUE%^The cart is mostly empty, except for a few small piles of rubble in the corner.  Obviously this doesn't regularly transport people.%^RESET%^",
    ]));
}

void init(){
    ::init();
    call_out("driving",10,TP,0);
    add_action("quit_func","quit");
}

void driving(object targ, int num){
  if (!present(targ,TO)) return;
    switch(num){
      case 0:
      tell_object(targ,"\n%^ORANGE%^The sky disappears from view as the tunnel closes in overhead.  As the cart rattles a "
"little and begins to pick up speed, and the stale air begins to rush past your face, you remember a few things you were "
"told before you left Offestry.%^RESET%^\n");
      break;
      case 1:
      tell_object(targ,"\n%^BOLD%^%^BLUE%^You recall talk of a few nearby towns and areas. There is a crossroads down the "
"path from the tunnel's exit, which offers many different roads.\n");
      break;
      case 2:
      tell_object(targ,"%^BOLD%^%^GREEN%^Tabor is the main haven for new adventurers, which is most easily accessed by "
"the ferry east of the crossroads. Those more daring souls may take the western fork instead, and travel due south to "
"reach the town on foot. Many warnings were given not to stray from the road, and to <peer> ahead before blindly running "
"forward, as dangerous creatures frequent the nearby meadows and grasslands.%^RESET%^\n");
      break;
      case 3:
      tell_object(targ,"\n%^BOLD%^%^CYAN%^Muul'daan, directly northeast of the crossroads, offers a similar respite for "
"beasts and other races that the human town Tabor does not tolerate.%^RESET%^\n");
      break;
      case 4:
      tell_object(targ,"\n%^BOLD%^%^WHITE%^Once settled, new travellers often try their hand at fighting some beasts in "
"areas along this road, including the Ebiki Caverns, the Meadowlands, the caves of the Echoes Mountains, the Koenig river "
"and the Goblin Stronghold. The beastly denizens of Muul'daan are warned, however, not to travel too far east or the "
"guards of Shadow City may swiftly put an end to their adventuring.%^RESET%^\n");
      break;
      case 5:
      tell_object(targ,"\n%^BOLD%^%^MAGENTA%^All travellers were warned against trying to contend with the orcs of the "
"encampment past the Meadowlands, Piaf's farm along the river, or the creatures of Yntala forest south of Tabor, as only "
"experienced travellers should risk such places.%^RESET%^\n");
      break;
      case 6:
      tell_object(targ,"\n%^BOLD%^%^RED%^You were also warned that other adventurers may attempt to do you harm now that "
"you have left the training grounds of Offestry, if you drop your player-killing protection. If you wish, you may keep "
"this until L19 but you may not act aggressively towards other players if so. You were pointed towards <help nopk> about "
"this, and <help levelcheck> to know who you may travel with and/or attack, when you meet other adventurers.%^RESET%^\n");
      break;
      case 7:
      tell_object(targ,"\n%^ORANGE%^Your thoughts are suddenly interrupted by the open sky that bursts open above you, "
"and the wheels of the cart screech loudly to a halt. You have enough room here to climb out of the cart.%^RESET%^\n");
      targ->move_player("/d/darkwood/tabor/room/cartroom");
      tell_room(environment(targ),targ->QCN+" climbs out of a freshly-arrived mining cart.",targ);
      return;
      break;
    }
    num++;
    call_out("driving",10,targ,num);
    return;
}

int quit_func(string str) {
   TP->move("/d/darkwood/tabor/room/cartroom");
   tell_room(ETP,TP->QCN+" climbs out of a freshly-arrived mining cart.",TP);
   tell_object(TP,"%^BOLD%^%^WHITE%^The cartride comes to an abrupt halt as you burst out of the tunnel.%^RESET%^");
   TP->force_me("quit");
}