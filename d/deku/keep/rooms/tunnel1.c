#include <std.h>
#include "../keep.h"
#define BONE_ITEMS ({"bones","pile","pile of bones","bones pile"})
inherit TUNNEL;

string original_long;

void original_configuration() {
    set_long(original_long + "%^YELLOW%^  The tunnel continues "+
    "into %^BOLD%^%^BLACK%^darkness%^YELLOW%^ toward the "+
    "southwest and ends in a large pile of %^BOLD%^%^WHITE%^"+
    "bones%^YELLOW%^ at what could very well be the "+
    "northeast.%^RESET%^");
}

void create() {
    ::create();
    original_long = TO->query_long();
    original_configuration();  
    set_exits(([
        "southwest": KEEPR + "tunnel2",
    ] ));
    set_search("bones",(:TO,"bones_search":));
    add_items(BONE_ITEMS,"%^BOLD%^%^WHITE%^This large pile of bones is in what could very well be "+
        "the northeast corner of this tunnel, where it ends.  They are obviously from an "+
        "assortment of creatures.  Some of them are large, probably humanoid or even giant, and some "+
        "are much smaller.  One thing is for certain, the pile is large and deep, anything could "+
        "be hidden beneath it.%^RESET%^");
}

int bones_search() {
    object where;
    if(!objectp(TP)) return 0;
    if(member_array("tunnel",TO->query_exits()) == -1) {
        TO->set_long(TO->query_long() + "%^YELLOW%^  An entrance to a %^BOLD%^%^WHITE%^"+
        "tunnel%^YELLOW%^ has been revealed underneath the pile of %^BOLD%^%^WHITE%^"+
        "bones%^YELLOW%^.%^RESET%^");
        tell_object(TP,"You dig through the bones and find the entrance to a %^YELLOW%^"+
        "tunnel%^RESET%^!");
        tell_room(TO,TPQCN+" digs through the bones and uncovers an entrance to a %^YELLOW%^"+
        "tunnel%^RESET%^!",TP);
        TO->add_exit(KEEPR+"dungeon31","tunnel");
        find_object_or_load(DUNGEON);
        where = find_object_or_load(KEEPR + "dungeon31");
        where->add_exit(KEEPR + "tunnel1","tunnel");
        tell_room(where,"%^RED%^Bones begin falling into the floor, revealing a hidden tunnel!%^RESET%^");
        where->set_long(where->query_long() + "%^BOLD%^%^WHITE%^  An entrance to a %^YELLOW%^tunnel%^BOLD%^%^WHITE%^ has been revealed underneath a pile of bones.%^RESET%^");
        return 1;
	}
    tell_room(TO,TPQCN+" digs through the bones.",TP);
    tell_object(TP,"You dig through the bones but find nothing else of value.");
        return 1;
}

void reset() {
  object room;
  ::reset();
  if(sizeof(query_exits()) < 1) return;
  if(member_array("tunnel",query_exits()) != -1) {
        remove_exit("tunnel");
	    original_configuration();
  }  
  if(!objectp(room = find_object_or_load(KEEPR+"dungeon31"))) { return; }
  if(sizeof(room->query_exits()) < 1) return;
  if(member_array("tunnel",room->query_exits()) != -1) {
    room->remove_exit("tunnel");
    room->original_configuration();
  }
 
}
