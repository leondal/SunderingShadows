//Updated with tp proof querying - Octothorpe 12/15/09
// locked to new 'tools of the trade' feat for thieves and bards. N, 4/15.
#include <std.h>
#include <daemons.h>
inherit OBJECT;
string baseloc, baseroom;
void set_origin(string str);

void create()
{
    ::create();
    set_name("black orb");
    set_id(({"orb","black orb","bomb","smokebomb","smoke bomb"}));
    set_short("%^BOLD%^%^BLACK%^Smo%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^ebomb%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^glossy black orb%^RESET%^");
    set_long((:TO,"long_desc":));
    set_weight(5);
    set_value(2000);
    set_origin("torm");
}

void init() {
    ::init();
    set_long((:TO,"long_desc":));
    add_action("light_func","light");
}

string long_desc() {
    string mydesc;
    mydesc = "%^RESET%^The %^BOLD%^%^BLACK%^jet-black surface %^RESET%^of this "
        "orb is glossy enough to see your face reflected in.  It is a %^CYAN%^perfect "
        "sphere%^RESET%^, just the right size to fit in a person's hand, and unmarked "
        "except at what must be the top and underside.  At the top, a small hole allows "
        "%^ORANGE%^slender braided threads %^RESET%^to protrude, woven together and "
        "coated in some kind of resin or oil.";
    if(TP->is_class("thief") || TP->is_class("bard")) {
        mydesc += "  Upon the underside are %^GREEN%^letters %^RESET%^scrawled "
            "to represent the "+baseloc+" thieves guild.\n";
        if(TP->is_singleClass())
            mydesc += "You've seen items like this before.  You're sure if you "
                "%^YELLOW%^light%^RESET%^ the orb and cast it down before you, you can make a "
                "quick getaway.\n";
    }
    else mydesc += "  Upon the underside are %^GREEN%^letters %^RESET%^scrawled "
        "in an unknown hand.\n";
    return mydesc;
}

int light_func(string str) {
    object destination;
    if( !str || !TO->id(str)) {
        notify_fail ("Light what?\n");
        return 0;
    }
    if (ETO->query_bound() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if(userp(ETO) && !FEATS_D->usable_feat(ETO,"tools of the trade")) {
        tell_object(ETO,"You wouldn't know how to use that!");
        return 1;
    }
    if((int)ETO->is_retinue()) {
        tell_object(ETO,"You wouldn't know how to use that!");
        return 1;
    }

    if(ETO->query_paralyzed())
        return notify_fail(ETO->query_paralyze_message()+"\n");
    destination = find_object_or_load(baseroom);
    if(EETO->query_property("teleport proof")){
        if((int)EETO->query_property("teleport proof") > (ETO->query_highest_level() + random(20))) {
            tell_object(ETO,"You strike a %^YELLOW%^light %^RESET%^to the end of the "
                "fuse and cast it down before you as it starts spewing %^BOLD%^%^BLACK%^thick "
                "smoke%^RESET%^.  But when the smoke clears... you are still standing there.  "
                "So much for a quick getaway?");
            tell_room(EETO,""+ETOQCN+" strikes a light to the end of the orb's fuse and "
                "casts it down as it starts spewing %^BOLD%^%^BLACK%^thick smoke%^RESET%^.  But "
                "when the smoke clears... "+ETO->QS+" is still standing there.",ETO);
            TO->remove();
            return 1;
        }
    }
    if(EETO->query_property("no teleport") || destination->query_property("no teleport")) {
        tell_object(ETO,"You strike a %^YELLOW%^light %^RESET%^to the end of the "
            "fuse and cast it down before you as it starts spewing %^BOLD%^%^BLACK%^thick "
            "smoke%^RESET%^.  But when the smoke clears... you are still standing there.  "
            "So much for a quick getaway?");
        tell_room(EETO,""+ETOQCN+" strikes a light to the end of the orb's fuse and "
            "casts it down as it starts spewing %^BOLD%^%^BLACK%^thick smoke%^RESET%^.  But "
            "when the smoke clears... "+ETO->QS+" is still standing there.",ETO);
        TO->remove();
        return 1;
    }
    tell_object(ETO,"You strike a %^YELLOW%^light %^RESET%^to the end of the "
        "fuse and cast it down before you as it starts spewing %^BOLD%^%^BLACK%^thick "
        "smoke%^RESET%^.");
    tell_room(EETO,""+ETOQCN+" strikes a light to the end of the orb's fuse and "
        "casts it down as it starts spewing %^BOLD%^%^BLACK%^thick smoke%^RESET%^.  But "
        "when the smoke clears... "+ETO->QS+" is gone!",ETO);
    ETO->move_player(baseroom);
    tell_object(ETO,"When the smoke clears, you find yourself emerging safely "
        "from the shadows back near the guild.");
    tell_room(EETO,""+ETOQCN+" steps from the shadows, smelling faintly of "
        "%^BOLD%^%^BLACK%^smoke%^RESET%^.",ETO);
    TO->remove();
    return 1;
}

void set_origin(string str) {
    if(!str) return 0;
    if(str != "torm" && str != "tharis" && str != "juran") return 0;
    baseloc = str;
    switch(baseloc) {
        case "torm": baseroom = "/d/dagger/Torm/city/warehouse"; break;
        case "tharis": baseroom = "/d/tharis/newtharis/rooms/thief_tailor"; break; //not sure if this is correct - was pointing to tea shop that no longer exists.
        case "juran": baseroom = "/d/shadow/juran/city/a3"; break;
        case "seneca": baseroom = "d/attaya/newseneca/rooms/bar_storage"; break;
    }
}

string query_origin() { return baseloc; }
