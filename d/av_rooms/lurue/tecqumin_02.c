// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tecqumin_02");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("jungle");
    set_travel("fresh blaze");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A clearing in the jungle%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The jungle forms a dense %^BOLD%^%^BLACK%^tangle%^RESET%^%^GREEN%^, barring passage in most directions.  %^BOLD%^Vibrant %^RESET%^%^GREEN%^gr%^BOLD%^ee%^RESET%^%^GREEN%^n %^BOLD%^pl%"
	"^RESET%^%^GREEN%^a%^BOLD%^nts %^RESET%^%^GREEN%^with thick, waxy leaves gather round the bases of %^BOLD%^%^BLACK%^ancient %^RESET%^%^GREEN%^growth trees with thick boles and twisted branches.  Here t"
	"hough the trees open up a bit, revealing a small set of ruins that spill in a tumble of aged %^RESET%^%^ORANGE%^s%^RESET%^o%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^pst%^BLACK%^%^BOLD%^o%^RESET%^%^ORANGE%^"
	"ne %^GREEN%^blocks.  A pillar at one time, age has pox-marked the carved surfaces into almost unrecognizable symbols.  Only a few of the larger ones can be made out, and even they have deteriorated un"
	"der the attention of the %^BLUE%^el%^RED%^em%^GREEN%^en%^WHITE%^ts%^GREEN%^.  Small creatures, lizards, spiders and lesser insects, crawl about these remains in a constant flicker of movement that sto"
	"ps only when they sense something larger near.%^RESET%^ "
	);

    set_smell("default","
%^RESET%^%^ORANGE%^The air is heavy with %^CYAN%^humidity%^ORANGE%^ and the heady scent of %^GREEN%^j%^BOLD%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant life.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^There is the constant hum of insect activity, the bustle and shrill calls of %^MAGENTA%^e%^RED%^x%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^t%^WHITE%^i%^MAGENTA%^c %^GREEN%^birds.%^RESET%^");

    
set_items(([ 
	({ "spiders", "spider" }) : "%^BOLD%^%^BLACK%^Tiny spiders weave webs around the pillar's niches, making their homes in the deepest of holes where they wait for some moth, fly or other insect to explore and become trapped in the tacky web.%^RESET%^",
	({ "lizard", "lizards" }) : "%^RESET%^%^ORANGE%^Little brown lizards only as long as your thumb hunt about the worn surface of this pillar, searching for insects to make a lunch of. Nearly the same color as the soapstone they move around on, they can be spotted by their bright %^YELLOW%^yellow%^RESET%^%^ORANGE%^ markings.%^RESET%^",
	({ "image 3", "image three" }) : "%^BOLD%^%^GREEN%^This carving faces north and features a wide hipped woman with her chest covered in fanciful necklaces of golden plates.  This circle of necklaces hang low enough to cover her chest, and a skirt of wide leaves covers her legs.  Before her, she holds a male child.  Beside her you can see a part of a curved blade lifted above the child's exposed head.  The remainder of the carving is worn away.%^RESET%^",
	({ "image 2", "image two" }) : "%^BOLD%^%^BLACK%^This carving faces south and is smaller then the other two you can make out.  The image is that of a pair of animals facing away from each other.  One looks to be a lizard with a decorative collar around his neck, while the other looks like a leopard.  The two have their tails intertwined.%^RESET%^",
	({ "image 1", "image one" }) : "%^RESET%^%^RED%^This carving faces east, toward the rising sun.  Studying it closely, you can make out the figure of a humanoid holding a large flame topped spear.  His head is covered in an ornate head dress of feathers and golden blocks.  An elaborately decorated loin cloth covers his lower body, but his muscular upper body is shown with a bloody claw mark across it.%^RESET%^",
	({ "carvings", "images" }) : "%^RESET%^%^ORANGE%^You circle around the pillar and can find three images that are clear enough to make out.%^RESET%^",
	({ "ruins", "soapstone", "pillar", "blocks" }) : "%^BOLD%^%^BLACK%^The remains of a pillar are found here.  Made from large soapstone blocks piled one on top of the other, someone has carved several symbols into each side of the pillar, though the weather has worn many of the smaller markings smooth.%^RESET%^",
	({ "leaves", "waxy leaves", "plants", "plant" }) : "%^RESET%^The jungle is full of all sorts of plant life. You notice a vigorous growth of Dreth's fingers, with massive, %^GREEN%^sh%^WHITE%^i%^GREEN%^ny%^RESET%^, %^BOLD%^%^GREEN%^lush green%^RESET%^, rounded leaves.",
	"creatures" : "%^GREEN%^All sorts of little creatures have made the holes and crevices within this pillar their home.  You can see lizards, spiders and other insects scampering about or cowering in a dark cranny waiting for you to go away.%^RESET%^",
	"insects" : "%^BOLD%^%^WHITE%^Besides the plethora of spiders, there are several other types of insects.  Everything from beetles to flies to moths and even an occasional butterfly.  They flit about avoiding the lizards and spiders looking for a place to rest.%^RESET%^",
	]));

    set_exits(([ 
		"jungle" : "/d/av_rooms/lurue/tecqumin_01",
	]));

}