#include <std.h>
#include "../gantioch.h"

inherit MONSTER;

string MYTYPE,MYSTYLE,MYHAIR,MYFACE,MYEYE,MYCRYSTAL,MYPRIEST,MYCLASS,MYCLASS_TWO,MYGENDER,MONSTER_LEVEL;
string *ABILITIES=({}),EXIT;
object *ENEMIES=({});
int SPLIT,MINIONS;


create() {
   ::create();
   set("aggressive",0);
   set_name("gnollguard");
   set_level(20);
   set_alignment(1);
   set_languages( ({ "common","elven" }) );
   command("speak common");
   command("pose standing guard in front of the portcullis");
   set_property("swarm",0);
   set_id( ({"gnoll","guard"}) );
   set_short("%^RESET%^A %^BOLD%^%^BLACK%^dark-furred %^RESET%^gnoll");
   set_long("%^RESET%^%^ORANGE%^This very large and dangerous gnoll seems to be"+
		" standing guard at the portcullis. Though you approach he does not budge"+
        " merely standing near the gate, %^BOLD%^%^RED%^growling %^RESET%^%^ORANGE%^in"+
        " your direction.");
   set_race("gnoll");
   set_emotes(3,({
		"The gnoll growls loudly in your direction.",
		"The gnoll shifts its weight, looking about.",
		"The gnoll scratches its ear slightly with its weapon.",
  }),0);set_hd(20,10);
   add_money("gold",random(100));
   set_body_type("human");
   set_size( 3 );
   set_property("no attack", 1);
   set_hp(240);
   set_max_hp(243);
   set_exp(400);
}

string query_monster_level()
{
    if(MONSTER_LEVEL != "high" && MONSTER_LEVEL != "mid" && MONSTER_LEVEL != "low")
    {
        MONSTER_LEVEL = "high";
    }
    return MONSTER_LEVEL;
}

int valid_level(object target)
{
    if(!objectp(TO)) { return 1; }
    if(!objectp(target)) { return 1; }
    if(!interactive(target)) { return 1; }

    switch(MONSTER_LEVEL)
    {
    case "high":
        if((int)target->query_level() > 30) { return 2; }
        break;
    case "mid":
        if((int)target->query_level() > 20) { return 2; }
        if((int)target->query_level() > 30) { return 3; }
        break;
    case "low":
        if((int)target->query_level() > 10) { return 2; }
        if((int)target->query_level() > 20) { return 3; }
        break;
    }
    return 1;
}


void level_reaction(int num,object target)
{
    object room, shape;
    string mrace;
    if(!objectp(TO)) { return; }
    if(!objectp(target)) { return; }
    if(!objectp(room=environment(target))) { return; }
    if(ETO != room) { return; }

    switch(num)
    {
    case 2:
        mrace = target->query_race();
        if(objectp(shape = target->query_property("shapeshifted"))) mrace = (string)shape->query_shape_race();
        TO->force_me("say You aren't worth my time "+mrace+".");
        TO->force_me("chuckle");
        TO->force_me("say But here's a little something to remember me by.");
        tell_room(room,""+TO->query_short()+" pulls a strange dart from "
            "a fold in "+TO->QP+" clothes and throws it at "+target->QCN+"!",target);
        tell_room(room,"%^RED%^The dart slams into "+target->QCN+" and "
            ""+target->QS+" instantly doubles over in pain!",target);
        tell_object(target,""+TO->query_short()+" pulls a strange dart from "
            "a fold in "+TO->QP+" clothes and quickly throws it at you!");
        tell_object(target,"%^RED%^You try to dodge out of the way but the "
            "throw was perfect and the dart slams into you!");
        tell_object(target,"%^RED%^A wave of posion rips through your body causing "
            "you to convulse in unbearable pain!");
        target->set_paralyzed(roll_dice(1,(int)TO->query_level()),"%^RED%^You are thrasing "
            "on the ground in agony!%^RESET%^");
        target->set_hp(roll_dice(2,12));
        tell_room(room,""+TO->query_short()+" produces a small glass sphere from "
            "a fold in "+TO->QP+" clothes and quickly smashes it!");
        new("/d/tharis/barrow/obj/sphere")->move(TO);
        TO->force_me("smash sphere");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    case 3:
        TO->force_me("say Woah, I don't want any part of this, I'm outta here.");
        tell_room(room,""+TO->query_short()+" produces a small glass sphere from "
            "a fold in "+TO->QP+" clothes and quickly smashes it!");
        new("/d/tharis/barrow/obj/sphere")->move(TO);
        TO->force_me("smash sphere");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }
    return;
}

// 1 just right, 2 too low, 3 too high
void level_test()
{
    object *attackers =({});
    int i,result;

    attackers = TO->query_attackers();
    if(!objectp(TO)) { return; }
    if(sizeof(attackers))
    {
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            result = valid_level(attackers[i]);
            if(result != 1)
            {
                level_reaction(result,attackers[i]);
                return;
            }
        }
    }
}
