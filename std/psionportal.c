// devising a general template for portals as they're getting semi-prolific. Nienne, 02/10.
// the inherit will need an NPC present with an ID "portalpsion", and at least one location set in create(), to function.
#include <std.h>
#include <daemons.h>
inherit CVAULT;

mapping portalallocs;
int do_portal(string location, object player);
// example of the below: add_location("tonovi",10,100,"/d/tonovi/xx")
// this gives a portal to tonovi, L10 and up can use, at 100g cost per level, which drops you in /d/tonovi/xx
int add_location(string thename, int minlevel, int therate, int thedest);

void create(){
    ::create();
    portalallocs = ([]);
}

void init(){
    ::init();
    add_action("get_portal","buy");
    add_action("get_price","ask");
    add_action("read_sign","read");
}

int get_price(string str) {
    int mylevel, myrate, mymin;
    string location, *mylocs;
    object mynomad;
    if(!present("portalpsion")) return notify_fail("There's noone here for you to ask.\n");
    if(TP->query_bound() || TP->query_unconscious() || TP->query_gagged()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
    }
    if(TP->query_blind()) return notify_fail("You can't even see who to ask!\n");
    mynomad = present("portalpsion");
    if(sizeof(mynomad->query_attackers()) > 0) return notify_fail("The psion is too distracted right now.\n");
    if(sizeof(TP->query_attackers()) > 0) return notify_fail("You are too distracted right now.\n");
    if(!str) return notify_fail("You need to ask for a location.\n");
    if((sscanf(str,"the price of %s",location) != 1)) return notify_fail("You need to ask for a location.\n");
    if(portalallocs == ([])) return notify_fail("There are no destinations set! Contact a wiz!\n");
    mylocs = keys(portalallocs);
    if(member_array(location,mylocs) == -1) return notify_fail("That's not a valid location!\n");
    if(avatarp(TP)) {
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^ You lucky imm, it won't cost you anything.");
      return 1;
    }

    mylevel = TP->query_level();
    myrate = (int)portalallocs[location]["rate"] * mylevel;
    mymin = (int)portalallocs[location]["minlevel"];
    if(location == "enclave" && (TP->is_class("psion") || TP->is_class("psywarrior"))) myrate = 0;
    if(mylevel < mymin) {
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^ I'm afraid you're too inexperienced yet to "
"travel to "+location+".");
      return 1;
    }
    tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^ It will cost you "+myrate+" gold to travel to "
+location+".");
    return 1;
}

int get_portal(string str) {
    int mylevel, myrate, mymin;
    string location, *mylocs;
    object mynomad;
    if(!present("portalpsion")) return notify_fail("There's noone here for you to ask.\n");
    if(TP->query_bound() || TP->query_unconscious() || TP->query_gagged()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
    }
    if(TP->query_blind()) return notify_fail("You can't even see who to ask!\n");
    if(TP->query_invis() && !avatarp(TP)) return notify_fail("Noone can see you!\n");
    mynomad = present("portalpsion");
    if(sizeof(mynomad->query_attackers()) > 0) return notify_fail("The psion is too distracted right now.\n");
    if(sizeof(TP->query_attackers()) > 0) return notify_fail("You are too distracted right now.\n");
    if(!str) return notify_fail("You need to ask for a location.\n");
    if((sscanf(str,"portal to %s",location) != 1)) return notify_fail("You need to ask for a location.\n");
    if(portalallocs == ([])) return notify_fail("There are no destinations set! Contact a wiz!\n");
    mylocs = keys(portalallocs);
    if(member_array(location,mylocs) == -1) return notify_fail("That's not a valid location!\n");

    mylevel = TP->query_level();
    myrate = (int)portalallocs[location]["rate"] * mylevel;
    mymin = (int)portalallocs[location]["minlevel"];
    if(avatarp(TP)) {
      mymin = 0;
      myrate = 0;
    }
    if(location == "enclave" && (TP->is_class("psion") || TP->is_class("psywarrior"))) myrate = 0;
    if(mylevel < mymin) {
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^ I'm afraid you're too inexperienced yet to "
"travel to "+location+".");
      return 1;
    }
    if(!(int)TP->query_funds("gold",myrate)) {
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^ I'm afraid you don't have enough money. You "
"will need "+myrate+" gold to travel to "+location+".");
      return 1;
    }
    TP->use_funds("gold",myrate);
    if(!TP->query_true_invis()) tell_room(TO,"%^CYAN%^The nomad makes a motion to the circle, and the three pillars begin "
"to %^WHITE%^glow%^CYAN%^ softly.%^RESET%^");
    call_out("do_portal",5,location,TP);
    return 1;
}

