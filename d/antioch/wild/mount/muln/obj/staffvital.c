#include <std.h>
#define MAXUSE 20
inherit "/d/common/obj/weapon/quarter_staff.c";

int uses;

void is_straight_cleric(object ob);

void create()
{
   ::create();
    set_obvious_short("%^BOLD%^%^WHITE%^A white yew wood staff with three "
        "%^RESET%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^BLUE%^n%^RESET%^"
        "%^CYAN%^g%^BOLD%^%^BLUE%^s%^RESET%^");
    set_name("Staff of Vitality");
    set_short("%^BOLD%^%^WHITE%^Staff of %^RESET%^%^CYAN%^V%^BOLD%^"
        "%^BLUE%^i%^GREEN%^t%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^l%^GREEN%^"
        "i%^RESET%^%^BOLD%^%^BLUE%^t%^RESET%^%^CYAN%^y%^RESET%^");
    set_id(({"staff","white staff","yew staff","staff of vitality", "Staff of Vitality"}));
    set_long("%^BOLD%^%^WHITE%^This six foot long staff is carved from a solid piece of " 
        "yew. The wood carries a smooth polished feeling, as if it's been worn from "
        "ages of use. The smooth wood has been bleached stark white, though none of "
        "the wood seems to have deteriorated. A steel cap on the crown of the staff "
        "closes off the top of the staff. Three large rings painted %^RESET%^%^CYAN%^"
        "blue-green%^BOLD%^%^WHITE%^, %^BLUE%^cerulean blue%^WHITE%^, and %^GREEN%^"
        "grass green%^WHITE%^ are linked through a central opening.");
    set_lore("The Staff of Vitality has been mentioned in many holy texts of every "
        "faith. It is said that only those with strong wills and deep devotion to "
        "the gods can ever hope to grasp such a powerful staff. Yew wood holds a "
        "sacred meaning, sages speculate, because of it's use in many healing and "
        "cleansing rituals performed by clergymen and women. The Staff of Vitality "
        "is said to bear within it the power to heal the wounds of many. A couple "
        "of legends have surfaced that when in time of need a benevolent diety "
        "will bless one of their clergy with this staff. Tales of priests going "
        "about plagued areas to heal the wounds of the populace can be found in "
        "nearly every faith.");
    set_read("\nIn the hands of the devoted, the staff can %^BOLD%^cure "
        "%^RESET%^many things. Those not of the calling may %^BOLD%^"
        "cure %^RESET%^poison on a fellow or themselves. Those of the "
        "calling who have not fully devoted themselves may %^BOLD%^cure "
        "%^RESET%^poison and set free a paralyzed companion. Those who are fully "
        "devoted to the cause may even restore sight to the blind through "
        "the power of the staff.");

    set_language("common");
    set_property("lore difficulty",7);

    set_value(5000);
    set_property("enchantment",4);
	set_item_bonus("caster level",2);
    set_hit((:TO,"hitme":));
    set_wield((:TO,"wieldme":));
    set_unwield((:TO,"unwieldme":));
    uses = 0;
}

void init() 
{
    ::init();
    add_action("cure","cure");
}

void is_straight_cleric(object ob)
{
    if(!objectp(ob)) return notify_fail("The staff is busted, tell a wiz.");
    if(ob->is_singleClass() && (member_array("cleric", ob->query_classes()) != -1) )  { return 1; }
    return 0;
}

int wieldme() 
{
    if((int)ETO->query_lowest_level() >= 22 ) {
        if (!ETO->query_property("silent_wield") && is_straight_cleric(ETO)) {
            tell_object(ETO, "%^BOLD%^The %^BLUE%^r%^GREEN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^"
                "g%^GREEN%^s%^WHITE%^ on the staff chime together as you grasp the yew wood staff.");
            tell_room(EETO, "%^BOLD%^As " + ETO->QCN + " grasps the yew wood staff, the three metal "
                "%^BLUE%^r%^GREEN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^g%^GREEN%^s%^WHITE%^ "
                "chime together", ETO);
        }
        return 1;
    }

    tell_object(ETO,"You are not strong enough to wield this weapon!");
    return 0;
}

