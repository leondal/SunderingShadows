#include <std.h>
inherit WEAPONLESS;

object owner;

void create(){
        ::create();

        set_name("fluffy sheep");
        set_id(({"sheep","spirit","fey spirit","feyspirit"}));
        set("short","%^RESET%^%^CYAN%^Fluffy Sheep%^RESET%^");
        set("long","This is a sparkling sheep.  It has extra fluff."+
        "  The fluff is so fluffy it glows with a magical light.");
        set_race("sheep");
        set_overall_ac(0);
        set_attacks_num(1);
        set_alignment(6);
        set_mob_magic_resistance("high");
        set_heart_beat(3);

        }


void ownerz(object ob){
    owner = ob;
}
void heart_beat(){
    object friend;
    if(query_hp() < 0) die(); //for some reason just getting ko
    if(!owner) return;
  
	//heal if not at full hp  
    if(owner->query_hp() < owner->query_max_hp())
    {
       friend = owner;
    }
    else if (!present("companion",ETO) )return;
    else 
       friend = present("companion",ETO);
    
    if (!friend) return; // no friends

    tell_room(ETO,"%^BOLD%^%^CYAN%^Sheep fluffs "+friend->QCN+" with %^WHITE%^fluffy wool.",friend);
    friend->add_hp(random(6)+1);
    tell_object(friend,"%^BOLD%^%^CYAN%^Sheep fluff's you %^WHITE%^fluffy.");
    return;
}

void die(object ob){
	tell_room(ETO,"%^CYAN%^The sheep runs away!");
    TO->move("/d/shadowgate/void");
}



int isMagic() {return 3;}