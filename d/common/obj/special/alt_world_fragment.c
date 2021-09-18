#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit OBJECT;

string rewardType;
int beingrewarded;

void create()
{
    ::create();
    set_property("no animate", 1);
   
    set_id(({"alt world quest item", "fragment", "fragment of reality", "reality fragment"}));
    set_name("fragment of reality");
    set_short(CRAYON_D->color_string("Fragment of Reality", "dark red"));   
    
    set_long("%^BOLD%^%^RED%^This item continually glows and gives of an aura that makes you nauseous simply "+
    "looking at it. You are not exactly sure what it is, but you realize that it is powerful, almost beyond "+
    "comprehension. You think that it is somehow connected to the world that you are in, as if it's existence "+
    "parallels that of the world around you. Actually, as crazy as it seems, it is almost like this item "+
    "controls the existence of the world around you. You think that there is a tremendously perverse magic at play here "+
    "and shudder visibly as you look over the item. You have an overwhelming urge to touch it, to pick it up, to let "+
    "your warmth encompass it. Though you have no idea why or from where this urge comes from, it seems extremely "+
    "important to you.%^RESET%^");        
    
    set_weight(0);   
}

void set_reward_type(string str)
{
    rewardType = str;
    if(rewardType != "tokens" && rewardType != "gold" && rewardType != "mats") rewardType = "gold";
    return;
}

void reward_player(object player)
{
    int mod = 1, exp_reward, gold_reward, mat_reward, pweight, plev, token_reward;
    object ob;
    string ttype;
    if(!objectp(player)) return;
    //first quest of the day?
    if(time() > player->query("altquesttime"))
    {
        mod = 4;
        player->delete("altquesttime");
        player->set("altquesttime", time() + 86400);
    }
    plev = (int)player->query_base_character_level();
    exp_reward = exp_for_level(plev + 1) / 13;
    exp_reward *= mod;
    tell_object(player, "%^BOLD%^%^WHITE%^You feel yourself become more experienced! (You gain "+english_number(exp_reward)+ " experience points!)%^RESET%^");
    player->add_exp(exp_reward);
    if(objectp(EETO) && !stringp(rewardType)) rewardType = EETO->query("reward type");
    if(!stringp(rewardType) || rewardType == "gold")
    {
        gold_reward = (plev * (1000 + random(201)));
        gold_reward *= mod;
        player->add_money("gold", gold_reward);
        tell_object(player, "%^BOLD%^%^YELLOW%^Your pockets are suddenly filled with "+gold_reward+" additional gold coins!%^RESET%^");
    }
    else if(rewardType == "mats")
    {
        mat_reward = (plev * (40 + random(21)));
        mat_reward *= mod;
        tell_object(player, "%^BOLD%^%^CYAN%^Suddenly an additional "+mat_reward+" enchanting materials appear within your inventory!%^RESET%^");
        ob = new("/cmds/mortal/obj/enchanting_mats.c");
        pweight = ob->query_weight();
        ob->set_weight(0);
        ob->set_count(mat_reward);
        ob->move(player);
        ob->set_weight(pweight);
    }
    else if(rewardType == "tokens")
    {
        token_reward = (plev * (1 + random(2)));
        token_reward *= mod;
        if(plev < 20) ttype = "copper";
        else if(plev >= 20 && plev < 30) ttype = "silver";
        else ttype = "gold";
        tell_object(player, "%^BOLD%^%^BLACK%^Suddenly, "+token_reward+" "+ttype+" tokens appear in your inventory!%^RESET%^");
        while(token_reward > 0)
        {
            ob = new("/d/token_hunt/single_token.c");
            ob->set_token_type(ttype);
            pweight = ob->query_weight();
            ob->set_weight(0);
            ob->move(player);
            ob->set_weight(pweight);
            token_reward--;
            continue;
        }
        
    }
    if(EETO->query("created for player") == player->query_true_name())
    {
        while(objectp(ob = present("saidealtworldquestitem", player)))
        {
            ob->remove();
            continue;
        }
    }
    return;
}

void remove_me()
{
    if(!objectp(TO)) return;
    TO->remove();
    return;
}

void reward_players()
{
    object *pls;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    if(!userp(ETO)) return;
    pls = ({});
    pls = filter_array(all_living(EETO), "is_non_immortal_player", FILTERS_D);
    if(!sizeof(pls)) return; //if we get here, something is tremendously fucked :P
    
    for(x = 0;x < sizeof(pls);x++)
    {
        if(!objectp(pls[x])) continue;
        reward_player(pls[x]);
        continue;
    }
    if(stringp(EETO->query("alternative world"))) ALT_WORLD_D->clear_alt_world(EETO->query("alternative world"), 1);
    if(stringp(ETO->query("alternative world"))) ALT_WORLD_D->clear_alt_world(ETO->query("alternative world"), 1);
    call_out("remove_me", 0.10);
    return;    
}

void init()
{
    object ob;
    ::init();   
    if(!objectp(TO) || !objectp(ETO) || !objectp(EETO)) return;
    if(beingrewarded) return;
    if(!userp(ETO)) return;
    if(!stringp(ETO->query("alternative world")))
    {
        if(!objectp(EETO) || !stringp(EETO->query("alternative world")))
        {
            call_out("remove_me", 0.1);
            return;
        }
    }
    if(userp(ETO) && !beingrewarded)
    {
        foreach(object obj in ETO->query_attackers())
        {
            ETO->remove_attacker(obj);
            obj->remove_attacker(ETO);
        }
        beingrewarded = 1;
        reward_players();
        return;
    }    
}   