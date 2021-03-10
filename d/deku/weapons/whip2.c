#include <std.h>
inherit "/d/common/obj/weapon/scourge.c";
int num;
object *SNAKES;

void create() 
{
    ::create();
    set_id(({ "whip", "serpent whip", "snake head whip"}));
    set_name("whip");
    set_obvious_short("snake head whip");
    set_short("%^BOLD%^%^GREEN%^S%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^rp"+
    "%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^nt wh%^RESET%^%^GREEN%^i%^BOLD%^p%^RESET%^");
    
    set_long("%^BOLD%^%^GREEN%^The handle of this strange whip is composed of a "+
    "%^RESET%^%^ORANGE%^dark leather%^BOLD%^%^GREEN%^ that has been wrapped with a "+
    "%^RESET%^%^WHITE%^dingy%^BOLD%^%^GREEN%^ cloth several layers thick. The handle "+
    "is connected to the thong of the whip by a piece of %^RESET%^%^RED%^"+
    "dull red%^BOLD%^%^GREEN%^ metal that has several strange symbols carved into "+
    "its surface. The thong of the whip starts out normal enough, appearing as "+
    "several strands of a similar %^RESET%^%^ORANGE%^dark leather%^BOLD%^%^GREEN%^ "+
    "but as it extends closer to the end of the whip it changes. The thong slowly "+
    "becomes %^RESET%^%^GREEN%^scaly%^BOLD%^%^GREEN%^ as it splits into "+
    "five strands. At the end of each strand is a %^BOLD%^%^RED%^hissing"+
    "%^BOLD%^%^GREEN%^ snake head. Each head seems locked in an eternal "+
    "struggle to free itself from the thong.%^RESET%^");
        
    set_property("lore difficult", 20);
   
    set_lore("%^BOLD%^%^GREEN%^These whips were once used by a very strange "+
    "sect of a cult that has remained hidden on the island of Deku for ages. It is "+
    "said that the cult was locked in a struggle against Aorus Devar for control of "+
    "the island. Some rumors suggest that these whips were used as a means of "+
    "extracting information. However, who knows how truthful such rumors are. "+
    "What is known is that the snakes are kept alive on the whips by some means of "+
    "magic and are kept subdued when it is not being used. Some say that the "+
    "whip is sometimes capable of producing another living snake, that follows the "+
    "wielder, others say that the snakes are quite poisonous and that some "+
    "unfortunate victims find this out the hard way.%^RESET%^");
    
    set_value(3000);
    num = 0;
    
    set_property("enchantment",3);
    set_wield((:TO,"wield_me":));
    set_unwield((:TO, "unwield_me":));
	set_hit((:TO,"weapon_hit":));
}

void clear_snakes()
{
    int x;
    object snake, where;
    if(!pointerp(SNAKES)) return;
    for(x = 0;x < sizeof(SNAKES);x++)
    {
        if(!objectp(SNAKES[x])) continue;
        snake = SNAKES[x];
        where = environment(snake);
        if(objectp(where))
        {
            tell_room(where, snake->QCN+"%^BOLD%^%^BLACK%^ suddenly turns to "+
            "ASH and blows away!%^RESET%^");
        }
        snake->remove();
        continue;
    }
    SNAKES = ({});
    return;        
}

void remove()
{
    clear_snakes();
    return ::remove();
}

