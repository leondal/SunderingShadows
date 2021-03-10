#include <std.h>
#include <daemons.h>
#include "/daemon/nwps_d.h"

#define WAIT 7200    // 60 secs/min * 60 min/hr * 4 hrs. 
// checks for time delay between training nwps added by Styx 6/6/03
// expanded the help file -Ares 8/21/06

inherit DAEMON;

int help();
int check_class(string theclass,object player);
int accept();
int forsake();

int cmd_dualclass(string str){
    string who, what, realwho;
    object player;
    int prof, other_prof, oldprof;

    if (!str)
        return help();

    if (str == "accept")
        return accept();

    if (str == "forsake") {
        return forsake();
    }


    if (sscanf(str,"%s in %s",who, what) != 2)
        return help();

    if (!player = present(who, ETP)) {
           return notify_fail(capitalize(who)+" isn't here.\n");
    }

    if ((string)player->query_race() != "human") {
        return notify_fail("You can not dual class a non human.\n");
    }

    if (player->is_class("cavalier") || player->is_class("antipaladin") || player->is_class("paladin")) {
        write("%^BOLD%^You can not dual class a knight.");
        return 1;
    }

    if (what == "paladin" || what == "antipaladin" || what=="cavalier") {
        write("%^BOLD%^You can not dual class a knight.");
        return 1;
    }


     if(player->get_dual_class()){
         write("That player is already dual classed, triple classing is currently not allowed.");
         return 1;
     }

    if (!TP->is_class(what)) {
        write("%^BOLD%^You can't help dual class in something you aren't");
        return 1;
    }

    if (TP->query_age() < 864000) {
        write("%^BOLD%^You don't have enough experience to help someone dual class.");
        return 1;
    }

    if (!check_class(what,player)) {
        write("%^BOLD%^That person does not meet the requirements for dual classing.");
    }


    TP->force_me("say I will begin your instruction as a "+what+" please acknowledge that you know what the price for dual classing is by typing \"dualclass accept\" within 60 seconds.");
    player->set("dualclassing",(["time":time(),"trainer":TP,"class":what]));
    return 1;
}

int check_class(string theclass, object player){
    int astr, adex, acon, awis, acha, aint;
    int align;

    align = player->query_alignment();

    astr = player->query_stats("strength");
    adex = player->query_stats("dexterity");
    acon = player->query_stats("constitution");
    awis = player->query_stats("wisdom");
    acha = player->query_stats("charisma");
    aint = player->query_stats("intelligence");
    switch (theclass) {
    case "fighter":
        return (astr > 15);
        break;
    case "cleric":
        return (awis > 15);
        break;
    case "thief":
        return (adex > 15);
        break;
    case "mage":
        return (aint > 15);
        break;
    case "psion":
        return (aint > 16);
        break;
    case "bard":
        return ((adex > 15) && (aint > 12) && (acha > 15) && (align == 2 || align == 4 || align == 5 || align == 6 || align == 8));
        break;
    case "ranger":
        return ((astr > 16) && (adex > 16) && (acon > 13) && (awis > 16) );
        break;
    default:
        return 0;
    }

}

int accept(){
    string theclass;
    object trainer;
    mapping info;
    int adv;

    info = TP->query("dualclassing");
    if (!info)
        return notify_fail("You have not been offered any dualclassing.\n");

    theclass = info["class"];
    trainer = info["trainer"];

    if (time() > (int)info["time"]+60)
        return notify_fail("Your time has run out.\n");

    if (!objectp(trainer) || !present(trainer,ETP))
        return notify_fail("The trainer has moved or no longer exists.\n");
    
    write("You are accepted now as a dual class "+theclass+" you have agreed to not use any of your ability for your previous class.");
    TP->set_dual_class(theclass);
    return 1;
}

int forsake(){
    write("%^BOLD%^You choose to forsake your training as a "+TP->get_dual_class()+".");
    TP->set_dual_class(0);
    return 1;
}

int help() {
    write("dualclass [who] in [what class]\n"+ 
     "dualclass accept - to accept training from both PC's\n"+
     "dualclass forsake - this will give up on the dual classing altogether.\n"+ 
     "You will be returned to the state before starting your dualclass.\n"+
     "\n Dual classing is a special ability for humans. It allows them to switch"+ 
"classes after attaining a satisfactory level in their first class. Knights "
"can not dual class. To dual class you will need to have 17s in the prime "
"requisits of the class to which you are changing. You loose all the "
"abilities of the first class until you gain a level equal to or greater" 
"than the first class.  The proficiencies from the second class are not"
"added on when a person dual classes, but rather as the levels go up in"
"the second class, the better of the two classes is picked.  Hence a level"
"15 fighter would have more profs than a level 15 thief, and so the "
"fighter proficiencies would be used. \n"
"%^BOLD%^%^RED%^Please submit an %^YELLOW%^<avatarmail>%^RED%^ with the reasons"+
" why you are dualclassing and who you are training with.  This gives the "+
"immortals a better understanding of what changes your character is going "+
"through. Questions to think of are :\n"+
"%^ORANGE%^Why am I giving up this life? \n"+
"If you are a mage, why are you giving up magic.  If you are a fighter why are "+
"you looking for a new path?  If you are a cleric, why are you leaving the "+
"service of your god?\n"+
"%^ORANGE%^What events have lead to this choice?\n"+
"%^ORANGE%^What role playing have you done prior to your dualclassing to"+
" learn this new life you are living.\n"+
"\n%^RESET%^Please note, as a dual class character, you are not protected from"+
" your enemies by being lower level.  Offestry is not a place you should go "+
"back to, as you are not a newbie.  Please spend the time learning this new"+
" life and don't see this as a way for you to power level back up.  The same"+
" rules and policies for Role Playing apply to dualclassing, and can carry "+
"the same rewards and punishments.");
    return 1;
}
