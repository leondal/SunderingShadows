#include <std.h>
#include "area_info.h"
#include "../fways.h"
inherit CROOM;

object *entrapped;

void place_my_mobs()
{
    if(base_name(TO) != DMARSH && !random(2)) 
    {
        switch(random(10))
        {
            case 0..2:
                set_monsters(({MMPATH "greater_battle_briar",}), ({2 + random(3)})); 
                break;
            case 3..5:
                set_monsters(({MMPATH "demon_footman", MMPATH "spiked"}), ({1 + random(2), 1 + random(2)}));
                break;
            case 6..7:
                set_monsters(({MMPATH "demon_footman"}), ({2 + random(2)}));
                break;
            case 8..9:
                set_monsters(({MMPATH "sterror", MMPATH "spiked"}), ({1+random(2)+random(2), 2+random(2)}));
                break;
        }        
        set_repop(55);
    }
}



void create()
{
    place_my_mobs();
    ::create();
    set_name("within the ancient marsh");
    set_short("%^BOLD%^%^BLACK%^Within the Anc%^RESET%^%^GREEN%^ie%^BOLD%^%^BLACK%^nt "+
    "M%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^rsh%^RESET%^");
    set_property("indoors", 0);
    set_property("light", 1);
    set_terrain(MARSH);
    set_travel(FOOT_PATH);

    set_long("%^BOLD%^%^BLACK%^You are within the anc%^RESET%^%^GREEN%^ie%^BOLD%^%^BLACK%^nt m"+
    "%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^rsh. You instantly question the sanity of willingly coming "+
    "into such a place. The entire marsh is almost overrun with %^RESET%^%^RED%^treacherous thorns"+
    "%^BOLD%^%^BLACK%^,%^RESET%^%^GREEN%^ gn%^BOLD%^a%^RESET%^%^GREEN%^rled trees%^BOLD%^%^BLACK%^, "+
    "and %^RESET%^%^GREEN%^thick roots%^BOLD%^%^BLACK%^. All growing from a bed composed of "+
    "copious layers of a %^RESET%^%^GREEN%^foul "+
    "sl%^BOLD%^u%^RESET%^%^GREEN%^dge%^BOLD%^%^BLACK%^. The %^RESET%^"+
    "%^RED%^thorns%^BOLD%^%^BLACK%^ stand out in stark contrast to the rest of the foliage. They appear to not "+
    "only be living but actually thriving as they wind tighty around the trees and the roots sucking life from "+
    "them with impunity. The %^RESET%^%^GREEN%^trees and roots%^BOLD%^%^BLACK%^ jut up "+
    "from beneath the sludge at odd angles. You watch as pieces of them break off and fall into "+
    "the sludge with audible '%^BOLD%^%^GREEN%^"+
    "plops%^BOLD%^%^BLACK%^' as the %^RESET%^%^RED%^thorns%^BOLD%^%^BLACK%^ harvest what little life remains."+
    " You believe that the %^RESET%^%^GREEN%^sl%^BOLD%^u%^RESET%^%^GREEN%^dge%^BOLD%^%^BLACK%^ used to "+
    "be water but years of stagnation and decay have deduced it to its current state. Travel here is nearly impossible "+
    "and a forboding and dreadful aura lingers over the surface of the %^RESET%^%^GREEN%^sl%^BOLD%^u%^RESET%^%^GREEN%^"+
    "dge%^BOLD%^%^BLACK%^ forming a tangible %^BOLD%^%^WHITE%^mist%^BOLD%^%^BLACK%^.%^RESET%^");


    set_items(([
        ({"marsh", "ancient marsh", "dreadful marsh"}) : "%^BOLD%^%^BLACK%^This marsh is ancient. What water might "+
        "have once been here has long since been deduced to a copious foul sludge. There are trees and roots "+
        "jutting up from within it at odd angles. They are wrapped tightly by treacherous thorns which seem to be "+
        "harvesting what little life remains from them. A forboding and dreadful aura lingers over the surface "+
        "of the sludge, forming a tangible mist.%^RESET%^", 
        ({"thorns", "treacherous thorns"}) : "%^RESET%^%^RED%^These treacherous thorns are in stark contrast to "+
        "the other foliage here. They are wrapped tightly around the trees and roots which jut up at odd angles from "+
        "the sludge and appear to be harvesting what little life remains from them.%^RESET%^",
        ({"trees", "gnarled trees", "roots", "thick roots"}) : "%^RESET%^%^GREEN%^These gnarled trees and "+
        "thick roots jut out from beneath the surface of the sludge at odd angles. Pieces of them break off and fall "+
        "into the sludge with audible 'plops' as the remaining life is sucked out of them by the treacherous "+
        "thorns.%^RESET%^",
        ({"sludge", "foul sludge"}) : "%^BOLD%^%^GREEN%^It is likely that this sludge was once the water that "+
        "provided substenance to the foilage here but years of stagnation and decaying plant matter has deduced it "+
        "to its current state. Surprisingly the thorns appear to be thriving from the sludge while the trees and "+
        "their roots sink further into decay.%^RESET%^",
        ({"mist", "tangible mist", "aura", "dreadful aura"}) : "%^BOLD%^%^WHITE%^This tangible mist seems the "+
        "physical manifestation of a forbiding and dreadful aura that lingers over the surface of the "+
        "sludge. You are unsure if the aura is coming from the sludge or if it is something else "+
        "entirely but whatever the case may be the mist does little to make travel here easier.%^RESET%^",
    ]));

    set_smell("default","\nAn almost toxic odor of decay hangs heavily in the air.");
    set_listen("default","Screams and growls faintly float through the air...");
}

