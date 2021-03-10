#include <std.h>
#include <daemons.h>
inherit ROOM;

int do_portal(object player);

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("Inside the marble rotunda");
    set_short("%^BOLD%^%^WHITE%^Inside the marble rotunda");
    set_long("%^BOLD%^%^WHITE%^Inside the marble rotunda%^RESET%^\n"
"This rotunda has been constructed from pure %^BOLD%^white marble%^RESET%^.  "
"The walls have been formed from perfectly cut stones, all intersecting "
"flawlessly to leave no holes or gaps between each.  The room is also a "
"perfect circle, with a raised dias dominating the centre of the room.  On "
"that dias is a%^BOLD%^%^BLACK%^ complicated carving %^RESET%^in the floor of "
"a circle, several feet in diameter.  At evenly-spaced intervals around the "
"circle are three small pillars, each seemingly embedded within the marble "
"itself, and carved from what appear to be varied kinds of precious rock and "
"gem in shades of %^BLUE%^blue%^RESET%^, %^BOLD%^white %^RESET%^and "
"%^BOLD%^%^BLACK%^black%^RESET%^.  The room is bright and airy, though there "
"are no obvious sources of light.  A single broad doorway is set into the "
"wall, leading into a hallway beyond.  Beside the doorway, a small "
"%^ORANGE%^sign %^RESET%^has been tacked up and printed in clear writing.\n");
    set_listen("default","The soft murmur of chanting voices drifts around you.");
    set_smell("default","The dry marble offers only a mild dry scent to the air.");
    set_items(([
      ({"circle","dust","carving"}):"A perfect circle has been carved "
"into the %^BOLD%^%^WHITE%^marble floor%^RESET%^, and filled with some kind "
"of %^BOLD%^gli%^RESET%^t%^BOLD%^ter%^RESET%^i%^BOLD%^ng %^RESET%^dust, "
"perhaps for some magical reason, or perhaps only to make it more visible "
"against the %^BOLD%^%^WHITE%^pure white %^RESET%^of the stone it is carved "
"into. At even intervals around its circumference are three stone pillars, "
"each formed of a different mineral.",
      ({"pillars","gemstones","rocks","stones"}):"Around the "
"circumference of the circle are three pillars, evenly spaced apart. Each "
"appears to be made of some precious mineral, in different hues - one "
"of %^BOLD%^%^BLACK%^obsidian%^RESET%^, one of %^BOLD%^%^WHITE%^moonstone"
"%^RESET%^, and one of %^BLUE%^bl%^CYAN%^u%^BLUE%^e "
"ame%^CYAN%^t%^BLUE%^hyst.%^RESET%^",
      "sign":({"A small %^ORANGE%^sign %^RESET%^has been tacked up by the "
"doorway, printed with clear writing that you could read.","%^ORANGE%^The "
"words on the sign seem to shift and change into legible characters as you "
"look at them.%^RESET%^\n\nYou may %^YELLOW%^buy portal to Shadow%^RESET%^, from where "
"you can travel to other cities. Simply %^YELLOW%^ask the price of "
"Shadow%^RESET%^, to find out what it would cost to travel there.","wizish"}),
    ]));
    set_exits(([
      "north":"/d/attaya/seneca/psion1",
    ]));
}

void reset(){
    if(!present("nomad")) {
      new("/d/shadow/mon/nomad")->move(TO);
      tell_room(TO,"A robed human enters quietly into the room, to "
"stand behind the etched circle.");
    }
}

void init(){
    ::init();
    add_action("get_portal","buy");
    add_action("get_price","ask");
}

int get_price(string str) {
    int mylevel;
    object mynomad;
    if(!present("nomad"))
      return notify_fail("There's noone here for you to buy from.\n");
    if(TP->query_bound() || TP->query_unconscious() || TP->query_gagged()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
    }
    if(TP->query_blind()) {
      tell_object(TP,"You can't even see who to ask!");
      return 1;
    }
    if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"They can't even see you!");
      return 1;
    }
    mynomad = present("nomad");
    if(sizeof(mynomad->query_attackers()) > 0) {
      tell_object(TP,"The nomad is too distracted right now.");
      return 1;
    }
    if(sizeof(TP->query_attackers()) > 0) {
      tell_object(TP,"You are too distracted right now.");
      return 1;
    }
    if (!str) {
      tell_object(TP,"You need to ask for a location.");
      return 1;
    }
    if (str != "the price of shadow" && str != "the price of Shadow") {
      tell_object(TP,"You need to ask for a valid location.");
      return 1;
    }
    mylevel = TP->query_highest_level();
    if(avatarp(TP)) {
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" You lucky imm, it won't cost you anything.");
      return 1;
    }
    switch(mylevel) {
      case 1..24:
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" I'm afraid you're too young yet to travel to Shadow.");
      return 1;
      break;
      case 25..34:
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" It will cost you 2000 gold to travel to Shadow.");
      return 1;
      break;
      case 35..44:
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" It will cost you 2500 gold to travel to Shadow.");
      return 1;
      break;
      case 45..60:
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" It will cost you 3000 gold to travel to Shadow.");
      return 1;
      break;
      default:
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" I'm afraid you've broken something, please contact a wiz.");
      return 1;
      break;
    }
    tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" I'm afraid you've broken something, please contact a wiz.");
    return 1;
}

