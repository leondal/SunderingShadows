#include <std.h>
inherit "/d/common/obj/clothing/hat.c";

void create(){
	::create();
	set_name("crown of flames");
	set_id(({ "crown", "fire crown", "crown of flames", "flame crown", "daliigwins crown" }));
	set_short("%^RED%^D%^RESET%^a%^RED%^l%^YELLOW%^i%^RESET%^i%^RED%^gw%^BOLD%^%^WHITE%^i%^RESET%^%^RED%^n's %^BOLD%^%^WHITE%^Crown of %^RESET%^%^RED%^Fl%^YELLOW%^a%^RESET%^%^RED%^m%^YELLOW%^e%^RESET%^%^RED%^s%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^A crown of %^BOLD%^f%^RESET%^%^ORANGE%^l%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^m%^RED%^e%^BOLD%^s%^RESET%^");
    set_property("repairtype",({ "jewel" }));
        set_long("%^BOLD%^%^WHITE%^This crown is made from a "+
    "%^BOLD%^%^BLACK%^dark%^RESET%^%^RED%^ cr%^YELLOW%^i"+
    "%^RESET%^%^RED%^mson%^BOLD%^%^WHITE%^ met%^RESET%^%^BLUE%^"+
    "a%^BOLD%^%^WHITE%^l.  The met%^BLUE%^a%^RESET%^%^BOLD%^"+
    "%^WHITE%^l has been enchanted to %^RED%^b%^YELLOW%^u"+
    "%^RESET%^%^RED%^rn %^BOLD%^%^WHITE%^continually, "+
    "fl%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^shes of %^RESET%^"+
    "%^RED%^f%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^e%^BOLD%^"+
    "%^WHITE%^ erupt from it constantly in some type of "+
    "strange, undiscernable pattern.  %^RESET%^%^RED%^Rub"+
    "%^YELLOW%^i%^RESET%^%^RED%^es %^BOLD%^%^WHITE%^are set "+
    "into it near the base and %^BOLD%^%^BLACK%^darker"+
    "%^BOLD%^%^WHITE%^ and smaller %^RESET%^%^RED%^rub"+
    "%^YELLOW%^i%^RESET%^%^RED%^es%^BOLD%^%^WHITE%^ are set "+
    "into the ridged top.  A %^BOLD%^%^BLACK%^dark "+
    "%^RESET%^%^BLUE%^blue%^BOLD%^%^WHITE%^ band of fire, "+
    "approximately two inches wide surrounds the center "+
    "of the entire crown.  A light %^RESET%^%^BLUE%^blue"+
    "%^BOLD%^%^WHITE%^ barrier encompasses the crown and "+
    "controls the otherwise chaotic nature of the "+
    "%^RESET%^%^RED%^fl%^YELLOW%^a%^RESET%^%^RED%^m"+
    "%^YELLOW%^e%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^.%^RESET%^");

    set_weight(4);
	set_value(3000);
	set_lore("These crowns were formed some ages ago by the "+
    "forgotten priest Kinorda, as gifts to his most trusted "+
    "and powerful servants.  This particular crown was formed "+
    "for the servant Daliigwin and is rumored to be Daliigwin's "+
    "most valued possession.  Rumors surrounding the crown "+
    "suggest that whatever magical properties it once had, "+
    "like all things made by Kinorda, began to fade not long "+
    "after its creation.  Another, more quiet rumor, suggests "+
    "that by 'observing the patterns' of the eruptions from "+
    "the crown has some type of affect.");

	set_property("lore difficulty",10);
	set_size(1);
    set_property("enchantment",3);
    set_item_bonus("charisma", 2);
      
}

void init() {
    ::init();
    add_action("observe","observe");
}

void do_display_patterns(object who, int step) {
    if(ETO != who) {
        if(objectp(who)) {
            who->remove_paralyzed();
        }
        return;
    }

    switch(step) {
        case 0:
            tell_object(who,"%^RED%^You see what appears "+
            "to be a large and flowing lake of fire.  "+
            "From the center of the lake rises a grotesque "+
            "and horrid creature, its body bent and gnarled, "+
            "its flesh a %^BOLD%^%^BLACK%^sooty%^RESET%^%^RED%^ "+
            "black, with %^BOLD%^%^BLACK%^black wings%^RESET%^"+
            "%^RED%^ sprouting out from its upper back.%^RESET%^");
            break;
        case 1:
            tell_object(who,"%^RED%^The creature floats "+
            "lifelessly toward the bank of the lake.  "+
            "The bank of the lake is made from flaming "+
            "rock and standing on the bank, with one finger beckoning "+
            "the creature forward, is a man clothed "+
            "with fire.  The creature hovers in "+
            "the air before the man and its body begins "+
            "to quake and shudder.%^RESET%^");
            break;
        case 2:
            tell_object(who,"%^RED%^A sudden intake of "+
            "air chokes the creature and its eyes "+
            "shoot open, they are a most intense "+
            "%^BLUE%^blue%^RESET%^%^RED%^.  The man laughs "+
            "insanely and chants a strange, yet short, phrase "+
            "and then slowly says: %^BOLD%^%^WHITE%^ "+
            "I shall call you Daliigwin, You will be "+
            "my servant, and I, Kinorda, who has given you "+
            "life, shall be your master.  You will do "+
            "my bidding or else return to the lake, with "+
            "life blood still flowing through your veins.  ");
            break;
        case 3:
            tell_object(who,"%^RED%^The man who called himself "+
            "Kinorda, laughs and turns away, walking up the "+
            "steep bank of the lake.  The creature stares at "+
            "him in both fear and admiration and sprints after him "+
            "shouting and waving its arms in what you recognize "+
            "to be a form of praise.%^RESET%^");
            tell_room(environment(who),"%^RED%^A loud shouting "+
            "of what you instantly recognize to be "+
            "praise suddently erupts from "+who->QCN+"%^RED%^"+
            "'s crown.%^RESET%^",ETO);
            tell_object(who,"%^RED%^You shake your head and "+
            "pull your gaze from the patterns as the scene "+
            "fades to blackness.%^RESET%^");
            tell_room(environment(who),who->QCN+"%^RED%^ "+
            "shakes "+ETO->QP+" head and pulls "+
            ETO->QP+" gaze from the crown.%^RESET%^",ETO);
            ETO->remove_paralyzed();
            break;
    }
    if(step < 4) {
        step++;
        call_out("do_display_patterns",10,who,step);
        return;
    }
    return;

}


int observe(string str) {
    if(str == "patterns" || str == "the patterns") {
        tell_object(ETO,"%^RED%^You stare intently at the "+
        "patterns, observing them, trying to figure out "+
        "the method behind their hidden order.");
        tell_room(EETO,ETOQCN+"%^RED%^ stares at "+ETO->QP+
        " crown, observing the flashes of f%^YELLOW%^i"+
        "%^RESET%^%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^ "+
        "that erupt from it.%^RESET%^",ETO);
        call_out("do_display_patterns",8,ETO,0);
        ETO->set_paralyzed(459,"%^RED%^You are captivated by "+
        "the dancing patterns of fire.%^RESET%^");
        return 1;
    }
    return 0;
}