void reset()
{
    place_my_mobs();
    ::reset();    
}

void sludge_monster(object who)
{
    object mob;
    if(!objectp(who)) return;
    if(member_array(who, entrapped) != -1) entrapped -= ({who});           
    if(environment(who) == TO)
    {
        who->set_paralyzed(0);                
        tell_object(who, "%^BOLD%^%^GREEN%^You manage to free yourself from the "+
        "%^RESET%^%^GREEN%^foul sludge%^BOLD%^!%^RESET%^");
        if(!TP->query_invis())
        {
            tell_room(TO, who->QCN+"%^BOLD%^%^GREEN%^ manages to free "+
            TP->QO+"self from the %^RESET%^%^GREEN%^foul sludge%^BOLD%^!"+
            "%^RESET%^", who);
        }
        if(!random(5))
        {
            mob = new(MMPATH"sludge_elemental");
            tell_room(TO, "%^BOLD%^%^GREEN%^A strange gurgling noise "+
            "ECHOES%^BOLD%^%^GREEN%^ through the %^BOLD%^%^BLACK%^marsh"+
            "%^BOLD%^%^GREEN%^ as "+mob->query_short()+"%^BOLD%^%^GREEN%^"+
            " erupts from the %^RESET%^%^GREEN%^foul sludge%^BOLD%^ and barrels "+
            "toward "+who->QCN+"%^BOLD%^%^GREEN%^!%^RESET%^", who);
            
            tell_object(who, "%^BOLD%^%^GREEN%^A strange gurgling noise "+
            "ECHOES%^BOLD%^%^GREEN%^ through the %^BOLD%^%^BLACK%^marsh"+
            "%^BOLD%^%^GREEN%^ as "+mob->query_short()+"%^BOLD%^%^GREEN%^" +
            " erupts from the %^RESET%^%^GREEN%^foul sludge%^BOLD%^ and barrels "+
            "toward you!%^RESET%^");
            mob->move(TO);
            mob->focus_on(who);
            mob->force_me("kill "+who->query_name());
            return;
        }
    }
    return;
}

void init()
{
    ::init();
    if(!pointerp(entrapped)) entrapped = ({});
    if(!objectp(TP)) return;
    if(userp(TP)) 
    {
        if(member_array(TP, entrapped) != -1 || TP->query_property("flying")) return;
        if(random(50)) return;
        tell_object(TP, "%^BOLD%^%^GREEN%^You slip into the %^RESET%^%^GREEN%^"+
        "foul sludge%^BOLD%^.... and struggle to free yourself from it!%^RESET%^");
        if(!TP->query_invis())
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^GREEN%^ slips into the %^RESET%^"+
            "%^GREEN%^foul sludge%^BOLD%^.... and struggles to free "+
            TP->QO+"self from it!%^RESET%^", TP);
        }
        TP->set_paralyzed(100, "%^BOLD%^%^GREEN%^You struggle to free yourself from "+
        "the %^RESET%^%^GREEN%^foul sludge%^BOLD%^!%^RESET%^");
        call_out("sludge_monster", 10, TP);
        return;        
    }
    return;
}


