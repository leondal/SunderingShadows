//generic inheritable cigar by Odin 5/2/2020
#include <std.h>
#include <move.h>
inherit OBJECT;

object ob;
string* mymsgs, * yourmsgs;
int lit, hasmsgs, intox, tracker;

void create()
{
    ::create();
    set_name("cigar");
    set_id(({ "cigar" }));
    set_short("%^RESET%^%^ORANGE%^cigar%^RESET%^");
    set_long("This is a hand rolled cigar.\n\n%^RESET%^%^ORANGE%^Try smoking it. Douse it to put it out.%^RESET%^");
    set_weight(0);
    set_value(50);
    lit = 0;
    hasmsgs = 1;
    tracker = 0;
    mymsgs = ({ "%^RESET%^%^ORANGE%^You enjoy the pungent taste of the tobacco.%^RESET%^" });
    yourmsgs = ({ "%^RESET%^%^ORANGE%^You smell the pungent aroma of the burning tobacco from the cigar.%^RESET%^" });
    intox = 0;
}

void init()
{
    ::init();
    add_action("extinguish", "douse");
    add_action("smoke", "smoke");
}

int smoke(string str)
{
    if (!id(str)) {
        notify_fail("Smoke what?\n");
        return 0;
    }
    if (lit) {
        notify_fail("You're already smoking it!\n");
        return 0;
    }
    write("You begin smoking your cigar.\n");
    say(TP->QCN + " begins smoking a cigar.\n", TP);
    TO->set_property("added short", ({ "%^YELLOW%^ (lit)%^RESET%^" }));
    call_out("take_drag", 5);
    TO->set_property("lit cigar", 1);
    lit = 1;
    return 1;
}

int extinguish(string str)
{
    if (!id(str)) {
        notify_fail("Douse what?\n");
        return 0;
    }
    if (!lit) {
        notify_fail("Your cigar is not lit!\n");
        return 0;
    }
    write("You douse your cigar.\n");
    say(TP->QCN + " douses a cigar.\n", TP);
    remove_call_out("take_drag");
    TO->remove_property("lit cigar");
    lit = 0;
    TO->remove_property_value("added short", ({ "%^YELLOW%^ (lit)%^RESET%^" }));
    TO->remove_property("added short");
    return 1;
}

void take_drag()
{
    int i;
    if (!living(ETO)) {
        call_out("go out", 2);
    }
    if (tracker > 30 + random(16)) {
        call_out("go_out", 1);
    }
    if (living(ETO)) {
        tell_object(ETO, "%^RED%^You take a long, gentle drag from your cigar.");
        tell_room(EETO, "%^RED%^" + ETO->QCN + " takes a long, gentle drag from a cigar.", ETO);
    }
    if (intox) {
        ETO->add_intox(intox);
        write("You start to feel strange, your mind wanders...");
    }
    if (!hasmsgs) {
        tell_room(EETO, "%^RED%^" + ETO->QCN + " giggles and stares off into the distance.%^RESET%^", ETO);
    }else {
        i = random(sizeof(mymsgs));
        tell_object(ETO, mymsgs[i]);
        tell_room(EETO, yourmsgs[i], ETO);
    }
    tracker++;
    call_out("take_drag", random(30) + 60);
}

void go_out()
{
    tell_room(EETO, "" + ETO->QCN + "'s cigar goes out, the tobacco finished; " + ETO->QS + " disposes of the remaining butt.\n", TP);
    tell_object(ETO, "Your cigar goes out, the tobacco finished. You dispose of the remaining butt.\n");
    TO->remove_property("lit cigar");
    remove_call_out("take_drag");
    lit = 0;
    intox = 0;
    hasmsgs = 0;
    tracker = 0;
    TO->remove_property_value("added short", ({ "%^YELLOW%^ (lit)%^RESET%^" }));
    TO->remove_property("added short");
    TO->remove();
}

remove()
{
    if (lit) {
        lit = 0;
        remove_call_out("take_drag");
        TO->remove_property("lit cigar");
    }
    return ::remove();
}

int get_tracker()
{
    return tracker;
}

int is_cigar(){
    return 1;
}

