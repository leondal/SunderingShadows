#include <std.h>
#include <daemons.h>
#include <new_exp_table.h>

//#define DELAY 2 * 24 * 60 * 60
#define DELAY 60 * 60

int cmd_reward(string str)
{
    object target;

    if (!str) {
        tell_object(TP, "<reward TARGET> or <reward all>");
        return 1;
    }
    
    if(!userp(this_player()))
        return 0;

    if(this_player()->cooldown("reward"))
    {
	 // if (TP->query("last_reward") + DELAY > time()) {
        tell_object(TP, "%^BOLD%^%^RED%^You can't use reward yet! Use the 'cooldowns' command to see how long you need to wait.");
        //tell_object(TP, "%^BOLD%^%^RED%^Delay timer wil expire at:%^RESET%^ " + ctime(TP->query("last_reward") + DELAY) + "UTC");
        return 1;
	}

 	if (str == "all"){
       object *livings;
       int i,j, expall, thelevels;
	   //int thelevel = target->query_adjusted_character_level();
       livings = filter_array(all_living(ETP),"is_non_immortal_player",FILTERS_D);
       j= sizeof(livings);
       if(!sizeof(livings)) return;
       for(i=0;i<j;i++){
          target = livings[i];
          if(!objectp(target)) continue;
          if(!interactive(target)) continue;
		  if(target == this_player()) continue;
		thelevels = target->query_adjusted_character_level();
        expall = abs(EXP_NEEDED[thelevels + 1] - EXP_NEEDED[thelevels]) / 8;
        expall = WORLD_EVENTS_D->check_exp_events(expall, TO);
        target->set_property("ignore tax", 1);
        target->add_general_exp(target->query_classes()[0], expall);
        target->remove_property("ignore tax");
        tell_object(target, "%^CYAN%^%^BOLD%^You feel enlightened as your powers grow.");
	   }
	   tell_object(TP, "%^CYAN%^%^BOLD%^You have rewarded everybody present.");
	    TP->delete("last_reward");
        //TP->set("last_reward", time());
        this_player()->add_cooldown("reward", DELAY);
	   return 1;
	}

    if (!objectp(target = present(str, ENV(TP)))) {
        tell_object(TP, "That is not here!");
        return 1;
    }

    if (!userp(target) ||
        avatarp(target)) {
        tell_object(TP, "That is not a player!");
        return 1;
    }

    if (TP == target) {
        tell_object(TP, "You cannot reward yourself.");
        return 1;
    }

    if (target->query("no_reward")) {
        tell_object(TP, "That player wishes no rewards!");
        return 1;
    }



    {
        int expdelta;
        int thelevel = target->query_adjusted_character_level();
        // garrett thinks adjusted is right for here, since this is a scaling award.

        expdelta = abs(EXP_NEEDED[thelevel + 1] - EXP_NEEDED[thelevel]) / 8;
        expdelta = WORLD_EVENTS_D->check_exp_events(expdelta, TO);

        target->set_property("ignore tax", 1);
        target->add_general_exp(target->query_classes()[0], expdelta);
        target->remove_property("ignore tax");

        tell_object(TP, "%^CYAN%^%^BOLD%^You have rewarded " + target->QCN + " with some experience.");
        tell_object(target, "%^CYAN%^%^BOLD%^You feel enlightened as your powers grow.");
        TP->delete("last_reward");
        //TP->set("last_reward", time());
        this_player()->add_cooldown("reward", DELAY);

    }

    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

reward - reward someone with exp

%^CYAN%^SYNOPSIS%^RESET%^

reward %^ORANGE%^%^ULINE%^TARGET%^RESET%^

reward %^ORANGE%^%^ULINE%^all%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will allow you to reward anyone or everyone in the group with 12.5% of exp towards their next level. The reason for doing so is left to your discretion. The player won't know who rewarded them, but will see the message about the reward. They also must be present in the room with you. You can do it only once per hour.

Player may opt out from receiving rewards with noreward setting in %^ORANGE%^<set>%^RESET%^ command. If they did so, your attempt to reward them won't count.

%^CYAN%^SEE ALSO%^RESET%^

set, score, who, chfn
"
        );
}
