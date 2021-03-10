#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_forsake(string str) {

    object who;

    string old, theclass;
    object symbol;
    int align,i,hp_loss;
    string curtheclass,*theclasses, diety;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) {
        return notify_fail("forsake <player name>\n");
    }

    if(!who = find_player(str)) {
        return notify_fail("That player is not present\n");
    }



    diety = (string)who->query_diety();
   if(!diety || diety == "") return notify_fail("That person has no diety.\n");
    symbol = present("holy symbol",who);
    if(!avatarp(who))
        ADVANCE_D->deity_news(diety,who->query_cap_name()+" has forsaken "+capitalize(diety)+" as "+who->query_possessive()+" diety!");
    log_file("player/god_change", capitalize(who->query_name())+" was removed from "+capitalize(diety)+": "+ctime(time())+" by "+capitalize(TP->query_true_name())+"\n");
    tell_object(who,"%^YELLOW%^"+capitalize(diety)+" will no longer have you as a follower!");
    tell_object(who,"%^YELLOW%^A bolt of energy streaks toward you from above, exacting "+capitalize(diety)+"'s revenge.");
    tell_object(who,"%^YELLOW%^You must seek out a temple and choose another deity to follow.");
    who->set_diety(0);
    who->set_sphere(0);
    if(!avatarp(who)) {
        who->set("last forsake",time());
    }
    who->forget_all_cl_spells();
    if(objectp(symbol)) symbol->remove();
    who->update_channels();
    if(avatarp(who)) {
        write("The avatar has been removed from the list of followers.");
        return 1;
    }
    who->add_exp(-((int)who->query_exp()*1/7));
    theclasses = who->query_theclasses();
    for(i=0;i<sizeof(who->query_theclasses());i++) {
        curtheclass = theclasses[i];
        while((int)ADVANCE_D->get_exp(who->query_theclass_level(curtheclass),curtheclass,who) > ((int)who->query_exp()/sizeof(who->query_theclasses()))) {
            who->set_mlevel(curtheclass,(int)who->query_theclass_level(curtheclass)-1);
            hp_loss = ADVANCE_D->get_hp_bonus(curtheclass,who->query_stats("constitution"),who->query_theclass_level(curtheclass),who);
            who->set_max_hp((int)who->query_max_hp() - hp_loss);
            who->set_hp(who->query_max_hp());
            who->reduce_my_skills(curtheclass);
            who->reduce_guild_level(curtheclass);
        }
    }
    who->setenv("TITLE", (string)ADVANCE_D->get_new_title(who));
    write("%^BOLD%^"+capitalize(who->query_name())+" has forsaken "+who->query_possessive()+" god and it is now official.");
    "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" %^BOLD%^%^CYAN%^was removed from following "+capitalize(diety)+" by "+capitalize(TP->query_true_name())+".");
    return 1;
}

int help(){
    write(
@OLI
    forsake <player>

    This will remove a player online from a god. It will remove the god, the sphere, etc.
    Note that this will act the same as if the player forsakes. They will not be able to
    follow another god for 2 days.

        This may encounter problems if you use it in the temples.
OLI
        );
}
