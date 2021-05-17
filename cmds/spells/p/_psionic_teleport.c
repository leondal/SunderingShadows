#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>

inherit "/cmds/spells/t/_teleport";

void create() {
    ::create();
    set_spell_name("psionic teleport");
    set_spell_level(([ "psion" : 5 ]));
    set_discipline("nomad");
    set_domains(({}));
    set_spell_sphere("psychoportation");
    set_syntax("cast CLASS psionic teleport to <location>");
    set_description("This power will move the nomad from his current location to one he has previously memorized.  The "
"nomad merely concentrates, setting his sights on the place he would like to be, and his mind manipulates time and space "
"to place him there.  An example of the power's usage is <remember here as cave>.  Then later on, the nomad would type, "
"<cast psion psionic teleport to cave>.  Again, you may also <unremember cave> to forget that particular location. Note: "
"The teleport power is not guaranteed, and the nomad may end up in a place he did not intend.\n\nSee also: remember, "
"unremember, recall");
    set_verbal_comp();
    set_arg_needed();
    set_casting_time(2);
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^GREEN%^%^BOLD%^"+caster->QCN+" focuses intently.";
}
