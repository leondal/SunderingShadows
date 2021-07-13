#include <std.h>
#include <namegen.h>
#include <daemons.h>

inherit MONSTER;

void create()
{
    ::create();
    make_me();
    set_body_type("human");
    set_class("fighter");
    set_class("mage");
    set("aggressive",2);
    set_property("swarm",0);
    set_hd(50,8);
    set_hp(25000);
    set_alignment(5);
    set_class("mage");
    set_mlevel("mage",70);
    set_guild_level("mage",70);
    set_guild_level("fighter",70);
    set_stats("intelligence",28);
    set_stats("wisdom",20);
    set_stats("strength",20);
    set_stats("charisma",8);
    set_stats("dexterity",20);
    set_stats("constitution",28);
    set_property("magic",1);
    set_new_exp(100,"boss");
    set_property("cast and attack",1);
    set_spells(({"prsimatic burst",
                    "prismatic burst",}));
    set_spell_chance(100);
    set_property("function and attack", 1);
    set_funcs(({"mercy"}));
    set_func_chance(5);
}

void mercy(object target)
{
    object *living;
    ::heart_beat();

    /*
    tell_room(ETO,"%^RESET%^%^MAGENTA%^"+query_name()+" speaks in an angry voice:%^RESET%^ Not today.");
    tell_room(ETO,query_name()+" snaps her fingers.");
    target->die();
    */
}

void make_me()
{
    string name;
    name = GENNAM(4,random(4)+1,);
    set_race("outsider");
    set_gender("female");
    set_name(name);
    set_short("%^RESET%^"+({"%^BLUE%^","%^MAGENTA%^","%^RED%^","%^ORANGE%^"})[random(4)]+name+"%^CYAN%^, Collector of Lost Relics%^RESET%^");
    set_id(({name,lower_case(name),"questor",query_race(),"collector","Collector"}));
    set_long("%^CYAN%^"+name+" is a proprietor of lost "+
    "artifacts. "+capitalize(TO->QS)+" is dressed in a "+
    "simple %^BLUE%^blue robe%^CYAN%^ that lacks any style or elegance. "+
    "She stands by quietly, keeping a careful watch over her "+
    "surroundings. While rather unassuming, your instincts warn you "+
    "that it would not be wise to overstep your welcome.\n"+ 
    "%^RESET%^%^GREEN%^You may wish to %^BOLD%^<read list>%^RESET%^%^GREEN%^ to see a sampling of the lost relics she seeks, "+
    "or you may %^BOLD%^<claim ITEMNAME>%^RESET%^%^GREEN%^ to be properly rewarded.%^RESET%^");
}

void thank()
{
    string thanklist;
    thanklist = ({
            "I've waited a long time for this.",
                "Now this one... this one is special.",
                "Well done!",
                "It must have been quite an adventure finding this.",
                "Thank you!",
                "Thanks so much!",
                "This is wonderful. Truly exquisite!",
                "Ahh..  priceless!",
                "Many thanks.",
                });
    tell_room(ETO,"%^RESET%^%^MAGENTA%^"+query_name()+" speaks with enthusiasm:%^RESET%^ "+thanklist[random(sizeof(thanklist))]);
}

void receive_given_item(object obj)
{
    tell_room(ETO,"%^RESET%^%^MAGENTA%^"+query_name()+" speaks in a kind voice:%^RESET%^ Try <claim>ing this instead.");
    force_me("drop "+obj->query_id()[0]);
}

void die(object ob)
{
    WORLD_EVENTS_D->kill_event("A rare opportunity");
    WORLD_EVENTS_D->inject_event((["A rare opportunity" : (["start message": "For the next two hours all experience gained will award an additional 15%!","event type" : "exp bonus", "length" : 120, "notification" : "15% Bonus Exp","event name" : "A rare opportunity", "modifier" : 15,"announce" : 1, "announce to" : "world" ]),]));
    ::die(ob);
}
