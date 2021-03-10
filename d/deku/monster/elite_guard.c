//Guards for Ruther - Saide
#include <std.h>
#include <daemons.h>
inherit NPC;

string master, findings;

void create() {
    object ob;
    ::create();
    set_name("guard");
    set_id( ({ "guard"  }) );
    set_race("human");
    set_gender("male");
    set_short("A guard decked out in black chain");
    set_long((:TO,"long_desc":));
    set_alignment(3);
    set_hd(15 + random(4),8);
    set_stats("intelligence",13);
    set_stats("wisdom",13);
    set_stats("strength",17 + random(2));
    set_stats("charisma",11);
    set_stats("dexterity",16);
    set_stats("constitution",14);
    set_hp(query_hd() * 8 + random(31));
    new("/d/common/obj/weapon/longsword")->move(TO);
    command("wield longsword");
    new("/d/common/obj/weapon/shortsword")->move(TO);
    command("wield sword");
    ob = new("/d/common/obj/armour/chain");
    ob->set_short("A suit of darkened chainmail");
    ob->set_long("%^BOLD%^%^BLACK%^This armor is made from "+
    "interlocking rings of darkened metal.  This mail is "+
    "quite a bit thinner than normal chainmail and appears "+
    "to be of equal thickness throughout.  A thick layer "+
    "of fabric rests beneath the chain to make wearing this "+
    "armor as comfortable as possible.  A pattern of shiny "+
    "black on the front of the armor depicts an opened hand.");
    ob->set_weight(30);
    if(!random(2)) {
    ob->set_property("enchantment",1);
    ob->set_ac(4);
    }
    ob->move(TO);
    command("wear chain");
    set_exp(query_hp() * 10);
    add_attack_bonus(8);
    master = 0;
    findings = 0;
} 

void init() {
    add_action("show_em","point");
}

int show_em(string str) {
    string what;
    if(!str) return 0;
    if(sscanf(str,"at %s",what) != 1) {
        return 0;
    }
    TP->force_me("emote motions for the guard to look at the "+what);
    if((string)TP->query_name() != master) {
        TO->force_me("say ya can point at whatever ya like, I aint "+
        "payin' no mind");
        return 1;
    }
    
    if(member_array(what,keys(ETO->query_items())) == -1 
    && !present(what,ETO)) {
        TO->force_me("shake");
        TO->force_me("say aint nothin' like that 'ere that I "+
        "can see.");
        return 1;
    }
    TO->force_me("emoteat "+TP->query_name()+" nods to $N and then "+
    "looks at the "+what+" carefully");
    if(!(ETO->query_buried_name(what))) { 
        TO->force_me("say aint nothin' there convincing me of "+
        "anyone being dead.");
        return 1;
    }
    TO->force_me("say looks like ya done found "+ETO->query_buried_name(what)+
    "'s resting place.");
    TO->force_me("emote nods grimly");
    findings = ETO->query_buried_name(what);
    return 1;
}


void set_master(string str) {
    master = str;
}
void query_master() {
    return master;
}
void query_findings() {
    return findings;
}

void catch_say(string msg){
    ::catch_say(msg);
    if(interactive(TP)) {
        call_out("response",1,msg,TP);
    }
}

void do_report_findings(object who, object mast) {
    command("say we done found "+findings+" dead, aint no "+
    "life left.");
    command("shake");
    who->do_reward("dead",findings,mast);
}

void fail() {
    command("say nope, I don't listen to ya.");
}

