// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tecqumin_05");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("jungle");
    set_travel("fresh blaze");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A clearing in the jungle%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Barely large enough to be called a clearing, this area pushes the dense foliage of the jungle back and is free of the %^BOLD%^vibrant %^RESET%^%^GREEN%^gr%^BOLD%^ee%^RESET%^%^GREEN%^"
	"n %^BOLD%^pl%^RESET%^%^GREEN%^a%^BOLD%^nts %^RESET%^%^GREEN%^that cluster everywhere else.  Circular in shape, the ground is oddly smooth and free of the natural rises and falls found elsewhere, leadi"
	"ng you to look closer at the ground.  There the outline of a large circular %^BOLD%^%^BLACK%^stone disk %^RESET%^%^GREEN%^can be seen.  Its' stone surface nearly smooth from time's wearing and the enc"
	"roachment of the %^CYAN%^moss %^GREEN%^and %^ORANGE%^weeds %^GREEN%^that crop up on its surface.  Despite this ware, there are clear depictions in the circular stone.  A central figure dominates the m"
	"ain potion of the ring while an outer loop along the rim is filled with over a dozen smaller faces circling.   Some sort of marker, its unclear what it might be pointing to or warning about.%^RESET%^"
	);

    set_smell("default","
%^RESET%^%^ORANGE%^The air is heavy with %^CYAN%^humidity%^ORANGE%^ and the heady scent of %^GREEN%^j%^BOLD%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant life.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^There is the constant hum of insect activity, the bustle and shrill calls of %^MAGENTA%^e%^RED%^x%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^t%^WHITE%^i%^MAGENTA%^c %^GREEN%^birds.%^RESET%^");

    set_search("stone","%^BOLD%^%^BLACK%^You search around the circular stone and think that if you had the right kind of leverage you could lift it.  Sadly, there doesn't appear to be anything nearby that could help.  Wonder what's buried under there.%^RESET%^");
    set_search("disk","%^BOLD%^%^BLACK%^You search around the circular stone and think that if you had the right kind of leverage you could lift it.  Sadly, there doesn't appear to be anything nearby that could help.  Wonder what's buried under there.%^RESET%^");
    set_search("plants","%^GREEN%^You notice a straight sapling that looks like it would be perfect to use as a pole or lever.%^RESET%^");
    
set_items(([ 
	({ "leaves", "waxy leaves", "plants", "plant" }) : "%^RESET%^The jungle is full of all sorts of plant life. You notice a vigorous growth of Dreth's fingers, with massive, %^GREEN%^sh%^WHITE%^i%^GREEN%^ny%^RESET%^, %^BOLD%^%^GREEN%^lush green%^RESET%^, rounded leaves.",
	({ "disk", "stone", "stone disk" }) : "%^BOLD%^%^BLACK%^The disk is covered in weeds and moss that has taken root in the many crevices that make up the %^RESET%^carvings %^BOLD%^%^BLACK%^on the stone.%^RESET%^",
	({ "faces", "carvings", "carving", "depictions" }) : "%^RESET%^%^CYAN%^You clear a few of the weeds away and brush the moss from the stone to reveal several carvings upon the circular disk.  There are a dozen or so small faces that ring the outside of the disk.  Each face has a different expression on their face, or so it appears.  The stylized, blocky sculpting and the wear from many years of exposure makes it harder to figure them out.  The central %^RESET%^figure%^CYAN%^ however is a bit clearer.%^RESET%^",
	({ "figure", "central figure" }) : "%^RESET%^%^ORANGE%^You dust away a bit of moss and pull a couple weeds, then look closely at the central figure on this stone disk.  The blocky style of the carving is a little hard to understand, but you believe it is a man kneeling with his face turned upward.  In his hands he holds a bowl with several round lumps within it, perhaps some sort of vegetable or maybe something less wholesome.  On his back, a bow and quiver of long arrows rests.  Around his neck, several bands of golden plates can be seen, each decorated much like the faces on the %^RESET%^depictions%^ORANGE%^ that ring the outside of the stone disk.%^RESET%^",
	({ "moss", "weeds" }) : "%^RESET%^%^GREEN%^The moss and weeds cling to the stone disk, growing up where dust has collected in the carving.  You could probably clear some of it away and get a better look at the depictions on the stone.%^RESET%^",
	"sapling" : "%^GREEN%^You look closely at the sapling and notice that it looks very strudy.  If you had an axe, you could probably %^WHITE%^cut%^GREEN%^ it down.%^RESET%^",
	]));

    set_exits(([ 
		"down" : "/d/av_rooms/lurue/tecqumin_05a",
		"jungle" : "/d/av_rooms/lurue/tecqumin_01",
	]));

}