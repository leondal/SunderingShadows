#include <std.h>
inherit "/d/magic/obj/light";

int duration;

void create() {
    ::create();
    set_id( ({ "lights","dancing lights","cloud","cloud of lights","cloud of dancing lights"}) );
    set_name("dancing lights");
    set_short("%^BOLD%^%^WHITE%^a small cl%^RESET%^ou%^BOLD%^%^WHITE%^d of da%^YELLOW%^n%^WHITE%^ci%^CYAN%^n%^WHITE%^g lig%^MAGENTA%^h%^WHITE%^ts%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Floating in the air here is a small cloud of swirling, dancing lights, each gleaming with a different color. They put off no heat, only a gentle glow that sheds light around the immediate area.  You can <darken> it when you no longer need it.");
}