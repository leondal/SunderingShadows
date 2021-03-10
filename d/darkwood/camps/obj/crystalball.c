#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("crystal ball");
   set_id(({"crystal ball","ball","crystal"}));
   set_obvious_short("%^BOLD%^WHITE%^Crystal Ball%^RESET%^");
   set_short("crystal ball");
   set_long("%^BOLD%^%^WHITE%^This is a crystal ball, filled with a smokey gray"+
            " mist. The mist is constantly swirling.%^RESET%^");
   set_weight(10);
   set_value(10);
}

void init() {
   ::init();
   add_action("scry_func","scry");
}

int scry_func(string str) {
object ob,locale;
string target;
int i; 
object *inv;
string desc;
    if(!str) {
        notify_fail("What?\n");
        return 0;
    }
    target = str;
    ob = find_player(target);
    if(!ob) {
        notify_fail("%BOLD%^%^WHITE%^The mist stirs...");
        return 0;
    }
    if(ob == TP) {
        notify_fail("%^BOLD%^%^WHITE%^You need only look around you to find yourself!\n");
        return 0;
    }
    if(ob->query_invis()) {
        notify_fail("%^BOLD%^%^WHITE%^The mist shifts, but nothing is revealed!");
        return 0;
    }
    if(ob->query_property("no scry")){
      notify_fail("%^BOLD%^%^WHITE%^The ball fills with intense fog, it is unclear!");
      return 0;
    }
    if(wizardp(ob)) {
        notify_fail("%^BOLD%^%^RED%^Do not use these powers on wizards!");
        return 0;
    }
    locale = environment(ob);
    desc = (string)locale->query_long()+"\n";
    inv = all_inventory(locale);
    for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->query_invis()) continue;
        desc += (string)inv[i]->query_short()+"\n";
    }
    tell_object(TP,"%^BOLD%^WHITE%^You concentrate while peering through the ball.\n"+desc+"");
    tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" peers into the crystal ball.",TP);
    if( random(10) > 2) {
        tell_object(TP,"%^BOLD%^%^WHITE%^The ball fills with mist, then %^BOLD%^%^RED%^cracks%^BOLD%^%^WHITE%^!");
        TO->remove();
    }
    return 1;
}
