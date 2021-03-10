/*=====================================================
Newbie daemon that will be utilized by the files
/d/newbie/obj/misc/newbie_object.c
/d/newbie/ooc/hub_room

This daemon should only advance characters as long as they are below newbie level
and spawn equipment - basically it will allow for seasoned
characters to skip the newbie area and leave the area with some decent gear

The entire newbie area is being re-designed to be more of an OOC experience
to teach some commands/concepts 

Given that we have a very STEEP learning curve I do not anticipate
it being possible to entirely teach the game with any tutorial 
but hopefully this attempt is more encouraging to potential players. 

Saide - November, 2016

=======================================================*/

#include <std.h>
#include <daemons.h>
#include <new_exp_table.h>

inherit DAEMON;

void advance_level(object who)
{
    int myExp, expNext;
    if(!objectp(who)) return;
    if(!newbiep(who)) return;
    myExp = (int)who->query_exp();  
    expNext = EXP_NEEDED[(int)who->query_adjusted_character_level() + 1];
    expNext = expNext - myExp;
    if(expNext >= 0)
    {
        myExp += expNext;
        myExp += 1;
        tell_object(who, "\n%^BOLD%^%^CYAN%^You feel yourself become more experienced!%^RESET%^");
        who->set_exp(myExp);
    }
    if(newbiep(who))
    {
        environment(who)->set_property("training", 1);
        who->force_me("advance");
        environment(who)->set_property("training", -1);
    }
    return;    
}

varargs mixed make_obj(string file, object who, int align)
{
    object myOb;
    int myWeight;
    if(!objectp(who)) return "";
    if(!file_exists(file) && !file_exists(file +".c")) return "";
    myOb = new(file);
    myWeight = (int)myOb->query_weight();
    myOb->set_weight(0);
    myOb->move(who);
    myOb->set_weight(myWeight);
    myOb->set_size((int)who->query_size());
    myOb->set_myAlign(align);
    return myOb->query_short();
}

varargs void spawn_eq(object who, int which, int align)
{
    string myObs;
    if(!objectp(who)) return;
    myObs = "";
    switch(which)
    {
        case 1:
            myObs += make_obj("/d/newbie/obj/misc/newbie_ring.c", who);
            if(who->is_class("mage") || who->is_class("sorcerer") || who->is_class("psion"))
            {
                myObs += " and " + make_obj("/d/newbie/obj/armor/newbie_robe", who);
            }
            else if(FEATS_D->usable_feat(who, "heavy armor proficiency"))
            {
                myObs += " and " + make_obj("/d/newbie/obj/armor/newbie_plate", who);
            }
            else if(FEATS_D->usable_feat(who, "medium armor proficiency"))
            {
                myObs += " and " + make_obj("/d/newbie/obj/armor/newbie_banded", who);
            }
            else if(FEATS_D->usable_feat(who, "light armor proficiency"))
            {
                myObs += " and " + make_obj("/d/newbie/obj/armor/newbie_hide", who);
            }
            if(stringp(myObs) && myObs != "") tell_object(who, "\n\nAstonishingly "+myObs+" appears in your inventory!");
            break;
        case 2:
            myObs += make_obj("/d/newbie/obj/clothing/newbie_belt.c", who);
            if(who->is_class("mage") || who->is_class("sorcerer") || who->is_class("psion"))
            {
                myObs += " and " + make_obj("/d/newbie/obj/clothing/newbie_pants", who);
            }
            else if(FEATS_D->usable_feat(who, "heavy armor proficiency") ||
            FEATS_D->usable_feat(who, "medium armor proficency"))
            {
                myObs += " and " + make_obj("/d/newbie/obj/armor/newbie_greaves", who);
            }
            else if(FEATS_D->usable_feat(who, "light armor proficiency"))
            {
                myObs += " and " + make_obj("/d/newbie/obj/armor/newbie_leather_greaves", who);
            }
            if(stringp(myObs) && myObs != "") tell_object(who, "\n\nAstonishingly "+myObs+" appears in your inventory!");
            break;
        case 3:
            myObs += make_obj("/d/newbie/obj/armor/newbie_bracers.c", who);
            if(!present("newbiecloakobject", who))
            {
                myObs += " and " + make_obj("/d/newbie/rooms/keep/obj/cloak.c", who);
            }
            if(stringp(myObs) && myObs != "") tell_object(who, "\n\nAstonishingly "+myObs+" appears in your inventory!");
            break;
        case 4:
            break;     
        case 5:
            if((string)who->query_race() == "centaur" || (string)who->query_race() == "minotaur") 
            {
                myObs += make_obj("/d/newbie/obj/armor/newbie_horseshoes.c", who);
            }
            else 
            { 
                myObs += make_obj("/d/newbie/obj/armor/newbie_boots.c", who);
            }
            if(stringp(myObs) && myObs != "") tell_object(who, "\n\nAstonishingly "+myObs+" appears in your inventory!");
            break;
        case 6:
            if(who->is_class("mage") || who->is_class("sorcerer") || who->is_class("psion"))
            {
                myObs = make_obj("/d/newbie/obj/armor/newbie_hat.c", who, align);
            }
            else if(FEATS_D->usable_feat(who, "heavy armor proficiency") ||
            FEATS_D->usable_feat(who, "medium armor proficency"))
            {
                myObs = make_obj("/d/newbie/obj/armor/newbie_helm", who, align);
            }
            else if(FEATS_D->usable_feat(who, "light armor proficiency"))
            {
                myObs = make_obj("/d/newbie/obj/armor/newbie_coif", who, align);
            }
            if(stringp(myObs) && myObs != "") tell_object(who, "\n\nAstonishingly "+myObs+" appears in your inventory!");
            break;
    }
}

