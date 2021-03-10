#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit ROOM;

int press_button(string str);

void create() {
  ::create();
  set_name("A dead end");
  set_short("A dead end");
  set_long("The stairs come to an end at a blank %^BOLD%^%^BLACK%^r"
          +"%^RESET%^o%^BOLD%^%^BLACK%^ckf%^RESET%^a%^BOLD%^%^BLACK%^ce"
          +"%^RESET%^, with nowhere else to go. However, there is a small"
          +" button cut into the stone to one side of the wall and the"
          +" obvious action would be to press it.");
 set_terrain(NAT_CAVE);
 set_travel(SLICK_FLOOR);
 set_items( ([ 
 ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of black slate"
                     +". They are smooth, and damp with condensation",
    "button" : "A simple button, set into the rock face of one of the"
              +" walls. You could press it if you wanted."  
   ]) );
  set_listen("default","You can hear a roaring sound below you.");
  set_smell("default","There is a faint smell of water");

  set_exits( ([
	"down":TUNNELS+"alcove"
    ]) );

}

void init()
{
  ::init();
  add_action("press_button", "press");
}

int press_button(string str)
{
  tell_object(TP,"You press the button in the wall.\n"
                +"With a groaning shudder, the"
                +" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^ck"
                +" face%^RESET%^ in front of you rotates, along with the"
                +" section of floor you are standing on, depositing you"
                +" outside on the surface.");
  tell_room(TO,TPQCN + " presses the button in the wall.\n"
                +"With a groaning shudder, the"
                +" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^ck"
                +" face%^RESET%^ in front of " + TPQCN + "you rotates,"
                +" along with the section of floor " + TPQS +"is standing"
                +" on, depositing " + TPQO + " outside.",TP);

  if (sizeof(all_living(TO))<1){return 0;}
  TP->move(find_object_or_load(TUNNELS+"tun_entry"));
  TP->force_me("look");
  
  return 1;
}
