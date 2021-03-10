#include <std.h>
#include "/d/deku/inherits/deku.h"

#define CELLAR "/d/deku/hhouse/cellar.c"

inherit "/d/deku/inherits/hideout_inh.c";

int open;
string original_long;

void query_open_state() {
    return open;
}

void remote_opened(int x) {
    if(x == 1) {
        open = x;
        tell_room(TO,"%^RED%^A section of the north wall slides to "+
        "the slide!%^RESET%^");
        TO->add_exit(BH_ROOMS+"cellar","north");
    }
    if(x == 0) {
        open = x;
        tell_room(TO,"%^RED%^A section of wood slides into place "+
        "over the north doorway!%^RESET%^");
        TO->remove_exit("north");
    }
}

void create() {
    ::create();
   original_long = TO->query_long();
   set_long((:TO,"long_desc":));
   add_item("lever","%^BOLD%^%^WHITE%^This lever is made from a "+
   "piece of iron.  It has been set into the wall at an angle and "+
   "apparently attaches to something within the very wall.  You "+
   "wonder what might happen if you pulled it.%^RESET%^"); 
   set_exits(([
     "south" : BH_ROOMS+"hideout2",
   ] ));
}

void init() {
    ::init();
    add_action("pull_lever","pull");
}

int pull_lever(string str) {
    if(!str) {
        tell_object(TP,"Try pulling the lever?");
        return 1;
    }
    if(str == "lever") {
        if(!open) {
            tell_object(TP,"%^RED%^You pull the lever and a section of the "+
            "north wall slides to the side!%^RESET%^");
            tell_room(TO,TPQCN+"%^RED%^ pulls the lever and a section "+
            "of the north wall slides to the side!%^RESET%^",TP);
            open = 1;
            if((int)CELLAR->query_open_state() == 0) {
                CELLAR->remote_opened(1); 
            }
            TO->add_exit(BH_ROOMS+"cellar","north");
            return 1;
        }

        tell_object(TP,"%^RED%^You pull the lever and a section of "+
        "wood slides back into place over the north doorway!%^RESET%^");
        tell_room(TO,TPQCN+"%^RED%^ pulls the lever and a section "+
        "of wood slides back into place over the north doorways!"+
        "%^RESET%^",TP);

        if((int)CELLAR->query_open_state() == 1) {
            CELLAR->remote_opened(0);
        }
        open = 0;
        TO->remove_exit("north");
        return 1;
    }
    tell_object(TP,"Try pulling the lever?");
    return 1;
}
void reset() {
    ::reset();
  
    if(member_array("north",query_exits()) != -1) {
        remote_opened(0);
    }
    if((int)CELLAR->query_open_state() == 1) {
        CELLAR->remote_opened(0);
    }
}

string long_desc(string str) {
  if(!open) {
    return(original_long + "%^YELLOW%^  A %^RESET%^lever%^YELLOW%^ is "+
    "set in the east side of the north wall of this room.  An open "+
    "doorway leads out of this room to the south.%^RESET%^");
  }
   return(original_long + "%^YELLOW%^  A %^RESET%^lever%^YELLOW%^ is "+
    "set in the east side of the north wall of this room.  An open "+
    "doorway leads out of this room to the south and another "+
    "to the north.%^RESET%^");
}
