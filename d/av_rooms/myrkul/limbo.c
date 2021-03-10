// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("limbo");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("desert");
    set_travel("rubble");
    set_climate("desert");

    set_short("%^BOLD%^%^CYAN%^L%^WHITE%^i%^CYAN%^m%^RED%^b%^CYAN%^o P%^WHITE%^l%^CYAN%^a%^RED%^n%^CYAN%^e%^RESET%^");

    set_long("%^BOLD%^%^RED%^C%^MAGENTA%^h%^BLUE%^a%^YELLOW%^o%^WHITE%^t%^GREEN%^i%^RESET%^%^ORANGE%^c%^YELLOW%^ light%^CYAN%^ dances like a %^BLUE%^k%^GREEN%^a%^BLUE%^l%^RED%^e%^MAGENTA%^i%^RED%^d%^MAGENTA%^o%^YEL"
	"LOW%^s%^WHITE%^c%^YELLOW%^o%^WHITE%^p%^YELLOW%^e%^CYAN%^ through this %^BLACK%^realm%^CYAN%^ which defies your minds attempt to order the %^RED%^j%^MAGENTA%^u%^RED%^m%^MAGENTA%^b%^RED%^l%^MAGENTA%^e%^"
	"CYAN%^ of images. Everything seems in motion. One moment you are on a %^RESET%^%^ORANGE%^mountain%^BOLD%^%^CYAN%^. Next you are on a %^RED%^desert%^CYAN%^, and then find yourself swimming in a lake. T"
	"emperature fluxuates wildly from %^WHITE%^hot%^CYAN%^ to %^BLUE%^cold%^CYAN%^. Finally you find yourself in extended states of %^BOLD%^%^MAGENTA%^island-like stability%^CYAN%^ in front of an enormous "
	"%^WHITE%^pillar%^CYAN%^. Tendrils of pure %^YELLOW%^energy%^CYAN%^ and %^BLUE%^c%^CYAN%^h%^WHITE%^a%^YELLOW%^o%^RESET%^%^ORANGE%^s%^BOLD%^%^CYAN%^ float away from the mighty stone. Changes here seem t"
	"o evolve more slowly here, though nothing here truly stops changing.%^RESET%^"
	);

    set_smell("default","
Smells are change inexplicably from the grotesque to heavenly and back again.");
    set_listen("default","You hear a lot of white noise, almost like static vibrations.");

    set_search("stone","This may actually be the legendary Spawning Stone of the Slaad. Only the truly insane would be here as anything living or dead could be infested with a fertilized Slaad egg!");
    set_search("pillar","This may actually be the legendary Spawning Stone of the Slaad. Only the truly insane would be here as anything living or dead could be infested with a fertilized Slaad egg!");
    
set_items(([ 
	({ "island", "stability" }) : "It is calmer around the stone, for whatever reason.",
	({ "images", "mountain", "desert", "lake", "temperature", "hot", "cold" }) : "The images flash around and the land changes constantly. It is worse farther away from the pillar, and in odd places it seems almost impossible that anything could survive as the land itself could grind anything walking there to dust in its violent upheavals. The hot and cold changes are unrelenting, and this place is very trying to the mind and body.",
	({ "pillar", "stone" }) : "There seem to be dead bodies floating around in a wide orbit around this pillar. The corpses look to be of odd humanoid creatures that look somewhat like toad or frog. The chaotic energy spewing from the pillar seems to be a force of nature.",
	({ "chaos", "light" }) : "%^BOLD%^%^YELLOW%^The light changes randomly and if you concentrate too long on it, you just might go %^RESET%^%^MAGENTA%^insane.%^RESET%^",
	]));

    set_exits(([ 
		"rift" : "/d/shadowgate/adv_main",
	]));

}