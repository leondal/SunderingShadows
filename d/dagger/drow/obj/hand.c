// removing this from the game (at least for now) alongside efforts to mitigate PK-overwhelming items. N, 4/15
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"hand","bloody hand"}));
    set_name("%^RED%^Bloody hand");
    set_short("%^RED%^Bloody hand%^RESET%^");
    set_long("%^RED%^This is a disgusting bloody hand. It contains magical "
      "properties which involve ancient voodoo evils. The hand can be used "
      "to caress <victim> to inflict them with an ancient voodoo disease. "
      "Your not sure what this disease is but know it must be used with "
      "extreme caution.%^RESET%^");
    set_lore("%^BOLD%^This hand was rumored to belong to a drow lich who's "
        "specialty in life was spreading diseases among her enemies.  "
        "Later in undeath, a noble matron of a drow house asked the lich for "
        "assistance.  The lich broke off her own hand and gave to the drow, "
        "along with instructions to create many more that she could use to spread "
        "a horrible plague among her enemies.  The lich however, was already in "
        "league with the matron's enemies and when she created many of the hands "
        "to spread among her enemies, they overwhelmed her.  The hands crawled with "
        "a mind of their own and infected the one who would wield them!  Ever since "
        "then the drow are careful to carry only one such hand at a time so that "
        "their combined magic does not overtake and destroy them.");
    set_property("lore difficulty",20);
    set_value(105);
    set_weight(1);
}

//void save_me(string file) { return 1; }

// do nasty things to them if they have more than one bloody hand when a reset rolls around
void reset()
{   
    object hand,sack,*hands=({}),*inv,*deep_inv,player;
    int i,j;

    ::reset();

    if(random(3)) { return; }

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    if(interactive(ETO))
    {
        player = ETO;
        inv = all_inventory(ETO);
    }
    else if(objectp(EETO))
    {
        if(interactive(EETO))
        {
            player = EETO;
            inv = all_inventory(EETO);
        }
    }

    if(!objectp(player)) { return; }

    for(i=0;i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }
        if(inv[i]->id("bloody hand")) 
        {
            hands += ({ inv[i] });
            if(!hand) { hand = inv[i]; }
        }
        if(inv[i]->is_container())
        {
            deep_inv = all_inventory(inv[i]);
            if(sizeof(deep_inv))
            {
                for(j=0;j<sizeof(deep_inv);j++)
                {
                    if(!objectp(deep_inv[j])) { continue; }
                    if(deep_inv[j]->id("bloody hand"))
                    {
                        hands += ({ deep_inv[j] });
                        if(!hand) { hand = deep_inv[j]; }
                    }
                }
            }
        }
    }
    if(!sizeof(hands) || sizeof(hands) == 1) { return; }

    for(i=0;i<sizeof(hands);i++)
    {
        if(!objectp(hands[i])) { continue; }
        if(environment(hands[i]) != player)
        {
            hands[i]->set_weight(0);
            hands[i]->move(player);
        }
        tell_object(player,"%^RED%^Bloody hands start crawling all over you, trying to escape!%^RESET%^");
        tell_object(player,"%^BOLD%^%^GREEN%^Their diseased fingers brush against your skin, making you ill!");
        tell_room(environment(player),"%^RED%^Bloody hands start crawling all over "+player->QCN+", attacking "+player->QO+"!%^RESET%^",player);
        player->force_me("caress "+player->query_true_name()+"");
    }
    return;
}

void init()
{
    ::init();
    add_action("caress_func","caress");
}

int caress_func(string str) {
    object ob;
    if(!str) return notify_fail(
	  "You failed to select a target for the hand.\n"
	);
    tell_object(TP,"You reach out with the hand, and it crumbles to dust!");
    TO->remove();
    return 1;
// removing this item for current rebalancing of PK-overwhelming items. N, 4/15.

    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(!(ob = present(str,environment(TP)))) return notify_fail (
	  "Not a valid target.\n"
	);
    if((int)ob->query_highest_level() < 5) return notify_fail("That's just WRONG!!\n");
    tell_room(ETP,
      "%^RED%^%^BOLD%^"+TPQCN+" begins to caress "
      +ob->query_cap_name()+"'s skin with a "
      "bloody hand!%^RESET%^"
      ,({TP,ob}));
    tell_object(TP,
      "%^BOLD%^%^RED%^You begin to caress "+ob->query_cap_name()+
      "'s skin with the bloody hand!%^RESET%^"
    );
    tell_object(ob,
      "%^RED%^%^BOLD%^"+TPQCN+" begins to caress your skin with "
      "a bloody hand!%^RESET%^"
    );
    new("/d/dagger/drow/obj/vomit.c")->move(ob);	
    TP->kill_ob(ob,1);
    TO->remove();
    return 1;
}
