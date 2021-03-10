#include <std.h>
#include "../arctic.h"
inherit CREATURE;

int i = 0;
int FLAG = 0;

void create() 
{        
    ::create();
    set_name("Wolf");
    set_id(({"wolf", "arcticmon"}));
    set_race("wolf");
    set_body_type("quadruped");
    set_gender((random(2)?"male":"female"));
    set_size(2);
    set_short("wolf");
    set_long("%^BOLD%^The coarse coat of the wolf is a "
             "pure white to help it blend in with its "
             "surroundings.  Its rounded amber eyes "
             "quietly survey the surroundings and its "
             "long tail flicks occasionally.  The wolf "
             "has a strong jaw and large feet to help "
             "it move on the snowy terrain.%^RESET%^");
    set_hd(20,1);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_hp((random(100)+100));
    set_exp(500);
    set_property("swarm", 1);
    set_overall_ac(1);
    set_stats("strength",14);
    set_stats("dexterity",17);
    set_stats("intelligence",2);
    set_stats("wisdom",9);
    set_stats("constitution",14);
    set_stats("charisma",11);
    set_attacks_num(1);
    set_damage(1,4);
    set_base_damage_type("piercing");
    add_limb("teeth", "head", 0, 0, 0);
    set_attack_limbs(({"teeth"}));
    set("aggressive", 12);
    set_funcs( ({"howl"}) );
    set_func_chance(7);
    set_speed(20);
    nogo("NOGO1");

}

void howl()
{
    tell_room(ETO, "%^BOLD%^The wolf throws "
    "its head back and howls!%^RESET%^");
    call_out("send_help",10,TO);
    return;
}

void send_help()
{
    if(!objectp(TO)) return;
    if(FLAG == 1) return;

    switch(random(5))
    {
    case 0..2:
        tell_room(ETO, "%^BOLD%^Howls echo back "
        "from all around the mountains!%^RESET%^");
        break;
    case 3:
        tell_room(ETO, "%^RED%^Several wolves answer "
        "the howl and attack!%^RESET%^");
        for(i=0;i<(random(2)+1);i++)
        {
            new(MON"wolf")->move(ETO);
            if(i > 10) {tell_room(ETO,"loop error howl "
            "in "+MON+"wolf.c"); break;} 
        }
        break;
    case 4:
        tell_room(ETO, "%^RED%^Several wolves answer "
        "the howl and attack!%^RESET%^");
        for(i=0;i<(random(5)+1);i++)
        {
            new(MON"wolf")->move(ETO);
            if(i > 10) {tell_room(ETO,"loop error howl "
            "in "+MON+"wolf.c"); break;}
        }
        break;
    }

    FLAG = 1;
}