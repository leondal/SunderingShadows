// another powder under 'tools of the trade' feat for thieves and bards. N, 10/15.
#include <std.h>
#include <daemons.h>
#include "../brew.h"
inherit BREWPOWDER;

int uses;

void create() 
{
   ::create();
   set_name("small bag");
   set_id(({"powder","bag","gleaming powder","life powder","powder of life"}));
   set_obvious_short("%^RESET%^%^CYAN%^a small bag of %^BOLD%^%^CYAN%^gleaming powder%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^powder of life%^RESET%^");
   set_long("This bag contains a collection of powders with a very odd smell.  "
"A sharp, but not unpleasant, aroma rises from the bag and seems to put an edge "
"on your senses even from the slightest whiff. The fine dust gleams under any "
"light with a rather pretty incandescence. You could probably <scatter the "
"powder over playername>.");
   set_value(600);
   set_weight(2);
   uses = 1;
   set_myname("powder of life");
}

void set_myname(string thename) {
    set_lore("This powder is one crafted by many alchemists of the land.  Because of the ingredients used, "+
"such powders often have similar qualities, such as color and smell.  You're familiar enough with this "+
"particular variety, to believe it is probably a "+thename+", able to draw the breath back into a body if "+
"used soon after death.");
    myname = thename;
}

void init() {
   ::init();
   add_action("rez_time","scatter");
}

int rez_time(string str) {
    string mystring, what;
    object who;
    if(!objectp(TP)) return 1;
    if(!objectp(ETP)) return 1;
    if(TP->query_property("shapeshifted")) {
        tell_object(TP,"You can't use powder while shapeshifted");
        return 1;
    }
    if(userp(TP) && !FEATS_D->usable_feat(TP,"tools of the trade")) {
        tell_object(TP,"You wouldn't know how to use that!");
        return 1;
    }
    if((int)TP->is_retinue()) {
        tell_object(TP,"You wouldn't know how to use that!");
        return 1;
    }
    if(!uses) {
        tell_object(TP,"The bag of powder is empty!");
        return 1;
    }
    if(!str) {
        tell_object(TP,"Who do you want to <scatter the powder over>?");
        return 1;
    }
    if(sscanf(str,"the powder over %s",mystring) != 1) {
        tell_object(TP,"Who do you want to <scatter the powder over>?");
        return 1;
    }
    what = "corpse of "+TP->realName(lower_case(mystring))+"";
    who = find_player(TP->realName(lower_case(mystring)));

    if(!who) {
        tell_object(TP,"You don't think that would do anything.");
        return 1;
    }
    if(!present(what,ETP)) {
        tell_object(TP,"You don't see "+mystring+"'s body here to scatter the powder over.");
        return 1;
    }

    tell_object(TP,"%^BOLD%^%^CYAN%^You scatter the small bag of powder over the corpse and hope for the best...%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" scatters a small bag of gleaming powder over the corpse.%^RESET%^",TP);
    new("/cmds/spells/d/_deny_the_reaper")->use_spell(TP,mystring,10,100,"potion");

    uses = 0;
    TO->set_short("An empty bag");
    TO->set_obvious_short("An empty bag");
    TO->set_value(1);
    set("coin type","copper");
    set_long("This empty bag used to hold some kind of powder, but there are only a few gleaming motes left now.");
    while(query_property("no offer")) remove_property("no offer");
    return 1;
}