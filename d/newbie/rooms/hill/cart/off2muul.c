// Cart from Offestry to Muul'daan. Nienne, 11/05.
#include <std.h>
#include "../../../newbie.h"
inherit ROOM;

void driving(object targ, int num);

void create(){
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_name("A shaky little mining cart");
    set_short("%^BOLD%^%^BLACK%^A mining cart%^RESET%^");
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
    call_out("driving",5,TP,0);
}

void driving(object targ, int num){
  if (!present(targ,TO)) return;
    switch(num){
      case(0):
      tell_object(targ,"\n%^ORANGE%^Another gnome off to the side pulls a lever, and the cart shudders and "
"moves off down the tracks.%^RESET%^\n");
      break;
      case(1):
      tell_object(targ,"\n%^BLUE%^The cart rattles a little and begins to pick up speed, the dull wind in the "
"tunnel starting to rush past your face.%^RESET%^\n");
      break;
      case(2):
      tell_object(targ,"\n%^BOLD%^%^BLACK%^It bumps and bounces along the tracks, the stone walls on either side now whizzing past you at breakneck speed.%^RESET%^\n");
      break;
      case(3):
      tell_object(targ,"\n%^RED%^The tunnel suddenly goes into a sharp turn, making the cart tilt dangerously to the side before the track straightens out again.%^RESET%^\n");
      break;
      case(4):
      tell_object(targ,"\n%^BOLD%^%^BLACK%^Finally the tunnel reaches an incline and the cart starts to slow a little.%^RESET%^\n");
      break;
      case(5):
      tell_object(targ,"\n%^ORANGE%^The wheels squeak as the cart slows even more, reaching the top of the incline and gliding toward a cavern opening ahead of you.%^RESET%^\n");
      break;
      case(6):
      tell_object(targ,"\n%^BLUE%^The stone roof suddenly widens above you as you rattle to a stop, just inside a broad stone cavern, and you find you finally have enough room to climb out of the cart.%^RESET%^\n");
      tell_room(environment(targ),targ->QCN+" climbs out of the mining cart.",targ);
      targ->move_player("/d/shadow/room/muuldaan/rooms/cartroom");
      return;
      break;
    }
    num++;
    call_out("driving",5,targ,num);
    return;
}
