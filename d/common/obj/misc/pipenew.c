//updated by Circe 7/11/04 with new desc, etc.
#include <std.h>
#include <move.h>
inherit OBJECT;

#define WOODS ({ "%^YELLOW%^oak", "%^BOLD%^pine", "%^RESET%^%^ORANGE%^birch", \
                 "%^BOLD%^%^BLACK%^ash", "%^BOLD%^walnut", "%^RESET%^%^ORANGE%^cypress", \
                 "%^RESET%^%^ORANGE%^chestnut", "%^RESET%^%^RED%^cherry", \
                 "%^YELLOW%^hickory", "%^YELLOW%^maple", \
                 "%^RESET%^%^RED%^teak", "%^RESET%^%^ORANGE%^poplar", "%^RESET%^%^RED%^rose wood", \
                 "%^RESET%^%^ORANGE%^elm", "%^RESET%^%^ORANGE%^cedar", "%^RESET%^%^RED%^redwood" })

object ob;
string tobacco_type, * mymsgs, * yourmsgs, packedshort, litshort;
int lit, packed, light_time, sp_adjust, con_req, hasmsgs, tobacco, intox, mycharges, tracker;

void create()
{
    int i;
    string str, WOOD;
    ::create();
    i = random(sizeof(WOODS));
    WOOD = WOODS[i];
    if (WOOD == "%^YELLOW%^oak" || WOOD == "%^BOLD%^%^BLACK%^ash" || WOOD == "%^RESET%^%^ORANGE%^elm") {
        str = "an";
    }else {
        str = "a";
    }
    set_name("wooden pipe");
    set_id(({ "pipe", "" + WOOD + " pipe", "wooden pipe", "a wooden pipe" }));
    set_short("a wooden pipe%^RESET%^");
    set_long("This hand-carved creation is made of seasoned " + WOOD + " %^RESET%^fashioned into a slender pipe and fitted with a %^BOLD%^%^BLACK%^black mouthpiece%^RESET%^.  The bowl of the pipe is deep and decorated with %^ORANGE%^burned scrollwork %^RESET%^that give it an elegant appearance.\n\n%^RESET%^%^ORANGE%^Try packing/filling it with some tobacco, then smoking it. Douse it to put it out. Empty it to get rid of the tobacco in it.%^RESET%^");
    set_weight(1);
    set_value(150);
    packed = 0;
    tobacco = 0;
    lit = 0;
    con_req = 0;
    sp_adjust = 0;
    hasmsgs = 0;
    tracker = 0;
    mymsgs = ({});
    yourmsgs = ({});
    intox = 0;
    mycharges = 0;
    set_property("repairtype", ({ "woodwork" }));
}

void init()
{
    ::init();
    add_action("extinguish", "douse");
    add_action("smoke", "smoke");
    add_action("pack_pipe", "pack");
    add_action("pack_pipe", "fill");
    add_action("empty", "empty");
}

int smoke(string str)
{
    if (!id(str)) {
        notify_fail("Smoke what?\n");
        return 0;
    }
    if (!packed) {
        notify_fail("Why would you want to smoke an empty pipe?\n");
        return 0;
    }
    if (lit) {
        notify_fail("You're already smoking it!\n");
        return 0;
    }
    if (con_req > this_player()->query_stats("constitution")) {
        write("You can't smoke this tobacco, it is too strong for you!");
        write("You unpack the pipe, and drop the contents on the ground.");
        packed = 0;
        TO->remove_property_value("added short", ({ "%^BOLD%^%^BLACK%^ (packed)%^RESET%^" }));
        TO->remove_property("added short");
        return 1;
    }
    write("You begin smoking your pipe.\n");
    say(TP->QCN + " begins smoking a pipe.\n", TP);
    TO->remove_property_value("added short", ({ "%^BOLD%^%^BLACK%^ (packed)%^RESET%^" }));
    TO->remove_property("added short");
    TO->set_property("added short", ({ "%^YELLOW%^ (lit)%^RESET%^" }));
    call_out("take_drag", 5);
    light_time = time();
    set_property("lit pipe", 1);
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
        notify_fail("Your pipe is not lit!\n");
        return 0;
    }
    write("You douse your pipe.\n");
    say(TP->QCN + " douses a pipe.\n", TP);
    tobacco -= (light_time - time());
    remove_call_out("take_drag");
    TO->remove_property("lit pipe");
    lit = 0;
    TO->remove_property_value("added short", ({ "%^YELLOW%^ (lit)%^RESET%^" }));
    TO->set_property("added short", ({ "%^BOLD%^%^BLACK%^ (packed)%^RESET%^" }));
    return 1;
}

