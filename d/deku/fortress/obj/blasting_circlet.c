// Coded by Saide
// Updated by Lujke December 20 2005, to fix a small bug that
// caused it to register as un-enchanted if it was cursed.

#include <std.h>
#include <daemons.h>
#define WAIT_TIME 15500

inherit ARMOUR;
int used_time;

void create(){
	::create();
	set_name("silver circlet");
	set_id(({ "circlet", "silver circlet", "circlet of blasting",
    "headband"}));
	
    set_short("%^BOLD%^%^WHITE%^Ish%^RED%^n%^WHITE%^or's "+
    "%^RESET%^Silver%^BOLD%^ Circlet of B%^RED%^la%^BOLD%^%^WHITE%^"+
    "st%^RED%^in%^BOLD%^%^WHITE%^g%^RESET%^");
	set_obvious_short("A silver circlet");
    set_property("repairtype",({ "jewel" }));
    set_long("%^BOLD%^%^WHITE%^This headband is made from a "+
    "solid piece of silver that is perhaps four inches wide.  A "+
    "%^RED%^fire ruby%^BOLD%^%^WHITE%^ is set into the center "+
    "of the front of it, where the band is slightly wider than "+
    "normal.  A shallow and narrow %^RESET%^groove%^BOLD%^%^WHITE%^ "+
    "runs from one side of the ruby around the entire band and "+
    "meets the other side of the ruby.  A much deeper mark "+
    "occassionally adorns the band directly above or below the "+
    "groove.  This circlet is obviously not designed to offer "+
    "defensive protection but the %^BLUE%^inscription%^BOLD%^"+
    "%^WHITE%^ engraved into the inside of the band may offer "+
    "an idea of what its true purpose is intended to be.%^RESET%^");
    
    set_read("%^RED%^Let the magnified light %^RESET%^sear"+
    "%^RED%^ the flesh of mine enemies!%^RESET%^");

    set_language(random(2) ? "elven":"common");
    
    set_lore("These handbands are rumored to have been "+
    "named after the magi who formed the first one.  They "+
    "have been used throughout the centuries by ascending mages "+
    "and as crutches or last resorts by warriors during the heat "+
    "of battle.  The legends suggest that the magical formula "+
    "only works correctly when used on high quality silver and "+
    "the lone ruby imbued with the right magical flame.");
   
	set_weight(3);
	set_value(1000);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(-1);
	set_wear((:TO,"wear_func":));
    set_property("enchantment",3);
    set_item_bonus("fire resistance", 5);
    set_item_bonus("acid resistance", 5);
}

void init() {
    ::init();
    if(living(ETO)) {
        add_action("sear_em","sear");
    }
}

void failure() {
    write("The circlet fails to respond...");
}

int sear_em(string str) {
    object targ;
    if(!str){
       tell_object(ETO,"You must declare a target!");
       return 0;
    }
//Added the above message in response to bug reports that nothing 
//was happening with the circlet. I had it return 0 in case 
//it was returning 0 for a particular reason (like to let another
//ability work). ~Circe~ 1/4/13
    if(ETO->query_bound() || ETO->query_unconscious()) {
       ETO->send_paralyzed_message("info",ETO);
       return 1;
    }
    if(!query_worn()) {
        failure();
        return 1;
    }     
    if(used_time + WAIT_TIME < time()) {
        if(targ = present(str,EETO)) {
            used_time = time();
            
            tell_object(ETO,"%^BOLD%^%^WHITE%^A ray of intense "+
            "%^YELLOW%^light%^BOLD%^%^WHITE%^ bursts forth from "+
            "your circlet and zaps toward toward "+targ->QCN+"!%^RESET%^");

            tell_room(EETO,"%^BOLD%^%^WHITE%^A ray of intense "+
            "%^YELLOW%^light%^BOLD%^%^WHITE%^ bursts forth from "+
            "the %^RED%^fire ruby%^BOLD%^%^WHITE%^ set into "+
            ETOQCN+"%^BOLD%^%^WHITE%^'s circlet and zaps toward "+
            targ->QCN+"!%^RESET%^",({ETO,targ}));

            tell_object(targ,"%^BOLD%^%^WHITE%^A ray of intense "+
            "%^YELLOW%^light%^BOLD%^%^WHITE%^ bursts forth from the "+
            "%^RED%^fire ruby%^BOLD%^%^WHITE%^ set into "+
            ETOQCN+"%^BOLD%^%^WHITE%^'s circlet and zaps toward "+
            "you!%^RESET%^");
            targ->add_attacker(ETO);
            targ->contine_attack();
            ETO->add_attacker(targ);
            ETO->continue_attack();
            if(targ->query_property("magic resistance") > 1 + random(100)) {
                tell_object(targ,"%^RED%^You are struck by the "+
                "ray but manage to resist its intense "+
                "heat!%^RESET%^");
                tell_room(EETO,targ->QCN+"%^RED%^ is struck by "+
                "the ray but seems unaffected by its intense "+
                "heat!%^RESET%^",targ);
                return 1;
            }
            tell_room(EETO,targ->QCN+"%^BOLD%^%^WHITE%^ is struck "+
            "by the intense ray of light!%^RESET%^",targ);
            tell_object(targ,"%^BOLD%^%^WHITE%^You are struck "+
            "by the intense ray of light!%^RESET%^");

            if(!SAVING_D->saving_throw(targ,"spell")) {
                targ->do_damage(targ->return_target_limb(),roll_dice(12,6));
                return 1;
            }
            targ->do_damage(targ->return_target_limb(),roll_dice(6,6));
            return 1;
        }
        write("No such target present");
        return 1;
    }
    failure();
    return 1;
}

int wear_func(){
    if(ETO->query_highest_level() < 15) {
        write("The magic of the circlet is too great!");      
        return 0;
    }
    /*if(!TO->query_owns_item(ETOQN)) {
        write("The magic of the circlet rejects you!");
        return 0;
    }*/
    tell_object(ETO,"The %^RED%^ruby%^RESET%^ in the circlet "+
    "flashes briefly!%^RESET%^");
    tell_room(EETO,"The %^RED%^ruby%^RESET%^ in "+ETO->QCN+"%^RESET%^"+
    "'s circlet flashes briefly!%^RESET%^",ETO);
	return 1;
}

int isMagic(){
 int y;
 y = ::isMagic();
 if (y<0){
   y--;
   return y;
 }
 y = y + 1;
 return y;
}
	
