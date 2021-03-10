#include <std.h>
#include "../keep.h"
inherit MONSTER;

int flag;
void attack(object targ);

void create()
{
    ::create();
    set_name("%^CYAN%^A human spectre%^RESET%^");
    set_id(({"human spectre","spectre","human"}));
    set_short("%^CYAN%^A human spectre%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This is the spectre of a fallen man.  Most of his features "+
    "are obscurred by a %^CYAN%^mysterious light%^BOLD%^%^WHITE%^, but it appears that "+
    "in life his body was consumed by %^RED%^fire%^BOLD%^%^WHITE%^.  His face, the only "+
    "completely visible feature, is littered with %^MAGENTA%^scars%^BOLD%^%^WHITE%^ of "+
    "varying sizes and patterns.  The orbs which are inset into his eyesockets are a very "+
    "intense %^BLUE%^azure%^BOLD%^%^WHITE%^.  Whatever fell this man managed to bind him "+
    "here, even in death he could not escape.%^RESET%^");
    set_body_type("human");
    set_gender("male");
    set_race("undead");
    set_hd(28,1);
    set_alignment(9);
    set_property("no bows",1);
    //set_property("no rush",1);
    set_property("no death",1);
    set_property("weapon resistance",1);
    set_mob_magic_resistance("average");
    //set_property("no stab",1);
    set_overall_ac(-14);
    set_hp(1700 + random(60));
    set_new_exp(25, "boss");
    set_funcs(({"attack"}));
    set_func_chance(100);
    add_money("gold",random(300));
    set_stats("strength",19);
    set_stats("intelligence",20);
    set_stats("wisdom",15);
    set_stats("constitution",19);
    set_stats("dexterity",18);
    set_stats("charisma",8);
    set("aggressive","aggression");
    set_property("full attacks",1);
    set_property("swarm",1);
    add_money("gold",random(500) + 500);
    set_max_level(25);
}

void init() 
{
    object *alive;
    int people, i;
    ::init();

    alive = all_living(ETO);
    alive -= ({TO});
    people = sizeof(alive);

    for(i = 0;i < people;i++) 
    {
        if(alive[i]->query_true_invis() != 0) {  continue; } 
        if(!interactive(alive[i])) { continue; }
        if(flag == 0) 
        {
            command("say you should not have come here, but alas, you may now join me!");
            command("block north");
            flag = 1;
        }
        if(!objectp(alive[i])) break;
        TO->add_attacker(alive[i]);
        TO->continue_attack();
        command("kill " + alive[i]->query_name());;
        alive[i]->add_attacker(TO);
        alive[i]->continue_attack();
    }
}

void reset() 
{
    ::reset();
    flag = 0;
}

void heart_beat() 
{
    object no_like;
    ::heart_beat();
	if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    
    if(no_like = present("snake", ETO) || no_like = present("kobold", ETO) || no_like = present("gnoll", ETO) ||
    no_like = present("hobgoblin", ETO) || no_like = present("goblin", ETO) ||
    no_like = present("bandit", ETO) || no_like = present("orc", ETO) ||
    no_like = present("bat", ETO) || no_like = present("rat", ETO) ||
    no_like = present("soldier", ETO) || no_like = present("centaur", ETO)) 
    {
    
        if(!interactive(no_like)) 
        {
            tell_room(ETO,"%^CYAN%^The spectre touches the "+no_like->query_name()+"%^CYAN%^ and "+
            "drains the life from it!%^RESET%^");
            TO->add_hp((int)no_like->query_hp() * 4);
            no_like->die();             
        }
    }
}

void attack(object targ) 
{
    int dam, x, par, which;
    string color;
    TO->set_property("magic",1);
    x = 2 + random(3);
    while(x--)
    {
        which = random(50);
        switch(which) 
        {
            case 0..15:
                color = "%^BOLD%^%^BLACK%^obsidian%^RESET%^";
                dam = roll_dice(8,10);
                break;
            case 16..25:
                color = "%^RED%^crimson%^RESET%^";
           		dam = roll_dice(8,12);
		        break;
            case 26..41:
                color = "%^BOLD%^%^BLUE%^blue%^RESET%^";
          		dam = roll_dice(8, 8);
                break;
            case 42..46:
                color = "%^BOLD%^%^WHITE%^pale white%^RESET%^";
                dam = roll_dice(10,10);
                par = 1;
                break;
            case 47..49:
                color = "%^BOLD%^%^GREEN%^green%^RESET%^";
				dam = roll_dice(5,20);            
                break;
        }
    }	

    TO->add_hp(dam);

    tell_room(ETO,"The spectre's hand glows a deep " + color + " as it touches " +targ->query_cap_name() + ".",targ);
    tell_object(targ,"The spectre's hand glows a deep " + color + " as it touches you!");
    if(targ->will_save(30)) 
    {
        dam = dam / 2;
    }   
	else
    {
        if(par)
        {
            targ->set_paralyzed(20,"%^CYAN%^You have been frozen by the cold touch "+
            "of the spectre!%^RESET%^");
        }
    }

    targ->cause_typed_damage(targ,"torso",dam,"negative energy");

    TO->remove_property("magic");
    return;
}
	

void die(object ob) 
{
	if(file_name(environment(TO)) == KEEPR+"spectre1") 
    {
        ETO->set_long("This %^BOLD%^%^BLACK%^marble%^RESET%^ chamber is small, only around eight "+
        "feet square.  The floor of the chamber is littered with the %^BOLD%^%^WHITE%^"+
        "bones%^RESET%^ of various creatures.  In the center of the chamber there is a rather "+
        "large %^BOLD%^%^WHITE%^hole%^RESET%^, obviously something was very forcefully ripped "+
        "from the floor.  The %^RED%^walls%^RESET%^ of this room are covered with %^RED%^"+
        "blood%^RESET%^, as if some type of horrific slaughter took place here and they bare "+
        "witness of it.  Inset directly into the center of the northern wall is a "+
        "massive %^BOLD%^%^BLACK%^marble door%^RESET%^.%^RESET%^");
        ETO->remove_item("spear");
        ETO->add_item("floor","%^BOLD%^%^BLACK%^The marble floor of this chamber is littered with "+
        "the %^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^ of various creatures.  There is a large "+
        "%^BOLD%^%^WHITE%^hole%^BOLD%^%^BLACK%^ directly in the center of the chamber.%^RESET%^");
        ETO->add_item("Floor","%^BOLD%^%^BLACK%^The marble floor of this chamber is littered with "+
        "the %^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^ of various creatures.  There is a large "+
        "%^BOLD%^%^WHITE%^hole%^BOLD%^%^BLACK%^ directly in the center of the chamber.%^RESET%^");
        ETO->add_item("hole","%^BOLD%^%^WHITE%^This hole is directly in the center of this chamber, "+
        "it looks almost like a large section of the %^BOLD%^%^BLACK%^marble%^BOLD%^%^WHITE%^ was "+
        "just ripped out.%^RESET%^");
        tell_room(ETO,"%^CYAN%^The spectre grabs the %^BOLD%^%^GREEN%^spear%^CYAN%^ and rips it "+
        "from the floor, hurling against the northern wall!%^RESET%^",TO);
        new(KEEPO + "impalerspear")->move(ETO);
    }
    ::die();
}
