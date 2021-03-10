//changed by Circe - removing assassin quest.  4/17/04
//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit "/std/vendor.c";

#define SAVEFILE "/d/save/assrings"
#define RINGFILE "/d/laerad/parnelli/cguild/assassin/rings/aring"
#define MAXRINGS 15

void get_ring();

void create() {
    ::create();
    set_nwp("escape",10,500);
   set_nwp("eavesdropping",10,500);
    set_id(({"estal","thief","shopkeeper"}));
    set_name("estal");
    set_short("%^BOLD%^%^BLACK%^Estal the little thief%^RESET%^");
    set_long(
            "Estal is a small little human thief.  He is wearing all black and sits "+
            "here in his little hiding place looking for victims or customers."
            );
    set_body_type("human");
    set_gender("male");
    set_race("human");
    set_size(2);
    set_hd(20,0);
    set_hp(160);
    set_property("no bump",1);
    set_exp(1000);
    set_overall_ac(-5);
    set("aggressive",0);
    set_alignment(6);
    set_emotes(3,({"%^MAGENTA%^Estal says%^RESET%^: I got some good stuff for sale here.","%^MAGENTA%^Estal says%^RESET%^: Welcome to my shop of magical oddities.","Estal shuffles around suspiciously.","Estal peers around the area."}),0);
    add_money("gold",random(50)+100);
     set_nwp("concealment",30);
    set_storage_room("/d/laerad/parnelli/asgard/secret_stor");
}

void init() {
    ::init();
}

void catch_say(string msg){
     ::catch_say(msg);
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   if(!msg || !objectp(who)) return;
   if(strsrch(msg,"ssassin") != -1 || strsrch(msg,"train") != -1 ||
      strsrch(msg,"killer") != -1 || strsrch(msg,"hire") != -1){
      force_me("smirk");
      force_me("say Sorry, I don't need any more friends.");
      return;
   }
}

/*
int train(string str) {
    object obj;
    int align;

    if(obj = present("Xnote",TP)) {
       if(D_BUG_D->assassin_global_break()) {
         TO->force_me("say Sorry, not looking for any more friends.");
          return 1;
       {
       }}
       if(TP->query("is_banned_assassin")) {
          TO->force_me("say Sorry, you've attracted too much attention. No dice.");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^YELLOW%^Rejected from assassin quest (avatar-banned).");
          obj->remove();
          return 1;
        }
        if(TP->query("is_assassin")) {
            TO->force_me("say You've already been through this, what are you doing again?");
            obj->remove();
            return 1;
        }
        if(sizeof(TP->query_kills()) < 90) {
            TO->force_me("say We want only skillful members, you need more training, go away!");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^YELLOW%^Rejected from assassin quest (Not enough kills.).");
            obj->remove();
            return 1;
        }
        if((int)TP->query_lowest_level() < 15) {
            TO->force_me("say We want only skillful members, you need more training, go away!");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^YELLOW%^Rejected from assassin quest (Too low level).");
            obj->remove();
            return 1;
        }
        align = TP->query_alignment();
        if(align == 1 || align == 2 || align == 4 || align == 5 || align == 7 || align == 8 ) {
            TO->force_me("say I just don't think you have the guts to stab a man in the back...sorry...");
            obj->remove();
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^YELLOW%^Rejected from assassin quest (Wrong Alignment).");
            return 1;
        }
        if(TP->is_class("antipaladin") || TP->is_class("cavalier")) {
            TO->force_me("say I don't think this kind of work is really your style...sorry...");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^YELLOW%^Rejected from assassin quest (Knight).");
            obj->remove();
            return 1;
        }
        tell_object(TP,"Estal takes the note from you and looks it over.");
        tell_room(ETP,"Estal takes a note from "+TPQCN+" and looks it over.",TP);
        TO->force_me("say Ok, let's test your skills and see if you are worthy...");
        call_out("test",3,TP);
        obj->remove();
        return 1;
    }
    TO->force_me("say I don't know what you want from me buddy...");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^YELLOW%^Rejected from assassin quest (DMF, no note.).");
    return 1;
}
*/
//took out train to remove the assassin quest.

