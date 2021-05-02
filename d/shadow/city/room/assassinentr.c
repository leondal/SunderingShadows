#include "../defs.h"

inherit VAULT;

void create()
{
    set_short("%^BOLD%^%^BLACK%^A Shadowy Vestibule%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A Shadowy Vestibule%^RESET%^
%^RESET%^%^ORANGE%^Cramped and damp, this vestibule is where people come to air their grievances against someone who has wronged them. A %^WHITE%^board %^ORANGE%^stands here, awaiting the names of the condemned - those who will soon find themselves the prey of a professional killer. It is quite %^BOLD%^%^BLACK%^dark %^RESET%^%^ORANGE%^here, as if the %^BOLD%^%^BLACK%^shadows %^RESET%^%^ORANGE%^blot out any hints of outside light. Looking at the board will tell you what you need to know. There is a small %^RED%^seal%^ORANGE%^ in the center made of glowing runes.%^WHITE%^
");
    set_smell("default","%^RESET%^%^CYAN%^Scents from the river drift in from outside.%^WHITE%^");
    set_listen("default","%^RESET%^%^BLUE%^You can hear the sound of water rushing over rocks.");
    set_property("no teleport",1);
    set_items(([
                   ({"floor","wall","ceiling"}) : "%^RESET%^%^ORANGE%^Dark stones, resilient but old, hold together this sunken tower. The persistent dampness from the flowing river outside of the crumbling walls allows for %^BOLD%^%^GREEN%^gr%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^n m%^RESET%^%^GREEN%^o%^ORANGE%^s%^BOLD%^%^GREEN%^s %^RESET%^%^ORANGE%^to flourish between the cracks. %^CYAN%^Water %^ORANGE%^trickles in and pools in the corners of the uneven floors, making every slippery step seem perilous.%^WHITE%^",
                   ({"seal"}) :(:TO,"seal_des":),
                   ]));
    set_exits(([
                   "up":ROOMS+"/assassinoutside",
                   ]));
    set_door("hatch",ROOMS+"/assassinentr","up",0,0);
    set_door_description("silver door","%^RESET%^%^ORANGE%^The hatch is worn and weathered, and constructed of stout oak. A strange series of sigils line the periphery, occasionally flickering with obscene colors.%^WHITE%^");

    {
        object ob;
        ob = new(OBJ+"/assassinboard");
        ob->set_name("board");
        ob->set_id(({"board","bulletin board","assassin bounty board","assassin board"}));
        ob->set_board_id("assassin_bounty_board");
        ob->set_short("%^RESET%^%^ORANGE%^Assassin bounty board%^RESET%^");
        ob->set_long("%^BOLD%^%^GREEN%^This is a large board where writs of assassination may be freely posted.
%^BOLD%^%^GREEN%^By means of The Void, only assassins can read these.

%^BOLD%^GREEN%^Suggested payment and details of open bounty must be listed in the writ you issue. The guild will act as a middleman in all transactions.

%^BOLD%^RED%^Members of the guild are explicitly forbidden to share details of these contracts with anyone on the penalty of death.
");
        ob->set_max_posts(50);
        ob->set_restricted_read();
        ob->set_location(ROOMS+"/assassinentr");
    }
}

void init()
{
    ::init();
    add_action("touch_seal","touch");
}

string seal_des()
{
    if(TP->is_class("assassin")||TP->query("is_assassin"))
    {
        return "%^RED%^Faithful of The Void may touch the seal to enter the sanctuary.";
    }
    else
        return "%^RED%^The runes shift themselves and are impossible to read.";
}

int touch_seal(string str)
{
    if(str!="seal")
        return 0;
    //if(!(TP->is_class("assassin")||TP->query("is_assassin")||avatarp(TP))) - allowing other people to enter, but there will be consequences  - Tsera
        //return 0; 
    tell_room(TO,"%^BLUE%^"+TP->QCN+" shifts down through the floor.",TP);
    write("%^BLUE%^The floor looses its corporeality and you fall through it.");
    TP->move(ROOMS+"/assassinhall");
    TP->force_me("look");
    return 1;
}
