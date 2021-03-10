#include <std.h>
#include <daemons.h>
#include "../ud_ruins.h"
inherit OBJECT;

int uses;

void create() {
    ::create();
    set_name("powder of nightmares");
    set_id(({"powder","nightmare powder","powder of nightmares","bag","dust"}));
    set_short(
        "%^MAGENTA%^a small bag of "
        "%^BOLD%^c%^ORANGE%^o%^MAGENTA%^l%^GREEN%^o%^MAGENTA%^r%^CYAN%^e"
        "%^MAGENTA%^d p%^RED%^o%^MAGENTA%^w%^ORANGE%^d%^MAGENTA%^er%^RESET%^"
    );
    set_long((:TO, "long_func":));
    set_lore(
        "%^MAGENTA%^Careful study reveals this substance to be %^CYAN%^Powder of "
        "Nightmares%^MAGENTA%^, a rare tool usually found in the employ of "
        "assassins - especially drowish assassins. Created from the spores of a "
        "strange mushroom indigenous to the middle reaches of the underdark, "
        "this powder is similar in composition to a recreational drug popular "
        "amongst the intelligent races where it grows, but has been so densely "
        "concentrated as to cause intense bouts of paranoia and terror in anyone "
        "who ingests it. %^WHITE%^"
    );
    set_property("lore difficulty",20);
    set_weight(2);
    set_value(1500);
    uses = random(2) + 3;
}

void init() {
    ::init();
    add_action("toss_func","toss");
}

void long_func()
{
    string res;

    if (!uses) {
        return "This empty bag seems to have once held some kind of colorful powder.";
    }

    res =
        "%^MAGENTA%^This %^BOLD%^%^CYAN%^prismatic%^RESET%^%^MAGENTA%^, "
        "%^CYAN%^powdered %^MAGENTA%^substance smells faintly of fungi, and is "
        "so finely grained as to almost flow like water around one's fingers. "
        "The powder seems to %^BOLD%^%^WHITE%^b%^RESET%^i%^BOLD%^ll"
        "%^RESET%^o%^BOLD%^w %^RESET%^%^MAGENTA%^into the air with even the "
        "slightest breeze, making it diffifult to avoid breathing it in.";
    if(objectp(TP))
    {
        if(FEATS_D->usable_feat(TP, "tools of the trade"))
        {
             res += "\n\n"
                "Despite the difficulty of handling the powder, you realize that you "
                "could, with the right training, %^BOLD%^toss "
                "%^RESET%^%^MAGENTA%^the powder at someone, though it is not "
                "immediately clear what good it would do.";
        }
    }
    return res;
}


int toss_func(string str) {
    string target;
    object targ,powder;
    if (!objectp(TP)) { return 1;}
    if (!objectp(ETP)) { return 1;}
    if (!str) { return notify_fail("Toss what?\n"); }
    if(TP->query_property("shapeshifted")) {
        tell_object(TP, "You can't use powder while shapeshifted.");
        return 1;
    }
    if (userp(TP) && !FEATS_D->usable_feat(TP, "tools of the trade")) {
        tell_object(TP, "You lack the training to use this effectively.");
        return 1;
    }
    if(!uses) {
        tell_object(TP, "The bag is empty!");
        return 1;
    }
    if (sscanf(str, "powder at %s",target) != 1) {
        return notify_fail("Syntax: toss powder at <target>\n");
    }
    if(TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!(targ=present(target,ETP))) {
        tell_object(TP, "That target is not here!");
        return 1;
    }
    if(targ == TP) {
        tell_object(TP, "That would be a bad idea.");
        return 1;
    }
    if(targ->query_property("powdered")) {
        return notify_fail(
            "That target is already fighting off the effects of another powder!"
            " Yours will have no effect!\n"
        );
    }
    if(!TP->kill_ob(targ,0)) return 1;
    uses--;
    tell_object(TP,
        "%^MAGENTA%^You take a handful of "
        "p%^BOLD%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^CYAN%^s%^RESET%^%^MAGENTA%^ma"
        "%^BOLD%^t%^CYAN%^i%^RESET%^%^MAGENTA%^c "
        "d%^BOLD%^%^CYAN%^u%^MAGENTA%^s%^RESET%^%^MAGENTA%^t from the bag and "
        "cast it in "+targ->QCN+"'s face!"
    );
    tell_object(targ,
        "%^MAGENTA%^"+TP->QCN+" takes a handful of "
        "p%^BOLD%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^CYAN%^s%^RESET%^%^MAGENTA%^ma"
        "%^BOLD%^t%^CYAN%^i%^RESET%^%^MAGENTA%^c "
        "d%^BOLD%^%^CYAN%^u%^MAGENTA%^s%^RESET%^%^MAGENTA%^t from a small bag "
        "and casts it in your face!"
    ,({TP}));
    tell_room(ETP,
        "%^MAGENTA%^"+TP->QCN+" takes a handful of "
        "p%^BOLD%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^CYAN%^s%^RESET%^%^MAGENTA%^ma"
        "%^BOLD%^t%^CYAN%^i%^RESET%^%^MAGENTA%^c "
        "d%^BOLD%^%^CYAN%^u%^MAGENTA%^s%^RESET%^%^MAGENTA%^t from a small bag "
        "and casts it in "+targ->QCN+"'s face!"
    ,({TP,targ}));
    TP->set_paralyzed(4,"%^MAGENTA%^You are busy throwing the dust!");
    powder = new(OBJ"illusionp_obj");
    // Note: There isn't currently an opposing check on this (though the effect is
    // countered by the target's wisdom bonus). set_userlvl() is called here
    // just to make it easier to add a check later if necessary (most likely
    // a will save)
    powder->set_userlvl(TP->query_level());
    powder->move(targ);
    if(uses <= 0) {
        set_short("an empty bag");
        set_value(0);
        uses = 0;
    }
    return 1;
}
