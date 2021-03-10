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
   set_short("%^RESET%^%^MAGENTA%^A circular workroom%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^A circular workroom%^RESET%^\n"+
      "The majority of the room is taken up by small %^BOLD%^%^CYAN%^cr"+
      "%^RESET%^%^CYAN%^ys%^BOLD%^tal-topped tables %^RESET%^supported "+
      "by %^BOLD%^%^BLACK%^wrought iron %^RESET%^bases.  Each table "+
      "is granted a pair of %^BOLD%^%^BLACK%^iron chairs %^RESET%^with "+
      "%^YELLOW%^c%^GREEN%^o%^CYAN%^l%^BLUE%^o%^MAGENTA%^r%^RED%^f"+
      "%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^l%^CYAN%^l%^GREEN%^y "+
      "%^YELLOW%^s%^RESET%^%^ORANGE%^t%^BOLD%^r%^RESET%^%^ORANGE%^i"+
      "%^BOLD%^p%^RESET%^%^ORANGE%^e%^BOLD%^d cushions%^RESET%^.  "+
      "Atop several of the tables are %^BOLD%^chisels%^RESET%^ "+
      "and %^BOLD%^hammers %^RESET%^needed "+
      "to carve gems.  The curved %^MAGENTA%^walls%^RESET%^ of "+
      "the room are broken only by the %^BOLD%^archways %^RESET%^"+
      "placed at intervals, each one "+
      "curtained save for the southern archway leading back to the "+
      "fountain.  Just to the west of the archway in the southern wall is a "+
      "small area that has been roped off to allow for psions to "+
      "open rifts to store their most precious crystals.  To the "+
      "right of the southern archway, a sublime %^MAGENTA%^cry%^BOLD%^st%^RESET%^"+
      "%^MAGENTA%^alli%^BOLD%^n%^RESET%^%^MAGENTA%^e staircase %^RESET%^"+
      "curves upward, leading to another floor.\n\n"+
      "The command <help workroom> will instruct you in its use.\n"
   );
   set_listen("default","The low moan of the wind breaks the silence.");
   set_smell("default","A light fragrance of ozone resides in the air here.");
   set_items( ([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^MAGENTA%^"+
         "The smooth walls and floor of this building are carved from "+
         "smooth crystal, translucent and pure.  They are almost "+
         "soft to the touch, and the floor seems to muffle the sound "+
         "of footsteps, almost as if absorbing them.  The walls of "+
         "this room are curved to make a perfect circle, broken only "+
         "by the four archways, three of which are curtained.%^RESET%^",
      ({"doorway","doorways","arches","archway","archways"}) : "The "+
         "walls of the room are unbroken save by the archways leading "+
         "to each of the cardinal directions.  The southern archway "+
         "is the only one left open.",
      ({"curtain","curtains"}) : "The west, north, and east archways "+
         "are each covered by simple curtains in different colors.",
      ({"table","tables","chair","chairs"}) : "%^CYAN%^The tables are "+
         "made with %^BOLD%^%^BLACK%^wrought iron bases %^RESET%^"+
         "%^CYAN%^fashioned into swirls and topped with %^BOLD%^azure "+
         "crystal%^RESET%^%^CYAN%^.  The two chairs bracing each "+
         "table are likewise made of %^BOLD%^%^BLACK%^iron %^RESET%^"+
         "%^CYAN%^and fitted with "+
         "%^YELLOW%^c%^GREEN%^o%^CYAN%^l%^BLUE%^o%^MAGENTA%^r%^RED%^f"+
         "%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^l%^CYAN%^l%^GREEN%^y "+
         "%^YELLOW%^s%^RESET%^%^ORANGE%^t%^BOLD%^r%^RESET%^%^ORANGE%^i"+
         "%^BOLD%^p%^RESET%^%^ORANGE%^e%^BOLD%^d cushions%^RESET%^%^CYAN%^."+
         "%^RESET%^",
      ({"hammers","chisels"}) : "The hammers and chisels are arranged "+
         "in wooden racks, free for anyone to use.  Most psions use "+
         "these to make sure their crystals are perfect before "+
         "manifesting powers or attuning gems.",
      ({"stairs","staircase"}) : "%^RESET%^%^MAGENTA%^The cry%^BOLD%^st%^RESET%^"+
         "%^MAGENTA%^alli%^BOLD%^n%^RESET%^%^MAGENTA%^e staircase is "+
         "made of the same material as the walls of the building.  It "+
         "almost blends in, though each flat step gives off a faint "+
         "shimmer, alerting you to its presence.%^RESET%^"
   ]));
   set_exits(([
      "south" : "/d/shadow/room/city/portal/fountain",
      "west" : "/d/shadow/room/city/portal/alcove1",
      "north" : "/d/shadow/room/city/portal/alcove2",
      "east" : "/d/shadow/room/city/portal/alcove3",
      "stairs" : "/d/shadow/room/city/portal/comps"
   ]));
   setOwner("none");
   setLabId("portal");
   set_door("blue curtain","/d/shadow/room/city/portal/alcove1","west",0,"tie");
   set_door_description("blue curtain","%^BOLD%^%^BLUE%^Made from "+
      "thick blue velvet, this simple curtain covers the archway "+
      "leading to the west.%^RESET%^");
   set_lock_description("blue curtain","tie","This is a simple tie to help hold the curtain closed.");
   set_door("green curtain","/d/shadow/room/city/portal/alcove2","north",0,"tie");
   set_door_description("green curtain","%^GREEN%^Made from "+
      "thick green velvet, this simple curtain covers the archway "+
      "leading to the north.%^RESET%^");
   set_lock_description("green curtain","tie","This is a simple tie to help hold the curtain closed.");
   set_door("yellow curtain","/d/shadow/room/city/portal/alcove3","east",0,"tie");
   set_door_description("yellow curtain","%^YELLOW%^Made from "+
      "thick yellow velvet, this simple curtain covers the archway "+
      "leading to the east.%^RESET%^");
   set_lock_description("yellow curtain","tie","This is a simple tie to help hold the curtain closed.");
}

void reset(){
   ::reset();
   if(!present("kirra")) find_object_or_load("/d/shadow/mon/kirra")->move(TO);
}