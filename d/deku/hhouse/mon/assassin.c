#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
object myMob;
int spawn_timer = 0;

varargs void pick_room(string file)
{
    int respawn_time = 0;
    string *tmp, *BADROOMS = ({"brr1.c", "brr2.c", "brr3.c"}), *rooms, room;
    object MyRoom;
    if(!objectp(TO)) return;
    SAVE_D->remove_array("hhouse_basement_assassin");
    SAVE_D->set_value("hhouse_basement_assassin", TO);
    if(spawn_timer <= 0 || !objectp(ETO)) 
    {
        if(!stringp(file)) 
        {
            rooms = get_dir(HHROOMS+"br*.c");
            rooms -= BADROOMS;
            room = rooms[random(sizeof(rooms))];
            room = HHROOMS + room;
        }
        else room = file;      
        
        if(!objectp(myMob)) 
        {
            if(myMob = new(HHMON+"spectral_spider"));
        }
        if(catch(MyRoom = find_object_or_load(room))) 
        {
            //tell_object(environment(previous_object()), "%^B_CYAN%^%^YELLOW%^ERROR: room for basement surprise FAILED to LOAD%^RESET%^");
            return;
        }    
        if(!objectp(MyRoom)) 
        {
            //tell_object(environment(previous_object()), "%^B_CYAN%^%^YELLOW%^ERROR: room for basement surprise FAILED to LOAD%^RESET%^");
            return;
        }    
        if(!sizeof(MyRoom->query_exits()) && !strlen(MyRoom->query_long()))
        {
            //tell_object(environment(previous_object()), "Room "+identify(MyRoom)+ " has no exits before TO is placed.");
        }        
        //move_object(TO, MyRoom);
        move_object(MyRoom);
        if(objectp(ETO)) 
        {
            myMob->move(ETO);
            myMob->set_property("minion", TO);
            if(!myMob->query_invis()) myMob->set_invis();
        }
        if(room != file) 
        {
            SAVE_D->remove_array("hhouse_basement_assassin_location");
            SAVE_D->set_value("hhouse_basement_assassin_location", room);
        }
        
        TO->add_follower(myMob);
        spawn_timer = (20*60);
        return;
    }
}

void create() 
{
    object ob;
    ::create();
    set_name("ardak");
    set_id(({"assassin", "ardak", "crazed assassin", "spider assassin"}));
    set_race("human");
    set_short("%^BOLD%^%^BLACK%^A%^BOLD%^%^GREEN%^r%^BOLD%^%^BLACK%^d%^BOLD%^%^GREEN%^"+
    "a%^BOLD%^%^BLACK%^k, The Insane%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This man looks ancient, his skin is wrinkled and "+
    "sagged with %^BOLD%^%^RED%^scars%^BOLD%^%^BLACK%^ covering %^BOLD%^%^RED%^scars"+
    "%^BOLD%^%^BLACK%^. His frame is quite thin with some slight muscle definition, but "+
    "mostly he walks stooped and carries himself slackly. His hair is long, upkept, and "+
    "matted with what looks to be spider webs. His face offers a constant look of "+
    "bitterness and his eyes radiate with a pure and intense hate. There is an "+
    "unmistakable air of mystery to this man. A fog of sorts seems to follow "+
    "him, making all of his actions appear hazy. You wonder for a moment if he "+
    "is actually real or just an illusion. Something tells you that whatever he "+
    "is, he is a danger.%^RESET%^");

    set_class("fighter");
    set_class("thief");
    set_guild_level("fighter", 32);
    set_guild_level("thief", 32);

    set_mlevel("fighter", 32);
    set_mlevel("thief", 32);
    set("aggressive",30);
    set_alignment(9);
    set_stats("strength",20);
    set_stats("intelligence",9);
    set_stats("wisdom",9);
    set_stats("dexterity",20);
    set_stats("charisma",8);
    set_stats("constitution",12);
    set_invis();
    set_gender("male");
    set_hp(3500 + random(450));
    set_new_exp(32, "boss");
    ob = new("/d/common/obj/weapon/shortsword");
    ob->set_property("enchantment", 5);
    ob->move(TO);
    command("wield sword");
    ob = new("/d/common/obj/weapon/shortsword");
    ob->set_property("enchantment", 5);
    ob->move(TO);

    command("wield sword");
    ob = new("/d/common/obj/armour/leather");
    ob->set_property("enchantment", 5);
    ob->move(TO);
    ob = new(HHOB+"greater_ring_of_elemental_resistance");
    ob->move(TO);
    command("wear band");
    command("wear leather");
    add_search_path("/cmds/thief");

    add_money("gold",5500 + random(2000));

    set_moving(1);
    set_speed(45);
    set_nogo(({FFROOMS+"iw20", BROOMS+"rr1", BROOMS+"rr2", BROOMS+"rr3"}));

    add_attack_bonus(5);
    set_funcs(({"sic_em", "gut_stab", "gut_stab", "throat_slit", "throat_slit", "gut_stab"}));

    set_func_chance(40);
    set_overall_ac(-25);

    add_search_path("/cmds/fighter");
    set_property("full attacks", 1);
    set_property("no tripped", 1);
	//place_me();
    spawn_timer = 0;
    set_monster_feats(({
        "parry",
        "scramble",
        "stab",
    }));
}

