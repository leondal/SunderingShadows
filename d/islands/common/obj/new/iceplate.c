#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/armour/bronze.c";

#define WAIT_TIME 14400
int used_time;


void create()
{
    ::create();
    set_name("Ice Plate");
    set_short("%^BOLD%^%^WHITE%^Iced %^BOLD%^%^CYAN%^Bear%^RESET%^");
    
    set_obvious_short("%^BOLD%^%^WHITE%^Crystal-like breastplate%^RESET%^");
    
    set_id(({"iced bear", "plate", "breastplate"}));
    
    set_long("%^BOLD%^%^WHITE%^This breastplate is made from pure ice, but is as solid as steel. The stability of the "
        "ice is owed to some enchantment, no doubt. The plates of ice are linked together by a clear mesh, but the ice "
        "is thick enough to hide the apperance of the wearer. Every piece of the armor is woven together tightly and "
        "even the thinnest of weapons would have a hard time finding a soft spot.%^RESET%^");

    set_lore("Legend has it that breastplate similar to this was worn by nothern tempusians in times of war. Through "
        "time, any specific ties to such armor are lost. However, through myth of the legend there are rumors that "
        "the one who commands such fine armor can %^YELLOW%^summon %^RESET%^mystical armor with only a thought, but "
        "such things are only myth.");
        
    set_value(164500);
    
    set_wear((:TO,"wear_func":));
    
    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("perception",6);
    set_item_bonus("damage resistance",10);
    
    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_func() 
{
    return 1;
}


void init()
{
    ::init();
    
    if(living(ETO)) 
    {
        add_action("stone","summon");
    }
    
    if(stringp(owner)) return;
    
    if(interactive(TP) && TP == ETO) {owner = TPQN; }
}


void failure() 
{
    tell_object(ETO,"The plate does not respond.",EETO);
    return 1;
}


int stone(string str)
{    
    if (ETO->query_bound() || EETO->query_unconscious() || EETO->query_paralyzed()) 
    {
        ETO->send_paralyzed_message("info",ETO);
    }

    if(!str) 
    {
        tell_object(ETO,"What?");
        return 1;
    }
    
    if(!(query_worn()))
    {
        failure();
        return 1;
    }
    
    if(WAIT_TIME > (time() - used_time)) 
    {
        failure();
        return 1;
    }
    
    if(str == "armor")
    {
        used_time = time();
        ETO->force_me("emote %^BOLD%^%^CYAN%^slams a fist into the middle of breastplate!%^RESET%^");
        new("/cmds/spells/s/_stoneskin")->use_spell(ETO,ETO,50,100,"mage");
        return 1;
    }
}


void set_used_time(int x) { used_time = x; }


int query_size()
{
    if(living(ETO)) { return ETO->query_size(); }
    else { return 2; }
}


int is_metal() { return 0; }  // made from ice
