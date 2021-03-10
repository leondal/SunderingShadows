#include <std.h>
inherit "/d/dagger/marsh/swamp/Mrooms.c";
#define MPATH "/d/dagger/marsh/swamp/mon/"+
#define RPATH "/d/dagger/marsh/swamp/rooms/"+
int xy;

// long desc

void create() {
    ::create();
   set_terrain(MARSH);
   set_travel(FRESH_BLAZE);
    set_property("light", -1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Marsh of Fear%^RESET%^");
    set_long( "%^RESET%^%^BLUE%^"
      "The marsh now is very dark as the %^GREEN%^rotten vegetation%^BLUE%^ "
      "and %^ORANGE%^trees%^BLUE%^ grow up "
      "to form a canopy above you. Blackness fills the area making movement treacherous and slow. "
      "The %^MAGENTA%^bog%^BLUE%^ squishes below your feet and you "
      "are extremely careful not to fall prey to the patches of "
      "%^RED%^quicksand%^BLUE%^ that are surely to be found here. "
      "All around you %^YELLOW%^insects%^RESET%^%^BLUE%^ buzz madly. The vegetation seems "
      "to own this marsh, growing possessed and with an insane frenzy. It is "
      "almost as though the land here seeps evil and is sentient and aware of those "
      "which walk upon its surface.\n%^RED%^Ahead of you to the east lies a massive tower-shaped billowing black column "
      "of mist. There appears to be no way into the swirling mass, but perhaps closer up you may find entrance into "
      "this mystical and evil place that must be the tower known only as Demongate."     
      "%^RESET%^"
    );
    set_listen("default",
      "Your mind screams in panic and you fight the urge to flee!"
    );
    set_smell("default",
      "Blood, evil, death, decay, insanity - it's all here and waits for you to join."
    );
    set_items(([
	"bog":"%^GREEN%^The bog is murky and disgusting%^RESET%^",
	"quicksand":"There is bound to be patches of its somewhere.%^RESET%^",
	"paths":"The paths are small and twist through the bog.",
	"insects":"Insects buzz around your head in a frenzy.",
	"trees":"The trees are all half-dead and rotten and provide many odd "
	"shaped shadows to add to the darkened mood.",
	"vegetation":"There is certainly an abundance of that here.",
	"moss":"The moss grows everywhere and on everything. It is as though "
	"vegetation is the master of this area.",
	"tower":"%^RED%^Ahead of you to the north lies a massive tower-shaped billowing black column "
	"of mist. There appears to be no way into the swirling mass, but perhaps closer up you may find entrance into "
	"this mystical and evil place that must be the tower known only as Demongate.%^RESET%^",
      ]));
    set_exits(([
	"east": RPATH "f29",
	"southwest": RPATH "f27",
      ]));
}
