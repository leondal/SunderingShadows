#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("no teleport",1);
  set_property("indoors", 1);
  set_short("A Dreadful Banquet Hall");
  set_long("%^RESET%^%^RED%^You have finally made it to the great banquet hall of "
           "the tower! However to you it looks much more like a %^BOLD%^torture "
           "chamber%^RESET%^%^RED%^ for the damned. There is a %^RESET%^%^ORANGE%^great table%^RESET%^%^RED%^ that sits in " 
           "the room's center with comfortable chairs set all around it. "
           "To one side of this table is a %^RESET%^slab%^RESET%^%^RED%^ with %^BOLD%^%^BLACK%^shackles%^RESET%^%^RED%^ that sits " 
           "up right. On the other side of the table sits another %^RESET%^slab%^RESET%^%^RED%^ that lays "
           "flat. There are small tables set near them with many objects for "
           "cutting and slicing. At the head of this table sits a great chair "
           "and behind it are %^MAGENTA%^curtains%^RESET%^%^RED%^. At the other end of the table sits "
           "a %^YELLOW%^brazier%^RESET%^%^RED%^ for cooking and serving things up fresh. You also "
           "notice something odd about the %^ORANGE%^floor%^RESET%^%^RED%^, and that YOU ARE NOT ALONE!%^RESET%^\n");
  set_smell("default", "It smells of blood and evil here.");
  set_listen("default","You hear the sobs and pleas of a small boy near by.");
  set_items( ([
     "table" : "This table is immense and very black. The vibes from it are of nothing but pure evil.",
     "chairs" : "They look very comfortable to sit in.",
     "chair" : "It looks very comfortable to sit in while dining on the innocent.",
     "slab" : "The slabs, at first glance, appear to be flat, but on closer inspection you notice that their centers dip in a bit as if waiting to hold a body.",
     "small table" : "Upon this table there are many different knives and assorted tools, there is even some healing material. They must like their victims to last as long as possible.",
     "curtains" : "It looks like there could be another room behind it.",
     "brazier" : "This is used for cooking things fresh and serving them immediately. You also notice many herbs sitting close at hand to spice with.",
     "floor" : "You notice that there are drains set near each slab. It would appear that they like to keep things fairly clean.",
     "boy" : " It is the spirit girl's little brother!"
]) );
  set_pre_exit_functions( ({"north"}),({"go_north"}) );
  set_exits( ([
     "south" : "/d/koenig/town/tower29",
     "north" : "/d/koenig/town/private.c"
]) );
  set_invis_exits( ({"north"}) );
}

void init() 
{
  ::init();
    add_action("kill","kill");
    add_action("stab","stab");
}

int kill(string str)
{
    if(str != "gentleman") return 0;
    if(!present("ogre guard")) return 0;
    write("%^BOLD%^%^WHITE%^The ogre stops your attempt.");
    say("%^BOLD%^%^WHITE%^The ogre blocks "+TPQCN+"'s attack on the gentleman.");
    return 1;
}

int stab(string str) {
    if(str != "gentleman") return 0;
    if(!present("ogre guard")) return 0;
    write("%^BOLD%^%^WHITE%^The ogre stops your malice.");
    say("%^BOLD%^%^WHITE%^The ogre stops "+TPQCN+"'s malice towards the gentleman.");
    return 1;
}

void reset() {
  ::reset();
if(!present("gentleman"))new("/d/koenig/town/mon/gentleman.c")->move(this_object());
if(!present("ogre guard"))new("/d/koenig/town/mon/ogreguard.c")->move(this_object());
}

int go_north() {
  if(present("gentleman") ) {
  write("%^BOLD%^%^BLACK%^The Gentleman moves to block your path!");
  return 0;
}
  return 1;
}