void response(string msg, object ob){   
    object ob1;
    int *fines, x;
    command("speak wizish");
    if(query_master() == "") return;
    if(!objectp(ob)) return;
    if(strsrch(msg,"halt") != -1 || strsrch(msg,"wait") != -1) {
        if((string)ob->query_name() == master) {
            command("say i'll be 'ere waitin' for ya.");
            if(!objectp(TO) || !objectp(ob)) return;
            ob->remove_follower(TO);
            return 1;
        }
        fail();
        return 1;
    }
    if(strsrch(msg,"follow") != -1) {
        if((string)ob->query_name() == master) {
            command("nod "+ob->query_name());
            command("say okie, i'll follow ya.");
            if(!objectp(TO) || !objectp(ob)) return;
            ob->add_follower(TO);
            return 1;
        }
        fail();
        return 1;
    }
    if(strsrch(msg,"swim") != -1) {
        if((string)ob->query_name() == master) {
            if(base_name(ETO) == "/d/deku/open/lake" || base_name(ETO) == "/d/deku/open/lake2") {
                command("emote sighs and then shakes his head slightly");
                command("say alrighty.... if ya say so, but it better "+
                "be a quick...");
                command("swim");
                return 1;
            }
            command("say aint no place to swim 'ere");
            return 1;
        }
        fail();
        return 1;
    }
    if(strsrch(msg,"stay") != -1) {
        if((string)ob->query_name() == master) {
            if(base_name(ETO) == "/d/deku/town/info_office") {
                if(findings) {
                    command("say best have me report my findin' "+
                    "first");
                    return 1;
                }
                
                fines = SAVE_D->query_array("deku_guard_fine");
                x = member_array(TP->query_name(),SAVE_D->query_array("deku_has_guard"));
                if(x != -1) {
                    SAVE_D->remove_name_from_array("deku_has_guard",TP->query_name());
                    SAVE_D->remove_name_from_array("deku_guard_fine",fines[x]);
                }            
                command("emote goes back to his post");
                command("say good luck to ya.");
                set_master(0);
                ETO->add_guards_out(-1);
                return 1;
            }
            command("shake");
            command("say I aint got a post 'ere.");
            return 1;
        }
        fail();
        return 1;
    }
    if(strsrch(msg,"report") != -1) {
        if((string)ob->query_name() == master) {
            if(base_name(ETO) == "/d/deku/town/info_office") {
                if(!findings) {
                    command("say I aint got nothin' to report yet.");
                    return 1;
                }
                if(!(ob1 = present("dariul",ETO))) {
                    command("emote shakes his head and looks around");
                    command("say ya will have to wait for my "+
                    "superior to get back... he aint 'ere");
                    return 1;
                }
                do_report_findings(ob1,ob);
                findings = 0;
                return 1;
            }
            command("shake");
            command("say aint no reason for me to report anything "+
            "'ere");
            return 1;
        }
        fail();
        return 1;
    }
}

void long_desc() {
    if((string)TP->query_name() == master) {
        return "This man towers well over six feet tall.  "+
        "His body is thick, muscular, and bears witness through "+
        "scars of many past battles.  His eyes are intense "+
        "and reflect a constant state of alertness.  His hair "+
        "is unkept and falls down to slightly below his shoulders.  "+
        "He wears a suit of darkened chainmail bearing the symbol "+
        "of an opened hand.  He carries a longsword in one hand "+
        "and a short blade in the other.  You have been granted "+
        "authority to tell him to %^RED%^follow%^CYAN%^, %^RED%^wait"+
        "%^CYAN%^, or %^RED%^swim%^CYAN%^ if the need arises.  "+
        "You should %^RED%^point at%^CYAN%^ what you will when "+
        "you find something to prove a missing person to be dead, "+
        "then have him %^RED%^report%^CYAN%^ his findings when "+
        "you get back to town.  After he reports his findings "+
        "you have been asked to have him %^RED%^stay"+
        "%^CYAN%^ at his post.";
    }
     return "This man towers well over six feet tall.  "+
        "His body is thick, muscular, and bears witness through "+
        "scars of many past battles.  His eyes are intense "+
        "and reflect a constant state of alertness.  His hair "+
        "is unkept and falls down to slightly below his shoulders.  "+
        "He wears a suit of darkened chainmail bearing the symbol "+
        "of an opened hand.  He carries a longsword in one hand "+
        "and a short blade in the other.";
}
