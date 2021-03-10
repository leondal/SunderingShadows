#include <std.h>
#include "../undead.h";

inherit CREATURE;

int FLAG = 0;

void create() 
{
    ::create();
    set_name("Morock");
    set_id(({"morock","king","high king","dwarf","undead"}));
    set_race("undead");
	set_gender("male");
    set_short("High King Morock");
    set_long("High King Morock stands a towering 4 feet tall, but then again he "
        "is just about that wide. He still wears the immense Armor of the Dwarven Kings "
        "it's cold steel catches the light. Though it is quite clear that "
        "this is not the former Morock, this is yet another undead abomination "
        "like all the others this land seems more then capable of producing.");
    set_class("fighter");
    set_level(30);
    set_mlevel("fighter",30);
    add_search_path("/cmds/fighter");
    set_hd(30,8);
    set_hp(600);
    set_property("full attacks",1);
    set_body_type("human");
    set("aggressive",0);
    set_alignment(9);
    set_ac(0);
    set_size(2);
    set_property("swarm", 0);
    set_exp(50000);
    set_new_exp(25,"boss");
    set_stats("intelligence",18);
    set_stats("wisdom",18);
    set_stats("strength",19);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
    set_stats("constitution",20);
    set_parrying(1);
    new(OBJS"dwarf_kings_plate.c")->move(TO);
    command("wear plate");
    new(WEAPONDIR+"handaxe")->move(this_object());
    command("wield axe");
}

void heart_beat()
{
    object *ob;
    ::heart_beat();    

    if(!objectp(TO))    { return; }
    if(!objectp(ETO))   { return; }

    if(present("demon") || present("bishop") && !FLAG) 
    { 
        command("kill demon");
        command("kill bishop");
        FLAG = 1; 
        return; 
    }

    if(!present("demon" || "bishop") && !sizeof(TO->query_attackers()))
    {
        force_me("say Thank you my young friend, thanks to you at least this land has rid itself of one evil.");
        force_me("say Now I can rest in piece knowing that Kartakass shall no longer be able to depend on the aid of that horrible demon.");
        force_me("say Maybe given time the forces of good will be able to topple Kartakass's evil empire.");
        force_me("say I owe you a great dept...here take my armor as a token of my thanks, maybe you can find a use for it in this world.");
        force_me("say Let it guide you well as it did me in the past.");
        force_me("remove plate");
        command("drop plate");
        force_me("say Farewell my friend.");
        tell_room(ETO, "%^BOLD%^Morock slowly turns around and walks back through the gates of hell." ,TO);
        TO->remove();
        return 1;
    }
}



