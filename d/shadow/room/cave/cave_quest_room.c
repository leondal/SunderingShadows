//cave_quest_room.c - kobold's hiding place for Pipe Quest
#include "../cave.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light",1);
    set_indoors(1);
    set_property("no teleport",1);
    set_property("no sticks", 1);
    set_terrain(NAT_CAVE);
    set_travel(RUBBLE);
    set_short("Dragon's Den Caverns");
    set_long(
      "%^BOLD%^You are in the Dragon's Den Caverns.%^RESET%^\n"+
      "There appears to be no normal way into this dank, dark cavern.  A "+
      "small %^ORANGE%^pile %^RESET%^of smelly scraps and broken rubble lies within a tiny "+
      "recess in the wall, but the smell emanating from it is quite foul.  "+
      "The %^BOLD%^%^BLACK%^smooth rock wall %^RESET%^of the cavern appears to have been originally "+
      "naturally carved, but it has obviously been hewn and enhanced by "+
      "humanoid hands...or perhaps by %^BOLD%^%^CYAN%^magic%^RESET%^.  A "+
      "s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g "+
      "%^MAGENTA%^portion %^RESET%^of the "+
      "wall draws your attention, and through it, you can see another "+
      "cavern.  The floor here is moist, and strange %^BOLD%^%^GREEN%^fungi %^RESET%^grow along the "+
      "bottom of the walls, emitting a faint green glow."
      );
    set_smell("default","An acrid scent of fungi and nastier things fills the air.");
    set_listen("default","The cave is eerily quiet.");
    set_items(([
      (({"cave","room","cavern"})) : "The smooth rock walls of the cavern allow little "+
         "light to penetrate the darkness here.  The air is damp and dank, filled with the "+
         "scent of acrid fungus.",
      (({"wall","walls","portion","shimmering portion"})) : "The dark gray rock of the "+
         "cavern walls is smooth and unbroken except for a strange round portion.  This "+
         "circular spot shimmers and shifts, and you can see part of a cavern beyond it, "+
         "though it is hard to focus your vision there.  It seems to be a portal of some kind.",
      "portal" : "It looks as though the portal will transport you to another part of the "+
         "caverns.  It is perhaps not safe...but it looks like you have little other choice as "+
         "there seems to be no other way out.",
      (({"pile","scraps","rubble","recess"})) : "The small pile of scraps hidden in the recess "+
         "seems made up of various bits of decayed food and bones.  The smell emanating from it "+
         "is repulsive.",
      (({"fungus","fungi"})) : "The fungi lining the lower walls of the cavern are various "+
         "shades of green and brown and glow faintly, providing what little illumination there "+
         "is in the chamber."
    ]));
    set_exits(([
	"portal" : CAVEDIR+"cave10"
    ]));
}
void reset(){
    object obj;
	::reset();
	if(!(present("malturkurk",TO))){
          obj = new(MONDIR+"malturkurk");
	    obj->move(TO);
	}
}
