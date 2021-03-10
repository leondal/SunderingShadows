#include <std.h>
inherit WEAPON;
int charges;

void query_charges();
void set_charges(int x);
void adj_charges(int x);

void create(){
	::create();
	set_name("staff");
	set_id(({ "staff", "kinordas staff","staff of fireballs",
    "fireball staff","kinordas fireball staff"}));
    
	set_obvious_short("A straight red wood staff");
	
    set_short("%^BOLD%^%^WHITE%^K%^YELLOW%^i%^BOLD%^%^WHITE%^n%^YELLOW%^o%^BOLD%^%^WHITE%^rd%^YELLOW%^a%^BOLD%^%^WHITE%^'s%^RESET%^ "+
    "%^RED%^Staff of F%^YELLOW%^i%^RESET%^%^RED%^r%^RESET%^e"+
    "%^RED%^b%^YELLOW%^a%^RESET%^%^RED%^lls%^RESET%^");
	
    set_long("%^RED%^This staff extends approximately five feet "+
    "in length.  Strangely, it is entirely straight, made from "+
    "a type of red wood.  The wood has patterns of varying shades "+
    "of red, ranging from very dark to a light that borders on "+
    "pink.  The patterns when observed create a "+
    "phrase that stands out in such a matter to suggest "+
    "importance.  One end of the staff is wrapped with a "+
    "thin cr%^YELLOW%^i%^RESET%^%^RED%^ms%^YELLOW%^o%^RESET%^"+
    "%^RED%^n cloth and the opposite end of the staff "+
    "becomes a shallow orafice.  The inside of the orafice "+
    "is charred and puffs of sm%^RESET%^o%^RED%^ke occassionally "+
    "explode outward from it.%^RESET%^");
    	
	set_read("%^RED%^Blast%^RESET%^ those that stand against you.");
        
    set_lore("This staff was created by the forgotten priest "+
    "Kinorda some ages ago.  It is rumored to have only one "+
    "function and to be of a very simple design.  However, Kinorda "+
    "was known to imbue his objects with various magical properties "+
    "and some stories suggest another property of this "+
    "staff grants the wielder the ability to inflict more "+
    "damage to his enemies.  This staff was lost some "+
    "years ago whenever Kinorda himself vanished.");

    	set_property("lore difficulty",10);
   	set("langage","common");	
    	set_weight(7);	
    	set_value(5000);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(3);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",3+random(2));
    	charges = 10 + random(11);
    	set_wield((:TO,"wield_me":));
    	set_unwield((:TO,"unwield_me":));
	set_item_bonus("damage bonus", 1);
}

int wield_me() {
    if(ETO->query_highest_level() < 15) {
        tell_object(ETO,"%^RED%^Your hands are burned as you "+
        "try to grip the staff and the pain is too intense "+
        "for you to hold it!%^RESET%^");
        ETO->do_damage("left hand",roll_dice(1,10));
        return 0;
    }
    tell_object(ETO,"%^RED%^You take hold of the staff and "+
    "feel empowered to strike harder.%^RESET%^");
    return 1;
}

int unwield_me() {
    tell_object(ETO,"%^RED%^You release the staff and feel "+
    "the power to strike harder leave you.%^RESET%^");
    return 1;
}

void query_charges() {
    return charges;
}

void set_charges(int x) {
    charges = x;
}

void adj_charges(int x) {
    charges = charges + x;
}

void init(){
    ::init();
    add_action("fireball","blast");
}

void failure() {
    write("The staff fails to respond to your command.");
    return 1;
}

int fireball(string str) {
    object ob;
        
    if(ETO->query_unconscious() || ETO->query_bound()
    || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if(!str && query_wielded()) {
        write("Who do you want to %^RED%^blast%^RESET%^ "+
        "with the staff?");
        return 1;
    }

    if(charges <= 0 || !query_wielded() || charges - 1 < 0) {
        failure();
        return 1;
    }

    if(ob = present(str,EETO)) {
        if(living(ob) && objectp(ob)) {
            tell_object(ETO,"%^RED%^You point the staff at "+
            ob->QCN+"%^RED%^ and begin chanting loudly!%^RESET%^");
            
            tell_object(ob,ETOQCN+"%^RED%^ points a staff at "+            
            "you and begins chanting loudly!%^RESET%^");
            
            tell_room(EETO,ETOQCN+"%^RED%^ points "+ETO->QP+ 
            " staff at "+ob->QCN+"%^RED%^ and begins "+
            "chanting loudly!%^RESET%^",({ETO,ob}));
            ETO->set_paralyzed(3,"%^RED%^Your busy using the staff!%^RESET%^");
            adj_charges(-1);
            new("/cmds/spells/f/_fireball")->use_spell(ETO,ob,14 + random(5),18,"mage");
            return 1;
        }
    }
    write("You see no such target here.");
    return 1;
}
        

