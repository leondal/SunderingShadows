// using Circe's new version from slip the bonds, allows caster to choose when to use
#include <std.h>
inherit OBJECT;

void set_mycaster(object obj);
void set_mylevel(int x);
void end_it();

object mycaster, myspellob;
int mylevel, FLAG;
int charges = 1;

void create()
{
    ::create();
    set_name("freedom");
    set_id(({ "freedom_remotexoli" }));
    set_short("");
    set_long("");
    set_property("no animate", 1);
    set_weight(0);
    //set_heart_beat(1);
    //FLAG = 0;
}

void init()
{
    ::init();
    add_action("freeme", "freeme");
}

int freeme()
{
    if (!objectp(ETO)) {
        return;
    }
    if (!(string)ETO->query_paralyzed() && !(string)ETO->query_tripped()) {
        tell_object(TP, "%^BOLD%^%^CYAN%^You are not tripped or paralyzed!%^RESET%^");
        return;
    }
    tell_object(TP, "%^BOLD%^You release the focus hidden within your mind, "
                "refusing to bow to the force that tries to contain you!%^RESET%^");
    tell_room(EETO, "%^BOLD%^With a resolute expression, " + ETOQCN + " casts off "
              "the forces that try to contain " + ETO->QO + "!%^RESET%^", ETO);
    ETO->remove_paralyzed();
    ETO->set_tripped(0);

    charges--;
    if (charges < 0) {
        call_out("end_it", 1);
    }
    return 1;
}

void set_mycaster(object obj)
{
    mycaster = obj;
}

void set_mylevel(int x)
{
    mylevel = x * 5;
}

void set_spellob(object spellob)
{
    myspellob = spellob;
}

int drop()
{
    return 1;
}

int is_detectable()
{
    return 0;
}

int query_invis()
{
    return 1;
}

int save_me(string file)
{
    return 0;
}

void end_it()
{
    if (objectp(mycaster)) {
        if (objectp(myspellob)) {
            myspellob->dest_effect();
        }
        mycaster->set_property("freedom time", time());
        mycaster->remove_property("freedom");
    }
    if (objectp(TO)) {
        TO->remove();
    }
    return;
}