void test(object who) {
    int pass;
    int intel, dex, wis, str;
    string which;

    if(!objectp(who)) return;
    if(!present(who, ETO)) return;
    TO->force_me("emote throws two apples up into the air.");
    intel = who->query_base_stats("intelligence");
    dex = who->query_base_stats("dexterity");
    wis = who->query_base_stats("wisdom");
    str = who->query_base_stats("strength");
    pass = 1;
    if(who->is_class("bard")) {
        if(intel < 9 || wis < 9 || (intel+wis) < 26) {
            call_out("failing_dagger",3,who,"intelligence");
            return;
        }
        else if(dex < 16) {
            call_out("failing_dagger",3,who,"dexterity");
            return;
        }
        else {
            which = "succeeding_dagger";
        }
    }
    if(who->is_class("cleric")) {
        if(intel < 14) {
            call_out("failing_cleric",3,who,"intelligence");
            return;
        }
        else if(wis < 17) {
            call_out("failing_cleric",3,who,"wisdom");
            return;
        }
        else {
            which = "succeeding_cleric";
        }
    }
    if(who->is_class("mage")) {
        if(intel < 17) {
            call_out("failing_mage",3,who,"intelligence");
            return;
        }
        else if(wis < 14) {
            call_out("failing_mage",3,who,"wisdom");
            return;;
        }
        else {
            which = "succeeding_mage";

        }
    }
    if(who->is_class("fighter")) {
        if(intel < 9 || wis < 9 || intel+wis <26) {
            call_out("failing_dagger",3,who,"intelligence");
            return;

        }
        else if(str < 17) {
            call_out("failing_dagger",3,who,"strength");
            return;
        }
        else {
            which = "succeeding_dagger";
        }
    }
    if(who->is_class("thief")) {
        if(intel < 11 || wis <11 || intel+wis < 27) {
            call_out("failing_dagger",3,who,"intelligence");
            return;
        }
        else if(dex < 17) {
            call_out("failing_dagger",3,who,"dexterity");
            return;
        }
        else {
            which = "succeeding_dagger";
        }
    }
    call_out(which,3,who);
}

void failing_dagger(object who, string stat) {
    if(!present(who, ETO)) return;
    tell_object(who,"You quickly grab a dagger from a table and let it go at an apple!");
    tell_room(ETO,who->query_cap_name()+" quickly grabs a dagger from a table and lets it go at an apple!",who);
    switch(stat) {
        case "strength":
            tell_room(ETO,"%^BOLD%^The dagger slams into a fresh apple and gets stuck.");
            break;
        case "dexterity":
            tell_room(ETO,"%^BOLD%^The dagger flies right past a fresh apple barely nicking a piece off of it.");
            break;
        case "intelligence":
        case "wisdom":
            tell_room(ETO,"%^BOLD%^The dagger slams into a fake wooden apple splitting it into perfect halves!");
            break;
    }
    call_out("failure",5,who);
    return;
}

void failing_mage(object who, string stat) {
    if(!present(who, ETO)) return;
    tell_object(who,"You start casting a spell.");
    tell_object(who,"%^BOLD%^%^YELLOW%^You point the palm of your hand at an apple!");
    tell_object(who,"%^BOLD%^%^RED%^A dart of energy shoots from your hand towards the!");
    tell_room(ETO,who->query_cap_name()+" starts casting a spell.",who);
    tell_room(ETO,"%^BOLD%^%^YELLOW%^"+who->query_cap_name()+" points the palm of "+who->query_possessive()+" hand at an apple!",who);
    tell_room(ETO,"%^BOLD%^%^RED%^A dart of energy shoots from "+who->query_cap_name()+"'s hand towards the apple.",who);
    switch(stat) {
        case "wisdom":
            tell_room(ETO,"%^BOLD%^%^RED%^The dart strikes the edge of a fresh apple, barely damaging it.");
            break;
        case "intelligence":
            tell_room(ETO,"%^BOLD%^%^RED%^The dart blasts into a fake wooden apple, splintering it.");
            break;
    }
    call_out("failure",5,who);
    return;
}

