#include <std.h>
#include <objects.h>

inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("FURNACE OF SOULS.");
    set_long("
    %^RED%^You find yourself on a circular platform in the middle of a field of fire!  Flames leap into the air everywhere around you.  The platform beneath you is rocking back and forth slowly, and a huge red pentagram is painted upon it.
    %^RESET%^Beyond the flames is darkness...

    %^BOLD%^%^BLUE%^A glimmering portal is here.
");

     set_smell("default","%^BOLD%^%^BLACK%^Heavy black smoke fills the air.");
 
    set_exits(([


    ] ));
   set_items(([
    "platform" : "The large circular platform is floating on a field of fire.  It is about 100 feet in diameter.  A large red pentagram covers its surface.",
    "flames" : "Fire leaps at you from unseen depths.",
    "darkness" : "Uh...  It is just dark.",
    "portal" : "It is a spinning vortex of bluish light that flashes brightly every few minutes.",
]));
}

void reset(){
       int num, i;
      ::reset();
       if(!present("warlock")){
                num = random(4)+1;
                for(i=0;i<num;i++)
                       new("/d/attaya/mon/warlock")->move(TO);
       }
    if(!present("magus prime"))
     new("d/attaya/mon/magus")->move(this_object());
}
void init() {
  ::init();
  add_action("enter", "enter");
}
int enter(string str) {
  if(str=="portal") {
 if(present("magus prime")) {
    write("The portal has been magically sealed by the Magus Prime.");
    return 1;
}
  write("You enter the mysterious portal.\n");
  say((string)this_player()->query_cap_name()+" enters the mysterious portal.\n");
  this_player()->move_player("/d/attaya/tower/hallb8");
  return 1;
}
  return 0;
}
