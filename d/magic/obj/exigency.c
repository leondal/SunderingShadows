#include <std.h>
#include <daemons.h>

inherit OBJECT;

string spell, args;
int prof;

void create() {
    ::create();
    set_name("exigency");
    set("id", ({ "remotexoli"}) );
    set("short", "");
    set("long", "");
    set_property("no animate", 1);
    set_weight(0);
}

int clean_up()
{
    if(!objectp(TO)) { return 1; }
    if(objectp(ETO)) { return 1; }
    destruct(TO);
    return 1;
}

void dest_effect()
{
    destruct(TO);
}

void init() {
    ::init();
    add_action("now","now");
}

set_prof(int i) {
    prof = i;
}

int get_prof() {
    return prof;
}

set_spell(string xxx) {
    spell = xxx;
}

set_args(string arg) {
    args = arg;
}


int save_me(string str) {
    return 1;
}
int flag =0;

int now(){
   string where, enclave;
   int mypower,startpower,endpower,bonus,mylevel;
   object place;

    if(flag) return 0;
    flag = 1;
    if(TP->is_class("psion")) {
        if(!TP->is_ok_armour("mage") && !FEATS_D->usable_feat(TP,"armored manifester") && !FEATS_D->usable_feat(TP,"eldritch conditioning")) {
            write("The spell conflicts with your armor and dies");
            call_out("dest_effect",1);
            return 1;
        }
    }
    if(TP->is_class("psywarrior")){
       mylevel = TP->query_guild_level("psywarrior");
    }else{
       mylevel = TP->query_guild_level("psion");
    }

   switch(args){
      case "shadow": case "Shadow": where = "/d/shadow/room/city/portal/foyer.c";
                                    enclave = "Shadow";
                                    break;
      case "tabor": case "Tabor": where = "/d/darkwood/tabor/room/psifoyer.c";
                                    enclave = "Tabor";
                                    break;
      case "seneca": case "Seneca": where = "/d/attaya/newseneca/rooms/psi_foyer.c";
                                    enclave = "Seneca";
                                    break;
      default: where = "/d/shadow/room/city/portal/foyer"; //shouldn't happen, but just in case
                                    enclave = "Shadow";
                                    break;
   }

   if (ETP->query_property("no teleport")) {
      tell_object(TP,"You expend your mental focus but cannot break free of the area's protections.");
      dest_effect();
      return 1;
   }
//teleport proof stuff by ~Circe~ 6/20/08
//new property to be used for areas protected from teleport
//but not foolproof
   place = ETP;
   if(TP->is_class("psywarrior")){
      mylevel = TP->query_guild_level("psywarrior");
   }else{
      mylevel = TP->query_guild_level("psion");
   }
   if(where &&
      (where->query_property("teleport proof") ||
      place->query_property("teleport proof") ||
      !where->is_room())){
      startpower = place->query_property("teleport proof");
      endpower = where->query_property("teleport proof");
      bonus = TP->query_stats("intelligence");
      bonus = bonus -10;
      if((object *)TP->query_attackers() != ({})){
         mypower = mylevel + bonus + random(6);
      }else{
         mypower = mylevel + bonus + random(6) + 5;
//making it easier to teleport out if you aren't in combat
      }
      if((mypower < startpower) || (mypower < endpower)){
         tell_object(TP,"You expend your mental focus but cannot break free of the area's protections.");
         dest_effect();
         return 1;
      }
   }
   tell_object(TP,"%^RESET%^%^MAGENTA%^You call upon your mental reserves and "
      "make a quick getaway to the "+enclave+" enclave!\n%^CYAN%^You feel a rush "
      "of %^BOLD%^cold air %^RESET%^%^CYAN%^raising goose bumps on your flesh "
      "before the world shifts around you!%^RESET%^");
   tell_room(EETO,"%^RESET%^%^CYAN%^A rush of %^BOLD%^cold air %^RESET%^%^CYAN%^"
      "buffets you before the %^BOLD%^air %^RESET%^%^CYAN%^around "+TPQCN+" %^BOLD%^"
      "s%^RESET%^%^CYAN%^h%^MAGENTA%^i%^BOLD%^mm%^RESET%^%^MAGENTA%^e%^CYAN%^r%^BOLD%^"
      "s%^RESET%^%^CYAN%^.\n%^MAGENTA%^When the air stills, "+TPQCN+" is gone!%^RESET%^", ({TP}));
   tell_room(find_object_or_load(where),"%^RESET%^%^MAGENTA%^The air nearby %^BOLD%^%^CYAN%^"
      "s%^RESET%^%^CYAN%^h%^MAGENTA%^i%^BOLD%^mm%^RESET%^%^MAGENTA%^e%^CYAN%^r%^BOLD%^"
      "s%^RESET%^%^MAGENTA%^ with i%^BOLD%^r%^RESET%^%^MAGENTA%^id%^CYAN%^e%^MAGENTA%^s"
      "c%^BOLD%^%^CYAN%^e%^RESET%^%^MAGENTA%^nce.\n%^RESET%^%^CYAN%^When it stills, "
      ""+TPQCN+" is standing before you!%^RESET%^",TP);
   TP->move_player(where);
   tell_object(TP,"%^RESET%^%^MAGENTA%^Faint spots of i%^BOLD%^r%^RESET%^%^MAGENTA%^"
      "id%^CYAN%^e%^MAGENTA%^sc%^BOLD%^%^CYAN%^e%^RESET%^%^MAGENTA%^nce cloud your "
      "vision briefly.\n%^BOLD%^When they clear, you are at the "+enclave+" enclave!%^RESET%^");
   call_out("dest_effect",1);
   return 1;
}

int drop() {
   return 1;
}

int is_detectable() { return 0; }
int query_invis() { return 1; }