void failing_cleric(object who, string stat) {
    if(!present(who, ETO)) return;
    tell_object(who,"You begin to cast the spell!");
    tell_object(who,"%^BOLD%^%^RED%^You summon your god's wrath to engulf an apple in a pillar of flame!");
    tell_room(ETO,who->query_cap_name()+" mutters a prayer and gestures to the air above an apple!",who);
    switch(stat) {
        case "wisdom":
            tell_room(ETO,"%^BOLD%^%^RED%^A scorching pillar of flame singes the edge of a fresh apple, barely damaging it.");
            break;
        case "intelligence":
            tell_room(ETO,"%^BOLD%^%^RED%^A scorching pillar of flame descends on a fake wooden apple, splintering it.");
            break;
    }
    call_out("failure",5,who);
    return 1;
}

void succeeding_dagger(object who, string str) {
    if(!present(who)) return;
    tell_object(who,"You quickly grab a dagger from a table and let it go at an apple!");
    tell_room(ETO,who->query_cap_name()+" quickly grabs a dagger from a table and lets it go at an apple!",who);
    tell_room(ETO,"%^BOLD%^The dagger slams into a fresh apple splitting it into perfect halves!");
    call_out("success",5,who);
    return;
}

void succeeding_mage(object who, string str) {
    if(!present(who, ETO)) return;
    tell_object(who,"You start casting a spell.");
    tell_object(who,"%^BOLD%^%^YELLOW%^You point the palm of your hand at an apple!");
    tell_object(who,"%^BOLD%^%^RED%^A dart of energy shoots from your hand towards the!");
    tell_room(ETO,who->query_cap_name()+" starts casting a spell.",who);
    tell_room(ETO,"%^BOLD%^%^YELLOW%^"+who->query_cap_name()+" points the palm of "+who->query_possessive()+" hand at an apple!",who);
    tell_room(ETO,"%^BOLD%^%^RED%^A dart of energy shoots from "+who->query_cap_name()+"'s hand towards the apple.",who);
    tell_room(ETO,"%^BOLD%^%^RED%^The dart blasts into a fresh apple, splintering it.");
    call_out("success",5,who);
    return 1;
}

void succeeding_cleric(object who, string str) {
    if(!present(who, ETO)) return;
    tell_object(who,"You begin to cast the spell!");
    tell_object(who,"%^BOLD%^%^RED%^You summon your god's wrath to engulf an apple in a pillar of flame!");
    tell_room(ETO,who->query_cap_name()+" mutters a prayer and gestures to the air above an apple!",who);
    tell_room(ETO,"%^BOLD%^%^RED%^A scorching pillar of flame descends on a fresh apple, splintering it.");
    call_out("success",5,who);
    return 1;
}

void success(object who) {
    if(present(who)) {
        TO->force_me("say Well done! I am happy to add you to our family!");
        who->set("is_assassin",1);
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^RED%^Finished the assassin quest.");
        who->add_search_path("/cmds/assassin");
        who->update_channels();
        get_ring();
        force_me("give ornate silver ring to "+who->query_name());
        who->force_me("save");
        return 1;
    }
}

void failure(object who) {
    if(present(who)) {
        TO->force_me("say I'm sorry but you just don't have what it takes to cut it in our guild.");
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^BLUE%^Failed the assassin quest.");
        return 1;
    }
}

void get_ring() {
    string *key;
    object ring;
    mapping owners;
    int i;

    if(file_exists(SAVEFILE+".o")) {
        ring = new(RINGFILE+"0");
        ring->restore_me(SAVEFILE);
        owners = ring->query_ring_owners();
        key = keys(owners);
        if(sizeof(key) < MAXRINGS) {
            for(i=1;i<MAXRINGS+1;i++) {
                if(member_array(RINGFILE+i,key) != -1) continue;
                if(!random(sizeof(key)+2))
                    ring = new(RINGFILE+i);
                else
                    ring = new(RINGFILE);
                break;
            }
        }
        else {
            ring = new(RINGFILE);
        }
    }
    else {
        if(random(20))
            ring = new(RINGFILE+"1");
        else
            ring = new(RINGFILE);
    }
    ring->move(TO);
    return;
}

