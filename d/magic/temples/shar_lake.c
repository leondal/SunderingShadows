#include <std.h>
inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1); 
        set_property("light",1);
        set_terrain(BUILT_TUNNEL);
        set_travel(PAVED_ROAD);
        set_name("%^BLUE%^Darktide Lake%^RESET%^"); 
        set_short("%^BLUE%^Darktide Lake%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^You have emerged on a rocky "+
           "outcropping that hovers far above the undisturbed "+
           "darkness of an enormous %^RESET%^%^BLUE%^subterranean "+
           "lake%^BOLD%^%^BLACK%^.  Jagged boulders of obsidian "+
           "are scattered across the floor, intermixed with the loose "+
           "stones and %^WHITE%^cr%^RESET%^%^MAGENTA%^y%^BOLD%^"+
           "%^WHITE%^st%^CYAN%^a%^WHITE%^ll%^RESET%^%^MAGENTA%^i"+
           "%^BOLD%^%^WHITE%^n%^CYAN%^e%^RESET%^ %^MAGENTA%^c"+
           "%^BOLD%^a%^RESET%^%^MAGENTA%^ve fl%^BOLD%^o%^RESET%^"+
           "%^MAGENTA%^wers%^BOLD%^%^BLACK%^.  Farther ahead, "+
           "tall black gates bar the way to the rest of the plateau.  "+
           "%^RESET%^Sconces %^BOLD%^%^BLACK%^line the gates casting "+
           "their %^RESET%^%^MAGENTA%^fl%^BOLD%^i%^RESET%^%^MAGENTA%^"+
           "cker%^BOLD%^i%^RESET%^%^MAGENTA%^ng l%^BOLD%^i%^RESET%^"+
           "%^MAGENTA%^ght %^BOLD%^%^BLACK%^across the pol%^WHITE%^i"+
           "%^BLACK%^sh%^WHITE%^e%^BLACK%^d black cobblestones that "+
           "form a path just beyond the wall.  %^RESET%^%^GREEN%^"+
           "Thick leafy foliage %^BOLD%^%^BLACK%^grows on either "+
           "side of the path, their dark and %^RESET%^%^GREEN%^th"+
           "%^BOLD%^%^RED%^o%^RESET%^%^GREEN%^rny vines %^BOLD%^"+
           "%^BLACK%^slithering insidiously through the gaps in the "+
           "bars.  The nebulous %^RESET%^%^GREEN%^forest %^BOLD%^"+
           "%^BLACK%^that dominates the majority of this mesa looms "+
           "over the bars of the wall, its claw like limbs reaching "+
           "through as if trying to burst free of its prison.  "+
           "Spilling over the edges of the plateau on both sides "+
           "are several small %^RESET%^%^BLUE%^waterfalls%^BOLD%^"+
           "%^BLACK%^.  The cavern itself stretches out "+
           "beyond your sight into absolute darkness leaving you "+
           "feeling very small indeed.%^RESET%^\n");
        set_smell("default","%^RESET%^%^GREEN%^The leafy scent "+
           "of damp forest air laced with a hint of lavender "+
           "fills your nostrils.%^RESET%^");
        set_listen("default","%^GREEN%^You can hear the rustling "+
           "of the leaves and the steady roar of crashing water "+
           "from far below.%^RESET%^");
        set_items(([
           "lake" : "%^BLUE%^Like some long hidden ocean of "+
              "%^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^, this "+
              "vast lake stretches well beyond sight into the "+
              "unknown reaches of this cavern.  The %^BOLD%^"+
              "%^BLACK%^dark %^RESET%^%^BLUE%^water ch%^BOLD%^"+
              "%^CYAN%^u%^RESET%^%^BLUE%^rns at the base of the "+
              "cliffs where the waterfalls cascade down to crash "+
              "into the %^BOLD%^%^BLACK%^jagged rocks%^RESET%^"+
              "%^BLUE%^.%^RESET%^",
           ({"floor","cave flowers"}) : "%^BOLD%^%^BLACK%^"+
              "Interspersed with the boulders and pebbles on "+
              "the cave floor are %^RESET%^%^MAGENTA%^sh%^BOLD%^"+
              "i%^RESET%^%^MAGENTA%^mm%^BOLD%^e%^RESET%^%^MAGENTA%^"+
              "r%^BOLD%^i%^RESET%^%^MAGENTA%^ng %^WHITE%^cr%^RESET%^"+
              "%^MAGENTA%^y%^BOLD%^%^WHITE%^st%^CYAN%^a%^WHITE%^ll"+
              "%^RESET%^%^MAGENTA%^i%^BOLD%^%^WHITE%^n%^CYAN%^e"+
              "%^RESET%^ %^MAGENTA%^c%^BOLD%^a%^RESET%^%^MAGENTA%^"+
              "ve fl%^BOLD%^o%^RESET%^%^MAGENTA%^wers%^BOLD%^"+
              "%^BLACK%^ jutting from the ground in jagged spikes.  "+
              "They are surrounded by a %^RESET%^%^MAGENTA%^fa"+
              "%^BOLD%^i%^RESET%^%^MAGENTA%^nt lum%^BOLD%^i%^RESET%^"+
              "%^MAGENTA%^nescence %^BOLD%^%^BLACK%^in several "+
              "%^RESET%^%^MAGENTA%^hues %^BOLD%^%^BLACK%^of "+
              "%^RESET%^%^MAGENTA%^violet %^BOLD%^%^BLACK%^that "+
              "give the surroundings a surreal dream-like look.%^RESET%^",
           ({"foliage","vines","forest","trees"}) : "%^GREEN%^The "+
              "dense foliage is brimming over the bars of the wall "+
              "as if trying to escape the confinement of the plateau"+
              ".  Leafy ferns and dark flora dot the otherwise "+
              "impenetrable darkness of the forest.%^RESET%^",
           ({"waterfall","waterfalls"}) : "%^BLUE%^Spilling from "+
              "the edges of the plateau on both sides are a number "+
              "of waterfalls that cr%^BOLD%^a%^RESET%^%^BLUE%^sh "+
              "into the %^BOLD%^%^BLACK%^rocky %^RESET%^%^BLUE%^"+
              "surf far below.%^RESET%^",
           "boulders" : "%^BOLD%^%^BLACK%^These massive obs%^WHITE%^"+
              "i%^BLACK%^d%^WHITE%^i%^BLACK%^an boulders seem like "+
              "nothing more then unworked stone at first glance.  "+
              "Upon closer examination however, you realize that "+
              "hidden within the gl%^WHITE%^a%^BLACK%^ssy material "+
              "you can make out the %^CYAN%^frozen %^BLACK%^features "+
              "of men and women trapped within!%^RESET%^"
        ]));
        set_exits(([
           "southeast" : "/d/magic/temples/shar_tunnel",
           "north" : "/d/magic/temples/shar_path1"           
        ]));
        set_door("black gates","/d/magic/temples/shar_path1","north",0);
        set_door_description("black gates","%^BOLD%^%^BLACK%^"+
           "Composed of thick iron bars, these menacing gates are "+
           "tipped in serrated barbs and %^RESET%^%^GREEN%^overgrown "+
           "%^BLACK%^%^BOLD%^with %^RESET%^%^GREEN%^th%^BOLD%^%^RED%^"+
           "o%^RESET%^%^GREEN%^rny vegetation%^BOLD%^%^BLACK%^.  "+
           "Flanking the gates are two support pillars of rough, "+
           "%^RESET%^%^GREEN%^moss%^BOLD%^%^BLACK%^ covered stone "+
           "on which are perched sleek obsidian panthers with eyes "+
           "of %^RESET%^%^MAGENTA%^violet fl%^BOLD%^%^RED%^a%^RESET%^"+
           "%^MAGENTA%^me%^BOLD%^%^BLACK%^.  The tall walls stretch "+
           "from one edge of the plateau to the other sealing the "+
           "darker %^RESET%^%^GREEN%^foliage%^BOLD%^%^BLACK%^ on the "+
           "far side.%^RESET%^");
}