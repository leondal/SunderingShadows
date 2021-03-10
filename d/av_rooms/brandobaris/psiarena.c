// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("psiarena");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("barren");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^within an a%^WHITE%^z%^RESET%^%^CYAN%^u%^BOLD%^re d%^RESET%^%^CYAN%^e%^BOLD%^m%^RESET%^%^CYAN%^i%^BOLD%^p%^RESET%^%^CYAN%^l%^BOLD%^a%^RESET%^%^CYAN%^n%^BOLD%^e%^RESET%^");

    set_long("%^BOLD%^Time %^CYAN%^and %^BLACK%^space %^CYAN%^seem to lose all meaning in this strange dimension, pervaded by a palpable air of %^RESET%^%^CYAN%^s%^WHITE%^e%^CYAN%^r%^GREEN%^e%^WHITE%^n%^CYAN%^e sti"
	"llness%^BOLD%^. Skies of v%^RESET%^%^CYAN%^i%^BOLD%^v%^RESET%^%^CYAN%^i%^BOLD%^d %^RESET%^%^CYAN%^a%^BOLD%^z%^WHITE%^u%^CYAN%^r%^RESET%^%^CYAN%^e %^BOLD%^stretch out to infinity in all directions, and"
	" thin, turning %^WHITE%^slivers %^CYAN%^of %^WHITE%^c%^RESET%^r%^BOLD%^y%^RESET%^s%^BOLD%^t%^RESET%^a%^BOLD%^l %^CYAN%^are suspended weightlessly throughout, their surfaces %^WHITE%^g%^MAGENTA%^l%^WHI"
	"TE%^i%^CYAN%^n%^WHITE%^t%^GREEN%^i%^WHITE%^ng %^CYAN%^like the %^WHITE%^s%^MAGENTA%^t%^WHITE%^a%^MAGENTA%^r%^WHITE%^s %^CYAN%^in some %^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^t%^RESET%^%^CYAN%^h%^ORANGE%^e%^"
	"CYAN%^r%^MAGENTA%^w%^CYAN%^or%^BOLD%^%^RED%^l%^RESET%^%^CYAN%^d%^BOLD%^%^MAGENTA%^l%^RESET%^%^CYAN%^y n%^BOLD%^%^MAGENTA%^i%^RESET%^%^CYAN%^g%^BOLD%^%^WHITE%^h%^RESET%^%^CYAN%^t s%^GREEN%^k%^CYAN%^y%^"
	"BOLD%^. A vast disk, some fifty yards in diameter, is the only solid object here upon which to stand, utterly %^RESET%^%^CYAN%^t%^WHITE%^r%^BOLD%^an%^CYAN%^spa%^WHITE%^re%^RESET%^n%^CYAN%^t %^BOLD%^bu"
	"t for the reflections of those upon it. Below the smooth surface of the disk lies a %^GREEN%^d%^ORANGE%^i%^GREEN%^z%^WHITE%^z%^GREEN%^y%^ORANGE%^i%^WHITE%^n%^GREEN%^g %^CYAN%^drop into an endless sea "
	"of crystals - possibly a fall without end. Keeping a clear mind in this place will be difficult.%^RESET%^"
	);

    set_smell("default","
You cannot smell anything.");
    set_listen("default","It is difficult to pierce the silence of this place.");

}