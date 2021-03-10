#include <std.h>
#include <daemons.h>
#include <move.h>
inherit OBJECT;

int dart_num;
string mastery_list;
void goblinscream();

int set_darts(int x) {
    return dart_num = x;
}

int query_darts() { return dart_num; }

string *query_mastery_list() { return
SAVE_D->query_array(mastery_list+"_darts_mastery_list"); }

string set_mastery_list(string str) { mastery_list = str; }

void reset() {
    ::reset();
    if(dart_num < 5) {
        dart_num += 5 - dart_num;
    }
}

void create() {
    ::create();
    set_weight(1000);
    set_short("A dartboard");
    set_name("dartboard");
    set_id(({"board","dartboard"}));
    set_property("no animate",1);
    set_long((:TO,"long":));
    dart_num = 5;
}

string long() {
    string tmp;
    tmp = "%^RESET%^%^MAGENTA%^This is a dartboard with alternating %^RED%^red %^MAGENTA%^and %^RESET%^white "
"%^MAGENTA%^rings.  Each is worth more points as far as the centre, which is known as a bulls-eye.  Unlike a "
"normal dartboard, however, this one has a still-living %^GREEN%^gob%^ORANGE%^li%^GREEN%^n %^MAGENTA%^secured "
"to it across the centre.  It squirms wildly, a pained look on its face as various patrons aim wickedly-"
"sharp dart pins at it.%^RESET%^\n\n";
    if(dart_num <= 0) {
      tmp += "%^BOLD%^%^WHITE%^The dartboard is clear.  You can <throw dart> to play the game, if you have one.%^RESET%^";
    }
    else {
      if(dart_num >= 5) {
        tmp += "%^BOLD%^%^WHITE%^The dartboard is full of darts!  Perhaps you can <retrieve dart> to clean it "
"up a bit?  You can <throw dart> to play the game, if you have one.%^RESET%^";
      }
      else {
        tmp += "%^BOLD%^%^WHITE%^There are some darts on the dartboard.  You can clean it up a bit by <retrieve "
"dart>. You count: umm... "+dart_num+" of them!  You can <throw dart> to play the game, if you have one.%^RESET%^";
      }
    }
    return tmp;
}

void init() {
    ::init();
    add_action("throw_func","throw");
    add_action("retrieve_func","retrieve");
}

