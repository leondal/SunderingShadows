#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;

int x;

void create() 
{
    int y, i;
    ::create();
    set_name("hound keeper");
    set_id( ({"keeper", "hound keeper", "Javiijeys", "javiijeys"}));
    set_gender("male");
    set_race("dwarf");
    set_short("%^RED%^J%^YELLOW%^a%^RED%^v%^YELLOW%^ii%^RED%^j%^YELLOW%^e"+
    "%^RED%^ys, Keeper of The Ho%^YELLOW%^u%^RED%^nds%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This ashen skinned dwarf stands "+
    "approximately four feet tall, yet the way he carries himself "+
    "makes him appear closer to five.  His chest sticks out proudly "+
    "and his back is straight, though grotesquely muscled.  His face "+
    "is scarred, almost beyond recognition, and you realize "+
    "that it is simply a testament to his untold years in "+
    "combat.  His eyes are alert and radiate with "+
    "a disturbing wisdom mingled with something else "+
    "that you recognize to be a still unsated thirst for "+
    "blood.  He carries, with both hands, a "+
    "dull gray longsword.%^RESET%^");
  
    set_body_type("human");
    set_size(1);
    set_alignment(9);
    add_money("gold", 2000 + random(1200));
    x = 26;
    set_hd(x,1);
    set_stats("strength",17);
    set_stats("intelligence",15);
    set_stats("constitution",14);
    set_stats("dexterity",19);
    set_stats("wisdom",19);
    set_stats("charisma",8);
    set_class("cleric");    
    set_mlevel("cleric", x);
    set_class("fighter");
    set_mlevel("fighter",x);
    set_guild_level("fighter",x);
    set_guild_level("cleric",x);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_hp(400 + random(51));
    //set_exp(12000);
    set_new_exp(25, "very high");
    set_funcs(({"here_puppy_puppy"}));
    set_func_chance(25);
    set_max_level(30);
    set("aggressive","kill_things");
    set_spells(({"flame strike", "limb attack", "flameburst"}));
    set_spell_chance(40);
    new(DEKU_WEP"gray_longsword")->move(TO);
    command("wield sword");
    //new(DEKU_ARM"eviscerator_exoskeleton")->move(TO);
    //command("wear armor");
 }

void heart_beat()
{
    object k, *atts;
    int y;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    atts = TO->query_attackers();
    if(!sizeof(atts)) return;
    for(y = 0;y < sizeof(atts);y++) 
    {
        if(atts[y]->id("saidedekufiremon")) 
        {
            TO->remove_attacker(atts[y]);
            atts[y]->remove_attacker(TO);
            return;
        }
    }
}


void here_puppy_puppy(object targ) 
{
    int x;
    object ob;
    if(!random(2)) return;
    if(!TO) return;
    command("say Come Forth my minions, protect your master!");
    x = 1 + random(2);
    while(x > 0)	
    {
        tell_room(ETO, "%^BOLD%^%^RED%^A hellhound rushes into the "+
        "room, in protection of Javiijeys!%^RESET%^");
        ob = new(DEKU_MON"hellhound");
        ob->move(ETO);
        ob->command("protect hound keeper");
        ob->command("protect hound keeper");
        if(!TO) return;
        x--;
    }
}
        

void kill_things() 
{
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;

    command("say today is the day that you die....");
    command("emote cackles insanely");
    command("kill "+TPQN);
    command("rush "+TPQN);
    return 1;    	            
}            
            