int do_portal(string location, object player) {
    string mylocation;
    object mylocation2, mynomad;
    if(!objectp(TO)) return 1;
    if(!present("portalpsion")) {
      tell_room(TO,"%^CYAN%^The spell fails without its caster present.%^RESET%^");
      return 1;
    }
    if(!objectp(player) || !present(player)) {
      tell_room(TO,"%^CYAN%^The nomad steps back again, as the spell fails without its subject present.%^RESET%^");
      return 1;
    }
    mynomad = present("portalpsion");
    if(sizeof(mynomad->query_attackers()) > 0) {
      tell_room(TO,"%^CYAN%^The spell fails, with its caster too distracted to maintain it.%^RESET%^");
      return 1;
    }
    if(sizeof(TP->query_attackers()) > 0) {
      tell_room(TO,"%^CYAN%^The spell fails, with its subject too disturbed to maintain it.%^RESET%^");
      return 1;
    }
    mylocation = (int)portalallocs[location]["destination"];
    mylocation2 = find_object_or_load(mylocation);
    if(!player->query_true_invis()) {
      tell_room(TO,"%^CYAN%^A sudden %^BOLD%^%^WHITE%^flash%^RESET%^%^CYAN%^ of light encloses the circle, and "
+player->QCN+" is no longer there!%^RESET%^",player);
      tell_room(mylocation2,"%^CYAN%^A sudden pulse of %^BOLD%^%^WHITE%^light %^RESET%^%^CYAN%^appears before you, "
"leaving behind the form of "+player->QCN+"!%^RESET%^",player);
      tell_object(player,"%^CYAN%^A sudden %^BOLD%^%^WHITE%^flash%^RESET%^ %^CYAN%^lights up your vision, and you find "
"yourself elsewhere!%^RESET%^");
    }
    player->move_player(mylocation2);
    return 1;
}

int add_location(string thename, int minlevel, int therate, int thedest) {
   if(thename == "" || thedest == "" || !thedest || !thename) return 0;
   if(!portalallocs) portalallocs = ([]);
   thename = lower_case(thename);
   portalallocs[thename] = ([ "minlevel" : minlevel, "rate" : therate, "destination" : thedest ]);
   return 1;
}

int read_sign(string str) {
   string mystring;
   if(str != "sign") return 0;
   if(!portalallocs) portalallocs = ([]);
   tell_object(TP,"%^BOLD%^%^BLUE%^%^The words on the sign seem to shift and change into legible characters as you look "
"at them.%^RESET%^");
   if(portalallocs == ([])) {
     tell_object(TP,"%^RESET%^This portal has no destinations set, please contact a wiz!");
     return 1;
   }
   mystring = implode(keys(portalallocs),", ");
   tell_object(TP,"%^RESET%^You may %^YELLOW%^buy portal to%^RESET%^ a city from here: %^YELLOW%^"+mystring+"%^RESET%^.  "
"Simply %^YELLOW%^ask the price of%^RESET%^ a portal to any of these places, to find out what it would cost to travel "
"there, or %^YELLOW%^buy portal to%^RESET%^ whichever you wish to visit.");
   return 1;
}
