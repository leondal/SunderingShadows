//Coded by Bane//
#include <std.h>
inherit WEAPON;
int uses;
void create() {
    ::create();
    set_id(({"staff","curing","staff of curing"}));
    set_name("staff of curing");
   set_obvious_short("A wooden staff");
   set_short("%^BOLD%^%^WHITE%^Staff of curing%^RESET%^");
   set("lore",
            "This long wooden staff is completely white.  Symbols of life "+
            "and health dorn its shaft.  There is an inscription "+
            "written on it."
            );
   set_long("This is a staff made out of white wood that has many symbols carved into its shaft.");
    set_weight(10);
    set_size(3);
    set_value(3500);
    set_type("bludgeoning");
    set_prof_type("staff");
    set_wc(1,6);
    set_large_wc(1,6);
    set_property("enchantment",2);
    uses = 0;
}
void init() {
    ::init();
    add_action("read","read");
    add_action("cure","cure");
}
void read(string str) {
    if(!str) return notify_fail("Read what?\n");
    if(str != "staff") return 0;
    write("This is a staff of curing, it has the following functions "+
          "that each use one charge:\n"
          "cure wounds on <name>: heals 6 - 21 damage on a living being\n"
          "cure poison on <name>: removes poison from a living being\n"
          "cure paralysis on <name>: removes paralysis from a living\n"
          "   being(doesnt work while wielder is paralyzed)"
         );
    return 1;
}
void cure(string str) {
    string who;
    object ob;
    if(!TO->query_wielded()) return notify_fail("You have to wield the staff first.\n");
    if(TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(uses > 24) return notify_fail("The staff is out of charges.\n");
    if(!str) return notify_fail("What type of cure and on who?\n");
    if(sscanf(str,"wounds on %s",who)) {
        if(!(ob = present(who, ETP))) return notify_fail("That isn't here!\n");
        tell_object(TP,"You touch the staff to "+ob->query_cap_name()+
                    "'s forehead.");
        tell_object(ob,TP->query_cap_name()+" touches the staff to "+
                    "your forehead.");
        tell_room(ETP,TP->query_cap_name()+" touches the staff to "+
                  ob->query_cap_name()+"'s forehead.",({TP,ob}));
        ob->heal(roll_dice(3,6)+3);
        uses += 1;
        return 1;
    }
    if(sscanf(str,"poison on %s",who)) {
        if(!(ob = present(who,ETP))) return notify_fail("That isn't here!\n");
        tell_object(TP,"You touch the staff to "+ob->query_cap_name()+
                    "'s forehead.");
        tell_object(ob,TP->query_cap_name()+" touches the staff to "+
                    "your forehead.");
        tell_room(ETP,TP->query_cap_name()+" touches the staff to "+
                  ob->query_cap_name()+"'s forehead.",({TP,ob}));
        ob->add_poisoning(-(int)ob->query_poisoning());
        uses += 1;
        return 1;
    }
    if(sscanf(str,"paralysis on %s",who)) {
        if(!(ob = present(who,ETP))) return notify_fail("That isn't here!\n");
        tell_object(TP,"You touch the staff to "+ob->query_cap_name()+
                    "'s forehead.");
        tell_object(ob,TP->query_cap_name()+" touches the staff to "+
                    "your forehead.");
        tell_room(ETP,TP->query_cap_name()+" touches the staff to "+
                  ob->query_cap_name()+"'s forehead.",({TP,ob}));
        ob->set_paralyzed(0);
        uses += 1;
        return 1;
    }
    return 0;
}
