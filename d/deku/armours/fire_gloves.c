#include <std.h>
inherit "/d/common/obj/clothing/gloves.c";
int charges;

void query_charges();
void set_charges(int x);
void adj_charges(int x);

void create(){
	::create();
	set_name("gloves of fire");
	set_id(({ "gloves", "fire gloves", "gloves of fire",
    "burning hands","hands" }));
	set_short("%^RED%^D%^RESET%^a%^RED%^l%^YELLOW%^i%^RESET%^i%^RED%^gw%^BOLD%^%^WHITE%^i%^RESET%^%^RED%^n's %^RED%^B%^YELLOW%^u%^RESET%^%^RED%^rn%^YELLOW%^i%^RESET%^%^RED%^ng H%^YELLOW%^a%^RESET%^%^RED%^nd%^YELLOW%^s%^RESET%^");
    set_obvious_short("%^BOLD%^%^RED%^A pair of %^RESET%^%^RED%^fl%^ORANGE%^a%^RED%^mi%^ORANGE%^n%^RED%^g %^BOLD%^gloves%^RESET%^");
	set_long("%^RED%^These strange gloves are made entirely "+
    "from roaring and out of control f%^YELLOW%^i%^RESET%^"+
    "%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^.  It is impossible "+
    "to determine if there is any solid substance to them at "+
    "all, it is as if pure f%^YELLOW%^i%^RESET%^%^RED%^r"+
    "%^YELLOW%^e%^RESET%^%^RED%^ was somehow tailored to make "+
    "them.  The fl%^YELLOW%^a%^RESET%^%^RED%^m%^YELLOW%^e"+
    "%^RESET%^%^RED%^s not only give them their existance but "+
    "also seem to be desperately trying to consume them.  "+
    "The coloration of the f%^YELLOW%^i%^RESET%^%^RED%^r"+
    "%^YELLOW%^e%^RESET%^%^RED%^ spans the spectrum, "+
    "ranging from light %^ORANGE%^orange%^RESET%^%^RED%^ "+
    "and reds, to lighter and darker %^BLUE%^blues%^RED%^.  "+
    "Occassionally the palms of the gloves %^CYAN%^"+
    "glow%^RESET%^%^RED%^ brighter and what looks like a "+
    "message is almost formed, you might be able to read it.  "+
    "A light %^BLUE%^blue%^RED%^ barrier surrounds them "+
    "entirely, as a means of preventing whoever happens to "+
    "wear them from being burned severely.%^RESET%^");

    set("read","With my hands I can %^RED%^burn%^RESET%^ "+
    "whoever I see fit.");
    set("langage","common");
    set_weight(1);
    set_value(888);
    set_lore("These gloves were formed by the forgotten "+
    "priest Kinorda, for his servant Daliigwin.  It "+
    "is rumored that Daliigwin enjoyed fire as much or "+
    "perhaps more than Kinorda himself and as Daliigwin "+
    "was his most loyal and trusted follower, Kinorda "+
    "awarded him with these.  It is rumored that at one "+
    "point in time they had many more magical properties, "+
    "but like all things forged by Kinorda those properties "+
    "began to fade not long after their creation.");
    set_property("lore difficulty",10);
	set_size(1);
    set_property("enchantment",3);
    set_item_bonus("thievery", -3);
    set_item_bonus("endurance", 2);
    set_item_bonus("fire resistance", 10);
    set_wear((:TO,"wear_me":));
    set_remove("%^RED%^You remove the gloves and your hands "+
    "feel strangely cool.%^RESET%^");
    charges = 10 + random(11);
}

int wear_me() {
    if(ETO->query_highest_level() < 15) {
        tell_object(ETO,"%^RED%^You are not powerful "+
        "enough to control these gloves!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^RED%^You slip your hands into the "+
    "gloves and are momentarily overwhelmed by the heat "+
    "but it quickly becomes bearable.%^RESET%^");
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
    add_action("burninghands","burn");
}

void failure() {
    write("You touch the thumbs of the gloves together, "+
    "but nothing seems to happen.");
    return 1;
}

int burninghands(string str) {
    object ob;
        
    if(ETO->query_unconscious() || ETO->query_bound()
    || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if(!str && query_worn()) {
        write("Who do you want your hands to %^RED%^burn%^RESET%^?");
        return 1;
    }

    if(charges <= 0 || !query_worn() || charges - 1 < 0) {
        failure();
        return 1;
    }

    if(ob = present(str,EETO)) {
        if(living(ob) && objectp(ob)) {
            tell_object(ETO,"%^RED%^You touch the thumbs of your "+
            "gloves together and focus on "+ob->QCN+", "+
            "chanting loudly!%^RESET%^");
            
            tell_object(ob,ETOQCN+"%^RED%^ touches the thumbs of "+
            ETO->QP+" gloves together and focuses on you, "+
            "chanting loudly!%^RESET%^");
            
            tell_room(EETO,ETOQCN+"%^RED%^ touches the "+
            "thumbs of "+ETO->QP+ " gloves together and "+
            "focuses on "+ob->QCN+"%^RED%^, "+
            "chanting loudly!%^RESET%^",({ETO,ob}));
            ETO->set_paralyzed(3,"%^RED%^Your using the gloves!%^RESET%^");
            adj_charges(-1);
            new("/cmds/spells/b/_burning_hands")->use_spell(ETO,ob,12 + random(5),16,"mage");
            return 1;
        }
    }
    write("You see no such target here.");
    return 1;
}
        



