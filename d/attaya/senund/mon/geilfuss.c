#include <std.h>
#include <daemons.h>
#include "../areadefs.h"

inherit MONSTER;
void create() {
    object ob;
    ::create();
    set_name("geilfuss");
    set_id(({"geilfuss"}));
    set_short("%^BOLD%^%^GREEN%^Geilfuss%^RESET%^");
    set_long(
@BRUENOR
%^RED%^Although shorter then most humans Geilfuss still manages to be rather
%^RED%^intimidating. He wields horrible screaming daggers in each hand
%^RED%^and a dark cloak keeps him hidden in the shadows. He has a grin on
%^RED%^his face that will not go away and he walks with a confidence that
%^RED%^only an idiot or an experienced assassin would have.
BRUENOR
);
    set_race("human");
    set_moving(1);

    set_speed(70);
    set_gender("male");
    set_hd(35,10);
    set_class("thief");
    add_search_path("/cmds/thief");
    add_search_path("/cmds/assassin");
    set_size(2);
    set_mlevel("thief",28);
    set_overall_ac(-18);
    set_property("full attacks", 1);
    set_max_hp(900);
    set_hp(900);
    set_exp(50000);
    set("aggressive","aggfunc");
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("no bump",1);
    set_stats("strength",19);
    set_stats("dexterity",18);
    set_stats("constitution",14);
    set_stats("intelligence",16);
    set_stats("wisdom",12);
    set_stats("charisma",10);
    set_thief_skill("hide in shadows",95);
    set_thief_skill("move silently",95);
    set_mob_magic_resistance("average");
    set_funcs(({"special","special2"}));
    set_func_chance(40);
    set_alignment(9);

        ob = new("/d/attaya/obj/screamer.c");
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield dagger in left hand");
        ob = new("/d/attaya/obj/screamer.c");
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield dagger in right hand");
        ob = new(OBJ+"magebane.c");
        ob->move(TO);
}



int kill_ob(object victim, int which)
{
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold)
    {
        if(interactive(victim))
        {
          TO->force_me("say %^BOLD%^%^GREEN%^Should watch what caves "+
                       "you wander into..");
          if(!random(2))
          {

          command("scramble");
          TO->force_me("crit "+victim->query_name());
          }
        }
        }
   return hold;
}


void aggfunc()
{
        if((string)TPQN != "bruenor")
        {
        command("say %^BOLD%^%^GREEN%^That sword is Gambrills.");
        command("stab "+TPQN);
        }
}


void special(object targ)
{
    string name;
    int count;
    name = targ->QCN;
        tell_object(targ,
            "%^BOLD%^%^RED%^Geifluss grins slightly and begins "+
            "stabbing at you incessantly!%^RESET%^");
        tell_room(ETO,
                "%^BOLD%^%^RED%^Geilfuss grins slightly and "+
                "begins stabbing "+name+ " incessantly!%^RESET%^",targ);
    targ->do_damage("head",roll_dice(4,5));
    for(count = 0;count < 5;count++)
    {
        tell_object(targ, "%^RED%^STAB!");
        tell_room(ETO, "%^RED%^"+name+ " gets stabbed!", targ);
        targ->do_damage("head",roll_dice(4,5));
    }
  return 1;
}


void special2(object targ)
{
    string name;
    int count;
    name = targ->QCN;
        tell_object(targ,
            "%^MAGENTA%^Geifluss pulls a scroll from his cloak, "+
            "glances at you, and quickly reads it!%^RESET%^");
        tell_room(ETO,
            "%^MAGENTA%^Geilfuss pulls a scroll from his cloak"+
            "and quickly reads it!%^RESET%^",targ);
    targ->do_damage("head",roll_dice(4,5));
new("/cmds/spells/f/_fireball")->use_spell(TO,targ->query_name(),20,100,"mage");
  return 1;
}
