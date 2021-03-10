#include <std.h>

inherit ROOM;

string what_alignment(int align);
int raise_player(string verb);

string WHICH_CALL_OUT;

void create() 
{
    ::create();
    set_short("The gate to the etherial plane");
    set_property("light", 2);
    set_property("no teleport", 1);
    set_property("indoors", 1);
    set_long("You are floating in a strange room...");
}

void attempt_raise()
{
    string diety,alignment,type;
    if(!TP->query("RaisingRoom")) { return; }

    alignment = what_alignment((int)TP->query("RaisingPriestAlignment"));
    diety     = (string)TP->query("RaisingPriestGod");
    type      = (string)TP->query("RaisingType");

    if(type == "deny the reaper") 
    {
        tell_object(TP,"%^RESET%^%^B_CYAN%^You can feel a pull on your soul.  You sense "
        "the tendrils of a necromancer's arcane energy trying to steal you away from "
        "the afterlife!\nType <accept> to return to life, or <cancel> to leave your "
        "fate in Lysara's hands.%^RESET%^");
        return;
    }

    tell_object(TP,"%^RESET%^%^B_CYAN%^You can feel a pull on your soul.  You sense "
    "that a "+alignment+" faithful of "+capitalize(diety)+" is trying to return "
    "you to life!\nType <accept> to return to life, or <cancel> to leave your "
    "fate in Lysara's hands.%^RESET%^");
    return;
}

void get_the_verb()
{
    raise_player(query_verb());
    return;
}

int raise_player(string verb)
{
    string diety,alignment,room,type;
    int loss;

    if(!objectp(TP)) { return 0; }
    if(avatarp(TP)) { return 1; }
    if(!TP->query("RaisingRoom")) { return 0; }

    room      = (string)TP->query("RaisingRoom");
    loss      = (int)TP->query("RaisingExpLoss");
    type      = (string)TP->query("RaisingType");
    if(TP->query("previous alternative world")) 
    {
        TP->set("alternative world", TP->query("previous alternative world"));
        TP->delete("previous alternative world");
    }
    if(!objectp(find_object_or_load(room))) 
    { 
        TP->delete("alternative world");
        room = "/d/shadowgate/death/death_exit";         
    }

    switch(verb)
    {
    case "accept":
        TP->revive(loss);
        if(type == "raise dead" || type == "deny the reaper") { TP->set_hp(10); }
        else { TP->set_hp((int)TP->query_max_hp()); }
        TP->set_heart_beat(1);
        TP->cease_all_attacks();
        TP->move(room);
        TP->force_me("look");
        TP->remove_pk_death_flag();
        TP->set_death_age(0);
        TP->delete("RaisingRoom");
        TP->delete("RaisingPriestAlignment");
        TP->delete("RaisingPriestGod");
        TP->delete("RaisingExpLoss");
        TP->delete("RaisingType");
        tell_object(TP,"%^BOLD%^You have choosen to return to life!%^RESET%^");
        tell_room(environment(TP),"%^BOLD%^"+TP->QCN+" has returned from the dead!",TP);
        if(stringp(WHICH_CALL_OUT)) { remove_call_out(WHICH_CALL_OUT); }
        // intentionally left a break out of here
    case "cancel":
        if(verb == "cancel")
        {
            tell_object(TP,"%^BOLD%^You have choosen to leave your fate in Lysara's hands!%^RESET%^");
        }
        TP->delete("RaisingRoom");
        TP->delete("RaisingPriestAlignment");
        TP->delete("RaisingPriestGod");
        TP->delete("RaisingExpLoss");
        TP->delete("RaisingType");
    }
    return 0;
}

string what_alignment(int align)
{
    string alignment;
    switch(align)
    {
    case 1: alignment = "Lawful Good"; break;
    case 2: alignment = "Lawful Neutral"; break;
    case 3: alignment = "Lawful Evil"; break;
    case 4: alignment = "Neutral Good"; break;
    case 5: alignment = "True Neutral"; break;
    case 6: alignment = "Neutral Evil"; break;
    case 7: alignment = "Chaotic Good"; break;
    case 8: alignment = "Chaotic Neutral"; break;
    case 9: alignment = "Chaotic Evil"; break;
    default: alignment = "necromancer"; break;
    }
    return alignment;
}
