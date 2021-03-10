#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("A grand crystalline fountain");
   set_short("%^RESET%^%^GREEN%^A grand cry%^BOLD%^st%^RESET%^"+
      "%^GREEN%^alli%^BOLD%^n%^RESET%^%^GREEN%^e fountain%^RESET%^");
   set_long("%^RESET%^%^GREEN%^A grand cry%^BOLD%^st%^RESET%^"+
      "%^GREEN%^alli%^BOLD%^n%^RESET%^%^GREEN%^e fountain%^RESET%^\n"+
      "This %^GREEN%^"+
      "ethereal building %^RESET%^is cunningly sculpted from "+
      "the same translucent %^GREEN%^cr%^BOLD%^y%^RESET%^"+
      "%^GREEN%^stal %^RESET%^as the pillars outside and "+
      "boasts towering arches supporting the vaulted ceiling "+
      "topped with a paper-thin dome of %^BOLD%^ir%^CYAN%^i%^WHITE%^des"+
      "%^MAGENTA%^c%^WHITE%^ent %^CYAN%^crystal%^RESET%^.  "+
      "The %^BOLD%^%^GREEN%^co%^CYAN%^lo%^RESET%^"+
      "%^MAGENTA%^r-%^YELLOW%^st%^GREEN%^re%^CYAN%^ak%^RESET%^"+
      "%^MAGENTA%^ed %^BOLD%^%^BLUE%^sky%^RESET%^ is clearly "+
      "visible above, lending a somewhat %^RED%^eerie "+
      "%^RESET%^light to the wide, shallow %^CYAN%^pool %^RESET%^"+
      "filling the majority of the chamber.  Centered under the "+
      "dome is an asymmetrical %^CYAN%^fountain %^RESET%^created "+
      "entirely from darkly-colored crystal.  Each tier of the "+
      "fountain is fashioned into a number of %^BOLD%^%^BLACK%^"+
      "ravens %^RESET%^with their wings spread in flight, each "+
      "with gleaming %^GREEN%^e%^BOLD%^m%^WHITE%^e%^RESET%^%^GREEN%^"+
      "ra%^BOLD%^l%^RESET%^%^GREEN%^d %^RESET%^eyes.  From beneath "+
      "their wings spills %^CYAN%^pure water %^RESET%^that flows "+
      "from the top tier all the way into the pool "+
      "below.  To each side of this square room, the vaulted "+
      "archways lead into different parts of the enclave.\n");
   set_listen("default","The low moan of the wind breaks the silence.");
   set_smell("default","A light fragrance of ozone resides in the air here.");
   set_items( ([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^GREEN%^"+
         "The smooth walls and floor of this building are carved from "+
         "smooth crystal, translucent and pure.  They are almost "+
         "soft to the touch, and the floor seems to muffle the sound "+
         "of footsteps, almost as if absorbing them.%^RESET%^",
      ({"light","lights","dome"}) : "The dome above is crafted from "+
         "the same crystal as the building but is so thin as to seem "+
         "almost colorless.  A faint sheen lends it an %^BOLD%^ir"+
         "%^CYAN%^i%^WHITE%^des%^MAGENTA%^c%^WHITE%^ence %^RESET%^"+
         "that enhances the beauty and peculiarity of the sky above.",
      ({"doorway","doorways","arches","archway","archways"}) : "The "+
         "walls of the room are unbroken save by the archways leading "+
         "to the north, south, east, and west.  Each arch leads into "+
         "a different room, with the western one leading back outside.",
      ({"west archway","west arch","arch 1","western archway","western arch"}) : "The "+
         "western archway leads into a circular workroom often in use by "+
         "psions.  It features several small tables and chairs, and "+
         "you can see three curtained areas along the walls.",
      ({"south archway","southern archway","south arch","southern arch","arch 2"}) : "The "+
         "archway on the southern end of the room leads into a hushed "+
         "chamber.  Through the archway, you can see several rows of chairs "+
         "set facing what looks to be an altar.",
      ({"east archway","eastern archway","east arch","eastern arch","arch 3"}) : "The "+
         "eastern archway reveals a library, which seems to be "+
         "well-stocked and outfitted with numerous couches and desks "+
         "with chairs.",
      ({"north archway","northern archway","north arch","northern arch","arch 4"}) : "The "+
         "northern arch leads out to the entryway, where the nomad "+
         "may be seen standing by the portal circle.",
      ({"pool","shallow pool"}) : "%^CYAN%^The clear pool features "+
         "shallow steps that run the entire perimeter of the pool.  "+
         "Each side has three steps leading down into the bottom, which "+
         "has been tiled with diamond-shaped crystals in shades of "+
         "%^RED%^crimson%^RESET%^%^CYAN%^, %^BOLD%^%^BLACK%^black%^CYAN%^, "+
         "%^GREEN%^green%^RESET%^%^CYAN%^, and accents of %^YELLOW%^"+
         "gold%^RESET%^%^CYAN%^.  The pond is pristinely clear, and the "+
         "cool water looks like an inviting drink.%^RESET%^",
      ({"statue","fountain"}) : "%^BOLD%^The exquisite fountain is "+
         "beautiful beyond description, despite its dark and forboding "+
         "appearance.  It looks to have been carved from a single crystal, "+
         "but that is hardly possible given the multiple colors and "
         "intricate parts.%^RESET%^"
   ]));
   set_property("fill waterskin",1);
   set_exits(([
      "north" : "/d/dagger/tonovi/town/cguilds/psions/foyer",
      "west" : "/d/dagger/tonovi/town/cguilds/psions/workroom",
      "south" : "/d/dagger/tonovi/town/cguilds/psions/shrine",
      "east" : "/d/dagger/tonovi/town/cguilds/psions/library"
   ]));
}

void init() {
    ::init();
    add_action("drink_func", "drink");
}

int drink_func(string str) {
   if(!str) {
      tell_object(TP,"What are you trying to drink?");
      return 0;
   }
   if(str != "water from fountain" && str != "from fountain" && str != "from the fountain" && str != "water from the fountain") {
      tell_object(TP,"Try drinking water from the fountain.");
      return 0;
   }
   if(!TP->add_quenched(20))
      return notify_fail("Your stomach is sloshing already!\n");
   tell_object(TP,"%^CYAN%^You see dancing i%^BOLD%^r%^RESET%^%^CYAN%^i"+
      "de%^BOLD%^%^WHITE%^s%^RESET%^%^CYAN%^ce%^BOLD%^%^MAGENTA%^n"+
      "%^RESET%^%^CYAN%^t lights as you dip your hand into the %^BOLD%^"+
      "cool water %^RESET%^%^CYAN%^and drink.");
   tell_room(TO,TPQCN+" drinks some of the cool water from the fountain.",TP);
   return 1;
}