int unwieldme()
{
    if(!ETO->query_property("silent_wield") && is_straight_cleric(ETO)) {
        tell_object(ETO,"%^BOLD%^Pulling your hands from the smooth staff, "
            "the metal %^BLUE%^r%^GREEN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^"
            "g%^GREEN%^s%^WHITE%^ chime once more");
        tell_room(EETO,"%^BOLD%^As "+ETO->QCN+" removes their hold from the "
            "yew wood staff, the three metals %^BLUE%^r%^GREEN%^i%^RESET%^%^CYAN%^"
            "n%^BOLD%^%^BLUE%^g%^GREEN%^s%^WHITE%^ chime together",ETO);
    }
    return 1;
}

int hitme(object targ)
{
    if(!objectp(targ)) return 0;

    if(random(1000) > 700 && is_straight_cleric(ETO))
    {
        tell_object(ETO,"You spin the staff around, striking "+targ->QCN+" with "
            "each of the three metal rings");
        tell_object(targ,""+ETO->QCN+" spins the yew wood staff around, striking you "
            "three times with the metal rings.");
        tell_room(EETO,""+ETO->QCN+" spins the yew wood staff around, "
            "striking "+targ->QCN+" with each of the three metal rings",({ETO,targ}));
        TO->set_property("magic", 1);
        ETO->cause_typed_damage(ETO, 0, roll_dice(1, 4), "bludgeoning");
        ETO->cause_typed_damage(ETO, 0, roll_dice(1, 4), "bludgeoning");
        ETO->cause_typed_damage(ETO, 0, roll_dice(1, 4), "bludgeoning");
        TO->set_property("magic", -1);
        return 1;
    }

    if(is_straight_cleric(ETO)) { return roll_dice(1,6); }
    return roll_dice(1,3);

}

void cure(string str) 
{
    string who;
    object ob;
    if(uses > MAXUSE) return notify_fail("The staff is out of charges.\n");
    if(!TO->query_wielded()) return notify_fail("You have to wield the staff first.\n");
    if(TP->query_bound() || TP->query_unconscious()) { TP->send_paralyzed_message("info",TP); return 1;}

    if(uses > MAXUSE) return notify_fail("The staff is out of charges.\n");
    
    if(!str) return notify_fail("What type of cure and on who?\n");

    if(sscanf(str,"blindness on %s",who)) 
    {
        if(!is_straight_cleric(TP)) { return notify_fail("You do not have the devotion to use this power!\n"); }
        if(!(ob = present(who, ETP))) { return notify_fail("That isn't here!\n"); }
        
        tell_object(TP,"%^BOLD%^%^WHITE%^You shake the staff around "+ob->QCN+", " 
            "moving in a circle and call upon the power of the %^BOLD%^%^BLUE%^"
            "cerulean blue%^WHITE%^ ring.");
        tell_object(ob,"%^BOLD%^%^WHITE%^"+TP->QCN+" shakes the staff around you and "
            "the %^BLUE%^cerulean blue%^WHITE%^ ring begins to glow!",TP);
        tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" shakes "+TP->QP+" yew "
            "wood staff around "+ob->QCN+", moving in a circle. "
            "The %^BLUE%^cerulean blue%^WHITE%^ ring begins to glow!",({TP,ob}));  
        
        ob->set_blind(0);
        ob->set_temporary_blinded(0);
        uses += 1;
        return 1;
    }


    if(sscanf(str,"paralysis on %s",who)) 
    {
        if(member_array("cleric",TP->query_classes()) == -1 ) { return notify_fail("You do not have the devotion to use this power!\n"); }
        if(!(ob = present(who,ETP))) return notify_fail("That isn't here!\n");

        tell_object(TP,"%^BOLD%^%^WHITE%^You shake the staff around "+ob->QCN+", "
            "moving in a circle and call upon the power of the "
            "%^BOLD%^%^GREEN%^grass green%^WHITE%^ ring.");        
        tell_object(ob,"%^BOLD%^%^WHITE%^"+TP->QCN+" shakes "+TP->QP+" yew wood "
            "staff around you, moving in a circle. The %^GREEN%^grass "
            "green%^WHITE%^ ring begins to glow!");        
        tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" shakes "+TP->QP+" yew wood "
            "staff around "+ob->QCN+", moving in a circle. The %^GREEN%^grass "
            "green%^WHITE%^ ring begins to glow!",({TP,ob}));

        ob->set_paralyzed(0);
        uses += 1;
        return 1;
    }
    return 0;
}