varargs int check_snakes(int amt)
{
    int x, chooser;
    object snake, where, *tmp, mon;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!pointerp(SNAKES)) SNAKES = ({});
    tmp = ({});
    for(x = 0;x < sizeof(SNAKES);x++)
    {
        if(!objectp(SNAKES[x]))
        {
            tmp += ({SNAKES[x]});
            continue;
        }
        snake = SNAKES[x];
        where = environment(snake);
        if(!objectp(where))
        {
            tmp += ({snake});
            continue;
        }
        if(where != EETO)
        {
            tell_room(where, snake->QCN+"%^BOLD%^%^BLACK%^ suddenly turns to "+
            "ASH and blows away!%^RESET%^");
            tmp += ({snake});
            snake->remove();
        }
        continue;
    }
    SNAKES -= tmp;
    if(sizeof(SNAKES) < 5 && !amt) return 1;
    if(sizeof(SNAKES) >= 5) return 0;
    while(amt--)
    {
        chooser = random(100) + (int)ETO->query_base_character_level();
        switch (chooser) 
        {
        case 0..70:
            mon = new("/d/magic/mon/gen_snake");
            break;
        case 71..75:
            mon = new("/d/magic/mon/cottonmouth");
            break;
        case 76..82:
            mon = new("/d/magic/mon/copperhead");
            break;
        case 83..87:
            mon = new("/d/magic/mon/rattlesnake");
            break;
        case 88..91:
            mon = new("/d/magic/mon/boa");
            break;
        case 92..97:
            mon = new("/d/magic/mon/python");
            break;
        case 98..101:
            mon = new("/d/magic/mon/cobra");
            break;
        case 102..106:
            mon = new("/d/magic/mon/kcobra");
            break;
        case 107..110:
            mon = new("/d/magic/mon/grattlesnake");
            break;
        case 111..114:
            mon = new("/d/magic/mon/gboa");
            break;
        case 115..117:
            mon = new("/d/magic/mon/gpython");
            break;
        case 118:
            mon = new("/d/magic/mon/boalisk");
            break;
        default:
            mon = new("/d/magic/mon/amphisbaena");
            break;
        }
        if(!objectp(mon)) { continue; }
        mon->set("aggressive", 1);
        mon->remove_property("swarm");
        mon->set_property("minion", ETO);
        mon->move(EETO);
        if(!objectp(mon)) { continue; }
        ETO->add_follower(mon);
        ETO->add_protector(mon);
        SNAKES += ({mon});
        continue;
    }
    return 1;        
}

int unwield_me()
{
    clear_snakes();
    tell_object(ETO, "%^BOLD%^%^GREEN%^The snakes suddenly calm, squirming about with less "+
    "fever.%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^GREEN%^The snakes on the end of "+ETOQCN+"%^BOLD%^%^GREEN%^"+
    "'s whip suddenly calm, squirming about with less fever.%^RESET%^", ETO);
    return 1;
}

int wield_me() 
{
    if(ETO->query_highest_level() < 20) 
    {
        tell_object(ETO,"%^RED%^The magic of this whip is beyond "+
        "you!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^GREEN%^You grip the whip and the snakes "+
    "become enraged!%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^GREEN%^The snakes on the end of "+ETOQCN+
    "%^BOLD%^%^GREEN%^'s whip become enraged!%^RESET%^", ETO);
    return 1;
}   

int weapon_hit(object targ) 
{
    int snakes;
    string tlim, num;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(5)) return 0;
    if(!check_snakes()) snakes = 4;
    else snakes = 10;
    switch(random(snakes))
    {
        case 0..4: case 7..9:
            snakes = roll_dice(1,4) + 1;
            num = consolidate_number(snakes);
            tlim = targ->return_target_limb();
            tell_object(ETO, "%^BOLD%^%^GREEN%^You %^BLACK%^CRACK%^BOLD%^%^GREEN%^ your "+
            "whip into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+tlim+" and "+num+" of "+
            "the snake heads bite viciously into "+targ->QO+"!%^RESET%^");
            
            tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^ CRACKS%^BOLD%^%^GREEN%^ "+
            ETO->QP+" whip into your "+tlim+" and "+num+" of the snake heads bite "+
            "viciously into you!%^RESET%^");            
    
            tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ CRACKS%^BOLD%^%^GREEN%^ "+
            ETO->QP+" whip into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+tlim+" and "+
            num+" of the snake heads bite viciously into "+targ->QO+"!%^RESET%^", ({ETO, targ}));
            
            targ->cause_typed_damage(targ, tlim, roll_dice(snakes, 3), "piercing");
            return 0;
            break;
        case 5..6:
            tell_object(ETO, "%^BOLD%^%^GREEN%^As you %^BOLD%^%^RED%^CRACK%^BOLD%^%^GREEN%^ "+
            "your whip against "+targ->QCN+"%^BOLD%^%^GREEN%^ you watch in amazement as "+
            "an entire snake flies from the whip!%^RESET%^");
            
            tell_object(targ, "%^BOLD%^%^GREEN%^As "+ETOQCN+"%^BOLD%^%^RED%^ CRACKS "+
            "%^BOLD%^%^GREEN%^you with "+ETO->QP+" whip an entire snake flies from it and "+
            "attacks!%^RESET%^");
            
            tell_object(targ, "%^BOLD%^%^GREEN%^As "+ETOQCN+"%^BOLD%^%^RED%^ CRACKS "+
            targ->QCN+"%^BOLD%^%^GREEN%^ with "+ETO->QP+" whip an entire snake flies from it and "+
            "attacks!%^RESET%^", ({ETO, targ}));
            check_snakes(1);            
            return 0;
            break;            
    }
    return 0;
}