int empty(string str)
{
    if (!id(str)) {
        notify_fail("empty what?\n");
        return 0;
    }
    if (lit == 1) {
        notify_fail("You must douse your pipe before emptying it!\n");
        return 0;
    }
    write("You empty your pipe.\n");
    say(TP->QCN + " empties a pipe.\n", TP);
    tobacco = 0;
    lit = 0;
    packed = 0;
    intox = 0;
    hasmsgs = 0;
    TO->remove_property_value("added short", ({ "%^BOLD%^%^BLACK%^ (packed)%^RESET%^" }));
    TO->remove_property("added short");
    return 1;
}

void take_drag()
{
    int i;
    if (!living(ETO)) {
        call_out("go_out", 0);
    }
    if (tracker > 30 + random(16)) {
        call_out("go_out", 0);
    }
    if (living(ETO)) {
        tell_object(ETO, "%^RED%^You take a long, gentle puff from your pipe.");
        tell_room(EETO, "%^RED%^" + ETO->QCN + " takes a long, gentle puff from a pipe.", ETO);
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
    tell_room(EETO, "" + ETO->QCN + "'s pipe goes out.\n", TP);
    tell_object(ETO, "Your pipe goes out.\n");
    TO->remove_property("lit pipe");
    remove_call_out("take_drag");
    tobacco = 0;
    lit = 0;
    packed = 0;
    intox = 0;
    hasmsgs = 0;
    tracker = 0;
    TO->remove_property_value("added short", ({ "%^YELLOW%^ (lit)%^RESET%^" }));
    TO->remove_property("added short");
}

int pack_pipe(string str)
{
    string pipe;

    if (packed) {
        notify_fail("Your pipe is already packed!\n");
        return 0;
    }
    if (!str) {
        return 0;
    }
    if ((sscanf(str, "%s with %s", pipe, tobacco_type)) != 2) {
        return 0;
    }
    if (pipe != "pipe") {
        return 0;
    }
    if (tobacco_type == "tobacco") {
        notify_fail("That is not a valid type of tobacco!\n");
        return 0;
    }
    if (!(ob = present(tobacco_type, TP))) {
        notify_fail("You can't pack your pipe with " + tobacco_type + "!!!\n");
        return 0;
    }
    if (ob->is_tobacco()) {
        //con_req = (int)ob->query_con_check();
        tell_object(TP, "You pack your pipe with " + tobacco_type + " tobacco.");
        tell_room(ETP, "" + TP->QCN + " packs " + TP->QP + " pipe with some " + tobacco_type + " tobacco.", TP);
        packed = 1;
        sp_adjust = ob->use_load();
        intox = (int)ob->query_intox();
        if (ob->query_has_messages()) {
            hasmsgs = 1;
            mymsgs = ({});
            mymsgs = (string)ob->query_my_messages();
            yourmsgs = ({});
            yourmsgs = (string)ob->query_your_messages();
        }else {
            hasmsgs = 0;
        }
        TO->remove_property_value("added short", ({ " %^BOLD%^%^BLACK%^(packed)%^RESET%^" }));
        TO->set_property("added short", ({ " %^BOLD%^%^BLACK%^(packed)%^RESET%^" }));
        return 1;
    }
    tell_object(TP, "You can't pack your pipe with that!");
    return 1;
}

remove()
{
    if (lit) {
        call_out("go out", 2);
    }
    if (packed) {
        call_out("empty", 2);
    }
    return ::remove();
}

int get_tracker()
{
    return tracker;
}

int is_carving()
{
    return 1;
}
