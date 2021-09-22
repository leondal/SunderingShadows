/*
  quest_item.c
  
  Similar to the alt reality quest item, this is what the player
  is seeking out when they enter the daily demiplane.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit OBJECT;

void create()
{
    ::create();
    
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
    
    set_property("no animate", 1);
    set_weight(0);
}

void init()
{
    object holder;
    
    ::init();
    
    holder = environment(this_object());
    
    if(!holder || !userp(holder))
        return;
    
    reward_player(holder);
}

void reward_player(object who)
{
    object compiler;
    int money, exp;
    
    if(!userp(who))
    {
        ::remove();
        return;
    }
    
    compiler = who->query_property("demiplane compiler");
    
    if(!objectp(compiler))
    {
        tell_object(who, "There is a problem with the demiplane. Performing emergency teleport!");
        who->move_player("/d/common/obj/daily/entrance");
        ::remove();
        return;
    }
    
    tell_object(who, "You pick up the fragment and you feel the demiplane dissolve arround you.");
    compiler->destroy_plane();
    tell_object(who, "You are rewarded for your efforts!");
    money = who->query_level() * (500 + random(101));
    exp = exp_for_level(who->query_level() + 1) / 13;
    tell_object(who, sprintf("You are awarded %d XP and %d gold!", exp, money));
    
    ::remove();
}
    
    
    
    
    