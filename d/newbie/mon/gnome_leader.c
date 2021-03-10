// /d/newbie/mon/gnome1.c
#include "../newbie.h";
#include <daemons.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("gnome");
    set_id(({"gnome","fat gnome", "large gnome", "siffunmo"}));
    set_race("gnome");
    set_body_type("human");
    set_gender("male");
    set_short("Siffunmo, A large bulbous gnome");
    set_long("This creature looks quite a bit like a small, slender dwarf except you can't miss the bulbous nose that dominates his round face.  "+
    "His face is smooth but round and quite chubby, as if he eats better than most of his kin. "+
    "His body is bulbous and he is obviously quite overweight. He has sparkling green eyes which reflect the torchlight and stand in stark "+
    "contrast to his deep woody brown skin and pale gray hair.");
 	set_class("fighter");
 	set_level(5);
    add_search_path("/cmds/fighter");
    set("aggressive",1);
    set_wimpy(10);
    set_hp(90 + random(20));
	set_stats("intelligence",12);
    set_stats("wisdom",10);
    set_stats("strength",15);
    set_stats("charisma",10);
    set_stats("dexterity",10);
    set_stats("constitution",17);
    set_property("swarm",1);
    set_alignment(4);
    set_size(1);
    new("/d/newbie/obj/weapons/sdagger")->move(TO);
    command("wield dagger");
    new("/d/newbie/obj/weapons/sdagger")->move(TO);
    command("wield dagger");
    add_money("silver",random(10));
    add_money("copper",random(20));
    set_emotes(3, ({"%^BOLD%^The gnome hums as he watches over the mines.", "%^BOLD%^%^BLUE%^The small gnome yawns casually as he sits down for another rest.", 
    "%^BOLD%^%^BLUE%^The small gnome smiles at you but seems to be a little nervous.", 
    "%^BOLD%^%^BLUE%^The gnome sharpens his dagger on a soft stone.", 
    "%^BOLD%^The gnome chuckles to himself as he picks his teeth with his dagger."}), 0);
	 set_achats(4, ({"%^YELLOW%^The small gnome cries out in fear as he tries to defend himself.", 
     "%^YELLOW%^The small gnome tries to run past you to escape.", 
     "%^YELLOW%^The gnome dodges toward an exit fearfully." }));
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
        
        MyKillers[Amt]->set_mini_quest("%^BOLD%^%^CYAN%^Newbie Quest: %^BOLD%^%^RED%^Killed the Gnome Leader!%^RESET%^",
        0, "%^BOLD%^%^CYAN%^Newbie Quest: %^BOLD%^%^RED%^Killed the Gnome Leader!%^RESET%^");
        
        tell_object(MyKillers[Amt], "%^BOLD%^%^RED%^\nYou have weakened the gnomish forces!%^RESET%^");
        if(objectp(obj = present("newbiemassobject", MyKillers[Amt]))) 
        {
            obj->adjust_my_align(0 - 25 - random(25));
            if((int)obj->query_myTask() == 5) obj->advance_task();
        }
    }
    return ::die(ob);
}

