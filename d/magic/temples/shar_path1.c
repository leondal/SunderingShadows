#include <std.h>
inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1); 
        set_property("light",1);
        set_terrain(BUILT_TUNNEL);
        set_travel(PAVED_ROAD);
        set_name("Obsidian Path"); 
        set_short("%^BOLD%^%^BLACK%^Obs%^WHITE%^i%^BLACK%^d%^WHITE%^"+
           "i%^BLACK%^an Path%^RESET%^");
        set_long("%^RESET%^%^GREEN%^Dense foliage and %^BOLD%^%^"+
           "BLACK%^sinister %^RESET%^%^GREEN%^trees loom over the "+
           "path here on both sides.  The %^BOLD%^%^BLACK%^gl"+
           "%^WHITE%^a%^BLACK%^ssy c%^WHITE%^o%^BLACK%^bbl%^WHITE%^"+
           "e%^BLACK%^st%^WHITE%^o%^BLACK%^nes %^RESET%^%^GREEN%^"+
           "wind a twisting trail through this subterranean forest, "+
           "smothered by the thick treetop canopy that hovers "+
           "overhead.  Gnarled vines hang loosely from the twisted "+
           "claw-like branches and th%^BOLD%^%^RED%^o%^RESET%^"+
           "%^GREEN%^rn filled foliage laced with %^BOLD%^%^BLACK%^"+
           "b%^RESET%^%^CYAN%^e%^MAGENTA%^a%^CYAN%^u%^BOLD%^%^BLACK%^"+
           "t%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^f%^RESET%^%^CYAN%^"+
           "u%^BOLD%^%^BLACK%^l d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^"+
           "rk bl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ss%^RESET%^"+
           "%^CYAN%^o%^BOLD%^%^BLACK%^ms%^RESET%^%^GREEN%^ hedges "+
           "you in on both sides.  The forest almost seems to breathe "+
           "around you, its great trees swaying in concert, expanding "+
           "and contracting over the path in an unsettling dance.  "+
           "The air is filled with a %^BOLD%^%^BLACK%^v%^RED%^i%^BLACK%^"+
           "le %^RED%^e%^BLACK%^n%^RED%^e%^BLACK%^rgy%^RESET%^%^GREEN%^ "+
           "that makes the hairs on your neck stand on end.%^RESET%^\n");
        set_smell("default","%^RESET%^%^GREEN%^The leafy scent of damp "+
           "forest air laced with a hint of lavender fills your "+
           "nostrils.%^RESET%^");
        set_listen("default","%^GREEN%^You can hear the rustling of "+
           "the leaves and the steady roar of crashing water from far "+
           "below.%^RESET%^");
        set_items(([
           ({"trees","tree"}) : "%^GREEN%^Looming over you, the "+
              "trees sway in an unsettling dance, their thick limbs "+
              "tangling overhead to completely block your view of the "+
              "cavern beyond. The groan of shifting wood further "+
              "serves to give your surroundings a %^RED%^malevolent "+
              "sentience%^GREEN%^.%^RESET%^",
           "path" : "%^BOLD%^%^BLACK%^Winding its way through the "+
              "dense undergrowth, this sleek obsidian path glitters "+
              "like the scales of some great serpent.%^RESET%^",
           ({"blossoms","foliage"}) : "%^GREEN%^Leafy ferns and dark "+
              "flora dot the otherwise inpenetrable %^BOLD%^%^BLACK%^"+
              "darkness%^RESET%^%^GREEN%^ of the forest.%^RESET%^"
        ]));
        set_exits(([
           "south" : "/d/magic/temples/shar_lake",
           "west" : "/d/magic/temples/shar_path2"
        ]));
        set_door("black gates","/d/magic/temples/shar_lake","south",0);
        set_door_description("black gates","%^BOLD%^%^BLACK%^Composed "+
           "of thick iron bars, these menacing gates are tipped in "+
           "serrated barbs and %^RESET%^%^GREEN%^overgrown %^BLACK%^"+
           "%^BOLD%^with %^RESET%^%^GREEN%^th%^BOLD%^%^RED%^o%^RESET%^"+
           "%^GREEN%^rny vegetation%^BOLD%^%^BLACK%^.  Flanking the "+
           "gates are two support pillars of rough, %^RESET%^"+
           "%^GREEN%^moss%^BOLD%^%^BLACK%^ covered stone on which "+
           "are perched sleek obsidian panthers with eyes of "+
           "%^RESET%^%^MAGENTA%^violet fl%^BOLD%^%^RED%^a%^RESET%^"+
           "%^MAGENTA%^me%^BOLD%^%^BLACK%^.  The tall walls stretch "+
           "from one edge of the plateau to the other sealing the "+
           "darker %^RESET%^%^GREEN%^foliage%^BOLD%^%^BLACK%^ on "+
           "the far side.%^RESET%^");
}