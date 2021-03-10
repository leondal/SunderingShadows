// koboldf.c - Kobold for the newbietown forest

#include <std.h>
#include "../../../newbie.h"
#include "../drownew.h"
#include <daemons.h>

inherit "/std/monster";

void create()
{
    object ob;
    ::create();
    set_name("kobold");
    set_id( ({ "kobold", "snark"}) );
    set_race("kobold");
    set_gender("male");
    set_short("Snark, A red-eyed, smelly kobold");
    set_long("%^BOLD%^%^RED%^This ugly little creature has beady red eyes and two small horns "+
    "protruding from the top of his head. He looks much bigger than the other kobolds "+
    "you have encountered. One of his ears is actually missing, as if it has been "+
    "torn off. His scaly body is much larger, as if he has seen his fair share of "+
    "combat and his hairless tail is tipped with a metal barb piercing. His claws "+
    "look almost as if they have been intentionally sharped.%^RESET%^");
    set_body_type("human");
    set("aggressive",10);
    set_alignment(6);
    set_size(1);
    set_hd(5,2);
    set_hp(95 + random(20));
    set_overall_ac(8);
    set_stats("intelligence",6);
    set_stats("wisdom",6);
    set_stats("strength",15);
    set_stats("charisma",5);
    set_stats("dexterity",16);
    set_stats("constitution",14);
    set_max_hp(query_hp());
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    new(CWEAP"mspear")->move(TO);
    command("wield spear");
    if(random(8) < 6) 
    {
        new(STUFF"kobvest")->move(TO);
        command("wear vest");
    }
    add_money("gold",random(250));
    add_money("silver",random(80));
    add_money("copper",random(20));
    set_property("swarm",1);
    set_achats(5, ({"%^RED%^The kobold darts back and forth.%^RESET%^", "%^RED%^The kobold's tail twitches as he dodges for position.%^RESET%^"}) );
    set_emotes(2, ({"The kobold tries to sharpen his spear on a rock.", 
	"The kobold's tail twitches as he points his spear at you.", 
	"The kobold's beady red eyes seem to be sizing you up.", 
	"The kobold darts past and tries to steal something." 
      }), 0);
    set_new_exp(1, "very low");
}

void die(object ob) 
{
    int Amt;
    object obj;
    string *tmpquests;
    object *MyKillers;
    
    MyKillers = TO->query_attackers();
    MyKillers = filter_array(TO->query_attackers(), "is_player", FILTERS_D);
        
    for(Amt = 0;Amt < sizeof(MyKillers);Amt++)
    {
        if(!objectp(MyKillers[Amt])) continue;
        if(environment(MyKillers[Amt]) != ETO) continue;
        tmpquests = MyKillers[Amt]->query_mini_quests();
        if(member_array("%^BOLD%^%^CYAN%^Newbie Quest: %^BOLD%^%^RED%^Killed the Gnome Leader!%^RESET%^", tmpquests) != -1 || 
        member_array("%^BOLD%^%^CYAN%^Newbie Quest: %^BOLD%^%^RED%^Killed the Kobold Leader!%^RESET%^", tmpquests) != -1) continue;
        
        MyKillers[Amt]->set_mini_quest("%^BOLD%^%^CYAN%^Newbie Quest: %^BOLD%^%^RED%^Killed the Kobold Leader!%^RESET%^",
        0, "%^BOLD%^%^CYAN%^Newbie Quest: %^BOLD%^%^RED%^Killed the Kobold Leader!%^RESET%^");
        
        tell_object(MyKillers[Amt], "%^BOLD%^%^RED%^\nYou have slain the leader of the kobolds!%^RESET%^");
        if(objectp(obj = present("newbiemassobject", MyKillers[Amt]))) 
        {
            if((int)obj->query_myTask() == 5) obj->advance_task();
            obj->adjust_my_align(25 + random(25));
        }
    }
    return ::die(ob);
}

