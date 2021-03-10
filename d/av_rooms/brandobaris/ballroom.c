// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ballroom");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^BOLD%^A l%^MAGENTA%^a%^WHITE%^vi%^MAGENTA%^s%^WHITE%^hly d%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^c%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^t%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^d grand ballroom%^RESET%^ ");

    set_long("%^BOLD%^You are standing in a grand ballroom. This room has had no %^ORANGE%^expense %^WHITE%^spared for such an extravagant affair. Scattered around the room are %^RESET%^v%^CYAN%^a%^BOLD%^%^WHITE%^s"
	"%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^s of %^GREEN%^flowers %^WHITE%^and %^RESET%^%^MAGENTA%^artwork%^BOLD%^%^WHITE%^. The floor is a %^RESET%^%^RED%^dark-cherry %^BOLD%^%^WHITE%^hardwood cleaned to a %^"
	"CYAN%^gleam%^WHITE%^. Silk %^MAGENTA%^streamers %^WHITE%^have been hung from the sleek curtains, which are pulled back allowing the %^MAGENTA%^s%^RESET%^%^MAGENTA%^t%^BOLD%^a%^RESET%^%^MAGENTA%^ined %"
	"^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^ss %^BOLD%^%^WHITE%^windows to show. The small amount of light that the windows allow in reflects off of the six c%^CYAN%^h%^WHITE"
	"%^a%^CYAN%^n%^WHITE%^d%^CYAN%^e%^WHITE%^l%^CYAN%^i%^WHITE%^e%^CYAN%^r%^WHITE%^s hanging from the ceiling. Along the southern most wall is a %^GREEN%^stage%^WHITE%^, which has a band setup atop it. The"
	"re are small, round %^ORANGE%^tables %^WHITE%^arranged off to the side of the stage area, near a large %^RESET%^%^GREEN%^banquet table %^BOLD%^%^WHITE%^brimming with %^RESET%^%^ORANGE%^food%^BOLD%^%^W"
	"HITE%^. Most of the room appears to be arranged in such a way as to allow dancing. Stationed on the outs%^RESET%^i%^BOLD%^de %^BLACK%^e%^RED%^d%^BLACK%^ge %^WHITE%^of the ballroom are %^RESET%^%^BLUE%"
	"^guards %^BOLD%^%^WHITE%^to ensure the event is %^CYAN%^secure%^WHITE%^.%^RESET%^"
	);

    set_smell("default","
Wafting aromas from the food fills the air with a slight undercurrent of incense and rose.");
    set_listen("default","You can hear dance music playing in the background with muffled voices rising during the changing of a song.");

    
set_items(([ 
	({ "guard", "knights", "priest", "guards" }) : "%^BOLD%^%^BLUE%^Upon closer inspection you can see the insignia of Helm on these guards The insignia varies from guard to guard, signifying them as either %^CYAN%^knight %^BLUE%^or %^RED%^priest%^BLUE%^.%^RESET%^",
	({ "wall", "walls" }) : "%^BOLD%^The walls are a %^RESET%^%^MAGENTA%^p%^BOLD%^%^WHITE%^al%^RESET%^%^MAGENTA%^e %^BOLD%^v%^RESET%^%^MAGENTA%^io%^BOLD%^%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t %^BOLD%^%^WHITE%^trimmed in %^ORANGE%^gold%^RESET%^. ",
	({ "banquet table", "banquet", "table", "food" }) : "%^BOLD%^A large banquet table running the length of the western wall is brimming in delicious %^RESET%^%^ORANGE%^food %^BOLD%^%^WHITE%^and %^RESET%^%^MAGENTA%^drink %^BOLD%^%^WHITE%^from around the northern region of %^BLACK%^Shadowgate%^WHITE%^. There is even a small section of %^RESET%^%^ORANGE%^food %^BOLD%^%^WHITE%^from the %^RESET%^%^CYAN%^Tsarven Empire %^WHITE%^t%^BOLD%^o accommodate anyone with that pallette as well%^RESET%^. ",
	({ "namecard", "namecards" }) : "%^CYAN%^There are a lot of cards placed throughout the room. A few specific ones catch your attention as they are in the most prestigious position of the entire ball. The first name is %^BOLD%^%^WHITE%^Karim Lar'Shil %^RESET%^%^CYAN%^accompanied by %^BOLD%^%^WHITE%^Viligant Rachel Kerth%^RESET%^%^CYAN%^, folliwed by %^BOLD%^%^WHITE%^Eoin %^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^Jysibyll White%^RESET%^%^CYAN%^, %^BOLD%^%^WHITE%^Advisor Xavier Le'Vey%^RESET%^%^CYAN%^, and lastly %^BOLD%^%^WHITE%^Saorin Ellistre%^RESET%^%^CYAN%^.%^WHITE%^ ",
	({ "tables", "small tables" }) : "%^BOLD%^These small, round tables are covered with various %^ORANGE%^c%^RED%^o%^ORANGE%^l%^RED%^o%^ORANGE%^rf%^RED%^u%^ORANGE%^l %^WHITE%^tablecloths. The tables are large enough to accompany six individuals comfortable with every table having a %^CYAN%^namecard %^WHITE%^to designate the seating arrangement.%^RESET%^ ",
	({ "stage", "band" }) : "%^BOLD%^Atop the stage is a band of bards playing almost any instrument imaginable from a flute to a %^GREEN%^pipe organ %^WHITE%^and %^BLACK%^piano%^WHITE%^.%^RESET%^",
	({ "chandeliers", "chandelier", "ceiling" }) : "%^BOLD%^%^BLUE%^Five smaller chandeliers are connected by small silver wires to the huge chandelier in the center. This connection has been crafted in such a way as to form a silver pegaus in rampant flight against the %^RESET%^%^MAGENTA%^d%^BOLD%^ee%^RESET%^%^MAGENTA%^p, %^BOLD%^p%^RESET%^%^MAGENTA%^u%^BOLD%^r%^RESET%^%^MAGENTA%^p%^BOLD%^l%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLUE%^ceiling.%^RESET%^",
	({ "windows", "window" }) : "%^BOLD%^The %^MAGENTA%^s%^RESET%^%^MAGENTA%^t%^BOLD%^a%^RESET%^%^MAGENTA%^ined %^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^ss %^BOLD%^%^WHITE%^windows are an op%^MAGENTA%^a%^WHITE%^le%^CYAN%^s%^WHITE%^ce%^CYAN%^n%^WHITE%^t hue, blocking a majority of %^ORANGE%^light %^WHITE%^allowing the hosts to set the preferred ambiance of choice no matter the time of day%^RESET%^.",
	({ "curtains", "curtain" }) : "%^CYAN%^The sleek, silk curtains are a pale blue with the holy symbols of %^BOLD%^%^WHITE%^The Triad %^RESET%^%^CYAN%^being prominently displayed in a silver embroidery.%^WHITE%^ ",
	({ "streamers", "streamer" }) : "%^BOLD%^Strands of flowing %^MAGENTA%^silk %^WHITE%^have been placed carefully about the room. They somehow manage to help direct the %^ORANGE%^light %^WHITE%^in the area to create a %^BLACK%^nighttime %^WHITE%^ambiance no matter the time of day%^RESET%^. ",
	"floor" : "%^BOLD%^A deep %^RESET%^%^RED%^dark cherry %^BOLD%^%^WHITE%^wood has been used for the floor. It has been cleaned to a sparkling %^ORANGE%^shine%^WHITE%^.%^RESET%^",
	({ "artwork", "art" }) : "%^MAGENTA%^The artwork shows different members of Antioch's nobility in paintings and sculptures%^WHITE%^. ",
	({ "vases", "vase" }) : "%^BOLD%^Arrangements of varying flowers ranging from %^RED%^roses %^WHITE%^to %^MAGENTA%^tulips %^WHITE%^are resting on small tables in highly decorated %^GREEN%^ceramic %^WHITE%^vases.%^RESET%^",
	]));

    set_exits(([ 
		"garden" : "/d/antioch/antioch2/rooms/yard4",
	]));

}