#include <std.h>
inherit ARMOUR;
int charges1;
int charges2;

int feattrack;

void create(){
	::create();
	set_name("circlet");
	set_id(({ "circlet", "illithid circlet", "sapphire circlet", "bone circlet","eye circlet","eye","zarizth's eye" }));
	set_short("%^BOLD%^%^WHITE%^Z%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ri%^RESET%^%^ORANGE%^z%^BOLD%^%^WHITE%^th's %^RESET%^%^CYAN%^e%^BOLD%^y%^RESET%^%^CYAN%^e%^RESET%^");
	set_obvious_short("%^RESET%^A strange %^BOLD%^b%^BLACK%^o%^RESET%^n%^BOLD%^e %^c%^RESET%^ir%^BOLD%^%^CYAN%^cl%^RESET%^e%^BOLD%^t%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This %^RESET%^circlet %^CYAN%^is entirely made out of"
             "%^RESET%^ twisted bone %^CYAN%^and %^BOLD%^%^WHITE%^sparkling"
             " %^CYAN%^sa%^BLUE%^p%^BLACK%^p%^BLUE%^h%^CYAN%^ire%^RESET%^%^CYAN%^, save for the strange"
             " %^BOLD%^e%^RESET%^%^CYAN%^y%^BOLD%^e %^RESET%^%^CYAN%^that rests in the center of the"
             " %^BOLD%^g%^BLUE%^e%^CYAN%^ms%^RESET%^%^CYAN%^.  A %^RESET%^pale %^CYAN%^and"
             " %^RESET%^cl%^CYAN%^ou%^RESET%^dy %^BOLD%^%^CYAN%^cyan %^RESET%^%^CYAN%^in color, the"
             " bulbous %^BOLD%^e%^RESET%^%^CYAN%^y%^BOLD%^e %^RESET%^%^CYAN%^stares %^ORANGE%^lifelessly"
             " %^CYAN%^outward as though it were simply waiting to be activated somehow.  Despite this"
             " oddity, the smooth %^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^ne %^CYAN%^has been %^WHITE%^polished"
             " %^RESET%^%^CYAN%^to a %^BOLD%^%^WHITE%^stunning shine%^RESET%^%^CYAN%^, and have been woven"
             " together with an %^MAGENTA%^artistic hand%^RESET%^%^CYAN%^.");
    set_lore("%^RESET%^%^ORANGE%^Made by a powerful illithid, this circlet has been rumored to"
             "both be able to <contact> people, as well as <scry> in upon their locations.  Myths and legend of old tell a story of Vecna being one of the few to have ever faced the illithid, but that has been written off mostly as untrue.  But is it?");
	set_weight(4);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(-1);
    set_property("enchantment",6);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_item_bonus("intelligence",4);
    set_item_bonus("will",4);

    charges1 = 15+ random(10);
    charges2 = 5+ random(5);
}

void init() {
   ::init();
   add_action("contact_em","contact");
   add_action("find_em","scry");
}

int wear_func(){
    tell_object(ETO,"%^BOLD%^%^CYAN%^The strange eye on the circlet blinks as you put the circlet into place");
    tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+""+
                " slips the circlet into place and looks surprised as the eye in the circlet slowly blinks.",ETO);

    if(member_array("unyielding soul",ETO->query_temporary_feats()) == -1) {
        ETO->add_temporary_feat("unyielding soul");
        feattrack = 1;
    }

	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^The %^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^y%^BOLD%^e %^RESET%^%^MAGENTA%^slowly shuts as "+ETO->query_cap_name()+" pulls the %^RESET%^ci%^BOLD%^%^BLACK%^rcl%^RESET%^et %^MAGENTA%^off.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^The %^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^y%^BOLD%^e %^RESET%^%^MAGENTA%^of the %^WHITE%^ci%^BOLD%^%^BLACK%^rcl%^RESET%^et %^MAGENTA%^slowly shuts as you pull it from your brow.%^RESET%^");
    if(feattrack)
    {
        ETO->remove_temporary_feat("unyielding soul"); //corrected a typo here, it was "unyelding soul" - Odin 2/16/20
        feattrack = 0;
    }
	return 1;
}

int contact_em(string str) {
   if(!TO->query_worn()) {
     notify_fail("You should be wearing the circlet to activate the spell.\n");
     return 0;
   }
   if(!str) {
     notify_fail("You should specify who you want to contact.\n");
     return 0;
   }
   if(!charges1) {
     notify_fail("The circlet's power is already depleted.\n");
     return 0;
   }
   charges1--;
   tell_room(ETP,"%^BOLD%^%^BLUE%^The %^CYAN%^e%^RESET%^%^CYAN%^y%^BOLD%^e %^BLUE%^of "+TP->QCN+
"'s %^WHITE%^circlet %^BLUE%^closes briefly.%^RESET%^",TP);
   new("/cmds/spells/t/_telepathy")->use_spell(ETO,str,40,100,"cleric");
   return 1;
}
int find_em(string str) { //code off of drow masks
    object ob,locale,*inv;
    string target,desc,*map_keys,real;
    int i,matches;
    mapping map;

    if(!str) {
        notify_fail("What?\n");
        return 0;
    }
    target = lower_case(str);

    if( (string)ETO->realNameVsProfile(target) && (string)ETO->realNameVsProfile(target) != "") { real = lower_case((string)ETO->realName(target)); }
    else
    {
	    tell_object(ETO,"%^BOLD%^RED%^You do not recall a person called "+target+"!%^RESET%^");
	    return 1;
    }

    ob = find_player(real);
    if(!ob) {
        notify_fail("Your senses do not extend to the realm known as Real Life!\n");
        return 0;
    }
    if(ob == TP) {
        notify_fail("You need only look around you to find yourself!\n");
        return 0;
    }
   if(!charges2) {
     notify_fail("The circlet's power is already depleted.\n");
     return 0;
   }
   charges2--;
    if(ob->query_property("no scry") || present("blockerx111",ob))
    {
    tell_room(ETP,"%^BOLD%^%^BLUE%^The %^CYAN%^e%^RESET%^%^CYAN%^y%^BOLD%^e %^BLUE%^of "+TP->QCN+"'s %^WHITE%^circlet %^BLUE%^closes briefly.%^RESET%^",TP);
        return 1;
    }
    if(ob->query_true_invis() || wizardp(ob)) { return 0; }
    locale = environment(ob);
    desc = (string)locale->query_long()+"\n";
    inv = all_inventory(locale);
    for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->query_invis()) continue;
        desc += (string)inv[i]->query_short()+"\n";
    }
    tell_object(TP,"%^RED%^You concentrate while the eye of the circlet closes and brings forth images in your mind.\n%^BLUE%^"+desc+"%^RESET%^");
    return 1;
}