int get_portal(string str) {
    int mylevel, myprice;
    object mynomad;
    if(!present("nomad"))
      return notify_fail("There's noone here for you to buy from.\n");
    if(TP->query_bound() || TP->query_unconscious() || TP->query_gagged()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
    }
    if(TP->query_blind()) {
      tell_object(TP,"You can't even see who to ask!");
      return 1;
    }
    if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"They can't even see you!");
      return 1;
    }
    mynomad = present("nomad");
    if(sizeof(mynomad->query_attackers()) > 0) {
      tell_object(TP,"The nomad is too distracted right now.");
      return 1;
    }
    if(sizeof(TP->query_attackers()) > 0) {
      tell_object(TP,"You are too distracted right now.");
      return 1;
    }
    if (!str) {
      tell_object(TP,"You need to ask for a location.");
      return 1;
    }
    if (str != "portal to shadow" && str != "portal to Shadow") {
      tell_object(TP,"You need to ask for a valid location.");
      return 1;
    }
    mylevel = TP->query_highest_level();
    if(avatarp(TP)) {
      tell_room(TO,"%^CYAN%^The nomad makes a motion to the circle, and the "
"three pillars begin to %^WHITE%^glow %^CYAN%^softly.%^RESET%^");
      call_out("do_portal",5,TP);
      return 1;
    }
    switch(mylevel) {
      case 1..24: tell_object(TP,"%^CYAN%^The psion's voice reaches your "
"mind:%^RESET%^ I'm afraid you're too young yet to travel to Shadow.");
      return 1; break;
      case 25..34: myprice = 2000; break;
      case 35..44: myprice = 2500; break;
      case 45..60: myprice = 3000; break;
      default:
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" I'm afraid you've broken something, please contact a wiz.");
      return 1;
      break;
    }
    if(!(int)TP->query_funds("gold",myprice)) {
      tell_object(TP,"%^CYAN%^The psion's voice reaches your mind:%^RESET%^"
" I'm afraid you don't have enough money. You will need "+myprice+
" gold to travel to Shadow.");
      return 1;
    }
    TP->use_funds("gold",myprice);
    tell_room(TO,"%^CYAN%^The nomad makes a motion to the circle, and the "
"three pillars begin to %^WHITE%^glow %^CYAN%^softly.%^RESET%^");
    call_out("do_portal",5,TP);
    return 1;
}

int do_portal(object player) {
    object mylocation2, mynomad;
    if(!objectp(TO)) return 1;
    if(!present("nomad")) {
      tell_room(TO,"%^CYAN%^The spell fails without its caster "
"present.%^RESET%^");
      return 1;
    }
    if(!objectp(player) || !present(player)) {
      tell_room(TO,"%^CYAN%^The nomad steps back again, as the spell fails "
"without its focus present.%^RESET%^");
      return 1;
    }
    mynomad = present("nomad");
    if(sizeof(mynomad->query_attackers()) > 0) {
      tell_room(TO,"%^CYAN%^The spell fails, with its caster too distracted "
"to maintain it.%^RESET%^");
      return 1;
    }
    if(sizeof(TP->query_attackers()) > 0) {
      tell_room(TO,"%^CYAN%^The spell fails, with its subject too disturbed "
"to maintain it.%^RESET%^");
      return 1;
    }
    mylocation2 = find_object_or_load("/d/darkwood/room/road1");
    tell_room(TO,"%^CYAN%^A sudden %^BOLD%^%^WHITE%^flash %^RESET%^%^CYAN%^of "
"light encloses the circle, and "+player->QCN+" is no longer "
"there!%^RESET%^",player);
    tell_object(player,"%^CYAN%^A sudden %^BOLD%^%^WHITE%^flash "
"%^RESET%^%^CYAN%^lights up your vision, and you find yourself "
"elsewhere!%^RESET%^");
    tell_room(mylocation2,"%^CYAN%^A sudden pulse of %^BOLD%^%^WHITE%^light "
"%^RESET%^%^CYAN%^appears before you, leaving behind the form of "
+player->QCN+"!%^RESET%^",player);
    player->move_player(mylocation2);
    return 1;
}
