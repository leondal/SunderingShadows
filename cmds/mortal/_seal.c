//_seal.c by Circe 6/19/04
//for use with signet rings
//new sealing devices may be added, but they must have
//int query_is_seal_device(){ return 1;}
//new waxes must have
//int is_sealing_wax(){return 1;}

#include <std.h>

inherit DAEMON;
int help();

int cmd_seal(string str)
{
    object wax, paper, ring;
    string dest, mywax, myring, junk, morejunk;
    int uses;
    if (!str) {
        help();
        return 1;
    }
    if (str == "break") {
        tell_object(TP, "Try <seal break on PAPER>");
        return 1;
    }
    if (sscanf(str, "break on %s", dest) == 1) {
        if (sscanf(str, "break on %s", dest) != 1) {
            help();
            return 1;
        }
        paper = present(dest, TP);
        if (!objectp(paper)) {
            return notify_fail("You don't have " + dest + "!\n");
        }
        if (!paper->query_property("sealed")) {
            return notify_fail("The " + dest + " is not sealed!\n");
        }
        tell_object(TP, "You break the seal on the " + dest + ".");
        paper->remove_property("sealed");
        morejunk = paper->query_long();
        morejunk += "  The seal is now %^BOLD%^%^RED%^broken%^RESET%^.";
        paper->set_long(morejunk);
        junk = paper->query_short();
        junk += " (%^BOLD%^%^RED%^seal broken%^RESET%^)";
        paper->set_short(junk);
        return 1;
    }
    if (sscanf(str, "%s with %s and %s", dest, myring, mywax) != -1) {
        if (sscanf(str, "%s with %s and %s", dest, myring, mywax) != 3) {
            tell_object(TP, "Try seal <paper> with <sealing device> and <wax>.");
            return 1;
        }
        paper = present(dest, TP);
        if (!objectp(paper)) {
            return notify_fail("You don't have " + dest + "!\n");
        }
        if (!paper->id("paper")) {
            return notify_fail("That " + dest + " is not paper!\n");
        }
        wax = present(mywax, TP);
        if (!objectp(wax)) {
            return notify_fail("You don't have any " + mywax + "!\n");
        }
        if (!wax->is_sealing_wax()) {
            return notify_fail("That is not sealing wax!\n");
        }
        uses = wax->query_uses();
        if (uses < 1) {
            return notify_fail("You are out of " + mywax + "!\n");
        }
        ring = present(myring, TP);
        if (!objectp(ring)) {
            return notify_fail("You don't have any " + myring + "!\n");
        }
        if ((int)ring->query_is_seal_device() != 1) {
            return notify_fail("The " + myring + " is not a sealing device!\n");
        }
        if (paper->query_property("sealed")) {
            return notify_fail("The " + dest + " is already sealed!\n");
        }
        junk = paper->query_short();
        junk += " (sealed)";
        tell_object(TP, "You melt the " + mywax + " onto the " + dest + " and " +
                    "press your signet ring into it, sealing it from prying eyes.");
        paper->set_property("sealed", 1);
        junk = paper->query_short();
        junk += " (sealed)";
        paper->set_short(junk);
        morejunk = paper->query_long();
        morejunk += " (sealed)  The seal bears the image of " +
            "" + (string)ring->query_seal() + ".  The " +
            "seal itself is made of " + wax->query_color() + " sealing wax%^RESET%^.";
        paper->set_long(morejunk);
        wax->set_uses(uses - 1);
        return 1;
    }
}

int help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

seal - seal letters with wax

%^CYAN%^SYNOPSIS%^RESET%^

seal %^ORANGE%^%^ULINE%^PAPER%^RESET%^ with %^ORANGE%^%^ULINE%^DEVICE%^RESET%^ and %^ORANGE%^%^ULINE%^WAX%^RESET%^
seal break on %^ORANGE%^%^ULINE%^PAPER%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will allow you to seal a letter or other paper to prevent unwelcome eyes from reading it. Once a paper is sealed, the seal must be broken before it can be read.

%^CYAN%^SEE ALSO%^RESET%^

write, sign
"
        );
    return 1;
}
