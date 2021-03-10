#include <std.h>

inherit "/std/psi_lab";

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("A circular workroom");
   set_short("%^RESET%^%^GREEN%^A circular workroom%^RESET%^");
   set_long("%^RESET%^%^GREEN%^A circular workroom%^RESET%^\n"+
      "The majority of the room is taken up by small %^BOLD%^%^CYAN%^cr"+
      "%^RESET%^%^CYAN%^ys%^BOLD%^tal-topped tables %^RESET%^supported "+
      "by %^BOLD%^%^BLACK%^wrought iron %^RESET%^bases.  Each table "+
      "is granted a pair of %^BOLD%^%^BLACK%^iron chairs %^RESET%^with "+
      "%^RED%^deep cr%^BOLD%^i%^RESET%^%^RED%^mson%^RESET%^ cushions.  "+
      "Atop several of the tables are %^BOLD%^chisels%^RESET%^ "+
      "and %^BOLD%^hammers %^RESET%^needed "+
      "to carve gems.  The curved %^GREEN%^walls%^RESET%^ of "+
      "the room are broken only by the three %^BOLD%^archways %^RESET%^"+
      "placed at intervals, with the north and south obscured each "+
      "by a thick curtain.  Just along the western wall is a "+
      "small area that has been roped off to allow for psions to "+
      "open rifts to store their most precious crystals.  To the "+
      "right of the southern archway, a sublime %^GREEN%^cry%^BOLD%^st%^RESET%^"+
      "%^GREEN%^alli%^BOLD%^n%^RESET%^%^GREEN%^e staircase %^RESET%^"+
      "curves upward, leading to another floor.\n\n"+
      "The command <help workroom> will instruct you in its use.\n"
   );
   set_listen("default","The low moan of the wind breaks the silence.");
   set_smell("default","A light fragrance of ozone resides in the air here.");
   set_items( ([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^GREEN%^"+
         "The smooth walls and floor of this building are carved from "+
         "smooth crystal, translucent and pure.  They are almost "+
         "soft to the touch, and the floor seems to muffle the sound "+
         "of footsteps, almost as if absorbing them.  The walls of "+
         "this room are curved to make a perfect circle, broken only "+
         "by the three archways, two of which are curtained.%^RESET%^",
      ({"doorway","doorways","arches","archway","archways"}) : "The "+
         "walls of the room are unbroken save by the archways leading "+
         "to each of the cardinal directions except the west.  "+
         "Curtains obscure the north and south from view.",
      ({"curtain","curtains"}) : "The north and south archways "+
         "are each covered by simple curtains in different colors.",
      ({"table","tables","chair","chairs"}) : "%^CYAN%^The tables are "+
         "made with %^BOLD%^%^BLACK%^wrought iron bases %^RESET%^"+
         "%^CYAN%^fashioned into swirls and topped with %^BOLD%^azure "+
         "crystal%^RESET%^%^CYAN%^.  The two chairs bracing each "+
         "table are likewise made of %^BOLD%^%^BLACK%^iron %^RESET%^"+
         "%^CYAN%^and fitted with %^RED%^deep cr%^BOLD%^i%^RESET%^"+
         "%^RED%^mson%^RESET%^%^CYAN%^ cushions.%^RESET%^",
      ({"hammers","chisels"}) : "The hammers and chisels are arranged "+
         "in wooden racks, free for anyone to use.  Most psions use "+
         "these to make sure their crystals are perfect before "+
         "manifesting powers or attuning gems.",
      ({"stairs","staircase"}) : "%^RESET%^%^GREEN%^The cry%^BOLD%^st%^RESET%^"+
         "%^GREEN%^alli%^BOLD%^n%^RESET%^%^GREEN%^e staircase is "+
         "made of the same material as the walls of the building.  It "+
         "almost blends in, though each flat step gives off a faint "+
         "shimmer, alerting you to its presence.%^RESET%^"
   ]));
   set_exits(([
      "east" : "/d/dagger/tonovi/town/cguilds/psions/fountain",
      "south" : "/d/dagger/tonovi/town/cguilds/psions/alcove1",
      "north" : "/d/dagger/tonovi/town/cguilds/psions/alcove2",
      "stairs" : "/d/dagger/tonovi/town/cguilds/psions/comps"
   ]));
   setOwner("none");
   setLabId("tonoviportal");
   set_door("red curtain","/d/dagger/tonovi/town/cguilds/psions/alcove1","south",0,"tie");
   set_door_description("red curtain","%^BOLD%^%^RED%^Made from "+
      "thick crimson velvet, this simple curtain covers the archway "+
      "leading to the south.%^RESET%^");
   set_lock_description("red curtain","tie","This is a simple tie to help hold the curtain closed.");
   set_door("green curtain","/d/dagger/tonovi/town/cguilds/psions/alcove2","north",0,"tie");
   set_door_description("green curtain","%^GREEN%^Made from "+
      "thick green velvet, this simple curtain covers the archway "+
      "leading to the north.%^RESET%^");
   set_lock_description("green curtain","tie","This is a simple tie to help hold the curtain closed.");
}

void reset(){
   ::reset();
   if(!present("hroath")) find_object_or_load("/d/dagger/tonovi/mon/hroath")->move(TO);
}