int throw_func(string str) {
    int dskill,hit,score,gain;
    object obj;

    if(!str || str != "dart") {
        return 0;
    }

    if(!obj = present("gamedart999",TP)) {
        tell_object(TP,"You don't have a dart!");
        return 1;
    }

    if(dart_num >= 5) {
        tell_object(TP,"The dartboard has too many darts on it!");
        return 1;
    }
    if(TP->query_paralyzed()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    dskill = TP->query("darts skill");
    hit = roll_dice(10,100);
    score = roll_dice(1,10);
    gain = roll_dice(1,2);

    tell_object(TP,"You throw a dart at the dartboard!");
    tell_room(ETO,TPQCN+" throws a dart at the dartboard!",TP);
    TP->set_paralyzed(1,"You need to regain your posture first.");

    if((dskill + 400) > hit) {
        tell_object(TP,"Your dart lands on the dartboard!");
        tell_room(ETO,TPQCN+"'s dart hits the dartboard!",TP);
        dart_num++;
        obj->remove();
        if(dskill >= 1000) {
          if(score >= 2) {
            tell_object(TP,"Your dart hits the bull's-eye!");
            tell_room(ETO,"The dart hits the bull's-eye!",TP);
            if(!random(4)) goblinscream();
          }
          else {
            tell_object(TP,"Your dart hits the "+(score+8)*10+" ring!");
            tell_room(ETO,"The dart hits the "+(score+8)*10+" ring!",TP);
            if(!random(12)) goblinscream();
          }
        }
        if(dskill >= 950 && dskill < 1000) {
          if(!random(20)){
            TP->set("darts skill",gain+dskill);
            if((gain+dskill) >= 1000) {
              if(!mastery_list || mastery_list == "shadow_fighter_guild") 
                present("mastery list")->add_master(TPQN);
              else {
                if(member_array(TPQN,SAVE_D->query_array(mastery_list+"_darts_mastery_list")) == -1)
                  SAVE_D->set_value(mastery_list+"_darts_mastery_list",TPQN);
              }
              tell_object(TP,"%^YELLOW%^You just achieved mastery in darts! Congratulations!%^RESET%^");
              message("broadcast",""+TPQCN+" just achieved mastery in darts!",users(),TP);
            }
          }
          if(score >= 3) {
            tell_object(TP,"Your dart hits the bull's-eye!");
            tell_room(ETO,"The dart hits the bull's-eye!",TP);
            if(!random(4)) goblinscream();
          }
          else {
            tell_object(TP,"Your dart hits the "+(score+7)*10+" ring!");
            tell_room(ETO,"The dart hits the "+(score+7)*10+" ring!",TP);
            if(!random(12)) goblinscream();
          }
        }
        if(dskill >= 750 && dskill < 950) {
          if(!random(15)) TP->set("darts skill",gain+dskill);
          if(score >= 5) {
            tell_object(TP,"Your dart hits the bull's-eye!");
            tell_room(ETO,"The dart hits the bull's-eye!",TP);
            if(!random(4)) goblinscream();
          }
          else {
            tell_object(TP,"Your dart hits the "+(score+5)*10+" ring!");
            tell_room(ETO,"The dart hits the "+(score+5)*10+" ring!",TP);
            if(!random(12)) goblinscream();
          }
        }
        if(dskill >= 350 && dskill < 750) {
          if(!random(8)) TP->set("darts skill",gain+dskill);
          if(score >= 8) {
            tell_object(TP,"Your dart hits the bull's-eye!");
            tell_room(ETO,"The dart hits the bull's-eye!",TP);
            if(!random(4)) goblinscream();
          }
          else {
            tell_object(TP,"Your dart hits the "+(score+2)*10+" ring!");
            tell_room(ETO,"The dart hits the "+(score+2)*10+" ring!",TP);
            if(!random(12)) goblinscream();
          }
        }
        if(dskill >= 50 && dskill < 350) {
          if(!random(3)) TP->set("darts skill",gain+dskill);
          if(score == 10) {
            tell_object(TP,"Your dart hits the bull's-eye!");
            tell_room(ETO,"The dart hits the bull's-eye!",TP);
            if(!random(4)) goblinscream();
          }
          else {
            tell_object(TP,"Your dart hits the "+(score)*10+" ring!");
            tell_room(ETO,"The dart hits the "+(score)*10+" ring!",TP);
            if(!random(12)) goblinscream();
          }
        }
        if(dskill < 50) {
          if(random(2)) TP->set("darts skill",gain+dskill);
          if(random(2)) {
            tell_object(TP,"Your dart lands outside the rings!");
            tell_room(ETO,"The dart lands outside the rings!",TP);
          }
          else if(score == 10) {
            tell_object(TP,"Your dart hits the bull's-eye!");
            tell_room(ETO,"The dart hits the bull's-eye!",TP);
            if(!random(4)) goblinscream();
          }
          else {
            tell_object(TP,"Your dart hits the "+(score)*10+" ring!");
            tell_room(ETO,"The dart hits the "+(score)*10+" ring!",TP);
            if(!random(12)) goblinscream();
          }
        }
    }
    else {
        if(random(5)) TP->set("darts skill",gain+dskill);
        tell_object(TP,"Your dart fails to hit the dartboard and drops on the floor.");
        tell_room(ETO,"The dart fails to hit the dartboard and drops on the floor.");
        obj->move(ETO);
    }
    return 1;
}

int retrieve_func(string str) {
    object dart;
    if(!str || (str != "dart")) {
        tell_object(TP,"Try retrieve dart?");
        return 1;
    }
    if(dart_num <= 0) {
        tell_object(TP,"There is no dart on the board!");
        return 1;
    }
    if(random(8)) {
      tell_object(TP,"You retrieve a dart from the dartboard.");
      tell_room(ETO,TPQCN+" retrieves a dart from the dartboard.",TP);
    }
    else {
      tell_object(TP,"%^GREEN%^The goblin on the dartboard squeals as you retrieve a dart from his flesh.");
      tell_room(ETO,"%^GREEN%^The goblin on the dartboard squeals as "+TPQCN+" %^RESET%^%^GREEN%^retrieves a "
"dart from its flesh.",TP);
    }
    dart_num--;
    dart = new("/d/shadow/room/city/cguild/fighter/dart");
    if(dart->move(TP) != MOVE_OK) {
        tell_object(TP,"You drop the dart!");
        tell_room(ETO,TPQCN+" drops the dart!",TP);
        dart->move(ETP);
    }
    return 1;
}

void goblinscream() {
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   switch(random(300)) {
     case 0..129:
       tell_room(ETO,"%^GREEN%^The goblin screeches loudly as the dart sinks into its flesh!%^RESET%^");
     break;
     case 130..229:
       tell_room(ETO,"%^ORANGE%^Your dart hits square into the goblin, who lets out a howl of protest!"
"%^RESET%^");
     break;
     case 230..290:
       tell_room(ETO,"%^RED%^A cheer goes up from a patron across the way as your dart thuds into the goblin "
"on the board!%^RESET%^");
     break;
     case 291..299:
       tell_room(ETO,"%^YELLOW%^An animalistic scream tears forth from the goblin as the dart sinks into his "
"eye, and horrific gore sprays forth!%^RESET%^");
     break;
   }
}