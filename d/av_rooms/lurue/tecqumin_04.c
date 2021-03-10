// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tecqumin_04");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("jungle");
    set_travel("fresh blaze");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A clearing in the jungle%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The jungle forms a dense %^BOLD%^%^BLACK%^tangle%^RESET%^%^GREEN%^, barring passage in most directions.  %^BOLD%^Vibrant %^RESET%^%^GREEN%^gr%^BOLD%^ee%^RESET%^%^GREEN%^n %^BOLD%^pl%"
	"^RESET%^%^GREEN%^a%^BOLD%^nts %^RESET%^%^GREEN%^with thick, waxy leaves gather round the bases of %^BOLD%^%^BLACK%^ancient %^RESET%^%^GREEN%^growth trees with thick boles and twisted branches.  The ne"
	"arly impenetrable barrier thins here, revealing the remains of a highly carved, ornate altar with a large stone figure sitting upon it.  The figure, carved from a rectangular block of %^BOLD%^%^BLACK%"
	"^granite%^RESET%^%^GREEN%^, appears to be that of a highly stylized %^CYAN%^fish %^GREEN%^or %^BOLD%^sea serpent%^RESET%^%^GREEN%^.  It's a bit difficult to tell as the body coils about itself and has"
	" many %^CYAN%^ichthyic features%^GREEN%^, the most prominent of which is the elongated nose with an gapping, oval mouth and small round eyes.  Despite this, %^BOLD%^%^GREEN%^serpentine ridges %^RESET%"
	"^%^GREEN%^along the back and a distinct lack of fins make it unclear just what this creature is.  Below this statue, a large square stone altar has been placed and carved with rows and rows of men, wo"
	"men and animals, all depicted with their faces turned upward, as though they are gazing upon the creature that sits above.%^RESET%^"
	);

    set_smell("default","
%^RESET%^%^ORANGE%^The air is heavy with %^CYAN%^humidity%^ORANGE%^ and the heady scent of %^GREEN%^j%^BOLD%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant life.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^There is the constant hum of insect activity, the bustle and shrill calls of %^MAGENTA%^e%^RED%^x%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^t%^WHITE%^i%^MAGENTA%^c %^GREEN%^birds.%^RESET%^");

    set_search("altar","%^BOLD%^%^BLACK%^You search about the altar but find little of interest.%^RESET%^");
    
set_items(([ 
	({ "altar", "men", "woman", "animals" }) : "%^BOLD%^%^BLACK%^The rectangular altar is clearly a solid block of soapstone that has been neatly carved with several horizontal rows of figures.  The top two rows appear to be mostly people with their heads turned upward.  In the bottom row, which is taller then the other two, animals can also be seen surrounded by ornately dressed men who hold weapons as though hunting or preparing the sacrifice the creature.%^RESET%^",
	({ "figure", "statue", "fish", "serpent", "sea serpent" }) : "%^CYAN%^It's difficult to tell what this creature is for it has been carved looped in on itself with a blocky form that further obscures its form.  Scales cover the entirety of the statue's form, except for the smooth fish like face with its round eyes and oval, big lipped mouth.  Scalloped ridges wind along the back ridge of the creature, though its tail fans out into two feather like curves.%^RESET%^",
	({ "leaves", "waxy leaves", "plants", "plant" }) : "%^RESET%^The jungle is full of all sorts of plant life. You notice a vigorous growth of Dreth's fingers, with massive, %^GREEN%^sh%^WHITE%^i%^GREEN%^ny%^RESET%^, %^BOLD%^%^GREEN%^lush green%^RESET%^, rounded leaves.",
	]));

    set_exits(([ 
		"jungle" : "/d/av_rooms/lurue/tecqumin_01",
	]));

}