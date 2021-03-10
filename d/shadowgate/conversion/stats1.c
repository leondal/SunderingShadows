#include <std.h>
inherit ROOM;

void newsg(object targ,int num);

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("no starve",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);

    set_name("beyond the haze");
    set_short("%^BOLD%^%^BLUE%^Beyond the Haze%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^Beyond the Haze%^RESET%^\n"+
        "%^BOLD%^%^CYAN%^You settle into reality once more, "+
        "but find yourself changed.  You realize that you can "+
        "reshape yourself into anything.\n\n"+
        "%^YELLOW%^Welcome to stat reallocation. Due to the "+
        "changed racial bonuses to 3.5e, everyone will have the chance to "+
        "re-allocate their total stat points as they desire.  "+
        "Please use the following commands:%^RESET%^\n\n"+
        "%^RESET%^%^MAGENTA%^<assign stat #> %^RESET%^(eg/ <assign strength 18>)\n"+
        "%^RESET%^%^CYAN%^<check stats>\n"+
        "%^RESET%^%^WHITE%^<finish>%^RESET%^ when you are happy to allocate your stats.\n\n"+
        "%^YELLOW%^You will be able to allocate your base stat "+
        "line, including any you have bought to date.%^RESET%^\n"+
        "%^BOLD%^%^RED%^Important:%^WHITE%^ please apply stats as though you are "+
        "rolling in creation (plus stats bought through levelling). Racial and age "+
        "modifiers will kick in of their own accord %^RED%^after%^WHITE%^ you are "+
        "done here.");

    set_smell("default","\nThere is nothing within the haze "+
        "to smell.");
    set_listen("default","You can hear nothing within the "+
        "haze.");
    set_exits((["out":"/d/shadowgate/conversion/conversion3"]));
    set_pre_exit_functions(({"out"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
    if(!objectp(TP)) { return 0; }
    if(avatarp(TP)) { return 1; }
    if(!TP->query_property("finished2")) {
        tell_object(TP,"You haven't finalized your stats.  Type "
            "<finish> if you are done setting them.");
        return 0; 
    }
    TP->set("new_stat_type2",1);
    return 1;
}

void init() {
    ::init();
    add_action("finish_me","finish");
    add_action("stat_set","assign");
    add_action("summary_fun","check");
}

void confirm_finish(string str,object ob) {
    if(!objectp(ob)) return;
    if(str != "yes") {
        tell_object(ob,"Aborting...");
        return;
    }
    tell_object(ob,"Finishing...  Your character can now leave the room "
        "and venture back into the land of Shadowgate.");
    ob->set_stats("strength",(int)TP->query_property("tempstr"));
    ob->set_stats("dexterity",(int)TP->query_property("tempdex"));
    ob->set_stats("constitution",(int)TP->query_property("tempcon"));
    ob->set_stats("intelligence",(int)TP->query_property("tempint"));
    ob->set_stats("wisdom",(int)TP->query_property("tempwis"));
    ob->set_stats("charisma",(int)TP->query_property("tempcha"));
    ob->set_property("finished2",1);
    return;
}

void finish_me(string str) {
    int STR, DEX, CON, INT, WIS, CHA, mytotal, gained, myflag;
    if(!objectp(TP)) return;
    if(!TP->query("new_class_type")) return;
    if(TP->query_property("finished2")) {
        tell_object(TP,"You are already finished with your character.");
        return;
    }

    STR = (int)TP->query_property("tempstr"); if(!STR) myflag = 1;
    DEX = (int)TP->query_property("tempdex"); if(!DEX) myflag = 1;
    CON = (int)TP->query_property("tempcon"); if(!CON) myflag = 1;
    INT = (int)TP->query_property("tempint"); if(!INT) myflag = 1;
    WIS = (int)TP->query_property("tempwis"); if(!WIS) myflag = 1;
    CHA = (int)TP->query_property("tempcha"); if(!CHA) myflag = 1;
    if(myflag) {
        tell_object(TP,"One or more of your stats is not set.  Please <check stats> and fix before you can leave.");
        return;
    }
    mytotal = STR + DEX + CON + INT + WIS + CHA;
    gained = (int)TP->query("stat_points_gained")+92;
    if(mytotal > gained) {
        tell_object(TP,"You have more than your possible "+gained+" stats.  Please <check stats> and fix this.");
        return;
    }
    if(mytotal < gained) {
        tell_object(TP,"You have assigned less than your possible "+gained+" stats.  You can adjust this before leaving "
"if you wish, please do not confirm with <yes> if you wish to make further changes.");
    }
    tell_object(TP,"%^RED%^  Are you sure that you are finished?  Moving stats "
        "will cost experience in future, so be sure you are happy with them.  "
        "Please use <check stats> to ensure they are as you intend them to be.");
    tell_object(TP,"Enter <yes> to confirm that you are finished, enter anything "
        "else to abort.");
    input_to("confirm_finish",TP);
    return;
}

void summon_player(object ob) {
    ob->move(TO);
    ob->force_me("look");
}

void summon_me(object ob) {
    call_out("summon_player",0,ob);
}

int stat_set(string str) {
   int amt, i, STR, DEX, CON, INT, WIS, CHA, mytotal, gained, extra;
   string stat;

   if(!str) {
        tell_object(TP,"Format is <assign statname #>.");
        return 1;
   }
   if(TP->query_property("finished2")) {
        tell_object(TP,"You are already finished with your character.");
        return 1;
   }
   if(sscanf(str,"%s %d", stat, amt) != 2) {
        tell_object(TP,"Format is <assign statname #>.");
        return 1;
   }
   switch(stat) {
     case "strength": case "str": i = 0; break;
     case "dexterity": case "dex": i = 1; break;
     case "constitution": case "con": i = 2; break;
     case "intelligence": case "int": i = 3; break;
     case "wisdom": case "wis": i = 4; break;
     case "charisma": case "cha": i = 5; break;
     default: return notify_fail("Bad stat. Please use full stat name.\n"); break;
   }
   if(amt < 6 || amt > 25) {
     tell_object(TP,"%^YELLOW%^Base-line stats must lie between 6 and 25.%^RESET%^");
     return 1;
   }
   if(i != 0) { STR = (int)TP->query_property("tempstr")-18; if(STR<0) STR = 0; }
   if(i != 1) { DEX = (int)TP->query_property("tempdex")-18; if(DEX<0) DEX = 0; }
   if(i != 2) { CON = (int)TP->query_property("tempcon")-18; if(CON<0) CON = 0; }
   if(i != 3) { INT = (int)TP->query_property("tempint")-18; if(INT<0) INT = 0; }
   if(i != 4) { WIS = (int)TP->query_property("tempwis")-18; if(WIS<0) WIS = 0; }
   if(i != 5) { CHA = (int)TP->query_property("tempcha")-18; if(CHA<0) CHA = 0; }
   mytotal = STR + DEX + CON + INT + WIS + CHA;
   gained = (int)TP->query("stat_points_gained");
   extra = amt-18;
   if(extra<0) extra = 0;
   if(mytotal+extra > gained) {
     tell_object(TP,"%^YELLOW%^Assigning "+amt+" to "+stat+" will exceed your base stats maximum (18 per stat) by more "
"than the "+gained+" points you have gained in levelling.%^RESET%^");
     return 1;
   }
   if(i != 0) STR = (int)TP->query_property("tempstr"); else STR = amt;
   if(i != 1) DEX = (int)TP->query_property("tempdex"); else DEX = amt;
   if(i != 2) CON = (int)TP->query_property("tempcon"); else CON = amt;
   if(i != 3) INT = (int)TP->query_property("tempint"); else INT = amt;
   if(i != 4) WIS = (int)TP->query_property("tempwis"); else WIS = amt;
   if(i != 5) CHA = (int)TP->query_property("tempcha"); else CHA = amt;
   mytotal = STR + DEX + CON + INT + WIS + CHA;
   gained = gained+92;
   if(mytotal > gained) {
     tell_object(TP,"%^YELLOW%^Assigning "+amt+" to "+stat+" will exceed your total stats by more than the "+gained+
" total points at your disposal.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^YELLOW%^You assign your "+stat+" to "+amt+".%^RESET%^");
   switch(i) {
     case 0: TP->remove_property("tempstr"); TP->set_property("tempstr",amt); break;
     case 1: TP->remove_property("tempdex"); TP->set_property("tempdex",amt); break;
     case 2: TP->remove_property("tempcon"); TP->set_property("tempcon",amt); break;
     case 3: TP->remove_property("tempint"); TP->set_property("tempint",amt); break;
     case 4: TP->remove_property("tempwis"); TP->set_property("tempwis",amt); break;
     case 5: TP->remove_property("tempcha"); TP->set_property("tempcha",amt); break;
   }
   return 1;
}

int summary_fun(string str) {
   int STR, DEX, CON, INT, WIS, CHA, thetotal, mytotal;
   string feedback;
   if(!str) return 0;
   if(str != "stats") return 0;
   thetotal = 92+(int)TP->query("stat_points_gained");
   STR = (int)TP->query_property("tempstr"); if(!STR) STR = 0;
   DEX = (int)TP->query_property("tempdex"); if(!DEX) DEX = 0;
   CON = (int)TP->query_property("tempcon"); if(!CON) CON = 0;
   INT = (int)TP->query_property("tempint"); if(!INT) INT = 0;
   WIS = (int)TP->query_property("tempwis"); if(!WIS) WIS = 0;
   CHA = (int)TP->query_property("tempcha"); if(!CHA) CHA = 0;
   mytotal = STR + DEX + CON + INT + WIS + CHA;
   feedback = "%^YELLOW%^You have assigned your stats as follows:\n";
   feedback += "%^BOLD%^%^CYAN%^str "+STR+", dex "+DEX+", con "+CON+", int "+INT+", wis "+WIS+", cha "+CHA+".%^RESET%^\n";
   feedback += "%^YELLOW%^You have assigned "+mytotal+" of your potential "+thetotal+" base stats.\n";
   feedback += "%^BOLD%^%^CYAN%^Remember: this will be your base stat line, %^RED%^before %^CYAN%^any age mods (see help "
"age).\n";
   tell_object(TP,feedback);
   return 1;
}