// basing on the storm rapier
#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/lrweapon/longbow.c";

#define B   +"%^RESET%^%^BOLD%^%^BLACK%^"+
#define L   +"%^RESET%^%^BOLD%^"+
#define R   +"%^RESET%^%^BOLD%^%^RED%^"+
#define S   +"%^RESET%^"+

#define CW  +""R"R"B"h"L"i"B"n"R"o "R"B"L"o"R"w"S""+
#define W   +""R"r"B"h"L"i"B"n"R"o "R"b"L"o"R"w"S""+
#define G   +""R"g"B"l"L"e"R"a"B"m"S""+
#define H   +""R"r"B"h"L"i"B"n"R"o"S""+


int charged;


string get_obvious_short()
{
    string str = "a bone recurve bow";
    str = CRAYON_D->color_string(str, "red and black");
    return str;    
}


string get_long()
{
    string str = "This bow has been crafted from some type of dark colored bone or horn.  The handle of the bow seems to be "
        "fashioned from multiple thick slices of hide layered atop each other to form rings.  The riser of the bow looks to be "
        "carved from a single piece of heavy bone and to either end of the riser are attached the upper and lower limbs.  The "
        "bow's limbs are made from what can only be the horn of a rhino.  The bow string is fashioned near the tip of the "
        "rhino horns and when it is drawn taut the points angle back nearly towards the wielder.  Arrows fired from this bow "
        "seem to take on a bone-like quality the instant they leave, and are prone to chipping off in the target and inflicting a "
        "painful wound.";    
    str = CRAYON_D->color_string(str, "red and black");    
    return str;
}


void create() 
{
    ::create();

    set_id(({ "bow","longbow","long bow","rhino","rhino bow" }));
    set_name(""CW"");
    set_short(""CW"");
    set_obvious_short(get_obvious_short());
    set_long(get_long());    
    set_lore("These bows are said to be crafted by the natives of a prarie island in the ocean west of the Tsarvani Empire.  "
        "The bows were common in the distant past but in recent years they have become much more rare as contact with the "
        "natives who crafted them has been lost.");
    set_value(0);
    set_property("no curse",1);
    set_property("enchantment",2);
    set_lrhit((:TO,"hit_func":));
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_overallStatus(220);
    charged = 0;
    set_property("no disenchant",1);
}


int wield_func()
{
    tell_object(ETO, ""B"As you grip the bow,  you feel the spirit of the "H""S"");    
    tell_room(EETO, ""B""+ETO->QCN+"'s eyes "G" as "+ETO->QS+" grips the bow."S"",ETO);    
    return 1;
}


int unwield_func()
{
    if(charged)
    {  
        tell_object(ETO, ""B"You feel the spirit of the "H" fade from the bow as it leaves your hand."S"");
        tell_room(EETO, ""B""+ETO->QCN+" seems somehow disappointed as "+ETO->QS+" unwields the bow."S"",ETO);
        charged = 0;
    }
    return 1;
}


string color(string str)
{
    return CRAYON_D->color_string(str, "red and black");
}


int hit_func(object target) 
{
    object ob;
    if(!objectp(target)) { return roll_dice(1,6)+charged; }
    if(!objectp(ETO)) { return 0; }
    if(!living(ETO)) { return 0; }    
    if(random(1000) > 400) { return roll_dice(1,6)+charged; }   

    switch(random(15))
    {
    case 0..4:    
    
         tell_room(EETO, color("As "+ETO->QCN+"'s arrow hits "+target->QCN+", a fragment of the arrowhead snaps off in the wound!"),({ETO,target}));
         tell_object(ETO, color("As your arrow hits "+target->QCN+", you can see a fragment of the arrowhead snap off in the wound!"));
         tell_object(target, color("As "+ETO->QCN+"'s arrow hits you, a fragment of the arrowhead snaps off in the wound!"));         
         
         if(!objectp(target)) return roll_dice(1,6)+charged;
         ob = new("/d/token_hunt/obj/low/rhino_damage.c");
         ob->set_target(target);
         ob->move(target);
         return roll_dice(1,6)+charged;
         
    case 5..11:
    
        tell_room(EETO, color(""+ETO->QCN+" grabs two arrows at the same time and fires them at "+target->QCN+"!"),({target,ETO}));
        tell_object(ETO, color("You grab two arrows at the same time and fire them at "+target->QCN+"!"));
        tell_object(target, color(""+ETO->QCN+" grabs two arrows at the same time and fires them at you!"));
        
        ETO->execute_attack();
        return roll_dice(2,4)+charged;
        
    case 12..14:
    
        if (EETO->query_property("indoors") && !charged) 
        {
            tell_room(EETO, color(""+ETO->QCN+" turns "+ETO->QP+" bow horizontally and sends an arrow streaking towards "+target->QCN+"!"),({target,ETO}));
            tell_object(ETO, color("You turn your wrist so your bow is horizontally and send an arrow streaking towards "+target->QCN+"!"));
            tell_object(target, color(""+ETO->QCN+" turns "+ETO->QP+" bow horizontally and sends an arrow streaking towards you!"));
            
            return roll_dice(2,5)+charged;
        }
        else if (!EETO->query_property("indoors") && !charged) 
        {
            tell_room(EETO, color(""+ETO->QCN+"'s eyes gleam as "+ETO->QP+" bow seems to draw in energy from the open space around "+ETO->QO+"!"),ETO);
            tell_object(ETO, color("Your eyes gleam as your bow seems to draw in energy from the open space around you!"));
            
            charged++;
            if(charged > 4) { charged = 4; }
        }
        else
        {
            switch(random(2))
            {
            case 0:
                tell_room(EETO, color(""+ETO->QCN+" snarls as "+ETO->QS+" lets fly an arrow from "+ETO->QP+" bow directly at "+target->QCN+"'s head!"),({target,ETO}));
                tell_object(ETO, color("You snarl as you let fly an arrow from your bow directly at "+target->QCN+"'s head!"));
                tell_object(target, color(""+ETO->QCN+" snarls as "+ETO->QS+" lets fly an arrow from "+ETO->QP+" bow directly towards your head!"));
                
                return roll_dice(1,10)+charged;

            case 1:
                tell_room(EETO, color(""+ETO->QCN+" moves into perfect position and shoots "+target->QCN+" right through "+target->QP+" defenses!"),({target,ETO}));
                tell_object(ETO, color("You move into perfect position and shoot "+target->QCN+" right through "+target->QP+" defenses!"));
                tell_object(target, color(""+ETO->QCN+" moves into perfect position and shoots you right through your defenses!"));
                
                charged--;                
                return roll_dice(charged,10);
            }
            return 1;
        }
    }

}
