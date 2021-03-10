// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tecqumin_03");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("jungle");
    set_travel("fresh blaze");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A clearing in the jungle%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The thick, clingy %^BOLD%^l%^RESET%^%^GREEN%^ea%^BOLD%^ves %^RESET%^%^GREEN%^of the jungle part to reveal a sloped clearing filled with a lush blanket of pale %^BOLD%^%^MAGENTA%^p%^W"
	"HITE%^i%^RESET%^n%^BOLD%^%^MAGENTA%^k b%^WHITE%^l%^RESET%^os%^BOLD%^%^MAGENTA%^so%^RESET%^%^WHITE%^m%^BOLD%^%^MAGENTA%^s%^RESET%^%^GREEN%^.  Their faint coloring, nearly %^RESET%^w%^BOLD%^h%^RESET%^it"
	"%^BOLD%^%^WHITE%^e%^RESET%^%^GREEN%^ upon the deep brown sweep of the forest floor, gives the impression of a blanket of freshly fallen %^BOLD%^%^WHITE%^s%^RESET%^n%^BOLD%^%^CYAN%^o%^WHITE%^w %^RESET%"
	"^%^GREEN%^rolling over the uneven ground of the slope.  A perpetual snowfall of these pale%^BOLD%^%^MAGENTA%^ b%^WHITE%^l%^RESET%^os%^BOLD%^%^MAGENTA%^so%^RESET%^%^WHITE%^m%^BOLD%^%^MAGENTA%^s%^RESET%"
	"^%^GREEN%^ rains down from the thickly %^ORANGE%^b%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^a%^ORANGE%^nc%^BOLD%^%^GREEN%^h%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d %^RESET%^%^GREEN%^tree above.  It's broad li"
	"mbs stretched outward to shade the small clearing.%^RESET%^"
	);

    set_smell("default","
%^RESET%^%^ORANGE%^The heady scent of the %^BOLD%^%^MAGENTA%^b%^WHITE%^l%^RESET%^os%^BOLD%^%^MAGENTA%^so%^RESET%^%^WHITE%^m%^BOLD%^%^MAGENTA%^i%^BOLD%^%^WHITE%^n%^MAGENTA%^g %^RESET%^%^ORANGE%^flower fills your senses.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^There is the constant hum of insect activity, the bustle and shrill calls of %^MAGENTA%^e%^RED%^x%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^t%^WHITE%^i%^MAGENTA%^c %^GREEN%^birds.%^RESET%^");

    set_search("tree","%^RESET%^%^ORANGE%^You search around the roots of the tree but find only a few cast off shells from the tree's seeds.%^RESET%^");
    set_search("blooms","%^BOLD%^%^MAGENTA%^Pushing some of the blossoms away from the ground below you see that the heavy fall of petals has caused the ground below to become soft and mushy with the constant mulching of plant matter.%^RESET%^");
    
set_items(([ 
	({ "leaves", "waxy leaves", "plants", "plant" }) : "%^RESET%^The jungle is full of all sorts of plant life. You notice a vigorous growth of Dreth's fingers, with massive, %^GREEN%^sh%^WHITE%^i%^GREEN%^ny%^RESET%^, %^BOLD%^%^GREEN%^lush green%^RESET%^, rounded leaves.",
	({ "blossoms", "blossom", "petals", "flowers" }) : "%^BOLD%^%^MAGENTA%^Much like a snowfall, the petals fall in a constant swirl of pink and white to shower the surrounding area in their delicate presence.  Each bloom is tiny, barely the size of a fingernail.  Star shaped, thousands cling to the tree and are brushed away by the gentle wind.%^RESET%^",
	({ "limbs", "tree", "branches" }) : "%^RESET%^%^ORANGE%^This sinewy, many branched tree looks incredibly old.  Thick knotted roots jumble and lift the ground into an uneven swell of earth.  The %^BOLD%^%^GREEN%^light green %^RESET%^%^ORANGE%^of the leaves is nearly obscured by the abundant clusters of star shaped %^BOLD%^%^MAGENTA%^b%^WHITE%^l%^RESET%^os%^BOLD%^%^MAGENTA%^so%^RESET%^%^WHITE%^m%^BOLD%^%^MAGENTA%^s%^RESET%^%^ORANGE%^.%^RESET%^",
	"snow" : "%^BOLD%^%^WHITE%^The constant fall of the tree's blossoms could almost look like a snowfall, but for the bloom's rich %^MAGENTA%^pink%^WHITE%^ color.%^RESET%^",
	]));

    set_exits(([ 
		"jungle" : "/d/av_rooms/lurue/tecqumin_01",
	]));

}