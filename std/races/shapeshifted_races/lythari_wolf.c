#include <std.h>
#include <daemons.h>
inherit "/std/races/shapeshifted_races/druid_wolf.c";

int change_into_message(object obj) {
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^CYAN%^You turn your mind inwards, reaching for the core of your spirit.%^RESET%^");
    tell_object(obj,"%^CYAN%^You breathe in, and as you exhale the world seems to shift and change.%^RESET%^");
    tell_object(obj,"%^GREEN%^Your senses are heightened as the ancient blessing takes hold.  You can smell countless scents, you can taste the very air.  You are wolf!%^RESET%^");

    tell_room(environment(obj),"%^CYAN%^"+obj->QCN+"'s eyes dull as "+obj->QP+" attention seems to drift.%^RESET%^",obj);
    tell_room(environment(obj),"%^GREEN%^You blink, and where "+obj->QCN+" once stood is now a massive silvery wolf!%^RESET%^",obj);
    return 1;
}

int change_outof_message(object obj) {
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^CYAN%^You turn your mind inwards, seeking the spark of inspiration.%^RESET%^");
    tell_object(obj,"%^GREEN%^You inhale a breath and stretch as your body changes, and you find your senses dulled as the air caresses your new fur-less face and fingertips.%^RESET%^");

    tell_room(environment(obj),"%^CYAN%^"+obj->QCN+"'s eyes gleam as "+obj->QS+" takes on a look of concentration.%^RESET%^",obj);
    tell_room(environment(obj),"%^GREEN%^You could swear you had not looked away, yet where "+obj->QCN+" once stood, now stands a slender elven woman!%^RESET%^",obj);
    return 1;
}

int default_descriptions(object obj){
    if(!objectp(obj)) { return 0; }

    obj->set_description("describe %^RESET%^%^GREEN%^is immediately apparent as an %^MAGENTA%^unnatural "
"%^GREEN%^creature.  Despite her lupine form, she is of immense size, almost as big as a small pony.  "
"Her fur is a beautiful %^RESET%^sil%^BOLD%^v%^RESET%^ery whi%^BOLD%^t%^RESET%^e %^GREEN%^colour, that "
"ripples with the movement of her sinewy limbs.  Powerfully built and easily recognisable as a %^RED%^"
"dangerous %^GREEN%^predator, she still doesn't bear the threatening nature of such a beast, her "
"presence being oddly calming.  Another oddity is her %^BOLD%^%^BLUE%^pier%^CYAN%^c%^BLUE%^ing blue eyes"
"%^RESET%^%^GREEN%^, unusual for such a creature.%^RESET%^");
    obj->setDescriptivePhrase("%^RESET%^mass%^BOLD%^i%^RESET%^ve si%^BOLD%^l%^RESET%^very $R%^RESET%^");

    obj->set("speech string","rumble");
    obj->set("describe string","low");
    obj->force_me("message in slinks in.");
    obj->force_me("message out lopes $D.");
    return 1;
}