/* I've taken this code out as of December 2016 and the Mausoleum update - Saide. 
void init() {
  ::init();
  add_action("crack_it","crack");
}

int crack_it(string str) {
  string tplayer;
  object targ;
  int need, tac, tlevel, roll;
  if(!str) {
    tell_room(ETP, "%^GREEN%^"+TPQCN+" whips the whip around creating a large CRACK!",TP);
    tell_object(TP,"%^GREEN%^You whip the whip around creating a large CRACK!");
    return 1;
  }
  targ = present(str, environment(this_player()));
    tplayer = ETO->QCN;
   if(!query_wielded()) {
    write("You must first have the whip wielded before you can use it!");
    return 1;
  }
  if(!targ) {
      tell_room(ETP, "%^GREEN%^"+tplayer+" does a wonderful display with the whip, making a loud CRACK!",TP);
    tell_object(TP,"%^GREEN%^You perform a wonderful display with the whip, making a loud CRACK!");
    return 1;
  }
  if(member_array(this_player(), targ->query_attackers()) == -1) {
    write("You can only target someone if you are already in battle!");
    return 1;
  }
  if(num == 1) {
    tell_object(this_player(), "%^GREEN%^You are recovering from your last attack with this whip!");
    return 1;
  }
   tlevel = ETO->query_level();
  roll = roll_dice(1,20);
   need = "/daemon/bonus_d.c"->thaco(tlevel, ETO->query_class());
  tac = targ->query_ac();
  if(!((roll >= (need - tac)) || (roll == 20))) {
    tell_room(environment(targ), "%^RED%^"+tplayer+" cracks the whip upon "+targ->QCN+" but does no damage!",({targ,ETO}));
    tell_object(ETO,"%^RED%^You crack the whip upon "+targ->QCN+" but do no damage!");
    tell_object(targ,"%^RED%^"+tplayer+" cracks the whip upon you but does no damage!");
    return 1;
  }
    tell_room(environment(targ), "%^GREEN%^"+tplayer+" cracks the whip upon "+targ->QCN+"'s chest inflicting some damage!",({ETO,targ}));
    tell_object(ETO,"%^GREEN%^You crack the whip upon "+targ->QCN+"'s chest inflicting some damage!");
    tell_object(targ,"%^GREEN%^"+tplayer+" cracks the whip upon your chest inflicting some damage!");
  targ->do_damage("torso", roll_dice(2,6));
  num = 1;
  call_out("next_hit",40);
  return 1;
}

void next_hit() {
  if(!objectp(TO))
	return;
  num = 0;
  tell_object(ETO, "%^GREEN%^The whip pulsates within your hand, waiting for the next strike.");
//  bug fix above, was - tell_object(this_player(), "%^GREEN%^The whip pulsates within your hand, waiting for the next strike.");
}
*/

