#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("pylon");
    set_id(({"dark pylon","pylon", "lever"}));
    set_short("%^BOLD%^%^BLUE%^A Dark Pylon");
    set_long(
      "%^RED%^  The pylon is a completely smooth black onyx slab that houses a brass lever.  A warning has been carved in the face of the pylon by someone."
    );
    set_weight(100000);
    set_value(10000);
}

int read(string str){
    if(!str || str != "warning") return  0;

    tell_room(environment(TO),TPQCN+" reads the warning!",TP);
    write("%^BOLD%^Please...  if you are smart enough to read this, then you are smart enough to avoid what lies beyond.  FLEE FROM HERE!  Escape into the oubliette, and out of this world.  Try to take the indigo, or one of the coloured crystals...  GO NO FURTHER!\n");
    return 1;
}

