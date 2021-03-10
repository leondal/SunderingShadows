#include <std.h>

inherit VAULT;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("A curtained alcove");
   set_short("%^BOLD%^%^BLUE%^A curtained alcove%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^A curtained alcove%^RESET%^\n"+
      "%^BOLD%^%^BLACK%^This rather dark alcove is lit only "+
      "by a %^WHITE%^luminescent orb %^BLACK%^hovering about "+
      "three feet over the surface of a simple iron table.  "+
      "Atop the table is a miniature %^CYAN%^crystal ball %^BLACK%^"+
      "of the sort used by psions.  There are two small chairs, "+
      "one on either side of the table.  The walls seem to press "+
      "close here, creating a cavernous sense when the curtain is "+
      "closed.%^RESET%^\n");
   set_smell("default","A crisp, clean fragrance permeates the air.");
   set_listen("default","A faint whispering seems just beyond hearing.");
   set_items(([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^GREEN%^"+
         "The smooth walls and floor of this building are carved from "+
         "smooth crystal, translucent and pure.  They are almost "+
         "soft to the touch, and the floor seems to muffle the sound "+
         "of footsteps, almost as if absorbing them.  In this small "+
         "space, the walls seem oppressively close.%^RESET%^",
      ({"table","chairs","chair"}) : "%^BOLD%^%^BLACK%^The table "+
         "and chairs are made purely of wrought iron crafted with "+
         "a swirling design to create the flat surfaces.  They are "+
         "ornate in their own way, but nothing quite as much as "+
         "those in the workroom proper.%^RESET%^",
      ({"orb","luminescent orb","light"}) : "%^BOLD%^%^WHITE%^The "+
         "luminescent orb features a faintly %^CYAN%^silver %^WHITE%^"+
         "light that illuminates the alcove nicely without "+
         "interfering with viewings in the crystal ball.%^RESET%^"
   ]));
   set_exits(([
      "north" : "/d/dagger/tonovi/town/cguilds/psions/workroom"
   ]));
   set_door("red curtain","/d/dagger/tonovi/town/cguilds/psions/workroom","north",0,"tie");
   set_door_description("red curtain","%^BOLD%^%^BLUE%^Made from "+
      "thick crimson velvet, this simple curtain covers the archway "+
      "leading to the north.%^RESET%^");
   set_lock_description("red curtain","tie","This is a simple tie to help hold the curtain closed.");
}

void reset(){
   ::reset();
   if(!present("crystal ball")) new("/d/magic/obj/crystal_ball")->move(TO);
}
