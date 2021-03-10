#include <std.h>
inherit ROOM;
int GLYPH;
int RUNE;
int TABLET;
int SPHERE;
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Within the temple walls");
    set_long(
	"%^BLACK%^%^BLUE%^You stand within the entrance of the %^CYAN%^temple "
 	"%^BLUE%^and now the %^CYAN%^temple doors%^BLUE%^ are clearly within "
	"view. The double doors are formed from black obsidian stone and "
	"are sealed shut. The doors are covered in symbols. "
	"\n%^RED%^A great evil seeps out from underneath the doors. "
	"%^RESET%^" 
    );
    set_listen("default",
 	"You hear a faint chanting that seems to come through the doors of the temple."
    );
    set_smell("default",
	"There is a faint trace of elemental disorder."
    );
    set_items(([
	"temple":"%^BOLD%^%^BLUE%^The temple is formed of black obsidian and there is no entrance from this point in the courtyard.%^RESET%^",
	"pinnacle":"%^MAGENTA%^The roof of the temple is pyramidical in shape and comes to a point at it'#define DIETYS ([ \
	"pan"                : "animal", \
	"aphrodite"          : "charm", \
	"hades"              : "combat", \
	"hermes"             : "creation", \
	"artemis"            : "divination", \
	"zeus"               : "elemental", \
	"nike"               : "guardian", \
	"demeter"            : "healing", \
	"ares"               : "necromanic", \
	"dionysus"           : "plant", \
	"hera"               : "protection", \
	"hecate"             : "summoning", \
	"apollo"             : "sun", \
	"posiden"            : "weather", \
	])