void gut_stab(object targ)
{
    int dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    dam = roll_dice(16,12);
    command("whisper "+targ->query_true_name() +" I'm gonna cut out your innards!");

    if(targ->reflex_save(35)) 
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You sense a sudden movement aimed at "+
        "your torso and move out of the way just in time!%^RESET%^");

        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ jumps back, moving out of the "+
        "way of an unseen attack!%^RESET%^", targ);
        return 1;
    }
    tell_object(targ, "%^BOLD%^%^RED%^You feel a sudden %^BOLD%^%^BLACK%^STABBING"+
    "%^BOLD%^%^RED%^ pain in your torso as an invisible blade sinks deep into it!%^RESET%^");
		
    tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ suddenly groans in pain and grabs "+
    targ->QP+" torso!%^RESET%^", targ);

    targ->cause_typed_damage(targ, 0, dam, "piercing");
    return 1;
}
 

void throat_slit(object targ)
{
    int dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    if(!random(25)) dam = roll_dice(6,50);
    else dam = roll_dice(10,10);
	
    command("whisper "+targ->query_true_name() +" I'm gonna saw off your head!");
	
    if(targ->reflex_save(35)) 
    {
        tell_object(targ, "%^BOLD%^%^RED%^You sense a sudden movement and "+
        "are able to move out of the way just in time to avoid an "+
        "attack on your %^BOLD%^%^WHITE%^throat%^BOLD%^%^RED%^!%^RESET%^");
        tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ moves quickly out of "+
        "the way, avoiding some unseen attack!%^RESET%^", targ);
        return 1;
    }

    tell_object(targ, "%^BOLD%^%^BLACK%^A sudden quick movement and "+
    "%^BOLD%^%^WHITE%^METAL%^BOLD%^%^BLACK%^ slices across your "+
    "throat, opening up a %^BOLD%^%^GREEN%^vicious wound%^BOLD%^%^BLACK%^"+
    " and leaving you gasping for breath and trying to recover!%^RESET%^");
		
    tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ suddenly grasps "+
    targ->QP+"%^BOLD%^%^RED%^ throat%^BOLD%^%^BLACK%^ and begins "+
    "gasping for breath, as a thin %^BOLD%^%^GREEN%^vicious"+
    " wound%^BOLD%^%^BLACK%^ appears across it!%^RESET%^", targ);

    targ->cause_typed_damage(targ, 0, dam, "piercing");
    targ->set_paralyzed(8, "%^BOLD%^%^RED%^You are gasping for breath and trying to recover!%^RESET%^");
    return 1;
}
		

void sic_em(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    command("speech croak angrily");
    command("say sic "+targ->QCN+" boy, want ya ripping 'em apart LIMB by LIMB!");
    if(objectp(myMob)) 
    {
        switch(random(8)) 
        {
            case 0..4:
                myMob->soul_theft(targ);
                break;
            case 5..7:
                myMob->spin(targ);
                break;
        }
    }
    else
    {
        command("say good fer nothing filthy beast!! Where'd ya RUN OFF TOO!!!?");
    }
    command("stab "+targ->query_true_name());
    return 1;
}

void init()
{
    ::init();
    if(!objectp(TO)) return;
    if(objectp(TP))
    {
        if(TP->query_true_invis()) return;
        if(!TP->is_player()) return;
        command("speak wizish");
        command("whisper "+TPQN+" tonight I'll dine on your %^BOLD%^%^RED%^S%^BOLD%^%^WHITE%^O%^BOLD%^"+
        "%^RED%^U%^BOLD%^%^WHITE%^L!%^RESET%^");
        sic_em(TP);
        return;
    }
}

void heart_beat() 
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(sizeof(TO->query_current_attackers()) < 1) 
    {
        spawn_timer -= 1;
        if(spawn_timer <= 0) pick_room();    
    }
    return;
}

void die(object ob)
{
    SAVE_D->remove_array("basement_assassin_died");
    SAVE_D->remove_array("hhouse_basement_assassin");
    SAVE_D->remove_array("hhouse_basement_assassin_location");
    SAVE_D->set_value("basement_assassin_died", time() + (60*15));
    ::die(ob);
}