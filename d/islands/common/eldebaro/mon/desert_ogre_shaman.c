#include <std.h>
inherit MONSTER;
#include "../area_stuff.h"

void create()
{
    int lev;
    object ob;
    string me;
    ::create();
    set_name("desert ogre shaman");
    set_id( ({"ogre", "shaman", "ogre shaman", "desert shaman", "desert ogre", "eldebarocreature"}) );
    
    set_short("%^RESET%^%^ORANGE%^A massive %^BOLD%^o%^RESET%^%^ORANGE%^gr%^BOLD%^e%^RESET%^%^ORANGE%^"+
    " cloaked in a %^BOLD%^%^YELLOW%^brilliant%^RESET%^%^ORANGE%^ robe%^RESET%^");
    
    set_long("%^RESET%^%^ORANGE%^This ogre is cloaked with a %^BOLD%^%^YELLOW%^"+
    "brilliant%^RESET%^%^ORANGE%^ robe that gives off a soft glow. He is massive, towering "+
    "nearly ten feet in the air. However, he does not look angry or enraged. In fact his "+
    "face looks quite stoic, as if he is immensely focused on something. He waves "+
    "his hands in front of himself chaotically, as if he is preparing some type of "+
    "magic, occasionally chanting in some strange language as he does. The rest of his body "+
    "appears quite tense, almost as if he is on high alert or maybe even afraid of "+
    "something.%^RESET%^");
    
    
    set_gender("male");
    set_race("ogre");
    set_body_type("human");
    set_overall_ac(-20);
    set_property("swarm",1);
    lev = 32 + random(9);
    set_class("cleric");
    set_mlevel("cleric",lev);
    set_guild_level("cleric",lev);
    set_speed(30);
    set_nogo(({ELROOMSD+"51",ELROOMSD+"102",ELROOMSD+"178",ELROOMSD+"107"}));
    set_stats("strength", 20);
    set_stats("dexterity", 8);
    set_stats("constitution", 20);
    set_stats("intelligence", 3);
    set_stats("wisdom", 19);
    set_stats("charisma", 3);
    //set("aggressive", 55);
    me = TO->query_short();
    
    set_emotes(3, ({"%^BOLD%^%^BLACK%^Darkness briefly overtakes "+me+" before he quickly chants and it goes away!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^shudders visibly and his entire massive body shakes%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^groans loudly as he completes another motion of his hands!%^RESET%^",
	    me+" %^BOLD%^%^BLACK%^adjusts his robe carefully as if he is trying to make sure his entire body is covered with it!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^sighs deeply, his entire body heaving!%^RESET%^",}),1);
    
    set_alignment(9);
    set_size(3);
    set_max_hp(lev * 25);
    set_hp(query_max_hp());
    set_property("full attacks", 1);
    add_money("gold", 400 + random(601));
    set_new_exp(lev,"normal");
   
    set_spell_chance(75);
    
    set_spells(({"earthquake", "flame strike", "call lightning"}));

    set_monster_feats(({"perfect caster", "spell power", "spell focus"}));
    ob = new(ELOB+"shroud_of_light"); 
    ob->set_size(3);
    ob->move(TO);
    if(random(4)) ob->set_property("monsterweapon",1);
    command("wear robe");
    if(!random(10)) new(ELOB+"dreadhorn_wrap")->move(TO);

}

int query_watched() { return random(101); }