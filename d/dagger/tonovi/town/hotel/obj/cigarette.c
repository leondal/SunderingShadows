// cigar by Odin 5/2/2020
// altered by Chernobog (1/27/21)

#include <std.h>
#include <move.h>
inherit OBJECT;

object ob;
string* mymsgs, * yourmsgs;
int lit, hasmsgs, intox, tracker;

void create()
{
    ::create();
    set_name("cigarette");
    set_id(({ "cigarette" }));
    set_short("%^RESET%^%^ORANGE%^A slender %^BOLD%^%^WHITE%^ci%^RESET%^g%^BOLD%^ar"+
        "%^RESET%^e%^BOLD%^tt%^RESET%^e");
    set_long("%^RESET%^%^ORANGE%^This is a crude, hand rolled %^BOLD%^%^WHITE%^ci"+
        "%^RESET%^g%^BOLD%^ar%^RESET%^e%^BOLD%^tt%^RESET%^e. %^ORANGE%^Dried, "+
        "aromatic tobacco has been tucked within a roll of thin parchment paper.\n\n"+
        "%^BOLD%^%^BLACK%^Try smoking it. Douse it to put it out.%^RESET%^");
    set_weight(0);
    set_value(50);
    lit = 0;
    hasmsgs = 1;
    tracker = 0;
    mymsgs = ({ "%^RESET%^%^ORANGE%^You enjoy the pungent taste of the tobacco.%^RESET%^" });
    yourmsgs = ({ "%^RESET%^%^ORANGE%^You smell the pungent aroma of the burning tobacco from the cigarette.%^RESET%^" });
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
    write("%^BOLD%^%^BLACK%^You begin smoking your cigarette.%^RESET%^\n");
    say("%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^begins smoking a cigarette.\n%^RESET%^", TP);
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
        notify_fail("Your cigarette is not lit!\n");
        return 0;
    }
    write("You douse your cigarette.\n");
    say(TP->QCN + " douses a cigarette.\n", TP);
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
        tell_object(ETO, "%^RED%^You take a long, gentle drag from your cigarette.");
        tell_room(EETO, "%^RED%^" + ETO->QCN + " takes a long, gentle drag from a cigarette.", ETO);
    }
    if (intox) {
        ETO->add_intox(intox);
        write("You start to feel strange, your mind wanders...");
    }
    if (!hasmsgs) {
        tell_room(EETO, "%^RED%^" + ETO->QCN + " sighs and stares off into the distance.%^RESET%^", ETO);
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
    tell_room(EETO, "" + ETO->QCN + "'s cigarette goes out, the tobacco finished; " + ETO->QS + " disposes of the remaining butt.\n", TP);
    tell_object(ETO, "Your cigarette goes out, the tobacco finished. You dispose of the remaining butt.\n");
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

int is_cigarette(){
    return 1;
}

