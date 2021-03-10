#include <std.h>

inherit MONSTER;

void create() 
{
    string myrace, *eyes, *hair, eye, hc, MyFile, COL, HC, EC, *PCOLS, *POSSIBLE_RACES;
    int mylvl;
    object ob;
    hc = "brown";
    eye = "blue";
    ::create();
    PCOLS = ({"%^BOLD%^%^BLUE%^", "%^BOLD%^%^GREEN%^", "%^BOLD%^%^MAGENTA%^", "%^BOLD%^%^RED%^", "%^BOLD%^%^YELLOW%^","%^BOLD%^%^BLACK%^", "%^BOLD%^%^WHITE%^"});
    POSSIBLE_RACES = ({"minotaur", "dwarf", "half-orc", "orc", "human"});
    myrace = POSSIBLE_RACES[random(sizeof(POSSIBLE_RACES))];
    set_name(myrace+ " mizat encampment guard");
    
    mylvl = 18 + random(11);
    
    EC = PCOLS[random(sizeof(PCOLS))];
    PCOLS -= ({EC});
    HC = PCOLS[random(sizeof(PCOLS))];
    PCOLS -= ({HC});
    COL = PCOLS[random(sizeof(PCOLS))];
    
    set_race(myrace);    
    
    set_id( ({ "mizat guard", myrace, myrace +" mizat guard",
    myrace + " guard", "guard"}) );
    MyFile = "/std/races/"+myrace+".c";
    set_body_type("human");
    set_class("fighter");
    set_alignment(5);
    set_hd(mylvl,12);
    set_hp((mylvl * 10) + random(30));
    set_max_hp(query_hp());    
    
    set_stats("strength", 17 + random(3));
    set_stats("constitution", 16 + random(4));
    set_stats("dexterity", 15 + random(3));
    set_stats("wisdom", 12 + random(3));
    set_stats("intelligence", 12 + random(3));
    set_stats("charisma", 11 + random(3));
    
    
    if(file_exists(MyFile))
    {
        eyes = MyFile->query_eye_colors(TO);
        hair = MyFile->query_hair_colors(TO);
        if(pointerp(eyes)) eye = eyes[random(sizeof(eyes))];
        if(pointerp(hair)) hc = hair[random(sizeof(hair))];
    }
    
    set_gender("male");
    
    set_short(COL+"A massive male "+myrace+" with "+EC+eye+" eyes"+COL+" and scraggily "+HC+hc+" hair");
    
    set_long(COL+"This massive male "+myrace+" looks as if he has "+
    "spent a good number of years doing nothing more than "+
    "demanding physical labor. However, amazingly, his "+EC+eye+" eyes "+COL+
    "look inviting, as if he is a friendly soul despite the grueling labor "+
    "he has endured or perhaps because of it. His "+HC+hc+" hair "+COL+"is scraggily "+
    "and unwashed, as if he has not taken care of it in a very long time. "+
    "Though you suspect that down here that is the least of his worries. "+
    "His kind eyes glance around constantly, as if he is ever on alert, despite "+
    "his obviously friendly nature.%^RESET%^");   
    
    if(random(2)) ob = new("/d/common/obj/weapon/longsword");
    else ob = new("/d/common/obj/weapon/scimitar");
    ob->set_property("enchantment", 2 + random(2));
    if(random(10)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield scimitar");    
    command("wield sword");
    
    if(random(2)) ob = new("/d/common/obj/armour/mshield");
    else ob = new("/d/common/obj/armour/sshield");
    ob->set_property("enchantment", 2 + random(2));
    if(random(10)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wear shield");
    
    if(!random(4)) ob = new("/d/common/obj/armour/fullplate");
    else if(random(2)) ob = new("/d/common/obj/armour/breastplate");
    else ob = new("/d/common/obj/armour/chain");
    ob->set_property("enchantment", 1 + random(2));
    if(random(15)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wear plate");    
    command("wear chain");
    command("wear breastplate");
    
    add_money("silver", 125 + random(55));
    add_money("gold", 175 + random(85));
    add_money("copper", 255 + random(65));    
    set_new_exp(mylvl, "normal");        
    set_monster_feats(({"rush", "shieldbash", "parry"}));
    ob = new("/d/charucavern/diseases/deep_flu");
    ob->move(TO);
    ob->set_incubation_period(0);
    ob->set_infected(TO);
} 
